%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  
  int lab_num = -1;

  int left_to_increment[128];
  int in_expression = 0;

  int* parameter_map[128];
  int error_count = 0;
  int warning_count = 0;
  
  int var_num = 0;
  int par_num = 0; 

  int fun_idx = -1;
  int fcall_idx = -1;
  int type_capture = 0;
  int func_type_capture = 0;
  int return_flag = 0;

  int in_select = 0;
  int select_counter = 0;
  char* select_map[128];

  int in_para = 0;
  int para_iterator_map[128];
  int para_count = 0;
  int para_count_map[128];

  int row_counter = 0;
  int switch_exp_is_declared = 1;
  int switch_depth = 0;
  int switch_count = 0;
  int otherwise_exists[CHAR_BUFFER_LENGTH];
  int switch_depth_map[CHAR_BUFFER_LENGTH];

  int map_of_depth_updated_literals[CHAR_BUFFER_LENGTH][CHAR_BUFFER_LENGTH];  // inicijalizuj sve na 0
  int num_of_updated_literals = 0;
  int count_of_depth_updated_literals[CHAR_BUFFER_LENGTH];
  int switch_label_map[CHAR_BUFFER_LENGTH][CHAR_BUFFER_LENGTH];

  int block_depth = 0;
  int block_counter[128];
  int has_outer_vars = 0;
  int did_declaration = 0;

  int variable_map[128];
  int arg_counter = 0;
  int id_index_capture = -1;
  int init_valid = 1;
  int in_assignment = 0;

  int parameters_to_be_generated[128];

  int conditional_operator_counter = 0;

  int while_counter = 0;
  int while_depth = 0;

  FILE *output;
%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP
%token _UNOP
%token _SELECT
%token _COMMA
%token _FROM
%token _WHERE
%token _PARA
%token _EN
%token _SWITCH;
%token _CASE;
%token _BREAK;
%token _OTHERWISE;
%token _COLON;
%token _WHILE;
%token _QMARK

%type <i> num_exp exp literal unaryop conditional half_exp full_exp
%type <i> function_call argument rel_exp if_part

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : global_list function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;


global_list
	: /*empty*/
	| global_list global_var
	;

global_var
	: _TYPE _ID _SEMICOLON
	{
		int idx = lookup_symbol($2, GVAR); 
		if (idx != NO_INDEX) 
		{
				err("redefinition of '%s'", $2);
		} else {
			insert_symbol($2, GVAR, $1, NO_ATR, NO_ATR);
			code("\n%s:\n\t\tWORD\t1", $2);
		}
	}
	;


function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX){
          int* param_types = (int*) malloc(sizeof(int)*128);
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
          parameter_map[fun_idx] = param_types;
        }
        else 
          err("redefinition of function '%s'", $2);
        func_type_capture = $1;
        return_flag = 0;
        par_num = 0;

        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      
        has_outer_vars = 0;
      }
    _LPAREN parameter_list _RPAREN body
      {
        int i = 0;
        for(i = 0; i <= get_last_element(); i+=1){
          if(get_kind(i) == VAR && get_atr2(i) == UNINITIALISED){
            err("uninitialised variable %s", get_name(i));
          }
        }
        clear_symbols(fun_idx + 1);
        var_num = 0;
        if(!return_flag && func_type_capture != VOID){
          warning("Function should return a value;");
        }
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;

parameter_list
  : /* empty */
    { set_atr1(fun_idx, 0); }
  | parameters

parameters
  : parameter
  | parameters _COMMA parameter

parameter
  : _TYPE _ID
      {
        if ( $1 == VOID){
          err("Type of parameter cannot be void.");
        }
        if(lookup_symbol($2, PAR) != -1){
          err("Redefinition of parameter %s ", $2);
        }
        if(lookup_symbol($2, GVAR) != -1){
          err("Parameter cannot have the same name as global variable %s ", $2);
        }
        insert_symbol($2, PAR, $1, ++par_num, NO_ATR);
        int num_params = get_atr1(fun_idx);
        int* param_types = parameter_map[fun_idx];
        param_types[num_params] = $1;
        num_params += 1;
        set_atr1(fun_idx, num_params);
      }
  ;

body
  : _LBRACKET variable_list
      {
        if(var_num && did_declaration == 0)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
          block_counter[0] = var_num;
          has_outer_vars = 1;
        code("\n@%s_body:", get_name(fun_idx));
      }
    statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  : _TYPE
    {
      if ( $1 == VOID){
        err("Type of variable cannot be void.");
      }
      type_capture = $1;
    } 
    vars declaration _SEMICOLON{ row_counter = 0; }
  ;

declaration
  : /* empty */
  | _ASSIGN _INT_NUMBER
    {
      if(type_capture != INT){
        err("'%s' is not of type INT", $2);
      }
      
      code("\n\t\tSUBS\t%%15,$%d,%%15", 4*row_counter);
      did_declaration = 1;

      int i;
      for(i = get_last_element(); i > get_last_element()-row_counter; i -= 1){
        set_atr2(i, INITIALISED);
        code("\n\t\tMOV\t");
        code("$%d, ", atoi($2));
        gen_sym_name(i);
      }
      row_counter = 0;
    }
  | _ASSIGN _UINT_NUMBER
    {
      if(type_capture != UINT){
        err("'%s' is not of type UINT", $2);
      }

      code("\n\t\tSUBS\t%%15,$%d,%%15", 4*row_counter);
      did_declaration = 1;

      int i;
      for(i = get_last_element(); i > get_last_element()-row_counter; i -= 1){
        set_atr2(i, INITIALISED);
        code("\n\t\tMOV\t");
        code("$%d, ", atoi($2));
        gen_sym_name(i);
      }
      row_counter = 0;
    }
  ;

vars
  : _ID
    {
      if(in_select){
        int i;
        for(i = 0; i < 128; i++){
          if(select_map[i] != (char*) -1 && strcmp(select_map[i], $1) == 0){
            err("'%s' used more than once in select statement.", $1);
          }
        }
        select_map[select_counter] = $1;
        select_counter += 1;
      }

      if (in_para > 0){
        int idx = lookup_symbol($1, VAR|PAR|GVAR);
        int i;
        for (i = 1; i <= in_para; i+=1){
          if (idx == para_iterator_map[i]){
            err("'%s' cannot have the same name as the iterator variable in PARA statement.", $1);
          }
        }
      }

      row_counter += 1;
      block_counter[block_depth] += 1;
      int idx = lookup_symbol($1, VAR|PAR|GVAR);
      if(idx == NO_INDEX){
        if(!in_select){
          insert_symbol($1, VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }else{
          err("'%s' not defined", $1);
        }
      }
      else{
        if(variable_map[idx] == block_depth || lookup_symbol($1, PAR) != -1){
          if(!in_select)
            err("redefinition of '%s'", $1);
        }else{
          insert_symbol($1, VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }
      }
    }
  | vars _COMMA _ID
    {
      if(in_select){
        int i;
        for(i = 0; i < 128; i++){
          if(select_map[i] != (char*) -1 && strcmp(select_map[i], $3) == 0){
            err("'%s' used more than once in select statement.", $3);
          }
        }
        select_map[select_counter] = $3;
        select_counter += 1;
      }

      if (in_para > 0){
        int idx = lookup_symbol($3, VAR|PAR|GVAR);
        int i;
        for (i = 1; i <= in_para; i+=1){
          if (idx == para_iterator_map[i]){
            err("'%s' cannot have the same name as the iterator variable in PARA statement.", $3);
          }
        }
      }

      row_counter += 1;
      block_counter[block_depth] += 1;
      int idx = lookup_symbol($3, VAR|PAR|GVAR);
      if(idx == NO_INDEX){
        if(!in_select){
          insert_symbol($3, VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }else{
          err("'%s' not defined.", $3);
        }
      }
      else{
        if(variable_map[idx] == block_depth || lookup_symbol($3, PAR) != -1){
          if(!in_select)
            err("redefinition of '%s'", $3);
        }else{
          insert_symbol($3, VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }
      }
    }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  | unaryop _SEMICOLON
  | select_statement
  | para_statement
  | switch_statement
  | while_statement
  | function_call _SEMICOLON
  ;

while_statement
  : _WHILE
    {
      $<i>$ = ++while_counter;
      code("\nwhile_%d_depth_%d:", while_counter, ++while_depth);
    } 
    _LPAREN rel_exp _RPAREN 
    {
      code("\n\t\t%s\tend_while_%d_depth_%d", opp_jumps[$4], while_counter, while_depth);
    }
    statement
    {
      code("\n\t\tJMP\twhile_%d_depth_%d", $<i>2, while_depth);
      code("\nend_while_%d_depth_%d:", $<i>2, while_depth--);
    }

switch_statement
  : _SWITCH _LPAREN _ID
    {
      switch_count += 1;
      $<i>$ = switch_count;
      switch_exp_is_declared = 1;
      switch_depth += 1;

      switch_depth_map[switch_depth] = switch_count;

      int index;
      index = lookup_symbol($3, VAR|PAR|GVAR);
      if(index == NO_INDEX){
        err("'%s' not declared.", $3);
        switch_exp_is_declared = 0;
      }
      type_capture = get_type(index);

      code("\n\t\tJMP\tswitch_%d_depth_%d_check", switch_depth_map[switch_depth], switch_depth);
    } _RPAREN _LBRACKET cases otherwise _RBRACKET
    {
      
      code("\n\nswitch_%d_depth_%d_skip_check:", switch_depth_map[switch_depth], switch_depth);
      code("\n\t\tJMP\tswitch_%d_depth_%d_exit", switch_depth_map[switch_depth], switch_depth);
      code("\n\nswitch_%d_depth_%d_check:", switch_depth_map[switch_depth], switch_depth);

      int j;
      int index;
      index = lookup_symbol($3, VAR|PAR|GVAR);

      for(j = 0; j <= get_last_element(); j += 1){
        if(get_kind(j) == LIT && get_atr1(j) == switch_depth && get_atr2(j) == IN_SWITCH && $<i>4 == switch_label_map[j][switch_depth]){
          gen_cmp(index, j);
          code("\n\t\tJEQ\tswitch_%d_depth_%d_case_%d", switch_depth_map[switch_depth], switch_depth, j);
        }
      }
      if(otherwise_exists[switch_depth]){
        code("\n\t\tJMP\tswitch_%d_depth_%d_otherwise", switch_depth_map[switch_depth], switch_depth);
      }
      code("\n\nswitch_%d_depth_%d_exit:", switch_depth_map[switch_depth], switch_depth);
      otherwise_exists[switch_depth] = 0;
      
      switch_depth -= 1;
      
      int i;
      for(i = 0; i <= get_last_element(); i += 1){

        if(get_kind(i) == LIT && get_atr2(i) == IN_SWITCH){
          if (count_of_depth_updated_literals[i] > 1){
            count_of_depth_updated_literals[i] -= 1;
            set_atr1(i, map_of_depth_updated_literals[i][count_of_depth_updated_literals[i] - 1]);
          }
        }
        
        if(get_kind(i) == LIT && get_atr2(i) == IN_SWITCH && switch_depth == 0){
          set_atr1(i, 0);
        }
      }
    }
  ;

cases
  : case
  | cases case
  ;

case
  : _CASE literal
    {
      if(get_type($2) != type_capture && switch_exp_is_declared){
        err("switch constants must be of same type as the switch expression.");
      }
      if (get_atr1($2) == switch_depth && get_atr2($2) == IN_SWITCH && switch_label_map[$2][switch_depth] == switch_depth_map[switch_depth]){
        err("case constants must be unique %s", get_name($2));
      }else{
        int depth_capture = get_atr1($2);
        set_atr1($2, switch_depth);
        set_atr2($2, IN_SWITCH);
        if (get_atr2($2) == IN_SWITCH){
          map_of_depth_updated_literals[$2][count_of_depth_updated_literals[$2]] = switch_depth;
          count_of_depth_updated_literals[$2] += 1;
        }
        switch_label_map[$2][switch_depth] = switch_depth_map[switch_depth];
      }

      code("\n\nswitch_%d_depth_%d_case_%d:", switch_depth_map[switch_depth], switch_depth, $2);
    }
    _COLON statement break
  ;

break
  : /* empty */
  | _BREAK _SEMICOLON
    {
      code("\n\t\tJMP\tswitch_%d_depth_%d_exit", switch_depth_map[switch_depth], switch_depth);
    }
  ;

otherwise
  : /* empty */
  | _OTHERWISE _COLON
  {
    otherwise_exists[switch_depth] = 1;
    code("\n\nswitch_%d_depth_%d_otherwise:", switch_depth_map[switch_depth], switch_depth);
  }
  statement
  {
    code("\n\t\tJMP\tswitch_%d_depth_%d_exit", switch_depth_map[switch_depth], switch_depth);
  }
  ;

para_statement
  : _PARA _LPAREN _ID _ASSIGN literal _EN literal _RPAREN
    {
      int index;
      in_para += 1;
      index = lookup_symbol($3, VAR | PAR | GVAR);
      if(index == NO_INDEX){ // da li moze biti parametar???
        err("'%s' not declared.", $3);
      }else{
        if(get_type($5) != get_type(index) || get_type($7) != get_type(index)){
          err("Iterator '%s' and iterator bounds are not of the same type.", $3);
        }
        set_atr2(index, INITIALISED);
      }
      if (atoi(get_name($5)) >= atoi(get_name($7))){
        err("Lower iterator bound must be LOWER than the upper iterator bound.");
      }
      para_iterator_map[in_para] = index;

      para_count += 1;
      para_count_map[in_para] = para_count;

      code("\npara_%d_%d_init:", para_count_map[in_para], in_para);
      code("\n\t\tMOV\t");
      gen_sym_name($5);
      code(", ");
      gen_sym_name(index);
      code("\npara_%d_%d_body:", para_count_map[in_para], in_para);
      gen_cmp(index, $7);

      if (get_type(index) == INT){
        code("\n\t\tJGTS\tpara_%d_%d_exit", para_count_map[in_para], in_para);
      } else {
        code("\n\t\tJGTU\tpara_%d_%d_exit", para_count_map[in_para], in_para);
      }
    }
    statement
    {
      int idx;
      idx = lookup_symbol($3, VAR | PAR | GVAR);
      if (get_type(idx) == INT){
        code("\n\t\tADDS\t");
      } else {
        code("\n\t\tADDU\t");
      }
      gen_sym_name(idx);
      code(", $1, ");
      gen_sym_name(idx);
      code("\n\t\tJMP\tpara_%d_%d_body", para_count_map[in_para], in_para);
      code("\npara_%d_%d_exit:", para_count_map[in_para], in_para);
      in_para -= 1;
    }
  ;

select_statement
  : _SELECT{
      in_select = 1; 
      select_counter = 0; 
      int i; 
      for(i = 0; i < 128; i += 1) {
          select_map[i] = (char*) -1;
      } 
    } 
    vars _FROM _ID _WHERE _LPAREN rel_exp _RPAREN _SEMICOLON
    {
      in_select = 0;
      if(lookup_symbol($5, VAR|PAR|GVAR) == NO_INDEX){
        err("'%s' not declared.", $5);
      }
    }
  ;

compound_statement
  : _LBRACKET 
    { 
      if(has_outer_vars == 0){
        block_counter[0] = 0; 
      }
      
      block_depth += 1; 
      block_counter[block_depth] = 0;
      did_declaration = 0;
    }
    variable_list 
    {
      if(var_num && did_declaration == 0)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*(block_counter[block_depth]));
    }
    statement_list _RBRACKET{
      if(block_counter[block_depth] > 0){
        int i;
        for(i = 0; i <= get_last_element(); i+=1){
          if(get_kind(i) == VAR && get_atr2(i) == UNINITIALISED && variable_map[i] == block_depth){
            err("uninitialised variable %s", get_name(i));
          }
        }
        int idx = get_last_element();
        while(block_counter[block_depth] > 0){
          if(get_kind(idx) == VAR){
            block_counter[block_depth] -= 1;
          }
          idx -= 1;
        }
        clear_symbols(idx + 1);
      }
      block_depth -= 1; 
    }
  ;

assignment_statement
  : _ID 
      { 
        in_assignment = 1;
        in_expression = 1;
        int j;
        for(j = 0; j < 128; j+=1){
          left_to_increment[j] = -1;
        }
      } 
    _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR|GVAR);
        id_index_capture = idx;
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($4))
            err("incompatible types in assignment.");
        if(init_valid == 1){
          set_atr2(idx, INITIALISED);
        }
        in_assignment = 0;
        init_valid = 1;

        int i;
        for(i = 0; i < 128; i+=1){
          if(left_to_increment[i] > -1){
            if(get_type(i) == UINT){
              code("\n\t\tADDU\t");
            }else {
              code("\n\t\tADDS\t");
            }
            gen_sym_name(i);
            code(", $1, ");
            gen_sym_name(i);
          }
        }
        in_expression = 0;

        gen_mov($4, idx);
      }
  ;

num_exp
  : exp
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
        else{
          int t1 = get_type($1);    
          code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
          gen_sym_name($1);
          code(",");
          gen_sym_name($3);
          code(",");
          free_if_reg($3);
          free_if_reg($1);
          $$ = take_reg();
          gen_sym_name($$);
          set_type($$, t1);
        }
      }
  ;

  conditional
    : _LPAREN rel_exp _RPAREN _QMARK half_exp _COLON half_exp
      {
        if (get_type($5) != get_type($7)){
          err("Both alternatives must be of the same type as a target variable.");
        }

        conditional_operator_counter += 1;
        
        code("\n\t\t%s\tsecond_choice_%d", opp_jumps[$2], conditional_operator_counter);
        $$ = take_reg();
        code("\n\t\tMOV\t");
        gen_sym_name($5);
        code(", ");
        gen_sym_name($$);
        code("\n\t\tJMP\tcond_end_%d", conditional_operator_counter);
        code("\nsecond_choice_%d:", conditional_operator_counter);
        code("\n\t\tMOV\t");
        gen_sym_name($7);
        code(", ");
        gen_sym_name($$);
        code("\ncond_end_%d:", conditional_operator_counter);
        set_type($$, get_type($7));
      }

exp
  : half_exp { $$ = $1; }
  | full_exp { $$ = $1; }

half_exp
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR|GVAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
        if(in_assignment){
          if(get_kind($$) == VAR && get_atr2($$) == UNINITIALISED){
            init_valid = 0;
          }
        }
      }

full_exp
  : function_call
      {
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
      }
  
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  | unaryop
  | conditional
  ;

unaryop
  : _ID _UNOP
    {
      if(lookup_symbol($1, FUN) != NO_INDEX){
          err("Postincrement may be only used on variables, not functions.");
      }
      $$ = lookup_symbol($1, VAR|PAR|GVAR);
      if($$ == NO_INDEX){
          err("%s is not declared previously as a variable", $1);
      }
      if(in_expression == 1){
        left_to_increment[$$] = 1;
      }else{
        if(get_type($$) == UINT){
              code("\n\t\tADDU\t");
            }else {
              code("\n\t\tADDS\t");
            }
            gen_sym_name($$);
            code(", $1, ");
            gen_sym_name($$);
      }
      
      
    }
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT);}

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT);}
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);

        arg_counter = 0;
      }
    _LPAREN argument_list _RPAREN
      {
        if(get_atr1(fcall_idx) != arg_counter)
          err("wrong number of args to function '%s'", 
              get_name(fcall_idx));
        
        int i = 0;
        for(i = arg_counter - 1; i >= 0; i -= 1){
          code("\n\t\tPUSH\t");
          gen_sym_name(parameters_to_be_generated[i]);
        }

        code("\n\t\tCALL\t%s", get_name(fcall_idx));
        if(arg_counter > 0)
          code("\n\t\tADDS\t%%15,$%d,%%15", arg_counter * 4);

        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;

        arg_counter = 0;
      }
  ;

argument_list
  : /* empty */
  | arguments

arguments
  : argument
  | arguments _COMMA argument

argument
  : num_exp
    { 
      if(parameter_map[fcall_idx][arg_counter] != get_type($1))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      arg_counter += 1;


      parameters_to_be_generated[arg_counter - 1] = $1;
      free_if_reg($1);
      $$ = 1;  // ovo ne treba ali neka stoji
    }
  ;

if_statement
  : if_part %prec ONLY_IF
      { code("\n@exit%d:", $1); }

  | if_part _ELSE statement
      { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
    rel_exp
      {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3); 
        code("\n@true%d:", $<i>3);
      }
    _RPAREN statement
      {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
        $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
        return_flag = 1;
        if(func_type_capture == VOID){
          err("Void function should not return a value.");
        }
        else if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");

        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
  | _RETURN _SEMICOLON
    {
      if(func_type_capture == INT || func_type_capture == UINT){
        warning("Function should return a value.");
      }
      code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
    }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}


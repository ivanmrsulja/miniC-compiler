%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int* parameter_map[128];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int type_capture = 0;
  int func_type_capture = 0;
  int return_flag = 0;
  int in_select = 0;
  int row_counter = 0;
  int switch_exp_is_declared = 1;
  int switch_depth = 0;
  int block_depth = 0;
  int block_counter[128];
  int variable_map[128];
  int arg_counter = 0;
  int id_index_capture = -1;
  int init_valid = 1;
  int in_assignment = 0;
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
%token _UNOP;
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

%type <i> num_exp exp literal function_call argument rel_exp

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
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
        insert_symbol($2, PAR, $1, 1, NO_ATR);
        int num_params = get_atr1(fun_idx);
        int* param_types = parameter_map[fun_idx];
        param_types[num_params] = $1;
        num_params += 1;
        set_atr1(fun_idx, num_params);
      }
  ;

body
  : _LBRACKET variable_list statement_list _RBRACKET
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
      int i;
      for(i = get_last_element(); i > get_last_element()-row_counter; i -= 1){
        set_atr2(i, INITIALISED);
      }
      row_counter = 0;
    }
  | _ASSIGN _UINT_NUMBER
    {
      if(type_capture != UINT){
        err("'%s' is not of type UINT", $2);
      }
      int i;
      for(i = get_last_element(); i > get_last_element()-row_counter; i -= 1){
        set_atr2(i, INITIALISED);
      }
      row_counter = 0;
    }
  ;

vars
  : _ID
    {
      row_counter += 1;
      block_counter[block_depth] += 1;
      int idx = lookup_symbol($1, VAR|PAR);
      if(idx == NO_INDEX){
        if(!in_select){
          insert_symbol($1, VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }else{
          err("'%s' not defined", $1);
        }
      }
      else{
        if(variable_map[idx] == block_depth){
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
      row_counter += 1;
      block_counter[block_depth] += 1;
      int idx = lookup_symbol($3, VAR|PAR);
      if(idx == NO_INDEX){
        if(!in_select){
          insert_symbol($3, VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }else{
          err("'%s' not defined.", $3);
        }
      }
      else{
        if(variable_map[idx] == block_depth){
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
  ;

while_statement
  : _WHILE _LPAREN rel_exp _RPAREN statement

switch_statement
  : _SWITCH _LPAREN _ID
    {
      switch_exp_is_declared = 1;
      switch_depth += 1;
      int index;
      index = lookup_symbol($3, VAR|PAR);
      if(index == NO_INDEX){
        err("'%s' not declared.", $3);
        switch_exp_is_declared = 0;
      }
      type_capture = get_type(index);
    } _RPAREN _LBRACKET cases otherwise _RBRACKET
    {
      switch_depth -= 1;
      int i;
      for(i = 0; i < get_last_element(); i += 1){
        if(get_kind(i) == LIT){
          set_atr1(i, switch_depth);
        }
      }
    }
  ;

cases
  : case
  | cases case
  ;

case
  : _CASE literal{
      if(get_type($2) != type_capture && switch_exp_is_declared){
        err("switch constants must be of same type as the switch expression.");
      }
      if (get_atr1($2) == switch_depth){
        err("case constants must be unique");
      }else{
        set_atr1($2, switch_depth);
      }
    } _COLON statement break
  ;

break
  : /* empty */
  | _BREAK _SEMICOLON
  ;

otherwise
  : /* empty */
  | _OTHERWISE _COLON statement
  ;

para_statement
  : _PARA _LPAREN _ID _ASSIGN literal _EN literal _RPAREN statement
    {
      int index;
      index = lookup_symbol($3, VAR);
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

    }
  ;

select_statement
  : _SELECT{ in_select = 1; } vars _FROM _ID _WHERE _LPAREN rel_exp _RPAREN _SEMICOLON
    {
      in_select = 0;
      if(lookup_symbol($5, VAR|PAR) == NO_INDEX){
        err("'%s' not declared.", $5);
      }
    }
  ;

compound_statement
  : _LBRACKET { block_depth += 1; block_counter[block_depth] = 0;} variable_list  statement_list _RBRACKET{
      if(block_counter[block_depth] > 0){
        printf("Count : %d", block_counter[block_depth]);
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
        clear_symbols(idx+1);
      }
      block_depth -= 1; 
    }
  ;

assignment_statement
  : _ID { in_assignment = 1; } _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR);
        id_index_capture = idx;
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($4))
            err("incompatible types in assignment");
        if(init_valid == 1){
          set_atr2(idx, INITIALISED);
        }
        in_assignment = 0;
        init_valid = 1;
      }
  ;

num_exp
  : exp
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands : arithmetic operation");
      }
  ;

exp
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
        if(in_assignment){
          if(get_kind($$) == VAR && get_atr2($$) == UNINITIALISED){
            init_valid = 0;
          }
        }
      }
  | function_call
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  ;

unaryop
  : _ID _UNOP
    {
      if(lookup_symbol($1, FUN) != NO_INDEX){
          err("Postincrement may be only used on variables, not functions.");
      }
      if(lookup_symbol($1, VAR|PAR) == NO_INDEX){
          err("%s not declared", $1);
      }
    }
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
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
    }
  ;

if_statement
  : if_part %prec ONLY_IF
  | if_part _ELSE statement
  ;

if_part
  : _IF _LPAREN rel_exp _RPAREN statement
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands : relational operator");
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
      }
	| _RETURN _SEMICOLON
    {
      if(func_type_capture == INT || func_type_capture == UINT){
        warning("Function should return a value.");
      }
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

  synerr = yyparse();

  clear_symtab();
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr)
    return -1; //syntax error
  else
    return error_count; //semantic errors
}


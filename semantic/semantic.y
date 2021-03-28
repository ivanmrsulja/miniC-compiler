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
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int type_capture = 0;
  int in_select = 0;
  int row_counter = 0;
  int switch_exp_is_declared = 1;
  int switch_depth = 0;
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
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);
      }
    _LPAREN parameter _RPAREN body
      {
        int i = 0;
        for(i = 0; i <= get_last_element(); i+=1){
          if(get_kind(i) == VAR && get_atr2(i) == UNINITIALISED){
            err("uninitialised variable %s", get_name(i));
          }
        }
        clear_symbols(fun_idx + 1);
        var_num = 0;
      }
  ;

parameter
  : /* empty */
      { set_atr1(fun_idx, 0); }

  | _TYPE _ID
      {
        insert_symbol($2, PAR, $1, 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, $1);
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
      if(lookup_symbol($1, VAR|PAR) == NO_INDEX){
        if(!in_select){
          insert_symbol($1, VAR, type_capture, ++var_num, UNINITIALISED);
        }else{
          err("'%s' not defined", $1);
        }
      }
      else{
        if(!in_select)
          err("redefinition of '%s'", $1);
      }
    }
  | vars _COMMA _ID
    {
      row_counter += 1;
      if(lookup_symbol($3, VAR|PAR) == NO_INDEX){
        if(!in_select){
          insert_symbol($3, VAR, type_capture, ++var_num, UNINITIALISED);
        }else{
          err("'%s' not defined.", $3);
        }
      }
      else{
        if(!in_select)
          err("redefinition of '%s'", $3);
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
  ;

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
      // printf("|%d < %d|", atoi(get_name($5)), atoi(get_name($7)));
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
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($3))
            err("incompatible types in assignment");
          set_atr2(idx, INITIALISED);
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
      }
    _LPAREN argument _RPAREN
      {
        if(get_atr1(fcall_idx) != $4)
          err("wrong number of args to function '%s'", 
              get_name(fcall_idx));
        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
      }
  ;

argument
  : /* empty */
    { $$ = 0; }

  | num_exp
    { 
      if(get_atr2(fcall_idx) != get_type($1))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      $$ = 1;
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
          err("invalid operands: relational operator");
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
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

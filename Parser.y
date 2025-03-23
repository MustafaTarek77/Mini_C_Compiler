%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    
    extern int yylex();
    extern int yylineno;
    void yyerror(const char *s);
%}

%union
{
    int int_type;     
    float float_type;  
    double double_type;   
    char char_type;    
    bool bool_type;     
    char *string_type; 
    long long_type;
    short short_type;
}

/* Token Definitions */
%token <int_type> INT
%token <float_type> FLOAT
%token <double_type> DOUBLE
%token <char_type> CHAR
%token <bool_type> BOOL
%token <string_type> STRING
%token <long_type> LONG
%token <short_type> SHORT

%token SEMICOLON COMMA ASSIGN ADD SUB MUL DIV MOD POW
%token LOGICAL_AND LOGICAL_OR LOGICAL_NOT
%token EQUAL NOT_EQUAL GREATER_THAN LESS_THAN GREATER_EQUAL LESS_EQUAL
%token BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_NOT SHIFT_LEFT SHIFT_RIGHT
%token BOOL_VALUE INTEGER_VALUE FLOAT_VALUE STRING_VALUE CHAR_VALUE
%token UNSIGNED SIGNED VOID
%token PRINT RETURN IF ELSE FOR WHILE DO SWITCH CASE DEFAULT BREAK CONTINUE
%token IDENTIFIER CONSTANT

/* Operator Precedence */
%left LOGICAL_OR
%left LOGICAL_AND
%left EQUAL NOT_EQUAL
%left GREATER_THAN LESS_THAN GREATER_EQUAL LESS_EQUAL
%left ADD SUB
%left MUL DIV MOD
%right POW
%right LOGICAL_NOT BITWISE_NOT
%left SHIFT_LEFT SHIFT_RIGHT

%nonassoc IFX
%nonassoc ELSE
%left COMMA

%%

program:
    program statement
    | statement
    ;

statement:
    declaration_statement SEMICOLON
    | assignment_statement SEMICOLON
    | print_statement SEMICOLON
    | return_statement SEMICOLON
    | expression SEMICOLON
    | function_call SEMICOLON
    | function_declaration 
    | break_statement SEMICOLON
    | continue_statement SEMICOLON
    | if_statement
    | while_statement
    | for_statement
    | do_while_statement
    | switch_statement
    | compound_statement
    ;

declaration_statement:
    type IDENTIFIER
    | type IDENTIFIER ASSIGN expression
    | type CONSTANT ASSIGN expression
    ;

assignment_statement:
    IDENTIFIER ASSIGN expression
    ;

print_statement:
    PRINT '(' expression ')'
    ;

return_statement:
    RETURN expression
    | RETURN
    ;

if_statement:
    IF '(' expression ')' compound_statement %prec IFX
    | IF '(' expression ')' compound_statement ELSE compound_statement
    ;

while_statement:
    WHILE '(' expression ')' compound_statement
    ;
    
do_while_statement : DO compound_statement WHILE '(' expression ')'
                   ;

for_statement:
    FOR '(' assignment_statement SEMICOLON expression SEMICOLON assignment_statement ')' compound_statement
    ;

switch_statement :  SWITCH '(' IDENTIFIER ')' '{' case_statement '}'
                 |  SWITCH '(' IDENTIFIER ')' '{' case_statement  default_statement'}'
                 ;

case_statement : CASE INT ':' statement case_statement
      | CASE BOOL ':' statement case_statement
      |
      ;

default_statement : DEFAULT ':' statement

compound_statement:
    '{' statement_list '}'
    ;

statement_list:
    statement_list statement
    |
    ;

parameter_list:
    parameter_list_non_empty
    |  %prec COMMA
    ;

parameter_list_non_empty:
    parameter
    | parameter_list_non_empty COMMA parameter
    ;

parameter:
    type IDENTIFIER
    ;

function_declaration:
    type IDENTIFIER '(' parameter_list ')' compound_statement
    ;

argument_list:
    argument_list_non_empty
    | 
    ;

argument_list_non_empty:
    expression
    | argument_list_non_empty COMMA expression
    ;


function_call:
    IDENTIFIER '(' argument_list ')'
    ;

break_statement:
    BREAK
    ;

continue_statement:
    CONTINUE
    ;

expression:
    expression ADD expression
    | expression SUB expression
    | expression MUL expression
    | expression DIV expression
    | expression MOD expression
    | expression POW expression
    | expression LOGICAL_AND expression
    | expression LOGICAL_OR expression
    | expression EQUAL expression
    | expression NOT_EQUAL expression
    | expression GREATER_THAN expression
    | expression LESS_THAN expression
    | expression GREATER_EQUAL expression
    | expression LESS_EQUAL expression
    | LOGICAL_NOT expression
    | BITWISE_NOT expression
    | expression SHIFT_LEFT expression
    | expression SHIFT_RIGHT expression
    | INTEGER_VALUE
    | FLOAT_VALUE
    | STRING_VALUE
    | CHAR_VALUE
    | BOOL_VALUE
    | IDENTIFIER
    | '(' expression ')'
    ;

type:
    INT | FLOAT | DOUBLE | STRING | CHAR | BOOL | LONG | SHORT | UNSIGNED | SIGNED | VOID
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

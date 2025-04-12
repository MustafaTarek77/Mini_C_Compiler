%{
    /* C Declarations */
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include "Parser.tab.h"
%}
%option yylineno

%%

\/\/.*                 { }  
\/\*.*\*\/       { } 

";"                    { printf("SEMICOLON: %s\n", yytext); return SEMICOLON; }  
","                    { printf("COMMA: %s\n", yytext); return COMMA; }  
[(){}:]                { printf("PUNCTUATOR: %s\n", yytext); return *yytext; } 

"="                    { printf("ASSIGN: %s\n", yytext); return ASSIGN; } 
"+"                    { printf("ADD: %s\n", yytext); return ADD; }  
"-"                    { printf("SUB: %s\n", yytext); return SUB; }    
"*"                    { printf("MUL: %s\n", yytext); return MUL; }    
"/"                    { printf("DIV: %s\n", yytext); return DIV; }   
"%"                    { printf("MOD: %s\n", yytext); return MOD; }     
"^"                    { printf("POW: %s\n", yytext); return POW; }  

"&&"                   { printf("LOGICAL_AND: %s\n", yytext); return LOGICAL_AND; }  
"||"                   { printf("LOGICAL_OR: %s\n", yytext); return LOGICAL_OR; }   
"!"                    { printf("LOGICAL_NOT: %s\n", yytext); return LOGICAL_NOT; }  

"=="                   { printf("EQUAL: %s\n", yytext); return EQUAL; }      
"!="                   { printf("NOT_EQUAL: %s\n", yytext); return NOT_EQUAL; }   
">"                    { printf("GREATER_THAN: %s\n", yytext); return GREATER_THAN; }
"<"                    { printf("LESS_THAN: %s\n", yytext); return LESS_THAN; }   
">="                   { printf("GREATER_EQUAL: %s\n", yytext); return GREATER_EQUAL; }
"<="                   { printf("LESS_EQUAL: %s\n", yytext); return LESS_EQUAL; }   

"&"                    { printf("BITWISE_AND: %s\n", yytext); return BITWISE_AND; }  
"|"                    { printf("BITWISE_OR: %s\n", yytext); return BITWISE_OR; }   
"#"                    { printf("BITWISE_XOR: %s\n", yytext); return BITWISE_XOR; }  
"~"                    { printf("BITWISE_NOT: %s\n", yytext); return BITWISE_NOT; }  
"<<"                   { printf("SHIFT_LEFT: %s\n", yytext); return SHIFT_LEFT; }   
">>"                   { printf("SHIFT_RIGHT: %s\n", yytext); return SHIFT_RIGHT; }  

"true"                 { yylval.bool_type = true; printf("BOOL_VALUE: %s\n", yytext); return BOOL_VALUE; }  
"false"                { yylval.bool_type = false; printf("BOOL_VALUE: %s\n", yytext); return BOOL_VALUE; }

"int"                  { printf("INT: %s\n", yytext); return INT; }   
"float"                { printf("FLOAT: %s\n", yytext); return FLOAT; } 
"double"               { printf("DOUBLE: %s\n", yytext); return DOUBLE; }  
"string"               { printf("STRING: %s\n", yytext); return STRING; } 
"char"                 { printf("CHAR: %s\n", yytext); return CHAR; }    
"bool"                 { printf("BOOL: %s\n", yytext); return BOOL; }    
"long"                 { printf("LONG: %s\n", yytext); return LONG; }    
"short"                { printf("SHORT: %s\n", yytext); return SHORT; }   
"unsigned"             { printf("UNSIGNED: %s\n", yytext); return UNSIGNED; }
"signed"               { printf("SIGNED: %s\n", yytext); return SIGNED; }  
"void"                 { printf("VOID: %s\n", yytext); return VOID; }   

"print"                { printf("PRINT: %s\n", yytext); return PRINT; }    
"return"               { printf("RETURN: %s\n", yytext); return RETURN; }   
"if"                   { printf("IF: %s\n", yytext); return IF; }       
"else"                 { printf("ELSE: %s\n", yytext); return ELSE; }     
"for"                  { printf("FOR: %s\n", yytext); return FOR; }      
"while"                { printf("WHILE: %s\n", yytext); return WHILE; }    
"do"                   { printf("DO: %s\n", yytext); return DO; }       
"switch"               { printf("SWITCH: %s\n", yytext); return SWITCH; }   
"case"                 { printf("CASE: %s\n", yytext); return CASE; }    
"default"              { printf("DEFAULT: %s\n", yytext); return DEFAULT; }  
"break"                { printf("BREAK: %s\n", yytext); return BREAK; }    
"continue"             { printf("CONTINUE: %s\n", yytext); return CONTINUE; } 

[A-Z]+                { yylval.string_type = strdup(yytext); printf("CONSTANT: %s\n", yytext); return CONSTANT; }

[a-zA-Z_][a-zA-Z0-9_]*    { yylval.string_type = strdup(yytext); printf("IDENTIFIER: %s\n", yytext); return IDENTIFIER; } 

-?[0-9]+                 { yylval.int_type = atoi(yytext); printf("INTEGER_VALUE: %s\n", yytext); return INTEGER_VALUE; }    
-?[0-9]+\.[0-9]+         { yylval.float_type = atof(yytext); printf("FLOAT_VALUE: %s\n", yytext); return FLOAT_VALUE; }  

\".*\"        { yylval.string_type = strdup(yytext); printf("STRING_VALUE: %s\n", yytext); return STRING_VALUE; }   

\'.\'         { yylval.string_type = strdup(yytext); printf("CHAR_VALUE: %s\n", yytext); return CHAR_VALUE; }  

[ \t\r\n]+             { }   

.                      { printf("Unexpected character: %s\n", yytext); }  

%%              

int yywrap(void) 
{
    return 1;
}

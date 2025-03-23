%{
    /* C Declarations */
    #include <stdio.h>
    #include <string.h>
    #include "parser.tab.h"
%}
%option yylineno

%%
\/\/.*                 { }  /* Matches single-line comments (// this is a comment) */
\/\*[\s\S]*?\*\/       { }  /* Matches multi-line comments (/* this is a block comment */) */

";"                    { return SEMICOLON; }  
","                    { return COMMA; }      /* Separator for function arguments */
[(){}:]                { return *yytext; } 

"="                    { return ASSIGN; } 
"+"                    { return ADD; }  
"-"                    { return SUB; }    
"*"                    { return MUL; }    
"/"                    { return DIV; }   
"%"                    { return MOD; }     
"^"                    { return POW; }  

"&&"                   { return LOGICAL_AND; }  
"||"                   { return LOGICAL_OR; }   
"!"                    { return LOGICAL_NOT; }  

"=="                   { return EQUAL; }      
"!="                   { return NOT_EQUAL; }   
">"                    { return GREATER_THAN; }
"<"                    { return LESS_THAN; }   
">="                   { return GREATER_EQUAL; }
"<="                   { return LESS_EQUAL; }   

"&"                    { return BITWISE_AND; }  
"|"                    { return BITWISE_OR; }   
"#"                    { return BITWISE_XOR; }  
"~"                    { return BITWISE_NOT; }  
"<<"                   { return SHIFT_LEFT; }   
">>"                   { return SHIFT_RIGHT; }  

"true"                 { yylval.bool_value = true; return BOOL_VALUE; }  
"false"                { yylval.bool_value = false; return BOOL_VALUE; }

"int"                  { return INT; }   
"float"                { return FLOAT; } 
"double"               { return DOUBLE; }  
"string"               { return STRING; } 
"char"                 { return CHAR; }    
"bool"                 { return BOOL; }    
"long"                 { return LONG; }    
"short"                { return SHORT; }   
"unsigned"             { return UNSIGNED; }
"signed"               { return SIGNED; }  
"void"                 { return VOID; }   

"print"                { return PRINT; }    
"return"               { return RETURN; }   
"if"                   { return IF; }       
"else"                 { return ELSE; }     
"for"                  { return FOR; }      
"while"                { return WHILE; }    
"do"                   { return DO; }       
"switch"               { return SWITCH; }   
"case"                 { return CASE; }    
"default"              { return DEFAULT; }  
"break"                { return BREAK; }    
"continue"             { return CONTINUE; } 

[a-zA-Z_][a-zA-Z0-9_]*    {yylval.string_value = strdup(yytext); return IDENTIFIER;}  /* Identifiers (Variable & Function Names) */

"const[ \t]+[a-zA-Z_][a-zA-Z0-9_]*[ \t]+([a-zA-Z_][a-zA-Z0-9_]*)" { yylval.string_value = strdup($1); return CONSTANT; }  /* Constants */

-?[0-9]+                 { yylval.int_value = atoi(yytext); return INTEGER_VALUE; }  /* Integer */  
-?[0-9]+\.[0-9]+         { yylval.float_value = atof(yytext); return FLOAT_VALUE; }  /* Floating point */

\".*\"        {yylval.string_value = strdup(yytext); return STRING_VALUE;}   /* String Values */

\'.\'         {yylval.string_value = strdup(yytext); return CHAR_VALUE;}    /* Character Values */

[ \t\r\n]+             { /* Ignore spaces, tabs, and newlines */ }   /* Whitespace (Ignored) */

.                      { printf("Unexpected character: %s\n", yytext); }   /* Unrecognized Tokens */

%%              
/* C Code Section */
int yywrap(void) 
{
    return 1;
}

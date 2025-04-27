%{
    #include "Parser.tab.h"
%}
%option yylineno

%%

";"                   {return SEMICOLON;}
","                   {return COMMA;}
[(){}:]               {return *yytext;}

"="        {return ASSIGN;}  
"+"        {return ADD;} 
"++"        {return POST_INC;} 
"-"        {return SUB;}
"--"        {return POST_DEC;} 
"*"        {return MUL;}
"/"        {return DIV;}      
"%"        {return MOD;}
"^"        {return POW;}

"&&"      {return LOGICAL_AND;}
"||"       {return LOGICAL_OR;}
"!"        {return LOGICAL_NOT;}

"=="       {return EQUAL;}
"!="       {return NOT_EQUAL;}
">"        {return GREATER_THAN;}
"<"        {return LESS_THAN;}
">="                   {return GREATER_EQUAL; }
"<="                   {return LESS_EQUAL; }   

"&"        {return BITWISE_AND;}
"|"        {return BITWISE_OR;}
"~"        {return BITWISE_NOT; } 
"<<"       {return SHIFT_LEFT;}
">>"       {return SHIFT_RIGHT;}

"true"     {yylval.bool_type = true; return BOOL_VALUE;}
"false"    {yylval.bool_type = false;return BOOL_VALUE;} 

"int"                  { return INT; }   
"float"                { return FLOAT; }  
"string"               { return STRING; } 
"char"                 {  return CHAR; }    
"bool"                 { return BOOL; }    
"void"                 {  return VOID; }   

"print"    {return PRINT;}
"return"   {return RETURN;}
"if"       {return IF;}
"else"     {return ELSE;}
"for"      {return FOR;}
"while"    {return WHILE;}
"do"       {return DO;}
"switch"   {return SWITCH;}
"case"     {return CASE;}
"break"    {return BREAK;}
"default"  {return DEFAULT;}
"continue" {return CONTINUE; }     

[A-Z]+                 {yylval.string_type = strdup(yytext); return CONSTANT;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.string_type = strdup(yytext); return IDENTIFIER;}

[0-9]+         {yylval.int_type = atoi(yytext); return INTEGER_VALUE;}
-?[0-9]+\.[0-9]+ {yylval.float_type= atof(yytext);return FLOAT_VALUE;}

\".*\"        {yylval.string_type = strdup(yytext); return STRING_VALUE;}
\'.\'         {yylval.string_type = strdup(yytext); return CHAR_VALUE;}

\/\/[\s\t]*.*[\s\t]*  {}
[ \t\r\n]+             { }               
.              {return *yytext;}
%%

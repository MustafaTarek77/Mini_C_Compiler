%{
    #include "Parser.tab.h"
    #include <stdio.h>
    #include <stdlib.h>

    #define LOG_ENABLED 1

    void log_token(const char *token);

%}

%option yylineno

%%

";"                   { 
                        return SEMICOLON; 
                    }

","                   { 
                        return COMMA; 
                    }

[(){}:]               { 
                        return *yytext; 
                    }


"+="        { 
    #if LOG_ENABLED
        log_token("ADD_ASSIGN");
    #endif
    return ADD_ASSIGN;
}  

"-="        { 
    #if LOG_ENABLED
        log_token("SUB_ASSIGN");
    #endif
    return SUB_ASSIGN;
}  

"*="        { 
    #if LOG_ENABLED
        log_token("MUL_ASSIGN");
    #endif
    return MUL_ASSIGN;
}  

"/="        { 
    #if LOG_ENABLED
        log_token("DIV_ASSIGN");
    #endif
    return DIV_ASSIGN;
}  

"%="        { 
    #if LOG_ENABLED
        log_token("MOD_ASSIGN");
    #endif
    return MOD_ASSIGN;
}  

"^="        { 
    #if LOG_ENABLED
        log_token("POW_ASSIGN");
    #endif
    return POW_ASSIGN;
}  

"&&="        { 
    #if LOG_ENABLED
        log_token("LOGICAL_AND_ASSIGN");
    #endif
    return LOGICAL_AND_ASSIGN;
}  

"||="        { 
    #if LOG_ENABLED
        log_token("LOGICAL_OR_ASSIGN");
    #endif
    return LOGICAL_OR_ASSIGN;
}  

"&="        { 
    #if LOG_ENABLED
        log_token("BITWISE_AND_ASSIGN");
    #endif
    return BITWISE_AND_ASSIGN;
}  

"|="        { 
    #if LOG_ENABLED
        log_token("BITWISE_OR_ASSIGN");
    #endif
    return BITWISE_OR_ASSIGN;
}  

"~="        { 
    #if LOG_ENABLED
        log_token("BITWISE_NOT_ASSIGN");
    #endif
    return BITWISE_NOT_ASSIGN;
}  

"<<="        { 
    #if LOG_ENABLED
        log_token("SHIFT_LEFT_ASSIGN");
    #endif
    return SHIFT_LEFT_ASSIGN;
}  

">>="        { 
    #if LOG_ENABLED
        log_token("SHIFT_RIGHT_ASSIGN");
    #endif
    return SHIFT_RIGHT_ASSIGN;
}  

"="        { 
    #if LOG_ENABLED
        log_token("ASSIGN");
    #endif
    return ASSIGN;
}  

"+"        { 
    #if LOG_ENABLED
        log_token("ADD");
    #endif
    return ADD;
} 

"++"        { 
    #if LOG_ENABLED
        log_token("PRE_POST_INC");
    #endif
    return PRE_POST_INC; 
} 

"-"        { 
    #if LOG_ENABLED
        log_token("SUB");
    #endif
    return SUB;
} 

"--"        { 
    #if LOG_ENABLED
        log_token("PRE_POST_DEC");
    #endif
    return PRE_POST_DEC; 
} 

"*"        { 
    #if LOG_ENABLED
        log_token("MUL");
    #endif
    return MUL;
} 

"/"        { 
    #if LOG_ENABLED
        log_token("DIV");
    #endif
    return DIV; 
}      

"%"        { 
    #if LOG_ENABLED
        log_token("MOD");
    #endif
    return MOD;
} 

"^"        { 
    #if LOG_ENABLED
        log_token("POW");
    #endif
    return POW;
}

"&&"      { 
    #if LOG_ENABLED
        log_token("LOGICAL_AND");
    #endif
    return LOGICAL_AND; 
}

"||"       { 
    #if LOG_ENABLED
        log_token("LOGICAL_OR");
    #endif
    return LOGICAL_OR; 
}

"!"        { 
    #if LOG_ENABLED
        log_token("LOGICAL_NOT");
    #endif
    return LOGICAL_NOT; 
}

"=="       { 
    #if LOG_ENABLED
        log_token("EQUAL");
    #endif
    return EQUAL;
}

"!="       { 
    #if LOG_ENABLED
        log_token("NOT_EQUAL");
    #endif
    return NOT_EQUAL; 
}

">"        { 
    #if LOG_ENABLED
        log_token("GREATER_THAN");
    #endif
    return GREATER_THAN;
}

"<"        { 
    #if LOG_ENABLED
        log_token("LESS_THAN");
    #endif
    return LESS_THAN;
}

">="       { 
    #if LOG_ENABLED
        log_token("GREATER_EQUAL");
    #endif
    return GREATER_EQUAL; 
}

"<="       { 
    #if LOG_ENABLED
        log_token("LESS_EQUAL");
    #endif
    return LESS_EQUAL; 
}

"&"        { 
    #if LOG_ENABLED
        log_token("BITWISE_AND");
    #endif
    return BITWISE_AND;
}

"|"        { 
    #if LOG_ENABLED
        log_token("BITWISE_OR");
    #endif
    return BITWISE_OR;
}

"~"        { 
    #if LOG_ENABLED
        log_token("BITWISE_NOT");
    #endif
    return BITWISE_NOT;
} 

"<<"       { 
    #if LOG_ENABLED
        log_token("SHIFT_LEFT");
    #endif
    return SHIFT_LEFT;
}

">>"       { 
    #if LOG_ENABLED
        log_token("SHIFT_RIGHT");
    #endif
    return SHIFT_RIGHT;
}

"true"     { 
    yylval.bool_type = true;
    #if LOG_ENABLED
        log_token("BOOL_VALUE: true");
    #endif
    return BOOL_VALUE;
}

"false"    { 
    yylval.bool_type = false;
    #if LOG_ENABLED
        log_token("BOOL_VALUE: false");
    #endif
    return BOOL_VALUE; 
}

"int"      { 
    #if LOG_ENABLED
        log_token("INT");
    #endif
    return INT;
}

"float"    { 
    #if LOG_ENABLED
        log_token("FLOAT");
    #endif
    return FLOAT;
}

"string"   { 
    #if LOG_ENABLED
        log_token("STRING");
    #endif
    return STRING;
}

"char"     { 
    #if LOG_ENABLED
        log_token("CHAR");
    #endif
    return CHAR;
}

"bool"     { 
    #if LOG_ENABLED
        log_token("BOOL");
    #endif
    return BOOL;
}

"void"     { 
    #if LOG_ENABLED
        log_token("VOID");
    #endif
    return VOID;
}

"print"    { 
    #if LOG_ENABLED
        log_token("PRINT");
    #endif
    return PRINT;
}

"return"   { 
    #if LOG_ENABLED
        log_token("RETURN");
    #endif
    return RETURN;
}

"if"       { 
    #if LOG_ENABLED
        log_token("IF");
    #endif
    return IF;
}

"else"     { 
    #if LOG_ENABLED
        log_token("ELSE");
    #endif
    return ELSE;
}

"for"      { 
    #if LOG_ENABLED
        log_token("FOR");
    #endif
    return FOR;
}

"while"    { 
    #if LOG_ENABLED
        log_token("WHILE");
    #endif
    return WHILE;
}

"do"       { 
    #if LOG_ENABLED
        log_token("DO");
    #endif
    return DO;
}

"switch"   { 
    #if LOG_ENABLED
        log_token("SWITCH");
    #endif
    return SWITCH;
}

"case"     { 
    #if LOG_ENABLED
        log_token("CASE");
    #endif
    return CASE;
}

"break"    { 
    #if LOG_ENABLED
        log_token("BREAK");
    #endif
    return BREAK;
}

"default"  { 
    #if LOG_ENABLED
        log_token("DEFAULT");
    #endif
    return DEFAULT;
}

"continue" { 
    #if LOG_ENABLED
        log_token("CONTINUE");
    #endif
    return CONTINUE;
}

"const"    { 
    #if LOG_ENABLED
        log_token("CONSTANT");
    #endif
    return CONSTANT;
}

[a-zA-Z_][a-zA-Z0-9_]* { 
    yylval.string_type = strdup(yytext);
    #if LOG_ENABLED
        log_token("IDENTIFIER");
    #endif
    return IDENTIFIER; 
}

[0-9]+         {  
    yylval.int_type = atoi(yytext);
    #if LOG_ENABLED
        log_token("INTEGER_VALUE");
    #endif
    return INTEGER_VALUE; 
}

-?[0-9]+\.[0-9]+ { 
    yylval.float_type = atof(yytext);
    #if LOG_ENABLED
        log_token("FLOAT_VALUE");
    #endif
    return FLOAT_VALUE; 
}

\".*\"        { 
    yylval.string_type = strdup(yytext); 
    #if LOG_ENABLED
        log_token("STRING_VALUE");
    #endif
    return STRING_VALUE; 
}

\'.\'         { 
    yylval.string_type = strdup(yytext); 
    #if LOG_ENABLED
        log_token("CHAR_VALUE");
    #endif
    return CHAR_VALUE; 
}

\/\/[\s\t]*.*[\s\t]*  {}

[ \t\r\n]+             { }

.              { 
    #if LOG_ENABLED
        log_token("UNKNOWN TOKEN");
    #endif
    return *yytext;
}

%%

void log_token(const char *token) {
    static int first_call = 1; // Static means it keeps its value between calls

    FILE *log_file;

    if (first_call) {
        log_file = fopen("./output/tokens.log", "w"); // First call: overwrite
        first_call = 0; // Next calls will append
    } else {
        log_file = fopen("./output/tokens.log", "a"); // Append mode
    }

    if (log_file) {
        fprintf(log_file, "Detected Token: %s\n", token);
        fclose(log_file);
    } else {
        fprintf(stderr, "Error opening log file. Make sure the './output/' directory exists.\n");
    }
}

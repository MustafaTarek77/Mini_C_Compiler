/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    DOUBLE = 260,                  /* DOUBLE  */
    CHAR = 261,                    /* CHAR  */
    BOOL = 262,                    /* BOOL  */
    STRING = 263,                  /* STRING  */
    LONG = 264,                    /* LONG  */
    SHORT = 265,                   /* SHORT  */
    SEMICOLON = 266,               /* SEMICOLON  */
    COMMA = 267,                   /* COMMA  */
    ASSIGN = 268,                  /* ASSIGN  */
    ADD = 269,                     /* ADD  */
    SUB = 270,                     /* SUB  */
    MUL = 271,                     /* MUL  */
    DIV = 272,                     /* DIV  */
    MOD = 273,                     /* MOD  */
    POW = 274,                     /* POW  */
    LOGICAL_AND = 275,             /* LOGICAL_AND  */
    LOGICAL_OR = 276,              /* LOGICAL_OR  */
    LOGICAL_NOT = 277,             /* LOGICAL_NOT  */
    EQUAL = 278,                   /* EQUAL  */
    NOT_EQUAL = 279,               /* NOT_EQUAL  */
    GREATER_THAN = 280,            /* GREATER_THAN  */
    LESS_THAN = 281,               /* LESS_THAN  */
    GREATER_EQUAL = 282,           /* GREATER_EQUAL  */
    LESS_EQUAL = 283,              /* LESS_EQUAL  */
    BITWISE_AND = 284,             /* BITWISE_AND  */
    BITWISE_OR = 285,              /* BITWISE_OR  */
    BITWISE_XOR = 286,             /* BITWISE_XOR  */
    BITWISE_NOT = 287,             /* BITWISE_NOT  */
    SHIFT_LEFT = 288,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 289,             /* SHIFT_RIGHT  */
    BOOL_VALUE = 290,              /* BOOL_VALUE  */
    INTEGER_VALUE = 291,           /* INTEGER_VALUE  */
    FLOAT_VALUE = 292,             /* FLOAT_VALUE  */
    STRING_VALUE = 293,            /* STRING_VALUE  */
    CHAR_VALUE = 294,              /* CHAR_VALUE  */
    UNSIGNED = 295,                /* UNSIGNED  */
    SIGNED = 296,                  /* SIGNED  */
    VOID = 297,                    /* VOID  */
    PRINT = 298,                   /* PRINT  */
    RETURN = 299,                  /* RETURN  */
    IF = 300,                      /* IF  */
    ELSE = 301,                    /* ELSE  */
    FOR = 302,                     /* FOR  */
    WHILE = 303,                   /* WHILE  */
    DO = 304,                      /* DO  */
    SWITCH = 305,                  /* SWITCH  */
    CASE = 306,                    /* CASE  */
    DEFAULT = 307,                 /* DEFAULT  */
    BREAK = 308,                   /* BREAK  */
    CONTINUE = 309,                /* CONTINUE  */
    IDENTIFIER = 310,              /* IDENTIFIER  */
    CONSTANT = 311,                /* CONSTANT  */
    IFX = 312                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "Parser.y"

    int int_type;     
    float float_type;  
    double double_type;   
    char char_type;    
    bool bool_type;     
    char *string_type; 
    long long_type;
    short short_type;

#line 132 "Parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

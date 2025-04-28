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
/* "%code requires" blocks.  */
#line 63 "Parser.y"

#include<stdbool.h>

#line 53 "Parser.tab.h"

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
    CHAR = 260,                    /* CHAR  */
    BOOL = 261,                    /* BOOL  */
    STRING = 262,                  /* STRING  */
    PRINT = 263,                   /* PRINT  */
    VOID = 264,                    /* VOID  */
    RETURN = 265,                  /* RETURN  */
    CONTINUE = 266,                /* CONTINUE  */
    SWITCH = 267,                  /* SWITCH  */
    BREAK = 268,                   /* BREAK  */
    CASE = 269,                    /* CASE  */
    DEFAULT = 270,                 /* DEFAULT  */
    IF = 271,                      /* IF  */
    ELSE = 272,                    /* ELSE  */
    FOR = 273,                     /* FOR  */
    WHILE = 274,                   /* WHILE  */
    DO = 275,                      /* DO  */
    BOOL_VALUE = 276,              /* BOOL_VALUE  */
    LOGICAL_AND = 277,             /* LOGICAL_AND  */
    LOGICAL_OR = 278,              /* LOGICAL_OR  */
    LOGICAL_NOT = 279,             /* LOGICAL_NOT  */
    EQUAL = 280,                   /* EQUAL  */
    NOT_EQUAL = 281,               /* NOT_EQUAL  */
    BITWISE_OR = 282,              /* BITWISE_OR  */
    BITWISE_AND = 283,             /* BITWISE_AND  */
    BITWISE = 284,                 /* BITWISE  */
    NOT = 285,                     /* NOT  */
    SEMICOLON = 286,               /* SEMICOLON  */
    COMMA = 287,                   /* COMMA  */
    MOD = 288,                     /* MOD  */
    ADD = 289,                     /* ADD  */
    SUB = 290,                     /* SUB  */
    MUL = 291,                     /* MUL  */
    DIV = 292,                     /* DIV  */
    POW = 293,                     /* POW  */
    SHIFT_LEFT = 294,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 295,             /* SHIFT_RIGHT  */
    GREATER_THAN = 296,            /* GREATER_THAN  */
    LESS_THAN = 297,               /* LESS_THAN  */
    ASSIGN = 298,                  /* ASSIGN  */
    GREATER_EQUAL = 299,           /* GREATER_EQUAL  */
    LESS_EQUAL = 300,              /* LESS_EQUAL  */
    POST_INC = 301,                /* POST_INC  */
    POST_DEC = 302,                /* POST_DEC  */
    CONSTANT = 303,                /* CONSTANT  */
    IDENTIFIER = 304,              /* IDENTIFIER  */
    STRING_VALUE = 305,            /* STRING_VALUE  */
    CHAR_VALUE = 306,              /* CHAR_VALUE  */
    INTEGER_VALUE = 307,           /* INTEGER_VALUE  */
    FLOAT_VALUE = 308,             /* FLOAT_VALUE  */
    PRE_POST_INC = 309,            /* PRE_POST_INC  */
    PRE_POST_DEC = 310,            /* PRE_POST_DEC  */
    BITWISE_NOT = 311              /* BITWISE_NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "Parser.y"
 
 int int_type;
 char* string_type; 
 float float_type;
 bool bool_type;
 char char_type;
 struct Node *node;

#line 135 "Parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

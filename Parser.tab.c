/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Parser.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include "Parser.tab.h"
    #include "globals.h"
    #include "quadruples.cpp"

    int yylex();
    extern FILE *yyin;  
    void yyerror(char* );
    extern int yylineno;  

    FILE *error_output_file = NULL;

    symbol symbol_table[MAX_SYMBOLS];
    int block_counter = 0;
    int symbol_table_index = 0;
    int curr_function_index = 0;
    int curr_function_arg_count = 0;
    int called_function_index = 0;
    int is_argument = 0;
    int is_loop = 0;
    int has_return = 0;
    int is_plus = 0;
    int insertion_index = -1;

    
    void check_mem_alloc(Node *node);
    Node *create_node(char *type);
    Node *check_valid_types_arithmetic(Node *operand1, Node *operand2, int curr_line);
    Node *check_valid_types_bool(Node *operand1, Node *operand2, int curr_line);
    Node *check_valid_types_bitwise(Node *operand1, Node *operand2, int curr_line);
    Node *check_valid_types_bitwise_not(Node *operand1, int curr_line);
    void end_scope(int line_number);
    int get_symbol_declaration_line(char *identifier);
    int add_symbol(char *ident_data_type, char *identifier, char *type, int line_number, bool is_function_parameter);
    int check_symbol(char *identifier, bool is_assigned, int line_number);
    void check_integer(int index, int value, int line_number);
    void check_float(int index, float value, int line_number);
    void check_bool(int index, bool value, int line_number);
    void check_string(int index, char *value, int line_number);
    void check_char(int index, char *value, int line_number);
    void check_variable_type(int i, int line_number);
    void check_value_type(char *ident_data_type, int line_number);
    void check_function_argument_count(int i, int line_number);
    void pop_function_parameters(int index);
    void write_symbol_table_to_file(const char *filename);
    void write_unused_symbols_to_file(const char *filename);


#line 124 "Parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_BOOL = 6,                       /* BOOL  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_PRINT = 8,                      /* PRINT  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_SWITCH = 12,                    /* SWITCH  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_BOOL_VALUE = 21,                /* BOOL_VALUE  */
  YYSYMBOL_LOGICAL_AND = 22,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 23,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 24,               /* LOGICAL_NOT  */
  YYSYMBOL_EQUAL = 25,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 26,                 /* NOT_EQUAL  */
  YYSYMBOL_BITWISE_OR = 27,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_AND = 28,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_NOT = 29,               /* BITWISE_NOT  */
  YYSYMBOL_SEMICOLON = 30,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_ADD = 33,                       /* ADD  */
  YYSYMBOL_SUB = 34,                       /* SUB  */
  YYSYMBOL_MUL = 35,                       /* MUL  */
  YYSYMBOL_DIV = 36,                       /* DIV  */
  YYSYMBOL_POW = 37,                       /* POW  */
  YYSYMBOL_SHIFT_LEFT = 38,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 39,               /* SHIFT_RIGHT  */
  YYSYMBOL_GREATER_THAN = 40,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 41,                 /* LESS_THAN  */
  YYSYMBOL_ASSIGN = 42,                    /* ASSIGN  */
  YYSYMBOL_GREATER_EQUAL = 43,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 44,                /* LESS_EQUAL  */
  YYSYMBOL_POST_INC = 45,                  /* POST_INC  */
  YYSYMBOL_POST_DEC = 46,                  /* POST_DEC  */
  YYSYMBOL_CONSTANT = 47,                  /* CONSTANT  */
  YYSYMBOL_IDENTIFIER = 48,                /* IDENTIFIER  */
  YYSYMBOL_STRING_VALUE = 49,              /* STRING_VALUE  */
  YYSYMBOL_CHAR_VALUE = 50,                /* CHAR_VALUE  */
  YYSYMBOL_INTEGER_VALUE = 51,             /* INTEGER_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 52,               /* FLOAT_VALUE  */
  YYSYMBOL_ADD_ASSIGN = 53,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 54,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 55,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 56,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 57,                /* MOD_ASSIGN  */
  YYSYMBOL_POW_ASSIGN = 58,                /* POW_ASSIGN  */
  YYSYMBOL_BITWISE_AND_ASSIGN = 59,        /* BITWISE_AND_ASSIGN  */
  YYSYMBOL_BITWISE_OR_ASSIGN = 60,         /* BITWISE_OR_ASSIGN  */
  YYSYMBOL_BITWISE_NOT_ASSIGN = 61,        /* BITWISE_NOT_ASSIGN  */
  YYSYMBOL_LOGICAL_AND_ASSIGN = 62,        /* LOGICAL_AND_ASSIGN  */
  YYSYMBOL_LOGICAL_OR_ASSIGN = 63,         /* LOGICAL_OR_ASSIGN  */
  YYSYMBOL_SHIFT_LEFT_ASSIGN = 64,         /* SHIFT_LEFT_ASSIGN  */
  YYSYMBOL_SHIFT_RIGHT_ASSIGN = 65,        /* SHIFT_RIGHT_ASSIGN  */
  YYSYMBOL_PRE_POST_INC = 66,              /* PRE_POST_INC  */
  YYSYMBOL_PRE_POST_DEC = 67,              /* PRE_POST_DEC  */
  YYSYMBOL_68_ = 68,                       /* '{'  */
  YYSYMBOL_69_ = 69,                       /* '}'  */
  YYSYMBOL_70_ = 70,                       /* '('  */
  YYSYMBOL_71_ = 71,                       /* ')'  */
  YYSYMBOL_72_ = 72,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_program = 74,                   /* program  */
  YYSYMBOL_block = 75,                     /* block  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_conditional_statement = 78,     /* conditional_statement  */
  YYSYMBOL_if_wrapper = 79,                /* if_wrapper  */
  YYSYMBOL_80_2 = 80,                      /* $@2  */
  YYSYMBOL_if_statement = 81,              /* if_statement  */
  YYSYMBOL_82_3 = 82,                      /* $@3  */
  YYSYMBOL_83_4 = 83,                      /* $@4  */
  YYSYMBOL_else_statement = 84,            /* else_statement  */
  YYSYMBOL_while_wrapper = 85,             /* while_wrapper  */
  YYSYMBOL_86_5 = 86,                      /* $@5  */
  YYSYMBOL_while_statement = 87,           /* while_statement  */
  YYSYMBOL_88_6 = 88,                      /* $@6  */
  YYSYMBOL_do_while_wrapper = 89,          /* do_while_wrapper  */
  YYSYMBOL_90_7 = 90,                      /* $@7  */
  YYSYMBOL_do_while_statement = 91,        /* do_while_statement  */
  YYSYMBOL_switch_wrapper = 92,            /* switch_wrapper  */
  YYSYMBOL_93_8 = 93,                      /* $@8  */
  YYSYMBOL_switch_statement = 94,          /* switch_statement  */
  YYSYMBOL_95_9 = 95,                      /* $@9  */
  YYSYMBOL_default_statement = 96,         /* default_statement  */
  YYSYMBOL_case_statement = 97,            /* case_statement  */
  YYSYMBOL_98_10 = 98,                     /* $@10  */
  YYSYMBOL_99_11 = 99,                     /* $@11  */
  YYSYMBOL_100_12 = 100,                   /* $@12  */
  YYSYMBOL_101_13 = 101,                   /* $@13  */
  YYSYMBOL_for_wrapper = 102,              /* for_wrapper  */
  YYSYMBOL_103_14 = 103,                   /* $@14  */
  YYSYMBOL_104_15 = 104,                   /* $@15  */
  YYSYMBOL_105_16 = 105,                   /* $@16  */
  YYSYMBOL_106_17 = 106,                   /* $@17  */
  YYSYMBOL_declaration_statement = 107,    /* declaration_statement  */
  YYSYMBOL_108_18 = 108,                   /* $@18  */
  YYSYMBOL_109_19 = 109,                   /* $@19  */
  YYSYMBOL_110_20 = 110,                   /* $@20  */
  YYSYMBOL_assignment_statement = 111,     /* assignment_statement  */
  YYSYMBOL_112_21 = 112,                   /* $@21  */
  YYSYMBOL_113_22 = 113,                   /* $@22  */
  YYSYMBOL_114_23 = 114,                   /* $@23  */
  YYSYMBOL_115_24 = 115,                   /* $@24  */
  YYSYMBOL_116_25 = 116,                   /* $@25  */
  YYSYMBOL_117_26 = 117,                   /* $@26  */
  YYSYMBOL_118_27 = 118,                   /* $@27  */
  YYSYMBOL_119_28 = 119,                   /* $@28  */
  YYSYMBOL_120_29 = 120,                   /* $@29  */
  YYSYMBOL_121_30 = 121,                   /* $@30  */
  YYSYMBOL_122_31 = 122,                   /* $@31  */
  YYSYMBOL_123_32 = 123,                   /* $@32  */
  YYSYMBOL_124_33 = 124,                   /* $@33  */
  YYSYMBOL_125_34 = 125,                   /* $@34  */
  YYSYMBOL_print_statement = 126,          /* print_statement  */
  YYSYMBOL_127_35 = 127,                   /* $@35  */
  YYSYMBOL_data_type = 128,                /* data_type  */
  YYSYMBOL_expression = 129,               /* expression  */
  YYSYMBOL_return_statement = 130,         /* return_statement  */
  YYSYMBOL_function_call = 131,            /* function_call  */
  YYSYMBOL_132_36 = 132,                   /* $@36  */
  YYSYMBOL_133_37 = 133,                   /* $@37  */
  YYSYMBOL_134_38 = 134,                   /* $@38  */
  YYSYMBOL_arguments_list = 135,           /* arguments_list  */
  YYSYMBOL_136_39 = 136,                   /* $@39  */
  YYSYMBOL_function_declaration = 137,     /* function_declaration  */
  YYSYMBOL_138_40 = 138,                   /* $@40  */
  YYSYMBOL_139_41 = 139,                   /* $@41  */
  YYSYMBOL_parameters_list = 140,          /* parameters_list  */
  YYSYMBOL_141_42 = 141                    /* $@42  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   945

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      70,    71,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,     2,    69,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   108,   111,   111,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   127,   128,   129,   130,
     131,   135,   135,   142,   144,   141,   149,   150,   151,   155,
     155,   162,   161,   168,   168,   174,   179,   179,   186,   185,
     197,   202,   209,   201,   214,   221,   213,   225,   226,   231,
     233,   235,   238,   230,   246,   245,   255,   254,   263,   262,
     275,   274,   289,   288,   305,   304,   321,   320,   337,   336,
     353,   352,   369,   368,   385,   384,   401,   400,   417,   416,
     433,   432,   449,   448,   465,   464,   481,   480,   500,   499,
     510,   514,   518,   522,   526,   530,   539,   543,   548,   556,
     565,   573,   582,   590,   597,   603,   609,   615,   621,   627,
     632,   638,   644,   651,   656,   661,   666,   671,   677,   682,
     687,   692,   698,   703,   709,   714,   720,   725,   730,   735,
     743,   744,   754,   759,   761,   753,   774,   773,   778,   782,
     787,   791,   786,   804,   803,   808,   812
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "BOOL", "STRING", "PRINT", "VOID", "RETURN", "CONTINUE", "SWITCH",
  "BREAK", "CASE", "DEFAULT", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BOOL_VALUE", "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "EQUAL",
  "NOT_EQUAL", "BITWISE_OR", "BITWISE_AND", "BITWISE_NOT", "SEMICOLON",
  "COMMA", "MOD", "ADD", "SUB", "MUL", "DIV", "POW", "SHIFT_LEFT",
  "SHIFT_RIGHT", "GREATER_THAN", "LESS_THAN", "ASSIGN", "GREATER_EQUAL",
  "LESS_EQUAL", "POST_INC", "POST_DEC", "CONSTANT", "IDENTIFIER",
  "STRING_VALUE", "CHAR_VALUE", "INTEGER_VALUE", "FLOAT_VALUE",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "POW_ASSIGN", "BITWISE_AND_ASSIGN", "BITWISE_OR_ASSIGN",
  "BITWISE_NOT_ASSIGN", "LOGICAL_AND_ASSIGN", "LOGICAL_OR_ASSIGN",
  "SHIFT_LEFT_ASSIGN", "SHIFT_RIGHT_ASSIGN", "PRE_POST_INC",
  "PRE_POST_DEC", "'{'", "'}'", "'('", "')'", "':'", "$accept", "program",
  "block", "$@1", "statement", "conditional_statement", "if_wrapper",
  "$@2", "if_statement", "$@3", "$@4", "else_statement", "while_wrapper",
  "$@5", "while_statement", "$@6", "do_while_wrapper", "$@7",
  "do_while_statement", "switch_wrapper", "$@8", "switch_statement", "$@9",
  "default_statement", "case_statement", "$@10", "$@11", "$@12", "$@13",
  "for_wrapper", "$@14", "$@15", "$@16", "$@17", "declaration_statement",
  "$@18", "$@19", "$@20", "assignment_statement", "$@21", "$@22", "$@23",
  "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32",
  "$@33", "$@34", "print_statement", "$@35", "data_type", "expression",
  "return_statement", "function_call", "$@36", "$@37", "$@38",
  "arguments_list", "$@39", "function_declaration", "$@40", "$@41",
  "parameters_list", "$@42", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-146)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -186,   193,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
     254,   -19,   -16,   -47,  -186,   254,   254,   254,   114,   404,
    -186,  -186,  -186,  -186,    -4,    -1,  -186,   254,  -186,  -186,
    -186,  -186,    26,  -186,    33,  -186,    50,  -186,    60,  -186,
    -186,  -186,  -186,    51,    23,    94,  -186,  -186,    57,  -186,
     -57,   821,  -186,  -186,  -186,    95,    95,     4,    85,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,    64,  -186,  -186,  -186,    -6,
     254,  -186,   254,  -186,    77,  -186,    78,  -186,   -27,   254,
     254,   254,   254,   254,   254,  -186,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,  -186,   254,
     329,  -186,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,  -186,   261,  -186,   821,
     821,   131,   104,   109,   123,    86,   861,   841,   147,   147,
     881,   901,    95,     4,     4,    95,    95,    95,    42,    42,
     196,   196,   196,   196,   103,  -186,   113,   453,   476,   499,
     522,   545,   568,   591,   614,   637,   660,   683,   706,   729,
     752,   254,  -186,    77,    77,    87,  -186,   254,  -186,   114,
     128,   329,   254,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,   378,  -186,  -186,
    -186,   254,    88,   775,   112,    92,  -186,  -186,   798,   133,
      96,   148,   401,    98,  -186,    99,  -186,   329,  -186,   254,
    -186,   -14,  -186,   141,   -10,   144,    77,   105,  -186,  -186,
    -186,  -186,   -26,   117,  -186,   125,   114,  -186,  -186,  -186,
    -186,    77,  -186,  -186,    77,   135,   136,  -186,  -186,    77,
      77,  -186,  -186,   -10,   -10,  -186,  -186
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    21,     1,    90,    91,    93,    94,    92,    88,    95,
     130,     0,     0,     0,   106,     0,     0,     0,   103,    98,
     107,   108,   104,   105,     0,     0,     4,     0,     6,     2,
      11,    16,     0,    17,     0,    18,     0,    19,     0,    20,
       7,     8,    10,     0,     0,     0,    97,    12,     0,   103,
      98,   131,    14,    13,    49,   110,   111,   109,     0,    60,
      62,    64,    66,    68,    72,    70,    78,    80,    82,    74,
      76,    84,    86,    99,   100,     0,   101,   102,     3,     0,
       0,    22,     0,    30,     0,    34,     0,    37,    54,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
      21,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,    21,    96,    23,
      31,     0,     0,     0,     0,     0,   122,   123,   124,   125,
     118,   119,   117,   112,   113,   114,   115,   116,   120,   121,
     126,   128,   127,   129,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,     5,     0,     0,     0,    38,     0,    57,   146,
       0,    21,     0,    61,    63,    65,    67,    69,    73,    71,
      79,    81,    83,    75,    77,    85,    87,   136,   134,    24,
      32,     0,     0,     0,     0,     0,    89,    51,     0,     0,
       0,    28,     0,     0,    55,   143,   141,    21,    59,   139,
     135,     0,    25,     0,    48,     0,     0,     0,   137,    26,
      27,    35,     0,     0,    47,     0,   146,   142,    52,    44,
      41,     0,    39,   144,     0,     0,     0,    40,    53,     0,
       0,    45,    42,    48,    48,    46,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,   137,   -72,  -186,   -95,  -186,  -186,  -186,   -12,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -185,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,   -18,    -9,  -186,  -186,  -186,
    -186,  -186,   -24,  -186,  -186,  -186,  -186,   -20,  -186
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    28,    78,    29,    30,    31,    32,    81,   173,
     211,   222,    33,    34,    83,   174,    35,    36,    85,    37,
      38,    87,   202,   234,   235,   246,   254,   245,   253,    39,
     110,   181,   217,   244,    40,   133,   134,   156,    41,   112,
     113,   114,   115,   116,   118,   117,   122,   123,   119,   120,
     121,   124,   125,    42,    48,    43,    44,    45,    46,    75,
     171,   210,   198,   209,    47,   135,   226,   205,   225
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    51,    80,   -56,   232,   233,    55,    56,    57,    73,
      74,    52,   131,  -132,    53,   155,    89,    90,    79,    91,
      92,    93,    94,    54,   239,   240,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    96,   106,   107,    99,
     100,   101,    80,  -140,    76,    89,    90,    77,    91,    92,
      93,    94,    82,    95,    26,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   128,   106,   107,   255,   256,
      84,   129,    86,   130,    96,    97,    98,    99,   100,   101,
     136,   137,   138,   139,   140,   141,   207,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    88,
     154,   199,   200,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     3,     4,     5,
       6,     7,   227,     9,   108,    89,    90,   109,    91,    92,
      93,    94,   101,   111,   126,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    26,   106,   107,   132,   229,
     175,   177,   176,   178,   237,   182,   179,   201,   206,   213,
     215,   204,   197,   216,   219,   221,   224,   220,   203,   247,
    -145,   231,   248,   208,   180,   236,   238,   251,   252,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   241,
     106,   107,   212,     2,   242,   228,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   -36,    12,   249,   250,   230,
     197,    13,   -29,   -33,    14,   127,   243,    15,   204,     0,
       0,     0,    16,     0,     0,     0,     0,    17,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,    26,     0,    27,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   -36,    12,    14,     0,     0,    15,    13,
     -29,   -33,    14,    16,     0,    15,     0,     0,    17,     0,
      16,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,    49,    50,    20,    21,    22,    23,     0,    18,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,    27,     0,     0,    24,    25,    26,
     172,    27,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   -36,    12,     0,     0,     0,     0,    13,   -29,   -33,
      14,     0,     0,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,    26,     0,    27,
      89,    90,     0,    91,    92,    93,    94,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,   107,    89,    90,     0,    91,    92,    93,    94,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107,    59,     0,     0,  -138,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   223,     0,  -132,    89,    90,     0,    91,    92,
      93,    94,     0,   183,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,   107,    89,    90,
       0,    91,    92,    93,    94,     0,   184,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
     107,    89,    90,     0,    91,    92,    93,    94,     0,   185,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,   107,    89,    90,     0,    91,    92,    93,
      94,     0,   186,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,   107,    89,    90,     0,
      91,    92,    93,    94,     0,   187,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,   107,
      89,    90,     0,    91,    92,    93,    94,     0,   188,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,   107,    89,    90,     0,    91,    92,    93,    94,
       0,   189,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107,    89,    90,     0,    91,
      92,    93,    94,     0,   190,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,   107,    89,
      90,     0,    91,    92,    93,    94,     0,   191,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,   107,    89,    90,     0,    91,    92,    93,    94,     0,
     192,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,   107,    89,    90,     0,    91,    92,
      93,    94,     0,   193,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,   107,    89,    90,
       0,    91,    92,    93,    94,     0,   194,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
     107,    89,    90,     0,    91,    92,    93,    94,     0,   195,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,   107,    89,    90,     0,    91,    92,    93,
      94,     0,   196,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,   107,    89,    90,     0,
      91,    92,    93,    94,     0,   214,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,   107,
      89,    90,     0,    91,    92,    93,    94,     0,   218,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,   107,    89,    90,     0,    91,    92,    93,    94,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    89,   106,   107,    91,    92,    93,    94,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107,    91,    92,    93,    94,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107,    91,    92,     0,    94,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107,    91,    92,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107
};

static const yytype_int16 yycheck[] =
{
      18,    10,    16,    30,    14,    15,    15,    16,    17,    66,
      67,    30,    84,    70,    30,   110,    22,    23,    27,    25,
      26,    27,    28,    70,    50,    51,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    32,    43,    44,    35,
      36,    37,    16,    70,    48,    22,    23,    48,    25,    26,
      27,    28,    19,    30,    68,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    71,    43,    44,   253,   254,
      20,    80,    12,    82,    32,    33,    34,    35,    36,    37,
      89,    90,    91,    92,    93,    94,   181,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    48,
     109,   173,   174,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     3,     4,     5,
       6,     7,   217,     9,    30,    22,    23,    70,    25,    26,
      27,    28,    37,    48,    70,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    68,    43,    44,    70,   221,
      19,    42,    48,    30,   226,    42,    70,    70,    30,    71,
      48,   179,   171,    71,    31,    17,    68,    71,   177,   241,
      71,    30,   244,   182,    71,    31,    71,   249,   250,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    72,
      43,    44,   201,     0,    69,   219,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    72,    72,   221,
     219,    18,    19,    20,    21,    78,   236,    24,   236,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    70,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    21,    -1,    -1,    24,    18,
      19,    20,    21,    29,    -1,    24,    -1,    -1,    34,    -1,
      29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    -1,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    70,    -1,    -1,    66,    67,    68,
      69,    70,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,
      22,    23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    22,    23,    -1,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    42,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    71,    -1,    70,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    22,    23,
      -1,    25,    26,    27,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      44,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    22,    23,    -1,    25,    26,    27,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    22,    23,    -1,    25,
      26,    27,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    22,
      23,    -1,    25,    26,    27,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    22,    23,    -1,    25,    26,    27,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    44,    22,    23,    -1,    25,    26,
      27,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    22,    23,
      -1,    25,    26,    27,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      44,    22,    23,    -1,    25,    26,    27,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    22,    23,    -1,    25,    26,    27,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      22,    23,    -1,    25,    26,    27,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    22,    23,    -1,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    22,    43,    44,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    25,    26,    -1,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    25,    26,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    13,    18,    21,    24,    29,    34,    47,    48,
      49,    50,    51,    52,    66,    67,    68,    70,    75,    77,
      78,    79,    80,    85,    86,    89,    90,    92,    93,   102,
     107,   111,   126,   128,   129,   130,   131,   137,   127,    47,
      48,   129,    30,    30,    70,   129,   129,   129,   128,    42,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   132,    48,    48,    76,   129,
      16,    81,    19,    87,    20,    91,    12,    94,    48,    22,
      23,    25,    26,    27,    28,    30,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    43,    44,    30,    70,
     103,    48,   112,   113,   114,   115,   116,   118,   117,   121,
     122,   123,   119,   120,   124,   125,    70,    74,    71,   129,
     129,    75,    70,   108,   109,   138,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,    77,   110,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   133,    69,    82,    88,    19,    48,    42,    30,    70,
      71,   104,    42,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,   129,   135,    75,
      75,    70,    95,   129,   128,   140,    30,    77,   129,   136,
     134,    83,   129,    71,    30,    48,    71,   105,    30,    31,
      71,    17,    84,    71,    68,   141,   139,    77,   135,    75,
      81,    30,    14,    15,    96,    97,    31,    75,    71,    50,
      51,    72,    69,   140,   106,   100,    98,    75,    75,    72,
      72,    75,    75,   101,    99,    97,    97
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    74,    76,    75,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    78,    78,
      78,    80,    79,    82,    83,    81,    84,    84,    84,    86,
      85,    88,    87,    90,    89,    91,    93,    92,    95,    94,
      96,    98,    99,    97,   100,   101,    97,    97,    97,   103,
     104,   105,   106,   102,   108,   107,   109,   107,   110,   107,
     112,   111,   113,   111,   114,   111,   115,   111,   116,   111,
     117,   111,   118,   111,   119,   111,   120,   111,   121,   111,
     122,   111,   123,   111,   124,   111,   125,   111,   127,   126,
     128,   128,   128,   128,   128,   128,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   132,   133,   134,   131,   136,   135,   135,   135,
     138,   139,   137,   141,   140,   140,   140
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     4,     1,     1,     1,     2,
       1,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     0,     2,     0,     0,     6,     2,     2,     0,     0,
       2,     0,     4,     0,     2,     7,     0,     2,     0,     8,
       3,     0,     0,     7,     0,     0,     7,     1,     0,     0,
       0,     0,     0,    11,     0,     6,     0,     4,     0,     7,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     6,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     0,     0,     0,     7,     0,     4,     1,     0,
       0,     0,     8,     0,     5,     2,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* $@1: %empty  */
#line 111 "Parser.y"
            {block_counter++;}
#line 1586 "Parser.tab.c"
    break;

  case 5: /* block: '{' $@1 program '}'  */
#line 111 "Parser.y"
                                           {end_scope(yylineno);}
#line 1592 "Parser.tab.c"
    break;

  case 13: /* statement: BREAK SEMICOLON  */
#line 121 "Parser.y"
                             {jump_to_end_of_loop();}
#line 1598 "Parser.tab.c"
    break;

  case 14: /* statement: CONTINUE SEMICOLON  */
#line 122 "Parser.y"
                                 {fprintf(quadrupleFilePointer, "\tcontinue\n");}
#line 1604 "Parser.tab.c"
    break;

  case 15: /* statement: return_statement SEMICOLON  */
#line 123 "Parser.y"
                                        {fprintf(quadrupleFilePointer, "\treturn\n");}
#line 1610 "Parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 135 "Parser.y"
      { push_if_end_label(++loop_end_counter); }
#line 1616 "Parser.tab.c"
    break;

  case 22: /* if_wrapper: $@2 if_statement  */
#line 137 "Parser.y"
      { pop_if_end_label(); }
#line 1622 "Parser.tab.c"
    break;

  case 23: /* $@3: %empty  */
#line 142 "Parser.y"
      { jump_if_false(++false_label_counter); }
#line 1628 "Parser.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 144 "Parser.y"
      { jump_to_end_of_if(); pop_last_false_label(); }
#line 1634 "Parser.tab.c"
    break;

  case 29: /* $@5: %empty  */
#line 155 "Parser.y"
      { push_start_label(++loop_start_counter, "while"); }
#line 1640 "Parser.tab.c"
    break;

  case 30: /* while_wrapper: $@5 while_statement  */
#line 157 "Parser.y"
      { pop_start_label(); }
#line 1646 "Parser.tab.c"
    break;

  case 31: /* $@6: %empty  */
#line 162 "Parser.y"
      { jump_if_false(++false_label_counter); }
#line 1652 "Parser.tab.c"
    break;

  case 32: /* while_statement: WHILE expression $@6 block  */
#line 164 "Parser.y"
      { jump_to_start_of_loop("while"); pop_last_false_label(); }
#line 1658 "Parser.tab.c"
    break;

  case 33: /* $@7: %empty  */
#line 168 "Parser.y"
      { push_start_label(++loop_start_counter, "do_while"); }
#line 1664 "Parser.tab.c"
    break;

  case 34: /* do_while_wrapper: $@7 do_while_statement  */
#line 170 "Parser.y"
      { pop_start_label(); }
#line 1670 "Parser.tab.c"
    break;

  case 35: /* do_while_statement: DO block WHILE '(' expression ')' SEMICOLON  */
#line 175 "Parser.y"
      { jump_if_false(++false_label_counter); jump_to_start_of_loop("do_while"); pop_last_false_label(); }
#line 1676 "Parser.tab.c"
    break;

  case 36: /* $@8: %empty  */
#line 179 "Parser.y"
      { push_end_label(++loop_end_counter); }
#line 1682 "Parser.tab.c"
    break;

  case 37: /* switch_wrapper: $@8 switch_statement  */
#line 181 "Parser.y"
      { pop_end_label(); }
#line 1688 "Parser.tab.c"
    break;

  case 38: /* $@9: %empty  */
#line 186 "Parser.y"
    { 
        push_switch_identifier((yyvsp[0].string_type));
        check_symbol((yyvsp[0].string_type), 0, yylineno); 
    }
#line 1697 "Parser.tab.c"
    break;

  case 39: /* switch_statement: SWITCH '(' IDENTIFIER $@9 ')' '{' case_statement '}'  */
#line 191 "Parser.y"
    { 
        pop_switch_identifier(); 
    }
#line 1705 "Parser.tab.c"
    break;

  case 41: /* $@10: %empty  */
#line 202 "Parser.y"
    { 
        push_case_value();
        fprintf(quadrupleFilePointer, "\tpush %d\n", (yyvsp[0].int_type));
        fprintf(quadrupleFilePointer, "\t%s\n", "equal");
        jump_if_false(++false_label_counter); 
    }
#line 1716 "Parser.tab.c"
    break;

  case 42: /* $@11: %empty  */
#line 209 "Parser.y"
    { 
        pop_last_false_label(); 
    }
#line 1724 "Parser.tab.c"
    break;

  case 44: /* $@12: %empty  */
#line 214 "Parser.y"
    { 
        push_case_value();
        fprintf(quadrupleFilePointer, "\tpush '%s'\n", (yyvsp[0].string_type));
        fprintf(quadrupleFilePointer, "\t%s\n", "equal");
        jump_if_false(++false_label_counter); 
    }
#line 1735 "Parser.tab.c"
    break;

  case 45: /* $@13: %empty  */
#line 221 "Parser.y"
    { 
        pop_last_false_label(); 
    }
#line 1743 "Parser.tab.c"
    break;

  case 49: /* $@14: %empty  */
#line 231 "Parser.y"
        { is_loop = 1; }
#line 1749 "Parser.tab.c"
    break;

  case 50: /* $@15: %empty  */
#line 233 "Parser.y"
        { push_start_label(++loop_start_counter, "for"); }
#line 1755 "Parser.tab.c"
    break;

  case 51: /* $@16: %empty  */
#line 235 "Parser.y"
        { jump_if_false(++false_label_counter); }
#line 1761 "Parser.tab.c"
    break;

  case 52: /* $@17: %empty  */
#line 238 "Parser.y"
      { is_loop = 0; }
#line 1767 "Parser.tab.c"
    break;

  case 53: /* for_wrapper: FOR '(' $@14 statement $@15 statement $@16 statement ')' $@17 block  */
#line 240 "Parser.y"
      { jump_to_start_of_loop("for"); pop_last_false_label(); }
#line 1773 "Parser.tab.c"
    break;

  case 54: /* $@18: %empty  */
#line 246 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "variable", yylineno, false); 
    }
#line 1781 "Parser.tab.c"
    break;

  case 55: /* declaration_statement: data_type IDENTIFIER $@18 ASSIGN expression SEMICOLON  */
#line 250 "Parser.y"
    { 
        insertion_index = -1;
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
    }
#line 1790 "Parser.tab.c"
    break;

  case 56: /* $@19: %empty  */
#line 255 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "variable", yylineno, false); 
    }
#line 1798 "Parser.tab.c"
    break;

  case 57: /* declaration_statement: data_type IDENTIFIER $@19 SEMICOLON  */
#line 259 "Parser.y"
    { 
        insertion_index = -1; 
    }
#line 1806 "Parser.tab.c"
    break;

  case 58: /* $@20: %empty  */
#line 263 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "constant", yylineno, false); 
    }
#line 1814 "Parser.tab.c"
    break;

  case 59: /* declaration_statement: CONSTANT data_type IDENTIFIER $@20 ASSIGN expression SEMICOLON  */
#line 267 "Parser.y"
    { 
        insertion_index = -1; 
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
    }
#line 1823 "Parser.tab.c"
    break;

  case 60: /* $@21: %empty  */
#line 275 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
    }
#line 1836 "Parser.tab.c"
    break;

  case 61: /* assignment_statement: IDENTIFIER ASSIGN $@21 expression SEMICOLON  */
#line 284 "Parser.y"
    { 
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 1845 "Parser.tab.c"
    break;

  case 62: /* $@22: %empty  */
#line 289 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 1859 "Parser.tab.c"
    break;

  case 63: /* assignment_statement: IDENTIFIER ADD_ASSIGN $@22 expression SEMICOLON  */
#line 299 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tadd\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 1869 "Parser.tab.c"
    break;

  case 64: /* $@23: %empty  */
#line 305 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 1883 "Parser.tab.c"
    break;

  case 65: /* assignment_statement: IDENTIFIER SUB_ASSIGN $@23 expression SEMICOLON  */
#line 315 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tsub\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 1893 "Parser.tab.c"
    break;

  case 66: /* $@24: %empty  */
#line 321 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 1907 "Parser.tab.c"
    break;

  case 67: /* assignment_statement: IDENTIFIER MUL_ASSIGN $@24 expression SEMICOLON  */
#line 331 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tmul\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 1917 "Parser.tab.c"
    break;

  case 68: /* $@25: %empty  */
#line 337 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 1931 "Parser.tab.c"
    break;

  case 69: /* assignment_statement: IDENTIFIER DIV_ASSIGN $@25 expression SEMICOLON  */
#line 347 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tdiv\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 1941 "Parser.tab.c"
    break;

  case 70: /* $@26: %empty  */
#line 353 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 1955 "Parser.tab.c"
    break;

  case 71: /* assignment_statement: IDENTIFIER POW_ASSIGN $@26 expression SEMICOLON  */
#line 363 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tpow\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 1965 "Parser.tab.c"
    break;

  case 72: /* $@27: %empty  */
#line 369 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 1979 "Parser.tab.c"
    break;

  case 73: /* assignment_statement: IDENTIFIER MOD_ASSIGN $@27 expression SEMICOLON  */
#line 379 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tmod\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 1989 "Parser.tab.c"
    break;

  case 74: /* $@28: %empty  */
#line 385 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 2003 "Parser.tab.c"
    break;

  case 75: /* assignment_statement: IDENTIFIER LOGICAL_AND_ASSIGN $@28 expression SEMICOLON  */
#line 395 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tlogical_and\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 2013 "Parser.tab.c"
    break;

  case 76: /* $@29: %empty  */
#line 401 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 2027 "Parser.tab.c"
    break;

  case 77: /* assignment_statement: IDENTIFIER LOGICAL_OR_ASSIGN $@29 expression SEMICOLON  */
#line 411 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tlogical_or\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 2037 "Parser.tab.c"
    break;

  case 78: /* $@30: %empty  */
#line 417 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 2051 "Parser.tab.c"
    break;

  case 79: /* assignment_statement: IDENTIFIER BITWISE_AND_ASSIGN $@30 expression SEMICOLON  */
#line 427 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tbitwise_and\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 2061 "Parser.tab.c"
    break;

  case 80: /* $@31: %empty  */
#line 433 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 2075 "Parser.tab.c"
    break;

  case 81: /* assignment_statement: IDENTIFIER BITWISE_OR_ASSIGN $@31 expression SEMICOLON  */
#line 443 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tbitwise_or\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 2085 "Parser.tab.c"
    break;

  case 82: /* $@32: %empty  */
#line 449 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 2099 "Parser.tab.c"
    break;

  case 83: /* assignment_statement: IDENTIFIER BITWISE_NOT_ASSIGN $@32 expression SEMICOLON  */
#line 459 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tbitwise_not\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 2109 "Parser.tab.c"
    break;

  case 84: /* $@33: %empty  */
#line 465 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 2123 "Parser.tab.c"
    break;

  case 85: /* assignment_statement: IDENTIFIER SHIFT_LEFT_ASSIGN $@33 expression SEMICOLON  */
#line 475 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tshift_left\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 2133 "Parser.tab.c"
    break;

  case 86: /* $@34: %empty  */
#line 481 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(strcmp(symbol_table[insertion_index].type , "constant")==0){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            fprintf(error_output_file, "Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE);
        }
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
    }
#line 2147 "Parser.tab.c"
    break;

  case 87: /* assignment_statement: IDENTIFIER SHIFT_RIGHT_ASSIGN $@34 expression SEMICOLON  */
#line 491 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tshift_right\n");
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
        insertion_index = -1;
    }
#line 2157 "Parser.tab.c"
    break;

  case 88: /* $@35: %empty  */
#line 500 "Parser.y"
    { 
        insertion_index = -1;
    }
#line 2165 "Parser.tab.c"
    break;

  case 89: /* print_statement: PRINT $@35 '(' expression ')' SEMICOLON  */
#line 504 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\t%s\n", "print");
    }
#line 2173 "Parser.tab.c"
    break;

  case 90: /* data_type: INT  */
#line 511 "Parser.y"
    { 
        (yyval.string_type) = "int";   
    }
#line 2181 "Parser.tab.c"
    break;

  case 91: /* data_type: FLOAT  */
#line 515 "Parser.y"
    { 
        (yyval.string_type) = "float"; 
    }
#line 2189 "Parser.tab.c"
    break;

  case 92: /* data_type: STRING  */
#line 519 "Parser.y"
    { 
        (yyval.string_type) = "string"; 
    }
#line 2197 "Parser.tab.c"
    break;

  case 93: /* data_type: CHAR  */
#line 523 "Parser.y"
    { 
        (yyval.string_type) = "char";  
    }
#line 2205 "Parser.tab.c"
    break;

  case 94: /* data_type: BOOL  */
#line 527 "Parser.y"
    { 
        (yyval.string_type) = "bool";  
    }
#line 2213 "Parser.tab.c"
    break;

  case 95: /* data_type: VOID  */
#line 531 "Parser.y"
    { 
        (yyval.string_type) = "void";  
    }
#line 2221 "Parser.tab.c"
    break;

  case 96: /* expression: '(' expression ')'  */
#line 540 "Parser.y"
    { 
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2229 "Parser.tab.c"
    break;

  case 97: /* expression: function_call  */
#line 544 "Parser.y"
    { 
        (yyval.node) = (yyvsp[0].node);  
    }
#line 2237 "Parser.tab.c"
    break;

  case 98: /* expression: IDENTIFIER  */
#line 549 "Parser.y"
    { 
        int i = check_symbol((yyvsp[0].string_type), 0, yylineno);
        check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[0].string_type), "push");
    }
#line 2248 "Parser.tab.c"
    break;

  case 99: /* expression: IDENTIFIER PRE_POST_INC  */
#line 557 "Parser.y"
    { 
        int i = check_symbol((yyvsp[-1].string_type), 0, yylineno);
        // check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "post_inc");
    }
#line 2260 "Parser.tab.c"
    break;

  case 100: /* expression: IDENTIFIER PRE_POST_DEC  */
#line 566 "Parser.y"
    { 
        int i = check_symbol((yyvsp[-1].string_type), 0, yylineno);
        // check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "post_dec");
    }
#line 2272 "Parser.tab.c"
    break;

  case 101: /* expression: PRE_POST_INC IDENTIFIER  */
#line 574 "Parser.y"
    { 
        int i = check_symbol((yyvsp[0].string_type), 0, yylineno);
        // check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[0].string_type), "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "pre_inc");
    }
#line 2284 "Parser.tab.c"
    break;

  case 102: /* expression: PRE_POST_DEC IDENTIFIER  */
#line 583 "Parser.y"
    { 
        int i = check_symbol((yyvsp[0].string_type), 0, yylineno);
        // check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[0].string_type), "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "pre_dec");
    }
#line 2296 "Parser.tab.c"
    break;

  case 103: /* expression: CONSTANT  */
#line 591 "Parser.y"
    { 
        int i = check_symbol((yyvsp[0].string_type), 0, yylineno); 
        check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[0].string_type), "push");
    }
#line 2307 "Parser.tab.c"
    break;

  case 104: /* expression: INTEGER_VALUE  */
#line 598 "Parser.y"
    { 
        (yyval.node) = create_node("int");
        check_value_type("int", yylineno);
        check_integer(insertion_index, (yyvsp[0].int_type), yylineno);
    }
#line 2317 "Parser.tab.c"
    break;

  case 105: /* expression: FLOAT_VALUE  */
#line 604 "Parser.y"
    { 
        (yyval.node) = create_node("float");
        check_value_type("float", yylineno);
        check_float(insertion_index, (yyvsp[0].float_type), yylineno);
    }
#line 2327 "Parser.tab.c"
    break;

  case 106: /* expression: BOOL_VALUE  */
#line 610 "Parser.y"
    { 
        (yyval.node) = create_node("bool");
        check_value_type("bool", yylineno);
        check_bool(insertion_index, (yyvsp[0].bool_type), yylineno);
    }
#line 2337 "Parser.tab.c"
    break;

  case 107: /* expression: STRING_VALUE  */
#line 616 "Parser.y"
    { 
        (yyval.node) = create_node("string");
        check_value_type("string", yylineno);
        check_string(insertion_index, (yyvsp[0].string_type), yylineno);
    }
#line 2347 "Parser.tab.c"
    break;

  case 108: /* expression: CHAR_VALUE  */
#line 622 "Parser.y"
    { 
        (yyval.node) = create_node("char");
        check_value_type("char", yylineno);
        check_char(insertion_index, (yyvsp[0].string_type), yylineno);
    }
#line 2357 "Parser.tab.c"
    break;

  case 109: /* expression: SUB expression  */
#line 628 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[0].node), NULL, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "neg");
    }
#line 2366 "Parser.tab.c"
    break;

  case 110: /* expression: LOGICAL_NOT expression  */
#line 633 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[0].node), NULL, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_not");
    }
#line 2375 "Parser.tab.c"
    break;

  case 111: /* expression: BITWISE_NOT expression  */
#line 639 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise_not((yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "bitwise_not");
    }
#line 2384 "Parser.tab.c"
    break;

  case 112: /* expression: expression ADD expression  */
#line 645 "Parser.y"
    { 
        is_plus = 1;
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "add");
        is_plus=0;
    }
#line 2395 "Parser.tab.c"
    break;

  case 113: /* expression: expression SUB expression  */
#line 652 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n","sub");
    }
#line 2404 "Parser.tab.c"
    break;

  case 114: /* expression: expression MUL expression  */
#line 657 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "mul");
    }
#line 2413 "Parser.tab.c"
    break;

  case 115: /* expression: expression DIV expression  */
#line 662 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "div");
    }
#line 2422 "Parser.tab.c"
    break;

  case 116: /* expression: expression POW expression  */
#line 667 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n","pow");
    }
#line 2431 "Parser.tab.c"
    break;

  case 117: /* expression: expression MOD expression  */
#line 672 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "mod");
    }
#line 2440 "Parser.tab.c"
    break;

  case 118: /* expression: expression BITWISE_OR expression  */
#line 678 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "bitwise_or");
    }
#line 2449 "Parser.tab.c"
    break;

  case 119: /* expression: expression BITWISE_AND expression  */
#line 683 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "bitwise_and");
    }
#line 2458 "Parser.tab.c"
    break;

  case 120: /* expression: expression SHIFT_LEFT expression  */
#line 688 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "shift_left");
    }
#line 2467 "Parser.tab.c"
    break;

  case 121: /* expression: expression SHIFT_RIGHT expression  */
#line 693 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "shift_right");
    }
#line 2476 "Parser.tab.c"
    break;

  case 122: /* expression: expression LOGICAL_AND expression  */
#line 699 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_and");
    }
#line 2485 "Parser.tab.c"
    break;

  case 123: /* expression: expression LOGICAL_OR expression  */
#line 704 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_or");
    }
#line 2494 "Parser.tab.c"
    break;

  case 124: /* expression: expression EQUAL expression  */
#line 710 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "equal");
    }
#line 2503 "Parser.tab.c"
    break;

  case 125: /* expression: expression NOT_EQUAL expression  */
#line 715 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "not_equal");
    }
#line 2512 "Parser.tab.c"
    break;

  case 126: /* expression: expression GREATER_THAN expression  */
#line 721 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "greater_than");
    }
#line 2521 "Parser.tab.c"
    break;

  case 127: /* expression: expression GREATER_EQUAL expression  */
#line 726 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "greater_equal");
    }
#line 2530 "Parser.tab.c"
    break;

  case 128: /* expression: expression LESS_THAN expression  */
#line 731 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "less_than");
    }
#line 2539 "Parser.tab.c"
    break;

  case 129: /* expression: expression LESS_EQUAL expression  */
#line 736 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "less_equal");
    }
#line 2548 "Parser.tab.c"
    break;

  case 131: /* return_statement: RETURN expression  */
#line 746 "Parser.y"
    { 
        has_return = 1; 
    }
#line 2556 "Parser.tab.c"
    break;

  case 132: /* $@36: %empty  */
#line 754 "Parser.y"
    { 
        curr_function_arg_count = 0;
        called_function_index = check_symbol((yyvsp[0].string_type), 0, yylineno);
    }
#line 2565 "Parser.tab.c"
    break;

  case 133: /* $@37: %empty  */
#line 759 "Parser.y"
    {is_argument = 1;}
#line 2571 "Parser.tab.c"
    break;

  case 134: /* $@38: %empty  */
#line 761 "Parser.y"
    { 
        is_argument = 0;
        check_function_argument_count(called_function_index, yylineno); 
    }
#line 2580 "Parser.tab.c"
    break;

  case 135: /* function_call: IDENTIFIER $@36 '(' $@37 arguments_list $@38 ')'  */
#line 766 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tcall %s\n", (yyvsp[-6].string_type));
        (yyval.node) = create_node(symbol_table[called_function_index].ident_data_type); 
    }
#line 2589 "Parser.tab.c"
    break;

  case 136: /* $@39: %empty  */
#line 774 "Parser.y"
    { 
        curr_function_arg_count++; 
    }
#line 2597 "Parser.tab.c"
    break;

  case 138: /* arguments_list: expression  */
#line 779 "Parser.y"
    { 
        curr_function_arg_count++; 
    }
#line 2605 "Parser.tab.c"
    break;

  case 140: /* $@40: %empty  */
#line 787 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "%s:\n", (yyvsp[0].string_type));
    }
#line 2613 "Parser.tab.c"
    break;

  case 141: /* $@41: %empty  */
#line 791 "Parser.y"
    { 
        curr_function_index = add_symbol((yyvsp[-5].string_type), (yyvsp[-4].string_type), "function", yylineno, 0);
        symbol_table[curr_function_index].scope_level = block_counter ;
        pop_function_parameters(curr_function_index); 
    }
#line 2623 "Parser.tab.c"
    break;

  case 142: /* function_declaration: data_type IDENTIFIER $@40 '(' parameters_list ')' $@41 block  */
#line 797 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tend %s\n", (yyvsp[-6].string_type));
    }
#line 2631 "Parser.tab.c"
    break;

  case 143: /* $@42: %empty  */
#line 804 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "variable", yylineno, true); 
    }
#line 2639 "Parser.tab.c"
    break;

  case 145: /* parameters_list: data_type IDENTIFIER  */
#line 809 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "variable", yylineno, true); 
    }
#line 2647 "Parser.tab.c"
    break;


#line 2651 "Parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 814 "Parser.y"


void check_mem_alloc(Node *node)
{
    if (!node)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

Node *create_node(char *type)
{
    Node *node = (Node *)malloc(sizeof(Node));
    check_mem_alloc(node);
    node->type = type;
    return node;
}

Node *check_valid_types_arithmetic(Node *operand1, Node *operand2, int curr_line)
{
    Node *res = (Node *)malloc(sizeof(Node));
    check_mem_alloc(res);

    if (!operand2)
    {
        if (strcmp(operand1->type, "int") != 0 && strcmp(operand1->type, "float") != 0)
        {
            printf("Error at line %d: Invalid type for unary operator (int and float types are valid only)\n", curr_line);
            fprintf(error_output_file, "Error at line %d: Invalid type for unary operator (int and float types are valid only)\n", curr_line);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if(is_plus==1){

            if(strcmp(operand1->type, "void") == 0 || strcmp(operand2->type, "void") == 0) {
                printf("Error at line %d: Invalid types for arithmetic operator (int and float types are valid only)\n", curr_line);
                fprintf(error_output_file, "Error at line %d: Invalid types for arithmetic operator (int and float types are valid only)\n", curr_line);
                exit(EXIT_FAILURE);
            }

        }
        else {
        if (strcmp(operand1->type, "string") == 0 ||
            strcmp(operand2->type, "string") == 0 ||
            strcmp(operand1->type, "char") == 0 ||
            strcmp(operand2->type, "char") == 0 ||
            strcmp(operand1->type, "void") == 0 ||
            strcmp(operand2->type, "void") == 0)
        {
            printf("Error at line %d: Invalid types for arithmetic operator (int and float types are valid only)\n", curr_line);
            fprintf(error_output_file, "Error at line %d: Invalid types for arithmetic operator (int and float types are valid only)\n", curr_line);
            exit(EXIT_FAILURE);
        }
        }
    }
    
    res->type = operand1->type;
    return res;
}

Node *check_valid_types_bool(Node *operand1, Node *operand2, int curr_line)
{
    Node *res = (Node *)malloc(sizeof(Node));
    check_mem_alloc(res);

    if (!operand2)
    {
        // Handle unary negation operator (!)
        if (strcmp(operand1->type, "string") == 0 || strcmp(operand1->type, "char") == 0 || strcmp(operand1->type, "void") == 0)
        {
            printf("Error at line %d: Invalid type for negation operator (!)\n", curr_line);
            fprintf(error_output_file, "Error at line %d: Invalid type for negation operator (!)\n", curr_line);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Handle binary operators (&&, ||, <, <=, >, >=, ==, !=)
        if (strcmp(operand1->type, "string") == 0 ||
            strcmp(operand2->type, "string") == 0 ||
            strcmp(operand1->type, "char") == 0 ||
            strcmp(operand2->type, "char") == 0 ||
            strcmp(operand1->type, "void") == 0 ||
            strcmp(operand2->type, "void") == 0)
        {
            printf("Error at line %d: Invalid types for boolean operator\n", curr_line);
            fprintf(error_output_file, "Error at line %d: Invalid types for boolean operator\n", curr_line);
            exit(EXIT_FAILURE);
        }
    }

    res->type = "bool";
    return res;
}

Node *check_valid_types_bitwise(Node *operand1, Node *operand2, int curr_line)
{
    Node *res = (Node *)malloc(sizeof(Node));
    check_mem_alloc(res);

    if (strcmp(operand1->type, "int") != 0 || strcmp(operand2->type, "int") != 0)
    {
        printf("Error at line %d: Invalid types for bitwise operator expecting integer\n", curr_line);
        fprintf(error_output_file, "Error at line %d: Invalid types for bitwise operator expecting integer\n", curr_line);
        exit(EXIT_FAILURE);
    }

    res->type = "int";
    return res;
}

Node *check_valid_types_bitwise_not(Node *operand1, int curr_line)
{
    Node *res = (Node *)malloc(sizeof(Node));
    check_mem_alloc(res);

    if (strcmp(operand1->type, "int") != 0)
    {
        printf("Error at line %d: Invalid types for bitwise operator expecting integer\n", curr_line);
        fprintf(error_output_file, "Error at line %d: Invalid types for bitwise operator expecting integer\n", curr_line);
        exit(EXIT_FAILURE);
    }

    res->type = "int";
    return res;
}

void end_scope(int line_number)
{
    // Function Return Validations
    if (curr_function_index != -1 && strcmp(symbol_table[curr_function_index].type, "function") == 0 &&
        symbol_table[curr_function_index].scope_level == block_counter-1)
    {
        // Non-void function missing return
        if (!has_return && strcmp(symbol_table[curr_function_index].ident_data_type, "void") != 0)
        {
            printf("Error at line %d: Missing 'return' in Function\n", line_number);
            fprintf(error_output_file, "Error at line %d: Missing 'return' in Function %s\n", line_number, symbol_table[curr_function_index].identifier);
            exit(EXIT_FAILURE);
        }

        // Void function has a return with value
        if (has_return && strcmp(symbol_table[curr_function_index].ident_data_type, "void") == 0)
        {
            printf("Error at line %d: It's a void Function; can't have 'return' with value\n", line_number);
            fprintf(error_output_file, "Error at line %d: It's a void Function; can't have 'return' with value\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    insertion_index = -1;
    curr_function_index = -1;
    has_return = 0;

    // Mark Variables in This Scope as Ended 
    for (int i = 0; i < symbol_table_index; i++)
    {
        if (symbol_table[i].scope_level == block_counter)
        {
            symbol_table[i].scope_ended = true;
        }
    }

    // Exit the Current Scope 
    block_counter--;
}

int get_symbol_declaration_line(char *identifier)
{
    // Search for Identifier in Current Scope 
    for (int i = 0; i < symbol_table_index; ++i)
    {
        if (strcmp(symbol_table[i].identifier, identifier) == 0 &&
            symbol_table[i].scope_level == block_counter &&
            !symbol_table[i].scope_ended)
        {
            return symbol_table[i].declaration_line;
        }
    }
    return -1;
}

int add_symbol(char *ident_data_type, char *identifier, char *type, int line_number, bool is_function_param)
{
    // Check for Redeclaration in Current Scope 
    int delaration_line = get_symbol_declaration_line(identifier);
    if (delaration_line != -1 && !is_function_param)
    {
        printf("Error at line %d: %s is already declared in this scope_level at line %d\n", line_number, identifier, delaration_line);
        fprintf(error_output_file, "Error at line %d: %s is already declared in this scope_level at line %d\n", line_number, identifier, delaration_line);
        exit(EXIT_FAILURE);
    }

    struct symbol new_item = {0}; // zero all fields
    new_item.identifier = identifier;
    new_item.ident_data_type = ident_data_type;
    new_item.type = type;
    new_item.declaration_line = line_number;
    new_item.id = symbol_table_index;

    new_item.is_function_parameter = is_function_param;
    new_item.is_assigned_to_func = false;
    new_item.scope_ended = false;
    new_item.is_initialized = false;
    new_item.is_used = false;

    if (is_function_param || is_loop)
    {
        new_item.scope_level = block_counter + 1;
    }
    else
    {
        new_item.scope_level = block_counter;
    }

    if (strcmp(type, "function") == 0)
    {
        int j = 0;
        for (int i = 0; i < symbol_table_index; i++)
        {
            if (symbol_table[i].is_function_parameter &&
                symbol_table[i].scope_level == (block_counter + 1) &&
                !symbol_table[i].is_assigned_to_func)
            {
                new_item.function_arguments[j] = symbol_table[i].id;
                symbol_table[i].is_assigned_to_func = true;
                j++;
            }
        }
        new_item.curr_function_arg_count = j;
    }

    symbol_table[symbol_table_index++] = new_item;

    return new_item.id;
}


int check_symbol(char *identifier, bool is_assigned, int line_number)
{
    for (int i = 0; i < symbol_table_index; ++i)
    {
        if (strcmp(symbol_table[i].identifier, identifier) == 0 && !symbol_table[i].scope_ended)
        {
            if (!symbol_table[i].is_initialized &&
                strcmp(symbol_table[i].type, "variable") == 0 &&
                !symbol_table[i].is_function_parameter &&
                !is_assigned)
            {
                printf("Error at line %d: %s used before initialization\n", line_number, identifier);
                fprintf(error_output_file, "Error at line %d: %s used before initialization\n", line_number, identifier);
                exit(EXIT_FAILURE);
            }

            if (!is_assigned)
            {
                symbol_table[i].is_used = true;
            }

            return symbol_table[i].id;
        }
    }

    printf("Error at line %d: %s undeclared identifier\n", line_number, identifier);
    fprintf(error_output_file, "Error at line %d: %s undeclared identifier\n", line_number, identifier);
    exit(EXIT_FAILURE);
}

static void push_correct_value_based_on_type(const char *type, int int_val, float float_val)
{
    if (strcmp(type, "float") == 0)
        fprintf(quadrupleFilePointer, "\tpush %f\n", (float)float_val);
    else if (strcmp(type, "bool") == 0)
        fprintf(quadrupleFilePointer, "\tpush %d\n", (bool)int_val);
    else if (strcmp(type, "int") == 0)
        fprintf(quadrupleFilePointer, "\tpush %d\n", int_val);
}

static void validate_assignment_type(int index, const char *expected_type, const char *value_type, int line_number)
{
    if ((strcmp(expected_type, "string") == 0 || strcmp(expected_type, "void") == 0))
    {
        printf("Error at line %d: %s '%s' variable assigned '%s' value\n",
               line_number, symbol_table[index].identifier, expected_type, value_type);
        fprintf(error_output_file, "Error at line %d: %s '%s' variable assigned '%s' value\n",
                line_number, symbol_table[index].identifier, expected_type, value_type);
        exit(EXIT_FAILURE);
    }
}

void check_integer(int index, int value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %d\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    symbol_table[index].is_initialized = true;

    if ((!symbol_table[index].scope_ended && strcmp(type, "void") != 0 && strcmp(type, "char") != 0 && strcmp(type, "string") != 0) || is_argument)
    {
        push_correct_value_based_on_type(type, value, (float)value);
    }
    else
    {
        validate_assignment_type(index, type, "int", line_number);
    }

    if (is_argument == 1)
        insertion_index = -1;
}

void check_float(int index, float value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %f\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    symbol_table[index].is_initialized = true;

    if ((!symbol_table[index].scope_ended && strcmp(type, "void") != 0 && strcmp(type, "char") != 0 && strcmp(type, "string") != 0) || is_argument)
    {
        push_correct_value_based_on_type(type, (int)value, value);
    }
    else
    {
        validate_assignment_type(index, type, "float", line_number);
    }

    if (is_argument == 1)
        insertion_index = -1;
}


void report_type_error(int line_number, const char *identifier, const char *actual_type, const char *assigned_type)
{
    printf("Error at line %d: %s type is '%s' but assigned '%s'\n", line_number, identifier, actual_type, assigned_type);
    fprintf(error_output_file, "Error at line %d: %s type is '%s' but assigned '%s'\n", line_number, identifier, actual_type, assigned_type);
    exit(EXIT_FAILURE);
}

void check_bool(int index, bool value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %d\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    if (((strcmp(type, "string") != 0 && strcmp(type, "char") != 0 && strcmp(type, "void") != 0) && !symbol_table[index].scope_ended) || is_argument)
    {
        push_correct_value_based_on_type(type, (int)value, (float)value);
    }
    else
    {
        report_type_error(line_number, symbol_table[index].identifier, type, "bool");
    }
    symbol_table[index].is_initialized = true;
    if (is_argument == 1)
        insertion_index = -1;
}

void check_string(int index, char *value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    if ((strcmp(type, "string") == 0) && (!symbol_table[index].scope_ended) || is_argument)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
    }
    else
    {
        report_type_error(line_number, symbol_table[index].identifier, type, "string");
    }

    symbol_table[index].is_initialized = true;
    if (is_argument == 1)
        insertion_index = -1;
}

void check_char(int index, char *value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    if ((strcmp(type, "char") == 0) && (!symbol_table[index].scope_ended) || is_argument)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
    }
    else
    {
        report_type_error(line_number, symbol_table[index].identifier, type, "char");
    }

    symbol_table[index].is_initialized = true;
    if (is_argument == 1)
        insertion_index = -1;
}

void report_type_mismatch_error(int line_number, const char *identifier1, const char *type1, const char *identifier2, const char *type2)
{
    printf("Error at line %d: %s is %s variable but found %s\n", line_number, identifier1, type1, type2);
    fprintf(error_output_file, "Error at line %d: %s is %s variable but found %s %s\n", line_number, identifier1, type1,identifier2, type2);
    exit(EXIT_FAILURE);
}

bool are_types_compatible(const char *type1, const char *type2,int from_func)
{
    if(from_func==1){
        if ((strcmp(type1, "string") == 0 && strcmp(type2, "char") == 0) ||
            (strcmp(type1, "int") == 0 && strcmp(type2, "float") == 0) ||
            (strcmp(type1, "char") == 0 && strcmp(type2, "int") == 0) ||
            (strcmp(type1, "int") == 0 && strcmp(type2, "char") == 0) ||
            (strcmp(type1, "float") == 0 && strcmp(type2, "int") == 0)||
            (strcmp(type1, "bool") == 0 && strcmp(type2, "int") == 0)||
            (strcmp(type1, "int") == 0 && strcmp(type2, "bool") == 0)||
            (strcmp(type1, "float") == 0 && strcmp(type2, "bool") == 0) ||
            (strcmp(type1, "bool") == 0 && strcmp(type2, "float") == 0))
        {
            return true;
        }
    }
    else {
        if ((strcmp(type1, "string") == 0 && strcmp(type2, "char") == 0) ||
            (strcmp(type1, "char") == 0 && strcmp(type2, "string") == 0) ||
            (strcmp(type1, "char") == 0 && strcmp(type2, "int") == 0) ||
            (strcmp(type1, "int") == 0 && strcmp(type2, "char") == 0) ||
            (strcmp(type1, "int") == 0 && strcmp(type2, "float") == 0) ||
            (strcmp(type1, "float") == 0 && strcmp(type2, "int") == 0)||
            (strcmp(type1, "bool") == 0 && strcmp(type2, "int") == 0)||
            (strcmp(type1, "int") == 0 && strcmp(type2, "bool") == 0)||
            (strcmp(type1, "float") == 0 && strcmp(type2, "bool") == 0) ||
            (strcmp(type1, "bool") == 0 && strcmp(type2, "float") == 0))
        {
            return true;
        }
    }
    return strcmp(type1, type2) == 0;
}


void check_argument_type_compatibility(int line_number, int insertion_index, const char *expected_type, const char *actual_type)
{
    if (are_types_compatible(expected_type, actual_type,1)== false)
    {
        report_type_mismatch_error(line_number, symbol_table[insertion_index].identifier, expected_type, symbol_table[called_function_index].identifier, actual_type);
    }
}

/**
 * Checks if the type of the variable being assigned matches the expected type. 
 * 
 * If the types do not match, it reports a type mismatch error and exits the program.
 * If the types match and the source symbol is not a function, it marks the symbol as initialized.
 */
void check_variable_type(int symbol_index, int line_number)
{

    if (symbol_index == -1 || insertion_index == -1) return;

    const char *expected_type = symbol_table[symbol_index].ident_data_type;
    const char *actual_type = symbol_table[insertion_index].ident_data_type;

    if (are_types_compatible(expected_type,actual_type,0) == false)
    {
        report_type_mismatch_error(line_number, symbol_table[insertion_index].identifier, actual_type, symbol_table[symbol_index].identifier, expected_type);
    }
    else if (strcmp(symbol_table[insertion_index].type, "function") != 0)
    {
        symbol_table[insertion_index].is_initialized = true;
    }
}

void check_value_type(char *ident_data_type, int line_number)
{
    if (is_argument == 1)
    {
        insertion_index = (curr_function_arg_count < symbol_table[called_function_index].curr_function_arg_count)
                              ? symbol_table[called_function_index].function_arguments[curr_function_arg_count]
                              : -1;
    }

    if (insertion_index == -1) return;

    const char *expected_type = symbol_table[insertion_index].ident_data_type;
    if (are_types_compatible(expected_type, ident_data_type,1)==false)
    {
        report_type_mismatch_error(line_number, symbol_table[insertion_index].identifier, expected_type, symbol_table[called_function_index].identifier, ident_data_type);
    }
}

void check_function_argument_count(int i, int line_number)
{
    int expected_arg_count = symbol_table[i].curr_function_arg_count;

    if (curr_function_arg_count > expected_arg_count)
    {
        printf("Error at line %d: too many arguments for function call. Expected %d, found %d\n", line_number, expected_arg_count, curr_function_arg_count);
        fprintf(error_output_file, "Error at line %d: too many arguments for function call. Expected %d, found %d\n", line_number, expected_arg_count, curr_function_arg_count);
        exit(EXIT_FAILURE);
    }
    else if (curr_function_arg_count < expected_arg_count)
    {
        printf("Error at line %d: too few arguments for function call. Expected %d, found %d\n", line_number, expected_arg_count, curr_function_arg_count);
        fprintf(error_output_file, "Error at line %d: too few arguments for function call. Expected %d, found %d\n", line_number, expected_arg_count, curr_function_arg_count);
        exit(EXIT_FAILURE);
    }
}

void pop_function_parameters(int index)
{
    for (int i = symbol_table[index].curr_function_arg_count - 1; i >= 0; --i)
    {
        int argIndex = symbol_table[index].function_arguments[i];
        write_identifier_quadruple(symbol_table[argIndex].identifier, "pop");
    }
}


void write_symbol_table_to_file(const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening symbol table file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "===============================================================================================================================\n");
    fprintf(fp, " ID | Identifier     | Type     | Data Type | Line | Scope | Func_Param | Used | Init | AssignToFunc | ScopeEnded | Func Args\n");
    fprintf(fp, "===============================================================================================================================\n");

    for (int i = 0; i < symbol_table_index; i++)
    {
        struct symbol node = symbol_table[i];
        
        fprintf(fp, "%3d | %-14s | %-8s | %-9s | %4d | %5d |    %d    |  %d  |  %d  |      %d      |     %d     | ", 
                node.id, 
                node.identifier ? node.identifier : "(null)", 
                node.type ? node.type : "(null)", 
                node.ident_data_type ? node.ident_data_type : "(null)",
                node.declaration_line, 
                node.scope_level, 
                node.is_function_parameter, 
                node.is_used, 
                node.is_initialized,
                node.is_assigned_to_func,
                node.scope_ended);

        if (node.curr_function_arg_count > 0)
        {
            for (int j = 0; j < node.curr_function_arg_count; j++)
            {
                fprintf(fp, "%d", node.function_arguments[j]);
                if (j != node.curr_function_arg_count - 1)
                    fprintf(fp, ",");
            }
        }
        else
        {
            fprintf(fp, "None");
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "===============================================================================================================================\n");

    fclose(fp);
}


void write_unused_symbols_to_file(const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening unused symbols file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < symbol_table_index; ++i)
    {
        if (!symbol_table[i].is_used) // Skip used symbols
        {
            if (strcmp(symbol_table[i].type, "function") == 0)
            {
                fprintf(fp, "warning: function %s declared at line %d but never used\n", 
                        symbol_table[i].identifier, symbol_table[i].declaration_line);
            }
            else if (symbol_table[i].is_function_parameter == 1)
            {
                fprintf(fp, "warning: argument %s declared in function at line %d but never used\n", 
                        symbol_table[i].identifier, symbol_table[i].declaration_line);
            }
            else
            {
                fprintf(fp, "warning: identifier %s declared at line %d but never used\n", 
                        symbol_table[i].identifier, symbol_table[i].declaration_line);
            }
        }
    }

    fclose(fp);
}
void yyerror(char *s) { 
    printf("line %d: %s\n", yylineno, s); 
    fprintf(error_output_file, "line %d: %s\n", yylineno, s); 
} 
int yywrap()
{
    return 1;
}

int main(int argc, char *argv[])
{ 
    quadrupleFilePath = QUAD_FILE;
    quadrupleFilePointer = create_output_file(QUAD_FILE);
    error_output_file = fopen(ERROR_FILE, "w");
    if (error_output_file == NULL) {
        printf("failed opening error file\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin==NULL){
        printf("failed opening code file\n");
        return 1;
    }
    yyparse();
    write_unused_symbols_to_file(UNUSED_SYMBOLS_FILE);
    write_symbol_table_to_file(SYMBOL_TABLE_FILE);
    
    return 0;
}

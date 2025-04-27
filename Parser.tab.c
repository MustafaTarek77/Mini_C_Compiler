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

    symbol symbol_table[MAX_SYMBOLS];

    int block_counter = 0;
    int symbol_table_index = 0;

    int curr_function_index = 0;
    int curr_function_arg_count = 0;
    int called_function_index = 0;
    int is_argument = 0;
    int is_loop = 0;
    int has_return = 0;

    int insertion_index = -1;

    FILE *error_output_file = NULL;

    // Checks if memory allocation was successful
    void check_mem_alloc(Node *node);

    // Creates a new AST node with the given type
    Node *create_node(char *type);

    // Validates types for arithmetic operations (unary or binary)
    Node *check_valid_types_arithmetic(Node *operand1, Node *operand2, int curr_line);

    // Validates types for boolean operations (unary or binary)
    Node *check_valid_types_bool(Node *operand1, Node *operand2, int curr_line);

    // Validates types for bitwise operations (binary only)
    Node *check_valid_types_bitwise(Node *operand1, Node *operand2, int curr_line);


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
    // Checks if the number of arguments in a function call matches the declaration
    void check_function_argument_count(int i, int line_number);

    // Pops function arguments from the stack and generates corresponding quadruples
    void pop_function_parameters(int index);

    // Displays the symbol table to a given file
    void write_symbol_table_to_file(const char *filename);

    // Logs all unused variables (functions, arguments, identifiers) to a file
    void write_unused_symbols_to_file(const char *filename);

    // Removes all output files
    int delete_output_files();





#line 148 "Parser.tab.c"

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
  YYSYMBOL_BITWISE = 29,                   /* BITWISE  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_SEMICOLON = 31,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_MOD = 33,                       /* MOD  */
  YYSYMBOL_ADD = 34,                       /* ADD  */
  YYSYMBOL_SUB = 35,                       /* SUB  */
  YYSYMBOL_MUL = 36,                       /* MUL  */
  YYSYMBOL_DIV = 37,                       /* DIV  */
  YYSYMBOL_POW = 38,                       /* POW  */
  YYSYMBOL_SHIFT_LEFT = 39,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 40,               /* SHIFT_RIGHT  */
  YYSYMBOL_GREATER_THAN = 41,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 42,                 /* LESS_THAN  */
  YYSYMBOL_ASSIGN = 43,                    /* ASSIGN  */
  YYSYMBOL_GREATER_EQUAL = 44,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 45,                /* LESS_EQUAL  */
  YYSYMBOL_POST_INC = 46,                  /* POST_INC  */
  YYSYMBOL_POST_DEC = 47,                  /* POST_DEC  */
  YYSYMBOL_CONSTANT = 48,                  /* CONSTANT  */
  YYSYMBOL_IDENTIFIER = 49,                /* IDENTIFIER  */
  YYSYMBOL_STRING_VALUE = 50,              /* STRING_VALUE  */
  YYSYMBOL_CHAR_VALUE = 51,                /* CHAR_VALUE  */
  YYSYMBOL_INTEGER_VALUE = 52,             /* INTEGER_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 53,               /* FLOAT_VALUE  */
  YYSYMBOL_BITWISE_NOT = 54,               /* BITWISE_NOT  */
  YYSYMBOL_PRE_POST_INC = 55,              /* PRE_POST_INC  */
  YYSYMBOL_PRE_POST_DEC = 56,              /* PRE_POST_DEC  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_block = 64,                     /* block  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_conditional_statement = 67,     /* conditional_statement  */
  YYSYMBOL_if_wrapper = 68,                /* if_wrapper  */
  YYSYMBOL_69_2 = 69,                      /* $@2  */
  YYSYMBOL_if_statement = 70,              /* if_statement  */
  YYSYMBOL_71_3 = 71,                      /* $@3  */
  YYSYMBOL_72_4 = 72,                      /* $@4  */
  YYSYMBOL_else_statement = 73,            /* else_statement  */
  YYSYMBOL_while_wrapper = 74,             /* while_wrapper  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_while_statement = 76,           /* while_statement  */
  YYSYMBOL_77_6 = 77,                      /* $@6  */
  YYSYMBOL_do_while_wrapper = 78,          /* do_while_wrapper  */
  YYSYMBOL_79_7 = 79,                      /* $@7  */
  YYSYMBOL_do_while_statement = 80,        /* do_while_statement  */
  YYSYMBOL_switch_wrapper = 81,            /* switch_wrapper  */
  YYSYMBOL_82_8 = 82,                      /* $@8  */
  YYSYMBOL_switch_statement = 83,          /* switch_statement  */
  YYSYMBOL_84_9 = 84,                      /* $@9  */
  YYSYMBOL_default_statement = 85,         /* default_statement  */
  YYSYMBOL_case_statement = 86,            /* case_statement  */
  YYSYMBOL_87_10 = 87,                     /* $@10  */
  YYSYMBOL_88_11 = 88,                     /* $@11  */
  YYSYMBOL_for_wrapper = 89,               /* for_wrapper  */
  YYSYMBOL_90_12 = 90,                     /* $@12  */
  YYSYMBOL_91_13 = 91,                     /* $@13  */
  YYSYMBOL_92_14 = 92,                     /* $@14  */
  YYSYMBOL_93_15 = 93,                     /* $@15  */
  YYSYMBOL_declaration_statement = 94,     /* declaration_statement  */
  YYSYMBOL_95_16 = 95,                     /* $@16  */
  YYSYMBOL_96_17 = 96,                     /* $@17  */
  YYSYMBOL_97_18 = 97,                     /* $@18  */
  YYSYMBOL_assignment_statement = 98,      /* assignment_statement  */
  YYSYMBOL_99_19 = 99,                     /* $@19  */
  YYSYMBOL_print_statement = 100,          /* print_statement  */
  YYSYMBOL_101_20 = 101,                   /* $@20  */
  YYSYMBOL_data_type = 102,                /* data_type  */
  YYSYMBOL_expression = 103,               /* expression  */
  YYSYMBOL_return_statement = 104,         /* return_statement  */
  YYSYMBOL_function_call = 105,            /* function_call  */
  YYSYMBOL_106_21 = 106,                   /* $@21  */
  YYSYMBOL_107_22 = 107,                   /* $@22  */
  YYSYMBOL_108_23 = 108,                   /* $@23  */
  YYSYMBOL_arguments_list = 109,           /* arguments_list  */
  YYSYMBOL_110_24 = 110,                   /* $@24  */
  YYSYMBOL_function_declaration = 111,     /* function_declaration  */
  YYSYMBOL_112_25 = 112,                   /* $@25  */
  YYSYMBOL_113_26 = 113,                   /* $@26  */
  YYSYMBOL_parameters_list = 114,          /* parameters_list  */
  YYSYMBOL_115_27 = 115                    /* $@27  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   566

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      59,    60,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   112,   112,   113,   116,   116,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   132,   133,   134,   135,
     136,   140,   140,   147,   149,   146,   154,   155,   156,   160,
     160,   167,   166,   173,   173,   179,   184,   184,   191,   190,
     202,   207,   213,   206,   217,   218,   223,   225,   227,   230,
     222,   238,   237,   247,   246,   255,   254,   267,   266,   282,
     281,   292,   296,   300,   304,   308,   312,   321,   325,   330,
     338,   348,   357,   366,   374,   381,   387,   393,   399,   405,
     411,   416,   422,   427,   432,   437,   442,   447,   453,   458,
     463,   468,   474,   479,   485,   490,   496,   501,   506,   511,
     519,   520,   530,   535,   537,   529,   550,   549,   554,   558,
     563,   567,   562,   579,   578,   583,   587
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
  "NOT_EQUAL", "BITWISE_OR", "BITWISE_AND", "BITWISE", "NOT", "SEMICOLON",
  "COMMA", "MOD", "ADD", "SUB", "MUL", "DIV", "POW", "SHIFT_LEFT",
  "SHIFT_RIGHT", "GREATER_THAN", "LESS_THAN", "ASSIGN", "GREATER_EQUAL",
  "LESS_EQUAL", "POST_INC", "POST_DEC", "CONSTANT", "IDENTIFIER",
  "STRING_VALUE", "CHAR_VALUE", "INTEGER_VALUE", "FLOAT_VALUE",
  "BITWISE_NOT", "PRE_POST_INC", "PRE_POST_DEC", "'{'", "'}'", "'('",
  "')'", "':'", "$accept", "program", "block", "$@1", "statement",
  "conditional_statement", "if_wrapper", "$@2", "if_statement", "$@3",
  "$@4", "else_statement", "while_wrapper", "$@5", "while_statement",
  "$@6", "do_while_wrapper", "$@7", "do_while_statement", "switch_wrapper",
  "$@8", "switch_statement", "$@9", "default_statement", "case_statement",
  "$@10", "$@11", "for_wrapper", "$@12", "$@13", "$@14", "$@15",
  "declaration_statement", "$@16", "$@17", "$@18", "assignment_statement",
  "$@19", "print_statement", "$@20", "data_type", "expression",
  "return_statement", "function_call", "$@21", "$@22", "$@23",
  "arguments_list", "$@24", "function_declaration", "$@25", "$@26",
  "parameters_list", "$@27", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-116)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -94,   167,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     369,   -27,   -24,   -49,   -94,   369,   369,    45,     3,   -94,
     -94,   -94,   -94,   -34,   -32,   -94,   369,   -94,   -94,   -94,
     -94,     4,   -94,     7,   -94,     8,   -94,    15,   -94,   -94,
     -94,   -94,    -7,   404,    12,   -94,   -94,   -14,   -94,   -47,
     500,   -94,   -94,   -94,    22,    22,    14,   -94,   -94,   -94,
      -6,   -94,   -94,   -94,    -4,   369,   -94,   369,   -94,    26,
     -94,     2,   -94,   -20,   369,   369,   369,   369,   369,   369,
     -94,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   -94,   369,   281,   -94,   369,   -94,   224,
     -94,   500,   500,    66,    37,    47,    62,    39,   521,   521,
     123,   123,   521,   521,    22,    22,    22,    22,    22,    22,
      22,    22,   123,   123,   123,   123,    69,   -94,    56,   428,
     369,   -94,    26,    26,    41,   -94,   369,   -94,    45,    70,
     281,   369,   -94,   319,   -94,   -94,   -94,   369,    52,   452,
      67,    55,   -94,   -94,   476,    85,    58,   102,   347,    64,
     -94,    65,   -94,   281,   -94,   369,   -94,   -13,   -94,    93,
      -1,    95,    26,    72,   -94,   -94,   -94,   -94,   369,    73,
     -94,    75,    45,   -94,   -94,   500,    26,   -94,   -94,    26,
      74,   -94,   -94,    26,   -94,    -1,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    21,     1,    61,    62,    64,    65,    63,    59,    66,
     100,     0,     0,     0,    77,     0,     0,    74,    69,    78,
      79,    75,    76,     0,     0,     4,     0,     6,     2,    11,
      16,     0,    17,     0,    18,     0,    19,     0,    20,     7,
       8,    10,     0,     0,     0,    68,    12,     0,    74,    69,
     101,    14,    13,    46,    81,    80,     0,    57,    70,    71,
       0,    72,    73,     3,     0,     0,    22,     0,    30,     0,
      34,     0,    37,    51,     0,     0,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,    21,    55,     0,   103,    21,
      67,    23,    31,     0,     0,     0,     0,     0,    92,    93,
      94,    95,    88,    89,    87,    82,    83,    84,    85,    86,
      90,    91,    96,    98,    97,    99,     0,    47,     0,     0,
     109,     5,     0,     0,     0,    38,     0,    54,   116,     0,
      21,     0,    58,   106,   104,    24,    32,     0,     0,     0,
       0,     0,    60,    48,     0,     0,     0,    28,     0,     0,
      52,   113,   111,    21,    56,   109,   105,     0,    25,     0,
      45,     0,     0,     0,   107,    26,    27,    35,     0,     0,
      44,     0,   116,   112,    49,    41,     0,    39,   114,     0,
       0,    40,    50,     0,    42,    45,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,    76,   -44,   -94,   -93,   -94,   -94,   -94,   -37,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -59,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -16,   -10,   -94,   -94,   -94,   -94,   -94,   -25,   -94,   -94,
     -94,   -94,   -41,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    27,    63,    28,    29,    30,    31,    66,   132,
     157,   168,    32,    33,    68,   133,    34,    35,    70,    36,
      37,    72,   148,   180,   181,   190,   195,    38,    95,   140,
     163,   189,    39,   105,   106,   128,    40,    97,    41,    47,
      42,    43,    44,    45,    60,   130,   156,   144,   155,    46,
     107,   172,   151,   171
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    56,   127,    65,    51,    54,    55,    52,    58,    59,
      53,   -53,  -102,   178,   179,    61,    64,    62,    74,    75,
      65,    76,    77,    78,    79,   103,    67,    71,    69,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,  -110,
      91,    92,    73,    93,    25,    94,    57,   153,     3,     4,
       5,     6,     7,    98,     9,   101,   100,   102,    58,    59,
      86,   104,  -102,    96,   108,   109,   110,   111,   112,   113,
     173,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    25,   126,   134,   135,   129,   145,   146,
     136,    74,    75,   137,    76,    77,    78,    79,   138,   141,
     147,   152,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,   159,    91,    92,   162,   161,   165,   166,   167,
     143,   170,   150,   175,   177,  -115,   149,   182,   183,   139,
     176,   154,   184,   187,   186,   193,   196,   158,     0,    99,
     174,   188,   191,     0,     0,   192,     0,     0,     0,   194,
       0,     0,     0,     0,     0,   143,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,   150,     2,   185,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   -36,
      12,     0,     0,     0,     0,    13,   -29,   -33,    14,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,     0,    26,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   -36,    12,     0,     0,
       0,     0,    13,   -29,   -33,    14,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,   131,    26,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   -36,    12,     0,     0,     0,     0,    13,
     -29,   -33,    14,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,     0,
      26,    74,    75,     0,    76,    77,    78,    79,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,    92,     0,     0,     0,     0,    74,
      75,     0,    76,    77,    78,    79,     0,     0,     0,  -108,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      14,    91,    92,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,   169,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    19,
      20,    21,    22,     0,    23,    24,    74,    75,    26,    76,
      77,    78,    79,     0,     0,    80,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,    92,
      74,    75,     0,    76,    77,    78,    79,     0,     0,   142,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    74,    75,     0,    76,    77,    78,
      79,     0,     0,   160,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    74,    75,
       0,    76,    77,    78,    79,     0,     0,   164,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    74,    75,     0,    76,    77,    78,    79,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    76,    77,     0,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92
};

static const yytype_int16 yycheck[] =
{
      10,    17,    95,    16,    31,    15,    16,    31,    55,    56,
      59,    31,    59,    14,    15,    49,    26,    49,    22,    23,
      16,    25,    26,    27,    28,    69,    19,    12,    20,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    59,
      44,    45,    49,    31,    57,    59,    43,   140,     3,     4,
       5,     6,     7,    59,     9,    65,    60,    67,    55,    56,
      38,    59,    59,    49,    74,    75,    76,    77,    78,    79,
     163,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    57,    94,    19,    49,    97,   132,   133,
      43,    22,    23,    31,    25,    26,    27,    28,    59,    43,
      59,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    60,    44,    45,    60,    49,    32,    60,    17,
     130,    57,   138,   167,    31,    60,   136,    32,   172,    60,
     167,   141,    60,    58,    61,    61,   195,   147,    -1,    63,
     165,   182,   186,    -1,    -1,   189,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,   165,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,   182,     0,   178,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    -1,    59,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    -1,
      59,    22,    23,    -1,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,    22,
      23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    60,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      21,    44,    45,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    22,    23,    59,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      22,    23,    -1,    25,    26,    27,    28,    -1,    -1,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    22,    23,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    22,    23,
      -1,    25,    26,    27,    28,    -1,    -1,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    22,    23,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    13,    18,    21,    24,    35,    48,    49,    50,
      51,    52,    53,    55,    56,    57,    59,    64,    66,    67,
      68,    69,    74,    75,    78,    79,    81,    82,    89,    94,
      98,   100,   102,   103,   104,   105,   111,   101,    48,    49,
     103,    31,    31,    59,   103,   103,   102,    43,    55,    56,
     106,    49,    49,    65,   103,    16,    70,    19,    76,    20,
      80,    12,    83,    49,    22,    23,    25,    26,    27,    28,
      31,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    44,    45,    31,    59,    90,    49,    99,    59,    63,
      60,   103,   103,    64,    59,    95,    96,   112,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,    66,    97,   103,
     107,    58,    71,    77,    19,    49,    43,    31,    59,    60,
      91,    43,    31,   103,   109,    64,    64,    59,    84,   103,
     102,   114,    31,    66,   103,   110,   108,    72,   103,    60,
      31,    49,    60,    92,    31,    32,    60,    17,    73,    60,
      57,   115,   113,    66,   109,    64,    70,    31,    14,    15,
      85,    86,    32,    64,    60,   103,    61,    58,   114,    93,
      87,    64,    64,    61,    64,    88,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    65,    64,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    69,    68,    71,    72,    70,    73,    73,    73,    75,
      74,    77,    76,    79,    78,    80,    82,    81,    84,    83,
      85,    87,    88,    86,    86,    86,    90,    91,    92,    93,
      89,    95,    94,    96,    94,    97,    94,    99,    98,   101,
     100,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   106,   107,   108,   105,   110,   109,   109,   109,
     112,   113,   111,   115,   114,   114,   114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     4,     1,     1,     1,     2,
       1,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     0,     2,     0,     0,     6,     2,     2,     0,     0,
       2,     0,     4,     0,     2,     7,     0,     2,     0,     8,
       3,     0,     0,     7,     1,     0,     0,     0,     0,     0,
      11,     0,     6,     0,     4,     0,     7,     0,     5,     0,
       6,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
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
#line 116 "Parser.y"
            {block_counter++;}
#line 1473 "Parser.tab.c"
    break;

  case 5: /* block: '{' $@1 program '}'  */
#line 116 "Parser.y"
                                           {end_scope(yylineno);}
#line 1479 "Parser.tab.c"
    break;

  case 13: /* statement: BREAK SEMICOLON  */
#line 126 "Parser.y"
                             {jump_to_end_of_loop();}
#line 1485 "Parser.tab.c"
    break;

  case 14: /* statement: CONTINUE SEMICOLON  */
#line 127 "Parser.y"
                                 {fprintf(quadrupleFilePointer, "\tcontinue\n");}
#line 1491 "Parser.tab.c"
    break;

  case 15: /* statement: return_statement SEMICOLON  */
#line 128 "Parser.y"
                                        {fprintf(quadrupleFilePointer, "\treturn\n");}
#line 1497 "Parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 140 "Parser.y"
      { push_if_end_label(++loop_end_counter); }
#line 1503 "Parser.tab.c"
    break;

  case 22: /* if_wrapper: $@2 if_statement  */
#line 142 "Parser.y"
      { pop_if_end_label(); }
#line 1509 "Parser.tab.c"
    break;

  case 23: /* $@3: %empty  */
#line 147 "Parser.y"
      { jump_if_false(++false_label_counter); }
#line 1515 "Parser.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 149 "Parser.y"
      { jump_to_end_of_if(); pop_last_false_label(); }
#line 1521 "Parser.tab.c"
    break;

  case 29: /* $@5: %empty  */
#line 160 "Parser.y"
      { push_start_label(++loop_start_counter, "while"); }
#line 1527 "Parser.tab.c"
    break;

  case 30: /* while_wrapper: $@5 while_statement  */
#line 162 "Parser.y"
      { pop_start_label(); }
#line 1533 "Parser.tab.c"
    break;

  case 31: /* $@6: %empty  */
#line 167 "Parser.y"
      { jump_if_false(++false_label_counter); }
#line 1539 "Parser.tab.c"
    break;

  case 32: /* while_statement: WHILE expression $@6 block  */
#line 169 "Parser.y"
      { jump_to_start_of_loop("while"); pop_last_false_label(); }
#line 1545 "Parser.tab.c"
    break;

  case 33: /* $@7: %empty  */
#line 173 "Parser.y"
      { push_start_label(++loop_start_counter, "do_while"); }
#line 1551 "Parser.tab.c"
    break;

  case 34: /* do_while_wrapper: $@7 do_while_statement  */
#line 175 "Parser.y"
      { pop_start_label(); }
#line 1557 "Parser.tab.c"
    break;

  case 35: /* do_while_statement: DO block WHILE '(' expression ')' SEMICOLON  */
#line 180 "Parser.y"
      { jump_if_false(++false_label_counter); jump_to_start_of_loop("do_while"); pop_last_false_label(); }
#line 1563 "Parser.tab.c"
    break;

  case 36: /* $@8: %empty  */
#line 184 "Parser.y"
      { push_end_label(++loop_end_counter); }
#line 1569 "Parser.tab.c"
    break;

  case 37: /* switch_wrapper: $@8 switch_statement  */
#line 186 "Parser.y"
      { pop_end_label(); }
#line 1575 "Parser.tab.c"
    break;

  case 38: /* $@9: %empty  */
#line 191 "Parser.y"
    { 
        push_switch_identifier((yyvsp[0].string_type));
        check_symbol((yyvsp[0].string_type), 0, yylineno); 
    }
#line 1584 "Parser.tab.c"
    break;

  case 39: /* switch_statement: SWITCH '(' IDENTIFIER $@9 ')' '{' case_statement '}'  */
#line 196 "Parser.y"
    { 
        pop_switch_identifier(); 
    }
#line 1592 "Parser.tab.c"
    break;

  case 41: /* $@10: %empty  */
#line 207 "Parser.y"
    { 
        push_case_value();
        fprintf(quadrupleFilePointer, "\t%s\n", "equal");
        jump_if_false(++false_label_counter); 
    }
#line 1602 "Parser.tab.c"
    break;

  case 42: /* $@11: %empty  */
#line 213 "Parser.y"
    { 
        pop_last_false_label(); 
    }
#line 1610 "Parser.tab.c"
    break;

  case 46: /* $@12: %empty  */
#line 223 "Parser.y"
        { is_loop = 1; }
#line 1616 "Parser.tab.c"
    break;

  case 47: /* $@13: %empty  */
#line 225 "Parser.y"
        { push_start_label(++loop_start_counter, "for"); }
#line 1622 "Parser.tab.c"
    break;

  case 48: /* $@14: %empty  */
#line 227 "Parser.y"
        { jump_if_false(++false_label_counter); }
#line 1628 "Parser.tab.c"
    break;

  case 49: /* $@15: %empty  */
#line 230 "Parser.y"
      { is_loop = 0; }
#line 1634 "Parser.tab.c"
    break;

  case 50: /* for_wrapper: FOR '(' $@12 statement $@13 statement $@14 statement ')' $@15 block  */
#line 232 "Parser.y"
      { jump_to_start_of_loop("for"); pop_last_false_label(); }
#line 1640 "Parser.tab.c"
    break;

  case 51: /* $@16: %empty  */
#line 238 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "variable", yylineno, false); 
    }
#line 1648 "Parser.tab.c"
    break;

  case 52: /* declaration_statement: data_type IDENTIFIER $@16 ASSIGN expression SEMICOLON  */
#line 242 "Parser.y"
    { 
        insertion_index = -1;
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
    }
#line 1657 "Parser.tab.c"
    break;

  case 53: /* $@17: %empty  */
#line 247 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "variable", yylineno, false); 
    }
#line 1665 "Parser.tab.c"
    break;

  case 54: /* declaration_statement: data_type IDENTIFIER $@17 SEMICOLON  */
#line 251 "Parser.y"
    { 
        insertion_index = -1; 
    }
#line 1673 "Parser.tab.c"
    break;

  case 55: /* $@18: %empty  */
#line 255 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "constant", yylineno, false); 
    }
#line 1681 "Parser.tab.c"
    break;

  case 56: /* declaration_statement: CONSTANT data_type IDENTIFIER $@18 ASSIGN expression SEMICOLON  */
#line 259 "Parser.y"
    { 
        insertion_index = -1; 
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
    }
#line 1690 "Parser.tab.c"
    break;

  case 57: /* $@19: %empty  */
#line 267 "Parser.y"
    { 
        insertion_index = check_symbol((yyvsp[-1].string_type), 1, yylineno); 
        if(symbol_table[insertion_index].type == "constant"){
            printf("Error at line: %d constants must not be reassigned\n", yylineno);
            exit(EXIT_FAILURE); 
        }
    }
#line 1702 "Parser.tab.c"
    break;

  case 58: /* assignment_statement: IDENTIFIER ASSIGN $@19 expression SEMICOLON  */
#line 275 "Parser.y"
    { 
        write_identifier_quadruple((yyvsp[-4].string_type), "pop"); 
    }
#line 1710 "Parser.tab.c"
    break;

  case 59: /* $@20: %empty  */
#line 282 "Parser.y"
    { 
        insertion_index = -1;
    }
#line 1718 "Parser.tab.c"
    break;

  case 60: /* print_statement: PRINT $@20 '(' expression ')' SEMICOLON  */
#line 286 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\t%s\n", "print");
    }
#line 1726 "Parser.tab.c"
    break;

  case 61: /* data_type: INT  */
#line 293 "Parser.y"
    { 
        (yyval.string_type) = "int";   
    }
#line 1734 "Parser.tab.c"
    break;

  case 62: /* data_type: FLOAT  */
#line 297 "Parser.y"
    { 
        (yyval.string_type) = "float"; 
    }
#line 1742 "Parser.tab.c"
    break;

  case 63: /* data_type: STRING  */
#line 301 "Parser.y"
    { 
        (yyval.string_type) = "string"; 
    }
#line 1750 "Parser.tab.c"
    break;

  case 64: /* data_type: CHAR  */
#line 305 "Parser.y"
    { 
        (yyval.string_type) = "char";  
    }
#line 1758 "Parser.tab.c"
    break;

  case 65: /* data_type: BOOL  */
#line 309 "Parser.y"
    { 
        (yyval.string_type) = "bool";  
    }
#line 1766 "Parser.tab.c"
    break;

  case 66: /* data_type: VOID  */
#line 313 "Parser.y"
    { 
        (yyval.string_type) = "void";  
    }
#line 1774 "Parser.tab.c"
    break;

  case 67: /* expression: '(' expression ')'  */
#line 322 "Parser.y"
    { 
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1782 "Parser.tab.c"
    break;

  case 68: /* expression: function_call  */
#line 326 "Parser.y"
    { 
        (yyval.node) = (yyvsp[0].node);  
    }
#line 1790 "Parser.tab.c"
    break;

  case 69: /* expression: IDENTIFIER  */
#line 331 "Parser.y"
    { 
        int i = check_symbol((yyvsp[0].string_type), 0, yylineno);
        check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[0].string_type), "push");
    }
#line 1801 "Parser.tab.c"
    break;

  case 70: /* expression: IDENTIFIER PRE_POST_INC  */
#line 339 "Parser.y"
    { 
        int i = check_symbol((yyvsp[-1].string_type), 0, yylineno);
        check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "post_inc");
        write_identifier_quadruple((yyvsp[-1].string_type), "pop");
    }
#line 1814 "Parser.tab.c"
    break;

  case 71: /* expression: IDENTIFIER PRE_POST_DEC  */
#line 349 "Parser.y"
    { 
        int i = check_symbol((yyvsp[-1].string_type), 0, yylineno);
        check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[-1].string_type), "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "post_dec");
        write_identifier_quadruple((yyvsp[-1].string_type), "pop");
    }
#line 1827 "Parser.tab.c"
    break;

  case 72: /* expression: PRE_POST_INC IDENTIFIER  */
#line 358 "Parser.y"
    { 
        int i = check_symbol((yyvsp[0].string_type), 0, yylineno);
        check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[0].string_type), "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "pre_inc");
    }
#line 1839 "Parser.tab.c"
    break;

  case 73: /* expression: PRE_POST_DEC IDENTIFIER  */
#line 367 "Parser.y"
    { 
        int i = check_symbol((yyvsp[0].string_type), 0, yylineno);
        check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[0].string_type), "push");
        fprintf(quadrupleFilePointer, "\t%s\n", "pre_dec");
    }
#line 1851 "Parser.tab.c"
    break;

  case 74: /* expression: CONSTANT  */
#line 375 "Parser.y"
    { 
        int i = check_symbol((yyvsp[0].string_type), 0, yylineno); 
        check_variable_type(i, yylineno);
        (yyval.node) = create_node(symbol_table[i].ident_data_type);
        write_identifier_quadruple((yyvsp[0].string_type), "push");
    }
#line 1862 "Parser.tab.c"
    break;

  case 75: /* expression: INTEGER_VALUE  */
#line 382 "Parser.y"
    { 
        (yyval.node) = create_node("int");
        check_value_type("int", yylineno);
        check_integer(insertion_index, (yyvsp[0].int_type), yylineno);
    }
#line 1872 "Parser.tab.c"
    break;

  case 76: /* expression: FLOAT_VALUE  */
#line 388 "Parser.y"
    { 
        (yyval.node) = create_node("float");
        check_value_type("float", yylineno);
        check_float(insertion_index, (yyvsp[0].float_type), yylineno);
    }
#line 1882 "Parser.tab.c"
    break;

  case 77: /* expression: BOOL_VALUE  */
#line 394 "Parser.y"
    { 
        (yyval.node) = create_node("bool");
        check_value_type("bool", yylineno);
        check_bool(insertion_index, (yyvsp[0].bool_type), yylineno);
    }
#line 1892 "Parser.tab.c"
    break;

  case 78: /* expression: STRING_VALUE  */
#line 400 "Parser.y"
    { 
        (yyval.node) = create_node("string");
        check_value_type("string", yylineno);
        check_string(insertion_index, (yyvsp[0].string_type), yylineno);
    }
#line 1902 "Parser.tab.c"
    break;

  case 79: /* expression: CHAR_VALUE  */
#line 406 "Parser.y"
    { 
        (yyval.node) = create_node("char");
        check_value_type("char", yylineno);
        check_char(insertion_index, (yyvsp[0].string_type), yylineno);
    }
#line 1912 "Parser.tab.c"
    break;

  case 80: /* expression: SUB expression  */
#line 412 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[0].node), NULL, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "neg");
    }
#line 1921 "Parser.tab.c"
    break;

  case 81: /* expression: LOGICAL_NOT expression  */
#line 417 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[0].node), NULL, yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_not");
    }
#line 1930 "Parser.tab.c"
    break;

  case 82: /* expression: expression ADD expression  */
#line 423 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "add");
    }
#line 1939 "Parser.tab.c"
    break;

  case 83: /* expression: expression SUB expression  */
#line 428 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n","sub");
    }
#line 1948 "Parser.tab.c"
    break;

  case 84: /* expression: expression MUL expression  */
#line 433 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "mul");
    }
#line 1957 "Parser.tab.c"
    break;

  case 85: /* expression: expression DIV expression  */
#line 438 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "div");
    }
#line 1966 "Parser.tab.c"
    break;

  case 86: /* expression: expression POW expression  */
#line 443 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n","pow");
    }
#line 1975 "Parser.tab.c"
    break;

  case 87: /* expression: expression MOD expression  */
#line 448 "Parser.y"
    { 
        (yyval.node) = check_valid_types_arithmetic((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "mod");
    }
#line 1984 "Parser.tab.c"
    break;

  case 88: /* expression: expression BITWISE_OR expression  */
#line 454 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "bitwise_or");
    }
#line 1993 "Parser.tab.c"
    break;

  case 89: /* expression: expression BITWISE_AND expression  */
#line 459 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "bitwise_and");
    }
#line 2002 "Parser.tab.c"
    break;

  case 90: /* expression: expression SHIFT_LEFT expression  */
#line 464 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "shift_left");
    }
#line 2011 "Parser.tab.c"
    break;

  case 91: /* expression: expression SHIFT_RIGHT expression  */
#line 469 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bitwise((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "shift_right");
    }
#line 2020 "Parser.tab.c"
    break;

  case 92: /* expression: expression LOGICAL_AND expression  */
#line 475 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_and");
    }
#line 2029 "Parser.tab.c"
    break;

  case 93: /* expression: expression LOGICAL_OR expression  */
#line 480 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "logical_or");
    }
#line 2038 "Parser.tab.c"
    break;

  case 94: /* expression: expression EQUAL expression  */
#line 486 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "equal");
    }
#line 2047 "Parser.tab.c"
    break;

  case 95: /* expression: expression NOT_EQUAL expression  */
#line 491 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "not_equal");
    }
#line 2056 "Parser.tab.c"
    break;

  case 96: /* expression: expression GREATER_THAN expression  */
#line 497 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "greater_than");
    }
#line 2065 "Parser.tab.c"
    break;

  case 97: /* expression: expression GREATER_EQUAL expression  */
#line 502 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "greater_equal");
    }
#line 2074 "Parser.tab.c"
    break;

  case 98: /* expression: expression LESS_THAN expression  */
#line 507 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "less_than");
    }
#line 2083 "Parser.tab.c"
    break;

  case 99: /* expression: expression LESS_EQUAL expression  */
#line 512 "Parser.y"
    { 
        (yyval.node) = check_valid_types_bool((yyvsp[-2].node), (yyvsp[0].node), yylineno);
        fprintf(quadrupleFilePointer, "\t%s\n", "less_equal");
    }
#line 2092 "Parser.tab.c"
    break;

  case 101: /* return_statement: RETURN expression  */
#line 522 "Parser.y"
    { 
        has_return = 1; 
    }
#line 2100 "Parser.tab.c"
    break;

  case 102: /* $@21: %empty  */
#line 530 "Parser.y"
    { 
        curr_function_arg_count = 0;
        called_function_index = check_symbol((yyvsp[0].string_type), 0, yylineno);
    }
#line 2109 "Parser.tab.c"
    break;

  case 103: /* $@22: %empty  */
#line 535 "Parser.y"
    {is_argument = 1;}
#line 2115 "Parser.tab.c"
    break;

  case 104: /* $@23: %empty  */
#line 537 "Parser.y"
    { 
        is_argument = 0;
        check_function_argument_count(called_function_index, yylineno); 
    }
#line 2124 "Parser.tab.c"
    break;

  case 105: /* function_call: IDENTIFIER $@21 '(' $@22 arguments_list $@23 ')'  */
#line 542 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tcall %s\n", (yyvsp[-6].string_type));
        (yyval.node) = create_node(symbol_table[called_function_index].ident_data_type); 
    }
#line 2133 "Parser.tab.c"
    break;

  case 106: /* $@24: %empty  */
#line 550 "Parser.y"
    { 
        curr_function_arg_count++; 
    }
#line 2141 "Parser.tab.c"
    break;

  case 108: /* arguments_list: expression  */
#line 555 "Parser.y"
    { 
        curr_function_arg_count++; 
    }
#line 2149 "Parser.tab.c"
    break;

  case 110: /* $@25: %empty  */
#line 563 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "%s:\n", (yyvsp[0].string_type));
    }
#line 2157 "Parser.tab.c"
    break;

  case 111: /* $@26: %empty  */
#line 567 "Parser.y"
    { 
        curr_function_index = add_symbol((yyvsp[-5].string_type), (yyvsp[-4].string_type), "function", yylineno, 0);
        pop_function_parameters(curr_function_index); 
    }
#line 2166 "Parser.tab.c"
    break;

  case 112: /* function_declaration: data_type IDENTIFIER $@25 '(' parameters_list ')' $@26 block  */
#line 572 "Parser.y"
    { 
        fprintf(quadrupleFilePointer, "\tend %s\n", (yyvsp[-6].string_type));
    }
#line 2174 "Parser.tab.c"
    break;

  case 113: /* $@27: %empty  */
#line 579 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "variable", yylineno, true); 
    }
#line 2182 "Parser.tab.c"
    break;

  case 115: /* parameters_list: data_type IDENTIFIER  */
#line 584 "Parser.y"
    { 
        insertion_index = add_symbol((yyvsp[-1].string_type), (yyvsp[0].string_type), "variable", yylineno, true); 
    }
#line 2190 "Parser.tab.c"
    break;


#line 2194 "Parser.tab.c"

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

#line 591 "Parser.y"


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
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (strcmp(operand1->type, "string") == 0 ||
            strcmp(operand2->type, "string") == 0 ||
            strcmp(operand1->type, "char") == 0 ||
            strcmp(operand2->type, "char") == 0 ||
            strcmp(operand1->type, "void") == 0 ||
            strcmp(operand2->type, "void") == 0)
        {
            printf("Error at line %d: Invalid types for arithmetic operator (int and float types are valid only)\n", curr_line);
            exit(EXIT_FAILURE);
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
        printf("Error at line %d: Invalid types for bitwise operator\n", curr_line);
        exit(EXIT_FAILURE);
    }

    res->type = "int";
    return res;
}

void end_scope(int line_number)
{
    // Function Return Validations
    if (curr_function_index != -1 && strcmp(symbol_table[curr_function_index].type, "function") == 0)
    {
        // Non-void function missing return
        if (!has_return && strcmp(symbol_table[curr_function_index].ident_data_type, "void") != 0)
        {
            printf("Error at line %d: Missing 'return' in Function\n", line_number);
            fprintf(error_output_file, "Error at line %d: Missing 'return' in Function %s\n", line_number, symbol_table[curr_function_index].identifier);
            exit(EXIT_FAILURE);
        }

        // Void function has a return
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

    // Link Function parameters if This is a Function
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
    if ((strcmp(expected_type, "string") == 0 || strcmp(expected_type, "char") == 0 || strcmp(expected_type, "void") == 0))
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

// Boolean check
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

// String check
void check_string(int index, char *value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    if ((strcmp(type, "string") == 0 && !symbol_table[index].scope_ended) || is_argument)
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

// Char check
void check_char(int index, char *value, int line_number)
{
    if (index == -1)
    {
        fprintf(quadrupleFilePointer, "\tpush %s\n", value);
        return;
    }

    const char *type = symbol_table[index].ident_data_type;

    if ((strcmp(type, "char") == 0 && !symbol_table[index].scope_ended) || is_argument)
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

// Helper: Report function errors with type mismatch
void report_type_mismatch_error(int line_number, const char *identifier1, const char *type1, const char *identifier2, const char *type2)
{
    printf("Error at line %d: %s is %s variable but found %s\n", line_number, identifier1, type1, type2);
    fprintf(error_output_file, "Error at line %d: %s is %s variable but found %s\n", line_number, identifier1, type1, type2);
    exit(EXIT_FAILURE);
}

bool are_types_compatible(const char *type1, const char *type2)
{
    if ((strcmp(type1, "string") == 0 && strcmp(type2, "char") == 0) ||
        (strcmp(type1, "char") == 0 && strcmp(type2, "string") == 0) ||
        (strcmp(type1, "int") == 0 && strcmp(type2, "float") == 0) ||
        (strcmp(type1, "float") == 0 && strcmp(type2, "int") == 0) ||
        (strcmp(type1, "int") == 0 && strcmp(type2, "bool") == 0) ||
        (strcmp(type1, "bool") == 0 && strcmp(type2, "int") == 0) ||
        (strcmp(type1, "bool") == 0 && strcmp(type2, "float") == 0) ||
        (strcmp(type1, "float") == 0 && strcmp(type2, "bool") == 0))
    {
        return true;
    }
    return strcmp(type1, type2) == 0;
}


// Helper: Check parameter type compatibility
void check_argument_type_compatibility(int line_number, int insertion_index, const char *expected_type, const char *actual_type)
{
    if (are_types_compatible(expected_type, actual_type)== false)
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

    if (are_types_compatible(expected_type,actual_type) == false)
    {
        report_type_mismatch_error(line_number, symbol_table[insertion_index].identifier, actual_type, symbol_table[symbol_index].identifier, expected_type);
    }
    else if (strcmp(symbol_table[insertion_index].type, "function") != 0)
    {
        symbol_table[insertion_index].is_initialized = true;
    }
}

// Main check for parameter type assignment
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
    if (are_types_compatible(expected_type, ident_data_type)==false)
    {
        report_type_mismatch_error(line_number, symbol_table[insertion_index].identifier, expected_type, symbol_table[called_function_index].identifier, ident_data_type);
    }
}

// Function argument count check
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

// Pop function arguments
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

    // Check each symbol and write warnings for unused symbols
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

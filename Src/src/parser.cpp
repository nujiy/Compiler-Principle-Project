/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.ypp"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
#include "../include/AST.h"
#include "../include/FlexLexer.h"
using namespace std;

AST* program; // total program
extern int yyparse(yyFlexLexer* yyflex);
int yyerror(const char* s);

#line 86 "parser.cpp"

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

#include "../include/parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COLON = 3,                      /* COLON  */
  YYSYMBOL_SEMICOLON = 4,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 5,                      /* COMMA  */
  YYSYMBOL_LEFTP = 6,                      /* LEFTP  */
  YYSYMBOL_RIGHTP = 7,                     /* RIGHTP  */
  YYSYMBOL_LEFTB = 8,                      /* LEFTB  */
  YYSYMBOL_RIGHTB = 9,                     /* RIGHTB  */
  YYSYMBOL_LEFTSB = 10,                    /* LEFTSB  */
  YYSYMBOL_RIGHTSB = 11,                   /* RIGHTSB  */
  YYSYMBOL_MAIN = 12,                      /* MAIN  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_IN = 15,                        /* IN  */
  YYSYMBOL_TO = 16,                        /* TO  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_IDENTIFIER = 21,                /* IDENTIFIER  */
  YYSYMBOL_STRING_VALUE = 22,              /* STRING_VALUE  */
  YYSYMBOL_INT = 23,                       /* INT  */
  YYSYMBOL_FLOAT = 24,                     /* FLOAT  */
  YYSYMBOL_BOOL = 25,                      /* BOOL  */
  YYSYMBOL_VOID = 26,                      /* VOID  */
  YYSYMBOL_STRING = 27,                    /* STRING  */
  YYSYMBOL_INTEGER_VALUE = 28,             /* INTEGER_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 29,               /* FLOAT_VALUE  */
  YYSYMBOL_BOOL_VALUE = 30,                /* BOOL_VALUE  */
  YYSYMBOL_FALSE = 31,                     /* FALSE  */
  YYSYMBOL_TRUE = 32,                      /* TRUE  */
  YYSYMBOL_ASSIGN = 33,                    /* ASSIGN  */
  YYSYMBOL_GT = 34,                        /* GT  */
  YYSYMBOL_LT = 35,                        /* LT  */
  YYSYMBOL_EQ = 36,                        /* EQ  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_EGT = 38,                       /* EGT  */
  YYSYMBOL_ELT = 39,                       /* ELT  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_ADD = 42,                       /* ADD  */
  YYSYMBOL_SUB = 43,                       /* SUB  */
  YYSYMBOL_MUL = 44,                       /* MUL  */
  YYSYMBOL_DIV = 45,                       /* DIV  */
  YYSYMBOL_POW = 46,                       /* POW  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_global = 49,                    /* global  */
  YYSYMBOL_decl_list = 50,                 /* decl_list  */
  YYSYMBOL_global_item = 51,               /* global_item  */
  YYSYMBOL_main_block = 52,                /* main_block  */
  YYSYMBOL_function = 53,                  /* function  */
  YYSYMBOL_function_list = 54,             /* function_list  */
  YYSYMBOL_function_impl = 55,             /* function_impl  */
  YYSYMBOL_id = 56,                        /* id  */
  YYSYMBOL_variable_decl = 57,             /* variable_decl  */
  YYSYMBOL_array_decl = 58,                /* array_decl  */
  YYSYMBOL_size = 59,                      /* size  */
  YYSYMBOL_protoType = 60,                 /* protoType  */
  YYSYMBOL_parameter_decl = 61,            /* parameter_decl  */
  YYSYMBOL_parameters = 62,                /* parameters  */
  YYSYMBOL_parameter = 63,                 /* parameter  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_value = 65,                     /* value  */
  YYSYMBOL_function_body = 66,             /* function_body  */
  YYSYMBOL_stmt_list = 67,                 /* stmt_list  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_func_call = 70,                 /* func_call  */
  YYSYMBOL_parameterExprs = 71,            /* parameterExprs  */
  YYSYMBOL_variables = 72,                 /* variables  */
  YYSYMBOL_loop = 73,                      /* loop  */
  YYSYMBOL_for_loop = 74,                  /* for_loop  */
  YYSYMBOL_while_loop = 75,                /* while_loop  */
  YYSYMBOL_condition = 76,                 /* condition  */
  YYSYMBOL_else_block = 77,                /* else_block  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_expr_return = 79,               /* expr_return  */
  YYSYMBOL_relation_expr = 80,             /* relation_expr  */
  YYSYMBOL_relation_op = 81,               /* relation_op  */
  YYSYMBOL_logic_expr = 82,                /* logic_expr  */
  YYSYMBOL_logic_term = 83,                /* logic_term  */
  YYSYMBOL_logic_op = 84,                  /* logic_op  */
  YYSYMBOL_arith_expr = 85,                /* arith_expr  */
  YYSYMBOL_term = 86,                      /* term  */
  YYSYMBOL_left_id = 87,                   /* left_id  */
  YYSYMBOL_factor = 88                     /* factor  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    69,    72,    73,    76,    77,    78,    81,
      83,    86,    87,    90,    93,    96,    97,   100,   101,   102,
     104,   107,   108,   111,   112,   115,   116,   118,   119,   120,
     121,   122,   125,   126,   127,   128,   129,   132,   135,   136,
     137,   138,   141,   142,   143,   144,   147,   150,   153,   154,
     157,   158,   161,   162,   164,   168,   172,   177,   178,   180,
     181,   182,   185,   186,   187,   188,   191,   193,   194,   195,
     196,   197,   198,   200,   201,   204,   206,   207,   209,   210,
     211,   214,   215,   216,   217,   220,   221,   222,   224,   225,
     226,   227
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
  "\"end of file\"", "error", "\"invalid token\"", "COLON", "SEMICOLON",
  "COMMA", "LEFTP", "RIGHTP", "LEFTB", "RIGHTB", "LEFTSB", "RIGHTSB",
  "MAIN", "RETURN", "FOR", "IN", "TO", "WHILE", "IF", "ELSE", "BREAK",
  "IDENTIFIER", "STRING_VALUE", "INT", "FLOAT", "BOOL", "VOID", "STRING",
  "INTEGER_VALUE", "FLOAT_VALUE", "BOOL_VALUE", "FALSE", "TRUE", "ASSIGN",
  "GT", "LT", "EQ", "NEQ", "EGT", "ELT", "AND", "OR", "ADD", "SUB", "MUL",
  "DIV", "POW", "$accept", "program", "global", "decl_list", "global_item",
  "main_block", "function", "function_list", "function_impl", "id",
  "variable_decl", "array_decl", "size", "protoType", "parameter_decl",
  "parameters", "parameter", "type", "value", "function_body", "stmt_list",
  "stmt", "assignment", "func_call", "parameterExprs", "variables", "loop",
  "for_loop", "while_loop", "condition", "else_block", "expression",
  "expr_return", "relation_expr", "relation_op", "logic_expr",
  "logic_term", "logic_op", "arith_expr", "term", "left_id", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
#endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -132,     8,     2,    55,  -132,    16,  -132,  -132,  -132,  -132,
    -132,  -132,    46,  -132,  -132,  -132,    32,    21,  -132,    55,
    -132,  -132,    19,    57,  -132,    57,    32,    68,     9,   101,
    -132,  -132,  -132,    79,    82,    55,  -132,  -132,    83,   113,
    -132,  -132,  -132,  -132,  -132,     7,  -132,  -132,  -132,  -132,
     -22,  -132,   146,    15,  -132,  -132,   133,  -132,  -132,  -132,
      88,    32,  -132,   113,    89,    -3,    96,    84,  -132,  -132,
     105,  -132,  -132,  -132,  -132,  -132,  -132,   113,   113,   113,
     113,   113,   113,  -132,    45,   108,   111,   112,  -132,  -132,
     116,  -132,  -132,  -132,  -132,  -132,  -132,   115,    93,  -132,
       5,     4,  -132,  -132,   114,   101,  -132,   117,   113,  -132,
      15,    15,    14,  -132,  -132,  -132,  -132,   123,    32,   101,
     113,  -132,  -132,   101,  -132,   126,  -132,   146,  -132,   128,
     132,   136,   141,  -132,  -132,   113,   131,   144,   145,  -132,
    -132,    32,   152,   133,   148,  -132,   153,   155,   121,  -132,
     156,  -132,   133,  -132,   158,   133,  -132,   159,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     3,     1,     0,    12,    27,    28,    29,
      30,    31,     0,     6,     8,     7,     0,     0,     2,    10,
       4,    14,    15,     0,    11,     0,     0,    24,     0,     0,
      41,     9,    13,     0,     0,     0,    18,    19,     0,     0,
      36,    32,    33,    34,    35,    85,    89,    90,    16,    60,
      61,    74,    59,    80,    91,    84,    65,    20,    25,    26,
      21,     0,    17,     0,     0,     0,    51,     0,    76,    77,
       0,    68,    67,    72,    71,    70,    69,     0,     0,     0,
       0,     0,     0,    64,     0,     0,     0,     0,    44,    45,
       0,    42,    43,    39,    52,    53,    40,     0,     0,    23,
      15,     0,    75,    88,     0,     0,    87,     0,     0,    73,
      78,    79,    66,    82,    83,    81,    63,     0,     0,     0,
       0,    38,    37,     0,    47,    48,    86,     0,    62,    85,
       0,     0,     0,    46,    50,     0,     0,     0,     0,    41,
      41,     0,     0,    65,     0,    55,     0,     0,    58,    41,
       0,    56,    65,    41,     0,    65,    54,     0,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   -16,
       6,    13,  -132,   134,  -132,  -132,  -132,    24,  -132,   140,
     -85,  -132,  -111,   -51,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,   -61,  -131,   -36,  -132,  -132,   102,  -132,   -37,    -8,
     -55,    28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,    12,     6,    18,    19,    24,    45,
      88,    89,    38,    15,    34,    35,    60,    61,    46,    31,
      56,    90,    91,    47,   104,   105,    93,    94,    95,    96,
     151,    48,    97,    49,    79,    50,    51,    70,    52,    53,
      54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    98,    65,    64,   103,    92,   107,   130,     4,    13,
      33,   103,   146,    66,     5,    28,    14,    67,    68,    69,
      36,   154,    17,   117,   157,    27,   101,    16,    23,    28,
     144,    71,    72,    73,    74,    75,    76,    37,    29,    77,
      78,    58,   112,    26,   125,   100,    77,    78,    59,   116,
      20,    39,    29,    21,   142,   143,    77,    78,   131,    80,
      81,    82,   133,    98,   152,    30,    21,    40,   155,   110,
     111,   127,    64,    41,    42,   -22,    43,    44,     7,     8,
       9,    10,    11,   127,   132,    27,    98,    98,    98,    57,
      39,    92,    92,    99,    62,   106,   102,    98,   127,   138,
      98,    92,   129,   -49,    92,    21,    40,    39,   113,   114,
     115,   108,    41,    42,   118,    43,    44,   119,   120,    63,
     121,   124,    21,    40,   122,   129,   123,   128,   126,    41,
      42,   134,    43,    44,    21,    40,   135,    83,    67,   139,
     150,    41,    42,   136,    43,    44,    84,    85,   137,   141,
      86,    87,   140,    25,    21,   147,     7,     8,     9,    10,
      11,   145,   148,   149,   153,    32,    85,   156,   158,    86,
      87,     0,   109,    21,     0,     7,     8,     9,    10,    11,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78
};

static const yytype_int16 yycheck[] =
{
      16,    56,    39,    39,     7,    56,    67,   118,     0,     3,
      26,     7,   143,     6,    12,    10,     3,    10,    40,    41,
      11,   152,     6,    84,   155,     6,    63,     3,     7,    10,
     141,    34,    35,    36,    37,    38,    39,    28,    33,    42,
      43,    35,    79,    19,   105,    61,    42,    43,    35,     4,
       4,     6,    33,    21,   139,   140,    42,    43,   119,    44,
      45,    46,   123,   118,   149,     8,    21,    22,   153,    77,
      78,   108,   108,    28,    29,     7,    31,    32,    23,    24,
      25,    26,    27,   120,   120,     6,   141,   142,   143,     7,
       6,   142,   143,     5,    11,    11,     7,   152,   135,   135,
     155,   152,   118,     7,   155,    21,    22,     6,    80,    81,
      82,     6,    28,    29,     6,    31,    32,     6,     6,     6,
       4,     7,    21,    22,     9,   141,    33,     4,    11,    28,
      29,     5,    31,    32,    21,    22,     4,     4,    10,     8,
      19,    28,    29,     7,    31,    32,    13,    14,     7,     4,
      17,    18,     8,    19,    21,     7,    23,    24,    25,    26,
      27,     9,     9,     8,     8,    25,    14,     9,     9,    17,
      18,    -1,    70,    21,    -1,    23,    24,    25,    26,    27,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,    50,     0,    12,    52,    23,    24,    25,
      26,    27,    51,    57,    58,    60,    64,     6,    53,    54,
       4,    21,    56,     7,    55,    60,    64,     6,    10,    33,
       8,    66,    66,    56,    61,    62,    11,    28,    59,     6,
      22,    28,    29,    31,    32,    56,    65,    70,    78,    80,
      82,    83,    85,    86,    87,    88,    67,     7,    57,    58,
      63,    64,    11,     6,    80,    85,     6,    10,    40,    41,
      84,    34,    35,    36,    37,    38,    39,    42,    43,    81,
      44,    45,    46,     4,    13,    14,    17,    18,    57,    58,
      68,    69,    70,    73,    74,    75,    76,    79,    87,     5,
      56,    85,     7,     7,    71,    72,    11,    78,     6,    83,
      86,    86,    85,    88,    88,    88,     4,    78,     6,     6,
       6,     4,     9,    33,     7,    78,    11,    85,     4,    56,
      69,    78,    80,    78,     5,     4,     7,     7,    80,     8,
       8,     4,    67,    67,    69,     9,    79,     7,     9,     8,
      19,    77,    67,     8,    79,    67,     9,    79,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    51,    51,    51,    52,
      53,    54,    54,    55,    56,    57,    57,    58,    58,    59,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    66,    67,    67,
      67,    67,    68,    68,    68,    68,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    76,    77,    77,    78,
      78,    78,    79,    79,    79,    79,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    84,    84,    85,    85,
      85,    86,    86,    86,    86,    87,    87,    87,    88,    88,
      88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     3,     0,     1,     1,     1,     4,
       1,     2,     0,     2,     1,     2,     4,     5,     4,     1,
       5,     2,     0,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     2,
       2,     0,     1,     1,     1,     1,     3,     4,     2,     0,
       3,     0,     1,     1,    12,     7,     9,     5,     0,     1,
       1,     1,     3,     2,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     4,     3,     3,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
yyparse (yyFlexLexer* yyflex)
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
      yychar = yyflex->yylex ();
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
  case 2: /* program: global main_block function  */
#line 66 "yacc.ypp"
                                    {program = new AST((yyvsp[-2].block),(yyvsp[-1].block),(yyvsp[0].block));}
#line 1279 "parser.cpp"
    break;

  case 3: /* global: decl_list  */
#line 69 "yacc.ypp"
                  {(yyval.block) = new GlobalPart((yyvsp[0].declList));}
#line 1285 "parser.cpp"
    break;

  case 4: /* decl_list: decl_list global_item SEMICOLON  */
#line 72 "yacc.ypp"
                                           {(yyval.declList)->addDecl((yyvsp[-1].decl)); (yyval.declList) = (yyvsp[-2].declList);}
#line 1291 "parser.cpp"
    break;

  case 5: /* decl_list: %empty  */
#line 73 "yacc.ypp"
                          {(yyval.declList) = new DeclList();}
#line 1297 "parser.cpp"
    break;

  case 6: /* global_item: variable_decl  */
#line 76 "yacc.ypp"
                           {(yyval.decl) = (yyvsp[0].decl);}
#line 1303 "parser.cpp"
    break;

  case 7: /* global_item: protoType  */
#line 77 "yacc.ypp"
                                  {(yyval.decl) = (yyvsp[0].decl);}
#line 1309 "parser.cpp"
    break;

  case 8: /* global_item: array_decl  */
#line 78 "yacc.ypp"
                               {(yyval.decl) = (yyvsp[0].decl);}
#line 1315 "parser.cpp"
    break;

  case 9: /* main_block: MAIN LEFTP RIGHTP function_body  */
#line 81 "yacc.ypp"
                                            {(yyval.block) = new MainPart((yyvsp[0].funcbody));}
#line 1321 "parser.cpp"
    break;

  case 10: /* function: function_list  */
#line 83 "yacc.ypp"
                        {(yyval.block) = new FuncPart((yyvsp[0].funcList));}
#line 1327 "parser.cpp"
    break;

  case 11: /* function_list: function_list function_impl  */
#line 86 "yacc.ypp"
                                           {(yyvsp[-1].funcList)->addFunction((yyvsp[0].funcImpl)); (yyval.funcList) = (yyvsp[-1].funcList);}
#line 1333 "parser.cpp"
    break;

  case 12: /* function_list: %empty  */
#line 87 "yacc.ypp"
                  {(yyval.funcList) = new FuncList();}
#line 1339 "parser.cpp"
    break;

  case 13: /* function_impl: protoType function_body  */
#line 90 "yacc.ypp"
                                       {(yyval.funcImpl) = new FuncImpl((yyvsp[-1].decl),(yyvsp[0].funcbody));}
#line 1345 "parser.cpp"
    break;

  case 14: /* id: IDENTIFIER  */
#line 93 "yacc.ypp"
               {(yyval.expr) = new Identifier(*(yyvsp[0].Str));}
#line 1351 "parser.cpp"
    break;

  case 15: /* variable_decl: type id  */
#line 96 "yacc.ypp"
                        {(yyval.decl) = new VariableDecl((yyvsp[-1].dataType),(yyvsp[0].expr));}
#line 1357 "parser.cpp"
    break;

  case 16: /* variable_decl: type id ASSIGN expression  */
#line 97 "yacc.ypp"
                                            {(yyval.decl) = new VariableDecl((yyvsp[-3].dataType),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1363 "parser.cpp"
    break;

  case 17: /* array_decl: type id LEFTSB size RIGHTSB  */
#line 100 "yacc.ypp"
                                        {(yyval.decl) = new ArrayDecl((yyvsp[-4].dataType),(yyvsp[-3].expr),(yyvsp[-1].intval));}
#line 1369 "parser.cpp"
    break;

  case 18: /* array_decl: type id LEFTSB RIGHTSB  */
#line 101 "yacc.ypp"
                                    {(yyval.decl) = new ArrayDecl((yyvsp[-3].dataType),(yyvsp[-2].expr));}
#line 1375 "parser.cpp"
    break;

  case 19: /* size: INTEGER_VALUE  */
#line 102 "yacc.ypp"
                    {(yyval.intval) = atoi((yyvsp[0].valueStr));}
#line 1381 "parser.cpp"
    break;

  case 20: /* protoType: type id LEFTP parameter_decl RIGHTP  */
#line 104 "yacc.ypp"
                                               {(yyval.decl) = new ProtoType((yyvsp[-4].dataType),(yyvsp[-3].expr),(yyvsp[-1].declList));}
#line 1387 "parser.cpp"
    break;

  case 21: /* parameter_decl: parameters parameter  */
#line 107 "yacc.ypp"
                                     {(yyvsp[-1].declList)->addDecl((yyvsp[0].decl)); (yyval.declList) = (yyvsp[-1].declList);}
#line 1393 "parser.cpp"
    break;

  case 22: /* parameter_decl: %empty  */
#line 108 "yacc.ypp"
                  {(yyval.declList) = new DeclList();}
#line 1399 "parser.cpp"
    break;

  case 23: /* parameters: parameters parameter COMMA  */
#line 111 "yacc.ypp"
                                       {(yyvsp[-2].declList)->addDecl((yyvsp[-1].decl)); (yyval.declList) = (yyvsp[-2].declList);}
#line 1405 "parser.cpp"
    break;

  case 24: /* parameters: %empty  */
#line 112 "yacc.ypp"
                  {(yyval.declList) = new DeclList();}
#line 1411 "parser.cpp"
    break;

  case 25: /* parameter: variable_decl  */
#line 115 "yacc.ypp"
                         {(yyval.decl) = (yyvsp[0].decl);}
#line 1417 "parser.cpp"
    break;

  case 26: /* parameter: array_decl  */
#line 116 "yacc.ypp"
                     {(yyval.decl) = (yyvsp[0].decl);}
#line 1423 "parser.cpp"
    break;

  case 27: /* type: INT  */
#line 118 "yacc.ypp"
          {(yyval.dataType) = VALUEINT;}
#line 1429 "parser.cpp"
    break;

  case 28: /* type: FLOAT  */
#line 119 "yacc.ypp"
                {(yyval.dataType) = VALUEFLOAT;}
#line 1435 "parser.cpp"
    break;

  case 29: /* type: BOOL  */
#line 120 "yacc.ypp"
               {(yyval.dataType) = VALUEBOOL;}
#line 1441 "parser.cpp"
    break;

  case 30: /* type: VOID  */
#line 121 "yacc.ypp"
               {(yyval.dataType) = VALUEVOID;}
#line 1447 "parser.cpp"
    break;

  case 31: /* type: STRING  */
#line 122 "yacc.ypp"
                 {(yyval.dataType) = VALUESTRING;}
#line 1453 "parser.cpp"
    break;

  case 32: /* value: INTEGER_VALUE  */
#line 125 "yacc.ypp"
                     {(yyval.expr) = new Integer(atoi((yyvsp[0].valueStr)));}
#line 1459 "parser.cpp"
    break;

  case 33: /* value: FLOAT_VALUE  */
#line 126 "yacc.ypp"
                      {double num = atof(yyvsp[0].valueStr);printf("%f",num);(yyval.expr) = new Float(num);}
#line 1465 "parser.cpp"
    break;

  case 34: /* value: FALSE  */
#line 127 "yacc.ypp"
                {(yyval.expr) = new Bool(false);}
#line 1471 "parser.cpp"
    break;

  case 35: /* value: TRUE  */
#line 128 "yacc.ypp"
               {(yyval.expr) = new Bool(true);}
#line 1477 "parser.cpp"
    break;

  case 36: /* value: STRING_VALUE  */
#line 129 "yacc.ypp"
                       {(yyval.expr) = new String(*(yyvsp[0].Str));}
#line 1483 "parser.cpp"
    break;

  case 37: /* function_body: LEFTB stmt_list expr_return RIGHTB  */
#line 132 "yacc.ypp"
                                                   {(yyval.funcbody) = new FuncBody((yyvsp[-2].stmtList),(yyvsp[-1].expr));}
#line 1489 "parser.cpp"
    break;

  case 38: /* stmt_list: stmt_list stmt SEMICOLON  */
#line 135 "yacc.ypp"
                                    {(yyvsp[-2].stmtList)->addStmt((yyvsp[-1].stmt)); (yyval.stmtList) = (yyvsp[-2].stmtList);}
#line 1495 "parser.cpp"
    break;

  case 39: /* stmt_list: stmt_list loop  */
#line 136 "yacc.ypp"
                         {(yyvsp[-1].stmtList)->addStmt((yyvsp[0].stmt)); (yyval.stmtList) = (yyvsp[-1].stmtList);}
#line 1501 "parser.cpp"
    break;

  case 40: /* stmt_list: stmt_list condition  */
#line 137 "yacc.ypp"
                              {(yyvsp[-1].stmtList)->addStmt((yyvsp[0].stmt)); (yyval.stmtList) = (yyvsp[-1].stmtList);}
#line 1507 "parser.cpp"
    break;

  case 41: /* stmt_list: %empty  */
#line 138 "yacc.ypp"
                  {(yyval.stmtList) = new StmtList();}
#line 1513 "parser.cpp"
    break;

  case 42: /* stmt: assignment  */
#line 141 "yacc.ypp"
                 {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1519 "parser.cpp"
    break;

  case 43: /* stmt: func_call  */
#line 142 "yacc.ypp"
                    {(yyval.stmt) = (yyvsp[0].expr);}
#line 1525 "parser.cpp"
    break;

  case 44: /* stmt: variable_decl  */
#line 143 "yacc.ypp"
                        {(yyval.stmt) = (yyvsp[0].decl);}
#line 1531 "parser.cpp"
    break;

  case 45: /* stmt: array_decl  */
#line 144 "yacc.ypp"
                     {(yyval.stmt) = (yyvsp[0].decl);}
#line 1537 "parser.cpp"
    break;

  case 46: /* assignment: left_id ASSIGN expression  */
#line 147 "yacc.ypp"
                                      {(yyval.stmt) = new Assignment((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1543 "parser.cpp"
    break;

  case 47: /* func_call: id LEFTP parameterExprs RIGHTP  */
#line 150 "yacc.ypp"
                                          {(yyval.expr) = new FuncCall((yyvsp[-3].expr),(yyvsp[-1].exprList));}
#line 1549 "parser.cpp"
    break;

  case 48: /* parameterExprs: variables expression  */
#line 153 "yacc.ypp"
                                     {(yyvsp[-1].exprList)->addExpr((yyvsp[0].expr)); (yyval.exprList) = (yyvsp[-1].exprList);}
#line 1555 "parser.cpp"
    break;

  case 49: /* parameterExprs: %empty  */
#line 154 "yacc.ypp"
                  {(yyval.exprList) = new ExprList();}
#line 1561 "parser.cpp"
    break;

  case 50: /* variables: variables expression COMMA  */
#line 157 "yacc.ypp"
                                      {(yyvsp[-2].exprList)->addExpr((yyvsp[-1].expr)); (yyval.exprList) = (yyvsp[-2].exprList);}
#line 1567 "parser.cpp"
    break;

  case 51: /* variables: %empty  */
#line 158 "yacc.ypp"
                  {(yyval.exprList) = new ExprList();}
#line 1573 "parser.cpp"
    break;

  case 52: /* loop: for_loop  */
#line 161 "yacc.ypp"
                {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1579 "parser.cpp"
    break;

  case 53: /* loop: while_loop  */
#line 162 "yacc.ypp"
                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1585 "parser.cpp"
    break;

  case 54: /* for_loop: FOR LEFTP assignment SEMICOLON relation_expr SEMICOLON assignment RIGHTP LEFTB stmt_list expr_return RIGHTB  */
#line 164 "yacc.ypp"
                                                                                                                       {
	(yyval.stmt) = new ForLoop((yyvsp[-9].stmt),(yyvsp[-7].expr),(yyvsp[-5].stmt),(yyvsp[-2].stmtList),(yyvsp[-1].expr));
}
#line 1593 "parser.cpp"
    break;

  case 55: /* while_loop: WHILE LEFTP expression RIGHTP LEFTB stmt_list RIGHTB  */
#line 168 "yacc.ypp"
                                                                  {
	(yyval.stmt) = new WhileLoop((yyvsp[-4].expr),(yyvsp[-1].stmtList));
}
#line 1601 "parser.cpp"
    break;

  case 56: /* condition: IF LEFTP relation_expr RIGHTP LEFTB stmt_list expr_return RIGHTB else_block  */
#line 172 "yacc.ypp"
                                                                                        {
ConditionBlock* ifBlock = new ConditionBlock((yyvsp[-3].stmtList),(yyvsp[-2].expr));
(yyval.stmt) =new Condition((yyvsp[-6].expr),ifBlock,(yyvsp[0].stmt));
}
#line 1610 "parser.cpp"
    break;

  case 57: /* else_block: ELSE LEFTB stmt_list expr_return RIGHTB  */
#line 177 "yacc.ypp"
                                                     {(yyval.stmt) = new ConditionBlock((yyvsp[-2].stmtList),(yyvsp[-1].expr));}
#line 1616 "parser.cpp"
    break;

  case 58: /* else_block: %empty  */
#line 178 "yacc.ypp"
              {(yyval.stmt) = nullptr;}
#line 1622 "parser.cpp"
    break;

  case 59: /* expression: arith_expr  */
#line 180 "yacc.ypp"
                       {(yyval.expr) = (yyvsp[0].expr);}
#line 1628 "parser.cpp"
    break;

  case 60: /* expression: relation_expr  */
#line 181 "yacc.ypp"
                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1634 "parser.cpp"
    break;

  case 61: /* expression: logic_expr  */
#line 182 "yacc.ypp"
                         {(yyval.expr) = (yyvsp[0].expr);}
#line 1640 "parser.cpp"
    break;

  case 62: /* expr_return: RETURN expression SEMICOLON  */
#line 185 "yacc.ypp"
                                         {(yyval.expr) = (yyvsp[-1].expr);}
#line 1646 "parser.cpp"
    break;

  case 63: /* expr_return: RETURN SEMICOLON  */
#line 186 "yacc.ypp"
                                   {(yyval.expr) = new Void();}
#line 1652 "parser.cpp"
    break;

  case 64: /* expr_return: SEMICOLON  */
#line 187 "yacc.ypp"
                            {(yyval.expr) = nullptr;}
#line 1658 "parser.cpp"
    break;

  case 65: /* expr_return: %empty  */
#line 188 "yacc.ypp"
                  {(yyval.expr) = nullptr;}
#line 1664 "parser.cpp"
    break;

  case 66: /* relation_expr: arith_expr relation_op arith_expr  */
#line 191 "yacc.ypp"
                                                 {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].intval));}
#line 1670 "parser.cpp"
    break;

  case 67: /* relation_op: LT  */
#line 193 "yacc.ypp"
                {(yyval.intval) = OPLT;}
#line 1676 "parser.cpp"
    break;

  case 68: /* relation_op: GT  */
#line 194 "yacc.ypp"
                 {(yyval.intval) = OPGT;}
#line 1682 "parser.cpp"
    break;

  case 69: /* relation_op: ELT  */
#line 195 "yacc.ypp"
                  {(yyval.intval) = OPELT;}
#line 1688 "parser.cpp"
    break;

  case 70: /* relation_op: EGT  */
#line 196 "yacc.ypp"
                  {(yyval.intval) = OPEGT;}
#line 1694 "parser.cpp"
    break;

  case 71: /* relation_op: NEQ  */
#line 197 "yacc.ypp"
                  {(yyval.intval) = OPNEQ;}
#line 1700 "parser.cpp"
    break;

  case 72: /* relation_op: EQ  */
#line 198 "yacc.ypp"
                 {(yyval.intval) = OPEQ;}
#line 1706 "parser.cpp"
    break;

  case 73: /* logic_expr: logic_expr logic_op logic_term  */
#line 200 "yacc.ypp"
                                          {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].intval));}
#line 1712 "parser.cpp"
    break;

  case 74: /* logic_expr: logic_term  */
#line 201 "yacc.ypp"
                         {(yyval.expr) = (yyvsp[0].expr);}
#line 1718 "parser.cpp"
    break;

  case 75: /* logic_term: LEFTP relation_expr RIGHTP  */
#line 204 "yacc.ypp"
                                       {(yyval.expr) = (yyvsp[-1].expr);}
#line 1724 "parser.cpp"
    break;

  case 76: /* logic_op: AND  */
#line 206 "yacc.ypp"
              {(yyval.intval) = OPAND;}
#line 1730 "parser.cpp"
    break;

  case 77: /* logic_op: OR  */
#line 207 "yacc.ypp"
                 {(yyval.intval) = OPOR;}
#line 1736 "parser.cpp"
    break;

  case 78: /* arith_expr: arith_expr ADD term  */
#line 209 "yacc.ypp"
                                {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPADD);}
#line 1742 "parser.cpp"
    break;

  case 79: /* arith_expr: arith_expr SUB term  */
#line 210 "yacc.ypp"
                              {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPSUB);}
#line 1748 "parser.cpp"
    break;

  case 80: /* arith_expr: term  */
#line 211 "yacc.ypp"
               {(yyval.expr) = (yyvsp[0].expr);}
#line 1754 "parser.cpp"
    break;

  case 81: /* term: term POW factor  */
#line 214 "yacc.ypp"
                      {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPPOW); }
#line 1760 "parser.cpp"
    break;

  case 82: /* term: term MUL factor  */
#line 215 "yacc.ypp"
                          {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPMUL); }
#line 1766 "parser.cpp"
    break;

  case 83: /* term: term DIV factor  */
#line 216 "yacc.ypp"
                          {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPDIV); }
#line 1772 "parser.cpp"
    break;

  case 84: /* term: factor  */
#line 217 "yacc.ypp"
                 {(yyval.expr) = (yyvsp[0].expr); }
#line 1778 "parser.cpp"
    break;

  case 85: /* left_id: id  */
#line 220 "yacc.ypp"
            {(yyval.expr) = (yyvsp[0].expr);}
#line 1784 "parser.cpp"
    break;

  case 86: /* left_id: id LEFTSB expression RIGHTSB  */
#line 221 "yacc.ypp"
                                       {(yyval.expr) = new ArrayExpr((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1790 "parser.cpp"
    break;

  case 87: /* left_id: id LEFTSB RIGHTSB  */
#line 222 "yacc.ypp"
                            {(yyval.expr) = new ArrayExpr((yyvsp[-2].expr));}
#line 1796 "parser.cpp"
    break;

  case 88: /* factor: LEFTP arith_expr RIGHTP  */
#line 224 "yacc.ypp"
                                {(yyval.expr) = (yyvsp[-1].expr); }
#line 1802 "parser.cpp"
    break;

  case 89: /* factor: value  */
#line 225 "yacc.ypp"
                {(yyval.expr) = (yyvsp[0].expr);}
#line 1808 "parser.cpp"
    break;

  case 90: /* factor: func_call  */
#line 226 "yacc.ypp"
                    {(yyval.expr) = (yyvsp[0].expr);}
#line 1814 "parser.cpp"
    break;

  case 91: /* factor: left_id  */
#line 227 "yacc.ypp"
                  {(yyval.expr) = (yyvsp[0].expr);}
#line 1820 "parser.cpp"
    break;


#line 1824 "parser.cpp"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 230 "yacc.ypp"


int yyerror(const char *s){
	cout<<s<<endl;
	return 0;
}

/*
array_decl: type id LEFTSB size RIGHTSB {$$ = new ArrayDecl($1,$2,$4);}
size: INTEGER_VALUE {$$ = atoi($1);}
*/

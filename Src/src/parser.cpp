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
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_LEFTP = 5,                      /* LEFTP  */
  YYSYMBOL_RIGHTP = 6,                     /* RIGHTP  */
  YYSYMBOL_LEFTB = 7,                      /* LEFTB  */
  YYSYMBOL_RIGHTB = 8,                     /* RIGHTB  */
  YYSYMBOL_LEFTSB = 9,                     /* LEFTSB  */
  YYSYMBOL_RIGHTSB = 10,                   /* RIGHTSB  */
  YYSYMBOL_MAIN = 11,                      /* MAIN  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_IDENTIFIER = 18,                /* IDENTIFIER  */
  YYSYMBOL_STRING_VALUE = 19,              /* STRING_VALUE  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_FLOAT = 21,                     /* FLOAT  */
  YYSYMBOL_BOOL = 22,                      /* BOOL  */
  YYSYMBOL_VOID = 23,                      /* VOID  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_INTEGER_VALUE = 25,             /* INTEGER_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 26,               /* FLOAT_VALUE  */
  YYSYMBOL_BOOL_VALUE = 27,                /* BOOL_VALUE  */
  YYSYMBOL_FALSE = 28,                     /* FALSE  */
  YYSYMBOL_TRUE = 29,                      /* TRUE  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NEQ = 34,                       /* NEQ  */
  YYSYMBOL_EGT = 35,                       /* EGT  */
  YYSYMBOL_ELT = 36,                       /* ELT  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_ADD = 39,                       /* ADD  */
  YYSYMBOL_SUB = 40,                       /* SUB  */
  YYSYMBOL_MUL = 41,                       /* MUL  */
  YYSYMBOL_DIV = 42,                       /* DIV  */
  YYSYMBOL_POW = 43,                       /* POW  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_global = 46,                    /* global  */
  YYSYMBOL_decl_list = 47,                 /* decl_list  */
  YYSYMBOL_global_item = 48,               /* global_item  */
  YYSYMBOL_main_block = 49,                /* main_block  */
  YYSYMBOL_function = 50,                  /* function  */
  YYSYMBOL_function_list = 51,             /* function_list  */
  YYSYMBOL_function_impl = 52,             /* function_impl  */
  YYSYMBOL_id = 53,                        /* id  */
  YYSYMBOL_variable_decl = 54,             /* variable_decl  */
  YYSYMBOL_array_decl = 55,                /* array_decl  */
  YYSYMBOL_size = 56,                      /* size  */
  YYSYMBOL_protoType = 57,                 /* protoType  */
  YYSYMBOL_parameter_decl = 58,            /* parameter_decl  */
  YYSYMBOL_parameters = 59,                /* parameters  */
  YYSYMBOL_parameter = 60,                 /* parameter  */
  YYSYMBOL_type = 61,                      /* type  */
  YYSYMBOL_value = 62,                     /* value  */
  YYSYMBOL_function_body = 63,             /* function_body  */
  YYSYMBOL_stmt_list = 64,                 /* stmt_list  */
  YYSYMBOL_stmt = 65,                      /* stmt  */
  YYSYMBOL_assignment = 66,                /* assignment  */
  YYSYMBOL_func_call = 67,                 /* func_call  */
  YYSYMBOL_parameterExprs = 68,            /* parameterExprs  */
  YYSYMBOL_variables = 69,                 /* variables  */
  YYSYMBOL_loop = 70,                      /* loop  */
  YYSYMBOL_for_loop = 71,                  /* for_loop  */
  YYSYMBOL_while_loop = 72,                /* while_loop  */
  YYSYMBOL_condition = 73,                 /* condition  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_expr_return = 75,               /* expr_return  */
  YYSYMBOL_relation_expr = 76,             /* relation_expr  */
  YYSYMBOL_relation_op = 77,               /* relation_op  */
  YYSYMBOL_logic_expr = 78,                /* logic_expr  */
  YYSYMBOL_logic_term = 79,                /* logic_term  */
  YYSYMBOL_logic_op = 80,                  /* logic_op  */
  YYSYMBOL_arith_expr = 81,                /* arith_expr  */
  YYSYMBOL_term = 82,                      /* term  */
  YYSYMBOL_left_id = 83,                   /* left_id  */
  YYSYMBOL_factor = 84                     /* factor  */
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
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
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
     157,   158,   161,   162,   164,   168,   172,   173,   176,   177,
     178,   181,   182,   183,   184,   187,   189,   190,   191,   192,
     193,   195,   196,   199,   201,   202,   204,   205,   206,   209,
     210,   211,   212,   215,   216,   218,   219,   220,   221
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COMMA",
  "LEFTP", "RIGHTP", "LEFTB", "RIGHTB", "LEFTSB", "RIGHTSB", "MAIN",
  "RETURN", "FOR", "WHILE", "IF", "ELSE", "BREAK", "IDENTIFIER",
  "STRING_VALUE", "INT", "FLOAT", "BOOL", "VOID", "STRING",
  "INTEGER_VALUE", "FLOAT_VALUE", "BOOL_VALUE", "FALSE", "TRUE", "ASSIGN",
  "GT", "LT", "EQ", "NEQ", "EGT", "ELT", "AND", "OR", "ADD", "SUB", "MUL",
  "DIV", "POW", "$accept", "program", "global", "decl_list", "global_item",
  "main_block", "function", "function_list", "function_impl", "id",
  "variable_decl", "array_decl", "size", "protoType", "parameter_decl",
  "parameters", "parameter", "type", "value", "function_body", "stmt_list",
  "stmt", "assignment", "func_call", "parameterExprs", "variables", "loop",
  "for_loop", "while_loop", "condition", "expression", "expr_return",
  "relation_expr", "relation_op", "logic_expr", "logic_term", "logic_op",
  "arith_expr", "term", "left_id", "factor", YY_NULLPTR
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
     295,   296,   297,   298
};
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -121,    13,     5,    56,  -121,    44,  -121,  -121,  -121,  -121,
    -121,  -121,    22,  -121,  -121,  -121,    40,    62,  -121,    56,
    -121,  -121,     2,    65,  -121,    65,    40,    93,    37,    85,
    -121,  -121,  -121,    96,   102,    56,  -121,  -121,    99,   100,
    -121,  -121,  -121,  -121,  -121,    15,  -121,  -121,  -121,  -121,
     -15,  -121,    20,    24,  -121,  -121,   118,  -121,  -121,  -121,
     108,    40,  -121,   100,   109,    -1,   110,    85,  -121,  -121,
     112,  -121,  -121,  -121,  -121,  -121,   100,   100,   100,   100,
     100,   100,  -121,    45,   115,   117,   119,  -121,  -121,   124,
    -121,  -121,  -121,  -121,  -121,  -121,   126,   105,  -121,     6,
       3,  -121,  -121,   131,    85,   134,   100,  -121,    24,    24,
      43,  -121,  -121,  -121,  -121,   142,    40,    85,   100,  -121,
    -121,    85,  -121,   143,  -121,    20,  -121,   137,   148,   146,
     155,  -121,  -121,   100,   147,   156,   159,  -121,  -121,    40,
     135,   152,   158,  -121,   153,   161,   164,  -121,  -121,   169,
     186,  -121,  -121
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
      36,    32,    33,    34,    35,    83,    86,    87,    16,    59,
      60,    72,    58,    78,    88,    82,    64,    20,    25,    26,
      21,     0,    17,     0,     0,     0,    51,     0,    74,    75,
       0,    67,    66,    70,    69,    68,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,    44,    45,     0,
      42,    43,    39,    52,    53,    40,     0,     0,    23,    15,
       0,    73,    85,     0,     0,     0,     0,    71,    76,    77,
      65,    80,    81,    79,    62,     0,     0,     0,     0,    38,
      37,     0,    47,    48,    84,     0,    61,    83,     0,     0,
       0,    46,    50,     0,     0,     0,     0,    41,    41,     0,
       0,     0,     0,    55,    56,     0,     0,    41,    41,     0,
       0,    54,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   -16,
       9,    11,  -121,   160,  -121,  -121,  -121,    18,  -121,   163,
    -120,  -121,  -110,   -52,  -121,  -121,  -121,  -121,  -121,  -121,
     -64,  -121,   -31,  -121,  -121,   111,  -121,   -37,    30,   -55,
      12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     3,    12,     6,    18,    19,    24,    45,
      87,    88,    38,    15,    34,    35,    60,    61,    46,    31,
      56,    89,    90,    47,   103,   104,    92,    93,    94,    95,
      48,    96,    49,    78,    50,    51,    70,    52,    53,    54,
      55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    97,    65,   105,    91,   102,   128,    27,    64,   102,
      33,    28,    13,     4,    14,    28,     5,   140,   141,   115,
      66,    16,    68,    69,    67,    20,   100,   149,   150,   142,
      71,    72,    29,    73,    74,    75,    29,    26,    76,    77,
     123,   110,    76,    77,    58,    99,    59,    36,   114,    17,
      39,    71,    72,   129,    73,    74,    75,   131,    21,    76,
      77,    97,    37,    21,    40,    79,    80,    81,    23,   125,
      41,    42,    30,    43,    44,    64,     7,     8,     9,    10,
      11,   125,    76,    77,    97,    97,    97,   130,    91,    91,
      39,   111,   112,   113,    97,    97,   125,    91,    91,   -22,
     127,    27,   136,    21,    40,    63,   108,   109,    57,    62,
      41,    42,    98,    43,    44,   101,   -49,   106,    21,    40,
     116,    82,   117,   127,   118,    41,    42,   119,    43,    44,
      83,    84,    85,    86,   120,   121,    21,   122,     7,     8,
       9,    10,    11,   143,   124,   126,    67,   132,    84,    85,
      86,   133,   134,    21,   137,     7,     8,     9,    10,    11,
     144,   135,   139,   138,   145,    84,    85,    86,   147,   146,
      21,   148,     7,     8,     9,    10,    11,   151,     0,    25,
       0,   107,    84,    85,    86,     0,     0,    21,    32,     7,
       8,     9,    10,    11,   152,     0,     0,     0,     0,    84,
      85,    86,     0,     0,    21,     0,     7,     8,     9,    10,
      11
};

static const yytype_int16 yycheck[] =
{
      16,    56,    39,    67,    56,     6,   116,     5,    39,     6,
      26,     9,     3,     0,     3,     9,    11,   137,   138,    83,
       5,     3,    37,    38,     9,     3,    63,   147,   148,   139,
      31,    32,    30,    34,    35,    36,    30,    19,    39,    40,
     104,    78,    39,    40,    35,    61,    35,    10,     3,     5,
       5,    31,    32,   117,    34,    35,    36,   121,    18,    39,
      40,   116,    25,    18,    19,    41,    42,    43,     6,   106,
      25,    26,     7,    28,    29,   106,    20,    21,    22,    23,
      24,   118,    39,    40,   139,   140,   141,   118,   140,   141,
       5,    79,    80,    81,   149,   150,   133,   149,   150,     6,
     116,     5,   133,    18,    19,     5,    76,    77,     6,    10,
      25,    26,     4,    28,    29,     6,     6,     5,    18,    19,
       5,     3,     5,   139,     5,    25,    26,     3,    28,    29,
      12,    13,    14,    15,     8,    30,    18,     6,    20,    21,
      22,    23,    24,     8,    10,     3,     9,     4,    13,    14,
      15,     3,     6,    18,     7,    20,    21,    22,    23,    24,
       8,     6,     3,     7,     6,    13,    14,    15,     7,    16,
      18,     7,    20,    21,    22,    23,    24,     8,    -1,    19,
      -1,    70,    13,    14,    15,    -1,    -1,    18,    25,    20,
      21,    22,    23,    24,     8,    -1,    -1,    -1,    -1,    13,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    22,    23,
      24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,    47,     0,    11,    49,    20,    21,    22,
      23,    24,    48,    54,    55,    57,    61,     5,    50,    51,
       3,    18,    53,     6,    52,    57,    61,     5,     9,    30,
       7,    63,    63,    53,    58,    59,    10,    25,    56,     5,
      19,    25,    26,    28,    29,    53,    62,    67,    74,    76,
      78,    79,    81,    82,    83,    84,    64,     6,    54,    55,
      60,    61,    10,     5,    76,    81,     5,     9,    37,    38,
      80,    31,    32,    34,    35,    36,    39,    40,    77,    41,
      42,    43,     3,    12,    13,    14,    15,    54,    55,    65,
      66,    67,    70,    71,    72,    73,    75,    83,     4,    53,
      81,     6,     6,    68,    69,    74,     5,    79,    82,    82,
      81,    84,    84,    84,     3,    74,     5,     5,     5,     3,
       8,    30,     6,    74,    10,    81,     3,    53,    66,    74,
      76,    74,     4,     3,     6,     6,    76,     7,     7,     3,
      64,    64,    66,     8,     8,     6,    16,     7,     7,    64,
      64,     8,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    48,    49,
      50,    51,    51,    52,    53,    54,    54,    55,    55,    56,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    63,    64,    64,
      64,    64,    65,    65,    65,    65,    66,    67,    68,    68,
      69,    69,    70,    70,    71,    72,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    76,    77,    77,    77,    77,
      77,    78,    78,    79,    80,    80,    81,    81,    81,    82,
      82,    82,    82,    83,    83,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     3,     0,     1,     1,     1,     4,
       1,     2,     0,     2,     1,     2,     4,     5,     4,     1,
       5,     2,     0,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     2,
       2,     0,     1,     1,     1,     1,     3,     4,     2,     0,
       3,     0,     1,     1,    11,     7,     7,    11,     1,     1,
       1,     3,     2,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     4,     3,     1,     1,     1
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
#line 1277 "parser.cpp"
    break;

  case 3: /* global: decl_list  */
#line 69 "yacc.ypp"
                  {(yyval.block) = new GlobalPart((yyvsp[0].declList));}
#line 1283 "parser.cpp"
    break;

  case 4: /* decl_list: decl_list global_item SEMICOLON  */
#line 72 "yacc.ypp"
                                           {(yyval.declList)->addDecl((yyvsp[-1].decl)); (yyval.declList) = (yyvsp[-2].declList);}
#line 1289 "parser.cpp"
    break;

  case 5: /* decl_list: %empty  */
#line 73 "yacc.ypp"
                          {(yyval.declList) = new DeclList();}
#line 1295 "parser.cpp"
    break;

  case 6: /* global_item: variable_decl  */
#line 76 "yacc.ypp"
                           {(yyval.decl) = (yyvsp[0].decl);}
#line 1301 "parser.cpp"
    break;

  case 7: /* global_item: protoType  */
#line 77 "yacc.ypp"
                                  {(yyval.decl) = (yyvsp[0].decl);}
#line 1307 "parser.cpp"
    break;

  case 8: /* global_item: array_decl  */
#line 78 "yacc.ypp"
                               {(yyval.decl) = (yyvsp[0].decl);}
#line 1313 "parser.cpp"
    break;

  case 9: /* main_block: MAIN LEFTP RIGHTP function_body  */
#line 81 "yacc.ypp"
                                            {(yyval.block) = new MainPart((yyvsp[0].funcbody));}
#line 1319 "parser.cpp"
    break;

  case 10: /* function: function_list  */
#line 83 "yacc.ypp"
                        {(yyval.block) = new FuncPart((yyvsp[0].funcList));}
#line 1325 "parser.cpp"
    break;

  case 11: /* function_list: function_list function_impl  */
#line 86 "yacc.ypp"
                                           {(yyvsp[-1].funcList)->addFunction((yyvsp[0].funcImpl)); (yyval.funcList) = (yyvsp[-1].funcList);}
#line 1331 "parser.cpp"
    break;

  case 12: /* function_list: %empty  */
#line 87 "yacc.ypp"
                  {(yyval.funcList) = new FuncList();}
#line 1337 "parser.cpp"
    break;

  case 13: /* function_impl: protoType function_body  */
#line 90 "yacc.ypp"
                                       {(yyval.funcImpl) = new FuncImpl((yyvsp[-1].decl),(yyvsp[0].funcbody));}
#line 1343 "parser.cpp"
    break;

  case 14: /* id: IDENTIFIER  */
#line 93 "yacc.ypp"
               {(yyval.expr) = new Identifier(*(yyvsp[0].Str));}
#line 1349 "parser.cpp"
    break;

  case 15: /* variable_decl: type id  */
#line 96 "yacc.ypp"
                        {(yyval.decl) = new VariableDecl((yyvsp[-1].dataType),(yyvsp[0].expr));}
#line 1355 "parser.cpp"
    break;

  case 16: /* variable_decl: type id ASSIGN expression  */
#line 97 "yacc.ypp"
                                            {(yyval.decl) = new VariableDecl((yyvsp[-3].dataType),(yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1361 "parser.cpp"
    break;

  case 17: /* array_decl: type id LEFTSB size RIGHTSB  */
#line 100 "yacc.ypp"
                                        {(yyval.decl) = new ArrayDecl((yyvsp[-4].dataType),(yyvsp[-3].expr),(yyvsp[-1].intval));}
#line 1367 "parser.cpp"
    break;

  case 18: /* array_decl: type id LEFTSB RIGHTSB  */
#line 101 "yacc.ypp"
                                    {(yyval.decl) = new ArrayDecl((yyvsp[-3].dataType),(yyvsp[-2].expr));}
#line 1373 "parser.cpp"
    break;

  case 19: /* size: INTEGER_VALUE  */
#line 102 "yacc.ypp"
                    {(yyval.intval) = atoi((yyvsp[0].valueStr));}
#line 1379 "parser.cpp"
    break;

  case 20: /* protoType: type id LEFTP parameter_decl RIGHTP  */
#line 104 "yacc.ypp"
                                               {(yyval.decl) = new ProtoType((yyvsp[-4].dataType),(yyvsp[-3].expr),(yyvsp[-1].declList));}
#line 1385 "parser.cpp"
    break;

  case 21: /* parameter_decl: parameters parameter  */
#line 107 "yacc.ypp"
                                     {(yyvsp[-1].declList)->addDecl((yyvsp[0].decl)); (yyval.declList) = (yyvsp[-1].declList);}
#line 1391 "parser.cpp"
    break;

  case 22: /* parameter_decl: %empty  */
#line 108 "yacc.ypp"
                  {(yyval.declList) = new DeclList();}
#line 1397 "parser.cpp"
    break;

  case 23: /* parameters: parameters parameter COMMA  */
#line 111 "yacc.ypp"
                                       {(yyvsp[-2].declList)->addDecl((yyvsp[-1].decl)); (yyval.declList) = (yyvsp[-2].declList);}
#line 1403 "parser.cpp"
    break;

  case 24: /* parameters: %empty  */
#line 112 "yacc.ypp"
                  {(yyval.declList) = new DeclList();}
#line 1409 "parser.cpp"
    break;

  case 25: /* parameter: variable_decl  */
#line 115 "yacc.ypp"
                         {(yyval.decl) = (yyvsp[0].decl);}
#line 1415 "parser.cpp"
    break;

  case 26: /* parameter: array_decl  */
#line 116 "yacc.ypp"
                     {(yyval.decl) = (yyvsp[0].decl);}
#line 1421 "parser.cpp"
    break;

  case 27: /* type: INT  */
#line 118 "yacc.ypp"
          {(yyval.dataType) = VALUEINT;}
#line 1427 "parser.cpp"
    break;

  case 28: /* type: FLOAT  */
#line 119 "yacc.ypp"
                {(yyval.dataType) = VALUEFLOAT;}
#line 1433 "parser.cpp"
    break;

  case 29: /* type: BOOL  */
#line 120 "yacc.ypp"
               {(yyval.dataType) = VALUEBOOL;}
#line 1439 "parser.cpp"
    break;

  case 30: /* type: VOID  */
#line 121 "yacc.ypp"
               {(yyval.dataType) = VALUEVOID;}
#line 1445 "parser.cpp"
    break;

  case 31: /* type: STRING  */
#line 122 "yacc.ypp"
                 {(yyval.dataType) = VALUESTRING;}
#line 1451 "parser.cpp"
    break;

  case 32: /* value: INTEGER_VALUE  */
#line 125 "yacc.ypp"
                     {(yyval.expr) = new Integer(atoi((yyvsp[0].valueStr)));}
#line 1457 "parser.cpp"
    break;

  case 33: /* value: FLOAT_VALUE  */
#line 126 "yacc.ypp"
                      {(yyval.expr) = new Float(atof((yyvsp[0].valueStr)));}
#line 1463 "parser.cpp"
    break;

  case 34: /* value: FALSE  */
#line 127 "yacc.ypp"
                {(yyval.expr) = new Bool(false);}
#line 1469 "parser.cpp"
    break;

  case 35: /* value: TRUE  */
#line 128 "yacc.ypp"
               {(yyval.expr) = new Bool(true);}
#line 1475 "parser.cpp"
    break;

  case 36: /* value: STRING_VALUE  */
#line 129 "yacc.ypp"
                       {(yyval.expr) = new String(*(yyvsp[0].Str));}
#line 1481 "parser.cpp"
    break;

  case 37: /* function_body: LEFTB stmt_list expr_return RIGHTB  */
#line 132 "yacc.ypp"
                                                   {(yyval.funcbody) = new FuncBody((yyvsp[-2].stmtList),(yyvsp[-1].expr));}
#line 1487 "parser.cpp"
    break;

  case 38: /* stmt_list: stmt_list stmt SEMICOLON  */
#line 135 "yacc.ypp"
                                    {(yyvsp[-2].stmtList)->addStmt((yyvsp[-1].stmt)); (yyval.stmtList) = (yyvsp[-2].stmtList);}
#line 1493 "parser.cpp"
    break;

  case 39: /* stmt_list: stmt_list loop  */
#line 136 "yacc.ypp"
                         {(yyvsp[-1].stmtList)->addStmt((yyvsp[0].stmt)); (yyval.stmtList) = (yyvsp[-1].stmtList);}
#line 1499 "parser.cpp"
    break;

  case 40: /* stmt_list: stmt_list condition  */
#line 137 "yacc.ypp"
                              {(yyvsp[-1].stmtList)->addStmt((yyvsp[0].stmt)); (yyval.stmtList) = (yyvsp[-1].stmtList);}
#line 1505 "parser.cpp"
    break;

  case 41: /* stmt_list: %empty  */
#line 138 "yacc.ypp"
                  {(yyval.stmtList) = new StmtList();}
#line 1511 "parser.cpp"
    break;

  case 42: /* stmt: assignment  */
#line 141 "yacc.ypp"
                 {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1517 "parser.cpp"
    break;

  case 43: /* stmt: func_call  */
#line 142 "yacc.ypp"
                    {(yyval.stmt) = (yyvsp[0].expr);}
#line 1523 "parser.cpp"
    break;

  case 44: /* stmt: variable_decl  */
#line 143 "yacc.ypp"
                        {(yyval.stmt) = (yyvsp[0].decl);}
#line 1529 "parser.cpp"
    break;

  case 45: /* stmt: array_decl  */
#line 144 "yacc.ypp"
                     {(yyval.stmt) = (yyvsp[0].decl);}
#line 1535 "parser.cpp"
    break;

  case 46: /* assignment: left_id ASSIGN expression  */
#line 147 "yacc.ypp"
                                      {(yyval.stmt) = new Assignment((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1541 "parser.cpp"
    break;

  case 47: /* func_call: id LEFTP parameterExprs RIGHTP  */
#line 150 "yacc.ypp"
                                          {(yyval.expr) = new FuncCall((yyvsp[-3].expr),(yyvsp[-1].exprList));}
#line 1547 "parser.cpp"
    break;

  case 48: /* parameterExprs: variables expression  */
#line 153 "yacc.ypp"
                                     {(yyvsp[-1].exprList)->addExpr((yyvsp[0].expr)); (yyval.exprList) = (yyvsp[-1].exprList);}
#line 1553 "parser.cpp"
    break;

  case 49: /* parameterExprs: %empty  */
#line 154 "yacc.ypp"
                  {(yyval.exprList) = new ExprList();}
#line 1559 "parser.cpp"
    break;

  case 50: /* variables: variables expression COMMA  */
#line 157 "yacc.ypp"
                                      {(yyvsp[-2].exprList)->addExpr((yyvsp[-1].expr)); (yyval.exprList) = (yyvsp[-2].exprList);}
#line 1565 "parser.cpp"
    break;

  case 51: /* variables: %empty  */
#line 158 "yacc.ypp"
                  {(yyval.exprList) = new ExprList();}
#line 1571 "parser.cpp"
    break;

  case 52: /* loop: for_loop  */
#line 161 "yacc.ypp"
                {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1577 "parser.cpp"
    break;

  case 53: /* loop: while_loop  */
#line 162 "yacc.ypp"
                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1583 "parser.cpp"
    break;

  case 54: /* for_loop: FOR LEFTP assignment SEMICOLON relation_expr SEMICOLON assignment RIGHTP LEFTB stmt_list RIGHTB  */
#line 164 "yacc.ypp"
                                                                                                           {
	(yyval.stmt) = new ForLoop((yyvsp[-8].stmt),(yyvsp[-6].expr),(yyvsp[-4].stmt),(yyvsp[-1].stmtList));
}
#line 1591 "parser.cpp"
    break;

  case 55: /* while_loop: WHILE LEFTP expression RIGHTP LEFTB stmt_list RIGHTB  */
#line 168 "yacc.ypp"
                                                                  {
	(yyval.stmt) = new WhileLoop((yyvsp[-4].expr),(yyvsp[-1].stmtList));
}
#line 1599 "parser.cpp"
    break;

  case 56: /* condition: IF LEFTP relation_expr RIGHTP LEFTB stmt_list RIGHTB  */
#line 172 "yacc.ypp"
                                                                {(yyval.stmt) =new Condition((yyvsp[-4].expr),(yyvsp[-1].stmtList));}
#line 1605 "parser.cpp"
    break;

  case 57: /* condition: IF LEFTP relation_expr RIGHTP LEFTB stmt_list RIGHTB ELSE LEFTB stmt_list RIGHTB  */
#line 173 "yacc.ypp"
                                                                                           {(yyval.stmt) = new ConditionOtherwise((yyvsp[-8].expr),(yyvsp[-5].stmtList),(yyvsp[-1].stmtList));}
#line 1611 "parser.cpp"
    break;

  case 58: /* expression: arith_expr  */
#line 176 "yacc.ypp"
                       {(yyval.expr) = (yyvsp[0].expr);}
#line 1617 "parser.cpp"
    break;

  case 59: /* expression: relation_expr  */
#line 177 "yacc.ypp"
                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1623 "parser.cpp"
    break;

  case 60: /* expression: logic_expr  */
#line 178 "yacc.ypp"
                         {(yyval.expr) = (yyvsp[0].expr);}
#line 1629 "parser.cpp"
    break;

  case 61: /* expr_return: RETURN expression SEMICOLON  */
#line 181 "yacc.ypp"
                                         {(yyval.expr) = (yyvsp[-1].expr);}
#line 1635 "parser.cpp"
    break;

  case 62: /* expr_return: RETURN SEMICOLON  */
#line 182 "yacc.ypp"
                                   {(yyval.expr) = new Void();}
#line 1641 "parser.cpp"
    break;

  case 63: /* expr_return: SEMICOLON  */
#line 183 "yacc.ypp"
                            {(yyval.expr) = new Void();}
#line 1647 "parser.cpp"
    break;

  case 64: /* expr_return: %empty  */
#line 184 "yacc.ypp"
                  {(yyval.expr) = new Void();}
#line 1653 "parser.cpp"
    break;

  case 65: /* relation_expr: arith_expr relation_op arith_expr  */
#line 187 "yacc.ypp"
                                                 {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].intval));}
#line 1659 "parser.cpp"
    break;

  case 66: /* relation_op: LT  */
#line 189 "yacc.ypp"
                {(yyval.intval) = OPLT;}
#line 1665 "parser.cpp"
    break;

  case 67: /* relation_op: GT  */
#line 190 "yacc.ypp"
                 {(yyval.intval) = OPGT;}
#line 1671 "parser.cpp"
    break;

  case 68: /* relation_op: ELT  */
#line 191 "yacc.ypp"
                  {(yyval.intval) = OPELT;}
#line 1677 "parser.cpp"
    break;

  case 69: /* relation_op: EGT  */
#line 192 "yacc.ypp"
                  {(yyval.intval) = OPEGT;}
#line 1683 "parser.cpp"
    break;

  case 70: /* relation_op: NEQ  */
#line 193 "yacc.ypp"
                  {(yyval.intval) = NEQ;}
#line 1689 "parser.cpp"
    break;

  case 71: /* logic_expr: logic_expr logic_op logic_term  */
#line 195 "yacc.ypp"
                                          {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].intval));}
#line 1695 "parser.cpp"
    break;

  case 72: /* logic_expr: logic_term  */
#line 196 "yacc.ypp"
                         {(yyval.expr) = (yyvsp[0].expr);}
#line 1701 "parser.cpp"
    break;

  case 73: /* logic_term: LEFTP relation_expr RIGHTP  */
#line 199 "yacc.ypp"
                                       {(yyval.expr) = (yyvsp[-1].expr);}
#line 1707 "parser.cpp"
    break;

  case 74: /* logic_op: AND  */
#line 201 "yacc.ypp"
              {(yyval.intval) = OPAND;}
#line 1713 "parser.cpp"
    break;

  case 75: /* logic_op: OR  */
#line 202 "yacc.ypp"
                 {(yyval.intval) = OPOR;}
#line 1719 "parser.cpp"
    break;

  case 76: /* arith_expr: arith_expr ADD term  */
#line 204 "yacc.ypp"
                                {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPADD);}
#line 1725 "parser.cpp"
    break;

  case 77: /* arith_expr: arith_expr SUB term  */
#line 205 "yacc.ypp"
                              {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPSUB);}
#line 1731 "parser.cpp"
    break;

  case 78: /* arith_expr: term  */
#line 206 "yacc.ypp"
               {(yyval.expr) = (yyvsp[0].expr);}
#line 1737 "parser.cpp"
    break;

  case 79: /* term: term POW factor  */
#line 209 "yacc.ypp"
                      {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPPOW); }
#line 1743 "parser.cpp"
    break;

  case 80: /* term: term MUL factor  */
#line 210 "yacc.ypp"
                          {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPMUL); }
#line 1749 "parser.cpp"
    break;

  case 81: /* term: term DIV factor  */
#line 211 "yacc.ypp"
                          {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPDIV); }
#line 1755 "parser.cpp"
    break;

  case 82: /* term: factor  */
#line 212 "yacc.ypp"
                 {(yyval.expr) = (yyvsp[0].expr); }
#line 1761 "parser.cpp"
    break;

  case 83: /* left_id: id  */
#line 215 "yacc.ypp"
            {(yyval.expr) = (yyvsp[0].expr);}
#line 1767 "parser.cpp"
    break;

  case 84: /* left_id: id LEFTSB expression RIGHTSB  */
#line 216 "yacc.ypp"
                                       {(yyval.expr) = new ArrayExpr((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1773 "parser.cpp"
    break;

  case 85: /* factor: LEFTP arith_expr RIGHTP  */
#line 218 "yacc.ypp"
                                {(yyval.expr) = (yyvsp[-1].expr); }
#line 1779 "parser.cpp"
    break;

  case 86: /* factor: value  */
#line 219 "yacc.ypp"
                {(yyval.expr) = (yyvsp[0].expr);}
#line 1785 "parser.cpp"
    break;

  case 87: /* factor: func_call  */
#line 220 "yacc.ypp"
                    {(yyval.expr) = (yyvsp[0].expr);}
#line 1791 "parser.cpp"
    break;

  case 88: /* factor: left_id  */
#line 221 "yacc.ypp"
                  {(yyval.expr) = (yyvsp[0].expr);}
#line 1797 "parser.cpp"
    break;


#line 1801 "parser.cpp"

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

#line 224 "yacc.ypp"


int yyerror(const char *s){
	cout<<s<<endl;
	return 0;
}

/*
array_decl: type id LEFTSB size RIGHTSB {$$ = new ArrayDecl($1,$2,$4);}
size: INTEGER_VALUE {$$ = atoi($1);}
*/

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
#line 1 "yacc.y"

#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

AST* program; // total program

extern int yyparse();
extern int yylex();
int yyerror(const char* s);
int yywrap();

#line 88 "parser.cpp"

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

#include "parser.hpp"
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
  YYSYMBOL_MAIN = 9,                       /* MAIN  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_IDENTIFIER = 15,                /* IDENTIFIER  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_FLOAT = 17,                     /* FLOAT  */
  YYSYMBOL_BOOL = 18,                      /* BOOL  */
  YYSYMBOL_INTEGER_VALUE = 19,             /* INTEGER_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 20,               /* FLOAT_VALUE  */
  YYSYMBOL_BOOL_VALUE = 21,                /* BOOL_VALUE  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NEQ = 26,                       /* NEQ  */
  YYSYMBOL_ADD = 27,                       /* ADD  */
  YYSYMBOL_SUB = 28,                       /* SUB  */
  YYSYMBOL_MUL = 29,                       /* MUL  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_POW = 31,                       /* POW  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_global = 34,                    /* global  */
  YYSYMBOL_decl_list = 35,                 /* decl_list  */
  YYSYMBOL_main_block = 36,                /* main_block  */
  YYSYMBOL_function = 37,                  /* function  */
  YYSYMBOL_function_list = 38,             /* function_list  */
  YYSYMBOL_function_impl = 39,             /* function_impl  */
  YYSYMBOL_global_item = 40,               /* global_item  */
  YYSYMBOL_variable_decl = 41,             /* variable_decl  */
  YYSYMBOL_protoType = 42,                 /* protoType  */
  YYSYMBOL_parameter_decl = 43,            /* parameter_decl  */
  YYSYMBOL_parameters = 44,                /* parameters  */
  YYSYMBOL_type = 45,                      /* type  */
  YYSYMBOL_value = 46,                     /* value  */
  YYSYMBOL_function_body = 47,             /* function_body  */
  YYSYMBOL_stmt_return = 48,               /* stmt_return  */
  YYSYMBOL_stmt_list = 49,                 /* stmt_list  */
  YYSYMBOL_stmt = 50,                      /* stmt  */
  YYSYMBOL_assignment = 51,                /* assignment  */
  YYSYMBOL_func_call = 52,                 /* func_call  */
  YYSYMBOL_parameterIDs = 53,              /* parameterIDs  */
  YYSYMBOL_variables = 54,                 /* variables  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_factor = 57                     /* factor  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   68

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  76

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    71,    74,    75,    78,    80,    82,    83,
      86,    89,    90,    93,    94,    97,   100,   101,   104,   105,
     108,   109,   110,   113,   114,   117,   120,   121,   122,   123,
     126,   127,   130,   131,   134,   137,   140,   141,   144,   145,
     148,   149,   150,   153,   154,   155,   156,   159,   160,   161
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
  "LEFTP", "RIGHTP", "LEFTB", "RIGHTB", "MAIN", "RETURN", "FOR", "WHILE",
  "IF", "ELSE", "IDENTIFIER", "INT", "FLOAT", "BOOL", "INTEGER_VALUE",
  "FLOAT_VALUE", "BOOL_VALUE", "ASSIGN", "GT", "LT", "EQ", "NEQ", "ADD",
  "SUB", "MUL", "DIV", "POW", "$accept", "program", "global", "decl_list",
  "main_block", "function", "function_list", "function_impl",
  "global_item", "variable_decl", "protoType", "parameter_decl",
  "parameters", "type", "value", "function_body", "stmt_return",
  "stmt_list", "stmt", "assignment", "func_call", "parameterIDs",
  "variables", "expression", "term", "factor", YY_NULLPTR
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
     285,   286
};
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -34,     3,    -3,    -8,   -34,    21,   -34,   -34,   -34,   -34,
      25,   -34,   -34,    27,    37,   -34,    -8,   -34,    12,    38,
     -34,    38,    29,    40,   -34,   -34,   -34,   -34,   -34,   -34,
      42,    43,    -8,     1,   -34,    44,    35,   -34,    -1,     2,
      45,    48,   -34,   -34,   -34,    17,   -34,    49,    39,    10,
     -34,   -34,   -34,    50,    46,    10,   -34,   -34,    11,   -17,
     -34,   -34,    51,    -5,    10,    10,    10,    10,    10,   -34,
     -34,   -17,   -17,   -34,   -34,   -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     3,     1,     0,     9,    20,    21,    22,
       0,    11,    12,     0,     0,     2,     7,     4,    13,     0,
       8,     0,     0,    19,    23,    24,    14,    31,     6,    10,
       0,     0,     0,    29,    15,    16,     0,    28,     0,     0,
       0,     0,    32,    33,    18,    13,    27,     0,    37,     0,
      25,    30,    26,     0,     0,     0,    49,    48,    34,    42,
      46,    35,    36,     0,     0,     0,     0,     0,     0,    38,
      47,    40,    41,    44,    45,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,    26,
      41,   -34,   -34,   -11,   -18,    47,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,     4,   -24,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     3,     6,    15,    16,    20,    10,    11,
      12,    31,    32,    13,    57,    28,    40,    33,    41,    42,
      43,    53,    54,    58,    59,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    70,    46,     4,    37,    22,     5,    48,     7,     8,
       9,    38,    66,    67,    68,    55,    39,    23,    24,    25,
      47,    36,    64,    65,    49,    56,    14,    26,    17,    24,
      25,    24,    25,    73,    74,    75,    24,    25,    64,    65,
      71,    72,    18,    19,    30,    27,   -17,    23,    44,    34,
      45,    51,    52,    50,   -39,    69,    61,    21,    35,    63,
       0,    62,     0,     0,     0,     0,     0,     0,    29
};

static const yytype_int8 yycheck[] =
{
      18,     6,     3,     0,     3,    16,     9,     5,    16,    17,
      18,    10,    29,    30,    31,     5,    15,     5,    19,    20,
      38,    32,    27,    28,    22,    15,     5,    45,     3,    19,
      20,    19,    20,    66,    67,    68,    19,    20,    27,    28,
      64,    65,    15,     6,    15,     7,     6,     5,     4,     6,
      15,     3,     3,     8,    15,     4,     6,    16,    32,    55,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,    35,     0,     9,    36,    16,    17,    18,
      40,    41,    42,    45,     5,    37,    38,     3,    15,     6,
      39,    42,    45,     5,    19,    20,    46,     7,    47,    47,
      15,    43,    44,    49,     6,    41,    45,     3,    10,    15,
      48,    50,    51,    52,     4,    15,     3,    46,     5,    22,
       8,     3,     3,    53,    54,     5,    15,    46,    55,    56,
      57,     6,    15,    55,    27,    28,    29,    30,    31,     4,
       6,    56,    56,    57,    57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    35,    35,    36,    37,    38,    38,
      39,    40,    40,    41,    41,    42,    43,    43,    44,    44,
      45,    45,    45,    46,    46,    47,    48,    48,    48,    48,
      49,    49,    50,    50,    51,    52,    53,    53,    54,    54,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     3,     0,     4,     1,     2,     0,
       2,     1,     1,     2,     3,     5,     2,     0,     3,     0,
       1,     1,     1,     1,     1,     4,     3,     2,     1,     0,
       3,     0,     1,     1,     3,     4,     2,     0,     3,     0,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     1
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
  case 2: /* program: global main_block function  */
#line 68 "yacc.y"
                                    {program = new AST((yyvsp[-2].block),(yyvsp[-1].block),(yyvsp[0].block));}
#line 1176 "parser.cpp"
    break;

  case 3: /* global: decl_list  */
#line 71 "yacc.y"
                   {(yyval.block) = new GlobalPart((yyvsp[0].declList));}
#line 1182 "parser.cpp"
    break;

  case 4: /* decl_list: decl_list global_item SEMICOLON  */
#line 74 "yacc.y"
                                           {(yyval.declList)->addDecl((yyvsp[-1].declaration)); (yyval.declList) = (yyvsp[-2].declList);}
#line 1188 "parser.cpp"
    break;

  case 5: /* decl_list: %empty  */
#line 75 "yacc.y"
                          {(yyval.declList) = new DeclList();}
#line 1194 "parser.cpp"
    break;

  case 6: /* main_block: MAIN LEFTP RIGHTP function_body  */
#line 78 "yacc.y"
                                            {(yyval.block) = new MainPart((yyvsp[0].funcbody));}
#line 1200 "parser.cpp"
    break;

  case 7: /* function: function_list  */
#line 80 "yacc.y"
                        {(yyval.block) = new FuncPart((yyvsp[0].funcList));}
#line 1206 "parser.cpp"
    break;

  case 8: /* function_list: function_list function_impl  */
#line 82 "yacc.y"
                                           {(yyvsp[-1].funcList)->addFunction((yyvsp[0].funcImpl)); (yyval.funcList) = (yyvsp[-1].funcList);}
#line 1212 "parser.cpp"
    break;

  case 9: /* function_list: %empty  */
#line 83 "yacc.y"
                  {(yyval.funcList) = new FuncList();}
#line 1218 "parser.cpp"
    break;

  case 10: /* function_impl: protoType function_body  */
#line 86 "yacc.y"
                                       {(yyval.funcImpl) = new FuncImpl((yyvsp[-1].declaration),(yyvsp[0].funcbody));}
#line 1224 "parser.cpp"
    break;

  case 11: /* global_item: variable_decl  */
#line 89 "yacc.y"
                           {(yyval.declaration) = (yyvsp[0].declaration);}
#line 1230 "parser.cpp"
    break;

  case 12: /* global_item: protoType  */
#line 90 "yacc.y"
                                  {(yyval.declaration) = (yyvsp[0].declaration);}
#line 1236 "parser.cpp"
    break;

  case 13: /* variable_decl: type IDENTIFIER  */
#line 93 "yacc.y"
                                {(yyval.declaration) = new VariableDecl((yyvsp[-1].dataType),(yyvsp[0].expr));}
#line 1242 "parser.cpp"
    break;

  case 14: /* variable_decl: type IDENTIFIER value  */
#line 94 "yacc.y"
                                        {(yyval.declaration) = new VariableDecl((yyvsp[-2].dataType),(yyvsp[-1].expr),(yyvsp[0].expr));}
#line 1248 "parser.cpp"
    break;

  case 15: /* protoType: type IDENTIFIER LEFTP parameter_decl RIGHTP  */
#line 97 "yacc.y"
                                                       {(yyval.declaration) = new ProtoType((yyvsp[-4].dataType),(yyvsp[-3].expr),(yyvsp[-1].paramList));}
#line 1254 "parser.cpp"
    break;

  case 16: /* parameter_decl: parameters variable_decl  */
#line 100 "yacc.y"
                                         {(yyval.paramList) = new ParamsList(*(yyvsp[-1].declVector)); (yyval.paramList)->addParam((yyvsp[0].declaration));}
#line 1260 "parser.cpp"
    break;

  case 17: /* parameter_decl: %empty  */
#line 101 "yacc.y"
                  {(yyval.paramList) = new ParamsList();}
#line 1266 "parser.cpp"
    break;

  case 18: /* parameters: parameters variable_decl COMMA  */
#line 104 "yacc.y"
                                           {(yyvsp[-2].declVector)->push_back((yyvsp[-1].declaration)); (yyval.declVector) = (yyvsp[-2].declVector);}
#line 1272 "parser.cpp"
    break;

  case 19: /* parameters: %empty  */
#line 105 "yacc.y"
                  {(yyval.declVector) = new vector<Decl*>();}
#line 1278 "parser.cpp"
    break;

  case 20: /* type: INT  */
#line 108 "yacc.y"
          {(yyval.dataType) = new DataType((yyvsp[0].txt));}
#line 1284 "parser.cpp"
    break;

  case 21: /* type: FLOAT  */
#line 109 "yacc.y"
                {(yyval.dataType) = new DataType((yyvsp[0].txt));}
#line 1290 "parser.cpp"
    break;

  case 22: /* type: BOOL  */
#line 110 "yacc.y"
               {(yyval.dataType) = new DataType((yyvsp[0].txt));}
#line 1296 "parser.cpp"
    break;

  case 23: /* value: INTEGER_VALUE  */
#line 113 "yacc.y"
                     {(yyval.expr) = new Integer(atoi((yyvsp[0].txt)));}
#line 1302 "parser.cpp"
    break;

  case 24: /* value: FLOAT_VALUE  */
#line 114 "yacc.y"
                      {(yyval.expr) = new Float(atof((yyvsp[0].txt)));}
#line 1308 "parser.cpp"
    break;

  case 25: /* function_body: LEFTB stmt_list stmt_return RIGHTB  */
#line 117 "yacc.y"
                                                   {(yyval.funcbody) = new FuncBody((yyvsp[-2].stmtList),(yyvsp[-1].stmt));}
#line 1314 "parser.cpp"
    break;

  case 26: /* stmt_return: RETURN value SEMICOLON  */
#line 120 "yacc.y"
                                    {(yyval.stmt) = (yyvsp[-1].expr);}
#line 1320 "parser.cpp"
    break;

  case 27: /* stmt_return: RETURN SEMICOLON  */
#line 121 "yacc.y"
                                   {(yyval.stmt) = new Void();}
#line 1326 "parser.cpp"
    break;

  case 28: /* stmt_return: SEMICOLON  */
#line 122 "yacc.y"
                            {(yyval.stmt) = new Void();}
#line 1332 "parser.cpp"
    break;

  case 29: /* stmt_return: %empty  */
#line 123 "yacc.y"
                  {(yyval.stmt) = new Void();}
#line 1338 "parser.cpp"
    break;

  case 30: /* stmt_list: stmt_list stmt SEMICOLON  */
#line 126 "yacc.y"
                                    {(yyvsp[-2].stmtList)->addStmt((yyvsp[-1].stmt)); (yyval.stmtList) = (yyvsp[-2].stmtList);}
#line 1344 "parser.cpp"
    break;

  case 31: /* stmt_list: %empty  */
#line 127 "yacc.y"
                  {(yyval.stmtList) = new StmtList();}
#line 1350 "parser.cpp"
    break;

  case 32: /* stmt: assignment  */
#line 130 "yacc.y"
                 {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1356 "parser.cpp"
    break;

  case 33: /* stmt: func_call  */
#line 131 "yacc.y"
                    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1362 "parser.cpp"
    break;

  case 34: /* assignment: IDENTIFIER ASSIGN expression  */
#line 134 "yacc.y"
                                         {(yyval.stmt) = new Assignment((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1368 "parser.cpp"
    break;

  case 35: /* func_call: IDENTIFIER LEFTP parameterIDs RIGHTP  */
#line 137 "yacc.y"
                                                {(yyval.stmt) = new FuncCall((yyvsp[-3].expr),(yyvsp[-1].idList));}
#line 1374 "parser.cpp"
    break;

  case 36: /* parameterIDs: variables IDENTIFIER  */
#line 140 "yacc.y"
                                   {(yyvsp[-1].idList)->addIdentifier((yyvsp[0].expr)); (yyval.idList) = (yyvsp[-1].idList);}
#line 1380 "parser.cpp"
    break;

  case 37: /* parameterIDs: %empty  */
#line 141 "yacc.y"
                  {(yyval.idList) = new IdentifierList();}
#line 1386 "parser.cpp"
    break;

  case 38: /* variables: variables IDENTIFIER COMMA  */
#line 144 "yacc.y"
                                      {(yyvsp[-2].idList)->addIdentifier((yyvsp[-1].expr)); (yyval.idList) = (yyvsp[-2].idList);}
#line 1392 "parser.cpp"
    break;

  case 39: /* variables: %empty  */
#line 145 "yacc.y"
                  {(yyval.idList) = new IdentifierList();}
#line 1398 "parser.cpp"
    break;

  case 40: /* expression: expression ADD term  */
#line 148 "yacc.y"
                                {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPADD);}
#line 1404 "parser.cpp"
    break;

  case 41: /* expression: expression SUB term  */
#line 149 "yacc.y"
                              {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPSUB);}
#line 1410 "parser.cpp"
    break;

  case 42: /* expression: term  */
#line 150 "yacc.y"
               {(yyval.expr) = (yyvsp[0].expr);}
#line 1416 "parser.cpp"
    break;

  case 43: /* term: term POW factor  */
#line 153 "yacc.y"
                      {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPPOW); }
#line 1422 "parser.cpp"
    break;

  case 44: /* term: term MUL factor  */
#line 154 "yacc.y"
                          {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPMUL); }
#line 1428 "parser.cpp"
    break;

  case 45: /* term: term DIV factor  */
#line 155 "yacc.y"
                          {(yyval.expr) = new BinaryExpr((yyvsp[-2].expr),(yyvsp[0].expr),OPDIV); }
#line 1434 "parser.cpp"
    break;

  case 46: /* term: factor  */
#line 156 "yacc.y"
                 {(yyval.expr) = (yyvsp[0].expr); }
#line 1440 "parser.cpp"
    break;

  case 47: /* factor: LEFTP expression RIGHTP  */
#line 159 "yacc.y"
                                {(yyval.expr) = (yyvsp[-1].expr); }
#line 1446 "parser.cpp"
    break;

  case 48: /* factor: value  */
#line 160 "yacc.y"
                {(yyval.expr) = (yyvsp[0].expr);}
#line 1452 "parser.cpp"
    break;

  case 49: /* factor: IDENTIFIER  */
#line 161 "yacc.y"
                     {(yyval.expr) = (yyvsp[0].expr);}
#line 1458 "parser.cpp"
    break;


#line 1462 "parser.cpp"

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

#line 164 "yacc.y"


int yywrap(){
	return 1;
}

int yyerror(const char *s){
	cout<<s<<endl;
	return 0;
}

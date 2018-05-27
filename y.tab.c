/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "rule.y" /* yacc.c:339  */

	#include <stdio.h>
	#include "table.c"
	#include "interpreteur.c"
	
	#define YYDEBUG 0
	
	int yylex(void);
	void yyerror(char*);


char* type;

#line 80 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tINT = 258,
    tACO = 259,
    tACC = 260,
    tCONST = 261,
    tADD = 262,
    tSUBTRACT = 263,
    tDIVIDE = 264,
    tMULTIPLY = 265,
    tEQUAL = 266,
    tPLUSPLUS = 267,
    tMINUSMINUS = 268,
    tIF = 269,
    tELSE = 270,
    tCHECKEQ = 271,
    tPO = 272,
    tPC = 273,
    tTAB = 274,
    tVIRGULE = 275,
    tDOLLAR = 276,
    tFINSTR = 277,
    tINTNR = 278,
    tWHILE = 279,
    tPRINTF = 280,
    tMAIN = 281,
    tVAR = 282,
    tFOR = 283,
    tSTRING = 284,
    tCHECKHIGHER = 285,
    tLESS = 286,
    tLESSEQUAL = 287,
    tMOREEQUAL = 288,
    tMINUSEQUAL = 289,
    tPLUSEQUAL = 290,
    tRETURN = 291
  };
#endif
/* Tokens.  */
#define tINT 258
#define tACO 259
#define tACC 260
#define tCONST 261
#define tADD 262
#define tSUBTRACT 263
#define tDIVIDE 264
#define tMULTIPLY 265
#define tEQUAL 266
#define tPLUSPLUS 267
#define tMINUSMINUS 268
#define tIF 269
#define tELSE 270
#define tCHECKEQ 271
#define tPO 272
#define tPC 273
#define tTAB 274
#define tVIRGULE 275
#define tDOLLAR 276
#define tFINSTR 277
#define tINTNR 278
#define tWHILE 279
#define tPRINTF 280
#define tMAIN 281
#define tVAR 282
#define tFOR 283
#define tSTRING 284
#define tCHECKHIGHER 285
#define tLESS 286
#define tLESSEQUAL 287
#define tMOREEQUAL 288
#define tMINUSEQUAL 289
#define tPLUSEQUAL 290
#define tRETURN 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "rule.y" /* yacc.c:355  */

	int nb;
	char* str;

#line 197 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 214 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    70,    68,    76,    76,    87,    89,    89,
      90,    90,    91,    92,   101,   103,   104,   105,   106,   106,
     108,   124,   124,   126,   127,   128,   131,   132,   133,   134,
     135,   136,   138,   141,   142,   144,   145,   155,   156,   165,
     166,   169,   174,   174,   181,   174,   197,   199,   204,   215,
     224,   233,   242,   256,   260,   256,   279,   281,   284,   288,
     279,   308,   310,   312,   315,   308,   335,   335,   349,   356,
     365,   372,   379,   388,   400,   409,   418,   427,   436,   441,
     445,   449,   456,   462,   462
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINT", "tACO", "tACC", "tCONST", "tADD",
  "tSUBTRACT", "tDIVIDE", "tMULTIPLY", "tEQUAL", "tPLUSPLUS",
  "tMINUSMINUS", "tIF", "tELSE", "tCHECKEQ", "tPO", "tPC", "tTAB",
  "tVIRGULE", "tDOLLAR", "tFINSTR", "tINTNR", "tWHILE", "tPRINTF", "tMAIN",
  "tVAR", "tFOR", "tSTRING", "tCHECKHIGHER", "tLESS", "tLESSEQUAL",
  "tMOREEQUAL", "tMINUSEQUAL", "tPLUSEQUAL", "tRETURN", "$accept", "Main",
  "$@1", "$@2", "DeclFunction", "$@3", "Params", "NextParam", "Param",
  "FuncBody", "FuncInstr", "FuncInstrs", "RetVal", "Body", "$@4",
  "Instruction", "Instructions", "Declaration", "Declarations",
  "Multideclaration", "Lastdeclaration", "vartype", "Print", "If", "$@5",
  "$@6", "$@7", "Else", "Condition", "While", "$@8", "$@9", "For", "$@10",
  "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "DeclCalc",
  "Calcul", "Expression", "Function", "$@18", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      71,  -123,  -123,    11,  -123,    -8,  -123,    -1,  -123,  -123,
      29,    37,     2,    57,  -123,    65,    59,    69,    94,    96,
       2,  -123,  -123,    62,  -123,    28,    84,  -123,  -123,  -123,
     103,    32,   104,  -123,    62,  -123,    99,  -123,  -123,  -123,
    -123,  -123,    89,   117,    28,  -123,  -123,  -123,   110,   111,
     107,    61,   113,   114,   102,   102,  -123,   132,  -123,    15,
     116,    99,  -123,   118,  -123,  -123,   102,   102,   121,   102,
      74,  -123,   124,    63,  -123,  -123,  -123,    85,    95,    24,
      24,  -123,   119,  -123,  -123,  -123,  -123,   125,     8,   126,
     127,   101,   122,   106,  -123,   102,   102,   102,   102,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,   128,  -123,   102,   102,
     102,   102,   102,  -123,  -123,  -123,   129,  -123,     2,     4,
       4,  -123,  -123,   102,   102,  -123,    94,   123,   123,   123,
     123,   123,    94,  -123,   133,   130,   131,  -123,  -123,  -123,
    -123,  -123,   135,   134,   136,    94,  -123,   142,   143,  -123,
     137,   139,  -123,  -123,    94,    94,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,    39,    40,     0,     2,     0,     1,     0,     5,     3,
       0,     0,     9,     0,    13,     0,    11,     0,     0,     0,
       0,     8,    12,    25,     4,    17,     0,    10,    42,    53,
       0,     0,     0,    21,    24,    30,     0,    29,    31,    28,
      27,    26,     0,     0,    16,    19,    18,     6,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,    23,    37,
       0,     0,    34,     0,    14,    15,     0,     0,     0,     0,
       0,    79,    78,     0,    80,    70,    71,     0,     0,     0,
       0,    22,     0,    35,    32,    33,    20,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,    68,
      72,    73,    66,    57,    67,    62,    38,    43,     0,     0,
       0,     0,     0,    54,    41,    69,     0,    82,     0,    74,
      75,    76,    77,     0,     0,    36,     0,    48,    50,    49,
      51,    52,     0,    81,     0,     0,     0,    44,    55,    84,
      58,    63,    47,     0,     0,     0,    45,     0,     0,    46,
       0,     0,    59,    64,     0,     0,    60,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   -19,  -123,
     115,  -123,  -123,  -122,  -123,   112,   -16,   -43,    97,  -123,
    -123,     0,  -123,  -123,  -123,  -123,  -123,  -123,   -65,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,    80,     1,   -48,  -123,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     7,    11,     4,    10,    15,    21,    16,    26,
      43,    44,    45,    24,    57,    33,    34,    35,    60,    61,
      62,    36,    37,    38,    48,   126,   142,   146,    87,    39,
      49,   132,    40,    79,   123,   143,   154,    80,   124,   144,
     155,   103,    41,    88,    74,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,    27,    89,    73,   137,     1,    77,    78,     2,    46,
     138,     6,    17,    97,    98,    95,    96,    97,    98,     8,
      17,    91,    93,   149,   108,     9,    82,     1,    46,    14,
       2,     1,   156,   157,     2,    83,   102,   102,   109,   110,
     111,   112,    28,    51,    52,    53,    12,   119,   120,   121,
     122,    31,    29,    30,    13,    31,    32,    42,   135,   136,
     127,   128,   129,   130,   131,     1,    54,    55,     2,    69,
      95,    96,    97,    98,     1,    18,    28,     2,    70,    20,
     104,   104,    92,    19,    71,    99,    29,    30,    72,    31,
      32,    70,    95,    96,    97,    98,    22,    71,    23,   134,
      25,    72,    95,    96,    97,    98,    47,   100,    95,    96,
      97,    98,    63,    95,    96,    97,    98,   101,    17,    70,
      50,    56,    64,   115,   117,    71,    59,    66,    67,    72,
      95,    96,    97,    98,    68,    75,    76,    81,    84,    90,
      86,    94,   106,   107,   113,   116,    58,   133,   125,   114,
     145,   139,   140,   141,   150,   152,   151,   153,    85,    65,
     105,   147,     0,   148
};

static const yytype_int16 yycheck[] =
{
       0,    20,    67,    51,   126,     3,    54,    55,     6,    25,
     132,     0,    12,     9,    10,     7,     8,     9,    10,    27,
      20,    69,    70,   145,    16,    26,    11,     3,    44,    27,
       6,     3,   154,   155,     6,    20,    79,    80,    30,    31,
      32,    33,    14,    11,    12,    13,    17,    95,    96,    97,
      98,    27,    24,    25,    17,    27,    28,    29,   123,   124,
     108,   109,   110,   111,   112,     3,    34,    35,     6,     8,
       7,     8,     9,    10,     3,    18,    14,     6,    17,    20,
      79,    80,     8,    18,    23,    22,    24,    25,    27,    27,
      28,    17,     7,     8,     9,    10,    27,    23,     4,   118,
       4,    27,     7,     8,     9,    10,    22,    22,     7,     8,
       9,    10,    23,     7,     8,     9,    10,    22,   118,    17,
      17,    17,     5,    22,    18,    23,    27,    17,    17,    27,
       7,     8,     9,    10,    27,    22,    22,     5,    22,    18,
      22,    17,    23,    18,    18,    23,    34,    18,    20,    22,
      15,    18,    22,    22,    12,    18,    13,    18,    61,    44,
      80,    27,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,    38,    41,    58,     0,    39,    27,    26,
      42,    40,    17,    17,    27,    43,    45,    58,    18,    18,
      20,    44,    27,     4,    50,     4,    46,    45,    14,    24,
      25,    27,    28,    52,    53,    54,    58,    59,    60,    66,
      69,    79,    29,    47,    48,    49,    53,    22,    61,    67,
      17,    11,    12,    13,    34,    35,    17,    51,    52,    27,
      55,    56,    57,    23,     5,    47,    17,    17,    27,     8,
      17,    23,    27,    80,    81,    22,    22,    80,    80,    70,
      74,     5,    11,    20,    22,    55,    22,    65,    80,    65,
      18,    80,     8,    80,    17,     7,     8,     9,    10,    22,
      22,    22,    54,    78,    79,    78,    23,    18,    16,    30,
      31,    32,    33,    18,    22,    22,    23,    18,    82,    80,
      80,    80,    80,    71,    75,    20,    62,    80,    80,    80,
      80,    80,    68,    18,    45,    65,    65,    50,    50,    18,
      22,    22,    63,    72,    76,    15,    64,    27,    27,    50,
      12,    13,    18,    18,    73,    77,    50,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    40,    38,    42,    41,    41,    43,    43,
      44,    44,    45,    45,    46,    47,    47,    47,    48,    48,
      49,    51,    50,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    61,    62,    63,    60,    64,    64,    65,    65,
      65,    65,    65,    67,    68,    66,    70,    71,    72,    73,
      69,    74,    75,    76,    77,    69,    78,    78,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    82,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     7,     0,     8,     0,     2,     0,
       2,     0,     2,     1,     3,     2,     1,     0,     1,     1,
       3,     0,     4,     2,     1,     0,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     2,     4,     1,     3,     1,
       1,     5,     0,     0,     0,     9,     2,     0,     3,     3,
       3,     3,     3,     0,     0,     7,     0,     0,     0,     0,
      13,     0,     0,     0,     0,    13,     1,     1,     4,     5,
       3,     3,     4,     4,     3,     3,     3,     3,     1,     1,
       1,     4,     3,     0,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 68 "rule.y" /* yacc.c:1646  */
    { 
			//edit_instruction(2,"JMP",get_latest_inst(),0);
		}
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "rule.y" /* yacc.c:1646  */
    { 
			//delete_symbol();print_table();

		}
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "rule.y" /* yacc.c:1646  */
    {}
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "rule.y" /* yacc.c:1646  */
    {
			add_symbol((yyvsp[0].str), type, 0, get_curr_prof()); 
			int a= get_last_index();
			int b=2 + get_latest_inst(); // we add 2 as we added 2 new instructions that should not be repeated , returns -1 so we have to add 3
			queue_instruction("AFC",1,b); 
			queue_instruction("STORE",a,1); 
			queue_instruction("TMPJMP",1,1); 
			//printf("Debug %s\n\n",$1);
			
			prof_increment();}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 91 "rule.y" /* yacc.c:1646  */
    {add_symbol((yyvsp[0].str), type, 0, get_curr_prof()); }
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 92 "rule.y" /* yacc.c:1646  */
    {		int a= find_symbol((yyvsp[0].str), get_curr_prof());
				add_symbol((yyvsp[0].str), type, 0, get_curr_prof()); 
				int b= get_last_index();
	 			queue_instruction("LOAD", 1, a);
				queue_instruction("STORE", b, 1); }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 108 "rule.y" /* yacc.c:1646  */
    {  //we create a temp variable wich has the value of the return
					print_table();
					
				delete_all_var(get_curr_prof());
				prof_decrement();
				//we want to store the variable at a lower level so we can retrieve it afterwards in the Calcul !
					print_table();
					add_symbol("funcReturn", "int", 0, get_curr_prof());
					int a= get_last_index();
					queue_instruction("AFC",1,(yyvsp[-1].nb));
					queue_instruction("STORE",a,1);
					queue_instruction("RET",1,1); 

					/* if it is an expression we need to decrement the prof so that the expression gets saved to another depth and then make the delete all var function search to delete only those particular variables*/
		}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 124 "rule.y" /* yacc.c:1646  */
    {printf("Debug mode\n\n");}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 144 "rule.y" /* yacc.c:1646  */
    {add_symbol((yyvsp[-1].str), type, 0,get_curr_prof());}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 145 "rule.y" /* yacc.c:1646  */
    {
		    add_symbol((yyvsp[-3].str), type, 0, get_curr_prof());
		// we could change add symbol to return the address
		    int a = find_symbol((yyvsp[-3].str), get_curr_prof());
		    queue_instruction("AFC", 1, (yyvsp[-1].nb));
		    queue_instruction("STORE", a, 1); 
}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 155 "rule.y" /* yacc.c:1646  */
    {add_symbol((yyvsp[0].str), type, 0, get_curr_prof());}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 156 "rule.y" /* yacc.c:1646  */
    {
				 add_symbol((yyvsp[-2].str), type, 0, get_curr_prof());
		// we could change add symbol to return the address
				 int a = find_symbol((yyvsp[-2].str), get_curr_prof());
				 queue_instruction("AFC", 1, (yyvsp[0].nb));
				 queue_instruction("STORE", a, 1); 
}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 165 "rule.y" /* yacc.c:1646  */
    { type = "int"; }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 166 "rule.y" /* yacc.c:1646  */
    { type = "const"; }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 169 "rule.y" /* yacc.c:1646  */
    {printf("Print not supported\n");}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 174 "rule.y" /* yacc.c:1646  */
    {prof_increment();}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 174 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index(); //condition-index
		queue_instruction("LOAD", 10, a);
		queue_instruction("TMP", 1, 1);
		(yyvsp[-4].nb) = get_latest_inst();
		delete_symbol();
		
	}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 181 "rule.y" /* yacc.c:1646  */
    {
		edit_instruction((yyvsp[-6].nb), "JMPC" , get_latest_inst(), 10);
		queue_instruction("AFC", 11, -1);
		queue_instruction("MUL", 10, 11);
		queue_instruction("TMP", 1, 1);
		(yyvsp[-6].nb) = get_latest_inst();
		
	}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 188 "rule.y" /* yacc.c:1646  */
    {	
		edit_instruction((yyvsp[-8].nb), "JMPC" , get_latest_inst(), 10);
		delete_all_var(get_curr_prof());
		prof_decrement();
				
}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 204 "rule.y" /* yacc.c:1646  */
    {

		printf("we are in condition after finding it at depth %d \n\n", get_curr_prof());
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("EQU", 2, 1);
		queue_instruction("STORE", b, 2);
		delete_symbol();
	}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 215 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("INF", 2, 1);
		queue_instruction("STORE", b, 2);
		delete_symbol();
	}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 224 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("SUP", 2, 1);
		queue_instruction("STORE", b, 2);
		delete_symbol();
	}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 233 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("INFE", 2, 1);
		queue_instruction("STORE", b, 2);
		delete_symbol();
	}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 242 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index(); // right arg
		int b = a-1;			// left arg
		queue_instruction("LOAD", 1, a);
		queue_instruction("LOAD", 2, b);
		queue_instruction("SUPE", 2, 1);
		queue_instruction("STORE", b, 2);
		delete_symbol();
	}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 256 "rule.y" /* yacc.c:1646  */
    {
	prof_increment();
	(yyvsp[0].nb) = get_latest_inst(); /* Hop to here to retry condition */
	//printf("$1 in while is : : %d\n", $1);
	}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 260 "rule.y" /* yacc.c:1646  */
    {

	int a = get_last_index(); //condition-index after all conditions
	queue_instruction("LOAD", 10, a); // add in place of 10 , 5+ prof
	queue_instruction("TMP", 1, 1); //we add the unedited JMPC
	(yyvsp[-2].nb) = get_latest_inst();         
	delete_symbol();

	}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 268 "rule.y" /* yacc.c:1646  */
    {
		queue_instruction("JMP", (yyvsp[-6].nb), 1);
		edit_instruction((yyvsp[-4].nb), "JMPC" , get_latest_inst(), 10);

		delete_all_var(get_curr_prof());
		prof_decrement();

	}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 279 "rule.y" /* yacc.c:1646  */
    {
			prof_increment();}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 281 "rule.y" /* yacc.c:1646  */
    {
		    	(yyvsp[-3].nb) = get_latest_inst();}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 284 "rule.y" /* yacc.c:1646  */
    {
	   		int a = get_last_index(); //condition-index after all conditions
			queue_instruction("LOAD", 10, a);}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 288 "rule.y" /* yacc.c:1646  */
    {
			(yyvsp[-9].nb)= find_symbol((yyvsp[-2].str), get_curr_prof());
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC 
			(yyvsp[-4].nb) = get_latest_inst();         
			delete_symbol();}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 293 "rule.y" /* yacc.c:1646  */
    {	
			//we add here the code for incrementing but targeting the variable that has to be targeted
			queue_instruction("LOAD", 1, (yyvsp[-11].nb));
			queue_instruction("AFC", 2, 1);
			queue_instruction("ADD", 1, 2);
			queue_instruction("STORE", (yyvsp[-11].nb), 1);
			//we updated the value of the value incremented and now we can jump to the condition
			queue_instruction("JMP", (yyvsp[-12].nb), 1);
			edit_instruction((yyvsp[-6].nb), "JMPC" , get_latest_inst(), 10);


			delete_all_var(get_curr_prof());
			prof_decrement();}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 308 "rule.y" /* yacc.c:1646  */
    {
			prof_increment();}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 310 "rule.y" /* yacc.c:1646  */
    {
		        (yyvsp[-3].nb) = get_latest_inst();}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 312 "rule.y" /* yacc.c:1646  */
    {
	   		int a = get_last_index(); //condition-index after all conditions
			queue_instruction("LOAD", 10, a);}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 315 "rule.y" /* yacc.c:1646  */
    {
			(yyvsp[-9].nb)= find_symbol((yyvsp[-2].str), get_curr_prof());
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC 
			(yyvsp[-4].nb) = get_latest_inst();         
			delete_symbol();}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 320 "rule.y" /* yacc.c:1646  */
    {

			queue_instruction("LOAD", 1,(yyvsp[-11].nb));
			queue_instruction("AFC", 2, 1);  // increment part
 			queue_instruction("SUB", 1, 2);
			queue_instruction("STORE", (yyvsp[-11].nb), 1);

			queue_instruction("JMP", (yyvsp[-12].nb), 1);
			edit_instruction((yyvsp[-6].nb), "JMPC" , get_latest_inst(), 10);


			delete_all_var(get_curr_prof());
			prof_decrement(); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 349 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-3].str), get_curr_prof());
				 int b = get_last_index();
				 queue_instruction("LOAD", 1, b);
				 queue_instruction("STORE", a, 1);
				 delete_symbol();}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 356 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-4].str), get_curr_prof());
				 int b = get_last_index();
				 queue_instruction("LOAD", 1, b);
				 queue_instruction("AFC", 2, -1);
				 queue_instruction("MUL", 1, 2);
				 queue_instruction("STORE", a, 1);
				 delete_symbol();}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 365 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-2].str), get_curr_prof());
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("AFC", 2, 1);
				 queue_instruction("ADD", 1, 2);
				 queue_instruction("STORE", a, 1);}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 372 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-2].str), get_curr_prof());
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("AFC", 2, 1);
				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", a, 1);}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 379 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-3].str), get_curr_prof());
				 int b = get_last_index();
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("LOAD", 2, b);
				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", a, 1);
				 delete_symbol();}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 388 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-3].str), get_curr_prof());
				 int b = get_last_index();
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("LOAD", 2, b);
			   	 queue_instruction("ADD", 1, 2);
				 queue_instruction("STORE", a, 1);
				 delete_symbol();}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 400 "rule.y" /* yacc.c:1646  */
    {
				 int a = get_last_index();
				 int b = a-1;
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("LOAD", 2, b);
				 queue_instruction("ADD", 1, 2);
			     queue_instruction("STORE", b, 1);
				 delete_symbol(); }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 409 "rule.y" /* yacc.c:1646  */
    {
				 int a = get_last_index();
			 	 int b = a-1;
				 queue_instruction("LOAD", 1, a);
			 	 queue_instruction("LOAD", 2, b);
				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", b, 1);
			 	 delete_symbol(); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 418 "rule.y" /* yacc.c:1646  */
    {
				 int a = get_last_index();
				 int b = a-1;
				 queue_instruction("LOAD", 1, a);
			 	 queue_instruction("LOAD", 2, b);
				 queue_instruction("DIV", 1, 2);
				 queue_instruction("STORE", b, 1);
				 delete_symbol(); }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 427 "rule.y" /* yacc.c:1646  */
    {
		 		 int a = get_last_index();
				 int b = a-1;
				 queue_instruction("LOAD", 1, a);
				 queue_instruction("LOAD", 2, b);
				 queue_instruction("MUL", 1, 2);
				 queue_instruction("STORE", b, 1);
				 delete_symbol(); }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 436 "rule.y" /* yacc.c:1646  */
    {
				add_temporary_symbol();
	 			queue_instruction("LOAD", 1, find_symbol((yyvsp[0].str), get_curr_prof()));
				queue_instruction("STORE", get_last_index(), 1); }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 441 "rule.y" /* yacc.c:1646  */
    {
				add_temporary_symbol();
				queue_instruction("AFC", 1, (yyvsp[0].nb));
				queue_instruction("STORE", get_last_index(), 1); }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 445 "rule.y" /* yacc.c:1646  */
    {
				//we always have the result in the last var ? 
			 }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 449 "rule.y" /* yacc.c:1646  */
    {
				add_temporary_symbol();
				queue_instruction("AFC", 1, (yyvsp[-1].nb));
				queue_instruction("AFC", 2, -1);
				queue_instruction("MUL", 1, 2);
				queue_instruction("STORE", get_last_index(), 1); }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 462 "rule.y" /* yacc.c:1646  */
    {/*connected*/}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 462 "rule.y" /* yacc.c:1646  */
    {
	
		queue_instruction("CALL",find_symbol((yyvsp[-4].str),0),0);}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1965 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 466 "rule.y" /* yacc.c:1906  */



void yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
	exit(1);
}

int main() {

	//#if YYDEBUG
	//	yydebug = 1;
//	#endif




//exit(-1);
	yyparse();
	execute_all_instructions();
	print_table();

	for(int i=0; i<=get_last_index(); i++){

		printf("var: %s, value: %d\n", get_variable_name(i), get_memory_value(i));
	}
}




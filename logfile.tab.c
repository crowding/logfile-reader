/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     WORD = 259,
     DOTWORD = 260,
     QUOTED = 261,
     BEGIN_ = 262,
     TRIGGER = 263,
     END = 264,
     EYE_DATA = 265,
     AUDIO_DATA = 266,
     REWARD = 267,
     FRAME_SKIP = 268,
     FRAME_COUNT = 269,
     EVENT_CODE = 270,
     AUDIO_UNDERFLOW = 271,
     AUDIO_SAMPLE = 272,
     EOL = 273,
     EQUAL = 274,
     LPAREN = 275,
     RPAREN = 276,
     LBRACKET = 277,
     RBRACKET = 278,
     LBRACE = 279,
     RBRACE = 280,
     COMMA = 281,
     SEMICOLON = 282,
     COLON = 283
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define WORD 259
#define DOTWORD 260
#define QUOTED 261
#define BEGIN_ 262
#define TRIGGER 263
#define END 264
#define EYE_DATA 265
#define AUDIO_DATA 266
#define REWARD 267
#define FRAME_SKIP 268
#define FRAME_COUNT 269
#define EVENT_CODE 270
#define AUDIO_UNDERFLOW 271
#define AUDIO_SAMPLE 272
#define EOL 273
#define EQUAL 274
#define LPAREN 275
#define RPAREN 276
#define LBRACKET 277
#define RBRACKET 278
#define LBRACE 279
#define RBRACE 280
#define COMMA 281
#define SEMICOLON 282
#define COLON 283




/* Copy the first part of user declarations.  */
#line 1 "logfile.y"

#include <stdio.h>
#include "strbuilder.h"

extern int yylineno;

int printNextLine = 1;

#define FINISH_LINE( x, y ) if (printNextLine) {strb_print( y ); putchar('\n');}; printNextLine = 1; strb_clean(); x = 0;

const char *preamble = 
  "#!/usr/bin/env Rscript\n";



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "logfile.y"
{ 
  struct strbuilder *s; 
  int *i;
}
/* Line 193 of yacc.c.  */
#line 172 "logfile.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 185 "logfile.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    11,    12,    14,    17,    20,
      23,    26,    28,    31,    34,    37,    40,    43,    46,    48,
      50,    53,    56,    60,    62,    64,    66,    68,    70,    72,
      74,    76,    78,    80,    82,    84,    87,    90,    93,    95,
      97,    99,   103,   106,   108,   110,   114,   116,   120,   122,
     124,   127,   131,   136,   138,   142,   144,   148,   152,   154,
     157,   159,   162,   164,   168,   172,   175,   180,   182,   186,
     190,   195,   201,   208,   214,   219,   224,   229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    30,    32,    18,    -1,    30,    18,    -1,
      -1,    -1,    27,    -1,    34,    31,    -1,    37,    31,    -1,
      38,    31,    -1,    47,    31,    -1,    51,    -1,    54,    31,
      -1,    55,    31,    -1,    58,    31,    -1,    59,    31,    -1,
      56,    31,    -1,    57,    31,    -1,    33,    -1,     9,    -1,
      33,    35,    -1,     7,    35,    -1,     7,    35,    36,    -1,
       4,    -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,    13,    -1,    15,    -1,    16,    -1,
      17,    -1,    35,    -1,    35,    36,    -1,    10,    39,    -1,
      11,    39,    -1,    40,    -1,    45,    -1,     3,    -1,    22,
      41,    23,    -1,    22,    23,    -1,     6,    -1,    43,    -1,
      43,    27,    42,    -1,    43,    -1,    42,    27,    43,    -1,
      44,    -1,    39,    -1,    44,    39,    -1,    44,    26,    39,
      -1,    35,    20,    46,    21,    -1,    40,    -1,    40,    26,
      46,    -1,    48,    -1,    48,    26,    46,    -1,    48,    19,
      39,    -1,    35,    -1,    35,    49,    -1,    50,    -1,    49,
      50,    -1,     5,    -1,    20,    46,    21,    -1,    24,    46,
      25,    -1,     8,    35,    -1,     8,    35,    52,    27,    -1,
      53,    -1,    52,    27,    53,    -1,    35,    19,    39,    -1,
      12,     3,     3,     3,    -1,    12,     3,     3,     3,     3,
      -1,    12,     3,     3,     3,     3,     3,    -1,    13,     3,
       3,     3,     3,    -1,    16,     3,     3,     3,    -1,    17,
      35,     3,     3,    -1,    14,     3,     4,     3,    -1,    15,
       3,     3,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    34,    34,    35,    36,    39,    40,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    59,
      60,    65,    77,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   106,   107,   111,   115,   119,   120,
     124,   125,   126,   127,   148,   149,   153,   154,   158,   162,
     163,   164,   168,   174,   175,   176,   177,   181,   185,   186,
     190,   191,   195,   196,   197,   201,   202,   207,   208,   212,
     216,   222,   229,   240,   250,   258,   266,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "WORD", "DOTWORD", "QUOTED",
  "BEGIN_", "TRIGGER", "END", "EYE_DATA", "AUDIO_DATA", "REWARD",
  "FRAME_SKIP", "FRAME_COUNT", "EVENT_CODE", "AUDIO_UNDERFLOW",
  "AUDIO_SAMPLE", "EOL", "EQUAL", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "COMMA", "SEMICOLON", "COLON", "$accept",
  "datafile", "optionalSemicolon", "line", "end", "begin", "word", "words",
  "eyeData", "audioData", "data", "literalData", "matrixContents",
  "multipleMatrixRows", "fullMatrixRow", "partMatrixRow", "fcall",
  "arguments", "assignment", "address", "addressSuffixes", "addressSuffix",
  "trigger", "structfields", "structfield", "reward", "frameSkip",
  "audioUnderflow", "audioSample", "frameCount", "eventCode", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    30,    30,    31,    31,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    33,
      33,    34,    34,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    36,    36,    37,    38,    39,    39,
      40,    40,    40,    40,    41,    41,    42,    42,    43,    44,
      44,    44,    45,    46,    46,    46,    46,    47,    48,    48,
      49,    49,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54,    54,    55,    56,    57,    58,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     0,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     3,     2,     1,     1,     3,     1,     3,     1,     1,
       2,     3,     4,     1,     3,     1,     3,     3,     1,     2,
       1,     2,     1,     3,     3,     2,     4,     1,     3,     3,
       4,     5,     6,     5,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,    23,    24,    25,    19,    27,    28,    29,
      30,     0,    31,    32,    33,     3,     0,    18,     5,    58,
       5,     5,     5,     0,    11,     5,     5,     5,     5,     5,
       5,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    21,    65,    40,    43,     0,     0,    36,    38,    39,
      37,     0,     0,     0,     0,     0,     0,     2,    20,     6,
       7,    62,     0,     0,    59,    60,     8,     9,    10,     0,
      12,    13,    16,    17,    14,    15,    34,    22,     0,     0,
      67,    42,    49,     0,    44,    48,     0,     0,     0,     0,
       0,     0,     0,    53,     0,    55,     0,    61,    57,    35,
       0,    66,    41,     0,     0,    50,     0,    70,     0,    76,
      77,    74,    75,     0,    63,     0,    64,    69,    68,    45,
      46,    51,    52,    71,    73,    54,    56,     0,    72,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    60,    16,    17,    18,    46,    77,    20,    21,
      82,    48,    83,   119,    84,    85,    49,    94,    22,    95,
      64,    65,    24,    79,    80,    25,    26,    27,    28,    29,
      30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -96
static const yytype_int16 yypact[] =
{
     -96,   131,   -96,   -96,   146,   146,    26,   112,   112,     6,
       7,     8,     9,    22,   146,   -96,    17,   146,    12,    29,
      12,    12,    12,    19,   -96,    12,    12,    12,    12,    12,
      12,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   146,   146,   -96,   -96,    61,    16,   -96,   -96,   -96,
     -96,    39,    40,    43,    41,    45,    48,   -96,   -96,   -96,
     -96,   -96,   112,   112,    29,   -96,   -96,   -96,   -96,   112,
     -96,   -96,   -96,   -96,   -96,   -96,   146,   -96,    33,    27,
     -96,   -96,   -96,    32,    53,    11,   112,    57,    63,    78,
      79,    83,    84,    62,    68,    64,    66,   -96,   -96,   -96,
     112,   146,   -96,   112,   112,   -96,    71,    90,    92,   -96,
     -96,   -96,   -96,   112,   -96,   112,   -96,   -96,   -96,    69,
     -96,   -96,   -96,    94,   -96,   -96,   -96,   112,   -96,   -96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,    81,   -96,   -96,   -96,    -1,    23,   -96,   -96,
      -6,   -57,   -96,   -96,   -95,   -96,   -96,   -56,   -96,   103,
     -96,    49,   -96,   -96,     4,   -96,   -96,   -96,   -96,   -96,
     -96
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -27
static const yytype_int16 yytable[] =
{
      19,    47,    50,    41,    42,    93,    93,    96,   120,    51,
      52,    53,    54,    56,    43,     3,    58,    44,    31,    32,
      33,    34,    35,    36,    37,    55,    38,    39,    40,    93,
     106,   -26,   129,    45,    61,    57,    86,   104,    69,    59,
      76,    78,    87,    88,    90,   -26,   -26,    89,    91,    62,
     -26,    92,   100,    63,   101,   102,    93,   125,    93,   126,
     107,    19,    19,    98,    43,     3,   108,    44,    31,    32,
      33,    34,    35,    36,    37,    76,    38,    39,    40,   105,
     103,   109,   110,    45,    81,    19,   111,   112,   113,   114,
     115,   116,   122,   123,   117,   124,   127,   128,   121,    99,
      78,    66,    67,    68,    23,   118,    70,    71,    72,    73,
      74,    75,    19,    97,    19,    43,     3,     0,    44,    31,
      32,    33,    34,    35,    36,    37,     0,    38,    39,    40,
       0,     2,     0,     0,    45,     3,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       3,     0,     0,    31,    32,    33,    34,    35,    36,    37,
       0,    38,    39,    40
};

static const yytype_int8 yycheck[] =
{
       1,     7,     8,     4,     5,    62,    63,    63,   103,     3,
       3,     3,     3,    14,     3,     4,    17,     6,     7,     8,
       9,    10,    11,    12,    13,     3,    15,    16,    17,    86,
      86,     5,   127,    22,     5,    18,    20,    26,    19,    27,
      41,    42,     3,     3,     3,    19,    20,     4,     3,    20,
      24,     3,    19,    24,    27,    23,   113,   113,   115,   115,
       3,    62,    63,    69,     3,     4,     3,     6,     7,     8,
       9,    10,    11,    12,    13,    76,    15,    16,    17,    85,
      27,     3,     3,    22,    23,    86,     3,     3,    26,    21,
      26,    25,    21,     3,   100,     3,    27,     3,   104,    76,
     101,    20,    21,    22,     1,   101,    25,    26,    27,    28,
      29,    30,   113,    64,   115,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      -1,     0,    -1,    -1,    22,     4,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       4,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,     0,     4,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    32,    33,    34,    35,
      37,    38,    47,    48,    51,    54,    55,    56,    57,    58,
      59,     7,     8,     9,    10,    11,    12,    13,    15,    16,
      17,    35,    35,     3,     6,    22,    35,    39,    40,    45,
      39,     3,     3,     3,     3,     3,    35,    18,    35,    27,
      31,     5,    20,    24,    49,    50,    31,    31,    31,    19,
      31,    31,    31,    31,    31,    31,    35,    36,    35,    52,
      53,    23,    39,    41,    43,    44,    20,     3,     3,     4,
       3,     3,     3,    40,    46,    48,    46,    50,    39,    36,
      19,    27,    23,    27,    26,    39,    46,     3,     3,     3,
       3,     3,     3,    26,    21,    26,    25,    39,    53,    42,
      43,    39,    21,     3,     3,    46,    46,    27,     3,    43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 36 "logfile.y"
    {(yyval.i) = 0;;}
    break;

  case 7:
#line 44 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 8:
#line 45 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 9:
#line 46 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 10:
#line 47 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 11:
#line 48 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (1)].s) );}
    break;

  case 12:
#line 49 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 13:
#line 50 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 14:
#line 51 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 15:
#line 52 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 16:
#line 53 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 17:
#line 54 "logfile.y"
    {FINISH_LINE( (yyval.i), (yyvsp[(1) - (2)].s) );}
    break;

  case 18:
#line 55 "logfile.y"
    {(yyval.i) = 0; strb_clean();;}
    break;

  case 21:
#line 65 "logfile.y"
    {
  const char *type = strb_cat((yyvsp[(2) - (2)].s))->str;
  if (!strcmp(type, "EXPERIMENT_RUN")) {
    (yyval.s) = strb_const("beginRun()\n");
  } else if (!strcmp(type, "TRIAL")) {
    (yyval.s) = strb_const("beginTrial()\n");
  } else if (!strcmp(type, "STIMULUS")) {
    (yyval.s) = strb_const("beginStimulus()\n");
  } else {
    yyerror("unknown run type"); YYERROR;
  }
;}
    break;

  case 22:
#line 77 "logfile.y"
    {
  const char *type = strb_cat((yyvsp[(2) - (3)].s))->str;
  if (!strcmp(type, "EXPERIMENT_RUN")) {
    (yyval.s) = strb_append(strb_append(strb_const("beginRun(id='"), (yyvsp[(3) - (3)].s)), strb_const("')"));
  } else if (!strcmp(type, "TRIAL")) {
    (yyval.s) = strb_append(strb_append(strb_const("beginTrial(id='"), (yyvsp[(3) - (3)].s)), strb_const("')")); 
  } else if (!strcmp(type, "STIMULUS")) {
    (yyval.s) = strb_append(strb_append(strb_const("beginStimulus(id='"), (yyvsp[(3) - (3)].s)), strb_const("')"));
 } else {
    yyerror("unknown run type"); YYERROR;
  }
;}
    break;

  case 35:
#line 107 "logfile.y"
    { (yyval.s) = strb_append(strb_append((yyvsp[(1) - (2)].s),strb_const(" ")),(yyvsp[(2) - (2)].s));}
    break;

  case 36:
#line 111 "logfile.y"
    { (yyval.s) = strb_append(strb_append(strb_const("eyeData("), (yyvsp[(2) - (2)].s)), strb_const(")")); ;}
    break;

  case 37:
#line 115 "logfile.y"
    { (yyval.s) = strb_append(strb_append(strb_const("audioData("), (yyvsp[(2) - (2)].s)), strb_const(")")); ;}
    break;

  case 41:
#line 125 "logfile.y"
    {(yyval.s) = (yyvsp[(2) - (3)].s);;}
    break;

  case 42:
#line 126 "logfile.y"
    {(yyval.s) = strb_const("numeric(0)");;}
    break;

  case 43:
#line 127 "logfile.y"
    {
  /* replace doubled-quotes with escaped-quotes. */
  strbuilder *new = strb_cat((yyvsp[(1) - (1)].s));
  char *cur = (char *) new->str;
  if (! *cur) {
    (yyval.s) = new;
  } else {
    while(*(++cur)) {
      if (*cur == '\'' && *(cur-1) == '\'') {
	*(cur-1) = '\\';	     
	if (!*(++cur)) {
	  break;
	}
      }
    }
  }
  (yyval.s) = strb_build(strb_const("'"), new, strb_const("'"), NULL);
;}
    break;

  case 45:
#line 149 "logfile.y"
    { (yyval.s) = strb_build(strb_const("rbind("), (yyvsp[(1) - (3)].s), strb_const(", "), (yyvsp[(3) - (3)].s), strb_const(")"), NULL); ;}
    break;

  case 47:
#line 154 "logfile.y"
    { (yyval.s) = strb_build((yyvsp[(1) - (3)].s), strb_const(", "), (yyvsp[(3) - (3)].s), NULL) ;}
    break;

  case 48:
#line 158 "logfile.y"
    { (yyval.s) = strb_build(strb_const("c("), (yyvsp[(1) - (1)].s), strb_const(")"), NULL) ;}
    break;

  case 50:
#line 163 "logfile.y"
    {(yyval.s) = strb_append(strb_append((yyvsp[(1) - (2)].s), strb_const(", ")), (yyvsp[(2) - (2)].s));}
    break;

  case 51:
#line 164 "logfile.y"
    {(yyval.s) = strb_append(strb_append((yyvsp[(1) - (3)].s), strb_const(", ")), (yyvsp[(3) - (3)].s));;}
    break;

  case 52:
#line 168 "logfile.y"
    { (yyval.s) = strb_build((yyvsp[(1) - (4)].s), strb_const("("), (yyvsp[(3) - (4)].s), strb_const(")"), NULL) ;}
    break;

  case 53:
#line 174 "logfile.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 54:
#line 175 "logfile.y"
    { (yyval.s) = strb_build((yyvsp[(1) - (3)].s), strb_const(","), (yyvsp[(3) - (3)].s), NULL); ;}
    break;

  case 55:
#line 176 "logfile.y"
    { printNextLine = 0; ;}
    break;

  case 56:
#line 177 "logfile.y"
    { printNextLine = 0; ;}
    break;

  case 57:
#line 181 "logfile.y"
    { (yyval.s) = strb_build((yyvsp[(1) - (3)].s), strb_const(" <- "), (yyvsp[(3) - (3)].s), NULL);;}
    break;

  case 58:
#line 185 "logfile.y"
    { (yyval.s) = strb_build(strb_const("`"), (yyvsp[(1) - (1)].s), strb_const("`"), NULL); ;}
    break;

  case 59:
#line 186 "logfile.y"
    { { (yyval.s) = strb_build(strb_const("`"), (yyvsp[(1) - (2)].s), strb_const("`"), (yyvsp[(2) - (2)].s), NULL); } ;}
    break;

  case 61:
#line 191 "logfile.y"
    { (yyval.s) = strb_append((yyvsp[(1) - (2)].s), (yyvsp[(2) - (2)].s)); ;}
    break;

  case 62:
#line 195 "logfile.y"
    {(yyval.s) = strb_build( strb_const("$`"), (yyvsp[(1) - (1)].s), strb_const("`"), NULL);;}
    break;

  case 63:
#line 196 "logfile.y"
    { (yyval.s) = strb_build(strb_const("["), (yyvsp[(2) - (3)].s), strb_const("]"), NULL) ;}
    break;

  case 64:
#line 197 "logfile.y"
    { (yyval.s) = strb_build(strb_const("[["), (yyvsp[(2) - (3)].s), strb_const("]]"), NULL) ;}
    break;

  case 65:
#line 201 "logfile.y"
    {(yyval.s) = strb_build(strb_const("storeTrigger(name=\""), (yyvsp[(2) - (2)].s), strb_const("\")"), NULL);;}
    break;

  case 66:
#line 202 "logfile.y"
    {(yyval.s) = strb_build(strb_const("storeTrigger(name=\""), (yyvsp[(2) - (4)].s), 
					     strb_const("\", "), (yyvsp[(3) - (4)].s), strb_const(")"), NULL);}
    break;

  case 68:
#line 208 "logfile.y"
    {(yyval.s) = strb_build((yyvsp[(1) - (3)].s), strb_const(", "), (yyvsp[(3) - (3)].s), NULL);;}
    break;

  case 69:
#line 212 "logfile.y"
    {(yyval.s) = strb_build(strb_const("`"), (yyvsp[(1) - (3)].s), strb_const("`="), (yyvsp[(3) - (3)].s), NULL);}
    break;

  case 70:
#line 216 "logfile.y"
    {
  (yyval.s) = strb_build(strb_const("storeTrigger(name='REWARD', requestedOnset="), (yyvsp[(2) - (4)].s),  
		  strb_const(", length="), (yyvsp[(3) - (4)].s),
		  strb_const(", predictedOnset="), (yyvsp[(4) - (4)].s),
		  strb_const(")"), NULL)
		  ;}
    break;

  case 71:
#line 222 "logfile.y"
    {
  (yyval.s) = strb_build(strb_const("storeTrigger(name='REWARD', requestedOnset="), (yyvsp[(2) - (5)].s),  
		  strb_const(", length="), (yyvsp[(3) - (5)].s),
		  strb_const(", refresh="), (yyvsp[(4) - (5)].s),
		  strb_const(", predictedOnset="), (yyvsp[(5) - (5)].s),
		  strb_const(")"), NULL)
		  ;}
    break;

  case 72:
#line 229 "logfile.y"
    {
  (yyval.s) = strb_build(strb_const("storeTrigger(name='REWARD', requestedOnset="), (yyvsp[(2) - (6)].s),  
		  strb_const(", length="), (yyvsp[(3) - (6)].s),
		  strb_const(", refresh="), (yyvsp[(4) - (6)].s),
		  strb_const(", predictedOnset="), (yyvsp[(5) - (6)].s),
		  strb_const(", volume="), (yyvsp[(6) - (6)].s),
		  strb_const(")"), NULL)
    ;}
    break;

  case 73:
#line 240 "logfile.y"
    {
  (yyval.s) = strb_build(strb_const("storeTrigger(name='FRAME_SKIP',skips="), (yyvsp[(2) - (5)].s),  
		  strb_const(", prevVBL="), (yyvsp[(3) - (5)].s),
		  strb_const(", VBL="), (yyvsp[(4) - (5)].s),
		  strb_const(", refresh="), (yyvsp[(5) - (5)].s),
		  strb_const(")"), NULL)
;}
    break;

  case 74:
#line 250 "logfile.y"
    {
  (yyval.s) = strb_build(strb_const("storeTrigger(name='AUDIO_UNDERFLOW', lastSampleSent="), (yyvsp[(2) - (4)].s),  
		  strb_const(", currentSample="), (yyvsp[(3) - (4)].s),
		  strb_const(", time="), (yyvsp[(4) - (4)].s),
		  strb_const(")"), NULL)
;}
    break;

  case 75:
#line 258 "logfile.y"
    {
  (yyval.s) = strb_build(strb_const("storeTrigger(name='AUDIO_SAMPLE', sampleName='"), (yyvsp[(2) - (4)].s),  
		  strb_const("', sampleOnsetTime="), (yyvsp[(3) - (4)].s),
		  strb_const(", sampleOnsetIndex="), (yyvsp[(4) - (4)].s),
		  strb_const(")"), NULL)
    ;}
    break;

  case 76:
#line 266 "logfile.y"
    {
  (yyval.s) = strb_build(strb_const("storeTrigger(name='FRAME_COUNT', frames="), (yyvsp[(2) - (4)].s),  
		  strb_const(", skipped="), (yyvsp[(4) - (4)].s),
		  strb_const(")"), NULL)  
;}
    break;

  case 77:
#line 274 "logfile.y"
    {
  (yyval.s) = strb_build(strb_const("storeTrigger(name='EVENT_CODE', refreshRequested="), (yyvsp[(2) - (4)].s),  
		  strb_const(", code="), (yyvsp[(3) - (4)].s),
		  strb_const(", refreshPredicted="), (yyvsp[(4) - (4)].s),
		  strb_const(")"), NULL);
;}
    break;


/* Line 1267 of yacc.c.  */
#line 1836 "logfile.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 282 "logfile.y"


int main(int argc, char **argv) {
  printf("%s", preamble);
  yyparse();
  return(0);
}

yyerror(char *s) {
  fprintf(stderr, "%d: error: %s\n", yylineno, s);
}

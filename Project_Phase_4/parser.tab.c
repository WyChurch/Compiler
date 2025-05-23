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
     ID = 258,
     INTCONST = 259,
     CHARCONST = 260,
     STRCONST = 261,
     KWD_INT = 262,
     KWD_CHAR = 263,
     KWD_STRING = 264,
     KWD_VOID = 265,
     KWD_WHILE = 266,
     KWD_IF = 267,
     KWD_ELSE = 268,
     KWD_RETURN = 269,
     KWD_FOR = 270,
     OPER_ADD = 271,
     OPER_SUB = 272,
     OPER_MUL = 273,
     OPER_DIV = 274,
     OPER_ASSN = 275,
     OPER_LT = 276,
     OPER_LTE = 277,
     OPER_EQ = 278,
     OPER_GTE = 279,
     OPER_GT = 280,
     OPER_NEQ = 281,
     OPER_ASGN = 282,
     LSQ_BRKT = 283,
     RSQ_BRKT = 284,
     LCRLY_BRKT = 285,
     RCRLY_BRKT = 286,
     LPAREN = 287,
     RPAREN = 288,
     COMMA = 289,
     SEMICLN = 290,
     ERROR = 291,
     ILLEGAL_TOKEN = 292
   };
#endif
/* Tokens.  */
#define ID 258
#define INTCONST 259
#define CHARCONST 260
#define STRCONST 261
#define KWD_INT 262
#define KWD_CHAR 263
#define KWD_STRING 264
#define KWD_VOID 265
#define KWD_WHILE 266
#define KWD_IF 267
#define KWD_ELSE 268
#define KWD_RETURN 269
#define KWD_FOR 270
#define OPER_ADD 271
#define OPER_SUB 272
#define OPER_MUL 273
#define OPER_DIV 274
#define OPER_ASSN 275
#define OPER_LT 276
#define OPER_LTE 277
#define OPER_EQ 278
#define OPER_GTE 279
#define OPER_GT 280
#define OPER_NEQ 281
#define OPER_ASGN 282
#define LSQ_BRKT 283
#define RSQ_BRKT 284
#define LCRLY_BRKT 285
#define RCRLY_BRKT 286
#define LPAREN 287
#define RPAREN 288
#define COMMA 289
#define SEMICLN 290
#define ERROR 291
#define ILLEGAL_TOKEN 292




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/tree.h"
#include "src/strtab.h"

#define YYDEBUG 1

int yylex(void);
int yyerror(const char *s);


extern int yylineno;
char* scope = "";
int param_count = 0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "src/parser.y"
{
    int value;
    struct treenode *node;
    char *strval;
}
/* Line 193 of yacc.c.  */
#line 194 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 207 "parser.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    24,    31,    35,    38,    43,    45,    49,    55,
      62,    66,    71,    74,    80,    88,    94,    97,   101,   103,
     105,   107,   109,   111,   112,   115,   120,   121,   124,   126,
     131,   133,   137,   139,   141,   143,   145,   147,   149,   151,
     155,   157,   159,   161,   163,   167,   169,   171,   173,   175,
     177,   179,   183,   188,   192,   194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    43,    -1,     7,    -1,     8,    -1,     7,
      -1,     8,    -1,    10,    -1,    44,    -1,    47,    -1,    42,
      -1,    43,    42,    -1,    40,     3,    28,     4,    29,    35,
      -1,    40,     3,    35,    -1,    40,     3,    -1,    40,     3,
      28,    29,    -1,    45,    -1,    45,    34,    46,    -1,    41,
       3,    32,    33,    55,    -1,    41,     3,    32,    46,    33,
      55,    -1,    30,    54,    31,    -1,    57,    20,    60,    35,
      -1,    60,    35,    -1,    12,    32,    60,    33,    53,    -1,
      12,    32,    60,    33,    53,    13,    53,    -1,    11,    32,
      60,    33,    53,    -1,    14,    35,    -1,    14,    60,    35,
      -1,    48,    -1,    49,    -1,    50,    -1,    51,    -1,    52,
      -1,    -1,    53,    54,    -1,    30,    56,    54,    31,    -1,
      -1,    44,    56,    -1,     3,    -1,     3,    28,    58,    29,
      -1,    64,    -1,    58,    61,    64,    -1,    22,    -1,    21,
      -1,    25,    -1,    24,    -1,    23,    -1,    26,    -1,    58,
      -1,    60,    59,    58,    -1,    16,    -1,    17,    -1,    18,
      -1,    19,    -1,    32,    60,    33,    -1,    57,    -1,    65,
      -1,     4,    -1,     5,    -1,     6,    -1,    63,    -1,    64,
      62,    63,    -1,     3,    32,    66,    33,    -1,     3,    32,
      33,    -1,    60,    -1,    66,    34,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    80,    84,    90,    94,    98,   104,   110,
     118,   124,   133,   144,   154,   166,   179,   185,   193,   209,
     227,   234,   241,   248,   255,   264,   272,   277,   285,   291,
     297,   303,   309,   318,   322,   331,   345,   349,   358,   365,
     375,   381,   391,   396,   401,   406,   411,   416,   423,   429,
     439,   444,   451,   456,   462,   468,   474,   480,   487,   494,
     503,   509,   519,   527,   537,   543
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTCONST", "CHARCONST",
  "STRCONST", "KWD_INT", "KWD_CHAR", "KWD_STRING", "KWD_VOID", "KWD_WHILE",
  "KWD_IF", "KWD_ELSE", "KWD_RETURN", "KWD_FOR", "OPER_ADD", "OPER_SUB",
  "OPER_MUL", "OPER_DIV", "OPER_ASSN", "OPER_LT", "OPER_LTE", "OPER_EQ",
  "OPER_GTE", "OPER_GT", "OPER_NEQ", "OPER_ASGN", "LSQ_BRKT", "RSQ_BRKT",
  "LCRLY_BRKT", "RCRLY_BRKT", "LPAREN", "RPAREN", "COMMA", "SEMICLN",
  "ERROR", "ILLEGAL_TOKEN", "$accept", "program", "varTypeSpecifier",
  "funcReturnType", "decl", "declList", "varDecl", "formalDecl",
  "formalDeclList", "funDecl", "compoundStmt", "assignStmt", "condStmt",
  "loopStmt", "returnStmt", "statement", "statementList", "funBody",
  "localDeclList", "var", "addExpr", "relop", "expression", "addop",
  "mulop", "factor", "term", "funcCallExpr", "argList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      48,    49,    49,    50,    50,    51,    52,    52,    53,    53,
      53,    53,    53,    54,    54,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     6,     3,     2,     4,     1,     3,     5,     6,
       3,     4,     2,     5,     7,     5,     2,     3,     1,     1,
       1,     1,     1,     0,     2,     4,     0,     2,     1,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     4,     7,     0,     0,     0,    10,     2,     8,
       9,     1,     0,     0,    11,     0,    13,     0,     0,     3,
       4,     0,     0,    16,     0,     0,    36,    18,    14,     0,
       0,    12,    36,    33,     0,    17,    19,    37,    38,    57,
      58,    59,     0,     0,     0,    33,     0,    28,    29,    30,
      31,    32,    33,     0,    55,    48,     0,    60,    40,    56,
      15,     0,     0,     0,     0,    26,    55,     0,     0,     0,
      34,    35,     0,    50,    51,     0,    43,    42,    46,    45,
      44,    47,    22,     0,    52,    53,     0,     0,    63,    64,
       0,     0,     0,    27,    20,    54,     0,    41,    49,    61,
      39,    62,     0,     0,     0,    21,    65,    25,    23,     0,
      24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    23,    24,    10,
      47,    48,    49,    50,    51,    52,    53,    27,    33,    66,
      55,    83,    56,    75,    86,    57,    58,    59,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -61
static const yytype_int8 yypact[] =
{
      82,   -61,   -61,   -61,    18,    25,    28,   -61,    82,   -61,
     -61,   -61,    22,    42,   -61,    50,   -61,     3,    43,   -61,
     -61,    97,   108,    92,    98,    93,    86,   -61,   101,    86,
      97,   -61,    86,    21,   103,   -61,   -61,   -61,    41,   -61,
     -61,   -61,   102,   105,     2,    21,    35,   -61,   -61,   -61,
     -61,   -61,    21,    99,   113,    96,    23,   -61,   104,   -61,
     -61,    35,    10,    35,    35,   -61,   -61,    40,   107,    62,
     -61,   -61,    35,   -61,   -61,    35,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,    35,   -61,   -61,    35,    39,   -61,    95,
      91,    75,    81,   -61,   -61,   -61,    56,   104,    96,   -61,
     -61,   -61,    35,    21,    21,   -61,    95,   -61,   122,    21,
     -61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,     0,   -61,   128,   -61,   -23,   -61,   110,   -61,
     -61,   -61,   -61,   -61,   -61,     6,     7,   111,   112,   -33,
     -60,   -61,   -42,   -61,   -61,    54,    67,   -61,   -61
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      54,    87,    67,    32,    69,    38,    39,    40,    41,    32,
      19,    20,    54,    38,    39,    40,    41,    22,    11,    54,
      89,    91,    92,    98,    38,    39,    40,    41,    12,    22,
      96,    13,    42,    43,    46,    44,    21,    65,    38,    39,
      40,    41,    46,    88,    76,    77,    78,    79,    80,    81,
      15,    45,    68,    46,    18,    73,    74,    16,    82,    70,
     106,    76,    77,    78,    79,    80,    81,    46,   100,    61,
      54,    54,    25,    62,    17,    93,    54,    76,    77,    78,
      79,    80,    81,    76,    77,    78,    79,    80,    81,     1,
       2,   105,     3,    19,    20,    95,    76,    77,    78,    79,
      80,    81,    76,    77,    78,    79,    80,    81,   103,   107,
     108,    28,    73,    74,   104,   110,    76,    77,    78,    79,
      80,    81,    84,    85,   101,   102,    29,    26,    31,    34,
      71,    30,    60,    72,    63,   109,    14,    64,    94,    35,
      99,    36,    97,     0,    37
};

static const yytype_int8 yycheck[] =
{
      33,    61,    44,    26,    46,     3,     4,     5,     6,    32,
       7,     8,    45,     3,     4,     5,     6,    17,     0,    52,
      62,    63,    64,    83,     3,     4,     5,     6,     3,    29,
      72,     3,    11,    12,    32,    14,    33,    35,     3,     4,
       5,     6,    32,    33,    21,    22,    23,    24,    25,    26,
      28,    30,    45,    32,     4,    16,    17,    35,    35,    52,
     102,    21,    22,    23,    24,    25,    26,    32,    29,    28,
     103,   104,    29,    32,    32,    35,   109,    21,    22,    23,
      24,    25,    26,    21,    22,    23,    24,    25,    26,     7,
       8,    35,    10,     7,     8,    33,    21,    22,    23,    24,
      25,    26,    21,    22,    23,    24,    25,    26,    33,   103,
     104,     3,    16,    17,    33,   109,    21,    22,    23,    24,
      25,    26,    18,    19,    33,    34,    34,    30,    35,    28,
      31,    33,    29,    20,    32,    13,     8,    32,    31,    29,
      86,    30,    75,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    10,    39,    40,    41,    42,    43,    44,
      47,     0,     3,     3,    42,    28,    35,    32,     4,     7,
       8,    33,    40,    45,    46,    29,    30,    55,     3,    34,
      33,    35,    44,    56,    28,    46,    55,    56,     3,     4,
       5,     6,    11,    12,    14,    30,    32,    48,    49,    50,
      51,    52,    53,    54,    57,    58,    60,    63,    64,    65,
      29,    28,    32,    32,    32,    35,    57,    60,    54,    60,
      54,    31,    20,    16,    17,    61,    21,    22,    23,    24,
      25,    26,    35,    59,    18,    19,    62,    58,    33,    60,
      66,    60,    60,    35,    31,    33,    60,    64,    58,    63,
      29,    33,    34,    33,    33,    35,    60,    53,    53,    13,
      53
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
        case 2:
#line 73 "src/parser.y"
    {
                    tree* progNode = maketree(PROGRAM);
                    addChild(progNode, (yyvsp[(1) - (1)].node));
                    ast = progNode;
                 ;}
    break;

  case 3:
#line 81 "src/parser.y"
    {
                     (yyval.node) = maketreeWithIntVal(TYPESPEC, INT_TYPE);
                 ;}
    break;

  case 4:
#line 85 "src/parser.y"
    {
                     (yyval.node) = maketreeWithIntVal(TYPESPEC, CHAR_TYPE);
                 ;}
    break;

  case 5:
#line 91 "src/parser.y"
    {
                   (yyval.node) = maketreeWithIntVal(TYPESPEC, INT_TYPE);
               ;}
    break;

  case 6:
#line 95 "src/parser.y"
    {
                   (yyval.node) = maketreeWithIntVal(TYPESPEC, CHAR_TYPE);
               ;}
    break;

  case 7:
#line 99 "src/parser.y"
    {
                   (yyval.node) = maketreeWithIntVal(TYPESPEC, VOID_TYPE);
               ;}
    break;

  case 8:
#line 105 "src/parser.y"
    {
                    tree* declNode = maketree(DECL);
                    addChild(declNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = declNode;
                 ;}
    break;

  case 9:
#line 111 "src/parser.y"
    {
                    tree* declNode = maketree(DECL);
                    addChild(declNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = declNode;
                 ;}
    break;

  case 10:
#line 119 "src/parser.y"
    {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = declListNode;
                 ;}
    break;

  case 11:
#line 125 "src/parser.y"
    {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[(1) - (2)].node));
                    addChild(declListNode, (yyvsp[(2) - (2)].node));
                    (yyval.node) = declListNode;
                 ;}
    break;

  case 12:
#line 134 "src/parser.y"
    {
                    ST_insert((yyvsp[(2) - (6)].strval),scope,(yyvsp[(1) - (6)].node)->val,ARRAY);
                    tree* varDeclNode = maketree(VARDECL);
                    addChild(varDeclNode, (yyvsp[(1) - (6)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(2) - (6)].strval));
                    addChild(varDeclNode, idNode);
                    tree* integerNode = maketreeWithIntVal(INTEGER,(yyvsp[(4) - (6)].value)); 
                    addChild(varDeclNode, integerNode);
                    (yyval.node) = varDeclNode;
                 ;}
    break;

  case 13:
#line 145 "src/parser.y"
    {
                    ST_insert((yyvsp[(2) - (3)].strval),scope,(yyvsp[(1) - (3)].node)->val,SCALAR);
                    tree* varDeclNode = maketree(VARDECL);
                    addChild(varDeclNode, (yyvsp[(1) - (3)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(2) - (3)].strval));
                    addChild(varDeclNode, idNode);
                    (yyval.node) = varDeclNode;
                 ;}
    break;

  case 14:
#line 155 "src/parser.y"
    {
                    ST_insert((yyvsp[(2) - (2)].strval), scope, (yyvsp[(1) - (2)].node)->val, SCALAR);
                    tree* formDeclNode = maketree(FORMALDECL);
                    addChild(formDeclNode, (yyvsp[(1) - (2)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(2) - (2)].strval));
                    addChild(formDeclNode, idNode);
                    (yyval.node) = formDeclNode;

                    add_param((yyvsp[(1) - (2)].node)->val, SCALAR);
                    param_count++;
                 ;}
    break;

  case 15:
#line 167 "src/parser.y"
    {
                    ST_insert((yyvsp[(2) - (4)].strval), scope, (yyvsp[(1) - (4)].node)->val, ARRAY);
                    tree* formDeclNode = maketree(FORMALDECL);
                    addChild(formDeclNode, (yyvsp[(1) - (4)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(2) - (4)].strval));
                    addChild(formDeclNode, idNode);
                    (yyval.node) = formDeclNode;

                    add_param((yyvsp[(1) - (4)].node)->val, ARRAY);
                    param_count++;
                 ;}
    break;

  case 16:
#line 180 "src/parser.y"
    {
                    tree* formDeclNode = maketree(FORMALDECLLIST);
                    addChild(formDeclNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = formDeclNode;
                 ;}
    break;

  case 17:
#line 186 "src/parser.y"
    {
                    tree* formDeclNode = maketree(FORMALDECLLIST);
                    addChild(formDeclNode, (yyvsp[(1) - (3)].node));
                    addChild(formDeclNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = formDeclNode;
                 ;}
    break;

  case 18:
#line 194 "src/parser.y"
    {
                    int index = ST_insert((yyvsp[(2) - (5)].strval), scope, (yyvsp[(1) - (5)].node)->val, FUNCTION);
                    scope = (yyvsp[(2) - (5)].strval);
                    connect_params(index, 0);
                    scope = "";

                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, (yyvsp[(1) - (5)].node)); // return type
                    tree* formals = maketree(FORMALDECLLIST); // empty param list
                    addChild(funDeclNode, formals);
                    addChild(funDeclNode, (yyvsp[(5) - (5)].node)); // body
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(2) - (5)].strval));
                    addChild(funDeclNode, idNode);
                    (yyval.node) = funDeclNode;
                ;}
    break;

  case 19:
#line 210 "src/parser.y"
    {
                    int index = ST_insert((yyvsp[(2) - (6)].strval), scope, (yyvsp[(1) - (6)].node)->val, FUNCTION);
                    scope = (yyvsp[(2) - (6)].strval);
                    connect_params(index, param_count);
                    param_count = 0;
                    scope = "";

                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, (yyvsp[(1) - (6)].node)); // return type
                    addChild(funDeclNode, (yyvsp[(4) - (6)].node)); // formal list
                    addChild(funDeclNode, (yyvsp[(6) - (6)].node)); // body
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(2) - (6)].strval));
                    addChild(funDeclNode, idNode);
                    (yyval.node) = funDeclNode;
                ;}
    break;

  case 20:
#line 228 "src/parser.y"
    {
                    tree* compStmtNode = maketree(COMPOUNDSTMT);
                    addChild(compStmtNode, (yyvsp[(2) - (3)].node));  // $2 is the statementList
                    (yyval.node) = compStmtNode;
                 ;}
    break;

  case 21:
#line 235 "src/parser.y"
    {
                    tree* assignStmtNode = maketree(ASSIGNSTMT);
                    addChild(assignStmtNode, (yyvsp[(1) - (4)].node));
                    addChild(assignStmtNode, (yyvsp[(3) - (4)].node));
                    (yyval.node) = assignStmtNode;
                 ;}
    break;

  case 22:
#line 242 "src/parser.y"
    {
                    tree* assignStmtNode = maketree(ASSIGNSTMT);
                    addChild(assignStmtNode, (yyvsp[(1) - (2)].node));
                    (yyval.node) = assignStmtNode;
                ;}
    break;

  case 23:
#line 249 "src/parser.y"
    {
                    tree* condStmtNode = maketree(CONDSTMT);
                    addChild(condStmtNode, (yyvsp[(3) - (5)].node));
                    addChild(condStmtNode, (yyvsp[(5) - (5)].node));
                    (yyval.node) = condStmtNode;
                 ;}
    break;

  case 24:
#line 256 "src/parser.y"
    {
                    tree* condStmtNode = maketree(CONDSTMT);
                    addChild(condStmtNode, (yyvsp[(3) - (7)].node));
                    addChild(condStmtNode, (yyvsp[(5) - (7)].node));
                    addChild(condStmtNode, (yyvsp[(7) - (7)].node));
                    (yyval.node) = condStmtNode;
                 ;}
    break;

  case 25:
#line 265 "src/parser.y"
    {
                    tree* loopStmtNode = maketree(LOOPSTMT);
                    addChild(loopStmtNode, (yyvsp[(3) - (5)].node));
                    addChild(loopStmtNode, (yyvsp[(5) - (5)].node));
                    (yyval.node) = loopStmtNode;
                 ;}
    break;

  case 26:
#line 273 "src/parser.y"
    {
                    tree* returnStmtNode = maketree(RETURNSTMT);
                    (yyval.node) = returnStmtNode;
                 ;}
    break;

  case 27:
#line 278 "src/parser.y"
    {
                    tree* returnStmtNode = maketree(RETURNSTMT);
                    addChild(returnStmtNode, (yyvsp[(2) - (3)].node));
                    (yyval.node) = returnStmtNode;
                 ;}
    break;

  case 28:
#line 286 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 ;}
    break;

  case 29:
#line 292 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 ;}
    break;

  case 30:
#line 298 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 ;}
    break;

  case 31:
#line 304 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 ;}
    break;

  case 32:
#line 310 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 ;}
    break;

  case 33:
#line 318 "src/parser.y"
    {
                    tree* statementListNode = maketree(STATEMENTLIST);
                    (yyval.node) = statementListNode;
                 ;}
    break;

  case 34:
#line 323 "src/parser.y"
    {
                    tree* statementListNode = maketree(STATEMENTLIST);
                    addChild(statementListNode, (yyvsp[(1) - (2)].node));
                    addChild(statementListNode, (yyvsp[(2) - (2)].node));
                    (yyval.node) = statementListNode;
                 ;}
    break;

  case 35:
#line 332 "src/parser.y"
    {
                    new_scope();  // Open a new scope for function body

                    tree* funBodyNode = maketree(FUNBODY);
                    addChild(funBodyNode, (yyvsp[(2) - (4)].node));
                    addChild(funBodyNode, (yyvsp[(3) - (4)].node));

                    up_scope();    // Close the scope at the end
                    scope = "";    // Reset to global
                    (yyval.node) = funBodyNode;
                ;}
    break;

  case 36:
#line 345 "src/parser.y"
    {
                    tree* localDeclListNode = maketree(LOCALDECLLIST);
                    (yyval.node) = localDeclListNode;
                ;}
    break;

  case 37:
#line 350 "src/parser.y"
    {
                    tree* localDeclListNode = maketree(LOCALDECLLIST);
                    addChild(localDeclListNode,(yyvsp[(1) - (2)].node));
                    addChild(localDeclListNode,(yyvsp[(2) - (2)].node));
                    (yyval.node) = localDeclListNode;
                 ;}
    break;

  case 38:
#line 359 "src/parser.y"
    {
                    tree* varNode = maketree(VAR);
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(1) - (1)].strval));
                    addChild(varNode, idNode);
                    (yyval.node) = varNode;
                 ;}
    break;

  case 39:
#line 366 "src/parser.y"
    {
                    tree* varNode = maketree(VAR);
                    addChild(varNode, (yyvsp[(3) - (4)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(1) - (4)].strval));
                    addChild(varNode, idNode);
                    (yyval.node) = varNode;
                 ;}
    break;

  case 40:
#line 376 "src/parser.y"
    {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = addExprNode;
                 ;}
    break;

  case 41:
#line 382 "src/parser.y"
    {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, (yyvsp[(1) - (3)].node));
                    addChild(addExprNode, (yyvsp[(2) - (3)].node));
                    addChild(addExprNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = addExprNode;
                 ;}
    break;

  case 42:
#line 392 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, LTE);
                    (yyval.node) = relopNode;
                 ;}
    break;

  case 43:
#line 397 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, LT);
                    (yyval.node) = relopNode;
                 ;}
    break;

  case 44:
#line 402 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, GT);
                    (yyval.node) = relopNode;
                 ;}
    break;

  case 45:
#line 407 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, GTE);
                    (yyval.node) = relopNode;
                 ;}
    break;

  case 46:
#line 412 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, EQ);
                    (yyval.node) = relopNode;
                 ;}
    break;

  case 47:
#line 417 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, NEQ);
                    (yyval.node) = relopNode;
                 ;}
    break;

  case 48:
#line 424 "src/parser.y"
    {
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = expressionNode;
                 ;}
    break;

  case 49:
#line 430 "src/parser.y"
    {
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, (yyvsp[(1) - (3)].node));
                    addChild(expressionNode, (yyvsp[(2) - (3)].node));
                    addChild(expressionNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = expressionNode;
                 ;}
    break;

  case 50:
#line 440 "src/parser.y"
    {
                    tree* addopNode = maketreeWithIntVal(ADDOP,ADD);
                    (yyval.node) = addopNode;
                 ;}
    break;

  case 51:
#line 445 "src/parser.y"
    {
                    tree* addopNode = maketreeWithIntVal(ADDOP,SUB);
                    (yyval.node) = addopNode;
                 ;}
    break;

  case 52:
#line 452 "src/parser.y"
    {
                    tree* mulopNode = maketreeWithIntVal(MULOP,MUL);
                    (yyval.node) = mulopNode;
                 ;}
    break;

  case 53:
#line 457 "src/parser.y"
    {
                    tree* mulopNode = maketreeWithIntVal(MULOP,DIV);
                    (yyval.node) = mulopNode;
                 ;}
    break;

  case 54:
#line 463 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, (yyvsp[(2) - (3)].node));
                    (yyval.node) = factorNode;
                 ;}
    break;

  case 55:
#line 469 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = factorNode;
                 ;}
    break;

  case 56:
#line 475 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = factorNode;
                 ;}
    break;

  case 57:
#line 481 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    tree* integerNode = maketreeWithIntVal(INTEGER,(yyvsp[(1) - (1)].value));
                    addChild(factorNode,integerNode);
                    (yyval.node) = factorNode;
                 ;}
    break;

  case 58:
#line 488 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    tree* charNode = maketreeWithVal(CHAR,(yyvsp[(1) - (1)].strval));
                    addChild(factorNode,charNode);
                    (yyval.node) = factorNode;
                 ;}
    break;

  case 59:
#line 495 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    tree* strNode = maketreeWithVal(STRING, (yyvsp[(1) - (1)].strval));
                    addChild(factorNode, strNode);
                    (yyval.node) = factorNode;
                 ;}
    break;

  case 60:
#line 504 "src/parser.y"
    {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = termNode;
                 ;}
    break;

  case 61:
#line 510 "src/parser.y"
    {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, (yyvsp[(1) - (3)].node));
                    addChild(termNode, (yyvsp[(2) - (3)].node));
                    addChild(termNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = termNode;
                 ;}
    break;

  case 62:
#line 520 "src/parser.y"
    {
                    tree* funcCallExprNode = maketree(FUNCCALLEXPR);
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(1) - (4)].strval));
                    addChild(funcCallExprNode, idNode);
                    addChild(funcCallExprNode, (yyvsp[(3) - (4)].node));
                    (yyval.node) = funcCallExprNode;
                 ;}
    break;

  case 63:
#line 528 "src/parser.y"
    {
                    tree* funcCallExprNode = maketree(FUNCCALLEXPR);
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(1) - (3)].strval));
                    addChild(funcCallExprNode, idNode);
                    tree* emptyArgs = maketree(ARGLIST);  // if you want to represent no args explicitly
                    addChild(funcCallExprNode, emptyArgs);
                    (yyval.node) = funcCallExprNode;
                 ;}
    break;

  case 64:
#line 538 "src/parser.y"
    {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = argListNode;
                 ;}
    break;

  case 65:
#line 544 "src/parser.y"
    {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, (yyvsp[(1) - (3)].node));
                    addChild(argListNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = argListNode;
                 ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2137 "parser.tab.c"
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


#line 551 "src/parser.y"


int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(const char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}


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
     OPER_ADD = 270,
     OPER_SUB = 271,
     OPER_MUL = 272,
     OPER_DIV = 273,
     OPER_ASSN = 274,
     OPER_LT = 275,
     OPER_LTE = 276,
     OPER_EQ = 277,
     OPER_GTE = 278,
     OPER_GT = 279,
     OPER_NEQ = 280,
     OPER_ASGN = 281,
     LSQ_BRKT = 282,
     RSQ_BRKT = 283,
     LCRLY_BRKT = 284,
     RCRLY_BRKT = 285,
     LPAREN = 286,
     RPAREN = 287,
     COMMA = 288,
     SEMICLN = 289,
     ERROR = 290,
     ILLEGAL_TOKEN = 291
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
#define OPER_ADD 270
#define OPER_SUB 271
#define OPER_MUL 272
#define OPER_DIV 273
#define OPER_ASSN 274
#define OPER_LT 275
#define OPER_LTE 276
#define OPER_EQ 277
#define OPER_GTE 278
#define OPER_GT 279
#define OPER_NEQ 280
#define OPER_ASGN 281
#define LSQ_BRKT 282
#define RSQ_BRKT 283
#define LCRLY_BRKT 284
#define RCRLY_BRKT 285
#define LPAREN 286
#define RPAREN 287
#define COMMA 288
#define SEMICLN 289
#define ERROR 290
#define ILLEGAL_TOKEN 291




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <strtab.h>

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
#line 192 "obj/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 205 "obj/y.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    21,    25,
      27,    29,    31,    34,    39,    41,    45,    52,    58,    63,
      64,    67,    68,    71,    73,    75,    77,    79,    81,    85,
      90,    93,    99,   107,   113,   116,   120,   122,   127,   129,
     133,   135,   137,   139,   141,   143,   145,   147,   151,   153,
     155,   157,   161,   163,   165,   169,   171,   173,   175,   177,
     179,   184,   188,   190
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    40,    -1,    39,    40,    -1,
      41,    -1,    45,    -1,    42,     3,    27,     4,    28,    34,
      -1,    42,     3,    34,    -1,     7,    -1,     8,    -1,    10,
      -1,    42,     3,    -1,    42,     3,    27,    28,    -1,    43,
      -1,    43,    33,    44,    -1,    42,     3,    31,    44,    32,
      46,    -1,    42,     3,    31,    32,    46,    -1,    29,    47,
      48,    30,    -1,    -1,    41,    47,    -1,    -1,    49,    48,
      -1,    50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,
      -1,    29,    48,    30,    -1,    55,    19,    56,    34,    -1,
      56,    34,    -1,    12,    31,    56,    32,    49,    -1,    12,
      31,    56,    32,    49,    13,    49,    -1,    11,    31,    56,
      32,    49,    -1,    14,    34,    -1,    14,    56,    34,    -1,
       3,    -1,     3,    28,    58,    27,    -1,    58,    -1,    56,
      57,    58,    -1,    21,    -1,    20,    -1,    24,    -1,    23,
      -1,    22,    -1,    25,    -1,    60,    -1,    58,    59,    60,
      -1,    15,    -1,    16,    -1,    62,    -1,    60,    61,    62,
      -1,    17,    -1,    18,    -1,    31,    56,    32,    -1,    55,
      -1,    63,    -1,     4,    -1,     5,    -1,     6,    -1,     3,
      31,    64,    32,    -1,     3,    31,    32,    -1,    56,    -1,
      64,    33,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    79,    85,    94,   100,   107,   118,   128,
     133,   138,   144,   156,   169,   175,   183,   199,   214,   228,
     232,   241,   245,   253,   259,   265,   271,   277,   284,   293,
     300,   307,   314,   323,   331,   336,   343,   350,   359,   365,
     374,   379,   384,   389,   394,   399,   405,   411,   420,   425,
     431,   437,   446,   451,   457,   465,   471,   477,   484,   491,
     497,   505,   511,   517
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTCONST", "CHARCONST",
  "STRCONST", "KWD_INT", "KWD_CHAR", "KWD_STRING", "KWD_VOID", "KWD_WHILE",
  "KWD_IF", "KWD_ELSE", "KWD_RETURN", "OPER_ADD", "OPER_SUB", "OPER_MUL",
  "OPER_DIV", "OPER_ASSN", "OPER_LT", "OPER_LTE", "OPER_EQ", "OPER_GTE",
  "OPER_GT", "OPER_NEQ", "OPER_ASGN", "LSQ_BRKT", "RSQ_BRKT", "LCRLY_BRKT",
  "RCRLY_BRKT", "LPAREN", "RPAREN", "COMMA", "SEMICLN", "ERROR",
  "ILLEGAL_TOKEN", "$accept", "program", "declList", "decl", "varDecl",
  "typeSpecifier", "formalDecl", "formalDeclList", "funDecl", "funBody",
  "localDeclList", "statementList", "statement", "compoundStmt",
  "assignStmt", "condStmt", "loopStmt", "returnStmt", "var", "expression",
  "relop", "addExpr", "addop", "term", "mulop", "factor", "funcCallExpr",
  "argList", 0
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    50,    51,
      51,    52,    52,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     3,     1,
       1,     1,     2,     4,     1,     3,     6,     5,     4,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     3,     4,
       2,     5,     7,     5,     2,     3,     1,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       4,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,    11,     0,     2,     3,     5,     0,     6,
       1,     4,     0,     0,     0,     8,     0,     0,     0,    14,
       0,     0,    19,    17,    12,     0,     0,     7,    19,     0,
      21,     0,    15,    16,    20,     0,    36,    57,    58,    59,
       0,     0,     0,    21,     0,     0,    21,    23,    24,    25,
      26,    27,    55,     0,    38,    46,    50,    56,    13,     0,
       0,     0,     0,    34,    55,     0,     0,     0,    18,    22,
       0,    41,    40,    44,    43,    42,    45,    30,     0,    48,
      49,     0,    52,    53,     0,     0,    61,    62,     0,     0,
       0,    35,    28,    54,     0,    39,    47,    51,    37,    60,
       0,     0,     0,    29,    63,    33,    31,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    19,    20,     9,    23,
      30,    45,    46,    47,    48,    49,    50,    51,    64,    53,
      78,    54,    81,    55,    84,    56,    57,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -45
static const yytype_int16 yypact[] =
{
      87,   -45,   -45,   -45,     2,    87,   -45,   -45,    25,   -45,
     -45,   -45,    33,    41,    36,   -45,    65,    18,    60,    28,
      84,    97,    87,   -45,   105,    87,    18,   -45,    87,   130,
      19,   106,   -45,   -45,   -45,    15,   -14,   -45,   -45,   -45,
     107,   108,     1,    19,    35,   110,    19,   -45,   -45,   -45,
     -45,   -45,   116,    31,    11,    57,   -45,   -45,   -45,    35,
       5,    35,    35,   -45,   -45,    58,   111,    79,   -45,   -45,
      35,   -45,   -45,   -45,   -45,   -45,   -45,   -45,    35,   -45,
     -45,    35,   -45,   -45,    35,    42,   -45,   104,    81,    85,
      98,   -45,   -45,   -45,    64,    11,    57,   -45,   -45,   -45,
      35,    19,    19,   -45,   104,   -45,   123,    19,   -45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   -45,   132,   -10,    48,   -45,   117,   -45,   118,
     115,    69,   -11,   -45,   -45,   -45,   -45,   -45,   -30,   -41,
     -45,   -44,   -45,    66,   -45,    61,   -45,   -45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    65,    10,    67,    36,    37,    38,    39,    36,    37,
      38,    39,    28,    52,    59,    85,    52,    60,    28,    87,
      89,    90,    36,    37,    38,    39,    79,    80,    12,    94,
      40,    41,    44,    42,    95,    63,    44,    86,    36,    37,
      38,    39,    13,     1,     2,    16,     3,    22,    43,    15,
      44,    71,    72,    73,    74,    75,    76,    79,    80,   104,
      13,    25,    18,    24,    14,    77,    44,    15,    17,    98,
      29,    52,    52,    18,    82,    83,    29,    52,    71,    72,
      73,    74,    75,    76,    71,    72,    73,    74,    75,    76,
     105,   106,    91,    21,     1,     2,   108,     3,   103,    71,
      72,    73,    74,    75,    76,    71,    72,    73,    74,    75,
      76,    93,    66,    99,   100,    69,    26,   101,    71,    72,
      73,    74,    75,    76,    71,    72,    73,    74,    75,    76,
     102,    27,    31,    35,    58,    70,   107,    11,    61,    62,
      68,    92,    32,    34,    33,    97,     0,    96
};

static const yytype_int8 yycheck[] =
{
      30,    42,     0,    44,     3,     4,     5,     6,     3,     4,
       5,     6,    22,    43,    28,    59,    46,    31,    28,    60,
      61,    62,     3,     4,     5,     6,    15,    16,     3,    70,
      11,    12,    31,    14,    78,    34,    31,    32,     3,     4,
       5,     6,    27,     7,     8,     4,    10,    29,    29,    34,
      31,    20,    21,    22,    23,    24,    25,    15,    16,   100,
      27,    33,    14,     3,    31,    34,    31,    34,    32,    27,
      22,   101,   102,    25,    17,    18,    28,   107,    20,    21,
      22,    23,    24,    25,    20,    21,    22,    23,    24,    25,
     101,   102,    34,    28,     7,     8,   107,    10,    34,    20,
      21,    22,    23,    24,    25,    20,    21,    22,    23,    24,
      25,    32,    43,    32,    33,    46,    32,    32,    20,    21,
      22,    23,    24,    25,    20,    21,    22,    23,    24,    25,
      32,    34,    27,     3,    28,    19,    13,     5,    31,    31,
      30,    30,    25,    28,    26,    84,    -1,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    10,    38,    39,    40,    41,    42,    45,
       0,    40,     3,    27,    31,    34,     4,    32,    42,    43,
      44,    28,    29,    46,     3,    33,    32,    34,    41,    42,
      47,    27,    44,    46,    47,     3,     3,     4,     5,     6,
      11,    12,    14,    29,    31,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    58,    60,    62,    63,    28,    28,
      31,    31,    31,    34,    55,    56,    48,    56,    30,    48,
      19,    20,    21,    22,    23,    24,    25,    34,    57,    15,
      16,    59,    17,    18,    61,    58,    32,    56,    64,    56,
      56,    34,    30,    32,    56,    58,    60,    62,    27,    32,
      33,    32,    32,    34,    56,    49,    49,    13,    49
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
#line 72 "src/parser.y"
    {
                    tree* progNode = maketree(PROGRAM);
                    addChild(progNode, (yyvsp[(1) - (1)].node));
                    ast = progNode;
                 }
    break;

  case 3:
#line 80 "src/parser.y"
    {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = declListNode;
                 }
    break;

  case 4:
#line 86 "src/parser.y"
    {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[(1) - (2)].node));
                    addChild(declListNode, (yyvsp[(2) - (2)].node));
                    (yyval.node) = declListNode;
                 }
    break;

  case 5:
#line 95 "src/parser.y"
    {
                    tree* declNode = maketree(DECL);
                    addChild(declNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = declNode;
                 }
    break;

  case 6:
#line 101 "src/parser.y"
    {
                    tree* declNode = maketree(DECL);
                    addChild(declNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = declNode;
                 }
    break;

  case 7:
#line 108 "src/parser.y"
    {
                    ST_insert((yyvsp[(2) - (6)].strval),scope,(yyvsp[(1) - (6)].node)->val,ARRAY);
                    tree* varDeclNode = maketree(VARDECL);
                    addChild(varDeclNode, (yyvsp[(1) - (6)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(2) - (6)].strval));
                    addChild(varDeclNode, idNode);
                    tree* integerNode = maketreeWithIntVal(INTEGER,(yyvsp[(4) - (6)].value)); 
                    addChild(varDeclNode, integerNode);
                    (yyval.node) = varDeclNode;
                 }
    break;

  case 8:
#line 119 "src/parser.y"
    {
                    ST_insert((yyvsp[(2) - (3)].strval),scope,(yyvsp[(1) - (3)].node)->val,SCALAR);
                    tree* varDeclNode = maketree(VARDECL);
                    addChild(varDeclNode, (yyvsp[(1) - (3)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(2) - (3)].strval));
                    addChild(varDeclNode, idNode);
                    (yyval.node) = varDeclNode;
                 }
    break;

  case 9:
#line 129 "src/parser.y"
    {
                    tree* typeSpecNode = maketreeWithIntVal(TYPESPEC, INT_TYPE);
                    (yyval.node) = typeSpecNode;
                 }
    break;

  case 10:
#line 134 "src/parser.y"
    {
                    tree* typeSpecNode = maketreeWithIntVal(TYPESPEC, CHAR_TYPE);
                    (yyval.node) = typeSpecNode;
                 }
    break;

  case 11:
#line 139 "src/parser.y"
    {
                    tree* typeSpecNode = maketreeWithIntVal(TYPESPEC, VOID_TYPE);
                    (yyval.node) = typeSpecNode;
                 }
    break;

  case 12:
#line 145 "src/parser.y"
    {
                    ST_insert((yyvsp[(2) - (2)].strval), scope, (yyvsp[(1) - (2)].node)->val, SCALAR);
                    tree* formDeclNode = maketree(FORMALDECL);
                    addChild(formDeclNode, (yyvsp[(1) - (2)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(2) - (2)].strval));
                    addChild(formDeclNode, idNode);
                    (yyval.node) = formDeclNode;

                    add_param((yyvsp[(1) - (2)].node)->val, SCALAR);
                    param_count++;
                 }
    break;

  case 13:
#line 157 "src/parser.y"
    {
                    ST_insert((yyvsp[(2) - (4)].strval), scope, (yyvsp[(1) - (4)].node)->val, ARRAY);
                    tree* formDeclNode = maketree(FORMALDECL);
                    addChild(formDeclNode, (yyvsp[(1) - (4)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(2) - (4)].strval));
                    addChild(formDeclNode, idNode);
                    (yyval.node) = formDeclNode;

                    add_param((yyvsp[(1) - (4)].node)->val, ARRAY);
                    param_count++;
                 }
    break;

  case 14:
#line 170 "src/parser.y"
    {
                    tree* formDeclNode = maketree(FORMALDECLLIST);
                    addChild(formDeclNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = formDeclNode;
                 }
    break;

  case 15:
#line 176 "src/parser.y"
    {
                    tree* formDeclNode = maketree(FORMALDECLLIST);
                    addChild(formDeclNode, (yyvsp[(1) - (3)].node));
                    addChild(formDeclNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = formDeclNode;
                 }
    break;

  case 16:
#line 184 "src/parser.y"
    {
                    int index = ST_insert((yyvsp[(2) - (6)].strval), scope, (yyvsp[(1) - (6)].node)->val, FUNCTION);
                    scope = (yyvsp[(2) - (6)].strval);
                    connect_params(index, param_count);
                    param_count = 0;
                    scope = "";

                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, (yyvsp[(1) - (6)].node));
                    addChild(funDeclNode, (yyvsp[(4) - (6)].node));
                    addChild(funDeclNode, (yyvsp[(6) - (6)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(2) - (6)].strval));
                    addChild(funDeclNode, idNode);
                    (yyval.node) = funDeclNode;
                 }
    break;

  case 17:
#line 200 "src/parser.y"
    {
                    int index = ST_insert((yyvsp[(2) - (5)].strval), scope, (yyvsp[(1) - (5)].node)->val, FUNCTION);
                    scope = (yyvsp[(2) - (5)].strval);
                    connect_params(index, 0);
                    scope = "";

                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, (yyvsp[(1) - (5)].node));
                    addChild(funDeclNode, (yyvsp[(5) - (5)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(2) - (5)].strval));
                    addChild(funDeclNode, idNode);
                    (yyval.node) = funDeclNode;
                 }
    break;

  case 18:
#line 215 "src/parser.y"
    {
                    new_scope();  // Open a new scope for function body

                    tree* funBodyNode = maketree(FUNBODY);
                    addChild(funBodyNode, (yyvsp[(2) - (4)].node));
                    addChild(funBodyNode, (yyvsp[(3) - (4)].node));

                    up_scope();    // Close the scope at the end
                    scope = "";    // Reset to global
                    (yyval.node) = funBodyNode;
                }
    break;

  case 19:
#line 228 "src/parser.y"
    {
                    tree* localDeclListNode = maketree(LOCALDECLLIST);
                    (yyval.node) = localDeclListNode;
                 }
    break;

  case 20:
#line 233 "src/parser.y"
    {
                    tree* localDeclListNode = maketree(LOCALDECLLIST);
                    addChild(localDeclListNode,(yyvsp[(1) - (2)].node));
                    addChild(localDeclListNode,(yyvsp[(2) - (2)].node));
                    (yyval.node) = localDeclListNode;
                 }
    break;

  case 21:
#line 241 "src/parser.y"
    {
                    tree* statementListNode = maketree(STATEMENTLIST);
                    (yyval.node) = statementListNode;
                 }
    break;

  case 22:
#line 246 "src/parser.y"
    {
                    tree* statementListNode = maketree(STATEMENTLIST);
                    addChild(statementListNode, (yyvsp[(1) - (2)].node));
                    addChild(statementListNode, (yyvsp[(2) - (2)].node));
                    (yyval.node) = statementListNode;
                 }
    break;

  case 23:
#line 254 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 }
    break;

  case 24:
#line 260 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 }
    break;

  case 25:
#line 266 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 }
    break;

  case 26:
#line 272 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 }
    break;

  case 27:
#line 278 "src/parser.y"
    {
                    tree* statementNode = maketree(STATEMENT);
                    addChild(statementNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = statementNode;
                 }
    break;

  case 28:
#line 285 "src/parser.y"
    {
                    tree* compStmtNode = maketree(COMPOUNDSTMT);
                    tree *idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(1) - (3)].strval));
                    addCharChild(compStmtNode, idNode);
                    //addCharChild(compStmtNode, $1);
                    (yyval.node) = compStmtNode;
                 }
    break;

  case 29:
#line 294 "src/parser.y"
    {
                    tree* assignStmtNode = maketree(ASSIGNSTMT);
                    addChild(assignStmtNode, (yyvsp[(1) - (4)].node));
                    addChild(assignStmtNode, (yyvsp[(3) - (4)].node));
                    (yyval.node) = assignStmtNode;
                 }
    break;

  case 30:
#line 301 "src/parser.y"
    {
                    tree* assignStmtNode = maketree(ASSIGNSTMT);
                    addChild(assignStmtNode, (yyvsp[(1) - (2)].node));
                    (yyval.node) = assignStmtNode;
                 }
    break;

  case 31:
#line 308 "src/parser.y"
    {
                    tree* condStmtNode = maketree(CONDSTMT);
                    addChild(condStmtNode, (yyvsp[(3) - (5)].node));
                    addChild(condStmtNode, (yyvsp[(5) - (5)].node));
                    (yyval.node) = condStmtNode;
                 }
    break;

  case 32:
#line 315 "src/parser.y"
    {
                    tree* condStmtNode = maketree(CONDSTMT);
                    addChild(condStmtNode, (yyvsp[(3) - (7)].node));
                    addChild(condStmtNode, (yyvsp[(5) - (7)].node));
                    addChild(condStmtNode, (yyvsp[(7) - (7)].node));
                    (yyval.node) = condStmtNode;
                 }
    break;

  case 33:
#line 324 "src/parser.y"
    {
                    tree* loopStmtNode = maketree(LOOPSTMT);
                    addChild(loopStmtNode, (yyvsp[(3) - (5)].node));
                    addChild(loopStmtNode, (yyvsp[(5) - (5)].node));
                    (yyval.node) = loopStmtNode;
                 }
    break;

  case 34:
#line 332 "src/parser.y"
    {
                    tree* returnStmtNode = maketree(RETURNSTMT);
                    (yyval.node) = returnStmtNode;
                 }
    break;

  case 35:
#line 337 "src/parser.y"
    {
                    tree* returnStmtNode = maketree(RETURNSTMT);
                    addChild(returnStmtNode, (yyvsp[(2) - (3)].node));
                    (yyval.node) = returnStmtNode;
                 }
    break;

  case 36:
#line 344 "src/parser.y"
    {
                    tree* varNode = maketree(VAR);
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(1) - (1)].strval));
                    addChild(varNode, idNode);
                    (yyval.node) = varNode;
                 }
    break;

  case 37:
#line 351 "src/parser.y"
    {
                    tree* varNode = maketree(VAR);
                    addChild(varNode, (yyvsp[(3) - (4)].node));
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(1) - (4)].strval));
                    addChild(varNode, idNode);
                    (yyval.node) = varNode;
                 }
    break;

  case 38:
#line 360 "src/parser.y"
    {
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = expressionNode;
                 }
    break;

  case 39:
#line 366 "src/parser.y"
    {
                    tree* expressionNode = maketree(EXPRESSION);
                    addChild(expressionNode, (yyvsp[(1) - (3)].node));
                    addChild(expressionNode, (yyvsp[(2) - (3)].node));
                    addChild(expressionNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = expressionNode;
                 }
    break;

  case 40:
#line 375 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, LTE);
                    (yyval.node) = relopNode;
                 }
    break;

  case 41:
#line 380 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, LT);
                    (yyval.node) = relopNode;
                 }
    break;

  case 42:
#line 385 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, GT);
                    (yyval.node) = relopNode;
                 }
    break;

  case 43:
#line 390 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, GTE);
                    (yyval.node) = relopNode;
                 }
    break;

  case 44:
#line 395 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, EQ);
                    (yyval.node) = relopNode;
                 }
    break;

  case 45:
#line 400 "src/parser.y"
    {
                    tree* relopNode = maketreeWithIntVal(RELOP, NEQ);
                    (yyval.node) = relopNode;
                 }
    break;

  case 46:
#line 406 "src/parser.y"
    {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = addExprNode;
                 }
    break;

  case 47:
#line 412 "src/parser.y"
    {
                    tree* addExprNode = maketree(ADDEXPR);
                    addChild(addExprNode, (yyvsp[(1) - (3)].node));
                    addChild(addExprNode, (yyvsp[(2) - (3)].node));
                    addChild(addExprNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = addExprNode;
                 }
    break;

  case 48:
#line 421 "src/parser.y"
    {
                    tree* addopNode = maketreeWithIntVal(ADDOP,ADD);
                    (yyval.node) = addopNode;
                 }
    break;

  case 49:
#line 426 "src/parser.y"
    {
                    tree* addopNode = maketreeWithIntVal(ADDOP,SUB);
                    (yyval.node) = addopNode;
                 }
    break;

  case 50:
#line 432 "src/parser.y"
    {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = termNode;
                 }
    break;

  case 51:
#line 438 "src/parser.y"
    {
                    tree* termNode = maketree(TERM);
                    addChild(termNode, (yyvsp[(1) - (3)].node));
                    addChild(termNode, (yyvsp[(2) - (3)].node));
                    addChild(termNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = termNode;
                 }
    break;

  case 52:
#line 447 "src/parser.y"
    {
                    tree* mulopNode = maketreeWithIntVal(MULOP,MUL);
                    (yyval.node) = mulopNode;
                 }
    break;

  case 53:
#line 452 "src/parser.y"
    {
                    tree* mulopNode = maketreeWithIntVal(MULOP,DIV);
                    (yyval.node) = mulopNode;
                 }
    break;

  case 54:
#line 458 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    tree *idNode = maketreeWithVal(IDENTIFIER, (yyvsp[(1) - (3)].strval));
                    addCharChild(factorNode, idNode);
                    //addCharChild(factorNode, $1);
                    (yyval.node) = factorNode;
                 }
    break;

  case 55:
#line 466 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = factorNode;
                 }
    break;

  case 56:
#line 472 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    addChild(factorNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = factorNode;
                 }
    break;

  case 57:
#line 478 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    tree* integerNode = maketreeWithIntVal(INTEGER,(yyvsp[(1) - (1)].value));
                    addChild(factorNode,integerNode);
                    (yyval.node) = factorNode;
                 }
    break;

  case 58:
#line 485 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    tree* charNode = maketreeWithVal(CHAR,(yyvsp[(1) - (1)].strval));
                    addChild(factorNode,charNode);
                    (yyval.node) = factorNode;
                 }
    break;

  case 59:
#line 492 "src/parser.y"
    {
                    tree* factorNode = maketree(FACTOR);
                    (yyval.node) = factorNode;
                 }
    break;

  case 60:
#line 498 "src/parser.y"
    {
                    tree* funcCallExprNode = maketree(FUNCCALLEXPR);
                    tree* idNode = maketreeWithVal(IDENTIFIER,(yyvsp[(2) - (4)].strval));
                    addChild(funcCallExprNode, idNode);
                    addChild(funcCallExprNode, (yyvsp[(3) - (4)].node));
                    (yyval.node) = funcCallExprNode;
                 }
    break;

  case 61:
#line 506 "src/parser.y"
    {
                    tree* funcCallExprNode = maketree(FUNCCALLEXPR);
                    (yyval.node) = funcCallExprNode;
                 }
    break;

  case 62:
#line 512 "src/parser.y"
    {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = argListNode;
                 }
    break;

  case 63:
#line 518 "src/parser.y"
    {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, (yyvsp[(1) - (3)].node));
                    addChild(argListNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = argListNode;
                 }
    break;


/* Line 1267 of yacc.c.  */
#line 2117 "obj/y.tab.c"
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


#line 525 "src/parser.y"


int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(const char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}


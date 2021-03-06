/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         config_fz_parse
#define yylex           config_fz_lex
#define yyerror         config_fz_error
#define yylval          config_fz_lval
#define yychar          config_fz_char
#define yydebug         config_fz_debug
#define yynerrs         config_fz_nerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "configs/config_fz_parser.y"

//#define YYDEBUG 1

#include <libfrozen.h>
#include <configs/config.h>
#include <configs/config_fz_parser.tab.h>	

typedef enum fz_keyword {
	KEYWORD_LOCAL  = 1,
	KEYWORD_GLOBAL = 2,
} fz_keyword;

keypair_t fz_keywords[] = {
	{ "local",  KEYWORD_LOCAL  },
	{ "global", KEYWORD_GLOBAL },
	{ NULL, 0 }
};

static void          yyerror(hash_t **, const char *);
static ssize_t       config_fz_keyword(uintmax_t *keyword, char *string);
//static ssize_t       config_fz_keyword_validate(uintmax_t *pkeyword);

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE config__scan_string (const char *string);  
extern int config_lex_destroy(void);
extern int config_lex(YYSTYPE *);
extern int config_get_lineno(void);
extern char *config_get_text(void);

#define emit_error(fmt, ...){                                               \
	do {                                                                \
		char _buffer[DEF_BUFFER_SIZE];                              \
		                                                            \
		snprintf(_buffer, sizeof(_buffer) - 1, fmt, ##__VA_ARGS__); \
		_buffer[sizeof(_buffer) - 1] = '\0';                        \
		yyerror(hash, _buffer);                                     \
		YYERROR;                                                    \
	}while(0); }

#define config_fz_lex config_lex



/* Line 189 of yacc.c  */
#line 124 "configs/config_fz_parser.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     STRING = 259,
     DIGITS = 260,
     ASSIGN = 261,
     TNULL = 262,
     KEYWORD = 263,
     SUB = 264
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 49 "configs/config_fz_parser.y"

	hash_t     *hash_items;
	hash_t      hash_item;
	
	char       *name;
	data_t      data;
	
	machine_t  *pipeline;
	hash_t     *pipeline_config;

	action_t    action;
	hashkey_t   hashkey;
	datatype_t  datatype;
	uintmax_t   keyword;



/* Line 214 of yacc.c  */
#line 187 "configs/config_fz_parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 199 "configs/config_fz_parser.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  97

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   264

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,     2,    24,     2,     2,     2,
      16,    17,     2,     2,    18,     2,    15,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    11,    13,
       2,     2,    12,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,    14,    20,    10,     2,     2,     2,
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
       5,     6,     7,     8,     9
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    20,
      22,    25,    29,    31,    33,    35,    39,    46,    48,    50,
      54,    58,    60,    62,    64,    66,    68,    70,    72,    74,
      76,    78,    80,    82,    84,    86,    88,    90,    94,    99,
     104,   110,   112,   115,   117,   119,   123,   129,   137,   139,
     141,   143,   146,   147,   149,   153,   155,   159
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      26,     0,    -1,    -1,    27,    -1,    28,    -1,    27,    28,
      -1,    29,    -1,    46,    -1,    58,     3,     6,    38,    -1,
      31,    -1,    32,    13,    -1,    31,    32,    13,    -1,    34,
      -1,    35,    -1,    33,    -1,    38,    14,    38,    -1,    38,
      15,    52,    16,    56,    17,    -1,    36,    -1,    37,    -1,
      36,    18,    37,    -1,    55,     6,    38,    -1,    39,    -1,
      51,    -1,    41,    -1,    42,    -1,    43,    -1,    45,    -1,
      44,    -1,    47,    -1,    50,    -1,    46,    -1,    39,    -1,
      51,    -1,     3,    -1,    55,    -1,     4,    -1,     5,    -1,
      19,    56,    20,    -1,     9,    19,    30,    20,    -1,    39,
      21,    48,    22,    -1,    39,    21,    23,    48,    22,    -1,
      49,    -1,    48,    49,    -1,    54,    -1,    44,    -1,    53,
      11,    39,    -1,     3,    10,    39,    12,    40,    -1,    53,
      11,    19,    56,    20,    12,    40,    -1,     3,    -1,     3,
      -1,     3,    -1,    24,    54,    -1,    -1,    57,    -1,    56,
      18,    57,    -1,    38,    -1,    54,     6,    38,    -1,     8,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   113,   118,   119,   122,   126,   134,   147,
     154,   159,   169,   170,   171,   175,   196,   216,   227,   228,
     231,   236,   237,   241,   242,   243,   244,   245,   246,   247,
     248,   252,   253,   258,   268,   276,   289,   297,   303,   306,
     313,   322,   323,   326,   334,   341,   362,   400,   424,   436,
     449,   461,   464,   465,   466,   469,   473,   480
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "DIGITS", "ASSIGN",
  "TNULL", "KEYWORD", "SUB", "'~'", "':'", "'>'", "';'", "'|'", "'.'",
  "'('", "')'", "','", "'{'", "'}'", "'['", "']'", "'!'", "'$'", "$accept",
  "start", "statements", "statement", "statement_named_data", "pipeline",
  "pipeline_raw", "pipeline_machine", "pipeline_machine_enum",
  "pipeline_machine_query", "pipeline_machine_assign",
  "pipeline_machine_assign_items", "pipeline_machine_assign_item", "data",
  "data_simple", "data_complex", "named_t", "env_t", "string_t", "uint_t",
  "hash_t", "subroutine", "inner_t", "inner_t_keys", "inner_t_key",
  "data_converted", "data_complex_rules", "action_t", "datatype_t",
  "hashkey_t", "env_t_key", "hash_items", "hash_item", "keyword", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     126,    58,    62,    59,   124,    46,    40,    41,    44,   123,
     125,    91,    93,    33,    36
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    25,    26,    26,    27,    27,    28,    28,    29,    30,
      31,    31,    32,    32,    32,    33,    34,    35,    36,    36,
      37,    38,    38,    39,    39,    39,    39,    39,    39,    39,
      39,    40,    40,    41,    42,    43,    44,    45,    46,    47,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    53,
      54,    55,    56,    56,    56,    57,    57,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     4,     1,
       2,     3,     1,     1,     1,     3,     6,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       5,     1,     2,     1,     1,     3,     5,     7,     1,     1,
       1,     2,     0,     1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    57,     0,     0,     3,     4,     6,     7,     0,     0,
       1,     5,     0,    33,    35,    36,    52,     0,     0,     9,
       0,    14,    12,    13,    17,    18,     0,    21,    23,    24,
      25,    27,    26,    30,    28,    29,    22,     0,    34,     0,
       0,    33,    55,     0,    34,     0,    53,    50,    51,    38,
       0,    10,     0,     0,     0,     0,     0,     0,     8,    33,
       0,     0,     0,     0,    37,    11,    19,     0,    15,    48,
       0,     0,    44,     0,    41,    43,    52,    45,    20,     0,
       0,    56,    54,    52,     0,    39,    42,     0,    31,    46,
      32,     0,    40,    37,    16,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    18,    19,    20,    21,    22,
      23,    24,    25,    42,    27,    89,    28,    29,    30,    31,
      32,    33,    34,    73,    74,    35,    36,    70,    37,    43,
      44,    45,    46,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int8 yypact[] =
{
      62,   -68,    -9,    31,    62,   -68,   -68,   -68,    13,     4,
     -68,   -68,    41,    75,   -68,   -68,    21,    71,    74,     4,
      78,   -68,   -68,   -68,    77,   -68,    73,    79,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,    81,    87,     4,
      56,    66,   -68,    90,   -68,    16,   -68,   -68,   -68,   -68,
      84,   -68,    80,     4,    95,     9,    59,     4,   -68,    88,
      27,    91,     4,    21,   -68,   -68,   -68,    87,   -68,   -68,
      85,    76,   -68,    24,   -68,   -68,    21,    79,   -68,     4,
      56,   -68,   -68,    21,    47,   -68,   -68,    64,    79,   -68,
     -68,    72,   -68,    93,   -68,     4,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -68,    99,   -68,   -68,   -68,    89,   -68,   -68,
     -68,   -68,    54,    -4,   -38,    12,   -68,   -68,   -68,   -51,
     -68,    51,   -68,    38,   -67,   -68,   -58,   -68,   -37,   -17,
      -8,   -10,    48,   -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int8 yytable[] =
{
      48,    38,    60,    61,    72,    26,    86,    13,    14,    15,
       9,    38,    47,     2,    15,    26,    12,    86,    77,    61,
      72,    90,    72,    16,    41,    14,    15,    47,    17,    15,
       2,    10,    71,    72,    63,    58,    64,    90,    75,    79,
      16,    88,    77,    61,    67,    17,    85,    39,    55,    68,
      47,     7,    15,    78,    75,     7,    75,    88,    81,    59,
      14,    15,    59,    14,    15,     2,    87,    75,     2,    92,
       1,     2,   -50,    91,    47,    16,    40,   -49,    76,    47,
      17,    15,    63,    17,    93,    40,   -49,    53,    54,    94,
      63,    51,    56,    57,    49,    52,    62,    65,    69,   -49,
      55,    83,    80,    11,    17,    95,    66,    96,    50,    84,
       0,    82
};

static const yytype_int8 yycheck[] =
{
      17,     9,    40,    40,    55,     9,    73,     3,     4,     5,
      19,    19,     3,     9,     5,    19,     3,    84,    56,    56,
      71,    79,    73,    19,     3,     4,     5,     3,    24,     5,
       9,     0,    23,    84,    18,    39,    20,    95,    55,    12,
      19,    79,    80,    80,    52,    24,    22,     6,    21,    53,
       3,     0,     5,    57,    71,     4,    73,    95,    62,     3,
       4,     5,     3,     4,     5,     9,    76,    84,     9,    22,
       8,     9,     6,    83,     3,    19,    10,    11,    19,     3,
      24,     5,    18,    24,    20,    10,    11,    14,    15,    17,
      18,    13,    11,     6,    20,    18,     6,    13,     3,    11,
      21,    16,    11,     4,    24,    12,    52,    95,    19,    71,
      -1,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    26,    27,    28,    29,    46,    58,    19,
       0,    28,     3,     3,     4,     5,    19,    24,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    41,    42,
      43,    44,    45,    46,    47,    50,    51,    53,    55,     6,
      10,     3,    38,    54,    55,    56,    57,     3,    54,    20,
      32,    13,    18,    14,    15,    21,    11,     6,    38,     3,
      39,    53,     6,    18,    20,    13,    37,    55,    38,     3,
      52,    23,    44,    48,    49,    54,    19,    39,    38,    12,
      11,    38,    57,    16,    48,    22,    49,    56,    39,    40,
      51,    56,    22,    20,    17,    12,    40
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (hash, YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
		  Type, Value, hash); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, hash_t **hash)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, hash)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    hash_t **hash;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (hash);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, hash_t **hash)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, hash)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    hash_t **hash;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, hash);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, hash_t **hash)
#else
static void
yy_reduce_print (yyvsp, yyrule, hash)
    YYSTYPE *yyvsp;
    int yyrule;
    hash_t **hash;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , hash);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, hash); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, hash_t **hash)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, hash)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    hash_t **hash;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (hash);

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
int yyparse (hash_t **hash);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
yyparse (hash_t **hash)
#else
int
yyparse (hash)
    hash_t **hash;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1464 of yacc.c  */
#line 112 "configs/config_fz_parser.y"
    { *hash = hash_new(1); ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 113 "configs/config_fz_parser.y"
    { *hash = (yyvsp[(1) - (1)].hash_items); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 118 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_new(2); hash_assign_hash_t(&(yyval.hash_items)[0], &(yyvsp[(1) - (1)].hash_item)); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 119 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_append((yyvsp[(1) - (2)].hash_items), (yyvsp[(2) - (2)].hash_item)); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 122 "configs/config_fz_parser.y"
    {
		(yyval.hash_item).key  = HK(data);
		(yyval.hash_item).data = (yyvsp[(1) - (1)].data);
	;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 126 "configs/config_fz_parser.y"
    {
		(yyval.hash_item).key  = HK(machine);
		(yyval.hash_item).data = (yyvsp[(1) - (1)].data);
	;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 134 "configs/config_fz_parser.y"
    {
		ssize_t           ret;
		
		if( (ret = data_named_t(&(yyval.data), (yyvsp[(2) - (4)].name), (yyvsp[(4) - (4)].data))) < 0)
			emit_error("data init failed (ret: %s)", errors_describe(ret));
		
		free((yyvsp[(2) - (4)].name));
	;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 147 "configs/config_fz_parser.y"
    {
		(yyval.data).type = TYPE_MACHINET;
		(yyval.data).ptr  = pipeline_finalize(&(yyvsp[(1) - (1)].pipeline));
	;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 154 "configs/config_fz_parser.y"
    {
		pipeline_new(&(yyval.pipeline));
		pipeline_append(&(yyval.pipeline), (yyvsp[(1) - (2)].pipeline_config));
		hash_free((yyvsp[(1) - (2)].pipeline_config));
	;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 159 "configs/config_fz_parser.y"
    {
		(yyval.pipeline) = (yyvsp[(1) - (3)].pipeline);
		pipeline_append(&(yyval.pipeline), (yyvsp[(2) - (3)].pipeline_config));
		hash_free((yyvsp[(2) - (3)].pipeline_config));
	;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 175 "configs/config_fz_parser.y"
    {
		data_t  d_action;
		data_action_t(&d_action, ACTION_ENUM);
		
		hash_t *r_request = hash_new(3);
		r_request[0].key  = HK(action);
		r_request[0].data = d_action;
		r_request[1].key  = HK(data);
		r_request[1].data = (yyvsp[(3) - (3)].data);
		
		hash_t r_config[] = {
			{ HK(class),   DATA_PTR_STRING(strdup("data/query"))  },
			{ HK(data),    (yyvsp[(1) - (3)].data)                                     },
			{ HK(request), DATA_PTR_HASHT(r_request)              },
			hash_end
		};
		(yyval.pipeline_config) = hash_rebuild(r_config);
	;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 196 "configs/config_fz_parser.y"
    {
		data_t  d_action;
		data_action_t(&d_action, (yyvsp[(3) - (6)].action));
		
		hash_t *r_request = hash_new(3);
		r_request[0].key  = HK(action);
		r_request[0].data = d_action;
		hash_assign_hash_inline(&r_request[1], (yyvsp[(5) - (6)].hash_items));
		
		hash_t r_config[] = {
			{ HK(class),   DATA_PTR_STRING(strdup("data/query"))  },
			{ HK(data),    (yyvsp[(1) - (6)].data)                                     },
			{ HK(list),    DATA_HEAP_UINTT(1)                     },
			{ HK(request), DATA_PTR_HASHT(r_request)              },
			hash_end
		};
		(yyval.pipeline_config) = hash_rebuild(r_config);
	;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 216 "configs/config_fz_parser.y"
    {
		hash_t r_config[] = {
			{ HK(class),   DATA_PTR_STRING(strdup("assign"))      },
			{ HK(before),  DATA_PTR_HASHT((yyvsp[(1) - (1)].hash_items))                     },
			hash_end
		};
		(yyval.pipeline_config) = hash_rebuild(r_config);
	;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 227 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_new(2); hash_assign_hash_t(&(yyval.hash_items)[0], &(yyvsp[(1) - (1)].hash_item)); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 228 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_append((yyvsp[(1) - (3)].hash_items), (yyvsp[(3) - (3)].hash_item)); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 231 "configs/config_fz_parser.y"
    { (yyval.hash_item).key  = (yyvsp[(1) - (3)].hashkey); (yyval.hash_item).data = (yyvsp[(3) - (3)].data); ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 258 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		data_t                 d_void            = DATA_VOID;
		
		if( (ret = data_named_t(&(yyval.data), (yyvsp[(1) - (1)].name), d_void)) < 0)
			emit_error("data init failed (ret: %s)", errors_describe(ret));
		
		free((yyvsp[(1) - (1)].name));
	;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 268 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		
		if( (ret = data_env_t(&(yyval.data), (yyvsp[(1) - (1)].hashkey))) < 0)
			emit_error("data init failed (ret: %s)", errors_describe(ret));
	;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 276 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		data_t                 d_initstr         = DATA_PTR_STRING((yyvsp[(1) - (1)].name));
		
		data_raw_t_empty(&(yyval.data));
		
		fastcall_convert_from r_init_str = { { 5, ACTION_CONVERT_FROM }, &d_initstr, FORMAT(config) }; 
		if( (ret = data_query(&(yyval.data), &r_init_str)) < 0)
			emit_error("value init failed from string (ret: %s)", errors_describe(ret));
		
		free((yyvsp[(1) - (1)].name));
	;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 289 "configs/config_fz_parser.y"
    {
		uintmax_t              value             = strtoul((yyvsp[(1) - (1)].name), NULL, 10);
		data_t                 d_uint            = DATA_HEAP_UINTT(value);
		
		(yyval.data) = d_uint;
		free((yyvsp[(1) - (1)].name));
	;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 297 "configs/config_fz_parser.y"
    {
		(yyval.data).type = TYPE_HASHT;
		(yyval.data).ptr = (yyvsp[(2) - (3)].hash_items);
	;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 303 "configs/config_fz_parser.y"
    { (yyval.data) = (yyvsp[(3) - (4)].data); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 306 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		data_t                 d_keys            = DATA_PTR_HASHT((yyvsp[(3) - (4)].hash_items));
		
		if( (ret = data_inner_t(&(yyval.data), (yyvsp[(1) - (4)].data), d_keys, 0)) < 0)
			emit_error("inner init failed (ret: %s)", errors_describe(ret));
	;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 313 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		data_t                 d_keys            = DATA_PTR_HASHT((yyvsp[(4) - (5)].hash_items));
		
		if( (ret = data_inner_t(&(yyval.data), (yyvsp[(1) - (5)].data), d_keys, 1)) < 0)
			emit_error("inner init failed (ret: %s)", errors_describe(ret));
	;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 322 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_new(2); hash_assign_hash_t(&(yyval.hash_items)[0], &(yyvsp[(1) - (1)].hash_item)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 323 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_append((yyvsp[(1) - (2)].hash_items), (yyvsp[(2) - (2)].hash_item)); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 326 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		
		if( (ret = data_hashkey_t(&(yyval.hash_item).data, (yyvsp[(1) - (1)].hashkey))) < 0)
			emit_error("hashkey init failed (ret: %s)", errors_describe(ret));

		(yyval.hash_item).key = 0;
	;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 334 "configs/config_fz_parser.y"
    {
		(yyval.hash_item).key  = 0;
		(yyval.hash_item).data = (yyvsp[(1) - (1)].data);
	;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 341 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		
		(yyval.data).type = (yyvsp[(1) - (3)].datatype);
		(yyval.data).ptr  = NULL;
		
		/* convert string to needed data */
		fastcall_convert_from r_convert = {
			{ 5, ACTION_CONVERT_FROM },
			&(yyvsp[(3) - (3)].data),
			((yyvsp[(3) - (3)].data).type == TYPE_HASHT) ?
				FORMAT(hash) :
				FORMAT(config)
		}; 
		if( (ret = data_query(&(yyval.data), &r_convert)) < 0)
			emit_error("value init failed (ret: %s)", errors_describe(ret));
		
		data_free(&(yyvsp[(3) - (3)].data));
	;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 362 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		char                  *triplet_type_str      = NULL;
		
		triplet_type_str = calloc(1, strlen((yyvsp[(1) - (5)].name)) + 8 + 2 + 1);
		strcat(triplet_type_str, "triplet_");
		strcat(triplet_type_str, (yyvsp[(1) - (5)].name));
		strcat(triplet_type_str, "_t");
		
		datatype_t             type;
		data_t                 d_type            = DATA_PTR_DATATYPET(&type);
		data_t                 d_type_str        = DATA_PTR_STRING(triplet_type_str);
		
		fastcall_convert_from r_convert = { { 5, ACTION_CONVERT_FROM }, &d_type_str, FORMAT(config) }; 
		if( (ret = data_query(&d_type, &r_convert)) < 0)
			emit_error("unknown triplet datatype_t \"%s\" (ret: %s)", triplet_type_str, errors_describe(ret));
		
		free(triplet_type_str);
		
		hash_t                 r_triplet_config[] = {
			{ HK(data),  (yyvsp[(5) - (5)].data) },
			{ HK(slave), (yyvsp[(3) - (5)].data) },
			hash_end
		};
		data_t                 d_triplet_config  = DATA_PTR_HASHT(r_triplet_config);
		
		(yyval.data).type = type;
		(yyval.data).ptr  = NULL;
		
		/* convert string to needed data */
		fastcall_convert_from r_convert_triplet = { { 5, ACTION_CONVERT_FROM }, &d_triplet_config, FORMAT(hash) }; 
		if( (ret = data_query(&(yyval.data), &r_convert_triplet)) < 0)
			emit_error("triplet data init failed (ret: %s)", errors_describe(ret));
		
		data_free(&r_triplet_config[0].data);
		data_free(&r_triplet_config[1].data);
		free((yyvsp[(1) - (5)].name));
	;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 400 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		hash_t                 r_hash[] = {
			{ HK(data), (yyvsp[(7) - (7)].data) },
			hash_inline((yyvsp[(4) - (7)].hash_items)),
			hash_end
		};
		data_t                 d_hash            = DATA_PTR_HASHT(hash_rebuild(r_hash));
		
		(yyval.data).type = (yyvsp[(1) - (7)].datatype);
		(yyval.data).ptr  = NULL;
		
		/* convert string to needed data */
		fastcall_convert_from r_convert = { { 5, ACTION_CONVERT_FROM }, &d_hash, FORMAT(hash) }; 
		if( (ret = data_query(&(yyval.data), &r_convert)) < 0)
			emit_error("proxy data init failed (ret: %s)", errors_describe(ret));
		
		data_free(&d_hash);
		data_free(&r_hash[0].data);
	;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 424 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		data_t                 d_action          = DATA_PTR_ACTIONT(&(yyval.action));
		data_t                 d_initstr         = DATA_PTR_STRING((yyvsp[(1) - (1)].name));
		
		fastcall_convert_from r_convert = { { 5, ACTION_CONVERT_FROM }, &d_initstr, FORMAT(config) }; 
		if( (ret = data_query(&d_action, &r_convert)) < 0)
			emit_error("unknown action \"%s\" (ret: %s)", (yyvsp[(1) - (1)].name), errors_describe(ret));
		
		free((yyvsp[(1) - (1)].name));
	;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 436 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		data_t                 d_type            = DATA_PTR_DATATYPET(&(yyval.datatype));
		data_t                 d_type_initstr    = DATA_PTR_STRING((yyvsp[(1) - (1)].name));
		
		fastcall_convert_from r_convert = { { 5, ACTION_CONVERT_FROM }, &d_type_initstr, FORMAT(config) }; 
		if( (ret = data_query(&d_type, &r_convert)) < 0)
			emit_error("unknown datatype_t \"%s\" (ret: %s)", (yyvsp[(1) - (1)].name), errors_describe(ret));
		
		free((yyvsp[(1) - (1)].name));
	;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 449 "configs/config_fz_parser.y"
    {
		ssize_t                ret;
		data_t                 d_key             = DATA_PTR_HASHKEYT(&(yyval.hashkey));
		data_t                 d_initstr         = DATA_PTR_STRING((yyvsp[(1) - (1)].name));
		
		fastcall_convert_from r_convert = { { 5, ACTION_CONVERT_FROM }, &d_initstr, FORMAT(config) }; 
		if( (ret = data_query(&d_key, &r_convert)) < 0)
			emit_error("unknown hashkey_t \"%s\" (ret: %s)", (yyvsp[(1) - (1)].name), errors_describe(ret));
		
		free((yyvsp[(1) - (1)].name));
	;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 461 "configs/config_fz_parser.y"
    { (yyval.hashkey) = (yyvsp[(2) - (2)].hashkey); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 464 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_new(1); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 465 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_new(2); hash_assign_hash_t(&(yyval.hash_items)[0], &(yyvsp[(1) - (1)].hash_item)); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 466 "configs/config_fz_parser.y"
    { (yyval.hash_items) = hash_append((yyvsp[(1) - (3)].hash_items), (yyvsp[(3) - (3)].hash_item)); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 469 "configs/config_fz_parser.y"
    {
		(yyval.hash_item).key  = 0;
		(yyval.hash_item).data = (yyvsp[(1) - (1)].data);
	;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 473 "configs/config_fz_parser.y"
    {
		(yyval.hash_item).key  = (yyvsp[(1) - (3)].hashkey);
		(yyval.hash_item).data = (yyvsp[(3) - (3)].data);
	;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 480 "configs/config_fz_parser.y"
    {
		if(config_fz_keyword(&(yyval.keyword), (yyvsp[(1) - (1)].name)) < 0)
			emit_error("unknown keyword \"%s\"", (yyvsp[(1) - (1)].name));
			
		free((yyvsp[(1) - (1)].name));
	;}
    break;



/* Line 1464 of yacc.c  */
#line 2015 "configs/config_fz_parser.tab.c"
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
      yyerror (hash, YY_("syntax error"));
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
	    yyerror (hash, yymsg);
	  }
	else
	  {
	    yyerror (hash, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
		      yytoken, &yylval, hash);
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
		  yystos[yystate], yyvsp, hash);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (hash, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, hash);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, hash);
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



/* Line 1684 of yacc.c  */
#line 489 "configs/config_fz_parser.y"


/*
	| KEYWORD keyword {
		ssize_t                ret;
		
		if(config_fz_keyword(&$$, $1) < 0)
			emit_error("unknown keyword \"%s\"", $1);
			
		free($1);
		
		$$ |= $2;
		if( (ret = config_fz_keyword_validate(&$$)) < 0)
			emit_error("invalid keyword combination (ret: %s)", errors_describe(ret));
	};*/

static void    yyerror(hash_t **hash, const char *msg){ // {{{
	char                  *file              = config_ext_file; 
	
	if(!file)
		file = "-";
	
	fprintf(stderr, "%s: error: %d: %s\n", file, config_get_lineno(), msg);
	(void)hash;
} // }}}
static ssize_t config_fz_keyword(uintmax_t *keyword, char *string){ // {{{
	keypair_t             *kp;
	
	for(kp = fz_keywords; kp->key_str; kp++){
		if(strcasecmp(string, kp->key_str) == 0){
			*keyword = kp->key_val;
			return 0;
		}
	}
	return -EINVAL;
} // }}}
/*static ssize_t config_fz_keyword_validate(uintmax_t *pkeyword){ // {{{
	uintmax_t             keyword           = *pkeyword;
	
	// local/global
	if((keyword & KEYWORD_GLOBAL) != 0){ keyword &= ~KEYWORD_LOCAL; };
	
	*pkeyword = keyword;
	return 0;
} // }}}*/

hash_t *       configs_fz_string_parse(char *string){ // {{{
	hash_t *new_hash = NULL;
	
	#if YYDEBUG
	yydebug = 1;
	#endif

	config__scan_string(string);
	
	yyparse(&new_hash);
	
	config_lex_destroy();
	return new_hash;
} // }}}



/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "ucparse.yy"

/**
 **	Ucparse.y - Usecode parser.
 **
 **	Written: 12/30/2000 - JSF
 **/

/*
Copyright (C) 2000 The Exult Team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <cstring>

#include "ucfun.h"
#include "ucclass.h"
#include "ucexpr.h"
#include "ucstmt.h"
#include "opcodes.h"
#include "ucscriptop.h"

using std::strcpy;
using std::strcat;
using std::strlen;
using std::string;

void yyerror(const char *);
void yywarning(const char *);
extern int yylex();
extern void start_script(), end_script();
extern void start_loop(), end_loop();
extern void start_breakable(), end_breakable();
extern void start_fun_id(), end_fun_id();
static Uc_array_expression *Create_array(int, Uc_expression *);
static Uc_array_expression *Create_array(int, Uc_expression *, 
							Uc_expression *);
static Uc_class *Find_class(const char *nm);
static bool Class_unexpected_error(Uc_expression *expr);
static bool Nonclass_unexpected_error(Uc_expression *expr);
static bool Incompatible_classes_error(Uc_class *src, Uc_class *trg);
static Uc_call_expression *cls_method_call(Uc_expression *cls, Uc_class *curcls,
		Uc_class *clsscope, char *nm, Uc_array_expression *parms);
static Uc_call_expression *cls_function_call(Uc_expression *ths,
		Uc_class *curcls, char *nm, bool original, Uc_array_expression *parms);


#define YYERROR_VERBOSE 1

std::vector<Uc_design_unit *> units;	// THIS is what we produce.

static Uc_function *cur_fun = 0;	// Current function being parsed.
static Uc_class *cur_class = 0;		// ...or, current class being parsed.
static Uc_struct_symbol *cur_struct = 0;		// ...or, current struct being parsed.
static int enum_val = -1;		// Keeps track of enum elements.
static bool is_extern = false;	// Marks a function symbol as being an extern
static Uc_class *class_type = 0;	// For declaration of class variables.
static Uc_struct_symbol *struct_type = 0;	// For declaration of struct variables.
static bool has_ret = false;
static int repeat_nesting = 0;
static std::vector<int> const_opcode;
static int converse = 0;	// If we are in a converse block.

struct Fun_id_info
	{
	Uc_function_symbol::Function_kind kind;
	int id;
	Fun_id_info(Uc_function_symbol::Function_kind k, int i)
		: kind(k), id(i)
		{  }
	};

struct Member_selector
	{
	Uc_expression *expr;
	char *name;
	Member_selector(Uc_expression *e, char *n)
		: expr(e), name(n)
		{  }
	};



/* Line 189 of yacc.c  */
#line 178 "ucparse.cc"

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
     IF = 258,
     ELSE = 259,
     RETURN = 260,
     DO = 261,
     WHILE = 262,
     FOR = 263,
     UCC_IN = 264,
     WITH = 265,
     TO = 266,
     EXTERN = 267,
     BREAK = 268,
     GOTO = 269,
     CASE = 270,
     VAR = 271,
     VOID = 272,
     ALIAS = 273,
     STRUCT = 274,
     UCC_CHAR = 275,
     UCC_INT = 276,
     UCC_LONG = 277,
     UCC_CONST = 278,
     STRING = 279,
     ENUM = 280,
     CONVERSE = 281,
     NESTED = 282,
     SAY = 283,
     MESSAGE = 284,
     RESPONSE = 285,
     EVENT = 286,
     FLAG = 287,
     ITEM = 288,
     UCTRUE = 289,
     UCFALSE = 290,
     REMOVE = 291,
     ADD = 292,
     HIDE = 293,
     SCRIPT = 294,
     AFTER = 295,
     TICKS = 296,
     STATIC_ = 297,
     ORIGINAL = 298,
     SHAPENUM = 299,
     OBJECTNUM = 300,
     ABORT = 301,
     CLASS = 302,
     NEW = 303,
     DELETE = 304,
     RUNSCRIPT = 305,
     UCC_INSERT = 306,
     SWITCH = 307,
     DEFAULT = 308,
     ADD_EQ = 309,
     SUB_EQ = 310,
     MUL_EQ = 311,
     DIV_EQ = 312,
     MOD_EQ = 313,
     CHOICE = 314,
     CONTINUE = 315,
     REPEAT = 316,
     NOP = 317,
     NOHALT = 318,
     WAIT = 319,
     RISE = 320,
     DESCEND = 321,
     FRAME = 322,
     HATCH = 323,
     NEXT = 324,
     PREVIOUS = 325,
     CYCLE = 326,
     STEP = 327,
     MUSIC = 328,
     CALL = 329,
     SPEECH = 330,
     SFX = 331,
     FACE = 332,
     HIT = 333,
     HOURS = 334,
     ACTOR = 335,
     ATTACK = 336,
     FINISH = 337,
     RESURRECT = 338,
     SETEGG = 339,
     MINUTES = 340,
     RESET = 341,
     WEATHER = 342,
     NEAR = 343,
     FAR = 344,
     NORTH = 345,
     SOUTH = 346,
     EAST = 347,
     WEST = 348,
     NE = 349,
     NW = 350,
     SE = 351,
     SW = 352,
     STANDING = 353,
     STEP_RIGHT = 354,
     STEP_LEFT = 355,
     READY = 356,
     RAISE_1H = 357,
     REACH_1H = 358,
     STRIKE_1H = 359,
     RAISE_2H = 360,
     REACH_2H = 361,
     STRIKE_2H = 362,
     SITTING = 363,
     BOWING = 364,
     KNEELING = 365,
     SLEEPING = 366,
     CAST_UP = 367,
     CAST_OUT = 368,
     CACHED_IN = 369,
     PARTY_NEAR = 370,
     AVATAR_NEAR = 371,
     AVATAR_FAR = 372,
     AVATAR_FOOTPAD = 373,
     PARTY_FOOTPAD = 374,
     SOMETHING_ON = 375,
     EXTERNAL_CRITERIA = 376,
     NORMAL_DAMAGE = 377,
     FIRE_DAMAGE = 378,
     MAGIC_DAMAGE = 379,
     LIGHTNING_DAMAGE = 380,
     ETHEREAL_DAMAGE = 381,
     SONIC_DAMAGE = 382,
     STRING_LITERAL = 383,
     STRING_PREFIX = 384,
     IDENTIFIER = 385,
     INT_LITERAL = 386,
     OR = 387,
     AND = 388,
     NEQUALS = 389,
     EQUALS = 390,
     GTEQUALS = 391,
     LTEQUALS = 392,
     UCC_CAST = 393,
     UPLUS = 394,
     UMINUS = 395,
     ADDRESSOF = 396,
     NOT = 397,
     UCC_SYM = 398,
     UCC_POINTS = 399,
     UCC_SCOPE = 400
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define RETURN 260
#define DO 261
#define WHILE 262
#define FOR 263
#define UCC_IN 264
#define WITH 265
#define TO 266
#define EXTERN 267
#define BREAK 268
#define GOTO 269
#define CASE 270
#define VAR 271
#define VOID 272
#define ALIAS 273
#define STRUCT 274
#define UCC_CHAR 275
#define UCC_INT 276
#define UCC_LONG 277
#define UCC_CONST 278
#define STRING 279
#define ENUM 280
#define CONVERSE 281
#define NESTED 282
#define SAY 283
#define MESSAGE 284
#define RESPONSE 285
#define EVENT 286
#define FLAG 287
#define ITEM 288
#define UCTRUE 289
#define UCFALSE 290
#define REMOVE 291
#define ADD 292
#define HIDE 293
#define SCRIPT 294
#define AFTER 295
#define TICKS 296
#define STATIC_ 297
#define ORIGINAL 298
#define SHAPENUM 299
#define OBJECTNUM 300
#define ABORT 301
#define CLASS 302
#define NEW 303
#define DELETE 304
#define RUNSCRIPT 305
#define UCC_INSERT 306
#define SWITCH 307
#define DEFAULT 308
#define ADD_EQ 309
#define SUB_EQ 310
#define MUL_EQ 311
#define DIV_EQ 312
#define MOD_EQ 313
#define CHOICE 314
#define CONTINUE 315
#define REPEAT 316
#define NOP 317
#define NOHALT 318
#define WAIT 319
#define RISE 320
#define DESCEND 321
#define FRAME 322
#define HATCH 323
#define NEXT 324
#define PREVIOUS 325
#define CYCLE 326
#define STEP 327
#define MUSIC 328
#define CALL 329
#define SPEECH 330
#define SFX 331
#define FACE 332
#define HIT 333
#define HOURS 334
#define ACTOR 335
#define ATTACK 336
#define FINISH 337
#define RESURRECT 338
#define SETEGG 339
#define MINUTES 340
#define RESET 341
#define WEATHER 342
#define NEAR 343
#define FAR 344
#define NORTH 345
#define SOUTH 346
#define EAST 347
#define WEST 348
#define NE 349
#define NW 350
#define SE 351
#define SW 352
#define STANDING 353
#define STEP_RIGHT 354
#define STEP_LEFT 355
#define READY 356
#define RAISE_1H 357
#define REACH_1H 358
#define STRIKE_1H 359
#define RAISE_2H 360
#define REACH_2H 361
#define STRIKE_2H 362
#define SITTING 363
#define BOWING 364
#define KNEELING 365
#define SLEEPING 366
#define CAST_UP 367
#define CAST_OUT 368
#define CACHED_IN 369
#define PARTY_NEAR 370
#define AVATAR_NEAR 371
#define AVATAR_FAR 372
#define AVATAR_FOOTPAD 373
#define PARTY_FOOTPAD 374
#define SOMETHING_ON 375
#define EXTERNAL_CRITERIA 376
#define NORMAL_DAMAGE 377
#define FIRE_DAMAGE 378
#define MAGIC_DAMAGE 379
#define LIGHTNING_DAMAGE 380
#define ETHEREAL_DAMAGE 381
#define SONIC_DAMAGE 382
#define STRING_LITERAL 383
#define STRING_PREFIX 384
#define IDENTIFIER 385
#define INT_LITERAL 386
#define OR 387
#define AND 388
#define NEQUALS 389
#define EQUALS 390
#define GTEQUALS 391
#define LTEQUALS 392
#define UCC_CAST 393
#define UPLUS 394
#define UMINUS 395
#define ADDRESSOF 396
#define NOT 397
#define UCC_SYM 398
#define UCC_POINTS 399
#define UCC_SCOPE 400




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 106 "ucparse.yy"

	class Uc_symbol *sym;
	class Uc_var_symbol *var;
	class Uc_class *cls;
	class Uc_struct_symbol *struc;
	class Uc_expression *expr;
	class Uc_call_expression *funcall;
	class Uc_function_symbol *funsym;
	class Uc_statement *stmt;
	class std::vector<Uc_var_symbol *> *varvec;
	class Uc_block_statement *block;
	class Uc_arrayloop_statement *arrayloop;
	class Uc_array_expression *exprlist;
	class std::vector<int> *intlist;
	class std::vector<Uc_statement *> *stmtlist;
	struct Fun_id_info *funid;
	struct Member_selector *membersel;
	int intval;
	char *strval;
	


/* Line 214 of yacc.c  */
#line 527 "ucparse.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 539 "ucparse.cc"

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
# if YYENABLE_NLS
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2427

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  166
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  151
/* YYNRULES -- Number of rules.  */
#define YYNRULES  399
/* YYNRULES -- Number of states.  */
#define YYNSTATES  820

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   400

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   146,   143,     2,
     154,   155,   144,   142,   164,   141,   153,   145,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   162,   163,
     137,   132,   138,     2,   165,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   156,     2,   157,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   160,     2,   161,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   133,   134,   135,
     136,   139,   140,   147,   148,   149,   150,   151,   152,   158,
     159
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    23,    31,    34,    35,    38,    39,    40,    44,
      51,    52,    59,    69,    70,    77,    80,    83,    85,    88,
      90,    91,    98,    99,   106,   109,   110,   114,   120,   127,
     128,   132,   136,   141,   142,   150,   160,   165,   170,   172,
     174,   175,   177,   179,   181,   182,   186,   191,   194,   196,
     199,   200,   202,   204,   206,   208,   210,   212,   214,   216,
     218,   220,   222,   224,   226,   228,   230,   232,   238,   244,
     246,   249,   251,   253,   255,   259,   266,   267,   275,   285,
     286,   294,   304,   308,   310,   312,   314,   316,   320,   322,
     323,   332,   334,   336,   338,   341,   344,   345,   349,   351,
     353,   355,   356,   362,   366,   368,   372,   374,   378,   382,
     384,   386,   390,   394,   396,   398,   402,   404,   406,   408,
     413,   414,   423,   424,   433,   435,   439,   441,   443,   447,
     449,   451,   455,   457,   461,   463,   467,   468,   473,   478,
     483,   488,   490,   492,   494,   496,   498,   502,   504,   506,
     507,   512,   518,   526,   527,   534,   535,   544,   545,   550,
     551,   552,   560,   561,   562,   563,   574,   579,   582,   585,
     593,   600,   609,   612,   613,   617,   620,   623,   624,   629,
     638,   640,   643,   644,   645,   652,   653,   659,   663,   665,
     666,   670,   677,   686,   690,   692,   696,   697,   698,   699,
     709,   712,   714,   719,   724,   728,   729,   735,   737,   740,
     742,   745,   748,   751,   754,   755,   761,   762,   770,   773,
     776,   780,   785,   790,   796,   802,   805,   808,   811,   815,
     820,   825,   828,   834,   840,   844,   849,   853,   858,   862,
     866,   872,   876,   880,   886,   889,   894,   898,   902,   906,
     910,   914,   920,   926,   929,   933,   936,   938,   940,   942,
     944,   946,   948,   950,   952,   954,   956,   958,   960,   962,
     964,   966,   968,   970,   972,   974,   976,   978,   980,   982,
     984,   986,   988,   990,   992,   994,   996,   998,  1000,  1002,
    1004,  1006,  1008,  1010,  1012,  1016,  1017,  1020,  1023,  1026,
    1029,  1033,  1039,  1045,  1047,  1048,  1052,  1054,  1056,  1058,
    1062,  1066,  1070,  1074,  1078,  1082,  1083,  1088,  1090,  1094,
    1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,  1129,  1132,
    1134,  1137,  1141,  1143,  1145,  1147,  1150,  1152,  1153,  1157,
    1159,  1163,  1165,  1168,  1170,  1172,  1177,  1182,  1184,  1186,
    1188,  1190,  1192,  1196,  1202,  1204,  1206,  1210,  1216,  1222,
    1231,  1238,  1248,  1256,  1266,  1274,  1276,  1277,  1279,  1280,
    1284,  1286,  1288,  1291,  1297,  1303,  1305,  1308,  1310,  1312,
    1314,  1316,  1317,  1319,  1324,  1326,  1328,  1330,  1332,  1334
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,   167,   168,    -1,   168,    -1,   185,    -1,
     230,    -1,   209,    -1,   203,    -1,   219,    -1,   169,    -1,
     181,    -1,    -1,    47,   130,   171,   170,   160,   172,   161,
      -1,   162,   315,    -1,    -1,   172,   173,    -1,    -1,    -1,
      16,   174,   177,    -1,    16,   198,   130,   132,   313,   163,
      -1,    -1,    19,   137,   316,   138,   175,   178,    -1,    19,
     137,   316,   138,   198,   130,   132,   313,   163,    -1,    -1,
      47,   137,   315,   138,   176,   179,    -1,   310,   179,    -1,
     202,   163,    -1,   179,    -1,   216,   163,    -1,   179,    -1,
      -1,   130,   154,   306,   155,   180,   187,    -1,    -1,    19,
     130,   182,   160,   183,   161,    -1,   183,   184,    -1,    -1,
      16,   130,   163,    -1,    19,   137,   316,   138,   163,    -1,
      19,   137,   316,   138,   130,   163,    -1,    -1,   188,   186,
     187,    -1,   160,   196,   161,    -1,   160,   196,   287,   161,
      -1,    -1,   311,   130,   189,   190,   154,   306,   155,    -1,
      47,   137,   315,   138,   130,   193,   154,   306,   155,    -1,
      44,   154,   192,   155,    -1,    45,   154,   191,   155,    -1,
     191,    -1,   192,    -1,    -1,   131,    -1,   130,    -1,   192,
      -1,    -1,   195,   196,   161,    -1,   195,   196,   287,   161,
      -1,   287,   197,    -1,   160,    -1,   196,   197,    -1,    -1,
     199,    -1,   232,    -1,   237,    -1,   238,    -1,   241,    -1,
     250,    -1,   251,    -1,   253,    -1,   194,    -1,   255,    -1,
     267,    -1,   272,    -1,   285,    -1,   286,    -1,   288,    -1,
     289,    -1,    28,   154,   291,   155,   163,    -1,    29,   154,
     291,   155,   163,    -1,   290,    -1,    46,   163,    -1,   163,
      -1,    18,    -1,   143,    -1,    16,   202,   163,    -1,    16,
     198,   130,   132,   313,   163,    -1,    -1,    19,   137,   316,
     138,   200,   216,   163,    -1,    19,   137,   316,   138,   198,
     130,   132,   313,   163,    -1,    -1,    47,   137,   315,   138,
     201,   214,   163,    -1,    47,   137,   315,   138,   198,   130,
     132,   313,   163,    -1,    24,   228,   163,    -1,   209,    -1,
     203,    -1,   230,    -1,   219,    -1,   202,   164,   213,    -1,
     213,    -1,    -1,    25,   130,   204,   206,   160,   207,   161,
     163,    -1,    21,    -1,    20,    -1,    22,    -1,    22,    21,
      -1,   162,   205,    -1,    -1,   207,   164,   208,    -1,   208,
      -1,   212,    -1,   130,    -1,    -1,    23,   205,   210,   211,
     163,    -1,   211,   164,   212,    -1,   212,    -1,   130,   132,
     293,    -1,   130,    -1,   130,   132,   293,    -1,   214,   164,
     215,    -1,   215,    -1,   130,    -1,   130,   132,   218,    -1,
     216,   164,   217,    -1,   217,    -1,   130,    -1,   130,   132,
     293,    -1,   301,    -1,   130,    -1,   304,    -1,    42,    16,
     222,   163,    -1,    -1,    42,    19,   137,   316,   138,   220,
     224,   163,    -1,    -1,    42,    47,   137,   315,   138,   221,
     226,   163,    -1,   223,    -1,   222,   164,   223,    -1,   130,
      -1,   225,    -1,   224,   164,   225,    -1,   130,    -1,   227,
      -1,   226,   164,   227,    -1,   130,    -1,   228,   164,   229,
      -1,   229,    -1,   130,   132,   128,    -1,    -1,    12,   231,
     188,   163,    -1,   294,   132,   294,   163,    -1,   293,   233,
     293,   163,    -1,   293,    51,   234,   163,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,   234,    51,
     235,    -1,   235,    -1,   293,    -1,    -1,   160,   236,   275,
     161,    -1,     3,   154,   294,   155,   197,    -1,     3,   154,
     294,   155,   197,     4,   197,    -1,    -1,     7,   154,   293,
     155,   239,   197,    -1,    -1,     6,   240,   197,     7,   154,
     293,   155,   163,    -1,    -1,   248,   155,   242,   197,    -1,
      -1,    -1,   248,    10,   130,   243,   155,   244,   197,    -1,
      -1,    -1,    -1,   248,    10,   130,   245,    11,   130,   246,
     155,   247,   197,    -1,   249,   130,     9,   313,    -1,     8,
     154,    -1,   304,   163,    -1,   300,   302,    28,   154,   291,
     155,   163,    -1,   300,   302,    38,   154,   155,   163,    -1,
     300,   302,    50,   154,   313,   252,   155,   163,    -1,   164,
     293,    -1,    -1,     5,   294,   163,    -1,     5,   163,    -1,
     162,    27,    -1,    -1,   256,   160,   261,   161,    -1,   256,
     254,   154,   294,   155,   160,   257,   161,    -1,    26,    -1,
     257,   258,    -1,    -1,    -1,    15,   265,   266,   162,   259,
     196,    -1,    -1,    53,   266,   162,   260,   196,    -1,   261,
       4,   262,    -1,   262,    -1,    -1,   264,   263,   196,    -1,
       3,   154,    30,   136,   128,   155,    -1,     3,   154,    30,
       9,   156,   265,   157,   155,    -1,   265,   164,   128,    -1,
     128,    -1,   154,    36,   155,    -1,    -1,    -1,    -1,    52,
     154,   268,   294,   155,   160,   269,   270,   161,    -1,   270,
     271,    -1,   271,    -1,    15,   309,   162,   196,    -1,    15,
     128,   162,   196,    -1,    53,   162,   196,    -1,    -1,    39,
     273,   274,   284,   276,    -1,   293,    -1,   275,   276,    -1,
     276,    -1,    82,   163,    -1,    83,   163,    -1,    60,   163,
      -1,    86,   163,    -1,    -1,    61,   293,   277,   276,   163,
      -1,    -1,    61,   293,   164,   293,   278,   276,   163,    -1,
      62,   163,    -1,    63,   163,    -1,    64,   293,   163,    -1,
      64,   293,    85,   163,    -1,    64,   293,    79,   163,    -1,
      64,     7,    88,   293,   163,    -1,    64,     7,    89,   293,
     163,    -1,    36,   163,    -1,    65,   163,    -1,    66,   163,
      -1,    67,   293,   163,    -1,    80,    67,   293,   163,    -1,
      80,    67,   282,   163,    -1,    68,   163,    -1,    84,   293,
     164,   293,   163,    -1,    84,   283,   164,   293,   163,    -1,
      69,    67,   163,    -1,    69,    67,    71,   163,    -1,    70,
      67,   163,    -1,    70,    67,    71,   163,    -1,    28,   293,
     163,    -1,    72,   293,   163,    -1,    72,   293,   164,   293,
     163,    -1,    72,   281,   163,    -1,    73,   293,   163,    -1,
      73,   293,   164,   293,   163,    -1,   279,   163,    -1,   279,
     164,   293,   163,    -1,    75,   293,   163,    -1,    76,   293,
     163,    -1,    77,   293,   163,    -1,    77,   281,   163,    -1,
      87,   293,   163,    -1,    78,   293,   164,   293,   163,    -1,
      78,   293,   164,   280,   163,    -1,    81,   163,    -1,   160,
     275,   161,    -1,    74,   293,    -1,   122,    -1,   123,    -1,
     124,    -1,   125,    -1,   126,    -1,   127,    -1,    90,    -1,
      94,    -1,    92,    -1,    96,    -1,    91,    -1,    97,    -1,
      93,    -1,    95,    -1,    98,    -1,    99,    -1,   100,    -1,
     101,    -1,   102,    -1,   103,    -1,   104,    -1,   105,    -1,
     106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,
     111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,
     116,    -1,   117,    -1,   118,    -1,   119,    -1,   120,    -1,
     121,    -1,    40,   293,    41,    -1,    -1,    13,   163,    -1,
      60,   163,    -1,   130,   162,    -1,    14,   130,    -1,    49,
     313,   163,    -1,    37,   154,   292,   155,   163,    -1,    36,
     154,   292,   155,   163,    -1,   292,    -1,    -1,   292,   164,
     293,    -1,   293,    -1,   294,    -1,   300,    -1,   293,   142,
     293,    -1,   293,   141,   293,    -1,   293,   144,   293,    -1,
     293,   145,   293,    -1,   293,   146,   293,    -1,   293,   136,
     293,    -1,    -1,    48,    39,   295,   276,    -1,    59,    -1,
     293,   135,   293,    -1,   293,   137,   293,    -1,   293,   140,
     293,    -1,   293,   138,   293,    -1,   293,   139,   293,    -1,
     293,   134,   293,    -1,   293,   133,   293,    -1,   293,     9,
     293,    -1,   293,   143,   293,    -1,   142,   300,    -1,   141,
     300,    -1,   296,    -1,   151,   300,    -1,   156,   297,   157,
      -1,   128,    -1,   129,    -1,   301,    -1,   143,   130,    -1,
     298,    -1,    -1,   298,   164,   294,    -1,   294,    -1,   154,
     205,   155,    -1,   131,    -1,   299,   131,    -1,   303,    -1,
     312,    -1,   313,   156,   294,   157,    -1,    32,   156,   293,
     157,    -1,   304,    -1,    34,    -1,    35,    -1,    31,    -1,
      33,    -1,   154,   294,   155,    -1,    48,   315,   154,   291,
     155,    -1,   158,    -1,   153,    -1,   300,   302,   130,    -1,
     303,   305,   154,   297,   155,    -1,   130,   305,   154,   297,
     155,    -1,   300,   302,   315,   159,   130,   154,   297,   155,
      -1,   315,   159,   130,   154,   297,   155,    -1,   300,   302,
     154,   144,   300,   155,   154,   297,   155,    -1,   154,   144,
     300,   155,   154,   297,   155,    -1,   300,   302,   154,   165,
     309,   155,   154,   297,   155,    -1,   154,   165,   309,   155,
     154,   297,   155,    -1,    43,    -1,    -1,   307,    -1,    -1,
     307,   164,   308,    -1,   308,    -1,   130,    -1,    16,   130,
      -1,    19,   137,   316,   138,   130,    -1,    47,   137,   315,
     138,   130,    -1,   131,    -1,   299,   131,    -1,   314,    -1,
      34,    -1,    35,    -1,    17,    -1,    -1,    16,    -1,    19,
     137,   316,   138,    -1,   310,    -1,   314,    -1,   314,    -1,
     130,    -1,   130,    -1,   130,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   215,   215,   216,   220,   221,   226,   227,   228,   229,
     230,   235,   234,   247,   250,   254,   255,   259,   259,   261,
     263,   263,   265,   267,   267,   269,   273,   274,   278,   279,
     284,   283,   314,   313,   324,   325,   329,   331,   333,   338,
     338,   347,   351,   360,   360,   389,   399,   409,   411,   416,
     418,   422,   423,   446,   448,   452,   457,   463,   478,   483,
     489,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   511,   513,
     514,   516,   521,   522,   526,   528,   530,   530,   532,   534,
     534,   536,   545,   547,   549,   551,   558,   563,   582,   587,
     587,   593,   595,   597,   599,   604,   607,   611,   612,   616,
     617,   629,   629,   635,   636,   640,   658,   666,   686,   704,
     709,   718,   737,   755,   760,   768,   789,   791,   816,   823,
     825,   824,   829,   828,   835,   836,   840,   850,   851,   855,
     865,   866,   870,   880,   881,   885,   892,   892,   897,   925,
     931,   940,   942,   944,   946,   948,   953,   955,   963,   964,
     964,   972,   992,  1017,  1017,  1038,  1038,  1059,  1059,  1068,
    1069,  1067,  1078,  1080,  1081,  1077,  1091,  1106,  1114,  1120,
    1131,  1137,  1159,  1162,  1166,  1206,  1223,  1226,  1230,  1237,
    1249,  1257,  1263,  1268,  1267,  1276,  1275,  1285,  1290,  1299,
    1298,  1308,  1313,  1318,  1320,  1328,  1331,  1336,  1338,  1335,
    1353,  1355,  1363,  1365,  1368,  1373,  1373,  1390,  1394,  1396,
    1404,  1406,  1408,  1410,  1412,  1412,  1427,  1427,  1441,  1443,
    1445,  1447,  1449,  1451,  1453,  1455,  1457,  1459,  1461,  1463,
    1469,  1471,  1473,  1475,  1477,  1479,  1481,  1483,  1485,  1487,
    1494,  1504,  1506,  1508,  1523,  1525,  1527,  1529,  1531,  1533,
    1535,  1537,  1539,  1541,  1543,  1548,  1567,  1569,  1571,  1573,
    1575,  1577,  1582,  1584,  1586,  1588,  1590,  1592,  1594,  1596,
    1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,  1617,  1619,
    1621,  1623,  1625,  1627,  1629,  1631,  1636,  1638,  1640,  1642,
    1644,  1646,  1648,  1650,  1655,  1658,  1662,  1667,  1672,  1690,
    1698,  1715,  1721,  1730,  1732,  1736,  1738,  1746,  1756,  1758,
    1760,  1762,  1764,  1766,  1768,  1770,  1770,  1775,  1786,  1788,
    1790,  1792,  1794,  1796,  1798,  1800,  1802,  1804,  1811,  1819,
    1821,  1823,  1825,  1827,  1829,  1833,  1862,  1864,  1868,  1870,
    1878,  1883,  1902,  1904,  1938,  1940,  1957,  1959,  1966,  1968,
    1970,  1972,  1974,  1979,  1986,  1987,  1991,  1996,  2001,  2005,
    2009,  2013,  2018,  2023,  2041,  2061,  2064,  2068,  2070,  2074,
    2076,  2084,  2086,  2088,  2090,  2095,  2114,  2116,  2130,  2132,
    2137,  2139,  2145,  2147,  2149,  2154,  2168,  2184,  2199,  2204
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "RETURN", "DO", "WHILE",
  "FOR", "UCC_IN", "WITH", "TO", "EXTERN", "BREAK", "GOTO", "CASE", "VAR",
  "VOID", "ALIAS", "STRUCT", "UCC_CHAR", "UCC_INT", "UCC_LONG",
  "UCC_CONST", "STRING", "ENUM", "CONVERSE", "NESTED", "SAY", "MESSAGE",
  "RESPONSE", "EVENT", "FLAG", "ITEM", "UCTRUE", "UCFALSE", "REMOVE",
  "ADD", "HIDE", "SCRIPT", "AFTER", "TICKS", "STATIC_", "ORIGINAL",
  "SHAPENUM", "OBJECTNUM", "ABORT", "CLASS", "NEW", "DELETE", "RUNSCRIPT",
  "UCC_INSERT", "SWITCH", "DEFAULT", "ADD_EQ", "SUB_EQ", "MUL_EQ",
  "DIV_EQ", "MOD_EQ", "CHOICE", "CONTINUE", "REPEAT", "NOP", "NOHALT",
  "WAIT", "RISE", "DESCEND", "FRAME", "HATCH", "NEXT", "PREVIOUS", "CYCLE",
  "STEP", "MUSIC", "CALL", "SPEECH", "SFX", "FACE", "HIT", "HOURS",
  "ACTOR", "ATTACK", "FINISH", "RESURRECT", "SETEGG", "MINUTES", "RESET",
  "WEATHER", "NEAR", "FAR", "NORTH", "SOUTH", "EAST", "WEST", "NE", "NW",
  "SE", "SW", "STANDING", "STEP_RIGHT", "STEP_LEFT", "READY", "RAISE_1H",
  "REACH_1H", "STRIKE_1H", "RAISE_2H", "REACH_2H", "STRIKE_2H", "SITTING",
  "BOWING", "KNEELING", "SLEEPING", "CAST_UP", "CAST_OUT", "CACHED_IN",
  "PARTY_NEAR", "AVATAR_NEAR", "AVATAR_FAR", "AVATAR_FOOTPAD",
  "PARTY_FOOTPAD", "SOMETHING_ON", "EXTERNAL_CRITERIA", "NORMAL_DAMAGE",
  "FIRE_DAMAGE", "MAGIC_DAMAGE", "LIGHTNING_DAMAGE", "ETHEREAL_DAMAGE",
  "SONIC_DAMAGE", "STRING_LITERAL", "STRING_PREFIX", "IDENTIFIER",
  "INT_LITERAL", "'='", "OR", "AND", "NEQUALS", "EQUALS", "'<'", "'>'",
  "GTEQUALS", "LTEQUALS", "'-'", "'+'", "'&'", "'*'", "'/'", "'%'",
  "UCC_CAST", "UPLUS", "UMINUS", "ADDRESSOF", "NOT", "UCC_SYM", "'.'",
  "'('", "')'", "'['", "']'", "UCC_POINTS", "UCC_SCOPE", "'{'", "'}'",
  "':'", "';'", "','", "'@'", "$accept", "design", "global_decl",
  "class_definition", "$@1", "opt_inheritance", "class_item_list",
  "class_item", "$@2", "$@3", "$@4", "class_var_def", "class_struct_def",
  "method", "$@5", "struct_definition", "$@6", "struct_item_list",
  "struct_item", "function", "$@7", "function_body", "function_proto",
  "$@8", "opt_funid", "opt_const_int_val", "const_int_val", "opt_int",
  "statement_block", "statement_block_start", "statement_list",
  "statement", "alias_tok", "stmt_declaration", "$@9", "$@10",
  "var_decl_list", "enum_decl", "$@11", "const_int_type", "opt_enum_type",
  "enum_item_list", "enum_item", "const_int_decl", "$@12",
  "const_int_decl_list", "const_int", "var_decl", "class_decl_list",
  "class_decl", "struct_decl_list", "struct_decl", "class_expr",
  "static_decl", "$@13", "$@14", "static_var_decl_list", "static_var",
  "static_struct_var_decl_list", "static_struct_var",
  "static_cls_decl_list", "static_cls", "string_decl_list", "string_decl",
  "function_decl", "$@15", "assignment_statement", "assignment_operator",
  "appended_element_list", "appended_element", "$@16", "if_statement",
  "while_statement", "$@17", "$@18", "array_loop_statement", "$@19",
  "$@20", "$@21", "$@22", "$@23", "$@24", "start_array_loop", "start_for",
  "function_call_statement", "special_method_call_statement", "opt_delay",
  "return_statement", "opt_nest", "converse_statement", "start_conv",
  "converse_case_list", "converse_case", "$@25", "$@26",
  "response_case_list", "response_case", "$@27", "response_expression",
  "string_list", "converse_options", "switch_statement", "$@28", "$@29",
  "switch_case_list", "switch_case", "script_statement", "$@30", "item",
  "script_command_list", "script_command", "$@31", "$@32", "start_call",
  "dam_type", "direction", "actor_frames", "egg_criteria",
  "opt_script_delay", "break_statement", "continue_statement",
  "label_statement", "goto_statement", "delete_statement",
  "answer_statement", "opt_nonclass_expr_list", "nonclass_expr_list",
  "nonclass_expr", "expression", "$@33", "addressof",
  "opt_expression_list", "expression_list", "int_cast", "primary",
  "new_expr", "hierarchy_tok", "member_selector", "function_call",
  "opt_original", "opt_param_list", "param_list", "param", "int_literal",
  "opt_void", "ret_type", "declared_var_value", "declared_var",
  "declared_sym", "defined_class", "defined_struct", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,    61,   387,   388,   389,   390,    60,    62,   391,
     392,    45,    43,    38,    42,    47,    37,   393,   394,   395,
     396,   397,   398,    46,    40,    41,    91,    93,   399,   400,
     123,   125,    58,    59,    44,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   166,   167,   167,   168,   168,   168,   168,   168,   168,
     168,   170,   169,   171,   171,   172,   172,   174,   173,   173,
     175,   173,   173,   176,   173,   173,   177,   177,   178,   178,
     180,   179,   182,   181,   183,   183,   184,   184,   184,   186,
     185,   187,   187,   189,   188,   188,   190,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   194,   194,   195,   196,
     196,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   198,   198,   199,   199,   200,   199,   199,   201,
     199,   199,   199,   199,   199,   199,   199,   202,   202,   204,
     203,   205,   205,   205,   205,   206,   206,   207,   207,   208,
     208,   210,   209,   211,   211,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   217,   217,   218,   218,   218,   219,
     220,   219,   221,   219,   222,   222,   223,   224,   224,   225,
     226,   226,   227,   228,   228,   229,   231,   230,   232,   232,
     232,   233,   233,   233,   233,   233,   234,   234,   235,   236,
     235,   237,   237,   239,   238,   240,   238,   242,   241,   243,
     244,   241,   245,   246,   247,   241,   248,   249,   250,   251,
     251,   251,   252,   252,   253,   253,   254,   254,   255,   255,
     256,   257,   257,   259,   258,   260,   258,   261,   261,   263,
     262,   264,   264,   265,   265,   266,   266,   268,   269,   267,
     270,   270,   271,   271,   271,   273,   272,   274,   275,   275,
     276,   276,   276,   276,   277,   276,   278,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   279,   280,   280,   280,   280,
     280,   280,   281,   281,   281,   281,   281,   281,   281,   281,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   283,   283,   283,   283,
     283,   283,   283,   283,   284,   284,   285,   286,   287,   288,
     289,   290,   290,   291,   291,   292,   292,   293,   294,   294,
     294,   294,   294,   294,   294,   295,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   296,   297,   297,   298,   298,
     299,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   301,   302,   302,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   305,   305,   306,   306,   307,
     307,   308,   308,   308,   308,   309,   309,   309,   309,   309,
     310,   310,   311,   311,   311,   312,   313,   314,   315,   316
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     7,     2,     0,     2,     0,     0,     3,     6,
       0,     6,     9,     0,     6,     2,     2,     1,     2,     1,
       0,     6,     0,     6,     2,     0,     3,     5,     6,     0,
       3,     3,     4,     0,     7,     9,     4,     4,     1,     1,
       0,     1,     1,     1,     0,     3,     4,     2,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     1,
       2,     1,     1,     1,     3,     6,     0,     7,     9,     0,
       7,     9,     3,     1,     1,     1,     1,     3,     1,     0,
       8,     1,     1,     1,     2,     2,     0,     3,     1,     1,
       1,     0,     5,     3,     1,     3,     1,     3,     3,     1,
       1,     3,     3,     1,     1,     3,     1,     1,     1,     4,
       0,     8,     0,     8,     1,     3,     1,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     0,     4,     4,     4,
       4,     1,     1,     1,     1,     1,     3,     1,     1,     0,
       4,     5,     7,     0,     6,     0,     8,     0,     4,     0,
       0,     7,     0,     0,     0,    10,     4,     2,     2,     7,
       6,     8,     2,     0,     3,     2,     2,     0,     4,     8,
       1,     2,     0,     0,     6,     0,     5,     3,     1,     0,
       3,     6,     8,     3,     1,     3,     0,     0,     0,     9,
       2,     1,     4,     4,     3,     0,     5,     1,     2,     1,
       2,     2,     2,     2,     0,     5,     0,     7,     2,     2,
       3,     4,     4,     5,     5,     2,     2,     2,     3,     4,
       4,     2,     5,     5,     3,     4,     3,     4,     3,     3,
       5,     3,     3,     5,     2,     4,     3,     3,     3,     3,
       3,     5,     5,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     2,     2,     2,     2,
       3,     5,     5,     1,     0,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     0,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       2,     3,     1,     1,     1,     2,     1,     0,     3,     1,
       3,     1,     2,     1,     1,     4,     4,     1,     1,     1,
       1,     1,     3,     5,     1,     1,     3,     5,     5,     8,
       6,     9,     7,     9,     7,     1,     0,     1,     0,     3,
       1,     1,     2,     5,     5,     1,     2,     1,     1,     1,
       1,     0,     1,     4,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     391,   146,   392,   390,     0,     0,     0,     0,     0,   391,
       3,     9,    10,     4,    39,     7,     6,     8,     5,   394,
       0,   391,    32,     0,   102,   101,   103,   111,    99,     0,
       0,     0,    14,     0,     1,     2,     0,    43,     0,     0,
       0,     0,   399,     0,   104,     0,   106,   136,     0,   134,
       0,     0,     0,    11,   398,     0,    60,    40,    50,   147,
      35,   393,     0,     0,   114,     0,     0,   129,     0,     0,
       0,    13,     0,     0,     0,     0,     0,    52,    51,     0,
      48,    49,     0,     0,   112,     0,   105,     0,   135,   130,
     132,    16,    54,     0,     0,   165,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,   360,     0,   361,   358,
     359,     0,     0,   215,     0,     0,     0,     0,     0,   327,
       0,   342,   343,   397,   351,     0,     0,     0,     0,     0,
     347,    58,    41,    81,    69,    60,    59,    61,    94,    93,
      96,    95,    62,    63,    64,    65,     0,     0,    66,    67,
      68,    70,   187,    71,    72,    73,    74,     0,    75,    76,
      79,     0,   317,   339,     0,   318,   344,   353,   357,   354,
       0,   395,     0,     0,    50,   378,     0,     0,    33,    34,
     397,   115,   317,   318,   357,   113,   110,     0,   108,   109,
       0,     0,   391,    53,     0,     0,   185,     0,   317,     0,
       0,   177,   306,   309,    82,   116,    83,     0,     0,    98,
       0,     0,     0,   144,   314,   314,     0,     0,     0,     0,
      80,     0,   325,     0,   397,     0,   396,   207,   307,   375,
     308,     0,   338,   337,   345,   340,     0,     0,     0,   317,
     317,     0,   346,     0,     0,   167,     0,     0,     0,     0,
      42,    57,     0,     0,     0,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,   365,   364,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,   381,
       0,   377,   380,     0,     0,     0,     0,     0,   139,     0,
     137,   142,     0,   140,    17,     0,     0,    12,    15,     0,
     378,   317,   184,     0,     0,     0,     0,    84,     0,     0,
       0,    92,     0,     0,   313,   316,     0,     0,     0,     0,
     305,   217,     0,     0,   314,   310,     0,   347,     0,   388,
     389,   385,     0,     0,     0,   387,   350,   362,   341,     0,
      55,     0,   169,     0,     0,     0,     0,   198,   199,   186,
       0,   335,   159,     0,   157,   158,   334,   333,   328,   324,
     329,   331,   332,   330,   320,   319,   336,   321,   322,   323,
       0,   317,     0,     0,     0,   366,     0,     0,   347,   317,
       0,    46,    47,   382,     0,     0,    44,     0,    36,     0,
     100,   107,   131,     0,   133,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,   163,   117,     0,    97,    86,
     145,   143,     0,     0,     0,   356,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   326,
       0,     0,   317,     0,     0,   386,     0,   317,    56,     0,
       0,   168,   176,     0,     0,   188,    60,   317,     0,     0,
     150,   149,   148,   314,     0,     0,     0,     0,     0,     0,
     355,   347,     0,     0,   379,     0,   138,   141,   116,    18,
      27,     0,     0,     0,     0,   378,    45,   161,     0,     0,
       0,     0,     0,    77,   315,    78,   312,   311,     0,   216,
       0,     0,     0,   235,   222,   224,   228,   229,     0,     0,
     236,   237,     0,   241,     0,     0,   272,   276,   274,   278,
     273,   279,   275,   277,     0,     0,     0,   265,     0,     0,
       0,     0,     0,     0,   263,   220,   221,   296,   297,   298,
     299,   300,   301,   302,   303,     0,     0,   223,     0,     0,
     219,   254,     0,   363,     0,   368,   347,   347,   170,     0,
       0,   197,   200,     0,     0,   156,     0,     0,   183,     0,
       0,     0,   367,     0,     0,     0,     0,    37,    26,     0,
      20,    23,     0,     0,     0,   164,    85,     0,   124,     0,
     123,   304,     0,   120,     0,   119,   248,     0,     0,     0,
       0,     0,     0,   230,   238,     0,   244,     0,   246,   251,
     249,     0,   252,     0,   256,   257,   259,   258,     0,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,     0,     0,     0,     0,   260,
     264,   218,     0,   208,     0,     0,     0,   173,     0,     0,
     192,   160,     0,   180,     0,     0,     0,     0,   347,   370,
     383,   384,    38,     0,     0,     0,     0,    30,   162,     0,
       0,     0,    87,     0,     0,     0,    90,     0,   226,     0,
       0,     0,   232,   231,   245,   247,     0,     0,   266,   267,
     268,   269,   270,   271,     0,     0,   240,   239,     0,     0,
     255,     0,   372,   374,   171,     0,     0,     0,     0,   179,
     182,     0,   347,   347,     0,    19,   124,    21,    29,     0,
       0,    24,     0,   166,     0,   125,   122,     0,     0,   397,
     121,     0,   126,   128,   118,     0,   225,   233,   234,   250,
     253,   262,   261,   243,   242,     0,     0,     0,   211,   174,
     204,     0,   201,     0,   206,   189,   191,   181,     0,     0,
     369,    28,     0,    31,    88,    91,     0,     0,     0,    60,
     209,   210,     0,     0,     0,   206,     0,     0,   371,   373,
       0,   227,    60,    60,   214,   175,   202,   203,     0,     0,
     195,    22,   213,   212,   193,   205,    60,    60,   196,   194
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    72,    53,   192,   308,   406,   684,
     686,   499,   737,   411,   742,    12,    41,    82,   179,    13,
      36,    57,    14,    58,    79,    80,    81,   194,   134,   135,
      74,   136,   207,   137,   512,   521,   208,   138,    46,   238,
      66,   187,   188,   139,    45,    63,   189,   209,   614,   615,
     609,   610,   750,   140,   190,   191,    48,    49,   299,   300,
     302,   303,   212,   213,   141,    21,   142,   274,   363,   364,
     478,   143,   144,   509,   199,   145,   353,   469,   666,   470,
     725,   792,   146,   147,   148,   149,   675,   150,   249,   151,
     152,   728,   776,   817,   816,   356,   357,   476,   358,   771,
     797,   153,   336,   721,   767,   768,   154,   219,   330,   569,
     570,   618,   755,   460,   714,   544,   655,   565,   429,   155,
     156,   252,   158,   159,   160,   323,   324,   161,   182,   333,
     163,   241,   242,   164,   183,   166,   295,   167,   184,   231,
     290,   291,   292,   344,    19,    20,   169,   170,   171,   172,
      43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -470
static const yytype_int16 yypact[] =
{
     578,  -470,  -470,  -470,     3,   262,   -81,    31,    66,  1728,
    -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
     -78,    55,  -470,   -67,  -470,  -470,    58,  -470,  -470,   -36,
     -25,   -23,   -21,    36,  -470,  -470,   -42,  -470,    -8,     0,
      22,    40,  -470,    71,  -470,    57,    76,  -470,   101,  -470,
     -67,    36,    36,  -470,  -470,   106,  -470,  -470,    -4,  -470,
    -470,  -470,   117,   110,  -470,   262,    92,  -470,   -36,   147,
     150,  -470,   131,   173,   784,   157,   189,  -470,  -470,   193,
    -470,  -470,     9,  2271,  -470,    57,  -470,   203,  -470,  -470,
    -470,  -470,   179,   197,  1971,  -470,   206,   208,   211,   239,
      33,   234,   249,  -470,   224,   241,  -470,   242,  -470,  -470,
    -470,   245,   246,  -470,   244,   274,    -2,   275,   261,  -470,
     253,  -470,  -470,    89,  -470,   266,   266,   288,   266,  1690,
    2271,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,  -470,    16,   289,  -470,  -470,
    -470,  -470,   -65,  -470,  -470,  -470,  -470,   981,  -470,  -470,
    -470,  1723,   291,  -470,   290,     7,  -470,   -12,   267,  -470,
     280,   282,   265,   179,   179,    38,   304,   302,  -470,  -470,
       5,  1649,  -470,     7,  -470,  -470,   117,   -72,  -470,  -470,
     310,   311,    19,  -470,   292,  2271,  -470,  1649,   281,  1357,
    2271,  -470,  -470,  -470,  -470,   315,  -470,   313,   152,  -470,
     -67,   318,   172,  -470,  2271,  2271,  2271,  2271,  2271,  2271,
    -470,    36,  -470,   297,  -470,   293,  -470,  -470,  -470,  -470,
    -470,   298,     7,     7,  -470,     7,   266,   283,   299,   300,
     -54,   326,   321,  1148,   327,  -470,   477,   498,   478,   350,
    -470,  -470,  1357,  2271,  1977,  -470,  -470,  -470,  -470,  -470,
    2271,  2271,  2271,  2271,  2271,  2271,  2271,  2271,  2271,  2271,
    2271,  2271,  2271,  2271,  2271,  2271,  -470,  -470,  -470,    32,
     352,  -470,  2271,   377,   355,   356,   383,   378,   379,  -470,
     359,   353,  -470,   363,   -67,   -77,   364,   203,  -470,   174,
    -470,  -470,   177,  -470,    15,   382,   391,  -470,  -470,   400,
      38,   376,  -470,   525,  1540,  2271,   401,  -470,   408,   402,
     413,  -470,   249,   388,   380,  1649,   392,  1500,   -48,   -47,
     506,  1649,   411,  1914,  2271,  -470,  2271,  2271,    49,  -470,
    -470,  -470,   262,   420,   397,  -470,  -470,  -470,  -470,  2271,
    -470,  1198,   542,  1357,   275,   417,    12,  -470,  -470,  -470,
    2271,   126,  -470,   -27,  -470,  1649,   354,   354,   335,   335,
     126,   126,   126,   126,   162,   162,   162,  -470,  -470,  -470,
     424,   409,   419,   422,   423,   395,   -56,   415,  2271,   427,
     429,  -470,  -470,  -470,   -67,    36,  -470,    38,  -470,   442,
    -470,  -470,  -470,   310,  -470,   311,   451,   455,   -67,    36,
     432,  -470,   433,  1357,   435,  -470,  1649,   275,  -470,    15,
    -470,  -470,   428,  2271,   430,  -470,   436,   437,  2271,  1914,
      15,  2271,   459,   460,  2271,   461,   464,   394,   465,   466,
    2271,   467,   529,   531,  2129,  2271,  2271,  2271,  2271,  2129,
    2271,   565,   470,   472,   474,  2135,   476,  2271,  1914,  -470,
     182,   491,   492,   493,   495,  -470,   497,   -51,  -470,   499,
     641,  -470,  -470,   623,   498,  -470,  -470,   501,  1914,  1977,
    -470,  -470,  -470,  2271,   502,   275,   266,   283,   530,   507,
    -470,  2271,   523,   526,  -470,   -87,  -470,  -470,   -86,  -470,
    -470,   190,   533,   528,   534,    38,  -470,   659,  2271,  1357,
     508,   543,   544,  -470,  1649,  -470,  -470,  -470,  1623,  -470,
     545,   546,   473,  -470,  -470,    10,  -470,  -470,   268,   325,
    -470,  -470,   755,  -470,   -44,   -39,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,   514,    77,    91,  1649,   815,   829,
     515,   932,   186,  2044,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,   517,   248,  -470,  1129,  1811,
    -470,  -470,  2271,  -470,   524,  -470,  2271,  2271,  -470,   555,
      21,  -470,  1357,   547,  1854,  -470,   548,   539,   540,   123,
     550,   552,  -470,   554,   580,   581,   549,  -470,  -470,   275,
      15,  -470,   558,  1357,  1563,  -470,  -470,   582,   583,   195,
    -470,  -470,   584,   585,   201,  -470,  -470,  2271,  1914,  2271,
    2271,   557,   559,  -470,  -470,   560,  -470,   561,  -470,  -470,
    -470,  2271,  -470,  2271,  -470,  -470,  -470,  -470,  2170,  -470,
    -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,   562,  1179,  2271,  2271,  -470,
    -470,  -470,  1285,  -470,   566,   571,  1357,  -470,   573,   599,
    -470,  -470,   569,  -470,  2271,   579,   588,   592,  2271,  -470,
    -470,  -470,  -470,   570,   605,   606,   400,  -470,  -470,   574,
     275,  2271,  -470,   544,   275,  1003,  -470,   546,  1649,   587,
    1301,  1334,  -470,  -470,  -470,  -470,  1388,  1402,  -470,  -470,
    -470,  -470,  -470,  -470,   590,  1440,  -470,  -470,  1454,  1485,
    -470,    27,  -470,  -470,  -470,   601,   619,   604,     6,  -470,
    1649,   598,  2271,  2271,   610,  -470,   -63,  -470,  -470,   204,
     634,  -470,   -42,  -470,   607,  1649,  -470,   608,    36,    30,
    -470,     7,  -470,   100,  -470,  1914,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,   278,   611,    14,  -470,  -470,
    -470,    41,  -470,   619,   613,  -470,  -470,  -470,   614,   617,
    -470,  -470,   275,  -470,  -470,  -470,   615,   612,   618,  -470,
    -470,  -470,  1357,   621,   640,   -89,   741,   620,  -470,  -470,
     616,  -470,  -470,  -470,  1357,  -470,  -470,  -470,   622,   626,
    -470,  -470,  1357,  1357,  -470,  -470,  -470,  -470,  1357,  1357
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -470,  -470,   774,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -391,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,    43,   767,  -470,  -470,   625,   -58,  -470,  -470,  -470,
    -134,  -154,  -296,  -470,  -470,  -470,   387,    81,  -470,    34,
    -470,  -470,   504,   111,  -470,  -470,    -1,   484,  -470,    97,
     120,   102,  -470,   130,  -470,  -470,  -470,   737,  -470,   403,
    -470,   406,  -470,   500,   181,  -470,  -470,  -470,  -470,   346,
    -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,  -470,   360,  -470,  -470,    54,
      42,  -470,  -470,  -470,  -470,    61,  -470,  -470,  -470,   351,
    -324,  -470,  -470,  -470,  -470,   386,  -470,  -470,  -470,  -470,
    -470,   -60,  -470,  -470,  -470,  -203,   159,   426,   -74,  -470,
    -470,  -330,  -470,  -231,   -64,   144,   675,  -470,   -61,   674,
    -299,  -470,   445,  -469,   653,  -470,  -470,  -112,  -115,   -29,
     -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -399
static const yytype_int16 yytable[] =
{
     162,   243,   226,   251,    55,   225,   343,   463,   407,   459,
     165,   412,   326,   168,   157,   500,   474,    69,   590,   253,
     198,   773,    70,    71,   479,   176,   244,   625,   177,   765,
     668,   229,   627,   204,   193,   304,     3,   222,   305,    27,
      75,    76,   765,   596,    64,   313,   315,    29,   229,    28,
      30,   204,    37,   385,   286,   239,   240,   287,   489,   774,
     382,   232,   233,    42,   235,   796,   306,   766,   505,   691,
     383,     2,     3,   229,    38,   794,   597,   386,    31,    44,
     766,    15,   384,   162,   185,   288,   253,   223,   486,   296,
      15,   505,   297,   165,    47,   247,   168,   248,   251,    86,
     253,  -349,    39,  -349,  -348,   519,  -348,   426,   427,   487,
    -349,    16,    50,  -348,    51,   284,   423,   423,    56,   626,
      16,   311,   345,   511,   628,   162,    77,    78,    54,    23,
      17,   461,   229,    22,   520,   165,   480,    33,   168,    17,
      23,    52,  -376,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   669,   206,  -376,
     277,   593,   385,   205,  -398,   278,    54,   775,   289,   162,
     178,   245,   338,   475,   617,   790,   206,   319,   162,   165,
     307,    18,   168,   351,  -376,    59,   386,    62,   165,  -398,
      18,   168,   332,  -127,  -127,   253,    32,   251,   793,   471,
      60,   381,   277,    33,   464,   794,   602,   278,   389,    61,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,    65,   226,
     630,   631,   472,  -376,    73,   661,   664,   665,  -398,    83,
     387,   230,    87,  -357,   632,   633,   343,   253,  -357,   507,
     661,   399,   462,   240,    67,    68,   387,   268,   269,   270,
     271,   272,   273,    84,    85,   467,   277,   162,   676,   162,
     586,   278,    24,    25,    26,    89,   477,   165,    90,   165,
     168,    91,   168,   738,   699,   741,   788,   106,   107,   108,
     109,   110,   226,    92,   685,   510,   271,   272,   273,    77,
      78,   173,   339,   340,   240,   317,   318,   339,   340,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   186,   253,   321,   322,   402,   403,   162,
     404,   405,   582,   174,   253,   571,   572,   175,   734,   165,
     638,   195,   168,   598,   318,   605,   619,   620,   692,   693,
     200,   492,   201,   253,   696,   697,   493,   781,   693,   203,
     226,   210,   345,   588,   202,   503,   328,   329,   214,   211,
     504,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   215,   180,   124,   216,   217,
     218,   528,   778,   779,   621,   224,   787,   220,   224,   341,
     622,   221,   658,   224,   341,   227,   228,   240,   234,   246,
     129,   276,   589,   275,   283,   106,   107,   108,   109,   110,
     281,   786,   342,   253,   293,   162,   282,   342,  -396,   294,
     298,   301,   116,   316,   312,   165,   310,   315,   168,   688,
     320,   334,   337,   119,   346,   347,   335,   352,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   253,   348,   226,   349,   354,   683,   623,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   355,   240,   240,   360,   359,   388,   390,   162,   181,
     391,   392,   724,   393,   396,   394,   395,   397,   165,   408,
     197,   168,   121,   122,   180,   124,   398,   400,   409,   162,
     410,   413,   414,   417,   343,   125,   126,   127,   205,   165,
     419,   420,   168,   422,   423,   128,   428,   424,   129,   430,
     130,   465,   466,  -172,  -398,   197,   197,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   473,   482,   483,   488,   226,   484,   485,   744,   226,
     495,   498,   747,   491,   490,   502,   505,   481,   506,   508,
       1,   513,   162,   515,     2,     3,   534,     4,   535,   516,
     517,     5,   165,     6,   240,   168,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
       7,   197,   523,   524,   526,     8,   314,   527,   530,   531,
     533,   751,   553,   554,   753,   555,   616,   556,   805,   567,
     325,   325,   327,   325,   325,   331,   573,   574,   575,   576,
     345,   577,   579,   580,   578,   804,   583,   587,   240,   240,
     591,   594,   592,   603,   595,   599,   600,   226,   812,   813,
     800,   606,   601,   607,   608,   612,   613,   629,   636,   361,
     365,   657,   818,   819,   663,   667,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   197,   673,   672,   674,   677,   678,   670,   197,   679,
     680,   681,   682,   687,   690,   691,   694,   695,   162,   223,
     702,   722,   703,   704,   705,   716,   723,   727,   165,   726,
     162,   168,   729,   735,   731,   736,   740,   743,   162,   162,
     165,   416,   732,   168,   162,   162,   733,   770,   165,   165,
     756,   168,   168,   761,   165,   165,   769,   168,   168,   772,
     325,   777,   197,   197,   253,   780,   782,   796,   807,   798,
     784,   785,   799,   789,   802,   197,   806,   809,   801,   811,
     803,   815,   810,    35,   814,   783,   197,    93,    40,    94,
      95,    96,    97,   501,   754,   746,     1,    98,    99,   285,
     100,   401,   418,   101,   739,    88,   496,     5,   102,     6,
     103,   497,   104,   105,   197,   106,   107,   108,   109,   110,
     111,   112,   421,   113,   253,   585,     7,   795,   791,   584,
     114,   115,   116,   117,   581,   550,   118,   808,   253,   752,
     279,   280,   494,   119,   120,   309,     0,     0,     0,   514,
       0,     0,     0,     0,   518,     0,     0,   522,     0,     0,
     525,     0,     0,   529,     0,     0,   532,     0,     0,     0,
     545,   546,   547,   548,   549,   551,   552,     0,     0,     0,
       0,   566,     0,   568,     0,     0,     0,     0,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,     0,     0,     0,   365,     0,     0,     0,   325,
       0,     0,   121,   122,   123,   124,     0,   197,   624,     0,
       0,     0,     0,     0,     0,   125,   126,   127,     0,     0,
       0,     0,     0,     0,   604,   128,     0,     0,   129,     0,
     130,   253,     0,     0,   131,   132,     0,   133,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,     0,     0,   634,   656,
       0,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,     0,   635,     1,    98,    99,     0,   100,   662,     0,
     101,     0,   197,   197,     5,   102,     6,   103,     0,   104,
     105,     0,   106,   107,   108,   109,   110,   111,   112,     0,
     113,     0,     0,     7,     0,     0,     0,   114,   115,   116,
     117,     0,     0,   118,   106,   107,   108,   109,   110,     0,
     119,   120,     0,   698,     0,   700,   701,     0,     0,     0,
       0,   748,     0,     0,     0,     0,     0,   706,     0,   707,
       0,     0,     0,     0,   715,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,     0,
       0,     0,     0,   718,   719,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   637,     0,     0,     0,     0,
     730,     0,     0,     0,   197,     0,     0,     0,     0,   121,
     122,   123,   124,     0,     0,     0,     0,   745,     0,     0,
       0,     0,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,   128,   749,   124,   129,     0,   130,   253,     0,
       0,   131,   250,     0,   133,     0,     0,     0,     0,     0,
       0,    93,     0,    94,    95,    96,    97,   129,   197,   197,
       1,    98,    99,     0,   100,     0,     0,   101,     0,     0,
       0,     5,   102,     6,   103,     0,   104,   105,     0,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   253,     0,
       7,     0,     0,     0,   114,   115,   116,   117,     0,     0,
     118,    93,     0,    94,    95,    96,    97,   119,   120,     0,
       1,    98,    99,     0,   100,     0,     0,   101,     0,     0,
       0,     5,   102,     6,   103,     0,   104,   105,     0,   106,
     107,   108,   109,   110,   111,   112,     0,   113,     0,     0,
       7,     0,     0,     0,   114,   115,   116,   117,     0,     0,
     118,     0,     0,     0,     0,     0,     0,   119,   120,     0,
       0,     0,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,   127,   659,     0,   253,     0,     0,     0,     0,   128,
       0,     0,   129,     0,   130,     0,     0,     0,   131,   350,
     253,   133,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,   127,   717,   253,     0,     0,     0,     0,     0,   128,
       0,     0,   129,     0,   130,     0,     0,     0,   131,   468,
      93,   133,    94,    95,    96,    97,     0,     0,     0,     1,
      98,    99,     0,   100,     0,     0,   101,     0,     0,     0,
       5,   102,     6,   103,     0,   104,   105,     0,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   253,     0,     7,
       0,     0,     0,   114,   115,   116,   117,     0,     0,   118,
       0,   253,     0,     0,     0,     0,   119,   120,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,     0,     0,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   720,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   757,     0,     0,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,     0,     0,     0,     0,   121,   122,   123,   124,     0,
       0,     0,     0,     0,   253,     0,     0,   758,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,   128,   253,
       0,   129,     0,   130,     0,     0,     0,   131,     0,     0,
     133,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   253,
       0,   759,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   760,     0,     0,     0,     0,
       0,     0,   253,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,     0,     0,   762,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   763,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   253,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,     0,   764,     0,
       0,     0,     0,     0,     0,     0,     0,   425,   253,     0,
       0,     0,     0,     0,   611,     0,     0,     0,     0,     0,
       0,     0,     0,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,     0,     0,     0,
       0,     0,     0,     0,     0,   415,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
      24,    25,    26,     0,     0,     0,     0,     0,   689,     0,
       0,   106,   107,   108,   109,   110,     0,     0,    34,     0,
       0,     0,   253,     0,     0,     0,     0,     0,   116,     0,
       1,     0,     0,     0,     2,     3,     0,     4,     0,   119,
       0,     5,     0,     6,     0,     0,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
       7,     0,     0,     0,   254,     8,     0,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,   122,
     180,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,   126,   127,   236,     0,     0,     0,     0,   431,
       0,   128,     0,     0,   129,     0,   130,   432,     0,     0,
       0,     0,     0,     0,     0,   237,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
       0,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   431,   444,   445,   446,   447,   448,   449,   450,
     432,   451,   452,   453,   454,   455,     0,   456,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,     0,   444,   445,   446,   447,
     448,   449,   450,     0,   451,   452,   453,   454,   455,     0,
     456,   457,   431,     0,     0,     0,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   458,   660,     0,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,     0,   444,   445,   446,   447,
     448,   449,   450,     0,   451,   452,   453,   454,   455,     0,
     456,   457,   106,   107,   108,   109,   110,     0,   106,   107,
     108,   109,   110,     0,   458,   671,     0,     0,     0,   116,
       0,     0,     0,     0,     0,   116,     0,     0,     0,     0,
     119,     0,     0,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   458,   106,   107,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,     0,     0,     0,   121,
     122,   180,   124,   119,     0,   121,   122,   180,   124,     0,
       0,     0,   125,   126,   127,     0,     0,     0,   125,   126,
     127,     0,   128,     0,     0,   129,     0,   130,   128,     0,
       0,   129,     0,   130,   196,     0,     0,   362,     0,     0,
       0,     0,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,     0,     0,
     106,   107,   108,   109,   110,     0,   106,   107,   108,   109,
     110,     0,   121,   122,   180,   124,     0,   116,     0,     0,
       0,     0,     0,   116,     0,   125,   126,   127,   119,     0,
       0,     0,     0,     0,   119,   128,     0,     0,   129,     0,
     130,   106,   107,   108,   109,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,   536,
     537,   538,   539,   540,   541,   542,   543,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   557,
     558,   559,   560,   561,   562,   563,   564,   121,   122,   180,
     124,     0,     0,   121,   122,   180,   124,     0,     0,     0,
     125,   126,   127,     0,     0,     0,   125,   126,   127,     0,
     128,     0,     0,   129,     0,   130,   128,     0,     0,   129,
       0,   130,   708,   709,   710,   711,   712,   713,   121,   122,
     180,   124,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   125,   126,   127,     0,     0,     0,     0,     0,   116,
       0,   128,     0,     0,   129,     0,   130,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     122,   180,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,   129,     0,   130
};

static const yytype_int16 yycheck[] =
{
      74,   135,   117,   157,    33,   117,   237,   337,   304,   333,
      74,   310,   215,    74,    74,   406,     4,    50,   487,     9,
      94,    15,    51,    52,    51,    16,    10,    71,    19,    15,
       9,    43,    71,    18,    92,    16,    17,    39,    19,     5,
      44,    45,    15,   130,    45,   199,   132,    16,    43,   130,
      19,    18,   130,   130,    16,   129,   130,    19,   388,    53,
      28,   125,   126,   130,   128,   154,    47,    53,   154,   132,
      38,    16,    17,    43,    19,   164,   163,   154,    47,    21,
      53,     0,    50,   157,    85,    47,     9,   116,   144,   161,
       9,   154,   164,   157,   130,   160,   157,   162,   252,    65,
       9,   155,    47,   157,   155,   429,   157,   155,   155,   165,
     164,     0,   137,   164,   137,   173,   164,   164,   160,   163,
       9,   195,   237,   419,   163,   199,   130,   131,   130,   137,
       0,   334,    43,   130,   430,   199,   163,   137,   199,     9,
     137,   162,   154,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   136,   143,   154,
     153,   491,   130,   130,   159,   158,   130,   161,   130,   243,
     161,   155,   236,   161,   164,   161,   143,   210,   252,   243,
     161,     0,   243,   243,   154,   163,   154,   130,   252,   159,
       9,   252,   221,   163,   164,     9,   130,   351,   157,   353,
     160,   275,   153,   137,   155,   164,   505,   158,   282,   138,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   162,   354,
     163,   164,   354,   154,   138,   569,   576,   577,   159,   132,
     279,   162,   160,   153,   163,   164,   487,     9,   158,   413,
     584,   294,   336,   337,   163,   164,   295,   141,   142,   143,
     144,   145,   146,   163,   164,   349,   153,   351,   155,   353,
     483,   158,    20,    21,    22,   138,   360,   351,   138,   353,
     351,   160,   353,   684,   618,   686,   765,    31,    32,    33,
      34,    35,   417,   130,   600,   417,   144,   145,   146,   130,
     131,   154,    34,    35,   388,   163,   164,    34,    35,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   130,     9,   163,   164,   163,   164,   413,
     163,   164,   476,   154,     9,   163,   164,   154,   678,   413,
     164,   154,   413,   163,   164,   509,    88,    89,   163,   164,
     154,   394,   154,     9,   163,   164,   395,   163,   164,   130,
     485,   137,   487,   485,   163,   408,   217,   218,   154,   130,
     409,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   154,   130,   131,   156,   154,
     154,     7,   732,   733,    79,   130,   128,   163,   130,   131,
      85,   137,   164,   130,   131,   154,   163,   491,   130,   130,
     154,   131,   486,   132,   159,    31,    32,    33,    34,    35,
     163,   755,   154,     9,   130,   509,   156,   154,   156,   137,
     130,   130,    48,   130,   163,   509,   154,   132,   509,   603,
     132,   154,   154,    59,   155,   155,   163,   130,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     9,   157,   599,   164,     9,   599,   163,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     3,   576,   577,   154,    27,   154,   130,   582,    83,
     155,   155,   666,   130,   155,   137,   137,   164,   582,   137,
      94,   582,   128,   129,   130,   131,   163,   163,   137,   603,
     130,   155,     7,   132,   765,   141,   142,   143,   130,   603,
     138,   128,   603,   155,   164,   151,    40,   155,   154,   138,
     156,   131,   155,    11,   159,   129,   130,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   154,   163,   154,   159,   690,   154,   154,   690,   694,
     138,   130,   694,   154,   157,   130,   154,   163,   155,   154,
      12,   163,   666,   163,    16,    17,    67,    19,    67,   163,
     163,    23,   666,    25,   678,   666,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      42,   195,   163,   163,   163,    47,   200,   163,   163,   163,
     163,   695,    67,   163,   695,   163,   163,   163,   792,   163,
     214,   215,   216,   217,   218,   219,   155,   155,   155,   154,
     765,   154,    11,    30,   155,   789,   155,   155,   732,   733,
     130,   138,   155,     4,   138,   132,   138,   782,   802,   803,
     782,   163,   138,   130,   130,   130,   130,   163,   163,   253,
     254,   164,   816,   817,   160,   130,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   163,   155,   164,   155,   154,   160,   282,   155,
     130,   130,   163,   155,   132,   132,   132,   132,   792,   748,
     163,   155,   163,   163,   163,   163,   155,   128,   792,   156,
     804,   792,   163,   163,   155,   130,   130,   163,   812,   813,
     804,   315,   154,   804,   818,   819,   154,   128,   812,   813,
     163,   812,   813,   163,   818,   819,   155,   818,   819,   155,
     334,   163,   336,   337,     9,   155,   132,   154,   128,   155,
     163,   163,   155,   162,   162,   349,   155,    36,   163,   163,
     162,   155,   162,     9,   162,   742,   360,     3,    21,     5,
       6,     7,     8,   406,   697,   693,    12,    13,    14,   174,
      16,   297,   318,    19,   684,    68,   403,    23,    24,    25,
      26,   405,    28,    29,   388,    31,    32,    33,    34,    35,
      36,    37,   322,    39,     9,   479,    42,   773,   767,   478,
      46,    47,    48,    49,   474,   449,    52,   795,     9,   695,
     165,   167,   397,    59,    60,   192,    -1,    -1,    -1,   423,
      -1,    -1,    -1,    -1,   428,    -1,    -1,   431,    -1,    -1,
     434,    -1,    -1,   437,    -1,    -1,   440,    -1,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,    -1,    -1,    -1,
      -1,   455,    -1,   457,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,   479,    -1,    -1,    -1,   483,
      -1,    -1,   128,   129,   130,   131,    -1,   491,   163,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,    -1,
      -1,    -1,    -1,    -1,   508,   151,    -1,    -1,   154,    -1,
     156,     9,    -1,    -1,   160,   161,    -1,   163,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,   163,   553,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
      -1,    -1,   163,    12,    13,    14,    -1,    16,   572,    -1,
      19,    -1,   576,   577,    23,    24,    25,    26,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    -1,    -1,    52,    31,    32,    33,    34,    35,    -1,
      59,    60,    -1,   617,    -1,   619,   620,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,   631,    -1,   633,
      -1,    -1,    -1,    -1,   638,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   657,   658,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
     674,    -1,    -1,    -1,   678,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,   691,    -1,    -1,
      -1,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   130,   131,   154,    -1,   156,     9,    -1,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,   154,   732,   733,
      12,    13,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,     9,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      52,     3,    -1,     5,     6,     7,     8,    59,    60,    -1,
      12,    13,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   163,    -1,     9,    -1,    -1,    -1,    -1,   151,
      -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,   161,
       9,   163,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   163,     9,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,   161,
       3,   163,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,     9,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,
      -1,     9,    -1,    -1,    -1,    -1,    59,    60,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   163,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,   163,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,   163,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,     9,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,
     163,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     9,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,     9,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     9,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,     9,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    31,    32,    33,    34,    35,    -1,    -1,     0,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      12,    -1,    -1,    -1,    16,    17,    -1,    19,    -1,    59,
      -1,    23,    -1,    25,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      42,    -1,    -1,    -1,    51,    47,    -1,    54,    55,    56,
      57,    58,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    28,
      -1,   151,    -1,    -1,   154,    -1,   156,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    28,    72,    73,    74,    75,    76,    77,    78,
      36,    80,    81,    82,    83,    84,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    31,    32,    33,    34,    35,    -1,    31,    32,
      33,    34,    35,    -1,   160,   161,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    59,    -1,   128,   129,   130,   131,    -1,
      -1,    -1,   141,   142,   143,    -1,    -1,    -1,   141,   142,
     143,    -1,   151,    -1,    -1,   154,    -1,   156,   151,    -1,
      -1,   154,    -1,   156,   163,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      31,    32,    33,    34,    35,    -1,    31,    32,    33,    34,
      35,    -1,   128,   129,   130,   131,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    48,    -1,   141,   142,   143,    59,    -1,
      -1,    -1,    -1,    -1,    59,   151,    -1,    -1,   154,    -1,
     156,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   128,   129,   130,
     131,    -1,    -1,   128,   129,   130,   131,    -1,    -1,    -1,
     141,   142,   143,    -1,    -1,    -1,   141,   142,   143,    -1,
     151,    -1,    -1,   154,    -1,   156,   151,    -1,    -1,   154,
      -1,   156,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,    48,
      -1,   151,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,   154,    -1,   156
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    16,    17,    19,    23,    25,    42,    47,   167,
     168,   169,   181,   185,   188,   203,   209,   219,   230,   310,
     311,   231,   130,   137,    20,    21,    22,   205,   130,    16,
      19,    47,   130,   137,     0,   168,   186,   130,    19,    47,
     188,   182,   130,   316,    21,   210,   204,   130,   222,   223,
     137,   137,   162,   171,   130,   315,   160,   187,   189,   163,
     160,   138,   130,   211,   212,   162,   206,   163,   164,   316,
     315,   315,   170,   138,   196,    44,    45,   130,   131,   190,
     191,   192,   183,   132,   163,   164,   205,   160,   223,   138,
     138,   160,   130,     3,     5,     6,     7,     8,    13,    14,
      16,    19,    24,    26,    28,    29,    31,    32,    33,    34,
      35,    36,    37,    39,    46,    47,    48,    49,    52,    59,
      60,   128,   129,   130,   131,   141,   142,   143,   151,   154,
     156,   160,   161,   163,   194,   195,   197,   199,   203,   209,
     219,   230,   232,   237,   238,   241,   248,   249,   250,   251,
     253,   255,   256,   267,   272,   285,   286,   287,   288,   289,
     290,   293,   294,   296,   299,   300,   301,   303,   304,   312,
     313,   314,   315,   154,   154,   154,    16,    19,   161,   184,
     130,   293,   294,   300,   304,   212,   130,   207,   208,   212,
     220,   221,   172,   192,   193,   154,   163,   293,   294,   240,
     154,   154,   163,   130,    18,   130,   143,   198,   202,   213,
     137,   130,   228,   229,   154,   154,   156,   154,   154,   273,
     163,   137,    39,   315,   130,   313,   314,   154,   163,    43,
     162,   305,   300,   300,   130,   300,   144,   165,   205,   294,
     294,   297,   298,   196,    10,   155,   130,   160,   162,   254,
     161,   197,   287,     9,    51,    54,    55,    56,    57,    58,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   233,   132,   131,   153,   158,   302,
     305,   163,   156,   159,   192,   191,    16,    19,    47,   130,
     306,   307,   308,   130,   137,   302,   161,   164,   130,   224,
     225,   130,   226,   227,    16,    19,    47,   161,   173,   310,
     154,   294,   163,   197,   293,   132,   130,   163,   164,   316,
     132,   163,   164,   291,   292,   293,   291,   293,   292,   292,
     274,   293,   315,   295,   154,   163,   268,   154,   300,    34,
      35,   131,   154,   299,   309,   314,   155,   155,   157,   164,
     161,   287,   130,   242,     9,     3,   261,   262,   264,    27,
     154,   293,   160,   234,   235,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   294,    28,    38,    50,   130,   154,   315,   154,   294,
     130,   155,   155,   130,   137,   137,   155,   164,   163,   316,
     163,   208,   163,   164,   163,   164,   174,   198,   137,   137,
     130,   179,   306,   155,     7,   155,   293,   132,   213,   138,
     128,   229,   155,   164,   155,   157,   155,   155,    40,   284,
     138,    28,    36,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    72,    73,    74,    75,    76,    77,
      78,    80,    81,    82,    83,    84,    86,    87,   160,   276,
     279,   291,   294,   297,   155,   131,   155,   294,   161,   243,
     245,   197,   313,   154,     4,   161,   263,   294,   236,    51,
     163,   163,   163,   154,   154,   154,   144,   165,   159,   297,
     157,   154,   316,   315,   308,   138,   225,   227,   130,   177,
     179,   202,   130,   316,   315,   154,   155,   197,   154,   239,
     313,   198,   200,   163,   293,   163,   163,   163,   293,   276,
     198,   201,   293,   163,   163,   293,   163,   163,     7,   293,
     163,   163,   293,   163,    67,    67,    90,    91,    92,    93,
      94,    95,    96,    97,   281,   293,   293,   293,   293,   293,
     281,   293,   293,    67,   163,   163,   163,   114,   115,   116,
     117,   118,   119,   120,   121,   283,   293,   163,   293,   275,
     276,   163,   164,   155,   155,   155,   154,   154,   155,    11,
      30,   262,   196,   155,   275,   235,   291,   155,   313,   300,
     309,   130,   155,   297,   138,   138,   130,   163,   163,   132,
     138,   138,   306,     4,   293,   197,   163,   130,   130,   216,
     217,    41,   130,   130,   214,   215,   163,   164,   277,    88,
      89,    79,    85,   163,   163,    71,   163,    71,   163,   163,
     163,   164,   163,   164,   163,   163,   163,   163,   164,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   282,   293,   164,   164,   163,
     161,   276,   293,   160,   297,   297,   244,   130,     9,   136,
     160,   161,   155,   163,   164,   252,   155,   155,   154,   155,
     130,   130,   163,   313,   175,   198,   176,   155,   197,   155,
     132,   132,   163,   164,   132,   132,   163,   164,   293,   276,
     293,   293,   163,   163,   163,   163,   293,   293,   122,   123,
     124,   125,   126,   127,   280,   293,   163,   163,   293,   293,
     163,   269,   155,   155,   197,   246,   156,   128,   257,   163,
     293,   155,   154,   154,   297,   163,   130,   178,   179,   216,
     130,   179,   180,   163,   313,   293,   217,   313,    48,   130,
     218,   300,   301,   304,   215,   278,   163,   163,   163,   163,
     163,   163,   163,   163,   163,    15,    53,   270,   271,   155,
     128,   265,   155,    15,    53,   161,   258,   163,   297,   297,
     155,   163,   132,   187,   163,   163,   276,   128,   309,   162,
     161,   271,   247,   157,   164,   265,   154,   266,   155,   155,
     313,   163,   162,   162,   196,   197,   155,   128,   266,    36,
     162,   163,   196,   196,   162,   155,   260,   259,   196,   196
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
# if YYLTYPE_IS_TRIVIAL
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


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
        case 5:

/* Line 1455 of yacc.c  */
#line 222 "ucparse.yy"
    {
		if (!Uc_function::add_global_function_symbol((yyvsp[(1) - (1)].funsym)))
			delete (yyvsp[(1) - (1)].funsym);
		}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 235 "ucparse.yy"
    { (yyvsp[(3) - (3)].cls) ? cur_class = new Uc_class((yyvsp[(2) - (3)].strval), (yyvsp[(3) - (3)].cls))
		     : cur_class = new Uc_class((yyvsp[(2) - (3)].strval)); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 238 "ucparse.yy"
    {
		units.push_back(cur_class);
		// Add to 'globals' symbol table.
		(void) Uc_class_symbol::create((yyvsp[(2) - (7)].strval), cur_class);
		cur_class = 0;
		}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 248 "ucparse.yy"
    { (yyval.cls) = (yyvsp[(2) - (2)].cls); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 250 "ucparse.yy"
    { (yyval.cls) = 0; }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 259 "ucparse.yy"
    { has_ret = true; }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 260 "ucparse.yy"
    { has_ret = false; }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 262 "ucparse.yy"
    { cur_class->add_alias((yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].var)); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 263 "ucparse.yy"
    { struct_type = (yyvsp[(3) - (4)].struc); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 264 "ucparse.yy"
    { struct_type = 0; }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 266 "ucparse.yy"
    { cur_class->add_alias((yyvsp[(6) - (9)].strval), (yyvsp[(8) - (9)].var), (yyvsp[(3) - (9)].struc)); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 267 "ucparse.yy"
    { class_type = (yyvsp[(3) - (4)].cls); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 268 "ucparse.yy"
    { class_type = 0; }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 284 "ucparse.yy"
    {
		(yyvsp[(3) - (4)].varvec)->insert((yyvsp[(3) - (4)].varvec)->begin(),		// So it's local[0].
			new Uc_class_inst_symbol("this", cur_class, 0));
		Uc_function_symbol *funsym = 
			Uc_function_symbol::create((yyvsp[(1) - (4)].strval), -1, *(yyvsp[(3) - (4)].varvec), false,
					cur_class->get_scope(), Uc_function_symbol::utility_fun);
		delete (yyvsp[(3) - (4)].varvec);		// A copy was made.
		
		// Set return type.
		if (has_ret)
			funsym->set_ret_type(true);
		else if (class_type)
			funsym->set_ret_type(class_type);
		else if (struct_type)
			funsym->set_ret_type(struct_type);
		has_ret = false;
		class_type = 0;
		struct_type = 0;

		cur_fun = new Uc_function(funsym, cur_class->get_scope());
		}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 306 "ucparse.yy"
    {
		cur_class->add_method(cur_fun);
		cur_fun = 0;
		}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 314 "ucparse.yy"
    { cur_struct = new Uc_struct_symbol((yyvsp[(2) - (2)].strval)); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 316 "ucparse.yy"
    {
		// Add to 'globals' symbol table.
		Uc_function::add_global_struct_symbol(cur_struct);
		cur_struct = 0;
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 330 "ucparse.yy"
    { cur_struct->add((yyvsp[(2) - (3)].strval)); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 332 "ucparse.yy"
    { cur_struct->merge_struct((yyvsp[(3) - (5)].struc)); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 334 "ucparse.yy"
    { cur_struct->merge_struct((yyvsp[(3) - (6)].struc)); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 338 "ucparse.yy"
    { cur_fun = new Uc_function((yyvsp[(1) - (1)].funsym)); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 340 "ucparse.yy"
    {
		units.push_back(cur_fun);
		cur_fun = 0;
		}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 348 "ucparse.yy"
    {
		cur_fun->set_statement((yyvsp[(2) - (3)].block));
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 352 "ucparse.yy"
    {	// Function ends in label.
		(yyvsp[(2) - (4)].block)->add((yyvsp[(3) - (4)].stmt));
		cur_fun->set_statement((yyvsp[(2) - (4)].block));
		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 360 "ucparse.yy"
    { start_fun_id(); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 361 "ucparse.yy"
    {
		end_fun_id();
		if ((yyvsp[(4) - (7)].funid)->kind != Uc_function_symbol::utility_fun)
			{
			char buf[180];
			if (has_ret || struct_type)
				{
				sprintf(buf, "Functions declared with '%s#' cannot return a value",
					(yyvsp[(4) - (7)].funid)->kind == Uc_function_symbol::shape_fun ? "shape" : "object");
				yyerror(buf);
				}
			if (!(yyvsp[(6) - (7)].varvec)->empty())
				{
				sprintf(buf, "Functions declared with '%s#' cannot have arguments",
					(yyvsp[(4) - (7)].funid)->kind == Uc_function_symbol::shape_fun ? "shape" : "object");
				yyerror(buf);
				}
			}
		(yyval.funsym) = Uc_function_symbol::create((yyvsp[(2) - (7)].strval), (yyvsp[(4) - (7)].funid)->id, *(yyvsp[(6) - (7)].varvec), is_extern, 0, (yyvsp[(4) - (7)].funid)->kind);
		if (has_ret)
			(yyval.funsym)->set_ret_type(true);
		else if (struct_type)
			(yyval.funsym)->set_ret_type(struct_type);
		delete (yyvsp[(6) - (7)].varvec);		// A copy was made.
		delete (yyvsp[(4) - (7)].funid);
		has_ret = false;
		struct_type = 0;
		}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 390 "ucparse.yy"
    {
		(yyval.funsym) = Uc_function_symbol::create((yyvsp[(5) - (9)].strval), (yyvsp[(6) - (9)].intval), *(yyvsp[(8) - (9)].varvec), is_extern, 0,
				Uc_function_symbol::utility_fun);
		(yyval.funsym)->set_ret_type((yyvsp[(3) - (9)].cls));
		delete (yyvsp[(8) - (9)].varvec);		// A copy was made.
		}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 400 "ucparse.yy"
    {
		(yyval.funid) = new Fun_id_info(Uc_function_symbol::shape_fun, (yyvsp[(3) - (4)].intval) < 0 ? -1 : (yyvsp[(3) - (4)].intval));
		if ((yyvsp[(3) - (4)].intval) < 0)
			{
			char buf[180];
			sprintf(buf, "Shape number cannot be negative");
			yyerror(buf);
			}
		}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 410 "ucparse.yy"
    { (yyval.funid) = new Fun_id_info(Uc_function_symbol::object_fun, (yyvsp[(3) - (4)].intval)); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 412 "ucparse.yy"
    { (yyval.funid) = new Fun_id_info(Uc_function_symbol::utility_fun, (yyvsp[(1) - (1)].intval)); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 418 "ucparse.yy"
    { (yyval.intval) = -1; }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 424 "ucparse.yy"
    {
		Uc_symbol *sym = Uc_function::search_globals((yyvsp[(1) - (1)].strval));
		Uc_const_int_symbol *var;
		char buf[180];
		if (!sym)
			{
			sprintf(buf, "'%s' not declared", (yyvsp[(1) - (1)].strval));
			yyerror(buf);
			(yyval.intval) = -1;
			}
		else if ((var = dynamic_cast<Uc_const_int_symbol *>(sym)) == 0)
			{
			sprintf(buf, "'%s' is not a constant integer", (yyvsp[(1) - (1)].strval));
			yyerror(buf);
			(yyval.intval) = -1;
			}
		else
			(yyval.intval) = var->get_value();
		}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 448 "ucparse.yy"
    { (yyval.intval) = -1; }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 453 "ucparse.yy"
    {
		(yyval.stmt) = (yyvsp[(2) - (3)].block);
		cur_fun->pop_scope();
		}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 458 "ucparse.yy"
    {	// Block ends in label.
		(yyvsp[(2) - (4)].block)->add((yyvsp[(3) - (4)].stmt));
		(yyval.stmt) = (yyvsp[(2) - (4)].block);
		cur_fun->pop_scope();
		}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 464 "ucparse.yy"
    {	// Label followed by statements; "grab" next statement for label.
		if ((yyvsp[(2) - (2)].stmt))
			{
			Uc_block_statement *stmt = new Uc_block_statement();
			stmt->add((yyvsp[(1) - (2)].stmt));
			stmt->add((yyvsp[(2) - (2)].stmt));
			(yyval.stmt) = stmt;
			}
		else	// This is the case for the "null" statement ';'.
			(yyval.stmt) = (yyvsp[(1) - (2)].stmt);
		}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 479 "ucparse.yy"
    { cur_fun->push_scope(); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 484 "ucparse.yy"
    {
		if ((yyvsp[(2) - (2)].stmt))
			(yyval.block)->add((yyvsp[(2) - (2)].stmt)); 
		}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 489 "ucparse.yy"
    { (yyval.block) = new Uc_block_statement(); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 510 "ucparse.yy"
    { (yyval.stmt) = new Uc_say_statement((yyvsp[(3) - (5)].exprlist)); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 512 "ucparse.yy"
    { (yyval.stmt) = new Uc_message_statement((yyvsp[(3) - (5)].exprlist)); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 515 "ucparse.yy"
    { (yyval.stmt) = new Uc_abort_statement(); }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 517 "ucparse.yy"
    { (yyval.stmt) = 0; }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 527 "ucparse.yy"
    { (yyval.stmt) = (yyvsp[(2) - (3)].stmt); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 529 "ucparse.yy"
    { cur_fun->add_alias((yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].var)); (yyval.stmt) = 0; }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 530 "ucparse.yy"
    { struct_type = (yyvsp[(3) - (4)].struc); }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 531 "ucparse.yy"
    { struct_type = 0; (yyval.stmt) = (yyvsp[(6) - (7)].stmt); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 533 "ucparse.yy"
    { cur_fun->add_alias((yyvsp[(6) - (9)].strval), (yyvsp[(8) - (9)].var), (yyvsp[(3) - (9)].struc)); (yyval.stmt) = 0; }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 534 "ucparse.yy"
    { class_type = (yyvsp[(3) - (4)].cls); }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 535 "ucparse.yy"
    { class_type = 0; (yyval.stmt) = (yyvsp[(6) - (7)].stmt); }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 537 "ucparse.yy"
    {
		if (!(yyvsp[(8) - (9)].var)->get_cls())
			yyerror("Can't convert non-class into class.");
		else if (!Incompatible_classes_error((yyvsp[(8) - (9)].var)->get_cls(), (yyvsp[(3) - (9)].cls)))
				// Alias may be of different (compatible) class.
			cur_fun->add_alias((yyvsp[(6) - (9)].strval), (yyvsp[(8) - (9)].var), (yyvsp[(3) - (9)].cls));
		(yyval.stmt) = 0;
		}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 546 "ucparse.yy"
    { (yyval.stmt) = 0; }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 548 "ucparse.yy"
    { (yyval.stmt) = 0; }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 550 "ucparse.yy"
    { (yyval.stmt) = 0; }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 552 "ucparse.yy"
    {
		if (!cur_fun->add_function_symbol((yyvsp[(1) - (1)].funsym), cur_class ?
				cur_class->get_scope() : 0))
			delete (yyvsp[(1) - (1)].funsym);
		(yyval.stmt) = 0;
		}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 559 "ucparse.yy"
    { (yyval.stmt) = 0; }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 564 "ucparse.yy"
    {
		if (!(yyvsp[(3) - (3)].stmt))
			(yyval.stmt) = (yyvsp[(1) - (3)].stmt);
		else if (!(yyvsp[(1) - (3)].stmt))
			(yyval.stmt) = (yyvsp[(3) - (3)].stmt);
		else			/* Both nonzero.  Need a list. */
			{
			Uc_block_statement *b = 
				dynamic_cast<Uc_block_statement *>((yyvsp[(1) - (3)].stmt));
			if (!b)
				{
				b = new Uc_block_statement();
				b->add((yyvsp[(1) - (3)].stmt));
				}
			b->add((yyvsp[(3) - (3)].stmt));
			(yyval.stmt) = b;
			}
		}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 583 "ucparse.yy"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 587 "ucparse.yy"
    { enum_val = -1; }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 589 "ucparse.yy"
    { const_opcode.pop_back(); }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 594 "ucparse.yy"
    { (yyval.intval) = UC_PUSHI; }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 596 "ucparse.yy"
    { (yyval.intval) = UC_PUSHB; }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 598 "ucparse.yy"
    { (yyval.intval) = UC_PUSHI32; }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 600 "ucparse.yy"
    { (yyval.intval) = UC_PUSHI32; }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 605 "ucparse.yy"
    { const_opcode.push_back((yyvsp[(2) - (2)].intval)); }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 607 "ucparse.yy"
    { const_opcode.push_back(UC_PUSHI); }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 618 "ucparse.yy"
    {			/* Increment last value.	*/
		++enum_val;
		int op = const_opcode.back();
		if (cur_fun)
			cur_fun->add_int_const_symbol((yyvsp[(1) - (1)].strval), enum_val, op);
		else			// Global.
			Uc_function::add_global_int_const_symbol((yyvsp[(1) - (1)].strval), enum_val, op);
		}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 629 "ucparse.yy"
    { const_opcode.push_back((yyvsp[(2) - (2)].intval)); }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 631 "ucparse.yy"
    { const_opcode.pop_back(); }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 641 "ucparse.yy"
    {
		int val;		// Get constant.
		if ((yyvsp[(3) - (3)].expr)->eval_const(val))
			{
			int op = const_opcode.back();
			if (cur_fun)
				cur_fun->add_int_const_symbol((yyvsp[(1) - (3)].strval), val, op);
			else		// Global.
				Uc_function::add_global_int_const_symbol((yyvsp[(1) - (3)].strval), val, op);
			enum_val = val;	// In case we're in an enum.
			}
		else
			yyerror("Integer constant expected.");
		}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 659 "ucparse.yy"
    {
		if (cur_fun)
			cur_fun->add_symbol((yyvsp[(1) - (1)].strval));
		else
			cur_class->add_symbol((yyvsp[(1) - (1)].strval));
		(yyval.stmt) = 0;
		}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 667 "ucparse.yy"
    {
		if (cur_class && !cur_fun)
			{
			char buf[180];
			sprintf(buf, "Initialization of class member var '%s' must be done through constructor", (yyvsp[(1) - (3)].strval));
			yyerror(buf);
			(yyval.stmt) = 0;
			}
		else
			{
			Uc_var_symbol *var = cur_fun ? cur_fun->add_symbol((yyvsp[(1) - (3)].strval))
							 : cur_class->add_symbol((yyvsp[(1) - (3)].strval));
			var->set_is_obj_fun((yyvsp[(3) - (3)].expr)->is_object_function(false));
			(yyval.stmt) = new Uc_assignment_statement(new Uc_var_expression(var), (yyvsp[(3) - (3)].expr));
			}
		}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 687 "ucparse.yy"
    {
		if (!(yyvsp[(3) - (3)].stmt))
			(yyval.stmt) = (yyvsp[(1) - (3)].stmt);
		else if (!(yyvsp[(1) - (3)].stmt))
			(yyval.stmt) = (yyvsp[(3) - (3)].stmt);
		else		/*	Both nonzero; need a list.	*/
			{
			Uc_block_statement *b = dynamic_cast<Uc_block_statement *>((yyvsp[(1) - (3)].stmt));
			if (!b)
				{
				b = new Uc_block_statement();
				b->add((yyvsp[(1) - (3)].stmt));
				}
			b->add((yyvsp[(3) - (3)].stmt));
			(yyval.stmt) = b;
			}
		}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 705 "ucparse.yy"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 710 "ucparse.yy"
    {
		if (cur_fun)
			cur_fun->add_symbol((yyvsp[(1) - (1)].strval), class_type);
		else
			// Unsupported for now
			;
		(yyval.stmt) = 0;
		}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 719 "ucparse.yy"
    {
		if (Nonclass_unexpected_error((yyvsp[(3) - (3)].expr)))
			(yyval.stmt) = 0;
		else
			{
			Uc_class *src = (yyvsp[(3) - (3)].expr)->get_cls();
			if (Incompatible_classes_error(src, class_type))
				(yyval.stmt) = 0;
			else
				{
				Uc_var_symbol *v = cur_fun->add_symbol((yyvsp[(1) - (3)].strval), class_type);
				(yyval.stmt) = new Uc_assignment_statement(new Uc_class_expression(v), (yyvsp[(3) - (3)].expr));
				}
			}
		}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 738 "ucparse.yy"
    {
		if (!(yyvsp[(3) - (3)].stmt))
			(yyval.stmt) = (yyvsp[(1) - (3)].stmt);
		else if (!(yyvsp[(1) - (3)].stmt))
			(yyval.stmt) = (yyvsp[(3) - (3)].stmt);
		else		/*	Both nonzero; need a list.	*/
			{
			Uc_block_statement *b = dynamic_cast<Uc_block_statement *>((yyvsp[(1) - (3)].stmt));
			if (!b)
				{
				b = new Uc_block_statement();
				b->add((yyvsp[(1) - (3)].stmt));
				}
			b->add((yyvsp[(3) - (3)].stmt));
			(yyval.stmt) = b;
			}
		}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 756 "ucparse.yy"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 761 "ucparse.yy"
    {
		if (cur_fun)
			cur_fun->add_symbol((yyvsp[(1) - (1)].strval), struct_type);
		else
			cur_class->add_symbol((yyvsp[(1) - (1)].strval), struct_type);
		(yyval.stmt) = 0;
		}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 769 "ucparse.yy"
    {
		if (cur_class && !cur_fun)
			{
			char buf[180];
			sprintf(buf, "Initialization of class member struct '%s' must be done through constructor", (yyvsp[(1) - (3)].strval));
			yyerror(buf);
			(yyval.stmt) = 0;
			}
		else
			{
			Uc_var_symbol *var = cur_fun ? cur_fun->add_symbol((yyvsp[(1) - (3)].strval), struct_type)
							 : cur_class->add_symbol((yyvsp[(1) - (3)].strval), struct_type);
			var->set_is_obj_fun((yyvsp[(3) - (3)].expr)->is_object_function(false));
			(yyval.stmt) = new Uc_assignment_statement(new Uc_var_expression(var), (yyvsp[(3) - (3)].expr));
			}
		}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 790 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 792 "ucparse.yy"
    {
		Uc_symbol *sym = cur_fun->search_up((yyvsp[(1) - (1)].strval));
		if (!sym)
			{
			char buf[150];
			sprintf(buf, "'%s' not declared", (yyvsp[(1) - (1)].strval));
			yyerror(buf);
			sym = cur_fun->add_symbol((yyvsp[(1) - (1)].strval));
			}
		else if (!sym->get_sym_type() == Uc_symbol::Class)
			{
			char buf[150];
			sprintf(buf, "'%s' not a class", (yyvsp[(1) - (1)].strval));
			yyerror(buf);
			(yyval.expr) = 0;
			}
		else
			{
				// Tests above guarantee this will always work.
			Uc_class_inst_symbol *cls =
					dynamic_cast<Uc_class_inst_symbol *>(sym->get_sym());
			(yyval.expr) = new Uc_class_expression(cls);
			}
		}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 817 "ucparse.yy"
    {
		(yyval.expr) = (yyvsp[(1) - (1)].funcall);
		}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 825 "ucparse.yy"
    { struct_type = (yyvsp[(4) - (5)].struc); }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 827 "ucparse.yy"
    { struct_type = 0; }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 829 "ucparse.yy"
    { class_type = (yyvsp[(4) - (5)].cls); }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 831 "ucparse.yy"
    { class_type = 0; }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 841 "ucparse.yy"
    {
		if (cur_fun)
			cur_fun->add_static((yyvsp[(1) - (1)].strval));
		else
			Uc_function::add_global_static((yyvsp[(1) - (1)].strval));
		}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 856 "ucparse.yy"
    {
		if (cur_fun)
			cur_fun->add_static((yyvsp[(1) - (1)].strval), struct_type);
		else
			Uc_function::add_global_static((yyvsp[(1) - (1)].strval), struct_type);
		}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 871 "ucparse.yy"
    {
		if (cur_fun)
			cur_fun->add_static((yyvsp[(1) - (1)].strval), class_type);
		else
			Uc_function::add_global_static((yyvsp[(1) - (1)].strval), class_type);
		}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 886 "ucparse.yy"
    {
		cur_fun->add_string_symbol((yyvsp[(1) - (3)].strval), (yyvsp[(3) - (3)].strval));
		}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 892 "ucparse.yy"
    { is_extern = true; }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 893 "ucparse.yy"
    { (yyval.funsym) = (yyvsp[(3) - (4)].funsym); is_extern = false; }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 898 "ucparse.yy"
    {
		// Some rudimentary type-checking for classes
		if ((yyvsp[(1) - (4)].expr)->is_class())
			{
			if (Nonclass_unexpected_error((yyvsp[(3) - (4)].expr)))
				(yyval.stmt) = 0;
			else
				{
				Uc_class *trg = (yyvsp[(1) - (4)].expr)->get_cls();
				Uc_class *src = (yyvsp[(3) - (4)].expr)->get_cls();
				if (Incompatible_classes_error(src, trg))
					(yyval.stmt) = 0;
				else
					{
					(yyvsp[(1) - (4)].expr)->set_is_obj_fun((yyvsp[(3) - (4)].expr)->is_object_function(false));
					(yyval.stmt) = new Uc_assignment_statement((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr));
					}
				}
			}
		else if (Class_unexpected_error((yyvsp[(3) - (4)].expr)))
			(yyval.stmt) = 0;
		else
			{
			(yyvsp[(1) - (4)].expr)->set_is_obj_fun((yyvsp[(3) - (4)].expr)->is_object_function(false));
			(yyval.stmt) = new Uc_assignment_statement((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr));
			}
		}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 926 "ucparse.yy"
    {
		(yyvsp[(1) - (4)].expr)->set_is_obj_fun(-1);
		(yyval.stmt) = new Uc_assignment_statement((yyvsp[(1) - (4)].expr), 
				new Uc_binary_expression((yyvsp[(2) - (4)].intval), (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)));
		}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 932 "ucparse.yy"
    {
		(yyvsp[(1) - (4)].expr)->set_is_obj_fun(-1);
		(yyval.stmt) = new Uc_assignment_statement(
				(yyvsp[(1) - (4)].expr), new Uc_array_expression((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].exprlist)));
		}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 941 "ucparse.yy"
    { (yyval.intval) = UC_ADD; }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 943 "ucparse.yy"
    { (yyval.intval) = UC_SUB; }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 945 "ucparse.yy"
    { (yyval.intval) = UC_MUL; }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 947 "ucparse.yy"
    { (yyval.intval) = UC_DIV; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 949 "ucparse.yy"
    { (yyval.intval) = UC_MOD; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 954 "ucparse.yy"
    { (yyval.exprlist)->add((yyvsp[(3) - (3)].expr)); }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 956 "ucparse.yy"
    {
		(yyval.exprlist) = new Uc_array_expression();
		(yyval.exprlist)->add((yyvsp[(1) - (1)].expr));
		}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 964 "ucparse.yy"
    { start_script(); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 965 "ucparse.yy"
    {
		(yyval.expr) = (yyvsp[(3) - (4)].exprlist);
		end_script();
		}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 973 "ucparse.yy"
    {
		int val;
		if ((yyvsp[(3) - (5)].expr)->eval_const(val))
			{
			if (val)
				{
				(yyvsp[(3) - (5)].expr)->warning("'if' clause will always be executed");
				(yyval.stmt) = (yyvsp[(5) - (5)].stmt);
				}
			else
				{	// Need this because of those pesky GOTOs...
				(yyvsp[(3) - (5)].expr)->warning("'if' clause may never be executed");
				(yyval.stmt) = new Uc_if_statement(0, (yyvsp[(5) - (5)].stmt), 0);
				}
			delete (yyvsp[(3) - (5)].expr);
			}
		else
			(yyval.stmt) = new Uc_if_statement((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt), 0);
		}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 993 "ucparse.yy"
    {
		int val;
		if ((yyvsp[(3) - (7)].expr)->eval_const(val))
			{
			if (val)
				{
					// Need this because of those pesky GOTOs...
				(yyvsp[(3) - (7)].expr)->warning("'else' clause may never be executed");
				(yyval.stmt) = new Uc_if_statement(new Uc_int_expression(val == 0), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
				}
			else
				{
					// Need this because of those pesky GOTOs...
				(yyvsp[(3) - (7)].expr)->warning("'if' clause may never be executed");
				(yyval.stmt) = new Uc_if_statement(0, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
				}
			delete (yyvsp[(3) - (7)].expr);
			}
		else
			(yyval.stmt) = new Uc_if_statement((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
		}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1017 "ucparse.yy"
    { start_loop(); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1018 "ucparse.yy"
    {
		int val;
		if ((yyvsp[(3) - (6)].expr)->eval_const(val))
			{
			if (val)
				{
				(yyvsp[(3) - (6)].expr)->warning("Infinite loop detected");
				(yyval.stmt) = new Uc_infinite_loop_statement((yyvsp[(6) - (6)].stmt));
				}
			else
				{	// Need this because of those pesky GOTOs...
				(yyvsp[(3) - (6)].expr)->warning("Body of 'while' statement may never be executed");
				(yyval.stmt) = new Uc_while_statement(0, (yyvsp[(6) - (6)].stmt));
				}
			delete (yyvsp[(3) - (6)].expr);
			}
		else
			(yyval.stmt) = new Uc_while_statement((yyvsp[(3) - (6)].expr), (yyvsp[(6) - (6)].stmt));
		end_loop();
		}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1038 "ucparse.yy"
    { start_loop(); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1039 "ucparse.yy"
    {
		int val;
		if ((yyvsp[(6) - (8)].expr)->eval_const(val))
			{
			if (val)
				{
				(yyvsp[(6) - (8)].expr)->warning("Infinite loop detected");
				(yyval.stmt) = new Uc_infinite_loop_statement((yyvsp[(3) - (8)].stmt));
				}
			else		// Optimize loop away.
				(yyval.stmt) = new Uc_breakable_statement((yyvsp[(3) - (8)].stmt));
			delete (yyvsp[(6) - (8)].expr);
			}
		else
			(yyval.stmt) = new Uc_dowhile_statement((yyvsp[(6) - (8)].expr), (yyvsp[(3) - (8)].stmt));
		end_loop();
		}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1059 "ucparse.yy"
    { start_loop(); }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1060 "ucparse.yy"
    {
		end_loop();
		(yyvsp[(1) - (4)].arrayloop)->set_statement((yyvsp[(4) - (4)].stmt));
		(yyvsp[(1) - (4)].arrayloop)->finish(cur_fun);
		cur_fun->pop_scope();
		end_loop();
		}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1068 "ucparse.yy"
    { (yyvsp[(1) - (3)].arrayloop)->set_index(cur_fun->add_symbol((yyvsp[(3) - (3)].strval))); }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1069 "ucparse.yy"
    { start_loop(); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1070 "ucparse.yy"
    {
		end_loop();
		(yyvsp[(1) - (7)].arrayloop)->set_statement((yyvsp[(7) - (7)].stmt));
		(yyvsp[(1) - (7)].arrayloop)->finish(cur_fun);
		cur_fun->pop_scope();
		end_loop();
		}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1078 "ucparse.yy"
    { (yyvsp[(1) - (3)].arrayloop)->set_index(cur_fun->add_symbol((yyvsp[(3) - (3)].strval))); }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1080 "ucparse.yy"
    { (yyvsp[(1) - (6)].arrayloop)->set_array_size(cur_fun->add_symbol((yyvsp[(6) - (6)].strval))); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1081 "ucparse.yy"
    { start_loop(); }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1082 "ucparse.yy"
    {
		end_loop();
		(yyvsp[(1) - (10)].arrayloop)->set_statement((yyvsp[(10) - (10)].stmt));
		cur_fun->pop_scope();
		end_loop();
		}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1092 "ucparse.yy"
    {
		if ((yyvsp[(4) - (4)].var)->get_cls())
			{
			char buf[150];
			sprintf(buf, "Can't convert class '%s' into non-class",
					(yyvsp[(4) - (4)].var)->get_name());
			yyerror(buf);
			}
		Uc_var_symbol *var = cur_fun->add_symbol((yyvsp[(2) - (4)].strval));
		(yyval.arrayloop) = new Uc_arrayloop_statement(var, (yyvsp[(4) - (4)].var));
		}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1107 "ucparse.yy"
    {
		cur_fun->push_scope();
		start_loop();
		}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1115 "ucparse.yy"
    { (yyval.stmt) = new Uc_call_statement((yyvsp[(1) - (2)].funcall));  }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1121 "ucparse.yy"
    {
		Uc_block_statement *stmts = new Uc_block_statement();
					/* Set up 'show' call.		*/
		stmts->add(new Uc_call_statement(
			new Uc_call_expression(Uc_function::get_show_face(),
			new Uc_array_expression((yyvsp[(1) - (7)].expr), new Uc_int_expression(0)), 
								cur_fun)));
		stmts->add(new Uc_say_statement((yyvsp[(5) - (7)].exprlist)));
		(yyval.stmt) = stmts;
		}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1132 "ucparse.yy"
    {
		(yyval.stmt) = new Uc_call_statement(
			new Uc_call_expression(Uc_function::get_remove_face(),
				new Uc_array_expression((yyvsp[(1) - (6)].expr)), cur_fun));
		}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1138 "ucparse.yy"
    {
		if ((yyvsp[(5) - (8)].var)->get_cls())
			{
			char buf[150];
			sprintf(buf, "Can't convert class '%s' into non-class",
					(yyvsp[(5) - (8)].var)->get_name());
			yyerror(buf);
			}
		Uc_array_expression *parms = new Uc_array_expression();
		parms->add((yyvsp[(1) - (8)].expr));		// Itemref.
		parms->add(new Uc_var_expression((yyvsp[(5) - (8)].var)));		// Script.
		if ((yyvsp[(6) - (8)].expr))
			parms->add((yyvsp[(6) - (8)].expr));		// Delay.
					// Get the script intrinsic.
		Uc_symbol *sym = Uc_function::get_intrinsic((yyvsp[(6) - (8)].expr) ? 2 : 1);
		(yyval.stmt) = new Uc_call_statement(
			new Uc_call_expression(sym, parms, cur_fun));
		}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1160 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(2) - (2)].expr); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1162 "ucparse.yy"
    { (yyval.expr) = 0; }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1167 "ucparse.yy"
    {
		if (!cur_fun->has_ret())
			{
			char buf[180];
			sprintf(buf, "Function '%s' can't return a value",
					cur_fun->get_name());
			yyerror(buf);
			(yyval.stmt) = 0;
			}
		else
			{
			Uc_class *src = (yyvsp[(2) - (3)].expr)->get_cls();
			Uc_class *trg = cur_fun->get_cls();
			if (!src && !trg)
				(yyval.stmt) = new Uc_return_statement((yyvsp[(2) - (3)].expr));
			else if (!src || !trg)
				{
				int ival;
				if (trg && (yyvsp[(2) - (3)].expr)->eval_const(ival) && ival == 0)
					(yyval.stmt) = new Uc_return_statement((yyvsp[(2) - (3)].expr));
				else
					{
					char buf[210];
					sprintf(buf, "Function '%s' expects a return of %s '%s' but supplied value is %s'%s'",
							cur_fun->get_name(),
							trg ? "class" : "type",
							trg ? trg->get_name() : "var",
							src ? "class " : "",
							src ? src->get_name() : "var");
					yyerror(buf);
					(yyval.stmt) = 0;
					}
				}
			else if (Incompatible_classes_error(src, trg))
				(yyval.stmt) = 0;
			else
				(yyval.stmt) = new Uc_return_statement((yyvsp[(2) - (3)].expr));
			}
		}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1207 "ucparse.yy"
    {
		if (cur_fun->has_ret())
			{
			Uc_class *cls = cur_fun->get_cls();
			char buf[180];
			sprintf(buf, "Function '%s' must return a '%s'",
					cur_fun->get_name(), cls ? cls->get_name() : "var");
			yyerror(buf);
			(yyval.stmt) = 0;
			}
		else
			(yyval.stmt) = new Uc_return_statement();
		}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1224 "ucparse.yy"
    { (yyval.intval) = 1; }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1226 "ucparse.yy"
    { (yyval.intval) = 0; }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1231 "ucparse.yy"
    {
		end_loop();
		--converse;
		(yyval.stmt) = new Uc_converse_statement(0, (yyvsp[(3) - (4)].stmtlist), false);
		}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1238 "ucparse.yy"
    {
		end_loop();
		--converse;
		if (Class_unexpected_error((yyvsp[(4) - (8)].expr)))
			(yyval.stmt) = 0;
		else
			(yyval.stmt) = new Uc_converse_statement((yyvsp[(4) - (8)].expr), (yyvsp[(7) - (8)].stmtlist), (yyvsp[(2) - (8)].intval));
		}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1250 "ucparse.yy"
    {
		start_loop();
		++converse;
		}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1258 "ucparse.yy"
    {
		if ((yyvsp[(2) - (2)].stmt))
			(yyval.stmtlist)->push_back((yyvsp[(2) - (2)].stmt));
		}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1263 "ucparse.yy"
    { (yyval.stmtlist) = new vector<Uc_statement *>; }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1268 "ucparse.yy"
    { cur_fun->push_scope(); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1269 "ucparse.yy"
    {
		(yyval.stmt) = new Uc_converse_case_statement(*(yyvsp[(2) - (6)].intlist),
				((yyvsp[(3) - (6)].intval) ? true : false), (yyvsp[(6) - (6)].block));
		delete (yyvsp[(2) - (6)].intlist);		// A copy was made.
		cur_fun->pop_scope();
		}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1276 "ucparse.yy"
    { cur_fun->push_scope(); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1277 "ucparse.yy"
    {
		(yyval.stmt) = new Uc_converse_case_statement(std::vector<int>(),
				((yyvsp[(2) - (5)].intval) ? true : false), (yyvsp[(5) - (5)].block));
		cur_fun->pop_scope();
		}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1286 "ucparse.yy"
    {
		if ((yyvsp[(3) - (3)].stmt))
			(yyval.stmtlist)->push_back((yyvsp[(3) - (3)].stmt));
		}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1291 "ucparse.yy"
    {
		(yyval.stmtlist) = new vector<Uc_statement *>;
		(yyval.stmtlist)->push_back((yyvsp[(1) - (1)].stmt));
		}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1299 "ucparse.yy"
    { cur_fun->push_scope(); }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1300 "ucparse.yy"
    {
		(yyval.stmt) = new Uc_converse_case_statement(*(yyvsp[(1) - (3)].intlist), false, (yyvsp[(3) - (3)].block));
		delete (yyvsp[(1) - (3)].intlist);		// A copy was made.
		cur_fun->pop_scope();
		}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1309 "ucparse.yy"
    {
		(yyval.intlist) = new vector<int>;
		(yyval.intlist)->push_back(cur_fun->add_string((yyvsp[(5) - (6)].strval)));
		}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1314 "ucparse.yy"
    { (yyval.intlist) = (yyvsp[(6) - (8)].intlist); }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1319 "ucparse.yy"
    { (yyval.intlist)->push_back(cur_fun->add_string((yyvsp[(3) - (3)].strval))); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1321 "ucparse.yy"
    {
		(yyval.intlist) = new vector<int>;
		(yyval.intlist)->push_back(cur_fun->add_string((yyvsp[(1) - (1)].strval)));
		}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1329 "ucparse.yy"
    { (yyval.intval) = 1; }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1331 "ucparse.yy"
    { (yyval.intval) = 0; }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1336 "ucparse.yy"
    { cur_fun->push_scope(); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1338 "ucparse.yy"
    { start_breakable(); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1339 "ucparse.yy"
    {
		if (Class_unexpected_error((yyvsp[(4) - (9)].expr)))
			(yyval.stmt) = 0;
		else
			{
			end_breakable();
			(yyval.stmt) = new Uc_switch_statement((yyvsp[(4) - (9)].expr), (yyvsp[(8) - (9)].stmtlist));
			delete((yyvsp[(8) - (9)].stmtlist));		// a copy has been made.
			cur_fun->pop_scope();
			}
		}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1354 "ucparse.yy"
    { (yyval.stmtlist)->push_back((yyvsp[(2) - (2)].stmt)); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1356 "ucparse.yy"
    {
		(yyval.stmtlist) = new vector<Uc_statement *>;
		(yyval.stmtlist)->push_back((yyvsp[(1) - (1)].stmt));
		}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1364 "ucparse.yy"
    {	(yyval.stmt) = new Uc_switch_expression_case_statement((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].block));	}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1366 "ucparse.yy"
    {	(yyval.stmt) = new Uc_switch_expression_case_statement(
				new Uc_string_expression(cur_fun->add_string((yyvsp[(2) - (4)].strval))), (yyvsp[(4) - (4)].block));	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1369 "ucparse.yy"
    {	(yyval.stmt) = new Uc_switch_default_case_statement((yyvsp[(3) - (3)].block));	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1373 "ucparse.yy"
    { start_script(); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1374 "ucparse.yy"
    {
		Uc_array_expression *parms = new Uc_array_expression();
		parms->add((yyvsp[(3) - (5)].expr));		// Itemref.
		parms->add((yyvsp[(5) - (5)].expr));		// Script.
		if ((yyvsp[(4) - (5)].expr))			// Delay?
			parms->add((yyvsp[(4) - (5)].expr));
					// Get the script intrinsic.
		Uc_symbol *sym = Uc_function::get_intrinsic((yyvsp[(4) - (5)].expr) ? 2 : 1);
		Uc_call_expression *fcall = 
				new Uc_call_expression(sym, parms, cur_fun);
		(yyval.stmt) = new Uc_call_statement(fcall);
		end_script();
		}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1395 "ucparse.yy"
    { (yyval.exprlist)->concat((yyvsp[(2) - (2)].expr)); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1397 "ucparse.yy"
    {
		(yyval.exprlist) = new Uc_array_expression();
		(yyval.exprlist)->concat((yyvsp[(1) - (1)].expr));
		}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1405 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::finish, UC_PUSHB); }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1407 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::resurrect, UC_PUSHB); }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1409 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::cont, UC_PUSHB); }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1411 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::reset, UC_PUSHB); }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1412 "ucparse.yy"
    { repeat_nesting++; }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1413 "ucparse.yy"
    {
		repeat_nesting--;
		Uc_array_expression *result = new Uc_array_expression();
		result->concat((yyvsp[(4) - (5)].expr));	// Start with cmnds. to repeat.
		int sz = result->get_exprs().size();
		result->add(new Uc_int_expression(
			repeat_nesting ? Ucscript::repeat2 : Ucscript::repeat, UC_PUSHB));
					// Then -offset to start.
		result->add(new Uc_int_expression(-sz));
		result->add((yyvsp[(2) - (5)].expr));	// Loop var for repeat2.
		if (repeat_nesting)
			result->add((yyvsp[(2) - (5)].expr));	// Then #times to repeat.
		(yyval.expr) = result;
		}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1427 "ucparse.yy"
    { repeat_nesting++; }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1429 "ucparse.yy"
    {	// Allow setting a different initial number of repeats.
		repeat_nesting--;
		Uc_array_expression *result = new Uc_array_expression();
		result->concat((yyvsp[(6) - (7)].expr));	// Start with cmnds. to repeat.
		int sz = result->get_exprs().size();
		result->add(new Uc_int_expression(Ucscript::repeat2, UC_PUSHB));
					// Then -offset to start.
		result->add(new Uc_int_expression(-sz));
		result->add((yyvsp[(2) - (7)].expr));	// Loop var for repeat2.
		result->add((yyvsp[(4) - (7)].expr));	// Then #times to repeat.
		(yyval.expr) = result;
		}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1442 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::nop, UC_PUSHB); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1444 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::dont_halt, UC_PUSHB); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1446 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::delay_ticks, (yyvsp[(2) - (3)].expr)); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1448 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::delay_minutes, (yyvsp[(2) - (4)].expr)); }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1450 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::delay_hours, (yyvsp[(2) - (4)].expr)); }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1452 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::wait_while_near, (yyvsp[(4) - (5)].expr)); }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1454 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::wait_while_far, (yyvsp[(4) - (5)].expr)); }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1456 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::remove, UC_PUSHB); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1458 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::rise, UC_PUSHB); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1460 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::descend, UC_PUSHB); }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1462 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::frame, (yyvsp[(2) - (3)].expr)); }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1464 "ucparse.yy"
    {
		(yyval.expr) = new Uc_binary_expression(UC_ADD, new Uc_int_expression(0x61),
				new Uc_binary_expression(UC_MOD, (yyvsp[(3) - (4)].expr), new Uc_int_expression(16)),
				UC_PUSHB);	// Want byte.
		}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1470 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(0x61 + ((yyvsp[(3) - (4)].intval) & 15), UC_PUSHB); }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1472 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::egg, UC_PUSHB); }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1474 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::set_egg, (yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1476 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::set_egg, new Uc_int_expression((yyvsp[(2) - (5)].intval)), (yyvsp[(4) - (5)].expr)); }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1478 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::next_frame_max, UC_PUSHB); }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1480 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::next_frame, UC_PUSHB); }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1482 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::prev_frame_min, UC_PUSHB); }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1484 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::prev_frame, UC_PUSHB); }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1486 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::say, (yyvsp[(2) - (3)].expr)); }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1488 "ucparse.yy"
    {
		(yyval.expr) = Create_array(Ucscript::step,
				new Uc_binary_expression(UC_ADD, (yyvsp[(2) - (3)].expr),
					new Uc_int_expression(0x30), UC_PUSHB),
				new Uc_int_expression(0));
		}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1495 "ucparse.yy"
    {
		(yyval.expr) = Create_array(Ucscript::step,
				new Uc_binary_expression(UC_ADD,
					new Uc_binary_expression(UC_MOD, (yyvsp[(2) - (5)].expr),
						new Uc_int_expression(8)),		// dir is 0-7.
					new Uc_int_expression(0x30), UC_PUSHB),
				new Uc_binary_expression(UC_MOD, (yyvsp[(4) - (5)].expr),
					new Uc_int_expression(16)));		// Allow max |dz| == 15.
		}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1505 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::step_n + (yyvsp[(2) - (3)].intval), UC_PUSHB); }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1507 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::music, (yyvsp[(2) - (3)].expr)); }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1509 "ucparse.yy"
    {
			// This is the 'repeat' flag.
		Uc_expression *expr;
		int ival;
		if ((yyvsp[(4) - (5)].expr)->eval_const(ival))
			expr = new Uc_int_expression(ival ? 256 : 0);
		else	// Argh.
			expr = new Uc_binary_expression(UC_MUL,
					new Uc_int_expression(256),
					new Uc_binary_expression(UC_CMPNE, (yyvsp[(4) - (5)].expr),
						new Uc_bool_expression(false)));
		(yyval.expr) = Create_array(Ucscript::music,
				new Uc_binary_expression(UC_ADD, (yyvsp[(2) - (5)].expr), expr));
		}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1524 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::usecode, (yyvsp[(1) - (2)].expr)); }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1526 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::usecode2, (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1528 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::speech, (yyvsp[(2) - (3)].expr)); }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1530 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::sfx, (yyvsp[(2) - (3)].expr)); }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1532 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::face_dir, (yyvsp[(2) - (3)].expr)); }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1534 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::face_dir, new Uc_int_expression((yyvsp[(2) - (3)].intval))); }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1536 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::weather, (yyvsp[(2) - (3)].expr)); }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1538 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::hit, (yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1540 "ucparse.yy"
    { (yyval.expr) = Create_array(Ucscript::hit, (yyvsp[(2) - (5)].expr), new Uc_int_expression((yyvsp[(4) - (5)].intval))); }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1542 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression(Ucscript::attack, UC_PUSHB); }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1544 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(2) - (3)].exprlist); }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1549 "ucparse.yy"
    {
		if (!(yyvsp[(2) - (2)].expr))
			(yyval.expr) = new Uc_int_expression(0);
		else
			{
				// May generate errors.
			if ((yyvsp[(2) - (2)].expr)->is_object_function() == -1)
				{	// Don't know.
				char buf[180];
				sprintf(buf, "Please ensure that 'call' uses a function declared with 'shape#' or 'object#'");
				yywarning(buf);
				}
			(yyval.expr) = (yyvsp[(2) - (2)].expr);
			}
		}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1568 "ucparse.yy"
    { (yyval.intval) = 0; }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1570 "ucparse.yy"
    { (yyval.intval) = 1; }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1572 "ucparse.yy"
    { (yyval.intval) = 2; }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1574 "ucparse.yy"
    { (yyval.intval) = 3; }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1576 "ucparse.yy"
    { (yyval.intval) = 4; }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1578 "ucparse.yy"
    { (yyval.intval) = 5; }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1583 "ucparse.yy"
    { (yyval.intval) = 0; }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1585 "ucparse.yy"
    { (yyval.intval) = 1; }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1587 "ucparse.yy"
    { (yyval.intval) = 2; }
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1589 "ucparse.yy"
    { (yyval.intval) = 3; }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1591 "ucparse.yy"
    { (yyval.intval) = 4; }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1593 "ucparse.yy"
    { (yyval.intval) = 5; }
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1595 "ucparse.yy"
    { (yyval.intval) = 6; }
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1597 "ucparse.yy"
    { (yyval.intval) = 7; }
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1602 "ucparse.yy"
    { (yyval.intval) = 0; }
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1604 "ucparse.yy"
    { (yyval.intval) = 1; }
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1606 "ucparse.yy"
    { (yyval.intval) = 2; }
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1608 "ucparse.yy"
    { (yyval.intval) = 3; }
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1610 "ucparse.yy"
    { (yyval.intval) = 4; }
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1612 "ucparse.yy"
    { (yyval.intval) = 5; }
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1614 "ucparse.yy"
    { (yyval.intval) = 6; }
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1616 "ucparse.yy"
    { (yyval.intval) = 7; }
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1618 "ucparse.yy"
    { (yyval.intval) = 8; }
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1620 "ucparse.yy"
    { (yyval.intval) = 9; }
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1622 "ucparse.yy"
    { (yyval.intval) = 10; }
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1624 "ucparse.yy"
    { (yyval.intval) = 11; }
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1626 "ucparse.yy"
    { (yyval.intval) = 12; }
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1628 "ucparse.yy"
    { (yyval.intval) = 13; }
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1630 "ucparse.yy"
    { (yyval.intval) = 14; }
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1632 "ucparse.yy"
    { (yyval.intval) = 15; }
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1637 "ucparse.yy"
    { (yyval.intval) = 0; }
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1639 "ucparse.yy"
    { (yyval.intval) = 1; }
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1641 "ucparse.yy"
    { (yyval.intval) = 2; }
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1643 "ucparse.yy"
    { (yyval.intval) = 3; }
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1645 "ucparse.yy"
    { (yyval.intval) = 4; }
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1647 "ucparse.yy"
    { (yyval.intval) = 5; }
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1649 "ucparse.yy"
    { (yyval.intval) = 6; }
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1651 "ucparse.yy"
    { (yyval.intval) = 7; }
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1656 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1658 "ucparse.yy"
    { (yyval.expr) = 0; }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1663 "ucparse.yy"
    { (yyval.stmt) = new Uc_break_statement(); }
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1668 "ucparse.yy"
    { (yyval.stmt) = new Uc_continue_statement(); }
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1673 "ucparse.yy"
    {
		if (cur_fun->search_label((yyvsp[(1) - (2)].strval)))
			{
			char buf[150];
			sprintf(buf, "duplicate label: '%s'", (yyvsp[(1) - (2)].strval));
			yyerror(buf);
			(yyval.stmt) = 0;
			}
		else
			{
			cur_fun->add_label((yyvsp[(1) - (2)].strval));
			(yyval.stmt) = new Uc_label_statement((yyvsp[(1) - (2)].strval));
			}
		}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1691 "ucparse.yy"
    {
		yywarning("You *really* shouldn't using goto statements...");
		(yyval.stmt) = new Uc_goto_statement((yyvsp[(2) - (2)].strval));
		}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1699 "ucparse.yy"
    {
		Uc_class_inst_symbol *cls =
				dynamic_cast<Uc_class_inst_symbol *>((yyvsp[(2) - (3)].var)->get_sym());
		if (!cls)
			{
			char buf[150];
			sprintf(buf, "'%s' is not a class", (yyvsp[(2) - (3)].var)->get_name());
			yyerror(buf);
			(yyval.stmt) = 0;
			}
		else
			(yyval.stmt) = new Uc_delete_statement(new Uc_del_expression(cls));
		}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1716 "ucparse.yy"
    {
		(yyval.stmt) = new Uc_call_statement(
			new Uc_call_expression(Uc_function::get_add_answer(),
								(yyvsp[(3) - (5)].exprlist), cur_fun));
		}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1722 "ucparse.yy"
    {
		(yyval.stmt) = new Uc_call_statement(new Uc_call_expression(
					Uc_function::get_remove_answer(),
								(yyvsp[(3) - (5)].exprlist), cur_fun));
		}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1732 "ucparse.yy"
    { (yyval.exprlist) = new Uc_array_expression(); }
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1737 "ucparse.yy"
    { (yyval.exprlist)->add((yyvsp[(3) - (3)].expr)); }
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1739 "ucparse.yy"
    {
		(yyval.exprlist) = new Uc_array_expression();
		(yyval.exprlist)->add((yyvsp[(1) - (1)].expr));
		}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1747 "ucparse.yy"
    {
		if (Class_unexpected_error((yyvsp[(1) - (1)].expr)))
			(yyval.expr) = 0;
		else
			(yyval.expr) = (yyvsp[(1) - (1)].expr);
		}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1757 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1759 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1761 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_SUB, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1763 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_MUL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1765 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1767 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1769 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_CMPEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1770 "ucparse.yy"
    { start_script(); }
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1771 "ucparse.yy"
    {
		(yyval.expr) = (yyvsp[(4) - (4)].expr);
		end_script();
		}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1776 "ucparse.yy"
    {
		if (!converse)	/* Only valid in converse blocks */
			{
			char buf[150];
			sprintf(buf, "'CHOICE' can only be used in a conversation block!");
			yyerror(buf);
			(yyval.expr) = 0;
			}
		(yyval.expr) = new Uc_choice_expression();
		}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1787 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_CMPNE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1789 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_CMPL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1791 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_CMPLE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1793 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_CMPG, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1795 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_CMPGE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1797 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1799 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1801 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_IN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1803 "ucparse.yy"
    { (yyval.expr) = new Uc_binary_expression(UC_ARRA, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1805 "ucparse.yy"
    {
		if (Class_unexpected_error((yyvsp[(2) - (2)].expr)))
			(yyval.expr) = 0;
		else
			(yyval.expr) = (yyvsp[(2) - (2)].expr);
		}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1812 "ucparse.yy"
    {
		if (Class_unexpected_error((yyvsp[(2) - (2)].expr)))
			(yyval.expr) = 0;
		else
			(yyval.expr) = new Uc_binary_expression(UC_SUB,
				new Uc_int_expression(0), (yyvsp[(2) - (2)].expr));
		}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1820 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1822 "ucparse.yy"
    { (yyval.expr) = new Uc_unary_expression(UC_NOT, (yyvsp[(2) - (2)].expr)); }
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1824 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(2) - (3)].exprlist); }
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1826 "ucparse.yy"
    { (yyval.expr) = new Uc_string_expression(cur_fun->add_string((yyvsp[(1) - (1)].strval))); }
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1828 "ucparse.yy"
    { (yyval.expr) = new Uc_string_prefix_expression(cur_fun, (yyvsp[(1) - (1)].strval)); }
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1834 "ucparse.yy"
    {	// A way to retrieve the function's assigned
			// usecode number
		Uc_symbol *sym = cur_fun->search_up((yyvsp[(2) - (2)].strval));
		if (!sym)	/* See if the symbol is defined */
			{
			char buf[150];
			sprintf(buf, "'%s' not declared", (yyvsp[(2) - (2)].strval));
			yyerror(buf);
			(yyval.expr) = 0;
			}
		Uc_function_symbol *fun = (Uc_function_symbol *) sym;
		if (!fun)	/* See if the symbol is a function */
			{
			char buf[150];
			sprintf(buf, "'%s' is not a function", (yyvsp[(2) - (2)].strval));
			yyerror(buf);
			(yyval.expr) = 0;
			}
		else		/* Output the function's assigned number */
			{
			int funid = fun->get_usecode_num();
			int op = is_int_32bit(funid) ? UC_PUSHI32 : UC_PUSHI;
			(yyval.expr) = new Uc_int_expression(funid, op);
			}
		}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1864 "ucparse.yy"
    { (yyval.exprlist) = new Uc_array_expression(); }
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1869 "ucparse.yy"
    { (yyval.exprlist)->add((yyvsp[(3) - (3)].expr)); }
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1871 "ucparse.yy"
    {
		(yyval.exprlist) = new Uc_array_expression();
		(yyval.exprlist)->add((yyvsp[(1) - (1)].expr));
		}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1879 "ucparse.yy"
    { (yyval.intval) = (yyvsp[(2) - (3)].intval); }
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1884 "ucparse.yy"
    {
		int op = const_opcode.size() ? const_opcode.back() : UC_PUSHI;
		if (is_sint_32bit((yyvsp[(1) - (1)].intval)) && op != UC_PUSHI32)
			{
			char buf[150];
			if (is_int_32bit((yyvsp[(1) - (1)].intval)))
				{
				sprintf(buf, "Literal integer '%d' cannot be represented as 16-bit integer. Assuming '(long)' cast.",
						(yyvsp[(1) - (1)].intval));
				op = UC_PUSHI32;
				}
			else
				sprintf(buf, "Interpreting integer '%d' as the signed 16-bit integer '%d'. If this is incorrect, use '(long)' cast.",
						(yyvsp[(1) - (1)].intval), (short)(yyvsp[(1) - (1)].intval));
			yywarning(buf);
			}
		(yyval.expr) = new Uc_int_expression((yyvsp[(1) - (1)].intval), op);
		}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1903 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression((yyvsp[(2) - (2)].intval), (yyvsp[(1) - (2)].intval)); }
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1905 "ucparse.yy"
    {
		Uc_var_expression *expr = dynamic_cast<Uc_var_expression *>((yyvsp[(1) - (1)].membersel)->expr);
		Uc_struct_symbol *base;
		if (!expr || !(base = expr->get_struct()))
			{
			yyerror("Expression is not a 'struct'");
			(yyval.expr) = new Uc_int_expression(0);
			}
		else
			{
			int offset = base->search((yyvsp[(1) - (1)].membersel)->name);
			if (offset < 0)
				{
				char buf[150];
				sprintf(buf, "'%s' does not belong to struct '%s'",
						(yyvsp[(1) - (1)].membersel)->name, base->get_name());
				yyerror(buf);
				(yyval.expr) = new Uc_int_expression(0);
				}
			else
				{
				Uc_var_symbol *var = expr->get_var();
				Uc_int_expression *index = new Uc_int_expression(offset);
				if (var->is_static())
					(yyval.expr) = new Uc_static_arrayelem_expression(var, index);
				else if (var->get_sym_type() == Uc_symbol::Member_var)
					(yyval.expr) = new Uc_class_arrayelem_expression(var, index);
				else
					(yyval.expr) = new Uc_arrayelem_expression(var, index);
				}
			}
		delete (yyvsp[(1) - (1)].membersel);
		}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1939 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1941 "ucparse.yy"
    {
		if ((yyvsp[(1) - (4)].var)->get_cls())
			{
			char buf[150];
			sprintf(buf, "Can't convert class '%s' into non-class",
					(yyvsp[(1) - (4)].var)->get_name());
			yyerror(buf);
			(yyval.expr) = new Uc_arrayelem_expression((yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].expr));
			}
		else if ((yyvsp[(1) - (4)].var)->is_static())
			(yyval.expr) = new Uc_static_arrayelem_expression((yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].expr));
		else if ((yyvsp[(1) - (4)].var)->get_sym_type() == Uc_symbol::Member_var)
			(yyval.expr) = new Uc_class_arrayelem_expression((yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].expr));
		else
			(yyval.expr) = new Uc_arrayelem_expression((yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].expr));
		}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1958 "ucparse.yy"
    { (yyval.expr) = new Uc_flag_expression((yyvsp[(3) - (4)].expr)); }
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1960 "ucparse.yy"
    {
		if ((yyvsp[(1) - (1)].funcall))
			(yyval.expr) = (yyvsp[(1) - (1)].funcall);
		else
			(yyval.expr) = new Uc_int_expression(0);
		}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1967 "ucparse.yy"
    { (yyval.expr) = new Uc_bool_expression(true); }
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1969 "ucparse.yy"
    { (yyval.expr) = new Uc_bool_expression(false); }
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1971 "ucparse.yy"
    { (yyval.expr) = new Uc_event_expression(); }
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1973 "ucparse.yy"
    { (yyval.expr) = new Uc_item_expression(); }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1975 "ucparse.yy"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1980 "ucparse.yy"
    {
		(yyval.expr) = new Uc_new_expression(new Uc_class_inst_symbol("", (yyvsp[(2) - (5)].cls), 0), (yyvsp[(4) - (5)].exprlist));
		}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1992 "ucparse.yy"
    { (yyval.membersel) = new Member_selector((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].strval)); }
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1997 "ucparse.yy"
    {
		(yyval.funcall) = cls_function_call((yyvsp[(1) - (5)].membersel)->expr, cur_class, (yyvsp[(1) - (5)].membersel)->name, (yyvsp[(2) - (5)].intval), (yyvsp[(4) - (5)].exprlist));
		delete (yyvsp[(1) - (5)].membersel);
		}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2002 "ucparse.yy"
    {
		(yyval.funcall) = cls_function_call(0, cur_class, (yyvsp[(1) - (5)].strval), (yyvsp[(2) - (5)].intval), (yyvsp[(4) - (5)].exprlist));
		}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2006 "ucparse.yy"
    {
		(yyval.funcall) = cls_method_call((yyvsp[(1) - (8)].expr), (yyvsp[(1) - (8)].expr)->get_cls(), (yyvsp[(3) - (8)].cls), (yyvsp[(5) - (8)].strval), (yyvsp[(7) - (8)].exprlist));
		}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2010 "ucparse.yy"
    {
		(yyval.funcall) = cls_method_call(0, cur_class, (yyvsp[(1) - (6)].cls), (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].exprlist));
		}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 2014 "ucparse.yy"
    {
		(yyval.funcall) = new Uc_call_expression((yyvsp[(5) - (9)].expr), (yyvsp[(8) - (9)].exprlist), cur_fun);
		(yyval.funcall)->set_itemref((yyvsp[(1) - (9)].expr));
		}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 2019 "ucparse.yy"
    {
		(yyval.funcall) = new Uc_call_expression((yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].exprlist), cur_fun);
		(yyval.funcall)->set_itemref(0);
		}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 2024 "ucparse.yy"
    {
		int num;
		if (!(yyvsp[(5) - (9)].expr)->eval_const(num))
			{
			char buf[150];
			sprintf(buf, "Failed to obtain value from integer constant");
			yyerror(buf);
			(yyval.funcall) = 0;
			}
		else
			{
			(yyval.funcall) = new Uc_call_expression(Uc_function::get_intrinsic(num), 
						(yyvsp[(8) - (9)].exprlist), cur_fun);
			(yyval.funcall)->set_itemref((yyvsp[(1) - (9)].expr));
			(yyval.funcall)->check_params();
			}
		}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 2042 "ucparse.yy"
    {
		int num;
		if (!(yyvsp[(3) - (7)].expr)->eval_const(num))
			{
			char buf[150];
			sprintf(buf, "Failed to obtain value from integer constant");
			yyerror(buf);
			(yyval.funcall) = 0;
			}
		else
			{
			(yyval.funcall) = new Uc_call_expression(Uc_function::get_intrinsic(num), 
						(yyvsp[(6) - (7)].exprlist), cur_fun);
			(yyval.funcall)->check_params();
			}
		}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2062 "ucparse.yy"
    { (yyval.intval) = 1; }
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 2064 "ucparse.yy"
    { (yyval.intval) = 0; }
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 2070 "ucparse.yy"
    { (yyval.varvec) = new std::vector<Uc_var_symbol *>; }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2075 "ucparse.yy"
    { (yyvsp[(1) - (3)].varvec)->push_back((yyvsp[(3) - (3)].var)); }
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2077 "ucparse.yy"
    {
		(yyval.varvec) = new std::vector<Uc_var_symbol *>;
		(yyval.varvec)->push_back((yyvsp[(1) - (1)].var));
		}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 2085 "ucparse.yy"
    { (yyval.var) = new Uc_var_symbol((yyvsp[(1) - (1)].strval), 0); }
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 2087 "ucparse.yy"
    { (yyval.var) = new Uc_var_symbol((yyvsp[(2) - (2)].strval), 0); }
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 2089 "ucparse.yy"
    { (yyval.var) = new Uc_struct_var_symbol((yyvsp[(5) - (5)].strval), (yyvsp[(3) - (5)].struc), 0); }
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 2091 "ucparse.yy"
    { (yyval.var) = new Uc_class_inst_symbol((yyvsp[(5) - (5)].strval), (yyvsp[(3) - (5)].cls), 0); }
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 2096 "ucparse.yy"
    {
		int op = const_opcode.size() ? const_opcode.back() : UC_PUSHI;
		if (is_sint_32bit((yyvsp[(1) - (1)].intval)) && op != UC_PUSHI32)
			{
			char buf[150];
			if (is_int_32bit((yyvsp[(1) - (1)].intval)))
				{
				sprintf(buf, "Literal integer '%d' cannot be represented as 16-bit integer. Assuming '(long)' cast.",
						(yyvsp[(1) - (1)].intval));
				op = UC_PUSHI32;
				}
			else
				sprintf(buf, "Interpreting integer '%d' as the signed 16-bit integer '%d'. If this is incorrect, use '(long)' cast.",
						(yyvsp[(1) - (1)].intval), (short)(yyvsp[(1) - (1)].intval));
			yywarning(buf);
			}
		(yyval.expr) = new Uc_int_expression((yyvsp[(1) - (1)].intval), op);
		}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 2115 "ucparse.yy"
    { (yyval.expr) = new Uc_int_expression((yyvsp[(2) - (2)].intval), (yyvsp[(1) - (2)].intval)); }
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 2117 "ucparse.yy"
    {
		Uc_const_int_symbol *sym = 
				dynamic_cast<Uc_const_int_symbol *>((yyvsp[(1) - (1)].sym));
		if (!sym)
			{
			char buf[150];
			sprintf(buf, "'%s' is not a const int", (yyvsp[(1) - (1)].sym)->get_name());
			yyerror(buf);
			(yyval.expr) = 0;
			}
		else
			(yyval.expr) = sym->create_expression();
		}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 2131 "ucparse.yy"
    { (yyval.expr) = new Uc_bool_expression(true); }
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 2133 "ucparse.yy"
    { (yyval.expr) = new Uc_bool_expression(false); }
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 2139 "ucparse.yy"
    {
		yywarning("You should prepend 'void' for functions that do not return a value.");
		}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 2146 "ucparse.yy"
    { has_ret = true; }
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 2148 "ucparse.yy"
    { struct_type = (yyvsp[(3) - (4)].struc); }
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 2150 "ucparse.yy"
    { has_ret = false; }
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2155 "ucparse.yy"
    {
		(yyval.expr) = (yyvsp[(1) - (1)].sym)->create_expression();
		if (!(yyval.expr))
			{
			char buf[150];
			sprintf(buf, "Can't use '%s' here", (yyvsp[(1) - (1)].sym)->get_name());
			yyerror(buf);
			(yyval.expr) = new Uc_int_expression(0);
			}
		}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2169 "ucparse.yy"
    {
		Uc_var_symbol *var = dynamic_cast<Uc_var_symbol *>((yyvsp[(1) - (1)].sym));
		if (!var)
			{
			char buf[150];
			sprintf(buf, "'%s' not a 'var'", (yyvsp[(1) - (1)].sym)->get_name());
			yyerror(buf);
			sprintf(buf, "%s_needvar", (yyvsp[(1) - (1)].sym)->get_name());
			var = cur_fun->add_symbol(buf);
			}
		(yyval.var) = var;
		}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2185 "ucparse.yy"
    {
		Uc_symbol *sym = cur_fun->search_up((yyvsp[(1) - (1)].strval));
		if (!sym)
			{
			char buf[150];
			sprintf(buf, "'%s' not declared", (yyvsp[(1) - (1)].strval));
			yyerror(buf);
			sym = cur_fun->add_symbol((yyvsp[(1) - (1)].strval));
			}
		(yyval.sym) = sym;
		}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2200 "ucparse.yy"
    { (yyval.cls) = Find_class((yyvsp[(1) - (1)].strval)); }
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2205 "ucparse.yy"
    {
		Uc_struct_symbol *sym = dynamic_cast<Uc_struct_symbol *>(
				Uc_function::search_globals((yyvsp[(1) - (1)].strval)));
		if (!sym)
			{
			char buf[150];
			sprintf(buf, "'%s' not found, or is not a struct.", (yyvsp[(1) - (1)].strval));
			yyerror(buf);
			(yyval.struc) = 0;
			}
		else
			(yyval.struc) = sym;
		}
    break;



/* Line 1455 of yacc.c  */
#line 6160 "ucparse.cc"
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 2220 "ucparse.yy"


/*
 *	Create an array with an integer as the first element.
 */

static Uc_array_expression *Create_array
	(
	int e1,
	Uc_expression *e2
	)
	{
	Uc_array_expression *arr = new Uc_array_expression();
	arr->add(new Uc_int_expression(e1, UC_PUSHB));
	arr->add(e2);
	return arr;
	}
static Uc_array_expression *Create_array
	(
	int e1,
	Uc_expression *e2,
	Uc_expression *e3
	)
	{
	Uc_array_expression *arr = new Uc_array_expression();
	arr->add(new Uc_int_expression(e1, UC_PUSHB));
	arr->add(e2);
	arr->add(e3);
	return arr;
	}
static Uc_class *Find_class
	(
	const char *nm
	)
	{
	Uc_class_symbol *csym = dynamic_cast<Uc_class_symbol *>(
			Uc_function::search_globals(nm));
	if (!csym)
		{
		char buf[150];
		sprintf(buf, "'%s' not found, or is not a class.", nm);
		yyerror(buf);
		return 0;
		}
	return csym->get_cls();
	}

static bool Class_unexpected_error(Uc_expression *expr)
	{
	if (expr->is_class())
		{
		yyerror("Can't convert class into non-class");
		return true;
		}
	return false;
	}

static bool Nonclass_unexpected_error(Uc_expression *expr)
	{
	if (!expr->is_class())
		{
		yyerror("Can't convert non-class into class.");
		return true;
		}
	return false;
	}

static bool Incompatible_classes_error(Uc_class *src, Uc_class *trg)
	{
	if (!src->is_class_compatible(trg->get_name()))
		{
		char buf[180];
		sprintf(buf, "Class '%s' can't be converted into class '%s'",
				src->get_name(), trg->get_name());
		yyerror(buf);
		return true;
		}
	return false;
	}

static Uc_call_expression *cls_method_call
	(
	Uc_expression *ths,
	Uc_class *curcls,
	Uc_class *clsscope,
	char *nm,
	Uc_array_expression *parms
	)
	{
	if (!curcls && !(ths && ths->is_class()))
		{
		char buf[150];
		sprintf(buf, "'%s' requires a class object", nm);
		yyerror(buf);
		return 0;
		}

	if (Incompatible_classes_error(curcls, clsscope))
		return 0;

	Uc_symbol *sym = clsscope->get_scope()->search(nm);
	if (!sym)
		{
		char buf[150];
		sprintf(buf, "Function '%s' is not declared in class '%s'",
				nm, clsscope->get_name());
		yyerror(buf);
		return 0;
		}

	Uc_function_symbol *fun = dynamic_cast<Uc_function_symbol *>(sym);
	if (!fun)
		{
		char buf[150];
		sprintf(buf, "'%s' is not a function", nm);
		yyerror(buf);
		return 0;
		}

	Uc_call_expression *ret =
			new Uc_call_expression(sym, parms, cur_fun, false);
	ret->set_itemref(ths);
	ret->set_call_scope(clsscope);
	ret->check_params();
	return ret;
	}

static bool Uc_is_valid_calle
	(
	Uc_symbol *sym,
	Uc_expression *ths,
	char *nm
	)
	{
	Uc_function_symbol *fun = dynamic_cast<Uc_function_symbol *>(sym);
	if (!fun)		// Most likely an intrinsic.
		return true;

	if (fun->get_function_type() == Uc_function_symbol::utility_fun)
		{
		if (ths && !ths->is_class())
			{
			char buf[150];
			sprintf(buf, "'%s' is not an object or shape function", nm);
			yyerror(buf);
			return false;
			}
		else if (ths)
			{
			char buf[150];
			sprintf(buf, "'%s' is not a member of class '%s'",
					nm, ths->get_cls()->get_name());
			yyerror(buf);
			return false;
			}
		}
	else
		{
		if (!ths)
			{
			char buf[180];
			sprintf(buf, "'%s' expects an itemref, but none was supplied; using current itemref", nm);
			ths = new Uc_item_expression();
			yywarning(buf);
			return true;
			}
		}
	return true;
	}

static Uc_call_expression *cls_function_call
	(
	Uc_expression *ths,
	Uc_class *curcls,
	char *nm,
	bool original,
	Uc_array_expression *parms
	)
	{
	Uc_symbol *sym = 0;
	// Check class methods first.
	if (!ths && curcls)
		sym = curcls->get_scope()->search(nm);
	else if (ths && ths->is_class())
		sym = ths->get_cls()->get_scope()->search(nm);
	
	// Search for defined functions.
	if (!sym)
		{
		sym = cur_fun->search_up(nm);
		if (!original && !Uc_is_valid_calle(sym, ths, nm))
			return 0;
		}

	// Check for intrinsic name.
	if (!sym)		
		{
		string iname = string("UI_") + nm;
		sym = cur_fun->search_up(iname.c_str());
		// Treat as method call on 'item'.
		if (sym && !ths)
			ths = new Uc_item_expression();
		}

	if (!sym)
		{
		char buf[150];
		sprintf(buf, "'%s' not declared", nm);
		yyerror(buf);
		return 0;
		}
	else
		{
		Uc_call_expression *ret =
				new Uc_call_expression(sym, parms, cur_fun, original);
		ret->set_itemref(ths);
		ret->check_params();
		return ret;
		}
	}


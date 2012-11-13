
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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
	


/* Line 1676 of yacc.c  */
#line 365 "ucparse.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "logfile.y"
{ 
  struct strbuilder *s; 
  int *i;
}
/* Line 1529 of yacc.c.  */
#line 110 "logfile.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


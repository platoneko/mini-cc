/* A Bison parser, made by GNU Bison 3.5.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    INT = 258,
    ID = 259,
    RELOP = 260,
    TYPE = 261,
    COMP_ASSIGN = 262,
    FLOAT = 263,
    CHAR = 264,
    LP = 265,
    RP = 266,
    LC = 267,
    RC = 268,
    LS = 269,
    RS = 270,
    SEMI = 271,
    COMMA = 272,
    PLUS = 273,
    MINUS = 274,
    STAR = 275,
    DIV = 276,
    MOD = 277,
    ASSIGNOP = 278,
    AND = 279,
    OR = 280,
    NOT = 281,
    BITAND = 282,
    BITOR = 283,
    BITXOR = 284,
    BITSHL = 285,
    BITSHR = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    RETURN = 290,
    CONTINUE = 291,
    BREAK = 292,
    EXT_DEF_LIST = 293,
    EXT_VAR_DEF = 294,
    FUNC_DEF = 295,
    FUNC_DEC = 296,
    EXT_DEC_LIST = 297,
    PARAM_LIST = 298,
    PARAM_DEC = 299,
    VAR_DEF = 300,
    VAR_DEC = 301,
    VAR_DEC_LIST = 302,
    COMP_STM = 303,
    STM_LIST = 304,
    EXP_STMT = 305,
    IF_THEN = 306,
    IF_THEN_ELSE = 307,
    FUNC_CALL = 308,
    ARGS = 309,
    ARRAY_DEC = 310,
    ARRAY_REF = 311,
    ARRAY_SUB_LIST = 312,
    ARRAY_INIT_LIST = 313,
    ARRAY_PARAM = 314,
    VAR = 315,
    PARAM = 316,
    FUNC = 317,
    ARRAY = 318,
    VOID = 319,
    LABEL = 320,
    GOTO = 321,
    EQ = 322,
    NEQ = 323,
    LT = 324,
    LE = 325,
    GT = 326,
    GE = 327,
    UMINUS = 328,
    DPLUS = 329,
    DMINUS = 330,
    LOWER_THEN_ELSE = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    int    type_int;
    float  type_float;
    char   type_char;
    char   type_id[32];
    struct ASTNode *ptr;

#line 142 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

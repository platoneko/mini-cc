/* A Bison parser, made by GNU Bison 3.6.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    ID = 259,                      /* ID  */
    RELOP = 260,                   /* RELOP  */
    TYPE = 261,                    /* TYPE  */
    COMP_ASSIGN = 262,             /* COMP_ASSIGN  */
    FLOAT = 263,                   /* FLOAT  */
    CHAR = 264,                    /* CHAR  */
    LP = 265,                      /* LP  */
    RP = 266,                      /* RP  */
    LC = 267,                      /* LC  */
    RC = 268,                      /* RC  */
    LS = 269,                      /* LS  */
    RS = 270,                      /* RS  */
    SEMI = 271,                    /* SEMI  */
    COMMA = 272,                   /* COMMA  */
    PLUS = 273,                    /* PLUS  */
    MINUS = 274,                   /* MINUS  */
    STAR = 275,                    /* STAR  */
    DIV = 276,                     /* DIV  */
    MOD = 277,                     /* MOD  */
    ASSIGNOP = 278,                /* ASSIGNOP  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    NOT = 281,                     /* NOT  */
    BITAND = 282,                  /* BITAND  */
    BITOR = 283,                   /* BITOR  */
    BITXOR = 284,                  /* BITXOR  */
    BITSHL = 285,                  /* BITSHL  */
    BITSHR = 286,                  /* BITSHR  */
    IF = 287,                      /* IF  */
    ELSE = 288,                    /* ELSE  */
    WHILE = 289,                   /* WHILE  */
    RETURN = 290,                  /* RETURN  */
    CONTINUE = 291,                /* CONTINUE  */
    BREAK = 292,                   /* BREAK  */
    EXT_DEF_LIST = 293,            /* EXT_DEF_LIST  */
    EXT_VAR_DEF = 294,             /* EXT_VAR_DEF  */
    FUNC_DEF = 295,                /* FUNC_DEF  */
    FUNC_DEC = 296,                /* FUNC_DEC  */
    EXT_DEC_LIST = 297,            /* EXT_DEC_LIST  */
    PARAM_LIST = 298,              /* PARAM_LIST  */
    PARAM_DEC = 299,               /* PARAM_DEC  */
    VAR_DEF = 300,                 /* VAR_DEF  */
    VAR_DEC = 301,                 /* VAR_DEC  */
    VAR_DEC_LIST = 302,            /* VAR_DEC_LIST  */
    COMP_STM = 303,                /* COMP_STM  */
    STM_LIST = 304,                /* STM_LIST  */
    EXP_STMT = 305,                /* EXP_STMT  */
    IF_THEN = 306,                 /* IF_THEN  */
    IF_THEN_ELSE = 307,            /* IF_THEN_ELSE  */
    FUNC_CALL = 308,               /* FUNC_CALL  */
    ARGS = 309,                    /* ARGS  */
    ARRAY_DEC = 310,               /* ARRAY_DEC  */
    ARRAY_REF = 311,               /* ARRAY_REF  */
    ARRAY_SUB_LIST = 312,          /* ARRAY_SUB_LIST  */
    ARRAY_INIT_LIST = 313,         /* ARRAY_INIT_LIST  */
    ARRAY_PARAM = 314,             /* ARRAY_PARAM  */
    VAR = 315,                     /* VAR  */
    PARAM = 316,                   /* PARAM  */
    FUNC = 317,                    /* FUNC  */
    ARG = 318,                     /* ARG  */
    VOID = 319,                    /* VOID  */
    ARRAY = 320,                   /* ARRAY  */
    LARRAY_REF = 321,              /* LARRAY_REF  */
    RARRAY_REF = 322,              /* RARRAY_REF  */
    LABEL = 323,                   /* LABEL  */
    GOTO = 324,                    /* GOTO  */
    EQ = 325,                      /* EQ  */
    NEQ = 326,                     /* NEQ  */
    LT = 327,                      /* LT  */
    LE = 328,                      /* LE  */
    GT = 329,                      /* GT  */
    GE = 330,                      /* GE  */
    UMINUS = 331,                  /* UMINUS  */
    DPLUS = 332,                   /* DPLUS  */
    DMINUS = 333,                  /* DMINUS  */
    LOWER_THEN_ELSE = 334          /* LOWER_THEN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

    int    type_int;
    float  type_float;
    char   type_char;
    char   type_id[32];
    struct ASTNode *ptr;

#line 151 "parser.tab.h"

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

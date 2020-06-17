/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

#include "def.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern "C" int yylex();
void yyerror(const char* fmt, ...);

extern int hasError;

#line 87 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 224 "parser.tab.c"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_RELOP = 5,                      /* RELOP  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_COMP_ASSIGN = 7,                /* COMP_ASSIGN  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_LP = 10,                        /* LP  */
  YYSYMBOL_RP = 11,                        /* RP  */
  YYSYMBOL_LC = 12,                        /* LC  */
  YYSYMBOL_RC = 13,                        /* RC  */
  YYSYMBOL_LS = 14,                        /* LS  */
  YYSYMBOL_RS = 15,                        /* RS  */
  YYSYMBOL_SEMI = 16,                      /* SEMI  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_STAR = 20,                      /* STAR  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_MOD = 22,                       /* MOD  */
  YYSYMBOL_ASSIGNOP = 23,                  /* ASSIGNOP  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_BITAND = 27,                    /* BITAND  */
  YYSYMBOL_BITOR = 28,                     /* BITOR  */
  YYSYMBOL_BITXOR = 29,                    /* BITXOR  */
  YYSYMBOL_BITSHL = 30,                    /* BITSHL  */
  YYSYMBOL_BITSHR = 31,                    /* BITSHR  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_RETURN = 35,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 36,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 37,                     /* BREAK  */
  YYSYMBOL_EXT_DEF_LIST = 38,              /* EXT_DEF_LIST  */
  YYSYMBOL_EXT_VAR_DEF = 39,               /* EXT_VAR_DEF  */
  YYSYMBOL_FUNC_DEF = 40,                  /* FUNC_DEF  */
  YYSYMBOL_FUNC_DEC = 41,                  /* FUNC_DEC  */
  YYSYMBOL_EXT_DEC_LIST = 42,              /* EXT_DEC_LIST  */
  YYSYMBOL_PARAM_LIST = 43,                /* PARAM_LIST  */
  YYSYMBOL_PARAM_DEC = 44,                 /* PARAM_DEC  */
  YYSYMBOL_VAR_DEF = 45,                   /* VAR_DEF  */
  YYSYMBOL_VAR_DEC = 46,                   /* VAR_DEC  */
  YYSYMBOL_VAR_DEC_LIST = 47,              /* VAR_DEC_LIST  */
  YYSYMBOL_COMP_STM = 48,                  /* COMP_STM  */
  YYSYMBOL_STM_LIST = 49,                  /* STM_LIST  */
  YYSYMBOL_EXP_STMT = 50,                  /* EXP_STMT  */
  YYSYMBOL_IF_THEN = 51,                   /* IF_THEN  */
  YYSYMBOL_IF_THEN_ELSE = 52,              /* IF_THEN_ELSE  */
  YYSYMBOL_FUNC_CALL = 53,                 /* FUNC_CALL  */
  YYSYMBOL_ARGS = 54,                      /* ARGS  */
  YYSYMBOL_ARRAY_DEC = 55,                 /* ARRAY_DEC  */
  YYSYMBOL_ARRAY_REF = 56,                 /* ARRAY_REF  */
  YYSYMBOL_ARRAY_SUB_LIST = 57,            /* ARRAY_SUB_LIST  */
  YYSYMBOL_ARRAY_INIT_LIST = 58,           /* ARRAY_INIT_LIST  */
  YYSYMBOL_ARRAY_PARAM = 59,               /* ARRAY_PARAM  */
  YYSYMBOL_VAR = 60,                       /* VAR  */
  YYSYMBOL_PARAM = 61,                     /* PARAM  */
  YYSYMBOL_FUNC = 62,                      /* FUNC  */
  YYSYMBOL_ARG = 63,                       /* ARG  */
  YYSYMBOL_VOID = 64,                      /* VOID  */
  YYSYMBOL_ARRAY = 65,                     /* ARRAY  */
  YYSYMBOL_LARRAY_REF = 66,                /* LARRAY_REF  */
  YYSYMBOL_RARRAY_REF = 67,                /* RARRAY_REF  */
  YYSYMBOL_LABEL = 68,                     /* LABEL  */
  YYSYMBOL_GOTO = 69,                      /* GOTO  */
  YYSYMBOL_EQ = 70,                        /* EQ  */
  YYSYMBOL_NEQ = 71,                       /* NEQ  */
  YYSYMBOL_LT = 72,                        /* LT  */
  YYSYMBOL_LE = 73,                        /* LE  */
  YYSYMBOL_GT = 74,                        /* GT  */
  YYSYMBOL_GE = 75,                        /* GE  */
  YYSYMBOL_UMINUS = 76,                    /* UMINUS  */
  YYSYMBOL_DPLUS = 77,                     /* DPLUS  */
  YYSYMBOL_DMINUS = 78,                    /* DMINUS  */
  YYSYMBOL_LOWER_THEN_ELSE = 79,           /* LOWER_THEN_ELSE  */
  YYSYMBOL_YYACCEPT = 80,                  /* $accept  */
  YYSYMBOL_Program = 81,                   /* Program  */
  YYSYMBOL_ExtDefList = 82,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 83,                    /* ExtDef  */
  YYSYMBOL_Specifier = 84,                 /* Specifier  */
  YYSYMBOL_ExtDecList = 85,                /* ExtDecList  */
  YYSYMBOL_VarDec = 86,                    /* VarDec  */
  YYSYMBOL_FuncDec = 87,                   /* FuncDec  */
  YYSYMBOL_ParamList = 88,                 /* ParamList  */
  YYSYMBOL_ParamDec = 89,                  /* ParamDec  */
  YYSYMBOL_CompSt = 90,                    /* CompSt  */
  YYSYMBOL_StmList = 91,                   /* StmList  */
  YYSYMBOL_Stmt = 92,                      /* Stmt  */
  YYSYMBOL_VarDecList = 93,                /* VarDecList  */
  YYSYMBOL_Exp = 94,                       /* Exp  */
  YYSYMBOL_Args = 95,                      /* Args  */
  YYSYMBOL_ArrayDec = 96,                  /* ArrayDec  */
  YYSYMBOL_ArraySubList = 97,              /* ArraySubList  */
  YYSYMBOL_ArrayInitList = 98              /* ArrayInitList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

#define YYMAXUTOK   334


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    78,    79,    82,    83,    84,    87,    90,
      91,    92,    93,    96,    97,   100,   101,   104,   105,   108,
     109,   112,   115,   116,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   132,   133,   134,   135,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   169,   170,
     173,   174,   177,   178,   179,   180,   183
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "ID", "RELOP",
  "TYPE", "COMP_ASSIGN", "FLOAT", "CHAR", "LP", "RP", "LC", "RC", "LS",
  "RS", "SEMI", "COMMA", "PLUS", "MINUS", "STAR", "DIV", "MOD", "ASSIGNOP",
  "AND", "OR", "NOT", "BITAND", "BITOR", "BITXOR", "BITSHL", "BITSHR",
  "IF", "ELSE", "WHILE", "RETURN", "CONTINUE", "BREAK", "EXT_DEF_LIST",
  "EXT_VAR_DEF", "FUNC_DEF", "FUNC_DEC", "EXT_DEC_LIST", "PARAM_LIST",
  "PARAM_DEC", "VAR_DEF", "VAR_DEC", "VAR_DEC_LIST", "COMP_STM",
  "STM_LIST", "EXP_STMT", "IF_THEN", "IF_THEN_ELSE", "FUNC_CALL", "ARGS",
  "ARRAY_DEC", "ARRAY_REF", "ARRAY_SUB_LIST", "ARRAY_INIT_LIST",
  "ARRAY_PARAM", "VAR", "PARAM", "FUNC", "ARG", "VOID", "ARRAY",
  "LARRAY_REF", "RARRAY_REF", "LABEL", "GOTO", "EQ", "NEQ", "LT", "LE",
  "GT", "GE", "UMINUS", "DPLUS", "DMINUS", "LOWER_THEN_ELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "Specifier", "ExtDecList", "VarDec",
  "FuncDec", "ParamList", "ParamDec", "CompSt", "StmList", "Stmt",
  "VarDecList", "Exp", "Args", "ArrayDec", "ArraySubList", "ArrayInitList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
};
#endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -12,   -95,    33,   -95,     6,    36,   -95,   -95,   -95,
      25,    31,    24,    40,    49,    38,    19,     5,    44,   -95,
      65,    69,   -95,    65,   -95,    70,    73,    72,   -95,    66,
     -95,   -95,     5,    84,     5,     5,     5,     5,   144,   357,
      98,     3,   -95,   -95,   104,   105,    83,   111,   114,    65,
     -95,   119,    69,   172,   -95,    84,   -95,   130,   109,   -95,
     205,   -95,   -67,   -67,   -67,   -67,     5,     5,    84,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,   -95,   -95,     5,   -95,     5,     5,   -95,   235,
     -95,   -95,   120,   122,   123,   -95,   -95,   -95,   -95,   -95,
     -95,   267,   128,   -95,   103,   357,   -95,   198,   198,   -67,
     -67,   -67,   357,   409,   389,   470,   427,   450,   136,   136,
     129,   296,   328,   -95,    65,   -95,    65,     5,   -95,   -95,
      69,    69,   -95,   -95,   -95,   110,   -95,    69,   -95
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     8,     0,     2,     0,     0,     7,     1,     4,
      13,     0,     9,     0,    11,     0,     0,     0,    70,     5,
       0,    22,     6,     0,    16,     0,     0,    17,    65,    64,
      66,    67,     0,    74,     0,     0,     0,     0,     0,    14,
       0,    13,    10,    32,     0,     0,     0,     0,     0,     0,
      26,     0,    22,     0,    12,    19,    15,     0,     0,    63,
       0,    75,    55,    56,    57,    59,     0,     0,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    60,     0,    71,     0,     0,    28,     0,
      33,    34,    35,     0,    37,    21,    23,    25,    20,    18,
      62,    69,     0,    54,    42,    48,    73,    43,    44,    45,
      46,    47,    39,    40,    41,    49,    50,    51,    52,    53,
       0,     0,     0,    27,     0,    24,     0,     0,    61,    76,
       0,     0,    36,    38,    68,    29,    31,     0,    30
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   139,   -95,   126,   -18,   -24,   -95,    88,   -95,
     135,   100,   -94,    26,   -16,   -81,   -17,    61,   -95
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    49,    11,    12,    13,    26,    27,
      50,    51,    52,    93,    53,   102,    14,    18,    85
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    39,    42,   120,     7,    54,    -3,     1,    28,    29,
      82,    83,     2,    30,    31,    32,    60,    16,    62,    63,
      64,    65,    28,    29,    34,    92,    17,    30,    31,    32,
      89,    35,    94,     8,    33,    15,   135,   136,    34,    16,
      10,    20,   101,   138,     2,    35,   134,    19,    17,    24,
     104,   105,    21,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    23,    40,   101,    41,
     121,   122,    28,    29,    55,     2,    58,    30,    31,    32,
      16,    21,    36,    37,    56,    43,    28,    29,    34,    57,
      59,    30,    31,    32,    61,    35,    36,    37,    16,    88,
      92,    44,    34,    45,    46,    47,    48,    94,   133,    35,
      84,   101,    28,    29,    86,    87,    98,    30,    31,    32,
     100,    69,    70,    71,    72,    73,     6,    90,    34,   106,
      91,     6,    95,    80,    81,    35,     2,   124,   125,   128,
     126,    25,   129,   137,     9,    99,    36,    37,    22,    66,
     132,    67,    96,     0,    69,    70,    71,    72,    73,    68,
      36,    37,    69,    70,    71,    72,    73,    74,    75,    76,
       0,    77,    78,    79,    80,    81,     0,    66,     0,    67,
      82,    83,     0,    25,     0,     0,    36,    37,    97,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
      66,     0,    67,    82,    83,     0,   103,     0,    71,    72,
      73,    82,    83,    69,    70,    71,    72,    73,    74,    75,
      76,     0,    77,    78,    79,    80,    81,     0,     0,     0,
      66,     0,    67,     0,     0,     0,     0,     0,     0,    82,
      83,   123,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,    77,    78,    79,    80,    81,     0,     0,     0,
       0,     0,    66,     0,    67,    82,    83,     0,     0,     0,
       0,     0,    82,    83,   127,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    77,    78,    79,    80,    81,     0,
       0,    66,     0,    67,     0,     0,     0,   130,     0,     0,
       0,     0,    82,    83,    69,    70,    71,    72,    73,    74,
      75,    76,     0,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,    66,     0,    67,     0,     0,     0,   131,
       0,     0,     0,     0,    82,    83,    69,    70,    71,    72,
      73,    74,    75,    76,     0,    77,    78,    79,    80,    81,
       0,     0,    66,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    69,    70,    71,
      72,    73,     0,    75,    66,     0,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    66,     0,    82,    83,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,     0,     0,     0,    77,    66,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    69,    70,
      71,    72,    73,     0,     0,    66,     0,    77,     0,     0,
      80,    81,     0,     0,     0,     0,    82,    83,    69,    70,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83
};

static const yytype_int16 yycheck[] =
{
      16,    17,    20,    84,    16,    23,     0,     1,     3,     4,
      77,    78,     6,     8,     9,    10,    32,    14,    34,    35,
      36,    37,     3,     4,    19,    49,    23,     8,     9,    10,
      46,    26,    49,     0,    15,    10,   130,   131,    19,    14,
       4,    17,    58,   137,     6,    26,   127,    16,    23,    11,
      66,    67,    12,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    17,    23,    84,     4,
      86,    87,     3,     4,     4,     6,    10,     8,     9,    10,
      14,    12,    77,    78,    11,    16,     3,     4,    19,    17,
      29,     8,     9,    10,    33,    26,    77,    78,    14,    16,
     124,    32,    19,    34,    35,    36,    37,   124,   126,    26,
      12,   127,     3,     4,    10,    10,    55,     8,     9,    10,
      11,    18,    19,    20,    21,    22,     0,    16,    19,    68,
      16,     5,    13,    30,    31,    26,     6,    17,    16,    11,
      17,    15,    13,    33,     5,    57,    77,    78,    13,     5,
     124,     7,    52,    -1,    18,    19,    20,    21,    22,    15,
      77,    78,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    -1,     5,    -1,     7,
      77,    78,    -1,    57,    -1,    -1,    77,    78,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    -1,     7,    77,    78,    -1,    11,    -1,    20,    21,
      22,    77,    78,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
       5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,     5,    -1,     7,    77,    78,    -1,    -1,    -1,
      -1,    -1,    77,    78,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,     5,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    77,    78,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,     5,    -1,     7,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    77,    78,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      -1,    -1,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    18,    19,    20,
      21,    22,    -1,    24,     5,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,     5,    -1,    77,    78,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,     5,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    18,    19,
      20,    21,    22,    -1,    -1,     5,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    77,    78,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     6,    81,    82,    83,    84,    16,     0,    82,
       4,    85,    86,    87,    96,    10,    14,    23,    97,    16,
      17,    12,    90,    17,    11,    84,    88,    89,     3,     4,
       8,     9,    10,    15,    19,    26,    77,    78,    94,    94,
      23,     4,    85,    16,    32,    34,    35,    36,    37,    84,
      90,    91,    92,    94,    85,     4,    11,    17,    10,    97,
      94,    97,    94,    94,    94,    94,     5,     7,    15,    18,
      19,    20,    21,    22,    23,    24,    25,    27,    28,    29,
      30,    31,    77,    78,    12,    98,    10,    10,    16,    94,
      16,    16,    86,    93,    96,    13,    91,    16,    97,    88,
      11,    94,    95,    11,    94,    94,    97,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    94,    94,    16,    17,    16,    17,    17,    11,    13,
      11,    11,    93,    85,    95,    92,    92,    33,    92
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    80,    81,    82,    82,    83,    83,    83,    84,    85,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    97,    98
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     3,     2,     1,     1,
       3,     1,     3,     1,     3,     4,     3,     1,     3,     2,
       3,     3,     0,     2,     3,     2,     1,     3,     2,     5,
       7,     5,     1,     2,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     4,     3,     2,     1,     1,     1,     1,     3,     1,
       2,     4,     3,     4,     2,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 65 "parser.y"
                    {
    analysis((yyvsp[0].ptr));
    if (hasError) {
        fprintf(stderr, "Detect fatal errors, compiler terminated!\n");
        exit(-1);
    }
    displayTable();
    genTAC((yyvsp[0].ptr));
    displayTAC((yyvsp[0].ptr)->code);
    genMips((yyvsp[0].ptr)->code, "example.asm");
}
#line 1885 "parser.tab.c"
    break;

  case 3:
#line 78 "parser.y"
            { (yyval.ptr) = NULL; }
#line 1891 "parser.tab.c"
    break;

  case 4:
#line 79 "parser.y"
                    { (yyval.ptr) = mknode(2, EXT_DEF_LIST, yylineno, (yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 1897 "parser.tab.c"
    break;

  case 5:
#line 82 "parser.y"
                                  { (yyval.ptr) = mknode(2, EXT_VAR_DEF, yylineno, (yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 1903 "parser.tab.c"
    break;

  case 6:
#line 83 "parser.y"
                           { (yyval.ptr) = mknode(3, FUNC_DEF, yylineno, (yyvsp[-2].ptr), (yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 1909 "parser.tab.c"
    break;

  case 7:
#line 84 "parser.y"
             { (yyval.ptr) = NULL; }
#line 1915 "parser.tab.c"
    break;

  case 8:
#line 87 "parser.y"
                { (yyval.ptr) = mknode(0, TYPE, yylineno); strcpy((yyval.ptr)->type_id, (yyvsp[0].type_id));}
#line 1921 "parser.tab.c"
    break;

  case 9:
#line 90 "parser.y"
                   { (yyval.ptr) = mknode(1, EXT_DEC_LIST, yylineno, (yyvsp[0].ptr)); }
#line 1927 "parser.tab.c"
    break;

  case 10:
#line 91 "parser.y"
                          { (yyval.ptr) = mknode(2, EXT_DEC_LIST, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1933 "parser.tab.c"
    break;

  case 11:
#line 92 "parser.y"
           { (yyval.ptr) = mknode(1, EXT_DEC_LIST, yylineno, (yyvsp[0].ptr)); }
#line 1939 "parser.tab.c"
    break;

  case 12:
#line 93 "parser.y"
                            { (yyval.ptr) = mknode(2, EXT_DEC_LIST, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1945 "parser.tab.c"
    break;

  case 13:
#line 96 "parser.y"
           { (yyval.ptr) = mknode(0, VAR_DEC, yylineno); strcpy((yyval.ptr)->type_id, (yyvsp[0].type_id)); }
#line 1951 "parser.tab.c"
    break;

  case 14:
#line 97 "parser.y"
                  { (yyval.ptr) = mknode(1, VAR_DEC, yylineno, (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-2].type_id)); }
#line 1957 "parser.tab.c"
    break;

  case 15:
#line 100 "parser.y"
                            { (yyval.ptr) = mknode(1, FUNC_DEC, yylineno, (yyvsp[-1].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-3].type_id)); }
#line 1963 "parser.tab.c"
    break;

  case 16:
#line 101 "parser.y"
           { (yyval.ptr) = mknode(0, FUNC_DEC, yylineno); strcpy((yyval.ptr)->type_id, (yyvsp[-2].type_id)); (yyval.ptr)->ptr[0] = NULL; }
#line 1969 "parser.tab.c"
    break;

  case 17:
#line 104 "parser.y"
                    { (yyval.ptr) = mknode(1, PARAM_LIST, yylineno, (yyvsp[0].ptr)); }
#line 1975 "parser.tab.c"
    break;

  case 18:
#line 105 "parser.y"
                           { (yyval.ptr) = mknode(2, PARAM_LIST, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 1981 "parser.tab.c"
    break;

  case 19:
#line 108 "parser.y"
                       { (yyval.ptr) = mknode(1, PARAM_DEC, yylineno, (yyvsp[-1].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[0].type_id)); }
#line 1987 "parser.tab.c"
    break;

  case 20:
#line 109 "parser.y"
                            { (yyval.ptr) = mknode(2, ARRAY_PARAM, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-1].type_id)); }
#line 1993 "parser.tab.c"
    break;

  case 21:
#line 112 "parser.y"
                      { (yyval.ptr) = mknode(1, COMP_STM, yylineno, (yyvsp[-1].ptr)); }
#line 1999 "parser.tab.c"
    break;

  case 22:
#line 115 "parser.y"
         { (yyval.ptr)=NULL; }
#line 2005 "parser.tab.c"
    break;

  case 23:
#line 116 "parser.y"
               { (yyval.ptr) = mknode(2, STM_LIST, yylineno, (yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2011 "parser.tab.c"
    break;

  case 24:
#line 119 "parser.y"
                                { (yyval.ptr) = mknode(2, VAR_DEF, yylineno, (yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 2017 "parser.tab.c"
    break;

  case 25:
#line 120 "parser.y"
           { (yyval.ptr) = mknode(1, EXP_STMT, yylineno, (yyvsp[-1].ptr)); }
#line 2023 "parser.tab.c"
    break;

  case 26:
#line 121 "parser.y"
         { (yyval.ptr)=(yyvsp[0].ptr); }
#line 2029 "parser.tab.c"
    break;

  case 27:
#line 122 "parser.y"
                  { (yyval.ptr) = mknode(1, RETURN, yylineno, (yyvsp[-1].ptr)); }
#line 2035 "parser.tab.c"
    break;

  case 28:
#line 123 "parser.y"
              { (yyval.ptr) = mknode(0, RETURN, yylineno); }
#line 2041 "parser.tab.c"
    break;

  case 29:
#line 124 "parser.y"
                                          { (yyval.ptr) = mknode(2, IF_THEN, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2047 "parser.tab.c"
    break;

  case 30:
#line 125 "parser.y"
                              { (yyval.ptr) = mknode(3, IF_THEN_ELSE, yylineno, (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2053 "parser.tab.c"
    break;

  case 31:
#line 126 "parser.y"
                       { (yyval.ptr) = mknode(2, WHILE, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2059 "parser.tab.c"
    break;

  case 32:
#line 127 "parser.y"
       { (yyval.ptr) = NULL; }
#line 2065 "parser.tab.c"
    break;

  case 33:
#line 128 "parser.y"
                { (yyval.ptr) = mknode(0, CONTINUE, yylineno); }
#line 2071 "parser.tab.c"
    break;

  case 34:
#line 129 "parser.y"
             { (yyval.ptr) = mknode(0, BREAK, yylineno); }
#line 2077 "parser.tab.c"
    break;

  case 35:
#line 132 "parser.y"
                   { (yyval.ptr) = mknode(1, VAR_DEC_LIST, yylineno, (yyvsp[0].ptr)); }
#line 2083 "parser.tab.c"
    break;

  case 36:
#line 133 "parser.y"
                          { (yyval.ptr) = mknode(2, VAR_DEC_LIST, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2089 "parser.tab.c"
    break;

  case 37:
#line 134 "parser.y"
           { (yyval.ptr) = mknode(1, VAR_DEC_LIST, yylineno, (yyvsp[0].ptr)); }
#line 2095 "parser.tab.c"
    break;

  case 38:
#line 135 "parser.y"
                            { (yyval.ptr) = mknode(2, VAR_DEC_LIST, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2101 "parser.tab.c"
    break;

  case 39:
#line 138 "parser.y"
                      { (yyval.ptr) = mknode(2, ASSIGNOP, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2107 "parser.tab.c"
    break;

  case 40:
#line 139 "parser.y"
              { (yyval.ptr) = mknode(2, AND, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2113 "parser.tab.c"
    break;

  case 41:
#line 140 "parser.y"
             { (yyval.ptr) = mknode(2, OR, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2119 "parser.tab.c"
    break;

  case 42:
#line 141 "parser.y"
                { (yyval.ptr) = mknode(2, RELOP, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-1].type_id)); }
#line 2125 "parser.tab.c"
    break;

  case 43:
#line 142 "parser.y"
               { (yyval.ptr) = mknode(2, PLUS, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2131 "parser.tab.c"
    break;

  case 44:
#line 143 "parser.y"
                { (yyval.ptr) = mknode(2, MINUS, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2137 "parser.tab.c"
    break;

  case 45:
#line 144 "parser.y"
               { (yyval.ptr) = mknode(2, STAR, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2143 "parser.tab.c"
    break;

  case 46:
#line 145 "parser.y"
              { (yyval.ptr) = mknode(2, DIV, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2149 "parser.tab.c"
    break;

  case 47:
#line 146 "parser.y"
              { (yyval.ptr) = mknode(2, MOD, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2155 "parser.tab.c"
    break;

  case 48:
#line 147 "parser.y"
                      { (yyval.ptr) = mknode(2, COMP_ASSIGN, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-1].type_id)); }
#line 2161 "parser.tab.c"
    break;

  case 49:
#line 148 "parser.y"
                 { (yyval.ptr) = mknode(2, BITAND, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2167 "parser.tab.c"
    break;

  case 50:
#line 149 "parser.y"
                { (yyval.ptr) = mknode(2, BITOR, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2173 "parser.tab.c"
    break;

  case 51:
#line 150 "parser.y"
                 { (yyval.ptr) = mknode(2, BITXOR, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2179 "parser.tab.c"
    break;

  case 52:
#line 151 "parser.y"
                 { (yyval.ptr) = mknode(2, BITSHL, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2185 "parser.tab.c"
    break;

  case 53:
#line 152 "parser.y"
                 { (yyval.ptr) = mknode(2, BITSHR, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2191 "parser.tab.c"
    break;

  case 54:
#line 153 "parser.y"
            { (yyval.ptr) = (yyvsp[-1].ptr); }
#line 2197 "parser.tab.c"
    break;

  case 55:
#line 154 "parser.y"
                         { (yyval.ptr) = mknode(1, UMINUS, yylineno, (yyvsp[0].ptr)); }
#line 2203 "parser.tab.c"
    break;

  case 56:
#line 155 "parser.y"
          { (yyval.ptr) = mknode(1, NOT, yylineno, (yyvsp[0].ptr)); }
#line 2209 "parser.tab.c"
    break;

  case 57:
#line 156 "parser.y"
            { (yyval.ptr) = mknode(1, DPLUS, yylineno, (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, "LDPLUS"); }
#line 2215 "parser.tab.c"
    break;

  case 58:
#line 157 "parser.y"
            { (yyval.ptr) = mknode(1, DPLUS, yylineno, (yyvsp[-1].ptr)); strcpy((yyval.ptr)->type_id, "RDPLUS"); }
#line 2221 "parser.tab.c"
    break;

  case 59:
#line 158 "parser.y"
             { (yyval.ptr) = mknode(1, DMINUS, yylineno, (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, "LDMINUS"); }
#line 2227 "parser.tab.c"
    break;

  case 60:
#line 159 "parser.y"
             { (yyval.ptr) = mknode(1, DMINUS, yylineno, (yyvsp[-1].ptr)); strcpy((yyval.ptr)->type_id, "RDMINUS"); }
#line 2233 "parser.tab.c"
    break;

  case 61:
#line 160 "parser.y"
                { (yyval.ptr) = mknode(1, FUNC_CALL, yylineno, (yyvsp[-1].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-3].type_id)); }
#line 2239 "parser.tab.c"
    break;

  case 62:
#line 161 "parser.y"
           { (yyval.ptr) = mknode(0, FUNC_CALL, yylineno); strcpy((yyval.ptr)->type_id, (yyvsp[-2].type_id)); }
#line 2245 "parser.tab.c"
    break;

  case 63:
#line 162 "parser.y"
                  { (yyval.ptr) = mknode(1, ARRAY_REF, yylineno, (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-1].type_id)); }
#line 2251 "parser.tab.c"
    break;

  case 64:
#line 163 "parser.y"
     { (yyval.ptr) = mknode(0, ID, yylineno); strcpy((yyval.ptr)->type_id, (yyvsp[0].type_id)); }
#line 2257 "parser.tab.c"
    break;

  case 65:
#line 164 "parser.y"
      { (yyval.ptr) = mknode(0, INT, yylineno); (yyval.ptr)->type_int = (yyvsp[0].type_int); }
#line 2263 "parser.tab.c"
    break;

  case 66:
#line 165 "parser.y"
        { (yyval.ptr) = mknode(0, FLOAT, yylineno); (yyval.ptr)->type_float = (yyvsp[0].type_float); }
#line 2269 "parser.tab.c"
    break;

  case 67:
#line 166 "parser.y"
       { (yyval.ptr) = mknode(0, INT, yylineno); (yyval.ptr)->type_int = (yyvsp[0].type_char); }
#line 2275 "parser.tab.c"
    break;

  case 68:
#line 169 "parser.y"
                     { (yyval.ptr) = mknode(2, ARGS, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2281 "parser.tab.c"
    break;

  case 69:
#line 170 "parser.y"
      { (yyval.ptr) = mknode(1, ARGS, yylineno, (yyvsp[0].ptr)); }
#line 2287 "parser.tab.c"
    break;

  case 70:
#line 173 "parser.y"
                          { (yyval.ptr) = mknode(1, ARRAY_DEC, yylineno, (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-1].type_id)); }
#line 2293 "parser.tab.c"
    break;

  case 71:
#line 174 "parser.y"
                                         { (yyval.ptr) = mknode(2, ARRAY_DEC, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); strcpy((yyval.ptr)->type_id, (yyvsp[-3].type_id)); }
#line 2299 "parser.tab.c"
    break;

  case 72:
#line 177 "parser.y"
                        { (yyval.ptr) = mknode(1, ARRAY_SUB_LIST, yylineno, (yyvsp[-1].ptr)); }
#line 2305 "parser.tab.c"
    break;

  case 73:
#line 178 "parser.y"
                         { (yyval.ptr) = mknode(2, ARRAY_SUB_LIST, yylineno, (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2311 "parser.tab.c"
    break;

  case 74:
#line 179 "parser.y"
        { (yyval.ptr) = mknode(1, ARRAY_SUB_LIST, yylineno, NULL); }
#line 2317 "parser.tab.c"
    break;

  case 75:
#line 180 "parser.y"
                     { (yyval.ptr) = mknode(2, ARRAY_SUB_LIST, yylineno, NULL, (yyvsp[0].ptr)); }
#line 2323 "parser.tab.c"
    break;

  case 76:
#line 183 "parser.y"
                          { (yyval.ptr) = mknode(1, ARRAY_INIT_LIST, yylineno, (yyvsp[-1].ptr)); }
#line 2329 "parser.tab.c"
    break;


#line 2333 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 186 "parser.y"


int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");
    if (!yyin) return -1;
    yylineno = 1;
    yyparse();
    return 0;
}

void yyerror(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "line %d: ", yylineno);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
    exit(-1);
}

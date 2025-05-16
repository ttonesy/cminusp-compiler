/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 75 "lab9.y"

    /* begin specs */
    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ast.h"
    #include "symtable.h"
    #include "emit.h"

    ASTnode *PROGRAM;

    int yylex(); /* prototype for the lexer function */

    extern int lineno; /*line number from LEX*/
    extern int mydebug; /*debugging flag*/

    int LEVEL = 0; /* global context variable for knowing how many levels deep we are in the tree */
    int OFFSET = 0; /* global variable for accumulating needed runtime space */
    int GOFFSET = 0; /* global variable for acuumlating global variable offset */
    int maxOFFSET = 0; /* largest offset needed for the current function */

    void yyerror(char *s) /* Called by yyparse on error */
    {
        /* Print error message */
        printf("YACC PARSE ERROR: %s on line number %d\n", s, lineno);
    }

#line 100 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    T_NUM = 258,                   /* T_NUM  */
    T_ID = 259,                    /* T_ID  */
    T_STRING = 260,                /* T_STRING  */
    T_INT = 261,                   /* T_INT  */
    T_VOID = 262,                  /* T_VOID  */
    T_READ = 263,                  /* T_READ  */
    T_IF = 264,                    /* T_IF  */
    T_ELSE = 265,                  /* T_ELSE  */
    T_WHILE = 266,                 /* T_WHILE  */
    T_WRITE = 267,                 /* T_WRITE  */
    T_RETURN = 268,                /* T_RETURN  */
    T_LT = 269,                    /* T_LT  */
    T_GT = 270,                    /* T_GT  */
    T_GE = 271,                    /* T_GE  */
    T_LE = 272,                    /* T_LE  */
    T_EQ = 273,                    /* T_EQ  */
    T_NE = 274                     /* T_NE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_NUM 258
#define T_ID 259
#define T_STRING 260
#define T_INT 261
#define T_VOID 262
#define T_READ 263
#define T_IF 264
#define T_ELSE 265
#define T_WHILE 266
#define T_WRITE 267
#define T_RETURN 268
#define T_LT 269
#define T_GT 270
#define T_GE 271
#define T_LE 272
#define T_EQ 273
#define T_NE 274

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 108 "lab9.y"

    int value;
    char *string;
    ASTnode *node;
    enum AST_MY_DATA_TYPE d_type;
    enum AST_OPERATORS operator;

#line 199 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_NUM = 3,                      /* T_NUM  */
  YYSYMBOL_T_ID = 4,                       /* T_ID  */
  YYSYMBOL_T_STRING = 5,                   /* T_STRING  */
  YYSYMBOL_T_INT = 6,                      /* T_INT  */
  YYSYMBOL_T_VOID = 7,                     /* T_VOID  */
  YYSYMBOL_T_READ = 8,                     /* T_READ  */
  YYSYMBOL_T_IF = 9,                       /* T_IF  */
  YYSYMBOL_T_ELSE = 10,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 11,                   /* T_WHILE  */
  YYSYMBOL_T_WRITE = 12,                   /* T_WRITE  */
  YYSYMBOL_T_RETURN = 13,                  /* T_RETURN  */
  YYSYMBOL_T_LT = 14,                      /* T_LT  */
  YYSYMBOL_T_GT = 15,                      /* T_GT  */
  YYSYMBOL_T_GE = 16,                      /* T_GE  */
  YYSYMBOL_T_LE = 17,                      /* T_LE  */
  YYSYMBOL_T_EQ = 18,                      /* T_EQ  */
  YYSYMBOL_T_NE = 19,                      /* T_NE  */
  YYSYMBOL_20_ = 20,                       /* ';'  */
  YYSYMBOL_21_ = 21,                       /* '['  */
  YYSYMBOL_22_ = 22,                       /* ']'  */
  YYSYMBOL_23_ = 23,                       /* ','  */
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* ')'  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* '='  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_Program = 35,                   /* Program  */
  YYSYMBOL_Declaration_List = 36,          /* Declaration_List  */
  YYSYMBOL_Declaration = 37,               /* Declaration  */
  YYSYMBOL_Var_Declaration = 38,           /* Var_Declaration  */
  YYSYMBOL_Var_List = 39,                  /* Var_List  */
  YYSYMBOL_Type_Specifier = 40,            /* Type_Specifier  */
  YYSYMBOL_Fun_Declaration = 41,           /* Fun_Declaration  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_Params = 44,                    /* Params  */
  YYSYMBOL_Param_List = 45,                /* Param_List  */
  YYSYMBOL_Param = 46,                     /* Param  */
  YYSYMBOL_Compound_Stmt = 47,             /* Compound_Stmt  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_Local_Declarations = 49,        /* Local_Declarations  */
  YYSYMBOL_Statement_List = 50,            /* Statement_List  */
  YYSYMBOL_Statement = 51,                 /* Statement  */
  YYSYMBOL_Expression_Stmt = 52,           /* Expression_Stmt  */
  YYSYMBOL_Selection_Stmt = 53,            /* Selection_Stmt  */
  YYSYMBOL_Iteration_Stmt = 54,            /* Iteration_Stmt  */
  YYSYMBOL_Return_Stmt = 55,               /* Return_Stmt  */
  YYSYMBOL_Read_Stmt = 56,                 /* Read_Stmt  */
  YYSYMBOL_Write_Stmt = 57,                /* Write_Stmt  */
  YYSYMBOL_Assignment_Stmt = 58,           /* Assignment_Stmt  */
  YYSYMBOL_Var = 59,                       /* Var  */
  YYSYMBOL_Expression = 60,                /* Expression  */
  YYSYMBOL_Simple_Expression = 61,         /* Simple_Expression  */
  YYSYMBOL_Relop = 62,                     /* Relop  */
  YYSYMBOL_Additive_Expression = 63,       /* Additive_Expression  */
  YYSYMBOL_Addop = 64,                     /* Addop  */
  YYSYMBOL_Term = 65,                      /* Term  */
  YYSYMBOL_Multop = 66,                    /* Multop  */
  YYSYMBOL_Factor = 67,                    /* Factor  */
  YYSYMBOL_Call = 68,                      /* Call  */
  YYSYMBOL_Args = 69,                      /* Args  */
  YYSYMBOL_Args_List = 70                  /* Args_List  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


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
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      24,    25,    31,    29,    23,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
       2,    28,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   137,   137,   141,   142,   150,   151,   155,   194,   199,
     205,   211,   221,   222,   226,   243,   225,   262,   263,   267,
     268,   276,   293,   311,   311,   326,   327,   335,   336,   345,
     346,   347,   348,   349,   350,   351,   352,   356,   361,   369,
     381,   392,   401,   406,   414,   422,   428,   436,   455,   477,
     504,   507,   508,   531,   532,   533,   534,   535,   536,   540,
     541,   561,   562,   566,   567,   587,   588,   589,   593,   594,
     599,   600,   601,   618,   655,   660,   667,   676
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_NUM", "T_ID",
  "T_STRING", "T_INT", "T_VOID", "T_READ", "T_IF", "T_ELSE", "T_WHILE",
  "T_WRITE", "T_RETURN", "T_LT", "T_GT", "T_GE", "T_LE", "T_EQ", "T_NE",
  "';'", "'['", "']'", "','", "'('", "')'", "'{'", "'}'", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "$accept", "Program", "Declaration_List",
  "Declaration", "Var_Declaration", "Var_List", "Type_Specifier",
  "Fun_Declaration", "$@1", "$@2", "Params", "Param_List", "Param",
  "Compound_Stmt", "$@3", "Local_Declarations", "Statement_List",
  "Statement", "Expression_Stmt", "Selection_Stmt", "Iteration_Stmt",
  "Return_Stmt", "Read_Stmt", "Write_Stmt", "Assignment_Stmt", "Var",
  "Expression", "Simple_Expression", "Relop", "Additive_Expression",
  "Addop", "Term", "Multop", "Factor", "Call", "Args", "Args_List", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,  -114,  -114,    13,  -114,     2,  -114,    37,  -114,  -114,
    -114,    29,    12,    51,    64,    45,  -114,    48,    39,  -114,
      40,    57,    56,    78,    60,  -114,    63,    64,    62,  -114,
       2,  -114,    67,    65,  -114,  -114,  -114,  -114,     2,     2,
      64,     7,  -114,  -114,    19,    86,    68,    69,    18,    31,
    -114,    35,    35,  -114,    70,     7,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,    66,    75,  -114,    58,    25,  -114,  -114,
      35,    35,    77,    76,    35,    35,    79,  -114,    80,  -114,
      81,    82,  -114,  -114,  -114,    35,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,    35,    35,  -114,  -114,  -114,
      35,    83,    85,    84,  -114,  -114,    87,    88,  -114,  -114,
    -114,  -114,    90,    34,    25,  -114,  -114,    35,  -114,     7,
       7,  -114,  -114,    92,  -114,     7,  -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    13,     0,     2,     3,     5,     0,     6,     1,
       4,     8,     0,     0,     0,     0,     7,     0,     8,    10,
       0,     9,    13,     0,     0,    18,    19,     0,    21,    15,
       0,    11,     0,     0,    20,    22,    23,    16,    25,    25,
       0,    27,    26,    69,    48,     0,     0,     0,     0,     0,
      38,     0,     0,    30,     0,    27,    29,    31,    32,    34,
      35,    36,    33,    70,     0,    50,    51,    59,    63,    71,
       0,    75,    48,     0,     0,     0,     0,    70,     0,    42,
       0,     0,    72,    24,    28,     0,    37,    53,    54,    55,
      56,    57,    58,    61,    62,     0,     0,    65,    66,    67,
       0,     0,    76,     0,    74,    44,     0,     0,    45,    46,
      43,    68,     0,    52,    60,    64,    49,     0,    73,     0,
       0,    47,    77,    39,    41,     0,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,    98,  -114,    28,     3,     6,  -114,  -114,  -114,
    -114,    74,  -114,    73,  -114,    72,    59,  -113,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,   -41,   -46,    30,  -114,    21,
    -114,    22,  -114,   -51,  -114,  -114,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    12,     7,     8,    15,    33,
      24,    25,    26,    53,    38,    41,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    77,    64,    65,    95,    66,
      96,    67,   100,    68,    69,   103,   104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    82,    78,    80,    73,    81,   123,   124,     1,     2,
      43,    44,   126,     9,    63,    45,    46,    19,    47,    48,
      49,    43,    44,    76,   101,   102,    23,    50,   106,   107,
      31,    51,    16,    36,    43,    44,    23,    52,    43,    44,
      70,    11,    51,    71,    40,    40,     1,    22,    52,   115,
      13,    79,    14,   -14,    17,    51,    97,    98,    99,    51,
      13,    52,    14,    93,    94,    52,    39,    39,    18,    20,
      21,   102,    87,    88,    89,    90,    91,    92,    63,    63,
      27,   -17,    28,    32,    63,    29,    30,    93,    94,    35,
      72,    36,    74,    75,    85,    86,   105,    83,    70,   108,
     109,   110,   125,    10,    34,   116,    37,   111,   117,   118,
     121,    42,   119,   120,    84,   112,   113,   122,   114
};

static const yytype_int8 yycheck[] =
{
      41,    52,    48,    49,    45,    51,   119,   120,     6,     7,
       3,     4,   125,     0,    55,     8,     9,    14,    11,    12,
      13,     3,     4,     5,    70,    71,    20,    20,    74,    75,
      27,    24,    20,    26,     3,     4,    30,    30,     3,     4,
      21,     4,    24,    24,    38,    39,     6,     7,    30,   100,
      21,    20,    23,    24,     3,    24,    31,    32,    33,    24,
      21,    30,    23,    29,    30,    30,    38,    39,     4,    24,
      22,   117,    14,    15,    16,    17,    18,    19,   119,   120,
      23,    25,     4,    21,   125,    25,    23,    29,    30,    22,
       4,    26,    24,    24,    28,    20,    20,    27,    21,    20,
      20,    20,    10,     5,    30,    22,    33,    25,    23,    25,
      20,    39,    25,    25,    55,    85,    95,   117,    96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    35,    36,    37,    38,    40,    41,     0,
      36,     4,    39,    21,    23,    42,    20,     3,     4,    39,
      24,    22,     7,    40,    44,    45,    46,    23,     4,    25,
      23,    39,    21,    43,    45,    22,    26,    47,    48,    38,
      40,    49,    49,     3,     4,     8,     9,    11,    12,    13,
      20,    24,    30,    47,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    63,    65,    67,    68,
      21,    24,     4,    59,    24,    24,     5,    59,    60,    20,
      60,    60,    67,    27,    50,    28,    20,    14,    15,    16,
      17,    18,    19,    29,    30,    62,    64,    31,    32,    33,
      66,    60,    60,    69,    70,    20,    60,    60,    20,    20,
      20,    25,    61,    63,    65,    67,    22,    23,    25,    25,
      25,    20,    70,    51,    51,    10,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    39,    39,
      39,    39,    40,    40,    42,    43,    41,    44,    44,    45,
      45,    46,    46,    48,    47,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    55,    55,    56,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    68,    69,    69,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     0,     0,     8,     1,     1,     1,
       3,     2,     4,     0,     5,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     5,
       7,     5,     2,     3,     3,     3,     3,     4,     1,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     2,     4,     1,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: Declaration_List  */
#line 137 "lab9.y"
                            { PROGRAM = (yyvsp[0].node); /* pass up the declaration list */}
#line 1331 "y.tab.c"
    break;

  case 3: /* Declaration_List: Declaration  */
#line 141 "lab9.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1337 "y.tab.c"
    break;

  case 4: /* Declaration_List: Declaration Declaration_List  */
#line 143 "lab9.y"
                        { 
                            (yyval.node) = (yyvsp[-1].node);            // set the first declaration
                            (yyval.node) -> next = (yyvsp[0].node);    // link declaration list with the next declaration
                        }
#line 1346 "y.tab.c"
    break;

  case 5: /* Declaration: Var_Declaration  */
#line 150 "lab9.y"
                                { (yyval.node) = (yyvsp[0].node); /* pass up the var declaration */}
#line 1352 "y.tab.c"
    break;

  case 6: /* Declaration: Fun_Declaration  */
#line 151 "lab9.y"
                                { (yyval.node) = (yyvsp[0].node); /* pass up the fun declaration */}
#line 1358 "y.tab.c"
    break;

  case 7: /* Var_Declaration: Type_Specifier Var_List ';'  */
#line 156 "lab9.y"
                { /* we need to update all elements to the list to the type 
                     needs work */
                     /* Populate the s1 connected list with the 
                        defined type via $1 */
                    ASTnode *p = (yyvsp[-1].node);                                        
                    while( p != NULL)
                    {
                        p->my_data_type = (yyvsp[-2].d_type);                                               
                        // check each variable in the list to see if it has
                        // been defined at our level
                        if(Search(p->name, LEVEL, 0) != NULL)                               
                        {
                            // symbol already defined -- BARF
                            yyerror(p->name);                                             
                            yyerror("Symbol already defined");
                            exit(1);
                        }
                        // it was not in the table

                        if (p->value == 0)
                        {
                            // we have a scalar
                            p->symbol = Insert(p->name, p->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);             // insert the variable into the symbol table
                            OFFSET = OFFSET + 1;                                                                    // increment the offset by 1
                        }
                        else 
                        {
                            p->symbol = Insert(p->name, p->my_data_type, SYM_ARRAY, LEVEL, p->value, OFFSET);       // insert the array into the symbol table
                            OFFSET = OFFSET + p->value;                                                             // increment the offset by the size of the array
                        }               
                        p = p->s1;                                                                                  // move to the next variable in the list
                    }

                    (yyval.node) = (yyvsp[-1].node);                                                                                        // pass up the var list
                }
#line 1398 "y.tab.c"
    break;

  case 8: /* Var_List: T_ID  */
#line 195 "lab9.y"
            { 
                (yyval.node) = ASTCreateNode(A_VARDEC);   // create a new node
                (yyval.node)->name = (yyvsp[0].string);                  // set the name
            }
#line 1407 "y.tab.c"
    break;

  case 9: /* Var_List: T_ID '[' T_NUM ']'  */
#line 200 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_VARDEC);   // create a new node
                (yyval.node) -> name = (yyvsp[-3].string);                // set the name    
                (yyval.node) -> value = (yyvsp[-1].value);               // set the value
            }
#line 1417 "y.tab.c"
    break;

  case 10: /* Var_List: T_ID ',' Var_List  */
#line 206 "lab9.y"
            { 
                (yyval.node) = ASTCreateNode(A_VARDEC);   // create a new node
                (yyval.node) -> name = (yyvsp[-2].string);                // set the name
                (yyval.node)->s1 = (yyvsp[0].node);                    // link var list with the next var
            }
#line 1427 "y.tab.c"
    break;

  case 11: /* Var_List: T_ID '[' T_NUM ']' ',' Var_List  */
#line 212 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_VARDEC);   // create a new node
                (yyval.node) -> name = (yyvsp[-5].string);                // set the name
                (yyval.node) -> value = (yyvsp[-3].value);               // set the value
                (yyval.node) -> s1 = (yyvsp[0].node);                  // link var list with the next var
            }
#line 1438 "y.tab.c"
    break;

  case 12: /* Type_Specifier: T_INT  */
#line 221 "lab9.y"
                        { (yyval.d_type) = A_INTTYPE; }
#line 1444 "y.tab.c"
    break;

  case 13: /* Type_Specifier: T_VOID  */
#line 222 "lab9.y"
                        { (yyval.d_type) = A_VOIDTYPE; }
#line 1450 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 226 "lab9.y"
                    {
                        // check to see if function has been defined
                        if(Search((yyvsp[0].string), LEVEL, 0) != NULL)
                        {
                            // id has already been used -- BARF
                            yyerror((yyvsp[0].string));
                            yyerror("Function name already in use");
                            exit(1);
                        } else {
                        // not in symbol table -- install it
                            Insert((yyvsp[0].string), (yyvsp[-1].d_type), SYM_FUNCTION, LEVEL, 0,0);
                            GOFFSET = OFFSET;
                            OFFSET = 2;
                            maxOFFSET = OFFSET;
                        }
                    }
#line 1471 "y.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 243 "lab9.y"
                    {
                        Search((yyvsp[-4].string), LEVEL, 0) -> fparms = (yyvsp[-1].node);
                    }
#line 1479 "y.tab.c"
    break;

  case 16: /* Fun_Declaration: Type_Specifier T_ID $@1 '(' Params ')' $@2 Compound_Stmt  */
#line 248 "lab9.y"
                    {
                        (yyval.node) = ASTCreateNode(A_FUNCTIONDEC);      // create a new node
                        (yyval.node) -> name = (yyvsp[-6].string);                        // set the name
                        (yyval.node) -> my_data_type = (yyvsp[-7].d_type);                // set the type
                        (yyval.node) -> s1 = (yyvsp[-3].node);                          // set the params
                        (yyval.node) -> s2 = (yyvsp[0].node);                 
                        (yyval.node) -> symbol = Search((yyvsp[-6].string), LEVEL, 0);         
                    
                        Search((yyvsp[-6].string), LEVEL, 0) -> offset = maxOFFSET;         // Set the function's offset to max used in function
                        OFFSET = GOFFSET;                                   // resets the offset for global variable
                    }
#line 1495 "y.tab.c"
    break;

  case 17: /* Params: T_VOID  */
#line 262 "lab9.y"
                { (yyval.node) = NULL; }
#line 1501 "y.tab.c"
    break;

  case 18: /* Params: Param_List  */
#line 263 "lab9.y"
                     { (yyval.node) = (yyvsp[0].node); /* pass up the param list */ }
#line 1507 "y.tab.c"
    break;

  case 19: /* Param_List: Param  */
#line 267 "lab9.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1513 "y.tab.c"
    break;

  case 20: /* Param_List: Param ',' Param_List  */
#line 269 "lab9.y"
                    {
                        (yyval.node) = (yyvsp[-2].node);            // set the first param
                        (yyval.node) -> next = (yyvsp[0].node);    // link param list with the next param
                    }
#line 1522 "y.tab.c"
    break;

  case 21: /* Param: Type_Specifier T_ID  */
#line 277 "lab9.y"
            {
                if(Search((yyvsp[0].string), LEVEL + 1, 0) != NULL)                    // check if the parameter has already been used
                {
                    yyerror((yyvsp[0].string));                                        // print the error message
                    yyerror("Parameter already used");
                    exit(1);
                }

                (yyval.node) = ASTCreateNode(A_PARAM);    // create a new node
                (yyval.node) -> my_data_type = (yyvsp[-1].d_type);        // set the type
                (yyval.node) -> name = (yyvsp[0].string);                // set the name
                (yyval.node) -> value = 0;                // set the value to 0 for array distinction
                (yyval.node) -> symbol = Insert((yyval.node)->name, (yyval.node)->my_data_type, SYM_SCALAR, LEVEL+1, 1, OFFSET);   // insert the parameter into the symbol table  

                OFFSET = OFFSET + 1;
            }
#line 1543 "y.tab.c"
    break;

  case 22: /* Param: Type_Specifier T_ID '[' ']'  */
#line 294 "lab9.y"
            {
                if(Search((yyvsp[-2].string), LEVEL + 1, 0) != NULL)                // check if the parameter has already been used
                {
                    yyerror((yyvsp[-2].string));                                    // print the error message
                    yyerror("Parameter already used");
                    exit(1);
                }
                (yyval.node) = ASTCreateNode(A_PARAM);    // create a new node
                (yyval.node) -> my_data_type = (yyvsp[-3].d_type);        // set the type        
                (yyval.node) -> name = (yyvsp[-2].string);                // set the name
                (yyval.node) -> value = 1;                // set the value to 1 for array distinction
                (yyval.node) -> symbol = Insert((yyval.node)->name, (yyval.node)->my_data_type, SYM_ARRAY, LEVEL+1, 1, OFFSET);
                OFFSET = OFFSET + 1;
            }
#line 1562 "y.tab.c"
    break;

  case 23: /* $@3: %empty  */
#line 311 "lab9.y"
                    { LEVEL++; }
#line 1568 "y.tab.c"
    break;

  case 24: /* Compound_Stmt: '{' $@3 Local_Declarations Statement_List '}'  */
#line 313 "lab9.y"
                    { 
                        (yyval.node) = ASTCreateNode(A_COMPOUND);     // create a new node
                        (yyval.node) -> s1 = (yyvsp[-2].node);                      // set the local declarations
                        (yyval.node) -> s2 = (yyvsp[-1].node);                      // set the statement list      
                        if(mydebug) Display();
                        // set the maxOFFSET
                        if (OFFSET > maxOFFSET) maxOFFSET = OFFSET;
                        OFFSET -= Delete(LEVEL);
                        LEVEL--;                      
                    }
#line 1583 "y.tab.c"
    break;

  case 25: /* Local_Declarations: %empty  */
#line 326 "lab9.y"
                                 { (yyval.node) = NULL; }
#line 1589 "y.tab.c"
    break;

  case 26: /* Local_Declarations: Var_Declaration Local_Declarations  */
#line 328 "lab9.y"
                   {
                        (yyval.node) = (yyvsp[-1].node);            // set the first var declaration
                        (yyval.node) -> next = (yyvsp[0].node);   // link var declaration with the next var declaration
                   }
#line 1598 "y.tab.c"
    break;

  case 27: /* Statement_List: %empty  */
#line 335 "lab9.y"
                             { (yyval.node) = NULL; }
#line 1604 "y.tab.c"
    break;

  case 28: /* Statement_List: Statement Statement_List  */
#line 337 "lab9.y"
               {
                    (yyval.node) = (yyvsp[-1].node);            // set the first statement
                    (yyval.node) -> next = (yyvsp[0].node);    // link statement list with the next statement
               }
#line 1613 "y.tab.c"
    break;

  case 29: /* Statement: Expression_Stmt  */
#line 345 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1619 "y.tab.c"
    break;

  case 30: /* Statement: Compound_Stmt  */
#line 346 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1625 "y.tab.c"
    break;

  case 31: /* Statement: Selection_Stmt  */
#line 347 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1631 "y.tab.c"
    break;

  case 32: /* Statement: Iteration_Stmt  */
#line 348 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1637 "y.tab.c"
    break;

  case 33: /* Statement: Assignment_Stmt  */
#line 349 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1643 "y.tab.c"
    break;

  case 34: /* Statement: Return_Stmt  */
#line 350 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1649 "y.tab.c"
    break;

  case 35: /* Statement: Read_Stmt  */
#line 351 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1655 "y.tab.c"
    break;

  case 36: /* Statement: Write_Stmt  */
#line 352 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1661 "y.tab.c"
    break;

  case 37: /* Expression_Stmt: Expression ';'  */
#line 357 "lab9.y"
                    {
                        (yyval.node) = ASTCreateNode(A_EXPRSTMT);     // create a new node
                        (yyval.node) -> s1 = (yyvsp[-1].node);                      // set the expression
                    }
#line 1670 "y.tab.c"
    break;

  case 38: /* Expression_Stmt: ';'  */
#line 362 "lab9.y"
                    {
                        (yyval.node) = ASTCreateNode(A_EXPRSTMT);     // create a new node
                        (yyval.node) -> s1 = NULL;                    // set the expression to NULL for empty statement
                    }
#line 1679 "y.tab.c"
    break;

  case 39: /* Selection_Stmt: T_IF '(' Expression ')' Statement  */
#line 370 "lab9.y"
                {
                    // create two nodes, to have enough children for the if-else statement
                    // the first node will have the expression and the if statement
                    // s2 will point to the second node, which will have the else statement
                    // s2 will be null if there is no else statement
                    (yyval.node) = ASTCreateNode(A_IF);           
                    (yyval.node) -> s1 = (yyvsp[-2].node);                      
                    (yyval.node) -> s2 = ASTCreateNode(A_IF);     
                    (yyval.node) -> s2 -> s1 = (yyvsp[0].node);                
                    (yyval.node) -> s2 -> s2 = NULL;              
                }
#line 1695 "y.tab.c"
    break;

  case 40: /* Selection_Stmt: T_IF '(' Expression ')' Statement T_ELSE Statement  */
#line 382 "lab9.y"
                {
                    (yyval.node) = ASTCreateNode(A_IF);   
                    (yyval.node) -> s1 = (yyvsp[-4].node);                      
                    (yyval.node) -> s2 = ASTCreateNode(A_IF);     
                    (yyval.node) -> s2 -> s1 = (yyvsp[-2].node);                
                    (yyval.node) -> s2 -> s2 = (yyvsp[0].node);                
                }
#line 1707 "y.tab.c"
    break;

  case 41: /* Iteration_Stmt: T_WHILE '(' Expression ')' Statement  */
#line 393 "lab9.y"
                {
                    (yyval.node) = ASTCreateNode(A_WHILE);    // create a new node
                    (yyval.node) -> s1 = (yyvsp[-2].node);                  // set the expression
                    (yyval.node) -> s2 = (yyvsp[0].node);                  // set the statement
                }
#line 1717 "y.tab.c"
    break;

  case 42: /* Return_Stmt: T_RETURN ';'  */
#line 402 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_RETURN);       // create a new node
                (yyval.node) -> s1 = NULL;                    // set the expression to NULL for empty return
            }
#line 1726 "y.tab.c"
    break;

  case 43: /* Return_Stmt: T_RETURN Expression ';'  */
#line 407 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_RETURN);       // create a new node
                (yyval.node) -> s1 = (yyvsp[-1].node);                      // set the expression
            }
#line 1735 "y.tab.c"
    break;

  case 44: /* Read_Stmt: T_READ Var ';'  */
#line 415 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_READ);         // create a new node
                (yyval.node) -> s1 = (yyvsp[-1].node);                      // set the variable
            }
#line 1744 "y.tab.c"
    break;

  case 45: /* Write_Stmt: T_WRITE T_STRING ';'  */
#line 423 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_WRITE);        // create a new node
                (yyval.node) -> name = (yyvsp[-1].string);                    // set the string
                //$$ -> label = CreateLabel();        /* trying */
            }
#line 1754 "y.tab.c"
    break;

  case 46: /* Write_Stmt: T_WRITE Expression ';'  */
#line 429 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_WRITE);        // create a new node
                (yyval.node) -> s1 = (yyvsp[-1].node);                      // set the expression
            }
#line 1763 "y.tab.c"
    break;

  case 47: /* Assignment_Stmt: Var '=' Simple_Expression ';'  */
#line 437 "lab9.y"
                {
                    if ((yyvsp[-3].node) -> my_data_type != (yyvsp[-1].node) -> my_data_type)
                    {
                        yyerror("Type mismatch in assignment");
                        exit(1);
                    }
                    (yyval.node) = ASTCreateNode(A_ASSIGNMENT);       // create a new node    
                    (yyval.node) -> s1 = (yyvsp[-3].node);                          // set the variable
                    (yyval.node) -> s2 = (yyvsp[-1].node);                          // set the expression
                    (yyval.node) -> name = CreateTemp();
                    (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[-3].node) -> my_data_type, SYM_SCALAR,           
                    LEVEL, 1, OFFSET);                                                         

                    OFFSET = OFFSET + 1;
                }
#line 1783 "y.tab.c"
    break;

  case 48: /* Var: T_ID  */
#line 456 "lab9.y"
        {
            struct SymbTab *p;
            p = Search((yyvsp[0].string), LEVEL, 1);
            if(p == NULL)
            {
                // reference variable not in symbol table
                yyerror((yyvsp[0].string));
                yyerror("Symbol used but not defined");
                exit(1);
            }
            if(p->SubType != SYM_SCALAR)
            {
                // a reference to a non SCALAR variable
                yyerror((yyvsp[0].string));
                yyerror("Symbol must be a SCALAR");
            }                
            (yyval.node) = ASTCreateNode(A_VAR);      // create a new node
            (yyval.node) -> name = (yyvsp[0].string);                // set the name
            (yyval.node) -> symbol = p;
            (yyval.node) -> my_data_type = p -> Declared_Type;
        }
#line 1809 "y.tab.c"
    break;

  case 49: /* Var: T_ID '[' Expression ']'  */
#line 478 "lab9.y"
        { 
            struct SymbTab *p;
            p = Search((yyvsp[-3].string), LEVEL, 1);
            if(p == NULL)                                           // check if the variable is in the symbol table
            {
                yyerror((yyvsp[-3].string));
                yyerror("Symbol used but not defined");
                exit(1);
            }
            if(p->SubType != SYM_ARRAY)                             // check if the variable is an array
            {
                //A reference to a non scalar variable 
                yyerror((yyvsp[-3].string));
                yyerror("Symbol must be a ARRAY"); 
                exit(1);
            }  
            (yyval.node) = ASTCreateNode(A_VAR);      // create a new node
            (yyval.node) -> name = (yyvsp[-3].string);                // set the name
            (yyval.node) -> s1 = (yyvsp[-1].node);                  // set the expression
            (yyval.node) -> symbol = p;               // i think this is right
            (yyval.node) -> my_data_type = p -> Declared_Type;

        }
#line 1837 "y.tab.c"
    break;

  case 50: /* Expression: Simple_Expression  */
#line 504 "lab9.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1843 "y.tab.c"
    break;

  case 51: /* Simple_Expression: Additive_Expression  */
#line 507 "lab9.y"
                                        { (yyval.node) = (yyvsp[0].node); }
#line 1849 "y.tab.c"
    break;

  case 52: /* Simple_Expression: Additive_Expression Relop Additive_Expression  */
#line 509 "lab9.y"
                    {
                        if((yyvsp[-2].node) -> my_data_type != (yyvsp[0].node) -> my_data_type)    // check if the data types match
                        {
                            yyerror("type mismatch");                   // print the error message
                            exit(1);
                        }
                        (yyval.node) = ASTCreateNode(A_EXPR);     // create a new node
                        (yyval.node) -> s1 = (yyvsp[-2].node);                  // set the first additive expression
                        (yyval.node) -> s2 = (yyvsp[0].node);                  // set the second additive expression
                        (yyval.node) -> operator = (yyvsp[-1].operator);            // set the operator
                        (yyval.node) -> name = CreateTemp();
                        (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[-2].node) -> my_data_type, SYM_SCALAR, 
                        LEVEL, 1, OFFSET);

                        (yyval.node) -> my_data_type = (yyvsp[-2].node) -> my_data_type;        // set the data type

                        OFFSET = OFFSET + 1;
                    }
#line 1872 "y.tab.c"
    break;

  case 53: /* Relop: T_LT  */
#line 531 "lab9.y"
             { (yyval.operator) = A_LT; }
#line 1878 "y.tab.c"
    break;

  case 54: /* Relop: T_GT  */
#line 532 "lab9.y"
             { (yyval.operator) = A_GT; }
#line 1884 "y.tab.c"
    break;

  case 55: /* Relop: T_GE  */
#line 533 "lab9.y"
             { (yyval.operator) = A_GE; }
#line 1890 "y.tab.c"
    break;

  case 56: /* Relop: T_LE  */
#line 534 "lab9.y"
             { (yyval.operator) = A_LE; }
#line 1896 "y.tab.c"
    break;

  case 57: /* Relop: T_EQ  */
#line 535 "lab9.y"
             { (yyval.operator) = A_EQ; }
#line 1902 "y.tab.c"
    break;

  case 58: /* Relop: T_NE  */
#line 536 "lab9.y"
             { (yyval.operator) = A_NE; }
#line 1908 "y.tab.c"
    break;

  case 59: /* Additive_Expression: Term  */
#line 540 "lab9.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1914 "y.tab.c"
    break;

  case 60: /* Additive_Expression: Additive_Expression Addop Term  */
#line 542 "lab9.y"
                        {
                        if ((yyvsp[-2].node) -> my_data_type != (yyvsp[0].node) -> my_data_type)       // check if the data types match
                        {
                            yyerror("Type mismatch");                       // print the error message
                            exit(1);
                        }
                            (yyval.node) = ASTCreateNode(A_EXPR);     // create a new node
                            (yyval.node) -> s1 = (yyvsp[-2].node);                  // set the additive expression
                            (yyval.node) -> s2 = (yyvsp[0].node);                  // set the term
                            (yyval.node) -> operator = (yyvsp[-1].operator);            // set the operator
                            (yyval.node) -> name = CreateTemp();
                            (yyval.node) -> symbol = Insert((yyval.node)->name, (yyvsp[-2].node)->my_data_type, SYM_SCALAR, 
                            LEVEL, 1, OFFSET);

                            OFFSET = OFFSET + 1;
                        }
#line 1935 "y.tab.c"
    break;

  case 61: /* Addop: '+'  */
#line 561 "lab9.y"
            { (yyval.operator) = A_PLUS; }
#line 1941 "y.tab.c"
    break;

  case 62: /* Addop: '-'  */
#line 562 "lab9.y"
            { (yyval.operator) = A_MINUS; }
#line 1947 "y.tab.c"
    break;

  case 63: /* Term: Factor  */
#line 566 "lab9.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1953 "y.tab.c"
    break;

  case 64: /* Term: Term Multop Factor  */
#line 568 "lab9.y"
        {
            if((yyvsp[-2].node) -> my_data_type != (yyvsp[0].node) -> my_data_type)            // check if the data types match
            {
                yyerror("Type mismatch");
                exit(1);
            }
            (yyval.node) = ASTCreateNode(A_EXPR);     // create a new node
            (yyval.node) -> s1 = (yyvsp[-2].node);                  // set the term
            (yyval.node) -> s2 = (yyvsp[0].node);                  // set the factor
            (yyval.node) -> operator = (yyvsp[-1].operator);            // set the operator

            (yyval.node) -> name = CreateTemp();
            (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[-2].node) -> my_data_type, SYM_SCALAR, 
            LEVEL, 1, OFFSET);
            OFFSET = OFFSET + 1;
        }
#line 1974 "y.tab.c"
    break;

  case 65: /* Multop: '*'  */
#line 587 "lab9.y"
                { (yyval.operator) = A_MULT; }
#line 1980 "y.tab.c"
    break;

  case 66: /* Multop: '/'  */
#line 588 "lab9.y"
                { (yyval.operator) = A_DIV; }
#line 1986 "y.tab.c"
    break;

  case 67: /* Multop: '%'  */
#line 589 "lab9.y"
                { (yyval.operator) = A_MOD; }
#line 1992 "y.tab.c"
    break;

  case 68: /* Factor: '(' Expression ')'  */
#line 593 "lab9.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1998 "y.tab.c"
    break;

  case 69: /* Factor: T_NUM  */
#line 594 "lab9.y"
                            { 
                                (yyval.node) = ASTCreateNode(A_NUM);   // create a new node
                                (yyval.node) -> value = (yyvsp[0].value);            // set the value
                                (yyval.node) -> my_data_type = A_INTTYPE;
                            }
#line 2008 "y.tab.c"
    break;

  case 70: /* Factor: Var  */
#line 599 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2014 "y.tab.c"
    break;

  case 71: /* Factor: Call  */
#line 600 "lab9.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2020 "y.tab.c"
    break;

  case 72: /* Factor: '-' Factor  */
#line 602 "lab9.y"
                            {
                                if((yyvsp[0].node) -> my_data_type != A_INTTYPE)
                                {
                                    yyerror("Type mismatch unary minus");
                                    exit(1);
                                }
                                (yyval.node) = ASTCreateNode(A_EXPR);     // create a new node
                                (yyval.node) -> s1 = (yyvsp[0].node);                  // set the factor
                                (yyval.node) -> operator = A_UNARY;       // set the operator to unary for ASTprint
                                (yyval.node) -> name = CreateTemp();
                                (yyval.node) -> my_data_type = A_INTTYPE;
                                (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[0].node) -> my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
                                OFFSET = OFFSET + 1;
                            }
#line 2039 "y.tab.c"
    break;

  case 73: /* Call: T_ID '(' Args ')'  */
#line 619 "lab9.y"
    {
        struct SymbTab *p;
        p = Search((yyvsp[-3].string), 0, 0);

        if(p == NULL)                                   // check if the function name is known
        {
            //function name not known
            yyerror((yyvsp[-3].string));
            yyerror("Function name not defined");
            exit(1);
        } 
        // name is there but is it a function?
        if(p->SubType != SYM_FUNCTION)
        {
            yyerror((yyvsp[-3].string));
            yyerror("is not defined as a function");
            exit(1);
        }
        // check to see that the formal and actual parameters are same
        // length and type
        if(check_params((yyvsp[-1].node), p->fparms) == 0) 
        {
            yyerror((yyvsp[-3].string));
            yyerror("Actual and formals do not match");
            exit(1);
        }

        (yyval.node) = ASTCreateNode(A_CALL);     // create a new node
        (yyval.node) -> name = (yyvsp[-3].string);                // set the name
        (yyval.node) -> s1 = (yyvsp[-1].node);                  // set the arguments
        (yyval.node) -> symbol = p;
        (yyval.node) -> my_data_type = p -> Declared_Type;
    }
#line 2077 "y.tab.c"
    break;

  case 74: /* Args: Args_List  */
#line 656 "lab9.y"
        {
            (yyval.node) = (yyvsp[0].node);    // pass up the arguments list
        }
#line 2085 "y.tab.c"
    break;

  case 75: /* Args: %empty  */
#line 660 "lab9.y"
        {
            (yyval.node) = NULL;  // set the arguments to NULL for empty arguments
        }
#line 2093 "y.tab.c"
    break;

  case 76: /* Args_List: Expression  */
#line 668 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_ARG);      // create a new node
                (yyval.node) -> s1 =  (yyvsp[0].node);                 // set the expression
                (yyval.node) -> my_data_type = (yyvsp[0].node) -> my_data_type;            // set the data type
                (yyval.node) -> name = CreateTemp();                          
                (yyval.node) -> symbol = Insert((yyval.node)-> name, (yyvsp[0].node) -> my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
                OFFSET = OFFSET + 1;
            }
#line 2106 "y.tab.c"
    break;

  case 77: /* Args_List: Expression ',' Args_List  */
#line 677 "lab9.y"
            {
                (yyval.node) = ASTCreateNode(A_ARG);      // create a new node
                (yyval.node) -> s1 = (yyvsp[-2].node);                  // set the expression
                (yyval.node) -> next = (yyvsp[0].node);                // link the arguments list with the next argument
                (yyval.node) -> my_data_type = (yyvsp[-2].node) -> my_data_type;
                (yyval.node) -> name = CreateTemp();
                (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[-2].node) -> my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
                OFFSET = OFFSET + 1;
            }
#line 2120 "y.tab.c"
    break;


#line 2124 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 688 "lab9.y"


int main(int argc, char **argv) {
    FILE *fp;
    // read our input arguments
    int i;
    char s[100];
    // option -d turn on debug
    // option -o next argument is output file name
    for(i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-d") == 0) mydebug = 1;
        if (strcmp(argv[i], "-o") == 0)
        {
            // we have a file input
            strcpy(s, argv[i+1]);
            strcat(s, ".asm");
        }
    }

    // now open the file that is referenced by s
    fp = fopen(s, "w");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", s);
        exit(1);
    }

    yyparse();
    if(mydebug) printf("\n\n\nFinished Parsing\n\n\n");
    // we know that global variable PROGRAM has a PTR to the top of the tree
    if(mydebug) Display();              // shows our global variables and functions
    if(mydebug) printf("\n\nAST PRINT\n\n");
    if(mydebug) ASTprint(0,PROGRAM);
    EMIT(PROGRAM, fp);  
}

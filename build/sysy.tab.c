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
#line 9 "src/sysy.y"


#include <iostream>
#include <memory>
#include <string>
#include "AST.hpp"

// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

using namespace std;


#line 86 "build/sysy.tab.c"

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

#include "sysy.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_RETURN = 4,                     /* RETURN  */
  YYSYMBOL_AND = 5,                        /* AND  */
  YYSYMBOL_OR = 6,                         /* OR  */
  YYSYMBOL_EQ = 7,                         /* EQ  */
  YYSYMBOL_NE = 8,                         /* NE  */
  YYSYMBOL_LE = 9,                         /* LE  */
  YYSYMBOL_GE = 10,                        /* GE  */
  YYSYMBOL_CONST = 11,                     /* CONST  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_VOID = 17,                      /* VOID  */
  YYSYMBOL_IDENT = 18,                     /* IDENT  */
  YYSYMBOL_INT_CONST = 19,                 /* INT_CONST  */
  YYSYMBOL_20_ = 20,                       /* ';'  */
  YYSYMBOL_21_ = 21,                       /* ','  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_23_ = 23,                       /* '('  */
  YYSYMBOL_24_ = 24,                       /* ')'  */
  YYSYMBOL_25_ = 25,                       /* '{'  */
  YYSYMBOL_26_ = 26,                       /* '}'  */
  YYSYMBOL_27_ = 27,                       /* '+'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_29_ = 29,                       /* '!'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_CompUnit = 36,                  /* CompUnit  */
  YYSYMBOL_CompUnit2 = 37,                 /* CompUnit2  */
  YYSYMBOL_Decl = 38,                      /* Decl  */
  YYSYMBOL_ConstDecl = 39,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 40,              /* ConstDefList  */
  YYSYMBOL_BType = 41,                     /* BType  */
  YYSYMBOL_ConstDef = 42,                  /* ConstDef  */
  YYSYMBOL_ConstInitVal = 43,              /* ConstInitVal  */
  YYSYMBOL_VarDecl = 44,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 45,                /* VarDefList  */
  YYSYMBOL_VarDef = 46,                    /* VarDef  */
  YYSYMBOL_InitVal = 47,                   /* InitVal  */
  YYSYMBOL_FuncDef = 48,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 49,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 50,                /* FuncFParam  */
  YYSYMBOL_FuncType = 51,                  /* FuncType  */
  YYSYMBOL_Block = 52,                     /* Block  */
  YYSYMBOL_BlockItemList = 53,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 54,                 /* BlockItem  */
  YYSYMBOL_Stmt = 55,                      /* Stmt  */
  YYSYMBOL_open_statement = 56,            /* open_statement  */
  YYSYMBOL_closed_statement = 57,          /* closed_statement  */
  YYSYMBOL_Exp = 58,                       /* Exp  */
  YYSYMBOL_LVal = 59,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 60,                /* PrimaryExp  */
  YYSYMBOL_Number = 61,                    /* Number  */
  YYSYMBOL_UnaryExp = 62,                  /* UnaryExp  */
  YYSYMBOL_FuncRParams = 63,               /* FuncRParams  */
  YYSYMBOL_UnaryOp = 64,                   /* UnaryOp  */
  YYSYMBOL_MulExp = 65,                    /* MulExp  */
  YYSYMBOL_AddExp = 66,                    /* AddExp  */
  YYSYMBOL_RelExp = 67,                    /* RelExp  */
  YYSYMBOL_EqExp = 68,                     /* EqExp  */
  YYSYMBOL_LAndExp = 69,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 70,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 71                   /* ConstExp  */
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

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
       2,     2,     2,    29,     2,     2,     2,    32,     2,     2,
      23,    24,    30,    27,    21,    28,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
      33,    22,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
       0,    54,    54,    60,    69,    76,    86,    92,   101,   110,
     115,   127,   136,   146,   154,   163,   168,   179,   185,   195,
     204,   212,   224,   229,   240,   248,   253,   262,   267,   275,
     280,   292,   298,   307,   309,   313,   320,   328,   337,   345,
     352,   359,   365,   370,   376,   382,   387,   395,   403,   411,
     417,   423,   432,   436,   442,   449,   456,   465,   471,   480,
     483,   486,   492,   498,   506,   514,   525,   531,   539,   550,
     556,   564,   572,   580,   591,   597,   605,   616,   622,   633,
     639,   651
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "RETURN", "AND",
  "OR", "EQ", "NE", "LE", "GE", "CONST", "IF", "ELSE", "WHILE", "CONTINUE",
  "BREAK", "VOID", "IDENT", "INT_CONST", "';'", "','", "'='", "'('", "')'",
  "'{'", "'}'", "'+'", "'-'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'",
  "$accept", "CompUnit", "CompUnit2", "Decl", "ConstDecl", "ConstDefList",
  "BType", "ConstDef", "ConstInitVal", "VarDecl", "VarDefList", "VarDef",
  "InitVal", "FuncDef", "FuncFParams", "FuncFParam", "FuncType", "Block",
  "BlockItemList", "BlockItem", "Stmt", "open_statement",
  "closed_statement", "Exp", "LVal", "PrimaryExp", "Number", "UnaryExp",
  "FuncRParams", "UnaryOp", "MulExp", "AddExp", "RelExp", "EqExp",
  "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,  -117,  -117,    11,     9,     9,    15,  -117,  -117,  -117,
       4,     0,  -117,    10,    23,    26,    34,    33,  -117,  -117,
      10,    54,    65,    54,    52,    72,    66,    77,    76,  -117,
    -117,    65,  -117,  -117,  -117,  -117,  -117,  -117,    82,  -117,
    -117,    79,    62,  -117,  -117,  -117,    87,    80,  -117,  -117,
    -117,    65,     8,   -14,    -2,    56,   110,   105,  -117,  -117,
      96,  -117,   100,    65,    65,  -117,  -117,   106,   102,   109,
     107,   111,  -117,  -117,  -117,    65,  -117,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
    -117,   114,   108,   116,   115,   117,  -117,   119,   118,  -117,
      65,  -117,    82,   123,  -117,  -117,  -117,     8,     8,   -14,
     -14,   -14,   -14,    -2,    -2,    56,   110,    65,  -117,   100,
      94,    94,    65,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,   125,  -117,  -117,  -117,    94,  -117,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,    26,     0,     3,     2,     0,     1,     5,     4,
       0,     0,    11,     0,     0,     0,    22,     0,    20,    24,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    52,
      42,     0,    28,    59,    60,    61,    31,     6,     0,     7,
      43,     0,    29,    32,    33,    34,     0,    50,    53,    51,
      62,     0,    66,    69,    74,    77,    79,    47,    21,    23,
       0,    50,     0,     0,     0,    46,    45,     0,     0,    17,
       0,    15,    27,    30,    41,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     9,     0,     0,    56,    57,     0,    49,
       0,    14,     0,     0,    63,    64,    65,    67,    68,    72,
      73,    70,    71,    75,    76,    78,    80,     0,     8,     0,
       0,     0,     0,    55,    18,    19,    16,    40,    12,    81,
      13,    10,    35,    34,    37,    39,    58,     0,    36,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,  -117,  -117,  -117,    25,    -8,  -117,  -117,  -117,
      43,  -117,  -117,    63,   126,  -117,  -117,     3,   104,  -117,
      28,  -115,  -116,   -21,   -17,  -117,  -117,   -49,    27,  -117,
     -11,   -65,   -15,    64,    61,  -117,  -117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    36,    37,    92,    14,    93,   128,    39,
      70,    71,   124,     5,    15,    16,     6,    40,    41,    42,
      43,    44,    45,    46,    61,    48,    49,    50,    98,    51,
      52,    53,    54,    55,    56,    57,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    60,    76,    12,   133,   135,   134,    82,    83,    38,
      68,     7,     1,    80,    81,    62,    18,   109,   110,   111,
     112,   139,   138,    58,    13,    47,     2,    11,   104,   105,
     106,    84,    85,    10,    38,    17,    12,    22,    77,    78,
      79,    19,    94,    95,    23,    24,    97,    25,    26,    27,
      20,    28,    29,    30,   103,    21,    31,    12,    17,    32,
      33,    34,    35,    86,    87,    12,    22,     8,     9,   107,
     108,   113,   114,    23,    24,    63,    25,    26,    27,   125,
      28,    29,    30,    28,    29,    31,    65,    17,    31,    33,
      34,    35,    33,    34,    35,    64,   129,    66,    22,    67,
      69,    97,    75,    47,    47,    72,    24,    74,    25,    26,
      27,    89,    28,    29,    30,    88,    90,    31,    91,    17,
      47,    33,    34,    35,    28,    29,    99,   101,   118,    31,
      96,   100,   102,    33,    34,    35,   117,   119,   137,   120,
     122,   121,   123,   127,   131,   126,    73,    59,   132,   136,
     116,     0,   115
};

static const yytype_int16 yycheck[] =
{
      17,    22,    51,     3,   120,   121,   121,     9,    10,    17,
      31,     0,     3,    27,    28,    23,    13,    82,    83,    84,
      85,   137,   137,    20,    24,    42,    17,    23,    77,    78,
      79,    33,    34,    18,    42,    25,     3,     4,    30,    31,
      32,    18,    63,    64,    11,    12,    67,    14,    15,    16,
      24,    18,    19,    20,    75,    21,    23,     3,    25,    26,
      27,    28,    29,     7,     8,     3,     4,     4,     5,    80,
      81,    86,    87,    11,    12,    23,    14,    15,    16,   100,
      18,    19,    20,    18,    19,    23,    20,    25,    23,    27,
      28,    29,    27,    28,    29,    23,   117,    20,     4,    23,
      18,   122,    22,   120,   121,    26,    12,    20,    14,    15,
      16,     6,    18,    19,    20,     5,    20,    23,    18,    25,
     137,    27,    28,    29,    18,    19,    24,    20,    20,    23,
      24,    22,    21,    27,    28,    29,    22,    21,    13,    24,
      21,    24,    24,    20,   119,   102,    42,    21,   120,   122,
      89,    -1,    88
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    17,    36,    37,    48,    51,     0,    48,    48,
      18,    23,     3,    24,    41,    49,    50,    25,    52,    18,
      24,    21,     4,    11,    12,    14,    15,    16,    18,    19,
      20,    23,    26,    27,    28,    29,    38,    39,    41,    44,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    64,    65,    66,    67,    68,    69,    70,    52,    49,
      58,    59,    41,    23,    23,    20,    20,    23,    58,    18,
      45,    46,    26,    53,    20,    22,    62,    30,    31,    32,
      27,    28,     9,    10,    33,    34,     7,     8,     5,     6,
      20,    18,    40,    42,    58,    58,    24,    58,    63,    24,
      22,    20,    21,    58,    62,    62,    62,    65,    65,    66,
      66,    66,    66,    67,    67,    68,    69,    22,    20,    21,
      24,    24,    21,    24,    47,    58,    45,    20,    43,    58,
      71,    40,    55,    57,    56,    57,    63,    13,    56,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    38,    38,    39,    40,
      40,    41,    42,    43,    44,    45,    45,    46,    46,    47,
      48,    48,    49,    49,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    59,    60,
      60,    60,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    65,    65,    66,    66,    66,    67,
      67,    67,    67,    67,    68,    68,    68,    69,    69,    70,
      70,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     6,     1,     3,     2,     1,     1,     3,     2,     1,
       2,     1,     1,     1,     1,     5,     7,     5,     7,     5,
       4,     2,     1,     1,     3,     2,     2,     1,     1,     3,
       1,     1,     1,     1,     2,     4,     3,     1,     3,     1,
       1,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1
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
        yyerror (ast, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ast);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ast);
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
                 int yyrule, std::unique_ptr<BaseAST> &ast)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YY_USE (yyvaluep);
  YY_USE (ast);
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
yyparse (std::unique_ptr<BaseAST> &ast)
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
  case 2: /* CompUnit: FuncDef  */
#line 54 "src/sysy.y"
            {
    auto comp_unit = make_unique<CompUnitAST>();
    comp_unit->func_def = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    comp_unit->mode = 1;
    ast = move(comp_unit);
  }
#line 1247 "build/sysy.tab.c"
    break;

  case 3: /* CompUnit: CompUnit2  */
#line 60 "src/sysy.y"
              {
    auto comp_unit = make_unique<CompUnitAST>();
    comp_unit->comp_unit2 = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    comp_unit->mode = 2;
    ast = move(comp_unit);
  }
#line 1258 "build/sysy.tab.c"
    break;

  case 4: /* CompUnit2: FuncDef FuncDef  */
#line 69 "src/sysy.y"
                   {
    auto comp_unit2 = new CompUnit2AST();
    comp_unit2->func_def1 = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    comp_unit2->func_def2 = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    comp_unit2->mode = 1;
    (yyval.ast_val) = comp_unit2;
  }
#line 1270 "build/sysy.tab.c"
    break;

  case 5: /* CompUnit2: CompUnit2 FuncDef  */
#line 76 "src/sysy.y"
                      {
    auto comp_unit2 = new CompUnit2AST();
    comp_unit2->comp_unit2 = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    comp_unit2->func_def1 = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    comp_unit2->mode = 2;
    (yyval.ast_val) = comp_unit2;
  }
#line 1282 "build/sysy.tab.c"
    break;

  case 6: /* Decl: ConstDecl  */
#line 86 "src/sysy.y"
             {
    auto decl = new DeclAST();
    decl->const_decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    decl->mode = 1;
    (yyval.ast_val) = decl;
  }
#line 1293 "build/sysy.tab.c"
    break;

  case 7: /* Decl: VarDecl  */
#line 92 "src/sysy.y"
            {
    auto decl = new DeclAST();
    decl->var_decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    decl->mode = 2;
    (yyval.ast_val) = decl;
  }
#line 1304 "build/sysy.tab.c"
    break;

  case 8: /* ConstDecl: CONST BType ConstDefList ';'  */
#line 101 "src/sysy.y"
                                 {
    auto const_decl = new ConstDeclAST();
    const_decl->b_type = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    const_decl->const_defs = unique_ptr<vector<std::unique_ptr<BaseAST>>>((yyvsp[-1].ast_list_val));
    (yyval.ast_val) = const_decl;
  }
#line 1315 "build/sysy.tab.c"
    break;

  case 9: /* ConstDefList: ConstDef  */
#line 110 "src/sysy.y"
             {
    auto const_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    const_def_list->push_back(move(unique_ptr<BaseAST>((yyvsp[0].ast_val))));
    (yyval.ast_list_val) = const_def_list;
  }
#line 1325 "build/sysy.tab.c"
    break;

  case 10: /* ConstDefList: ConstDef ',' ConstDefList  */
#line 115 "src/sysy.y"
                              {
    auto const_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    const_def_list->push_back(move(unique_ptr<BaseAST>((yyvsp[-2].ast_val))));
    for (auto &const_def : *(yyvsp[0].ast_list_val)) {
      const_def_list->push_back(move(const_def));
    }
    (yyval.ast_list_val) = const_def_list;
  }
#line 1338 "build/sysy.tab.c"
    break;

  case 11: /* BType: INT  */
#line 127 "src/sysy.y"
        {
    auto b_type = new BTypeAST();
    b_type->btype = "int";
    (yyval.ast_val) = b_type;
  }
#line 1348 "build/sysy.tab.c"
    break;

  case 12: /* ConstDef: IDENT '=' ConstInitVal  */
#line 136 "src/sysy.y"
                           {
    auto const_def = new ConstDefAST();
    const_def->const_name = *unique_ptr<string>((yyvsp[-2].str_val));
    const_def->const_init_val = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = const_def;
  }
#line 1359 "build/sysy.tab.c"
    break;

  case 13: /* ConstInitVal: ConstExp  */
#line 146 "src/sysy.y"
             {
    auto const_init_val = new ConstInitValAST();
    const_init_val->const_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = const_init_val;
  }
#line 1369 "build/sysy.tab.c"
    break;

  case 14: /* VarDecl: BType VarDefList ';'  */
#line 154 "src/sysy.y"
                         {
    auto var_decl = new VarDeclAST();
    var_decl->b_type = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    var_decl->var_defs = unique_ptr<vector<std::unique_ptr<BaseAST>>>((yyvsp[-1].ast_list_val));
    (yyval.ast_val) = var_decl;
  }
#line 1380 "build/sysy.tab.c"
    break;

  case 15: /* VarDefList: VarDef  */
#line 163 "src/sysy.y"
           {
    auto var_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    var_def_list->push_back(move(unique_ptr<BaseAST>((yyvsp[0].ast_val))));
    (yyval.ast_list_val) = var_def_list;
  }
#line 1390 "build/sysy.tab.c"
    break;

  case 16: /* VarDefList: VarDef ',' VarDefList  */
#line 168 "src/sysy.y"
                          {
    auto var_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    var_def_list->push_back(move(unique_ptr<BaseAST>((yyvsp[-2].ast_val))));
    for (auto &var_def : *(yyvsp[0].ast_list_val)) {
      var_def_list->push_back(move(var_def));
    }
    (yyval.ast_list_val) = var_def_list;
  }
#line 1403 "build/sysy.tab.c"
    break;

  case 17: /* VarDef: IDENT  */
#line 179 "src/sysy.y"
          {
    auto var_def = new VarDefAST();
    var_def->var_name = *unique_ptr<string>((yyvsp[0].str_val));
    var_def->mode = 1;
    (yyval.ast_val) = var_def;
  }
#line 1414 "build/sysy.tab.c"
    break;

  case 18: /* VarDef: IDENT '=' InitVal  */
#line 185 "src/sysy.y"
                      {
    auto var_def = new VarDefAST();
    var_def->var_name = *unique_ptr<string>((yyvsp[-2].str_val));
    var_def->init_val = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    var_def->mode = 2;
    (yyval.ast_val) = var_def;
  }
#line 1426 "build/sysy.tab.c"
    break;

  case 19: /* InitVal: Exp  */
#line 195 "src/sysy.y"
        {
    auto init_val = new InitValAST();
    init_val->exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = init_val;
  }
#line 1436 "build/sysy.tab.c"
    break;

  case 20: /* FuncDef: FuncType IDENT '(' ')' Block  */
#line 204 "src/sysy.y"
                                 {
    auto func_def = new FuncDefAST();
    func_def->func_type = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
    func_def->func_name = *unique_ptr<string>((yyvsp[-3].str_val));
    func_def->func_block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    func_def->mode = 1;
    (yyval.ast_val) = func_def;
  }
#line 1449 "build/sysy.tab.c"
    break;

  case 21: /* FuncDef: FuncType IDENT '(' FuncFParams ')' Block  */
#line 212 "src/sysy.y"
                                             {
    auto func_def = new FuncDefAST();
    func_def->func_type = unique_ptr<BaseAST>((yyvsp[-5].ast_val));
    func_def->func_name = *unique_ptr<string>((yyvsp[-4].str_val));
    func_def->func_fparams = unique_ptr<BaseAST>((yyvsp[-2].func_fparams_val));
    func_def->func_block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    func_def->mode = 2;
    (yyval.ast_val) = func_def;
  }
#line 1463 "build/sysy.tab.c"
    break;

  case 22: /* FuncFParams: FuncFParam  */
#line 224 "src/sysy.y"
               {
    auto func_fparams = new FuncFParamsAST();
    func_fparams -> func_fparams.push_back(move(unique_ptr<BaseAST>((yyvsp[0].ast_val))));
    (yyval.func_fparams_val) = func_fparams;
  }
#line 1473 "build/sysy.tab.c"
    break;

  case 23: /* FuncFParams: FuncFParam ',' FuncFParams  */
#line 229 "src/sysy.y"
                               {
    auto func_fparams = new FuncFParamsAST();
    func_fparams -> func_fparams.push_back(move(unique_ptr<BaseAST>((yyvsp[-2].ast_val))));
    for (auto &func_fparam : ((yyvsp[0].func_fparams_val) -> func_fparams)) {
      func_fparams -> func_fparams.push_back(move(func_fparam));
    }
    (yyval.func_fparams_val) = func_fparams;
  }
#line 1486 "build/sysy.tab.c"
    break;

  case 24: /* FuncFParam: BType IDENT  */
#line 240 "src/sysy.y"
                {
    auto func_fparam = new FuncFParamAST();
    func_fparam -> btype = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    func_fparam -> param_name = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = func_fparam;
  }
#line 1497 "build/sysy.tab.c"
    break;

  case 25: /* FuncType: INT  */
#line 248 "src/sysy.y"
        {
    auto func_type = new FuncTypeAST();
    func_type -> type = "int";
    (yyval.ast_val) = func_type;
  }
#line 1507 "build/sysy.tab.c"
    break;

  case 26: /* FuncType: VOID  */
#line 253 "src/sysy.y"
         {
    auto func_type = new FuncTypeAST();
    func_type -> type = "void";
    (yyval.ast_val) = func_type;
  }
#line 1517 "build/sysy.tab.c"
    break;

  case 27: /* Block: '{' BlockItemList '}'  */
#line 262 "src/sysy.y"
                          {
    auto block = new BlockAST();
    block -> block_items = unique_ptr<vector<std::unique_ptr<BaseAST>>>((yyvsp[-1].ast_list_val));
    (yyval.ast_val) = block;
  }
#line 1527 "build/sysy.tab.c"
    break;

  case 28: /* Block: '{' '}'  */
#line 267 "src/sysy.y"
            {
    auto block = new BlockAST();
    block -> block_items = nullptr;
    (yyval.ast_val) = block;
  }
#line 1537 "build/sysy.tab.c"
    break;

  case 29: /* BlockItemList: BlockItem  */
#line 275 "src/sysy.y"
              {
    auto blockitem_list = new std::vector<std::unique_ptr<BaseAST>>();
    blockitem_list -> push_back(move(unique_ptr<BaseAST>((yyvsp[0].ast_val))));
    (yyval.ast_list_val) = blockitem_list;
  }
#line 1547 "build/sysy.tab.c"
    break;

  case 30: /* BlockItemList: BlockItem BlockItemList  */
#line 280 "src/sysy.y"
                            {
    auto blockitem_list = new std::vector<std::unique_ptr<BaseAST>>();
    blockitem_list -> push_back(move(unique_ptr<BaseAST>((yyvsp[-1].ast_val))));
    for (auto &blockitem : *(yyvsp[0].ast_list_val)) {
      blockitem_list -> push_back(move(blockitem));
    }
    (yyval.ast_list_val) = blockitem_list;
  }
#line 1560 "build/sysy.tab.c"
    break;

  case 31: /* BlockItem: Decl  */
#line 292 "src/sysy.y"
         {
    auto blockitem = new BlockItemAST();
    blockitem -> decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    blockitem -> mode = 1;
    (yyval.ast_val) = blockitem;
  }
#line 1571 "build/sysy.tab.c"
    break;

  case 32: /* BlockItem: Stmt  */
#line 298 "src/sysy.y"
         {
    auto blockitem = new BlockItemAST();
    blockitem -> stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    blockitem -> mode = 2;
    (yyval.ast_val) = blockitem;
  }
#line 1582 "build/sysy.tab.c"
    break;

  case 33: /* Stmt: open_statement  */
#line 307 "src/sysy.y"
                  { 
  }
#line 1589 "build/sysy.tab.c"
    break;

  case 34: /* Stmt: closed_statement  */
#line 309 "src/sysy.y"
                     {
  }
#line 1596 "build/sysy.tab.c"
    break;

  case 35: /* open_statement: IF '(' Exp ')' Stmt  */
#line 313 "src/sysy.y"
                       {
    auto stmt = new StmtAST();
    stmt->mode = 6;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val)); 
    stmt->if_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1608 "build/sysy.tab.c"
    break;

  case 36: /* open_statement: IF '(' Exp ')' closed_statement ELSE open_statement  */
#line 320 "src/sysy.y"
                                                       {
    auto stmt = new StmtAST();
    stmt->mode = 7;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-4].ast_val)); 
    stmt->if_stmt = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    stmt->else_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1621 "build/sysy.tab.c"
    break;

  case 37: /* open_statement: WHILE '(' Exp ')' open_statement  */
#line 328 "src/sysy.y"
                                     {
    auto stmt = new StmtAST();
    stmt->mode = 8;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    stmt->while_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1633 "build/sysy.tab.c"
    break;

  case 38: /* closed_statement: IF '(' Exp ')' closed_statement ELSE closed_statement  */
#line 337 "src/sysy.y"
                                                         {
    auto stmt = new StmtAST();
    stmt->mode = 7;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
    stmt->if_stmt = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    stmt->else_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt; 
  }
#line 1646 "build/sysy.tab.c"
    break;

  case 39: /* closed_statement: WHILE '(' Exp ')' closed_statement  */
#line 345 "src/sysy.y"
                                       {
    auto stmt = new StmtAST();
    stmt->mode = 8;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    stmt->while_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1658 "build/sysy.tab.c"
    break;

  case 40: /* closed_statement: LVal '=' Exp ';'  */
#line 352 "src/sysy.y"
                     {
    auto stmt = new StmtAST();
    stmt->mode = 2;
    stmt->lval = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1670 "build/sysy.tab.c"
    break;

  case 41: /* closed_statement: Exp ';'  */
#line 359 "src/sysy.y"
            {
    auto stmt = new StmtAST();
    stmt->mode = 3;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1681 "build/sysy.tab.c"
    break;

  case 42: /* closed_statement: ';'  */
#line 365 "src/sysy.y"
       {
    auto stmt = new StmtAST();
    stmt->mode = 4;
    (yyval.ast_val) = stmt;
  }
#line 1691 "build/sysy.tab.c"
    break;

  case 43: /* closed_statement: Block  */
#line 370 "src/sysy.y"
          {
    auto stmt = new StmtAST();
    stmt->mode = 5;
    stmt->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1702 "build/sysy.tab.c"
    break;

  case 44: /* closed_statement: RETURN Exp ';'  */
#line 376 "src/sysy.y"
                   {
    auto stmt = new StmtAST();
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    stmt->mode = 1;
    (yyval.ast_val) = stmt;
  }
#line 1713 "build/sysy.tab.c"
    break;

  case 45: /* closed_statement: BREAK ';'  */
#line 382 "src/sysy.y"
              {
    auto stmt = new StmtAST();
    stmt->mode = 9;
    (yyval.ast_val) = stmt;
  }
#line 1723 "build/sysy.tab.c"
    break;

  case 46: /* closed_statement: CONTINUE ';'  */
#line 387 "src/sysy.y"
                 {
    auto stmt = new StmtAST();
    stmt->mode = 10;
    (yyval.ast_val) = stmt;
  }
#line 1733 "build/sysy.tab.c"
    break;

  case 47: /* Exp: LOrExp  */
#line 395 "src/sysy.y"
           {
    auto exp = new ExpAST();
    exp -> lor_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = exp;
  }
#line 1743 "build/sysy.tab.c"
    break;

  case 48: /* LVal: IDENT  */
#line 403 "src/sysy.y"
          {
    auto lval = new LValAST();
    lval -> name = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = lval;
  }
#line 1753 "build/sysy.tab.c"
    break;

  case 49: /* PrimaryExp: '(' Exp ')'  */
#line 411 "src/sysy.y"
                {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    primary_exp -> mode = 1;
    (yyval.ast_val) = primary_exp;
  }
#line 1764 "build/sysy.tab.c"
    break;

  case 50: /* PrimaryExp: LVal  */
#line 417 "src/sysy.y"
         {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> lval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    primary_exp -> mode = 2;
    (yyval.ast_val) = primary_exp;
  }
#line 1775 "build/sysy.tab.c"
    break;

  case 51: /* PrimaryExp: Number  */
#line 423 "src/sysy.y"
           {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> number = (yyvsp[0].int_val);
    primary_exp -> mode = 3;
    (yyval.ast_val) = primary_exp;
  }
#line 1786 "build/sysy.tab.c"
    break;

  case 53: /* UnaryExp: PrimaryExp  */
#line 436 "src/sysy.y"
               {
    auto unary_exp = new UnaryExpAST();
    unary_exp -> primary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    unary_exp -> mode = 1;
    (yyval.ast_val) = unary_exp;
  }
#line 1797 "build/sysy.tab.c"
    break;

  case 54: /* UnaryExp: UnaryOp UnaryExp  */
#line 442 "src/sysy.y"
                    {
    auto unary_exp = new UnaryExpAST();
    unary_exp -> unary_op = *((yyvsp[-1].str_val));
    unary_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    unary_exp -> mode = 2;
    (yyval.ast_val) = unary_exp;
  }
#line 1809 "build/sysy.tab.c"
    break;

  case 55: /* UnaryExp: IDENT '(' FuncRParams ')'  */
#line 449 "src/sysy.y"
                              {
    auto unary_exp = new UnaryExpAST();
    unary_exp -> func_name = *unique_ptr<string>((yyvsp[-3].str_val));
    unary_exp -> func_rparams = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    unary_exp -> mode = 3;
    (yyval.ast_val) = unary_exp;
  }
#line 1821 "build/sysy.tab.c"
    break;

  case 56: /* UnaryExp: IDENT '(' ')'  */
#line 456 "src/sysy.y"
                  {
    auto unary_exp = new UnaryExpAST();
    unary_exp -> func_name = *unique_ptr<string>((yyvsp[-2].str_val));
    unary_exp -> mode = 4;
    (yyval.ast_val) = unary_exp;
  }
#line 1832 "build/sysy.tab.c"
    break;

  case 57: /* FuncRParams: Exp  */
#line 465 "src/sysy.y"
        {
    auto func_rparams = new FuncRParamsAST();
    func_rparams -> exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    func_rparams -> mode = 1;
    (yyval.ast_val) = func_rparams;
  }
#line 1843 "build/sysy.tab.c"
    break;

  case 58: /* FuncRParams: Exp ',' FuncRParams  */
#line 471 "src/sysy.y"
                        {
    auto func_rparams = new FuncRParamsAST();
    func_rparams -> exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    func_rparams -> func_rparams = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    func_rparams -> mode = 2;
    (yyval.ast_val) = func_rparams;
  }
#line 1855 "build/sysy.tab.c"
    break;

  case 59: /* UnaryOp: '+'  */
#line 480 "src/sysy.y"
        {
    (yyval.str_val) = new string("+");
  }
#line 1863 "build/sysy.tab.c"
    break;

  case 60: /* UnaryOp: '-'  */
#line 483 "src/sysy.y"
        {
    (yyval.str_val) = new string("-");
  }
#line 1871 "build/sysy.tab.c"
    break;

  case 61: /* UnaryOp: '!'  */
#line 486 "src/sysy.y"
        {
    (yyval.str_val) = new string("!");
  }
#line 1879 "build/sysy.tab.c"
    break;

  case 62: /* MulExp: UnaryExp  */
#line 492 "src/sysy.y"
             {
    auto mul_exp = new MulExpAST();
    mul_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    mul_exp -> mode = 1;
    (yyval.ast_val) = mul_exp;
  }
#line 1890 "build/sysy.tab.c"
    break;

  case 63: /* MulExp: MulExp '*' UnaryExp  */
#line 498 "src/sysy.y"
                        {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    mul_exp -> mode = 2;
    mul_exp -> op = "*";
    mul_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = mul_exp;
  }
#line 1903 "build/sysy.tab.c"
    break;

  case 64: /* MulExp: MulExp '/' UnaryExp  */
#line 506 "src/sysy.y"
                        {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    mul_exp -> mode = 2;
    mul_exp -> op = "/";
    mul_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = mul_exp;
  }
#line 1916 "build/sysy.tab.c"
    break;

  case 65: /* MulExp: MulExp '%' UnaryExp  */
#line 514 "src/sysy.y"
                        {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    mul_exp -> mode = 2;
    mul_exp -> op = "%";
    mul_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = mul_exp;
  }
#line 1929 "build/sysy.tab.c"
    break;

  case 66: /* AddExp: MulExp  */
#line 525 "src/sysy.y"
          {
    auto add_exp = new AddExpAST();
    add_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    add_exp -> mode = 1;
    (yyval.ast_val) = add_exp;
 }
#line 1940 "build/sysy.tab.c"
    break;

  case 67: /* AddExp: AddExp '+' MulExp  */
#line 531 "src/sysy.y"
                      {
    auto add_exp = new AddExpAST();
    add_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    add_exp -> mode = 2;
    add_exp -> op = "+";
    add_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = add_exp;
  }
#line 1953 "build/sysy.tab.c"
    break;

  case 68: /* AddExp: AddExp '-' MulExp  */
#line 539 "src/sysy.y"
                      {
    auto add_exp = new AddExpAST();
    add_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    add_exp -> mode = 2;
    add_exp -> op = "-";
    add_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = add_exp;
  }
#line 1966 "build/sysy.tab.c"
    break;

  case 69: /* RelExp: AddExp  */
#line 550 "src/sysy.y"
           {
    auto rel_exp = new RelExpAST();
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    rel_exp -> mode = 1;
    (yyval.ast_val) = rel_exp;
  }
#line 1977 "build/sysy.tab.c"
    break;

  case 70: /* RelExp: RelExp '<' AddExp  */
#line 556 "src/sysy.y"
                      {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    rel_exp -> mode = 2;
    rel_exp -> op = "<";
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
  }
#line 1990 "build/sysy.tab.c"
    break;

  case 71: /* RelExp: RelExp '>' AddExp  */
#line 564 "src/sysy.y"
                      {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    rel_exp -> mode = 2;
    rel_exp -> op = ">";
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
  }
#line 2003 "build/sysy.tab.c"
    break;

  case 72: /* RelExp: RelExp LE AddExp  */
#line 572 "src/sysy.y"
                     {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    rel_exp -> mode = 2;
    rel_exp -> op = "<=";
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
  }
#line 2016 "build/sysy.tab.c"
    break;

  case 73: /* RelExp: RelExp GE AddExp  */
#line 580 "src/sysy.y"
                     {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    rel_exp -> mode = 2;
    rel_exp -> op = ">=";
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
  }
#line 2029 "build/sysy.tab.c"
    break;

  case 74: /* EqExp: RelExp  */
#line 591 "src/sysy.y"
           {
    auto eq_exp = new EqExpAST();
    eq_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    eq_exp -> mode = 1;
    (yyval.ast_val) = eq_exp;
  }
#line 2040 "build/sysy.tab.c"
    break;

  case 75: /* EqExp: EqExp EQ RelExp  */
#line 597 "src/sysy.y"
                    {
    auto eq_exp = new EqExpAST();
    eq_exp -> eq_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    eq_exp -> mode = 2;
    eq_exp -> op = "==";
    eq_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = eq_exp;
  }
#line 2053 "build/sysy.tab.c"
    break;

  case 76: /* EqExp: EqExp NE RelExp  */
#line 605 "src/sysy.y"
                    {
    auto eq_exp = new EqExpAST();
    eq_exp -> eq_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    eq_exp -> mode = 2;
    eq_exp -> op = "!=";
    eq_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = eq_exp;
  }
#line 2066 "build/sysy.tab.c"
    break;

  case 77: /* LAndExp: EqExp  */
#line 616 "src/sysy.y"
          {
    auto land_exp = new LAndExpAST();
    land_exp -> eq_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    land_exp -> mode = 1;
    (yyval.ast_val) = land_exp;
  }
#line 2077 "build/sysy.tab.c"
    break;

  case 78: /* LAndExp: LAndExp AND EqExp  */
#line 622 "src/sysy.y"
                      {
    auto land_exp = new LAndExpAST();
    land_exp -> land_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    land_exp -> mode = 2;
    land_exp -> op = "&&";
    land_exp -> eq_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = land_exp;
  }
#line 2090 "build/sysy.tab.c"
    break;

  case 79: /* LOrExp: LAndExp  */
#line 633 "src/sysy.y"
            {
    auto lor_exp = new LOrExpAST();
    lor_exp -> land_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    lor_exp -> mode = 1;
    (yyval.ast_val) = lor_exp;
  }
#line 2101 "build/sysy.tab.c"
    break;

  case 80: /* LOrExp: LOrExp OR LAndExp  */
#line 639 "src/sysy.y"
                      {
    auto lor_exp = new LOrExpAST();
    lor_exp -> lor_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    lor_exp -> mode = 2;
    lor_exp -> op = "||";
    lor_exp -> land_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = lor_exp;
  }
#line 2114 "build/sysy.tab.c"
    break;

  case 81: /* ConstExp: Exp  */
#line 651 "src/sysy.y"
        {
    auto const_exp = new ConstExpAST();
    const_exp -> exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = const_exp;
  }
#line 2124 "build/sysy.tab.c"
    break;


#line 2128 "build/sysy.tab.c"

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
      yyerror (ast, YY_("syntax error"));
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
                      yytoken, &yylval, ast);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ast);
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
  yyerror (ast, YY_("memory exhausted"));
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
                  yytoken, &yylval, ast);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ast);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 657 "src/sysy.y"


// 定义错误处理函数, 其中第二个参数是错误信息, parser 如果发生错误 (例如输入的程序出现了语法错误), 就会调用这个函数
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  extern char* yytext;  // 声明 yytext
  extern int yylineno;  // 声明 yylineno
  cerr << "error: " << s << endl;
   cerr << "near " << yytext << endl;
   cerr << "line " << yylineno << endl;
}

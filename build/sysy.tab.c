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
  YYSYMBOL_IDENT = 14,                     /* IDENT  */
  YYSYMBOL_INT_CONST = 15,                 /* INT_CONST  */
  YYSYMBOL_16_ = 16,                       /* ';'  */
  YYSYMBOL_17_ = 17,                       /* ','  */
  YYSYMBOL_18_ = 18,                       /* '='  */
  YYSYMBOL_19_ = 19,                       /* '('  */
  YYSYMBOL_20_ = 20,                       /* ')'  */
  YYSYMBOL_21_ = 21,                       /* '{'  */
  YYSYMBOL_22_ = 22,                       /* '}'  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '!'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_CompUnit = 32,                  /* CompUnit  */
  YYSYMBOL_Decl = 33,                      /* Decl  */
  YYSYMBOL_ConstDecl = 34,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 35,              /* ConstDefList  */
  YYSYMBOL_BType = 36,                     /* BType  */
  YYSYMBOL_ConstDef = 37,                  /* ConstDef  */
  YYSYMBOL_ConstInitVal = 38,              /* ConstInitVal  */
  YYSYMBOL_VarDecl = 39,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 40,                /* VarDefList  */
  YYSYMBOL_VarDef = 41,                    /* VarDef  */
  YYSYMBOL_InitVal = 42,                   /* InitVal  */
  YYSYMBOL_FuncDef = 43,                   /* FuncDef  */
  YYSYMBOL_FuncType = 44,                  /* FuncType  */
  YYSYMBOL_Block = 45,                     /* Block  */
  YYSYMBOL_BlockItemList = 46,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 47,                 /* BlockItem  */
  YYSYMBOL_Stmt = 48,                      /* Stmt  */
  YYSYMBOL_open_statement = 49,            /* open_statement  */
  YYSYMBOL_closed_statement = 50,          /* closed_statement  */
  YYSYMBOL_Exp = 51,                       /* Exp  */
  YYSYMBOL_LVal = 52,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 53,                /* PrimaryExp  */
  YYSYMBOL_Number = 54,                    /* Number  */
  YYSYMBOL_UnaryExp = 55,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 56,                   /* UnaryOp  */
  YYSYMBOL_MulExp = 57,                    /* MulExp  */
  YYSYMBOL_AddExp = 58,                    /* AddExp  */
  YYSYMBOL_RelExp = 59,                    /* RelExp  */
  YYSYMBOL_EqExp = 60,                     /* EqExp  */
  YYSYMBOL_LAndExp = 61,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 62,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 63                   /* ConstExp  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270


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
       2,     2,     2,    25,     2,     2,     2,    28,     2,     2,
      19,    20,    26,    23,    17,    24,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    16,
      29,    18,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    61,    67,    76,    86,    91,   103,   112,
     122,   130,   139,   144,   155,   161,   171,   180,   190,   199,
     207,   212,   224,   230,   239,   241,   245,   252,   262,   270,
     277,   283,   288,   294,   303,   311,   319,   325,   331,   340,
     344,   350,   360,   363,   366,   372,   378,   386,   394,   405,
     411,   419,   430,   436,   444,   452,   460,   471,   477,   485,
     496,   502,   513,   519,   531
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
  "OR", "EQ", "NE", "LE", "GE", "CONST", "IF", "ELSE", "IDENT",
  "INT_CONST", "';'", "','", "'='", "'('", "')'", "'{'", "'}'", "'+'",
  "'-'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "$accept", "CompUnit",
  "Decl", "ConstDecl", "ConstDefList", "BType", "ConstDef", "ConstInitVal",
  "VarDecl", "VarDefList", "VarDef", "InitVal", "FuncDef", "FuncType",
  "Block", "BlockItemList", "BlockItem", "Stmt", "open_statement",
  "closed_statement", "Exp", "LVal", "PrimaryExp", "Number", "UnaryExp",
  "UnaryOp", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp",
  "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,   -91,    12,   -91,     2,   -91,    18,    11,     0,    -1,
     -91,   -91,    43,    36,    24,   -91,   -91,   -91,    43,   -91,
     -91,   -91,   -91,   -91,    32,   -91,   -91,    39,    -1,   -91,
     -91,   -91,    47,    30,   -91,   -91,   -91,    43,    28,   -15,
      23,    21,    59,    67,    58,   -91,    61,    43,    56,    60,
      63,    64,   -91,   -91,   -91,    43,   -91,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
     -91,    62,    68,    66,    57,   -91,    43,   -91,    32,    69,
     -91,   -91,   -91,    28,    28,   -15,   -15,   -15,   -15,    23,
      23,    21,    59,    43,   -91,    61,    26,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,    73,    26,   -91,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,     0,     2,     0,     1,     0,     0,     0,     0,
      17,     8,     0,     0,     0,    35,    39,    31,     0,    42,
      43,    44,    22,     3,     0,     4,    32,     0,    20,    23,
      24,    25,     0,    37,    40,    38,    45,     0,    49,    52,
      57,    60,    62,    34,     0,    37,     0,     0,     0,    14,
       0,    12,    19,    21,    30,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     6,     0,    36,     0,    11,     0,     0,
      46,    47,    48,    50,    51,    55,    56,    53,    54,    58,
      59,    61,    63,     0,     5,     0,     0,    15,    16,    13,
      29,     9,    64,    10,     7,    26,    25,     0,    27,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,   -91,    -6,    75,   -91,   -91,   -91,    13,
     -91,   -91,   -91,   -91,    82,    65,   -91,    -4,   -13,   -90,
     -11,    -9,   -91,   -91,   -32,   -91,   -26,     7,    -7,    27,
      31,   -91,   -91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    22,    23,    72,    24,    73,   101,    25,    50,
      51,    97,     3,     4,    26,    27,    28,    29,    30,    31,
      32,    45,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      33,    44,    11,    12,     1,    56,   106,    48,    60,    61,
      13,    14,     5,    15,    16,    17,     6,   109,    18,    33,
       9,     9,    19,    20,    21,    80,    81,    82,    66,    67,
      12,     8,    62,    63,    83,    84,    74,     7,    14,    11,
      15,    16,    17,    47,    79,    18,    49,     9,    55,    19,
      20,    21,    64,    65,    57,    58,    59,    15,    16,    89,
      90,    52,    18,    54,    68,    98,    19,    20,    21,    85,
      86,    87,    88,    69,    70,    71,    75,    96,    76,    77,
      93,    78,   102,    95,    94,   100,   107,    33,    46,   104,
      10,    99,   105,    53,   108,    91,     0,     0,    33,     0,
      92
};

static const yytype_int8 yycheck[] =
{
       9,    12,     3,     4,     3,    37,    96,    18,    23,    24,
      11,    12,     0,    14,    15,    16,    14,   107,    19,    28,
      21,    21,    23,    24,    25,    57,    58,    59,     7,     8,
       4,    20,     9,    10,    60,    61,    47,    19,    12,     3,
      14,    15,    16,    19,    55,    19,    14,    21,    18,    23,
      24,    25,    29,    30,    26,    27,    28,    14,    15,    66,
      67,    22,    19,    16,     5,    76,    23,    24,    25,    62,
      63,    64,    65,     6,    16,    14,    20,    20,    18,    16,
      18,    17,    93,    17,    16,    16,    13,    96,    13,    95,
       8,    78,    96,    28,   107,    68,    -1,    -1,   107,    -1,
      69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    32,    43,    44,     0,    14,    19,    20,    21,
      45,     3,     4,    11,    12,    14,    15,    16,    19,    23,
      24,    25,    33,    34,    36,    39,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    51,    52,    36,    19,    51,    14,
      40,    41,    22,    46,    16,    18,    55,    26,    27,    28,
      23,    24,     9,    10,    29,    30,     7,     8,     5,     6,
      16,    14,    35,    37,    51,    20,    18,    16,    17,    51,
      55,    55,    55,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    61,    18,    16,    17,    20,    42,    51,    40,
      16,    38,    51,    63,    35,    48,    50,    13,    49,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    35,    35,    36,    37,
      38,    39,    40,    40,    41,    41,    42,    43,    44,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    51,    52,    53,    53,    53,    54,
      55,    55,    56,    56,    56,    57,    57,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    62,    62,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     2,     1,     1,     1,     1,     5,     7,     7,     4,
       2,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1
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
#line 53 "src/sysy.y"
            {
    auto comp_unit = make_unique<CompUnitAST>();
    comp_unit->func_def = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast = move(comp_unit);
  }
#line 1212 "build/sysy.tab.c"
    break;

  case 3: /* Decl: ConstDecl  */
#line 61 "src/sysy.y"
             {
    auto decl = new DeclAST();
    decl->const_decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    decl->mode = 1;
    (yyval.ast_val) = decl;
  }
#line 1223 "build/sysy.tab.c"
    break;

  case 4: /* Decl: VarDecl  */
#line 67 "src/sysy.y"
            {
    auto decl = new DeclAST();
    decl->var_decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    decl->mode = 2;
    (yyval.ast_val) = decl;
  }
#line 1234 "build/sysy.tab.c"
    break;

  case 5: /* ConstDecl: CONST BType ConstDefList ';'  */
#line 76 "src/sysy.y"
                                 {
    auto const_decl = new ConstDeclAST();
    const_decl->b_type = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    const_decl->const_defs = unique_ptr<vector<std::unique_ptr<BaseAST>>>((yyvsp[-1].ast_list_val));
    (yyval.ast_val) = const_decl;
  }
#line 1245 "build/sysy.tab.c"
    break;

  case 6: /* ConstDefList: ConstDef  */
#line 86 "src/sysy.y"
             {
    auto const_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    const_def_list->push_back(move(unique_ptr<BaseAST>((yyvsp[0].ast_val))));
    (yyval.ast_list_val) = const_def_list;
  }
#line 1255 "build/sysy.tab.c"
    break;

  case 7: /* ConstDefList: ConstDef ',' ConstDefList  */
#line 91 "src/sysy.y"
                              {
    auto const_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    const_def_list->push_back(move(unique_ptr<BaseAST>((yyvsp[-2].ast_val))));
    for (auto &const_def : *(yyvsp[0].ast_list_val)) {
      const_def_list->push_back(move(const_def));
    }
    (yyval.ast_list_val) = const_def_list;
  }
#line 1268 "build/sysy.tab.c"
    break;

  case 8: /* BType: INT  */
#line 103 "src/sysy.y"
        {
    auto b_type = new BTypeAST();
    b_type->btype = "int";
    (yyval.ast_val) = b_type;
  }
#line 1278 "build/sysy.tab.c"
    break;

  case 9: /* ConstDef: IDENT '=' ConstInitVal  */
#line 112 "src/sysy.y"
                           {
    auto const_def = new ConstDefAST();
    const_def->const_name = *unique_ptr<string>((yyvsp[-2].str_val));
    const_def->const_init_val = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = const_def;
  }
#line 1289 "build/sysy.tab.c"
    break;

  case 10: /* ConstInitVal: ConstExp  */
#line 122 "src/sysy.y"
             {
    auto const_init_val = new ConstInitValAST();
    const_init_val->const_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = const_init_val;
  }
#line 1299 "build/sysy.tab.c"
    break;

  case 11: /* VarDecl: BType VarDefList ';'  */
#line 130 "src/sysy.y"
                         {
    auto var_decl = new VarDeclAST();
    var_decl->b_type = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    var_decl->var_defs = unique_ptr<vector<std::unique_ptr<BaseAST>>>((yyvsp[-1].ast_list_val));
    (yyval.ast_val) = var_decl;
  }
#line 1310 "build/sysy.tab.c"
    break;

  case 12: /* VarDefList: VarDef  */
#line 139 "src/sysy.y"
           {
    auto var_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    var_def_list->push_back(move(unique_ptr<BaseAST>((yyvsp[0].ast_val))));
    (yyval.ast_list_val) = var_def_list;
  }
#line 1320 "build/sysy.tab.c"
    break;

  case 13: /* VarDefList: VarDef ',' VarDefList  */
#line 144 "src/sysy.y"
                          {
    auto var_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    var_def_list->push_back(move(unique_ptr<BaseAST>((yyvsp[-2].ast_val))));
    for (auto &var_def : *(yyvsp[0].ast_list_val)) {
      var_def_list->push_back(move(var_def));
    }
    (yyval.ast_list_val) = var_def_list;
  }
#line 1333 "build/sysy.tab.c"
    break;

  case 14: /* VarDef: IDENT  */
#line 155 "src/sysy.y"
          {
    auto var_def = new VarDefAST();
    var_def->var_name = *unique_ptr<string>((yyvsp[0].str_val));
    var_def->mode = 1;
    (yyval.ast_val) = var_def;
  }
#line 1344 "build/sysy.tab.c"
    break;

  case 15: /* VarDef: IDENT '=' InitVal  */
#line 161 "src/sysy.y"
                      {
    auto var_def = new VarDefAST();
    var_def->var_name = *unique_ptr<string>((yyvsp[-2].str_val));
    var_def->init_val = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    var_def->mode = 2;
    (yyval.ast_val) = var_def;
  }
#line 1356 "build/sysy.tab.c"
    break;

  case 16: /* InitVal: Exp  */
#line 171 "src/sysy.y"
        {
    auto init_val = new InitValAST();
    init_val->exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = init_val;
  }
#line 1366 "build/sysy.tab.c"
    break;

  case 17: /* FuncDef: FuncType IDENT '(' ')' Block  */
#line 180 "src/sysy.y"
                                 {
    auto func_def = new FuncDefAST();
    func_def->func_type = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
    func_def->func_name = *unique_ptr<string>((yyvsp[-3].str_val));
    func_def->func_block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
  }
#line 1378 "build/sysy.tab.c"
    break;

  case 18: /* FuncType: INT  */
#line 190 "src/sysy.y"
        {
    auto func_type = new FuncTypeAST();
    func_type -> type = "int";
    (yyval.ast_val) = func_type;
  }
#line 1388 "build/sysy.tab.c"
    break;

  case 19: /* Block: '{' BlockItemList '}'  */
#line 199 "src/sysy.y"
                          {
    auto block = new BlockAST();
    block -> block_items = unique_ptr<vector<std::unique_ptr<BaseAST>>>((yyvsp[-1].ast_list_val));
    (yyval.ast_val) = block;
  }
#line 1398 "build/sysy.tab.c"
    break;

  case 20: /* BlockItemList: BlockItem  */
#line 207 "src/sysy.y"
              {
    auto blockitem_list = new std::vector<std::unique_ptr<BaseAST>>();
    blockitem_list -> push_back(move(unique_ptr<BaseAST>((yyvsp[0].ast_val))));
    (yyval.ast_list_val) = blockitem_list;
  }
#line 1408 "build/sysy.tab.c"
    break;

  case 21: /* BlockItemList: BlockItem BlockItemList  */
#line 212 "src/sysy.y"
                            {
    auto blockitem_list = new std::vector<std::unique_ptr<BaseAST>>();
    blockitem_list -> push_back(move(unique_ptr<BaseAST>((yyvsp[-1].ast_val))));
    for (auto &blockitem : *(yyvsp[0].ast_list_val)) {
      blockitem_list -> push_back(move(blockitem));
    }
    (yyval.ast_list_val) = blockitem_list;
  }
#line 1421 "build/sysy.tab.c"
    break;

  case 22: /* BlockItem: Decl  */
#line 224 "src/sysy.y"
         {
    auto blockitem = new BlockItemAST();
    blockitem -> decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    blockitem -> mode = 1;
    (yyval.ast_val) = blockitem;
  }
#line 1432 "build/sysy.tab.c"
    break;

  case 23: /* BlockItem: Stmt  */
#line 230 "src/sysy.y"
         {
    auto blockitem = new BlockItemAST();
    blockitem -> stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    blockitem -> mode = 2;
    (yyval.ast_val) = blockitem;
  }
#line 1443 "build/sysy.tab.c"
    break;

  case 24: /* Stmt: open_statement  */
#line 239 "src/sysy.y"
                  { 
  }
#line 1450 "build/sysy.tab.c"
    break;

  case 25: /* Stmt: closed_statement  */
#line 241 "src/sysy.y"
                     {
  }
#line 1457 "build/sysy.tab.c"
    break;

  case 26: /* open_statement: IF '(' Exp ')' Stmt  */
#line 245 "src/sysy.y"
                       {
    auto stmt = new StmtAST();
    stmt->mode = 6;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val)); 
    stmt->if_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1469 "build/sysy.tab.c"
    break;

  case 27: /* open_statement: IF '(' Exp ')' closed_statement ELSE open_statement  */
#line 252 "src/sysy.y"
                                                       {
    auto stmt = new StmtAST();
    stmt->mode = 7;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-4].ast_val)); 
    stmt->if_stmt = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    stmt->else_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1482 "build/sysy.tab.c"
    break;

  case 28: /* closed_statement: IF '(' Exp ')' closed_statement ELSE closed_statement  */
#line 262 "src/sysy.y"
                                                         {
    auto stmt = new StmtAST();
    stmt->mode = 7;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
    stmt->if_stmt = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    stmt->else_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt; 
  }
#line 1495 "build/sysy.tab.c"
    break;

  case 29: /* closed_statement: LVal '=' Exp ';'  */
#line 270 "src/sysy.y"
                     {
    auto stmt = new StmtAST();
    stmt->mode = 2;
    stmt->lval = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1507 "build/sysy.tab.c"
    break;

  case 30: /* closed_statement: Exp ';'  */
#line 277 "src/sysy.y"
            {
    auto stmt = new StmtAST();
    stmt->mode = 3;
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1518 "build/sysy.tab.c"
    break;

  case 31: /* closed_statement: ';'  */
#line 283 "src/sysy.y"
       {
    auto stmt = new StmtAST();
    stmt->mode = 4;
    (yyval.ast_val) = stmt;
  }
#line 1528 "build/sysy.tab.c"
    break;

  case 32: /* closed_statement: Block  */
#line 288 "src/sysy.y"
          {
    auto stmt = new StmtAST();
    stmt->mode = 5;
    stmt->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
  }
#line 1539 "build/sysy.tab.c"
    break;

  case 33: /* closed_statement: RETURN Exp ';'  */
#line 294 "src/sysy.y"
                   {
    auto stmt = new StmtAST();
    stmt->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    stmt->mode = 1;
    (yyval.ast_val) = stmt;
  }
#line 1550 "build/sysy.tab.c"
    break;

  case 34: /* Exp: LOrExp  */
#line 303 "src/sysy.y"
           {
    auto exp = new ExpAST();
    exp -> lor_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = exp;
  }
#line 1560 "build/sysy.tab.c"
    break;

  case 35: /* LVal: IDENT  */
#line 311 "src/sysy.y"
          {
    auto lval = new LValAST();
    lval -> name = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = lval;
  }
#line 1570 "build/sysy.tab.c"
    break;

  case 36: /* PrimaryExp: '(' Exp ')'  */
#line 319 "src/sysy.y"
                {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    primary_exp -> mode = 1;
    (yyval.ast_val) = primary_exp;
  }
#line 1581 "build/sysy.tab.c"
    break;

  case 37: /* PrimaryExp: LVal  */
#line 325 "src/sysy.y"
         {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> lval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    primary_exp -> mode = 2;
    (yyval.ast_val) = primary_exp;
  }
#line 1592 "build/sysy.tab.c"
    break;

  case 38: /* PrimaryExp: Number  */
#line 331 "src/sysy.y"
           {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> number = (yyvsp[0].int_val);
    primary_exp -> mode = 3;
    (yyval.ast_val) = primary_exp;
  }
#line 1603 "build/sysy.tab.c"
    break;

  case 40: /* UnaryExp: PrimaryExp  */
#line 344 "src/sysy.y"
               {
    auto unary_exp = new UnaryExpAST();
    unary_exp -> primary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    unary_exp -> mode = 1;
    (yyval.ast_val) = unary_exp;
  }
#line 1614 "build/sysy.tab.c"
    break;

  case 41: /* UnaryExp: UnaryOp UnaryExp  */
#line 350 "src/sysy.y"
                    {
    auto unary_exp = new UnaryExpAST();
    unary_exp -> unary_op = *((yyvsp[-1].str_val));
    unary_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    unary_exp -> mode = 2;
    (yyval.ast_val) = unary_exp;
  }
#line 1626 "build/sysy.tab.c"
    break;

  case 42: /* UnaryOp: '+'  */
#line 360 "src/sysy.y"
        {
    (yyval.str_val) = new string("+");
  }
#line 1634 "build/sysy.tab.c"
    break;

  case 43: /* UnaryOp: '-'  */
#line 363 "src/sysy.y"
        {
    (yyval.str_val) = new string("-");
  }
#line 1642 "build/sysy.tab.c"
    break;

  case 44: /* UnaryOp: '!'  */
#line 366 "src/sysy.y"
        {
    (yyval.str_val) = new string("!");
  }
#line 1650 "build/sysy.tab.c"
    break;

  case 45: /* MulExp: UnaryExp  */
#line 372 "src/sysy.y"
             {
    auto mul_exp = new MulExpAST();
    mul_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    mul_exp -> mode = 1;
    (yyval.ast_val) = mul_exp;
  }
#line 1661 "build/sysy.tab.c"
    break;

  case 46: /* MulExp: MulExp '*' UnaryExp  */
#line 378 "src/sysy.y"
                        {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    mul_exp -> mode = 2;
    mul_exp -> op = "*";
    mul_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = mul_exp;
  }
#line 1674 "build/sysy.tab.c"
    break;

  case 47: /* MulExp: MulExp '/' UnaryExp  */
#line 386 "src/sysy.y"
                        {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    mul_exp -> mode = 2;
    mul_exp -> op = "/";
    mul_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = mul_exp;
  }
#line 1687 "build/sysy.tab.c"
    break;

  case 48: /* MulExp: MulExp '%' UnaryExp  */
#line 394 "src/sysy.y"
                        {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    mul_exp -> mode = 2;
    mul_exp -> op = "%";
    mul_exp -> unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = mul_exp;
  }
#line 1700 "build/sysy.tab.c"
    break;

  case 49: /* AddExp: MulExp  */
#line 405 "src/sysy.y"
          {
    auto add_exp = new AddExpAST();
    add_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    add_exp -> mode = 1;
    (yyval.ast_val) = add_exp;
 }
#line 1711 "build/sysy.tab.c"
    break;

  case 50: /* AddExp: AddExp '+' MulExp  */
#line 411 "src/sysy.y"
                      {
    auto add_exp = new AddExpAST();
    add_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    add_exp -> mode = 2;
    add_exp -> op = "+";
    add_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = add_exp;
  }
#line 1724 "build/sysy.tab.c"
    break;

  case 51: /* AddExp: AddExp '-' MulExp  */
#line 419 "src/sysy.y"
                      {
    auto add_exp = new AddExpAST();
    add_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    add_exp -> mode = 2;
    add_exp -> op = "-";
    add_exp -> mul_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = add_exp;
  }
#line 1737 "build/sysy.tab.c"
    break;

  case 52: /* RelExp: AddExp  */
#line 430 "src/sysy.y"
           {
    auto rel_exp = new RelExpAST();
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    rel_exp -> mode = 1;
    (yyval.ast_val) = rel_exp;
  }
#line 1748 "build/sysy.tab.c"
    break;

  case 53: /* RelExp: RelExp '<' AddExp  */
#line 436 "src/sysy.y"
                      {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    rel_exp -> mode = 2;
    rel_exp -> op = "<";
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
  }
#line 1761 "build/sysy.tab.c"
    break;

  case 54: /* RelExp: RelExp '>' AddExp  */
#line 444 "src/sysy.y"
                      {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    rel_exp -> mode = 2;
    rel_exp -> op = ">";
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
  }
#line 1774 "build/sysy.tab.c"
    break;

  case 55: /* RelExp: RelExp LE AddExp  */
#line 452 "src/sysy.y"
                     {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    rel_exp -> mode = 2;
    rel_exp -> op = "<=";
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
  }
#line 1787 "build/sysy.tab.c"
    break;

  case 56: /* RelExp: RelExp GE AddExp  */
#line 460 "src/sysy.y"
                     {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    rel_exp -> mode = 2;
    rel_exp -> op = ">=";
    rel_exp -> add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
  }
#line 1800 "build/sysy.tab.c"
    break;

  case 57: /* EqExp: RelExp  */
#line 471 "src/sysy.y"
           {
    auto eq_exp = new EqExpAST();
    eq_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    eq_exp -> mode = 1;
    (yyval.ast_val) = eq_exp;
  }
#line 1811 "build/sysy.tab.c"
    break;

  case 58: /* EqExp: EqExp EQ RelExp  */
#line 477 "src/sysy.y"
                    {
    auto eq_exp = new EqExpAST();
    eq_exp -> eq_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    eq_exp -> mode = 2;
    eq_exp -> op = "==";
    eq_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = eq_exp;
  }
#line 1824 "build/sysy.tab.c"
    break;

  case 59: /* EqExp: EqExp NE RelExp  */
#line 485 "src/sysy.y"
                    {
    auto eq_exp = new EqExpAST();
    eq_exp -> eq_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    eq_exp -> mode = 2;
    eq_exp -> op = "!=";
    eq_exp -> rel_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = eq_exp;
  }
#line 1837 "build/sysy.tab.c"
    break;

  case 60: /* LAndExp: EqExp  */
#line 496 "src/sysy.y"
          {
    auto land_exp = new LAndExpAST();
    land_exp -> eq_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    land_exp -> mode = 1;
    (yyval.ast_val) = land_exp;
  }
#line 1848 "build/sysy.tab.c"
    break;

  case 61: /* LAndExp: LAndExp AND EqExp  */
#line 502 "src/sysy.y"
                      {
    auto land_exp = new LAndExpAST();
    land_exp -> land_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    land_exp -> mode = 2;
    land_exp -> op = "&&";
    land_exp -> eq_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = land_exp;
  }
#line 1861 "build/sysy.tab.c"
    break;

  case 62: /* LOrExp: LAndExp  */
#line 513 "src/sysy.y"
            {
    auto lor_exp = new LOrExpAST();
    lor_exp -> land_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    lor_exp -> mode = 1;
    (yyval.ast_val) = lor_exp;
  }
#line 1872 "build/sysy.tab.c"
    break;

  case 63: /* LOrExp: LOrExp OR LAndExp  */
#line 519 "src/sysy.y"
                      {
    auto lor_exp = new LOrExpAST();
    lor_exp -> lor_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    lor_exp -> mode = 2;
    lor_exp -> op = "||";
    lor_exp -> land_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = lor_exp;
  }
#line 1885 "build/sysy.tab.c"
    break;

  case 64: /* ConstExp: Exp  */
#line 531 "src/sysy.y"
        {
    auto const_exp = new ConstExpAST();
    const_exp -> exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = const_exp;
  }
#line 1895 "build/sysy.tab.c"
    break;


#line 1899 "build/sysy.tab.c"

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

#line 537 "src/sysy.y"


// 定义错误处理函数, 其中第二个参数是错误信息, parser 如果发生错误 (例如输入的程序出现了语法错误), 就会调用这个函数
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  extern char* yytext;  // 声明 yytext
  extern int yylineno;  // 声明 yylineno
  cerr << "error: " << s << endl;
   cerr << "near " << yytext << endl;
   cerr << "line " << yylineno << endl;
}

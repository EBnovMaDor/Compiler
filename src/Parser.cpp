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

#include "Parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COMMA = 3,                      /* COMMA  */
  YYSYMBOL_ELLIPSIS = 4,                   /* ELLIPSIS  */
  YYSYMBOL_DOT = 5,                        /* DOT  */
  YYSYMBOL_SEMI = 6,                       /* SEMI  */
  YYSYMBOL_ARROW = 7,                      /* ARROW  */
  YYSYMBOL_QUES = 8,                       /* QUES  */
  YYSYMBOL_COLON = 9,                      /* COLON  */
  YYSYMBOL_LPAREN = 10,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 11,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 12,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 13,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 14,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 15,                    /* RBRACE  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_BANDEQ = 25,                    /* BANDEQ  */
  YYSYMBOL_BAND = 26,                      /* BAND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_BOREQ = 28,                     /* BOREQ  */
  YYSYMBOL_BOR = 29,                       /* BOR  */
  YYSYMBOL_BXOR = 30,                      /* BXOR  */
  YYSYMBOL_BXOREQ = 31,                    /* BXOREQ  */
  YYSYMBOL_BNOT = 32,                      /* BNOT  */
  YYSYMBOL_AADD = 33,                      /* AADD  */
  YYSYMBOL_ADDEQ = 34,                     /* ADDEQ  */
  YYSYMBOL_ADD = 35,                       /* ADD  */
  YYSYMBOL_SSUB = 36,                      /* SSUB  */
  YYSYMBOL_SUBEQ = 37,                     /* SUBEQ  */
  YYSYMBOL_SUB = 38,                       /* SUB  */
  YYSYMBOL_MULEQ = 39,                     /* MULEQ  */
  YYSYMBOL_MUL = 40,                       /* MUL  */
  YYSYMBOL_DIVEQ = 41,                     /* DIVEQ  */
  YYSYMBOL_DIV = 42,                       /* DIV  */
  YYSYMBOL_MOD = 43,                       /* MOD  */
  YYSYMBOL_MODEQ = 44,                     /* MODEQ  */
  YYSYMBOL_STRUCT = 45,                    /* STRUCT  */
  YYSYMBOL_TYPEDEF = 46,                   /* TYPEDEF  */
  YYSYMBOL_CONST = 47,                     /* CONST  */
  YYSYMBOL_RETURN = 48,                    /* RETURN  */
  YYSYMBOL_IF = 49,                        /* IF  */
  YYSYMBOL_ELSE = 50,                      /* ELSE  */
  YYSYMBOL_FOR = 51,                       /* FOR  */
  YYSYMBOL_WHILE = 52,                     /* WHILE  */
  YYSYMBOL_CONTINUE = 53,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 54,                     /* BREAK  */
  YYSYMBOL_SWITCH = 55,                    /* SWITCH  */
  YYSYMBOL_CASE = 56,                      /* CASE  */
  YYSYMBOL_DEFAULT = 57,                   /* DEFAULT  */
  YYSYMBOL_TRUE = 58,                      /* TRUE  */
  YYSYMBOL_FALSE = 59,                     /* FALSE  */
  YYSYMBOL_BOOL = 60,                      /* BOOL  */
  YYSYMBOL_SHORT = 61,                     /* SHORT  */
  YYSYMBOL_LONG = 62,                      /* LONG  */
  YYSYMBOL_INT = 63,                       /* INT  */
  YYSYMBOL_FLOAT = 64,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 65,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 66,                      /* CHAR  */
  YYSYMBOL_VOID = 67,                      /* VOID  */
  YYSYMBOL_SQUOTE = 68,                    /* SQUOTE  */
  YYSYMBOL_DQUOTE = 69,                    /* DQUOTE  */
  YYSYMBOL_PRINTF = 70,                    /* PRINTF  */
  YYSYMBOL_SCANF = 71,                     /* SCANF  */
  YYSYMBOL_INTERGER = 72,                  /* INTERGER  */
  YYSYMBOL_IDENTIFIER = 73,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 74,                    /* STRING  */
  YYSYMBOL_REAL = 75,                      /* REAL  */
  YYSYMBOL_CHARACTER = 76,                 /* CHARACTER  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_CompUnit = 78,                  /* CompUnit  */
  YYSYMBOL_Decl = 79,                      /* Decl  */
  YYSYMBOL_StructDecl = 80,                /* StructDecl  */
  YYSYMBOL_VarDeclWrap = 81,               /* VarDeclWrap  */
  YYSYMBOL_BType = 82,                     /* BType  */
  YYSYMBOL_ConstDecl = 83,                 /* ConstDecl  */
  YYSYMBOL_ConstDef = 84,                  /* ConstDef  */
  YYSYMBOL_ConstInitVal = 85,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValWrap = 86,          /* ConstInitValWrap  */
  YYSYMBOL_VarDecl = 87,                   /* VarDecl  */
  YYSYMBOL_VarDef = 88,                    /* VarDef  */
  YYSYMBOL_InitVal = 89,                   /* InitVal  */
  YYSYMBOL_InitValWrap = 90,               /* InitValWrap  */
  YYSYMBOL_FuncDef = 91,                   /* FuncDef  */
  YYSYMBOL_FuncType = 92,                  /* FuncType  */
  YYSYMBOL_FuncFParams = 93,               /* FuncFParams  */
  YYSYMBOL_FuncFParamsWrap = 94,           /* FuncFParamsWrap  */
  YYSYMBOL_FuncFParam = 95,                /* FuncFParam  */
  YYSYMBOL_ExpWrap = 96,                   /* ExpWrap  */
  YYSYMBOL_Block = 97,                     /* Block  */
  YYSYMBOL_BlockItemWrap = 98,             /* BlockItemWrap  */
  YYSYMBOL_BlockItem = 99,                 /* BlockItem  */
  YYSYMBOL_Stmt = 100,                     /* Stmt  */
  YYSYMBOL_Exp = 101,                      /* Exp  */
  YYSYMBOL_Cond = 102,                     /* Cond  */
  YYSYMBOL_LVal = 103,                     /* LVal  */
  YYSYMBOL_PrimaryExp = 104,               /* PrimaryExp  */
  YYSYMBOL_Number = 105,                   /* Number  */
  YYSYMBOL_UnaryExp = 106,                 /* UnaryExp  */
  YYSYMBOL_UnaryOp = 107,                  /* UnaryOp  */
  YYSYMBOL_FuncRParams = 108,              /* FuncRParams  */
  YYSYMBOL_FuncRParamsWrap = 109,          /* FuncRParamsWrap  */
  YYSYMBOL_MulExp = 110,                   /* MulExp  */
  YYSYMBOL_AddExp = 111,                   /* AddExp  */
  YYSYMBOL_RelExp = 112,                   /* RelExp  */
  YYSYMBOL_EqExp = 113,                    /* EqExp  */
  YYSYMBOL_LAndExp = 114,                  /* LAndExp  */
  YYSYMBOL_LOrExp = 115                    /* LOrExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 16 "Parser.y"

    #include <string>
    #include <iostream>
    #include <memory>
    #include <vector>
    #include "AST.hpp"
    using namespace std;

    int yylex();
    void yyerror(shared_ptr<BaseAST> &ast, const char *s);

#line 231 "Parser.cpp"

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


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
      75,    76
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    68,    76,    85,    97,   102,   107,   115,
     122,   136,   141,   149,   154,   163,   168,   172,   173,   174,
     175,   179,   180,   184,   191,   201,   211,   221,   222,   232,
     242,   252,   257,   260,   261,   264,   273,   278,   286,   294,
     307,   314,   321,   331,   334,   342,   345,   353,   366,   383,
     387,   393,   401,   407,   412,   420,   423,   429,   438,   447,
     456,   465,   473,   476,   486,   496,   505,   513,   521,   529,
     537,   545,   548,   554,   560,   567,   574,   585,   588,   591,
     603,   611,   622,   625,   632,   640,   644,   645,   646,   650,
     656,   664,   670,   678,   681,   690,   699,   711,   714,   723,
     735,   738,   747,   756,   765,   777,   780,   789,   801,   804,
     816,   819
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
  "\"end of file\"", "error", "\"invalid token\"", "COMMA", "ELLIPSIS",
  "DOT", "SEMI", "ARROW", "QUES", "COLON", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "EQ", "GE", "LE", "GT", "LT", "NE",
  "NOT", "ASSIGN", "AND", "BANDEQ", "BAND", "OR", "BOREQ", "BOR", "BXOR",
  "BXOREQ", "BNOT", "AADD", "ADDEQ", "ADD", "SSUB", "SUBEQ", "SUB",
  "MULEQ", "MUL", "DIVEQ", "DIV", "MOD", "MODEQ", "STRUCT", "TYPEDEF",
  "CONST", "RETURN", "IF", "ELSE", "FOR", "WHILE", "CONTINUE", "BREAK",
  "SWITCH", "CASE", "DEFAULT", "TRUE", "FALSE", "BOOL", "SHORT", "LONG",
  "INT", "FLOAT", "DOUBLE", "CHAR", "VOID", "SQUOTE", "DQUOTE", "PRINTF",
  "SCANF", "INTERGER", "IDENTIFIER", "STRING", "REAL", "CHARACTER",
  "$accept", "CompUnit", "Decl", "StructDecl", "VarDeclWrap", "BType",
  "ConstDecl", "ConstDef", "ConstInitVal", "ConstInitValWrap", "VarDecl",
  "VarDef", "InitVal", "InitValWrap", "FuncDef", "FuncType", "FuncFParams",
  "FuncFParamsWrap", "FuncFParam", "ExpWrap", "Block", "BlockItemWrap",
  "BlockItem", "Stmt", "Exp", "Cond", "LVal", "PrimaryExp", "Number",
  "UnaryExp", "UnaryOp", "FuncRParams", "FuncRParamsWrap", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-176)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      79,   -48,    52,   -45,   -26,    -8,    17,  -176,  -176,  -176,
    -176,    69,  -176,    76,   -10,  -176,  -176,    24,     9,    34,
    -176,  -176,  -176,  -176,  -176,     3,    60,    93,   119,    84,
     216,   192,   117,   192,   120,   131,    87,   154,   148,    94,
      95,    20,  -176,   192,   143,  -176,   216,  -176,  -176,  -176,
    -176,    88,  -176,   156,  -176,  -176,  -176,  -176,   216,   113,
     257,   118,    78,   147,   146,    16,  -176,  -176,   192,  -176,
     192,   140,  -176,   162,   131,    52,  -176,     6,    38,   170,
    -176,   171,   221,   173,   107,   236,  -176,   119,  -176,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,  -176,     5,  -176,  -176,   175,     1,   172,   176,
     184,   189,   186,   187,  -176,  -176,   183,    57,  -176,   193,
     177,   188,  -176,   148,  -176,  -176,   210,  -176,  -176,  -176,
    -176,  -176,   205,   198,  -176,  -176,  -176,  -176,   113,   113,
      18,    18,    18,    18,    18,   118,   118,    78,   147,   192,
    -176,   201,  -176,  -176,   213,   216,   216,  -176,  -176,   155,
     159,  -176,  -176,  -176,   216,   119,  -176,  -176,    19,   216,
    -176,  -176,   225,  -176,  -176,   223,   146,   226,    67,   233,
     243,  -176,   221,  -176,   235,   205,  -176,   169,   169,   216,
     246,   216,  -176,   250,  -176,  -176,   207,  -176,   244,  -176,
     251,  -176,   169,   255,   260,  -176,  -176,  -176
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     3,     8,     6,
       7,     0,     2,     0,     0,    13,    14,     0,    24,    28,
      42,     1,     4,     5,    23,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    30,     0,     0,     0,    43,     0,
       0,     0,    11,     0,     0,    15,     0,    88,    87,    86,
      80,    74,    81,     0,    78,    82,    79,    93,     0,    97,
     100,   105,   108,   110,    72,     0,    25,    32,     0,    29,
       0,     0,    38,    47,     0,     0,    44,    24,    28,     0,
      12,     0,     0,     0,     0,     0,    75,    50,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,    27,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    62,     0,     0,    56,     0,
      78,     0,    39,    45,     9,    10,     0,    16,    17,    77,
      76,    83,    89,     0,    51,    94,    95,    96,    98,    99,
     104,   103,   102,   101,   100,   106,   107,   109,   111,     0,
      34,     0,    70,    69,     0,     0,     0,    67,    66,     0,
       0,    52,    54,    61,     0,    48,    46,    18,     0,     0,
      90,    84,    36,    35,    68,     0,    73,     0,     0,     0,
       0,    49,     0,    19,     0,    91,    37,     0,     0,     0,
       0,     0,    57,    21,    20,    92,    63,    65,     0,    58,
       0,    22,     0,     0,     0,    64,    59,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,    43,  -176,  -176,   267,  -176,  -176,  -123,    80,
     -17,  -176,   -28,   103,   270,  -176,  -176,   157,   202,   -18,
     -29,   161,  -176,  -175,   -30,   123,   -69,  -176,  -176,    23,
    -176,   -88,    96,    15,   203,    50,   190,   185,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,   114,     8,    41,    36,     9,    29,   127,   184,
      10,    11,    66,   151,    12,    13,    37,    76,    38,    32,
     115,   116,   117,   118,    67,   175,    54,    55,    56,    57,
      58,   133,   170,    59,    60,    61,    62,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    34,   120,   168,    26,    69,    72,   153,   149,    42,
      44,    46,   196,   197,    35,    81,    83,    21,    30,   -40,
     150,    30,   182,    47,    80,    14,    46,   205,    18,    31,
      65,   102,    31,    86,   183,    79,    48,   103,    47,    49,
     104,   119,   105,     7,   -41,   122,    30,    19,   120,    22,
      30,    48,   128,    92,    49,   132,    93,    33,   106,   193,
      34,    33,     1,    27,     2,    20,    15,    46,    16,   134,
     189,    71,   -53,    50,    51,    24,    52,   154,   190,    47,
       3,    88,     4,    39,     5,    40,    25,   119,    50,    51,
      45,    52,    48,    84,    98,    49,   128,    28,    85,    99,
      30,   198,     1,   200,     2,   107,   108,   138,   139,   109,
     110,   111,   135,   136,   137,    15,    43,    16,   120,   120,
      39,   172,    40,    39,     1,    40,     2,   112,   113,    50,
      51,    30,    52,   120,   180,    94,    95,    96,    97,   185,
      68,   106,     3,    70,     4,    71,     5,   181,   145,   146,
      46,    75,   128,    89,    71,    90,    91,   119,   119,   132,
      73,   132,    47,   176,   176,    74,    82,    77,    78,    87,
     106,   100,   119,   101,   121,    48,   124,   125,    49,    46,
     130,   152,   155,    71,   129,     1,   156,     2,   107,   108,
     157,    47,   109,   110,   111,   158,   159,   160,   161,   163,
     164,   165,    46,    39,    48,    40,    65,    49,   169,   171,
     112,   113,    50,    51,    47,    52,   173,   107,   108,   174,
      46,   109,   110,   111,   126,   167,    46,    48,   149,   178,
      49,    46,    47,   179,   187,   126,   191,   188,    47,   112,
     113,    50,    51,    47,    52,    48,    46,   131,    49,   192,
     194,    48,   199,   182,    49,   203,    48,   202,    47,    49,
     -71,   206,   204,   -71,    50,    51,   207,    52,   -71,    17,
     -71,    48,   -71,   201,    49,   186,    23,   123,   162,   177,
     166,   195,    50,    51,     0,    52,   148,     0,    50,    51,
     147,    52,    92,    50,    51,    93,    52,   140,   141,   142,
     143,   144,   144,   144,   144,     0,     0,     0,    50,    51,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   144
};

static const yytype_int16 yycheck[] =
{
      30,    19,    71,   126,    14,    33,    35,     6,     3,    26,
      28,    10,   187,   188,    11,    43,    46,     0,    12,    10,
      15,    12,     3,    22,    41,    73,    10,   202,    73,    23,
      14,    15,    23,    51,    15,    15,    35,    65,    22,    38,
      68,    71,    70,     0,    10,    74,    12,    73,   117,     6,
      12,    35,    82,    35,    38,    85,    38,    23,     1,   182,
      78,    23,    45,    73,    47,    73,    63,    10,    65,    87,
       3,    14,    15,    72,    73,     6,    75,   107,    11,    22,
      63,    58,    65,    63,    67,    65,    10,   117,    72,    73,
       6,    75,    35,     5,    16,    38,   126,    73,    10,    21,
      12,   189,    45,   191,    47,    48,    49,    92,    93,    52,
      53,    54,    89,    90,    91,    63,    23,    65,   187,   188,
      63,   149,    65,    63,    45,    65,    47,    70,    71,    72,
      73,    12,    75,   202,   164,    17,    18,    19,    20,   169,
      23,     1,    63,    23,    65,    14,    67,   165,    98,    99,
      10,     3,   182,    40,    14,    42,    43,   187,   188,   189,
      73,   191,    22,   155,   156,    11,    23,    73,    73,    13,
       1,    24,   202,    27,    12,    35,     6,     6,    38,    10,
      73,     6,    10,    14,    11,    45,    10,    47,    48,    49,
       6,    22,    52,    53,    54,     6,    10,    10,    15,     6,
      23,    13,    10,    63,    35,    65,    14,    38,     3,    11,
      70,    71,    72,    73,    22,    75,    15,    48,    49,     6,
      10,    52,    53,    54,    14,    15,    10,    35,     3,    74,
      38,    10,    22,    74,    11,    14,     3,    11,    22,    70,
      71,    72,    73,    22,    75,    35,    10,    11,    38,     6,
      15,    35,     6,     3,    38,    11,    35,    50,    22,    38,
       3,     6,    11,     6,    72,    73,     6,    75,    11,     2,
      13,    35,    15,   193,    38,   172,     6,    75,   117,   156,
     123,   185,    72,    73,    -1,    75,   101,    -1,    72,    73,
     100,    75,    35,    72,    73,    38,    75,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    72,    73,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    47,    63,    65,    67,    78,    79,    80,    83,
      87,    88,    91,    92,    73,    63,    65,    82,    73,    73,
      73,     0,    79,    91,     6,    10,    14,    73,    73,    84,
      12,    23,    96,    23,    96,    11,    82,    93,    95,    63,
      65,    81,    87,    23,    96,     6,    10,    22,    35,    38,
      72,    73,    75,   101,   103,   104,   105,   106,   107,   110,
     111,   112,   113,   114,   115,    14,    89,   101,    23,    89,
      23,    14,    97,    73,    11,     3,    94,    73,    73,    15,
      87,    89,    23,   101,     5,    10,    96,    13,   106,    40,
      42,    43,    35,    38,    17,    18,    19,    20,    16,    21,
      24,    27,    15,    89,    89,    89,     1,    48,    49,    52,
      53,    54,    70,    71,    79,    97,    98,    99,   100,   101,
     103,    12,    97,    95,     6,     6,    14,    85,   101,    11,
      73,    11,   101,   108,    96,   106,   106,   106,   110,   110,
     111,   111,   111,   111,   111,   112,   112,   113,   114,     3,
      15,    90,     6,     6,   101,    10,    10,     6,     6,    10,
      10,    15,    98,     6,    23,    13,    94,    15,    85,     3,
     109,    11,    89,    15,     6,   102,   115,   102,    74,    74,
     101,    96,     3,    15,    86,   101,    90,    11,    11,     3,
      11,     3,     6,    85,    15,   109,   100,   100,   108,     6,
     108,    86,    50,    11,    11,   100,     6,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    77,    78,    78,    78,    78,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    84,    85,    85,    85,
      85,    86,    86,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      96,    96,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   103,   103,   103,   104,   104,   104,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   111,   111,   111,
     112,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     6,
       6,     1,     2,     1,     1,     4,     4,     1,     2,     3,
       4,     2,     3,     2,     2,     4,     3,     5,     2,     4,
       3,     5,     1,     2,     3,     4,     2,     3,     4,     5,
       2,     2,     2,     1,     2,     2,     3,     2,     4,     5,
       3,     4,     3,     1,     2,     1,     1,     4,     5,     7,
       7,     2,     1,     5,     7,     5,     2,     2,     3,     2,
       2,     1,     1,     1,     1,     2,     3,     3,     1,     1,
       1,     1,     1,     3,     4,     2,     1,     1,     1,     1,
       2,     2,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3
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
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, shared_ptr<BaseAST> &ast)
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, shared_ptr<BaseAST> &ast)
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
                 int yyrule, shared_ptr<BaseAST> &ast)
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, shared_ptr<BaseAST> &ast)
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
yyparse (shared_ptr<BaseAST> &ast)
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
#line 60 "Parser.y"
             {
        auto func = new CompUnit();
        func->Name = "CompUnits";
        func->AST_type = COMPUNIT;
		func->CompUnits.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		ast = shared_ptr<CompUnit>(func);
		(yyval.astVal) = func;
    }
#line 1372 "Parser.cpp"
    break;

  case 3: /* CompUnit: Decl  */
#line 68 "Parser.y"
           {
		auto decl = new CompUnit();
		decl->Name = "CompUnits";
		decl->AST_type = COMPUNIT;
		decl->CompUnits.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		ast = shared_ptr<CompUnit>(decl);
		(yyval.astVal) = decl;
	}
#line 1385 "Parser.cpp"
    break;

  case 4: /* CompUnit: CompUnit Decl  */
#line 76 "Parser.y"
                    {
		auto comp_unit = new CompUnit();
		comp_unit->Name = "CompUnits";
		comp_unit->AST_type = COMPUNIT;
		comp_unit->CompUnits = move(reinterpret_cast<CompUnit*>(yyvsp[-1].astVal)->CompUnits);
		comp_unit->CompUnits.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		ast = shared_ptr<CompUnit>(comp_unit);
		(yyval.astVal) = comp_unit;
	}
#line 1399 "Parser.cpp"
    break;

  case 5: /* CompUnit: CompUnit FuncDef  */
#line 85 "Parser.y"
                       {
		auto comp_unit = new CompUnit();
		comp_unit->Name = "CompUnits";
		comp_unit->AST_type = COMPUNIT;
		comp_unit->CompUnits = move(reinterpret_cast<CompUnit*>(yyvsp[-1].astVal)->CompUnits);
		comp_unit->CompUnits.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		ast = shared_ptr<CompUnit>(comp_unit);
		(yyval.astVal) = comp_unit;
	}
#line 1413 "Parser.cpp"
    break;

  case 6: /* Decl: ConstDecl  */
#line 97 "Parser.y"
                    { 
		(yyvsp[0].astVal)->Name = "ConstDecl";
		(yyvsp[0].astVal)->AST_type = DECL;
		(yyval.astVal) = (yyvsp[0].astVal); 
	}
#line 1423 "Parser.cpp"
    break;

  case 7: /* Decl: VarDecl  */
#line 102 "Parser.y"
                  { 
		(yyvsp[0].astVal)->Name = "VarDecl"; 
		(yyvsp[0].astVal)->AST_type = DECL;
		(yyval.astVal) = (yyvsp[0].astVal); 
	}
#line 1433 "Parser.cpp"
    break;

  case 8: /* Decl: StructDecl  */
#line 107 "Parser.y"
                     {
		(yyvsp[0].astVal)->Name = "StructDecl";
		(yyvsp[0].astVal)->AST_type = DECL;
		(yyval.astVal) = (yyvsp[0].astVal);
	}
#line 1443 "Parser.cpp"
    break;

  case 9: /* StructDecl: STRUCT IDENTIFIER LBRACE VarDeclWrap RBRACE SEMI  */
#line 115 "Parser.y"
                                                       {
        auto ast = new Decl();
        ast->Decl_type = Struct;
        ast->Struct_name = *shared_ptr<string>((yyvsp[-4].sVal));
        ast->Member = move(reinterpret_cast<Decl*>(yyvsp[-2].astVal)->Member);
        (yyval.astVal) = ast;
    }
#line 1455 "Parser.cpp"
    break;

  case 10: /* StructDecl: STRUCT IDENTIFIER IDENTIFIER ASSIGN InitVal SEMI  */
#line 122 "Parser.y"
                                                       {
        auto ast = new Decl();
        ast->Decl_type = Struct;
		ast->Struct_name = *shared_ptr<string>((yyvsp[-4].sVal));
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[-3].sVal));
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = shared_ptr<BaseAST>((yyvsp[-1].astVal));
		(yyval.astVal) = ast;
    }
#line 1471 "Parser.cpp"
    break;

  case 11: /* VarDeclWrap: VarDecl  */
#line 136 "Parser.y"
              {
        auto ast = new Decl();
		ast->Member.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		(yyval.astVal) = ast;
    }
#line 1481 "Parser.cpp"
    break;

  case 12: /* VarDeclWrap: VarDeclWrap VarDecl  */
#line 141 "Parser.y"
                          {
        auto ast = reinterpret_cast<Decl*>(yyvsp[-1].astVal);
		ast->Member.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		(yyval.astVal) = ast;
    }
#line 1491 "Parser.cpp"
    break;

  case 13: /* BType: INT  */
#line 149 "Parser.y"
          {
        auto ast = new Decl();
		ast->Decl_type = Int;
		(yyval.astVal) = ast;
    }
#line 1501 "Parser.cpp"
    break;

  case 14: /* BType: DOUBLE  */
#line 154 "Parser.y"
             {
        auto ast = new Decl();
		ast->Decl_type = Double;
		(yyval.astVal) = ast;
    }
#line 1511 "Parser.cpp"
    break;

  case 15: /* ConstDecl: CONST BType ConstDef SEMI  */
#line 163 "Parser.y"
                                    { }
#line 1517 "Parser.cpp"
    break;

  case 16: /* ConstDef: IDENTIFIER ExpWrap ASSIGN ConstInitVal  */
#line 168 "Parser.y"
                                             { }
#line 1523 "Parser.cpp"
    break;

  case 17: /* ConstInitVal: Exp  */
#line 172 "Parser.y"
          { }
#line 1529 "Parser.cpp"
    break;

  case 18: /* ConstInitVal: LBRACE RBRACE  */
#line 173 "Parser.y"
                    { }
#line 1535 "Parser.cpp"
    break;

  case 19: /* ConstInitVal: LBRACE ConstInitVal RBRACE  */
#line 174 "Parser.y"
                                 { }
#line 1541 "Parser.cpp"
    break;

  case 20: /* ConstInitVal: LBRACE ConstInitVal ConstInitValWrap RBRACE  */
#line 175 "Parser.y"
                                                  { }
#line 1547 "Parser.cpp"
    break;

  case 21: /* ConstInitValWrap: COMMA ConstInitVal  */
#line 179 "Parser.y"
                         { }
#line 1553 "Parser.cpp"
    break;

  case 22: /* ConstInitValWrap: COMMA ConstInitVal ConstInitValWrap  */
#line 180 "Parser.y"
                                          { }
#line 1559 "Parser.cpp"
    break;

  case 23: /* VarDecl: VarDef SEMI  */
#line 184 "Parser.y"
                  {
        (yyval.astVal) = (yyvsp[-1].astVal);
    }
#line 1567 "Parser.cpp"
    break;

  case 24: /* VarDef: INT IDENTIFIER  */
#line 191 "Parser.y"
                     {
        auto ast = new Decl();
		ast->Decl_type = Int;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[0].sVal));
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = nullptr;
		(yyval.astVal) = ast;
    }
#line 1582 "Parser.cpp"
    break;

  case 25: /* VarDef: INT IDENTIFIER ASSIGN InitVal  */
#line 201 "Parser.y"
                                    {
        auto ast = new Decl();
		ast->Decl_type = Int;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[-2].sVal));
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 1597 "Parser.cpp"
    break;

  case 26: /* VarDef: INT IDENTIFIER ExpWrap  */
#line 211 "Parser.y"
                             {
        auto ast = new Decl();
		ast->Decl_type = Int;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[-1].sVal));
		var_ast->Length = move(reinterpret_cast<Variable*>(yyvsp[0].astVal)->Length);
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = nullptr;
		(yyval.astVal) = ast;
    }
#line 1612 "Parser.cpp"
    break;

  case 27: /* VarDef: INT IDENTIFIER ExpWrap ASSIGN InitVal  */
#line 221 "Parser.y"
                                            { }
#line 1618 "Parser.cpp"
    break;

  case 28: /* VarDef: DOUBLE IDENTIFIER  */
#line 222 "Parser.y"
                        {
        auto ast = new Decl();
		ast->Decl_type = Double;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[0].sVal));
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = nullptr;
		(yyval.astVal) = ast;
    }
#line 1633 "Parser.cpp"
    break;

  case 29: /* VarDef: DOUBLE IDENTIFIER ASSIGN InitVal  */
#line 232 "Parser.y"
                                       {
        auto ast = new Decl();
		ast->Decl_type = Double;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[-2].sVal));
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 1648 "Parser.cpp"
    break;

  case 30: /* VarDef: DOUBLE IDENTIFIER ExpWrap  */
#line 242 "Parser.y"
                                {
        auto ast = new Decl();
		ast->Decl_type = Double;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[-1].sVal));
		var_ast->Length = move(reinterpret_cast<Variable*>(yyvsp[0].astVal)->Length);
		ast->Var = shared_ptr<BaseAST>(var_ast);
		ast->Exp = nullptr;
		(yyval.astVal) = ast;
    }
#line 1663 "Parser.cpp"
    break;

  case 31: /* VarDef: DOUBLE IDENTIFIER ExpWrap ASSIGN InitVal  */
#line 252 "Parser.y"
                                               { }
#line 1669 "Parser.cpp"
    break;

  case 32: /* InitVal: Exp  */
#line 257 "Parser.y"
          {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 1677 "Parser.cpp"
    break;

  case 33: /* InitVal: LBRACE RBRACE  */
#line 260 "Parser.y"
                    { }
#line 1683 "Parser.cpp"
    break;

  case 34: /* InitVal: LBRACE InitVal RBRACE  */
#line 261 "Parser.y"
                           {
        (yyval.astVal) = (yyvsp[-1].astVal);
    }
#line 1691 "Parser.cpp"
    break;

  case 35: /* InitVal: LBRACE InitVal InitValWrap RBRACE  */
#line 264 "Parser.y"
                                       {
        auto ast = reinterpret_cast<ExpList*>(yyvsp[-1].astVal);
		ast->AST_type = EXPLIST;
		ast->Exps.insert(ast->Exps.begin(), shared_ptr<BaseAST>((yyvsp[-2].astVal)));
		(yyval.astVal) = ast;
    }
#line 1702 "Parser.cpp"
    break;

  case 36: /* InitValWrap: COMMA InitVal  */
#line 273 "Parser.y"
                    {
        auto ast = new ExpList();
		ast->Exps.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		(yyval.astVal) = ast;
    }
#line 1712 "Parser.cpp"
    break;

  case 37: /* InitValWrap: COMMA InitVal InitValWrap  */
#line 278 "Parser.y"
                                {
        auto ast = reinterpret_cast<ExpList*>(yyvsp[0].astVal);
		ast->Exps.insert(ast->Exps.begin(), shared_ptr<BaseAST>((yyvsp[-1].astVal)));
		(yyval.astVal) = ast;
    }
#line 1722 "Parser.cpp"
    break;

  case 38: /* FuncDef: FuncType LPAREN RPAREN Block  */
#line 286 "Parser.y"
                                   {
        auto ast = new Func();
		ast->Name = "FuncDef";
		ast->AST_type = FUNC;
		ast->Prototype = shared_ptr<BaseAST>((yyvsp[-3].astVal));
		ast->Blocks = move(reinterpret_cast<Func*>(yyvsp[0].astVal)->Blocks);
		(yyval.astVal) = ast;
    }
#line 1735 "Parser.cpp"
    break;

  case 39: /* FuncDef: FuncType LPAREN FuncFParams RPAREN Block  */
#line 294 "Parser.y"
                                               {
        auto ast = new Func();
		ast->Name = "FuncDef";
		ast->AST_type = FUNC;
		auto func_prototype = move(reinterpret_cast<FuncPrototype*>(yyvsp[-4].astVal));
		func_prototype->Params = move(reinterpret_cast<FuncPrototype*>(yyvsp[-2].astVal)->Params);
		ast->Prototype = shared_ptr<BaseAST>(func_prototype);
		ast->Blocks = move(reinterpret_cast<Func*>(yyvsp[0].astVal)->Blocks);
		(yyval.astVal) = ast;
    }
#line 1750 "Parser.cpp"
    break;

  case 40: /* FuncType: INT IDENTIFIER  */
#line 307 "Parser.y"
                     {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Func_name = *shared_ptr<string>((yyvsp[0].sVal));
		ast->Func_type = Int;
		(yyval.astVal) = ast;
    }
#line 1762 "Parser.cpp"
    break;

  case 41: /* FuncType: DOUBLE IDENTIFIER  */
#line 314 "Parser.y"
                        {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Func_name = *shared_ptr<string>((yyvsp[0].sVal));
		ast->Func_type = Double;
		(yyval.astVal) = ast;
    }
#line 1774 "Parser.cpp"
    break;

  case 42: /* FuncType: VOID IDENTIFIER  */
#line 321 "Parser.y"
                      {
		auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Func_name = *shared_ptr<string>((yyvsp[0].sVal));
		ast->Func_type = Void;
		(yyval.astVal) = ast;
	}
#line 1786 "Parser.cpp"
    break;

  case 43: /* FuncFParams: FuncFParam  */
#line 331 "Parser.y"
                 {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 1794 "Parser.cpp"
    break;

  case 44: /* FuncFParams: FuncFParam FuncFParamsWrap  */
#line 334 "Parser.y"
                                 {
        auto ast = reinterpret_cast<FuncPrototype*>(yyvsp[0].astVal);
		ast->Params.insert(ast->Params.begin(), reinterpret_cast<FuncPrototype*>(yyvsp[-1].astVal)->Params[0]);
		(yyval.astVal) = ast;
    }
#line 1804 "Parser.cpp"
    break;

  case 45: /* FuncFParamsWrap: COMMA FuncFParam  */
#line 342 "Parser.y"
                       {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 1812 "Parser.cpp"
    break;

  case 46: /* FuncFParamsWrap: COMMA FuncFParam FuncFParamsWrap  */
#line 345 "Parser.y"
                                       {
        auto ast = reinterpret_cast<FuncPrototype*>(yyvsp[0].astVal);
		ast->Params.insert(ast->Params.begin(), reinterpret_cast<FuncPrototype*>(yyvsp[-1].astVal)->Params[0]);
		(yyval.astVal) = ast;
    }
#line 1822 "Parser.cpp"
    break;

  case 47: /* FuncFParam: BType IDENTIFIER  */
#line 353 "Parser.y"
                       {
        auto ast = new FuncPrototype();
		auto decl = new Decl();
		decl->Decl_type = reinterpret_cast<Decl*>(yyvsp[-1].astVal)->Decl_type;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[0].sVal));
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		decl->Var = shared_ptr<BaseAST>(var_ast);
		decl->Exp = nullptr;
		ast->Params = vector<shared_ptr<BaseAST>>();
		ast->Params.push_back(shared_ptr<BaseAST>(decl));
		(yyval.astVal) = ast;
    }
#line 1840 "Parser.cpp"
    break;

  case 48: /* FuncFParam: BType IDENTIFIER LBRACKET RBRACKET  */
#line 366 "Parser.y"
                                         {
        auto ast = new FuncPrototype();
		auto decl = new Decl();
		decl->Decl_type = reinterpret_cast<Decl*>(yyvsp[-3].astVal)->Decl_type;
		auto var_ast = new Variable();
		var_ast->Var_name = *shared_ptr<string>((yyvsp[-2].sVal));
		var_ast->Length = vector<shared_ptr<BaseAST>>();
		auto fake_exp = new Exp();
		fake_exp->AST_type = EXP;
		fake_exp->Name = "fake";
		var_ast->Length.push_back(shared_ptr<BaseAST>(fake_exp));
		decl->Var = shared_ptr<BaseAST>(var_ast);
		decl->Exp = nullptr;
		ast->Params = vector<shared_ptr<BaseAST>>();
		ast->Params.push_back(shared_ptr<BaseAST>(decl));
		(yyval.astVal) = ast;
    }
#line 1862 "Parser.cpp"
    break;

  case 49: /* FuncFParam: BType IDENTIFIER LBRACKET RBRACKET ExpWrap  */
#line 383 "Parser.y"
                                                 { }
#line 1868 "Parser.cpp"
    break;

  case 50: /* ExpWrap: LBRACKET Exp RBRACKET  */
#line 387 "Parser.y"
                            {
        auto ast = new Variable();
		ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Length.push_back(shared_ptr<BaseAST>((yyvsp[-1].astVal)));
		(yyval.astVal) = ast;
    }
#line 1879 "Parser.cpp"
    break;

  case 51: /* ExpWrap: LBRACKET Exp RBRACKET ExpWrap  */
#line 393 "Parser.y"
                                    {
        auto ast = reinterpret_cast<Variable*>(yyvsp[0].astVal);
		ast->Length.insert(ast->Length.begin(), shared_ptr<BaseAST>((yyvsp[-2].astVal)));
		(yyval.astVal) = move(ast);
    }
#line 1889 "Parser.cpp"
    break;

  case 52: /* Block: LBRACE BlockItemWrap RBRACE  */
#line 401 "Parser.y"
                                  {
        (yyval.astVal) = (yyvsp[-1].astVal);
    }
#line 1897 "Parser.cpp"
    break;

  case 53: /* BlockItemWrap: BlockItem  */
#line 407 "Parser.y"
                {
        auto ast = new Func();
		ast->Blocks.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		(yyval.astVal) = ast;
    }
#line 1907 "Parser.cpp"
    break;

  case 54: /* BlockItemWrap: BlockItem BlockItemWrap  */
#line 412 "Parser.y"
                              {
        auto ast = reinterpret_cast<Func*>(yyvsp[0].astVal);
		ast->Blocks.insert(ast->Blocks.begin(), shared_ptr<BaseAST>((yyvsp[-1].astVal)));
		(yyval.astVal) = move(ast);
    }
#line 1917 "Parser.cpp"
    break;

  case 55: /* BlockItem: Decl  */
#line 420 "Parser.y"
           {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 1925 "Parser.cpp"
    break;

  case 56: /* BlockItem: Stmt  */
#line 423 "Parser.y"
           {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 1933 "Parser.cpp"
    break;

  case 57: /* Stmt: LVal ASSIGN Exp SEMI  */
#line 429 "Parser.y"
                           {
        auto ast = new Stmt();
		ast->Name = "BinaryOpStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Assign;
		ast->LVal = shared_ptr<BaseAST>((yyvsp[-3].astVal));
		ast->RVal = shared_ptr<BaseAST>((yyvsp[-1].astVal));
		(yyval.astVal) = ast;
    }
#line 1947 "Parser.cpp"
    break;

  case 58: /* Stmt: PRINTF LPAREN STRING RPAREN SEMI  */
#line 438 "Parser.y"
                                       {
        auto ast = new Stmt();
		ast->Name = "PrintfStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Printf;
		ast->IO = *shared_ptr<string>((yyvsp[-2].sVal));
		ast->First_block = vector<shared_ptr<BaseAST>>();
		(yyval.astVal) = ast;
    }
#line 1961 "Parser.cpp"
    break;

  case 59: /* Stmt: PRINTF LPAREN STRING COMMA FuncRParams RPAREN SEMI  */
#line 447 "Parser.y"
                                                         {
        auto ast = new Stmt();
		ast->Name = "PrintfStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Printf;
		ast->IO = *shared_ptr<string>((yyvsp[-4].sVal));
		ast->First_block = move(reinterpret_cast<FuncPrototype*>(yyvsp[-2].astVal)->Params);
		(yyval.astVal) = ast;
    }
#line 1975 "Parser.cpp"
    break;

  case 60: /* Stmt: SCANF LPAREN STRING COMMA FuncRParams RPAREN SEMI  */
#line 456 "Parser.y"
                                                        {
        auto ast = new Stmt();
		ast->Name = "ScanfStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Scanf;
		ast->IO = *shared_ptr<string>((yyvsp[-4].sVal));
		ast->First_block = move(reinterpret_cast<FuncPrototype*>(yyvsp[-2].astVal)->Params);
		(yyval.astVal) = ast;
    }
#line 1989 "Parser.cpp"
    break;

  case 61: /* Stmt: Exp SEMI  */
#line 465 "Parser.y"
               {
        auto ast = new Stmt();
		ast->Name = "ExpStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Expression;
		ast->RVal = shared_ptr<BaseAST>((yyvsp[-1].astVal));
		(yyval.astVal) = ast;
    }
#line 2002 "Parser.cpp"
    break;

  case 62: /* Stmt: Block  */
#line 473 "Parser.y"
            {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2010 "Parser.cpp"
    break;

  case 63: /* Stmt: IF LPAREN Cond RPAREN Stmt  */
#line 476 "Parser.y"
                                 {
        auto ast = new Stmt();
		ast->Name = "IfStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = If;
		ast->Condition = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->First_block = move(reinterpret_cast<Func*>(yyvsp[0].astVal)->Blocks);
		ast->Second_block = vector<shared_ptr<BaseAST>>();
		(yyval.astVal) = ast;
    }
#line 2025 "Parser.cpp"
    break;

  case 64: /* Stmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 486 "Parser.y"
                                           {
        auto ast = new Stmt();
		ast->Name = "IfElseStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = If;
		ast->Condition = shared_ptr<BaseAST>((yyvsp[-4].astVal));
		ast->First_block = move(reinterpret_cast<Func*>(yyvsp[-2].astVal)->Blocks);
		ast->Second_block = move(reinterpret_cast<Func*>(yyvsp[0].astVal)->Blocks);
		(yyval.astVal) = ast;
    }
#line 2040 "Parser.cpp"
    break;

  case 65: /* Stmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 496 "Parser.y"
                                    {
        auto ast = new Stmt();
		ast->Name = "WhileStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = While;
		ast->Condition = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->First_block = move(reinterpret_cast<Func*>(yyvsp[0].astVal)->Blocks);
		(yyval.astVal) = ast;
    }
#line 2054 "Parser.cpp"
    break;

  case 66: /* Stmt: BREAK SEMI  */
#line 505 "Parser.y"
                 {
        auto ast = new Stmt();
		ast->Name = "BreakStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Break;
		ast->RVal = nullptr;
		(yyval.astVal) = ast;
    }
#line 2067 "Parser.cpp"
    break;

  case 67: /* Stmt: CONTINUE SEMI  */
#line 513 "Parser.y"
                    {
        auto ast = new Stmt();
		ast->Name = "ContinueStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Continue;
		ast->RVal = nullptr;
		(yyval.astVal) = ast;
    }
#line 2080 "Parser.cpp"
    break;

  case 68: /* Stmt: RETURN Exp SEMI  */
#line 521 "Parser.y"
                      {
        auto ast = new Stmt();
		ast->Name = "ReturnStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Return;
		ast->RVal = shared_ptr<BaseAST>((yyvsp[-1].astVal));
		(yyval.astVal) = ast;
    }
#line 2093 "Parser.cpp"
    break;

  case 69: /* Stmt: RETURN SEMI  */
#line 529 "Parser.y"
                  {
        auto ast = new Stmt();
		ast->Name = "ReturnStmt";
		ast->AST_type = STMT;
		ast->Stmt_type = Return;
		ast->RVal = nullptr;
		(yyval.astVal) = ast;
    }
#line 2106 "Parser.cpp"
    break;

  case 70: /* Stmt: error SEMI  */
#line 537 "Parser.y"
                 {
		auto ast = new ErrorAST();
		ast->AST_type = ERROR;
		(yyval.astVal) = ast;
	}
#line 2116 "Parser.cpp"
    break;

  case 71: /* Exp: AddExp  */
#line 545 "Parser.y"
             {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2124 "Parser.cpp"
    break;

  case 72: /* Exp: LOrExp  */
#line 548 "Parser.y"
             {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2132 "Parser.cpp"
    break;

  case 73: /* Cond: LOrExp  */
#line 554 "Parser.y"
             {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2140 "Parser.cpp"
    break;

  case 74: /* LVal: IDENTIFIER  */
#line 560 "Parser.y"
                 {
        auto ast = new Variable();
		ast->AST_type = VARIABLE;
		ast->Var_name = *shared_ptr<string>((yyvsp[0].sVal));
		ast->Length = vector<shared_ptr<BaseAST>>();
		(yyval.astVal) = ast;
    }
#line 2152 "Parser.cpp"
    break;

  case 75: /* LVal: IDENTIFIER ExpWrap  */
#line 567 "Parser.y"
                         {
        auto ast = new Variable();
		ast->AST_type = VARIABLE;
		ast->Var_name = *shared_ptr<string>((yyvsp[-1].sVal));
		ast->Length = move(reinterpret_cast<Variable*>(yyvsp[0].astVal)->Length);
		(yyval.astVal) = ast;
    }
#line 2164 "Parser.cpp"
    break;

  case 76: /* LVal: IDENTIFIER DOT IDENTIFIER  */
#line 574 "Parser.y"
                                {
        auto ast = new Variable();
		ast->AST_type = VARIABLE;
		ast->Var_name = *shared_ptr<string>((yyvsp[-2].sVal));
		ast->Length = vector<shared_ptr<BaseAST>>();
		ast->Member_name = *shared_ptr<string>((yyvsp[0].sVal));
		(yyval.astVal) = ast;
    }
#line 2177 "Parser.cpp"
    break;

  case 77: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 585 "Parser.y"
                        {
        (yyval.astVal) = (yyvsp[-1].astVal);
    }
#line 2185 "Parser.cpp"
    break;

  case 78: /* PrimaryExp: LVal  */
#line 588 "Parser.y"
           {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2193 "Parser.cpp"
    break;

  case 79: /* PrimaryExp: Number  */
#line 591 "Parser.y"
             {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "Number";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		ast->Right_exp = nullptr;
		ast->Operator = "";
		(yyval.astVal) = ast;
    }
#line 2207 "Parser.cpp"
    break;

  case 80: /* Number: INTERGER  */
#line 603 "Parser.y"
               {
        auto ast = new FinalExp();
		ast->Name = "IntConst";
		ast->AST_type = FINALEXP;
		ast->Exp_type = Int;
		ast->Number = (yyvsp[0].iVal);
		(yyval.astVal) = ast;
    }
#line 2220 "Parser.cpp"
    break;

  case 81: /* Number: REAL  */
#line 611 "Parser.y"
           {
        auto ast = new FinalExp();
		ast->Name = "DoubleConst";
		ast->AST_type = FINALEXP;
		ast->Exp_type = Double;
		ast->Number = (yyvsp[0].dVal);
		(yyval.astVal) = ast;
    }
#line 2233 "Parser.cpp"
    break;

  case 82: /* UnaryExp: PrimaryExp  */
#line 622 "Parser.y"
                 {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2241 "Parser.cpp"
    break;

  case 83: /* UnaryExp: IDENTIFIER LPAREN RPAREN  */
#line 625 "Parser.y"
                               {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Name = "FuncCall";
		ast->Func_name = *shared_ptr<string>((yyvsp[-2].sVal));
		(yyval.astVal) = ast;
    }
#line 2253 "Parser.cpp"
    break;

  case 84: /* UnaryExp: IDENTIFIER LPAREN FuncRParams RPAREN  */
#line 632 "Parser.y"
                                           {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Name = "FuncCall";
		ast->Func_name = *shared_ptr<string>((yyvsp[-3].sVal));
		ast->Params = move(reinterpret_cast<FuncPrototype*>(yyvsp[-1].astVal)->Params);
		(yyval.astVal) = ast;
    }
#line 2266 "Parser.cpp"
    break;

  case 85: /* UnaryExp: UnaryOp UnaryExp  */
#line 640 "Parser.y"
                       { }
#line 2272 "Parser.cpp"
    break;

  case 86: /* UnaryOp: SUB  */
#line 644 "Parser.y"
          { }
#line 2278 "Parser.cpp"
    break;

  case 87: /* UnaryOp: ADD  */
#line 645 "Parser.y"
          { }
#line 2284 "Parser.cpp"
    break;

  case 88: /* UnaryOp: NOT  */
#line 646 "Parser.y"
          { }
#line 2290 "Parser.cpp"
    break;

  case 89: /* FuncRParams: Exp  */
#line 650 "Parser.y"
          {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Params.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		(yyval.astVal) = ast;
    }
#line 2301 "Parser.cpp"
    break;

  case 90: /* FuncRParams: Exp FuncRParamsWrap  */
#line 656 "Parser.y"
                          {
        auto ast = reinterpret_cast<FuncPrototype*>(yyvsp[0].astVal);
		ast->Params.insert(ast->Params.begin(), shared_ptr<BaseAST>((yyvsp[-1].astVal)));
		(yyval.astVal) = ast;
    }
#line 2311 "Parser.cpp"
    break;

  case 91: /* FuncRParamsWrap: COMMA Exp  */
#line 664 "Parser.y"
                {
        auto ast = new FuncPrototype();
		ast->AST_type = FUNCPROTO;
		ast->Params.push_back(shared_ptr<BaseAST>((yyvsp[0].astVal)));
		(yyval.astVal) = ast;
    }
#line 2322 "Parser.cpp"
    break;

  case 92: /* FuncRParamsWrap: COMMA Exp FuncRParamsWrap  */
#line 670 "Parser.y"
                                {
        auto ast = reinterpret_cast<FuncPrototype*>(yyvsp[0].astVal);
		ast->Params.insert(ast->Params.begin(), shared_ptr<BaseAST>((yyvsp[-1].astVal)));
		(yyval.astVal) = ast;
    }
#line 2332 "Parser.cpp"
    break;

  case 93: /* MulExp: UnaryExp  */
#line 678 "Parser.y"
               {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2340 "Parser.cpp"
    break;

  case 94: /* MulExp: MulExp MUL UnaryExp  */
#line 681 "Parser.y"
                          {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "MulExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		ast->Operator = "*";
		(yyval.astVal) = ast;
    }
#line 2354 "Parser.cpp"
    break;

  case 95: /* MulExp: MulExp DIV UnaryExp  */
#line 690 "Parser.y"
                          {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "MulExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		ast->Operator = "/";
		(yyval.astVal) = ast;
    }
#line 2368 "Parser.cpp"
    break;

  case 96: /* MulExp: MulExp MOD UnaryExp  */
#line 699 "Parser.y"
                          {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "MulExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		ast->Operator = "%";
		(yyval.astVal) = ast;
    }
#line 2382 "Parser.cpp"
    break;

  case 97: /* AddExp: MulExp  */
#line 711 "Parser.y"
             {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2390 "Parser.cpp"
    break;

  case 98: /* AddExp: AddExp ADD MulExp  */
#line 714 "Parser.y"
                        {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "AddExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		ast->Operator = "+";
		(yyval.astVal) = ast;
    }
#line 2404 "Parser.cpp"
    break;

  case 99: /* AddExp: AddExp SUB MulExp  */
#line 723 "Parser.y"
                        {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "AddExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		ast->Operator = "-";
		(yyval.astVal) = ast;
    }
#line 2418 "Parser.cpp"
    break;

  case 100: /* RelExp: AddExp  */
#line 735 "Parser.y"
             {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2426 "Parser.cpp"
    break;

  case 101: /* RelExp: RelExp LT AddExp  */
#line 738 "Parser.y"
                       {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "RelExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Operator = "<";
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 2440 "Parser.cpp"
    break;

  case 102: /* RelExp: RelExp GT AddExp  */
#line 747 "Parser.y"
                       {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "RelExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Operator = ">";
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 2454 "Parser.cpp"
    break;

  case 103: /* RelExp: RelExp LE AddExp  */
#line 756 "Parser.y"
                       {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "RelExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Operator = "<=";
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 2468 "Parser.cpp"
    break;

  case 104: /* RelExp: RelExp GE AddExp  */
#line 765 "Parser.y"
                       {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "RelExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Operator = ">=";
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 2482 "Parser.cpp"
    break;

  case 105: /* EqExp: RelExp  */
#line 777 "Parser.y"
             {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2490 "Parser.cpp"
    break;

  case 106: /* EqExp: EqExp EQ RelExp  */
#line 780 "Parser.y"
                      {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "EqExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Operator = "==";
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 2504 "Parser.cpp"
    break;

  case 107: /* EqExp: EqExp NE RelExp  */
#line 789 "Parser.y"
                      {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "EqExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Operator = "!=";
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 2518 "Parser.cpp"
    break;

  case 108: /* LAndExp: EqExp  */
#line 801 "Parser.y"
            {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2526 "Parser.cpp"
    break;

  case 109: /* LAndExp: LAndExp AND EqExp  */
#line 804 "Parser.y"
                        {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "LAndExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Operator = "&&";
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 2540 "Parser.cpp"
    break;

  case 110: /* LOrExp: LAndExp  */
#line 816 "Parser.y"
              {
        (yyval.astVal) = (yyvsp[0].astVal);
    }
#line 2548 "Parser.cpp"
    break;

  case 111: /* LOrExp: LOrExp OR LAndExp  */
#line 819 "Parser.y"
                        {
        auto ast = new Exp();
		ast->AST_type = EXP;
		ast->Name = "LOrExp";
		ast->Left_exp = shared_ptr<BaseAST>((yyvsp[-2].astVal));
		ast->Operator = "||";
		ast->Right_exp = shared_ptr<BaseAST>((yyvsp[0].astVal));
		(yyval.astVal) = ast;
    }
#line 2562 "Parser.cpp"
    break;


#line 2566 "Parser.cpp"

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

#line 831 "Parser.y"


void yyerror(shared_ptr<BaseAST> &ast, const char *s) {
	cerr << "error: " << s << endl;
}

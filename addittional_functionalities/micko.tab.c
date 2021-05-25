/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "micko.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  
  int lab_num = -1;

  int left_to_increment[128];
  int in_expression = 0;

  int* parameter_map[128];
  int error_count = 0;
  int warning_count = 0;
  
  int var_num = 0;
  int par_num = 0; 

  int fun_idx = -1;
  int fcall_idx = -1;
  int type_capture = 0;
  int func_type_capture = 0;
  int return_flag = 0;

  int in_select = 0;
  int select_counter = 0;
  char* select_map[128];

  int in_para = 0;
  int para_iterator_map[128];
  int para_count = 0;
  int para_count_map[128];

  int row_counter = 0;
  int switch_exp_is_declared = 1;
  int switch_depth = 0;
  int switch_count = 0;
  int otherwise_exists[CHAR_BUFFER_LENGTH];
  int switch_depth_map[CHAR_BUFFER_LENGTH];

  int map_of_depth_updated_literals[CHAR_BUFFER_LENGTH][CHAR_BUFFER_LENGTH];  // inicijalizuj sve na 0
  int num_of_updated_literals = 0;
  int count_of_depth_updated_literals[CHAR_BUFFER_LENGTH];
  int switch_label_map[CHAR_BUFFER_LENGTH][CHAR_BUFFER_LENGTH];

  int block_depth = 0;
  int block_counter[128];
  int has_outer_vars = 0;
  int did_declaration = 0;

  int variable_map[128];
  int arg_counter = 0;
  int id_index_capture = -1;
  int init_valid = 1;
  int in_assignment = 0;

  int parameters_to_be_generated[128];

  int conditional_operator_counter = 0;

  int while_counter = 0;
  int while_depth = 0;

  int offset_capture = -1;

  FILE *output;

#line 149 "micko.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_MICKO_TAB_H_INCLUDED
# define YY_YY_MICKO_TAB_H_INCLUDED
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
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _UINT_NUMBER = 264,
    _LPAREN = 265,
    _RPAREN = 266,
    _LBRACKET = 267,
    _RBRACKET = 268,
    _LSQBRACKET = 269,
    _RSQBRACKET = 270,
    _ASSIGN = 271,
    _SEMICOLON = 272,
    _AROP = 273,
    _RELOP = 274,
    _UNOP = 275,
    _SELECT = 276,
    _COMMA = 277,
    _FROM = 278,
    _WHERE = 279,
    _PARA = 280,
    _EN = 281,
    _SWITCH = 282,
    _CASE = 283,
    _BREAK = 284,
    _OTHERWISE = 285,
    _COLON = 286,
    _WHILE = 287,
    _QMARK = 288,
    ONLY_IF = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 80 "micko.y"

  int i;
  char *s;

#line 241 "micko.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MICKO_TAB_H_INCLUDED  */



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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   135,   136,   140,   155,   156,   161,   160,
     203,   204,   207,   208,   211,   233,   232,   244,   245,   250,
     249,   259,   260,   291,   292,   310,   331,   375,   422,   423,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     441,   446,   440,   457,   456,   517,   518,   523,   522,   546,
     547,   554,   556,   555,   568,   567,   621,   621,   640,   650,
     639,   678,   677,   726,   727,   731,   732,   758,   783,   784,
     787,   788,   802,   808,   810,   811,   812,   827,   862,   865,
     871,   870,   902,   903,   906,   907,   910,   925,   928,   934,
     939,   933,   952,   962,   974
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_LSQBRACKET", "_RSQBRACKET", "_ASSIGN", "_SEMICOLON",
  "_AROP", "_RELOP", "_UNOP", "_SELECT", "_COMMA", "_FROM", "_WHERE",
  "_PARA", "_EN", "_SWITCH", "_CASE", "_BREAK", "_OTHERWISE", "_COLON",
  "_WHILE", "_QMARK", "ONLY_IF", "$accept", "program", "global_list",
  "global_var", "function_list", "function", "$@1", "parameter_list",
  "parameters", "parameter", "body", "$@2", "variable_list", "var_start",
  "$@3", "variable", "declaration", "vars", "statement_list", "statement",
  "while_statement", "@4", "$@5", "switch_statement", "@6", "cases",
  "case", "$@7", "break", "otherwise", "$@8", "para_statement", "$@9",
  "select_statement", "$@10", "compound_statement", "$@11", "$@12",
  "assignment_statement", "$@13", "indexing", "num_exp", "conditional",
  "exp", "half_exp", "full_exp", "unaryop", "literal", "function_call",
  "$@14", "argument_list", "arguments", "argument", "if_statement",
  "if_part", "@15", "$@16", "rel_exp", "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -124,     8,    16,  -124,    26,  -124,    51,  -124,    21,    54,
    -124,  -124,    63,  -124,    76,    74,    77,    72,  -124,  -124,
      78,    76,  -124,  -124,  -124,    93,  -124,  -124,  -124,    90,
       5,    84,  -124,    18,    91,     6,    -4,  -124,  -124,  -124,
      92,    95,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
      86,    96,  -124,   102,  -124,   100,    37,   103,    97,  -124,
      11,  -124,  -124,    42,  -124,    40,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,   104,    99,   105,  -124,   109,   110,   114,
     112,  -124,  -124,    68,   108,  -124,  -124,  -124,  -124,    42,
     116,    99,    25,   115,  -124,    42,   113,  -124,   111,    42,
      93,  -124,    41,   117,  -124,    42,  -124,   119,    58,  -124,
     123,  -124,    42,    98,  -124,  -124,    42,   107,   118,   124,
    -124,  -124,   125,    75,   128,   129,  -124,   134,   127,   107,
      62,    69,  -124,    42,    35,   106,   122,   137,  -124,    68,
    -124,   120,  -124,  -124,  -124,   140,    75,   126,    68,  -124,
      62,    42,   141,    75,    -6,  -124,  -124,  -124,   142,  -124,
    -124,   130,  -124,   121,   138,    68,   131,  -124,  -124,  -124,
    -124,    68,    68,   135,  -124,   139,  -124,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     6,     8,     0,
       7,     5,     0,     8,    10,     0,     0,    11,    12,    14,
       0,     0,    17,     9,    13,    15,    19,    28,    18,     0,
       0,    26,    20,    23,     0,     0,    63,    58,    16,    56,
       0,     0,    40,    29,    38,    37,    36,    35,    30,    31,
       0,     0,    32,    87,    33,     0,     0,     0,     0,    89,
      71,    78,    79,     0,    94,     0,    75,    65,    68,    69,
      74,    70,    72,     0,    61,     0,    17,     0,     0,     0,
       0,    34,    39,     0,     0,    24,    25,    27,    21,     0,
       0,     0,     0,     0,    93,     0,     0,    77,     0,    82,
      59,    26,     0,     0,    43,     0,    88,     0,     0,    90,
       0,    73,     0,     0,    66,    64,     0,    86,     0,    83,
      84,    28,     0,     0,     0,     0,    22,     0,    76,    92,
       0,     0,    81,     0,     0,     0,     0,     0,    41,     0,
      71,     0,    62,    85,    60,     0,     0,     0,     0,    91,
       0,     0,     0,     0,    51,    45,    42,    67,     0,    54,
      47,     0,    46,     0,     0,     0,     0,    52,    44,    57,
      55,     0,     0,    49,    53,     0,    48,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,  -124,  -124,   151,  -124,  -124,  -124,   144,
    -124,  -124,    82,  -124,  -124,  -124,  -124,    83,    38,   -80,
    -124,  -124,  -124,  -124,  -124,  -124,     9,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
     132,   -34,  -124,    71,  -123,  -124,   -30,  -118,   -28,  -124,
    -124,  -124,    34,  -124,  -124,  -124,  -124,   -85,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    12,    16,    17,    18,
      23,    27,    25,    28,    29,    32,    58,    33,    30,    43,
      44,    80,   148,    45,   124,   154,   155,   166,   176,   163,
     172,    46,   165,    47,    77,    48,    76,   121,    49,    98,
      74,   108,    66,    67,    68,    69,    70,    71,    72,    75,
     118,   119,   120,    52,    53,    89,   127,    93,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    65,    51,   106,   109,   136,   -80,   141,     3,    34,
      73,    35,    36,    60,    61,    62,    63,    37,    38,     4,
     125,   -80,   153,    64,   161,    90,    39,   157,   152,    92,
      40,   -63,    41,     8,    56,   160,   111,    42,    11,    34,
      57,    35,    36,    95,   112,    85,    86,    37,   144,    60,
      61,    62,    63,    50,     9,    51,    39,    94,    95,   149,
      40,    13,    41,    57,   122,   117,   158,    42,   156,   140,
      61,    62,    34,    14,    35,    36,    95,   112,   129,    15,
      37,    19,   131,    61,    62,   170,   142,    95,    20,    39,
      22,   173,   174,    40,    21,    41,    26,    31,    55,   117,
      42,    59,    78,    81,    50,    79,    51,    83,    84,    50,
      87,    51,    96,    82,    88,    99,   101,   103,    50,    97,
      51,   104,   105,   107,   110,    95,   113,   116,   115,   132,
     145,   130,   135,   123,   168,    50,   126,    51,   128,   137,
     138,    50,    50,    51,    51,   139,   133,   -64,   146,   147,
     151,   150,   159,   164,   153,   169,   177,    10,   100,   134,
     102,   167,   171,   162,   175,    24,   114,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91
};

static const yytype_int16 yycheck[] =
{
      30,    35,    30,    83,    89,   123,    10,   130,     0,     4,
      14,     6,     7,     7,     8,     9,    10,    12,    13,     3,
     105,    10,    28,    17,    30,    14,    21,   150,   146,    63,
      25,    20,    27,     7,    16,   153,    11,    32,    17,     4,
      22,     6,     7,    18,    19,     8,     9,    12,    13,     7,
       8,     9,    10,    83,     3,    83,    21,    17,    18,   139,
      25,     7,    27,    22,    23,    99,   151,    32,   148,     7,
       8,     9,     4,    10,     6,     7,    18,    19,   112,     3,
      12,     7,   116,     8,     9,   165,    17,    18,    11,    21,
      12,   171,   172,    25,    22,    27,     3,     7,    14,   133,
      32,    10,    10,    17,   134,    10,   134,     5,     8,   139,
       7,   139,     8,    17,    17,    10,     7,     7,   148,    20,
     148,     7,    10,    15,     8,    18,    11,    16,    15,    11,
      24,    33,     7,    16,    13,   165,    17,   165,    15,    11,
      11,   171,   172,   171,   172,    11,    22,    20,    26,    12,
      10,    31,    11,    11,    28,    17,    17,     6,    76,   121,
      77,    31,    31,   154,    29,    21,    95,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,     3,    38,    39,    40,     7,     3,
      40,    17,    41,     7,    10,     3,    42,    43,    44,     7,
      11,    22,    12,    45,    44,    47,     3,    46,    48,    49,
      53,     7,    50,    52,     4,     6,     7,    12,    13,    21,
      25,    27,    32,    54,    55,    58,    66,    68,    70,    73,
      81,    83,    88,    89,    93,    14,    16,    22,    51,    10,
       7,     8,     9,    10,    17,    76,    77,    78,    79,    80,
      81,    82,    83,    14,    75,    84,    71,    69,    10,    10,
      56,    17,    17,     5,     8,     8,     9,     7,    17,    90,
      14,    75,    76,    92,    17,    18,     8,    20,    74,    10,
      47,     7,    52,     7,     7,    10,    54,    15,    76,    92,
       8,    11,    19,    11,    78,    15,    16,    76,    85,    86,
      87,    72,    23,    16,    59,    92,    17,    91,    15,    76,
      33,    76,    11,    22,    53,     7,    82,    11,    11,    11,
       7,    79,    17,    87,    13,    24,    26,    12,    57,    54,
      31,    10,    82,    28,    60,    61,    54,    79,    92,    11,
      82,    30,    61,    64,    11,    67,    62,    31,    13,    17,
      54,    31,    65,    54,    54,    29,    63,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    39,    39,    41,    40,
      42,    42,    43,    43,    44,    46,    45,    47,    47,    49,
      48,    50,    50,    51,    51,    51,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      56,    57,    55,    59,    58,    60,    60,    62,    61,    63,
      63,    64,    65,    64,    67,    66,    69,    68,    71,    72,
      70,    74,    73,    75,    75,    76,    76,    77,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    81,    82,    82,
      84,    83,    85,    85,    86,    86,    87,    88,    88,    90,
      91,    89,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     2,     0,     7,
       0,     1,     1,     3,     2,     0,     5,     0,     2,     0,
       3,     3,     5,     0,     2,     2,     1,     3,     0,     2,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     2,
       0,     0,     7,     0,     9,     1,     2,     0,     6,     0,
       2,     0,     0,     4,     0,    10,     0,    10,     0,     0,
       6,     0,     6,     0,     3,     1,     3,     7,     1,     1,
       1,     1,     1,     3,     1,     1,     4,     3,     1,     1,
       0,     5,     0,     1,     1,     3,     1,     1,     3,     0,
       0,     7,     3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 2:
#line 127 "micko.y"
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1552 "micko.tab.c"
    break;

  case 5:
#line 141 "micko.y"
        {
		int idx = lookup_symbol((yyvsp[-1].s), GVAR); 
		if (idx != NO_INDEX) 
		{
				err("redefinition of '%s'", (yyvsp[-1].s));
		} else {
			insert_symbol((yyvsp[-1].s), GVAR, (yyvsp[-2].i), NO_ATR, NO_ATR);
			code("\n%s:\n\t\tWORD\t1", (yyvsp[-1].s));
		}
	}
#line 1567 "micko.tab.c"
    break;

  case 8:
#line 161 "micko.y"
      {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX){
          int* param_types = (int*) malloc(sizeof(int)*128);
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR);
          parameter_map[fun_idx] = param_types;
        }
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));
        func_type_capture = (yyvsp[-1].i);
        return_flag = 0;
        par_num = 0;

        code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      
        has_outer_vars = 0;
      }
#line 1591 "micko.tab.c"
    break;

  case 9:
#line 181 "micko.y"
      {
        int i = 0;
        for(i = 0; i <= get_last_element(); i+=1){
          if(get_kind(i) == VAR && get_atr2(i) == UNINITIALISED){
            err("uninitialised variable %s", get_name(i));
          }
        }
        clear_symbols(fun_idx + 1);
        var_num = 0;
        if(!return_flag && func_type_capture != VOID){
          warning("Function should return a value;");
        }
        
        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1614 "micko.tab.c"
    break;

  case 10:
#line 203 "micko.y"
    { set_atr1(fun_idx, 0); }
#line 1620 "micko.tab.c"
    break;

  case 14:
#line 212 "micko.y"
      {
        if ( (yyvsp[-1].i) == VOID){
          err("Type of parameter cannot be void.");
        }
        if(lookup_symbol((yyvsp[0].s), PAR) != -1){
          err("Redefinition of parameter %s ", (yyvsp[0].s));
        }
        if(lookup_symbol((yyvsp[0].s), GVAR) != -1){
          err("Parameter cannot have the same name as global variable %s ", (yyvsp[0].s));
        }
        insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++par_num, NO_ATR);
        int num_params = get_atr1(fun_idx);
        int* param_types = parameter_map[fun_idx];
        param_types[num_params] = (yyvsp[-1].i);
        num_params += 1;
        set_atr1(fun_idx, num_params);
      }
#line 1642 "micko.tab.c"
    break;

  case 15:
#line 233 "micko.y"
      {
        if(var_num && did_declaration == 0)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
          block_counter[0] = var_num;
          has_outer_vars = 1;
        code("\n@%s_body:", get_name(fun_idx));
      }
#line 1654 "micko.tab.c"
    break;

  case 19:
#line 250 "micko.y"
    {
      if ( (yyvsp[0].i) == VOID){
        err("Type of variable cannot be void.");
      }
      type_capture = (yyvsp[0].i);
    }
#line 1665 "micko.tab.c"
    break;

  case 21:
#line 259 "micko.y"
                               { row_counter = 0; }
#line 1671 "micko.tab.c"
    break;

  case 22:
#line 261 "micko.y"
    {
      int arr_size = atoi((yyvsp[-2].s));
      if (arr_size < 1){
        err("Size of the array annot be less than 1.");
      }
      code("\n\t\tSUBS\t%%15,$%d,%%15", 4*arr_size);
      did_declaration = 1;

      if(lookup_symbol((yyvsp[-4].s), VAR | PAR | GVAR) != -1){
        err("redefinition of '%s'", (yyvsp[-4].s));
      }

      insert_symbol((yyvsp[-4].s), VAR, type_capture, ++var_num, INITIALISED);
      set_atr2(get_last_element(), INITIALISED);
      int i;
      for (i = 0; i < arr_size; i+=1){
        code("\n\t\tMOV \t$0, ");
        gen_arr_sym_name(get_last_element(), i);
      }
      char* source = malloc(sizeof(char));
      source[0] = '*';
      //strcpy(res, get_name(get_last_element()));
      for (i = 1; i < arr_size; i+=1){
        block_counter[block_depth] += 1;
        insert_symbol(source, VAR, type_capture, ++var_num, INITIALISED);
      }
    }
#line 1703 "micko.tab.c"
    break;

  case 24:
#line 293 "micko.y"
    {
      if(type_capture != INT){
        err("'%s' is not of type INT", (yyvsp[0].s));
      }
      
      code("\n\t\tSUBS\t%%15,$%d,%%15", 4*row_counter);
      did_declaration = 1;

      int i;
      for(i = get_last_element(); i > get_last_element()-row_counter; i -= 1){
        set_atr2(i, INITIALISED);
        code("\n\t\tMOV\t");
        code("$%d, ", atoi((yyvsp[0].s)));
        gen_sym_name(i);
      }
      row_counter = 0;
    }
#line 1725 "micko.tab.c"
    break;

  case 25:
#line 311 "micko.y"
    {
      if(type_capture != UINT){
        err("'%s' is not of type UINT", (yyvsp[0].s));
      }

      code("\n\t\tSUBS\t%%15,$%d,%%15", 4*row_counter);
      did_declaration = 1;

      int i;
      for(i = get_last_element(); i > get_last_element()-row_counter; i -= 1){
        set_atr2(i, INITIALISED);
        code("\n\t\tMOV\t");
        code("$%d, ", atoi((yyvsp[0].s)));
        gen_sym_name(i);
      }
      row_counter = 0;
    }
#line 1747 "micko.tab.c"
    break;

  case 26:
#line 332 "micko.y"
    {
      if(in_select){
        int i;
        for(i = 0; i < 128; i++){
          if(select_map[i] != (char*) -1 && strcmp(select_map[i], (yyvsp[0].s)) == 0){
            err("'%s' used more than once in select statement.", (yyvsp[0].s));
          }
        }
        select_map[select_counter] = (yyvsp[0].s);
        select_counter += 1;
      }

      if (in_para > 0){
        int idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
        int i;
        for (i = 1; i <= in_para; i+=1){
          if (idx == para_iterator_map[i]){
            err("'%s' cannot have the same name as the iterator variable in PARA statement.", (yyvsp[0].s));
          }
        }
      }

      row_counter += 1;
      block_counter[block_depth] += 1;
      int idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
      if(idx == NO_INDEX){
        if(!in_select){
          insert_symbol((yyvsp[0].s), VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }else{
          err("'%s' not defined", (yyvsp[0].s));
        }
      }
      else{
        if(variable_map[idx] == block_depth || lookup_symbol((yyvsp[0].s), PAR) != -1){
          if(!in_select)
            err("redefinition of '%s'", (yyvsp[0].s));
        }else{
          insert_symbol((yyvsp[0].s), VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }
      }
    }
#line 1795 "micko.tab.c"
    break;

  case 27:
#line 376 "micko.y"
    {
      if(in_select){
        int i;
        for(i = 0; i < 128; i++){
          if(select_map[i] != (char*) -1 && strcmp(select_map[i], (yyvsp[0].s)) == 0){
            err("'%s' used more than once in select statement.", (yyvsp[0].s));
          }
        }
        select_map[select_counter] = (yyvsp[0].s);
        select_counter += 1;
      }

      if (in_para > 0){
        int idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
        int i;
        for (i = 1; i <= in_para; i+=1){
          if (idx == para_iterator_map[i]){
            err("'%s' cannot have the same name as the iterator variable in PARA statement.", (yyvsp[0].s));
          }
        }
      }

      row_counter += 1;
      block_counter[block_depth] += 1;
      int idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
      if(idx == NO_INDEX){
        if(!in_select){
          insert_symbol((yyvsp[0].s), VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }else{
          err("'%s' not defined.", (yyvsp[0].s));
        }
      }
      else{
        if(variable_map[idx] == block_depth || lookup_symbol((yyvsp[0].s), PAR) != -1){
          if(!in_select)
            err("redefinition of '%s'", (yyvsp[0].s));
        }else{
          insert_symbol((yyvsp[0].s), VAR, type_capture, ++var_num, UNINITIALISED);
          variable_map[get_last_element()] = block_depth;
        }
      }
    }
#line 1843 "micko.tab.c"
    break;

  case 40:
#line 441 "micko.y"
    {
      (yyval.i) = ++while_counter;
      code("\nwhile_%d_depth_%d:", while_counter, ++while_depth);
    }
#line 1852 "micko.tab.c"
    break;

  case 41:
#line 446 "micko.y"
    {
      code("\n\t\t%s\tend_while_%d_depth_%d", opp_jumps[(yyvsp[-1].i)], while_counter, while_depth);
    }
#line 1860 "micko.tab.c"
    break;

  case 42:
#line 450 "micko.y"
    {
      code("\n\t\tJMP\twhile_%d_depth_%d", (yyvsp[-5].i), while_depth);
      code("\nend_while_%d_depth_%d:", (yyvsp[-5].i), while_depth--);
    }
#line 1869 "micko.tab.c"
    break;

  case 43:
#line 457 "micko.y"
    {
      switch_count += 1;
      (yyval.i) = switch_count;
      switch_exp_is_declared = 1;
      switch_depth += 1;

      switch_depth_map[switch_depth] = switch_count;

      int index;
      index = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
      if(index == NO_INDEX){
        err("'%s' not declared.", (yyvsp[0].s));
        switch_exp_is_declared = 0;
      }
      type_capture = get_type(index);

      code("\n\t\tJMP\tswitch_%d_depth_%d_check", switch_depth_map[switch_depth], switch_depth);
    }
#line 1892 "micko.tab.c"
    break;

  case 44:
#line 475 "micko.y"
    {
      
      code("\n\nswitch_%d_depth_%d_skip_check:", switch_depth_map[switch_depth], switch_depth);
      code("\n\t\tJMP\tswitch_%d_depth_%d_exit", switch_depth_map[switch_depth], switch_depth);
      code("\n\nswitch_%d_depth_%d_check:", switch_depth_map[switch_depth], switch_depth);

      int j;
      int index;
      index = lookup_symbol((yyvsp[-6].s), VAR|PAR|GVAR);

      for(j = 0; j <= get_last_element(); j += 1){
        if(get_kind(j) == LIT && get_atr1(j) == switch_depth && get_atr2(j) == IN_SWITCH && (yyvsp[-5].i) == switch_label_map[j][switch_depth]){
          gen_cmp(index, j);
          code("\n\t\tJEQ\tswitch_%d_depth_%d_case_%d", switch_depth_map[switch_depth], switch_depth, j);
        }
      }
      if(otherwise_exists[switch_depth]){
        code("\n\t\tJMP\tswitch_%d_depth_%d_otherwise", switch_depth_map[switch_depth], switch_depth);
      }
      code("\n\nswitch_%d_depth_%d_exit:", switch_depth_map[switch_depth], switch_depth);
      otherwise_exists[switch_depth] = 0;
      
      switch_depth -= 1;
      
      int i;
      for(i = 0; i <= get_last_element(); i += 1){

        if(get_kind(i) == LIT && get_atr2(i) == IN_SWITCH){
          if (count_of_depth_updated_literals[i] > 1){
            count_of_depth_updated_literals[i] -= 1;
            set_atr1(i, map_of_depth_updated_literals[i][count_of_depth_updated_literals[i] - 1]);
          }
        }
        
        if(get_kind(i) == LIT && get_atr2(i) == IN_SWITCH && switch_depth == 0){
          set_atr1(i, 0);
        }
      }
    }
#line 1936 "micko.tab.c"
    break;

  case 47:
#line 523 "micko.y"
    {
      if(get_type((yyvsp[0].i)) != type_capture && switch_exp_is_declared){
        err("switch constants must be of same type as the switch expression.");
      }
      if (get_atr1((yyvsp[0].i)) == switch_depth && get_atr2((yyvsp[0].i)) == IN_SWITCH && switch_label_map[(yyvsp[0].i)][switch_depth] == switch_depth_map[switch_depth]){
        err("case constants must be unique %s", get_name((yyvsp[0].i)));
      }else{
        int depth_capture = get_atr1((yyvsp[0].i));
        set_atr1((yyvsp[0].i), switch_depth);
        set_atr2((yyvsp[0].i), IN_SWITCH);
        if (get_atr2((yyvsp[0].i)) == IN_SWITCH){
          map_of_depth_updated_literals[(yyvsp[0].i)][count_of_depth_updated_literals[(yyvsp[0].i)]] = switch_depth;
          count_of_depth_updated_literals[(yyvsp[0].i)] += 1;
        }
        switch_label_map[(yyvsp[0].i)][switch_depth] = switch_depth_map[switch_depth];
      }

      code("\n\nswitch_%d_depth_%d_case_%d:", switch_depth_map[switch_depth], switch_depth, (yyvsp[0].i));
    }
#line 1960 "micko.tab.c"
    break;

  case 50:
#line 548 "micko.y"
    {
      code("\n\t\tJMP\tswitch_%d_depth_%d_exit", switch_depth_map[switch_depth], switch_depth);
    }
#line 1968 "micko.tab.c"
    break;

  case 52:
#line 556 "micko.y"
  {
    otherwise_exists[switch_depth] = 1;
    code("\n\nswitch_%d_depth_%d_otherwise:", switch_depth_map[switch_depth], switch_depth);
  }
#line 1977 "micko.tab.c"
    break;

  case 53:
#line 561 "micko.y"
  {
    code("\n\t\tJMP\tswitch_%d_depth_%d_exit", switch_depth_map[switch_depth], switch_depth);
  }
#line 1985 "micko.tab.c"
    break;

  case 54:
#line 568 "micko.y"
    {
      int index;
      in_para += 1;
      index = lookup_symbol((yyvsp[-5].s), VAR | PAR | GVAR);
      if(index == NO_INDEX){ // da li moze biti parametar???
        err("'%s' not declared.", (yyvsp[-5].s));
      }else{
        if(get_type((yyvsp[-3].i)) != get_type(index) || get_type((yyvsp[-1].i)) != get_type(index)){
          err("Iterator '%s' and iterator bounds are not of the same type.", (yyvsp[-5].s));
        }
        set_atr2(index, INITIALISED);
      }
      if (atoi(get_name((yyvsp[-3].i))) >= atoi(get_name((yyvsp[-1].i)))){
        err("Lower iterator bound must be LOWER than the upper iterator bound.");
      }
      para_iterator_map[in_para] = index;

      para_count += 1;
      para_count_map[in_para] = para_count;

      code("\npara_%d_%d_init:", para_count_map[in_para], in_para);
      code("\n\t\tMOV\t");
      gen_sym_name((yyvsp[-3].i));
      code(", ");
      gen_sym_name(index);
      code("\npara_%d_%d_body:", para_count_map[in_para], in_para);
      gen_cmp(index, (yyvsp[-1].i));

      if (get_type(index) == INT){
        code("\n\t\tJGTS\tpara_%d_%d_exit", para_count_map[in_para], in_para);
      } else {
        code("\n\t\tJGTU\tpara_%d_%d_exit", para_count_map[in_para], in_para);
      }
    }
#line 2024 "micko.tab.c"
    break;

  case 55:
#line 603 "micko.y"
    {
      int idx;
      idx = lookup_symbol((yyvsp[-7].s), VAR | PAR | GVAR);
      if (get_type(idx) == INT){
        code("\n\t\tADDS\t");
      } else {
        code("\n\t\tADDU\t");
      }
      gen_sym_name(idx);
      code(", $1, ");
      gen_sym_name(idx);
      code("\n\t\tJMP\tpara_%d_%d_body", para_count_map[in_para], in_para);
      code("\npara_%d_%d_exit:", para_count_map[in_para], in_para);
      in_para -= 1;
    }
#line 2044 "micko.tab.c"
    break;

  case 56:
#line 621 "micko.y"
           {
      in_select = 1; 
      select_counter = 0; 
      int i; 
      for(i = 0; i < 128; i += 1) {
          select_map[i] = (char*) -1;
      } 
    }
#line 2057 "micko.tab.c"
    break;

  case 57:
#line 630 "micko.y"
    {
      in_select = 0;
      if(lookup_symbol((yyvsp[-5].s), VAR|PAR|GVAR) == NO_INDEX){
        err("'%s' not declared.", (yyvsp[-5].s));
      }
    }
#line 2068 "micko.tab.c"
    break;

  case 58:
#line 640 "micko.y"
    { 
      if(has_outer_vars == 0){
        block_counter[0] = 0; 
      }
      
      block_depth += 1; 
      block_counter[block_depth] = 0;
      did_declaration = 0;
    }
#line 2082 "micko.tab.c"
    break;

  case 59:
#line 650 "micko.y"
    {
      if(var_num && did_declaration == 0)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*(block_counter[block_depth]));
    }
#line 2091 "micko.tab.c"
    break;

  case 60:
#line 654 "micko.y"
                            {
      code("\n\t\tADDS\t%%15,$%d,%%15", 4*(block_counter[block_depth]));
      if(block_counter[block_depth] > 0){
        int i;
        for(i = 0; i <= get_last_element(); i+=1){
          if(get_kind(i) == VAR && get_atr2(i) == UNINITIALISED && variable_map[i] == block_depth){
            err("uninitialised variable %s", get_name(i));
          }
        }
        int idx = get_last_element();
        while(block_counter[block_depth] > 0){
          if(get_kind(idx) == VAR){
            block_counter[block_depth] -= 1;
          }
          idx -= 1;
        }
        clear_symbols(idx + 1);
      }
      block_depth -= 1; 
    }
#line 2116 "micko.tab.c"
    break;

  case 61:
#line 678 "micko.y"
      { 
        in_assignment = 1;
        in_expression = 1;
        int j;
        for(j = 0; j < 128; j+=1){
          left_to_increment[j] = -1;
        }
      }
#line 2129 "micko.tab.c"
    break;

  case 62:
#line 687 "micko.y"
      {
        int idx = lookup_symbol((yyvsp[-5].s), VAR|PAR|GVAR);
        id_index_capture = idx;
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-5].s));
        else
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment.");
        if(init_valid == 1){
          set_atr2(idx, INITIALISED);
        }
        in_assignment = 0;
        init_valid = 1;

        int i, j;
        for(i = 0; i < 128; i+=1){
          for(j = 0; j < left_to_increment[i] + 1; j+=1){
            if(get_type(i) == UINT){
              code("\n\t\tADDU\t");
            }else {
              code("\n\t\tADDS\t");
            }
            gen_sym_name(i);
            code(", $1, ");
            gen_sym_name(i);
          }
          left_to_increment[i] = -1;
        }
        in_expression = 0;
        if((yyvsp[-4].i) == -1){
          gen_mov((yyvsp[-1].i), idx);
        } else {
          gen_arr_mov((yyvsp[-1].i), idx, (yyvsp[-4].i));
        }
        
      }
#line 2170 "micko.tab.c"
    break;

  case 63:
#line 726 "micko.y"
                { (yyval.i) = -1; }
#line 2176 "micko.tab.c"
    break;

  case 64:
#line 727 "micko.y"
                                        { (yyval.i) = atoi((yyvsp[-1].s)); }
#line 2182 "micko.tab.c"
    break;

  case 66:
#line 733 "micko.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: arithmetic operation");
        else{
          int t1 = get_type((yyvsp[-2].i));    
          code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
          gen_sym_name((yyvsp[-2].i));
          code(",");
          if(offset_capture < 0){
            gen_sym_name((yyvsp[0].i));
          } else {
            gen_arr_sym_name((yyvsp[0].i), offset_capture);
            offset_capture = -1;
          }
          code(",");
          free_if_reg((yyvsp[0].i));
          free_if_reg((yyvsp[-2].i));
          (yyval.i) = take_reg();
          gen_sym_name((yyval.i));
          set_type((yyval.i), t1);
        }
      }
#line 2209 "micko.tab.c"
    break;

  case 67:
#line 759 "micko.y"
      {
        if (get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i))){
          err("Both alternatives must be of the same type as a target variable.");
        }

        conditional_operator_counter += 1;
        
        code("\n\t\t%s\tsecond_choice_%d", opp_jumps[(yyvsp[-5].i)], conditional_operator_counter);
        (yyval.i) = take_reg();
        code("\n\t\tMOV\t");
        gen_sym_name((yyvsp[-2].i));
        code(", ");
        gen_sym_name((yyval.i));
        code("\n\t\tJMP\tcond_end_%d", conditional_operator_counter);
        code("\nsecond_choice_%d:", conditional_operator_counter);
        code("\n\t\tMOV\t");
        gen_sym_name((yyvsp[0].i));
        code(", ");
        gen_sym_name((yyval.i));
        code("\ncond_end_%d:", conditional_operator_counter);
        set_type((yyval.i), get_type((yyvsp[0].i)));
      }
#line 2236 "micko.tab.c"
    break;

  case 68:
#line 783 "micko.y"
             { (yyval.i) = (yyvsp[0].i); }
#line 2242 "micko.tab.c"
    break;

  case 69:
#line 784 "micko.y"
             { (yyval.i) = (yyvsp[0].i); }
#line 2248 "micko.tab.c"
    break;

  case 71:
#line 789 "micko.y"
      {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
        if(in_assignment){
          if(get_kind((yyval.i)) == VAR && get_atr2((yyval.i)) == UNINITIALISED){
            init_valid = 0;
          }
        }
      }
#line 2263 "micko.tab.c"
    break;

  case 72:
#line 803 "micko.y"
      {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      }
#line 2272 "micko.tab.c"
    break;

  case 73:
#line 809 "micko.y"
      { (yyval.i) = (yyvsp[-1].i); }
#line 2278 "micko.tab.c"
    break;

  case 76:
#line 813 "micko.y"
    {
      (yyval.i) = lookup_symbol((yyvsp[-3].s), VAR);
      if((yyval.i) == NO_INDEX)
        err("'%s' undeclared", (yyvsp[-3].s));
      if(in_assignment){
        if(get_kind((yyval.i)) == VAR && get_atr2((yyval.i)) == UNINITIALISED){
          init_valid = 0;
        }
      }
      offset_capture = atoi((yyvsp[-1].s));
    }
#line 2294 "micko.tab.c"
    break;

  case 77:
#line 828 "micko.y"
    {
      if(lookup_symbol((yyvsp[-2].s), FUN) != NO_INDEX){
          err("Postincrement may be only used on variables, not functions.");
      }
      (yyval.i) = lookup_symbol((yyvsp[-2].s), VAR|PAR|GVAR);
      if((yyval.i) == NO_INDEX){
          err("%s is not declared previously as a variable", (yyvsp[-2].s));
      }
      
      if(in_expression == 1){
        left_to_increment[(yyval.i)] += 1;
      }else{
        if(get_type((yyval.i)) == UINT){
              code("\n\t\tADDU\t");
            }else {
              code("\n\t\tADDS\t");
            }
            if(offset_capture < 0){
              gen_sym_name((yyval.i));
              code(", $1, ");
              gen_sym_name((yyval.i));
            }else{
              gen_arr_sym_name((yyval.i), offset_capture);
              code(", $1, ");
              gen_arr_sym_name((yyval.i), offset_capture);
              offset_capture = -1;
            }
      }
      
      
    }
#line 2330 "micko.tab.c"
    break;

  case 78:
#line 863 "micko.y"
      { (yyval.i) = insert_literal((yyvsp[0].s), INT);}
#line 2336 "micko.tab.c"
    break;

  case 79:
#line 866 "micko.y"
      { (yyval.i) = insert_literal((yyvsp[0].s), UINT);}
#line 2342 "micko.tab.c"
    break;

  case 80:
#line 871 "micko.y"
      {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));

        arg_counter = 0;
      }
#line 2354 "micko.tab.c"
    break;

  case 81:
#line 879 "micko.y"
      {
        if(get_atr1(fcall_idx) != arg_counter)
          err("wrong number of args to function '%s'", 
              get_name(fcall_idx));
        
        int i = 0;
        for(i = arg_counter - 1; i >= 0; i -= 1){
          code("\n\t\tPUSH\t");
          gen_sym_name(parameters_to_be_generated[i]);
        }

        code("\n\t\tCALL\t%s", get_name(fcall_idx));
        if(arg_counter > 0)
          code("\n\t\tADDS\t%%15,$%d,%%15", arg_counter * 4);

        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;

        arg_counter = 0;
      }
#line 2379 "micko.tab.c"
    break;

  case 86:
#line 911 "micko.y"
    { 
      if(parameter_map[fcall_idx][arg_counter] != get_type((yyvsp[0].i)))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      arg_counter += 1;


      parameters_to_be_generated[arg_counter - 1] = (yyvsp[0].i);
      free_if_reg((yyvsp[0].i));
      (yyval.i) = 1;  // ovo ne treba ali neka stoji
    }
#line 2395 "micko.tab.c"
    break;

  case 87:
#line 926 "micko.y"
      { code("\n@exit%d:", (yyvsp[0].i)); }
#line 2401 "micko.tab.c"
    break;

  case 88:
#line 929 "micko.y"
      { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 2407 "micko.tab.c"
    break;

  case 89:
#line 934 "micko.y"
      {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 2416 "micko.tab.c"
    break;

  case 90:
#line 939 "micko.y"
      {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i)); 
        code("\n@true%d:", (yyvsp[-1].i));
      }
#line 2425 "micko.tab.c"
    break;

  case 91:
#line 944 "micko.y"
      {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 2435 "micko.tab.c"
    break;

  case 92:
#line 953 "micko.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
      }
#line 2446 "micko.tab.c"
    break;

  case 93:
#line 963 "micko.y"
      {
        return_flag = 1;
        if(func_type_capture == VOID){
          err("Void function should not return a value.");
        }
        else if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");

        gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
#line 2462 "micko.tab.c"
    break;

  case 94:
#line 975 "micko.y"
    {
      if(func_type_capture == INT || func_type_capture == UINT){
        warning("Function should return a value.");
      }
      code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
    }
#line 2473 "micko.tab.c"
    break;


#line 2477 "micko.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 983 "micko.y"


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}


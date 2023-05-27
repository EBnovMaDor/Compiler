/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "Parser.y"

    #include <string>
    #include <iostream>
    #include <memory>
    #include <vector>
    #include "AST.hpp"
    using namespace std;

    int yylex();
    void yyerror(shared_ptr<BaseAST> &ast, const char *s);

#line 61 "Parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    COMMA = 258,                   /* COMMA  */
    ELLIPSIS = 259,                /* ELLIPSIS  */
    DOT = 260,                     /* DOT  */
    SEMI = 261,                    /* SEMI  */
    ARROW = 262,                   /* ARROW  */
    QUES = 263,                    /* QUES  */
    COLON = 264,                   /* COLON  */
    LPAREN = 265,                  /* LPAREN  */
    RPAREN = 266,                  /* RPAREN  */
    LBRACKET = 267,                /* LBRACKET  */
    RBRACKET = 268,                /* RBRACKET  */
    LBRACE = 269,                  /* LBRACE  */
    RBRACE = 270,                  /* RBRACE  */
    EQ = 271,                      /* EQ  */
    GE = 272,                      /* GE  */
    LE = 273,                      /* LE  */
    GT = 274,                      /* GT  */
    LT = 275,                      /* LT  */
    NE = 276,                      /* NE  */
    NOT = 277,                     /* NOT  */
    ASSIGN = 278,                  /* ASSIGN  */
    AND = 279,                     /* AND  */
    BANDEQ = 280,                  /* BANDEQ  */
    BAND = 281,                    /* BAND  */
    OR = 282,                      /* OR  */
    BOREQ = 283,                   /* BOREQ  */
    BOR = 284,                     /* BOR  */
    BXOR = 285,                    /* BXOR  */
    BXOREQ = 286,                  /* BXOREQ  */
    BNOT = 287,                    /* BNOT  */
    AADD = 288,                    /* AADD  */
    ADDEQ = 289,                   /* ADDEQ  */
    ADD = 290,                     /* ADD  */
    SSUB = 291,                    /* SSUB  */
    SUBEQ = 292,                   /* SUBEQ  */
    SUB = 293,                     /* SUB  */
    MULEQ = 294,                   /* MULEQ  */
    MUL = 295,                     /* MUL  */
    DIVEQ = 296,                   /* DIVEQ  */
    DIV = 297,                     /* DIV  */
    MOD = 298,                     /* MOD  */
    MODEQ = 299,                   /* MODEQ  */
    STRUCT = 300,                  /* STRUCT  */
    TYPEDEF = 301,                 /* TYPEDEF  */
    CONST = 302,                   /* CONST  */
    RETURN = 303,                  /* RETURN  */
    IF = 304,                      /* IF  */
    ELSE = 305,                    /* ELSE  */
    FOR = 306,                     /* FOR  */
    WHILE = 307,                   /* WHILE  */
    CONTINUE = 308,                /* CONTINUE  */
    BREAK = 309,                   /* BREAK  */
    SWITCH = 310,                  /* SWITCH  */
    CASE = 311,                    /* CASE  */
    DEFAULT = 312,                 /* DEFAULT  */
    TRUE = 313,                    /* TRUE  */
    FALSE = 314,                   /* FALSE  */
    BOOL = 315,                    /* BOOL  */
    SHORT = 316,                   /* SHORT  */
    LONG = 317,                    /* LONG  */
    INT = 318,                     /* INT  */
    FLOAT = 319,                   /* FLOAT  */
    DOUBLE = 320,                  /* DOUBLE  */
    CHAR = 321,                    /* CHAR  */
    VOID = 322,                    /* VOID  */
    SQUOTE = 323,                  /* SQUOTE  */
    DQUOTE = 324,                  /* DQUOTE  */
    PRINTF = 325,                  /* PRINTF  */
    SCANF = 326,                   /* SCANF  */
    INTERGER = 327,                /* INTERGER  */
    IDENTIFIER = 328,              /* IDENTIFIER  */
    STRING = 329,                  /* STRING  */
    REAL = 330,                    /* REAL  */
    CHARACTER = 331                /* CHARACTER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "Parser.y"

    int iVal;
    double dVal;
    char cVal;
    string *sVal;
    BaseAST *astVal;

#line 162 "Parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (shared_ptr<BaseAST> &ast);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

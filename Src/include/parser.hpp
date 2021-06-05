/* A Bison parser, made by GNU Bison 3.7.4.  */

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

#ifndef YY_YY_INCLUDE_PARSER_HPP_INCLUDED
# define YY_YY_INCLUDE_PARSER_HPP_INCLUDED
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
    COLON = 258,                   /* COLON  */
    SEMICOLON = 259,               /* SEMICOLON  */
    COMMA = 260,                   /* COMMA  */
    LEFTP = 261,                   /* LEFTP  */
    RIGHTP = 262,                  /* RIGHTP  */
    LEFTB = 263,                   /* LEFTB  */
    RIGHTB = 264,                  /* RIGHTB  */
    LEFTSB = 265,                  /* LEFTSB  */
    RIGHTSB = 266,                 /* RIGHTSB  */
    MAIN = 267,                    /* MAIN  */
    RETURN = 268,                  /* RETURN  */
    FOR = 269,                     /* FOR  */
    IN = 270,                      /* IN  */
    TO = 271,                      /* TO  */
    WHILE = 272,                   /* WHILE  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    BREAK = 275,                   /* BREAK  */
    IDENTIFIER = 276,              /* IDENTIFIER  */
    STRING_VALUE = 277,            /* STRING_VALUE  */
    INT = 278,                     /* INT  */
    FLOAT = 279,                   /* FLOAT  */
    BOOL = 280,                    /* BOOL  */
    VOID = 281,                    /* VOID  */
    STRING = 282,                  /* STRING  */
    INTEGER_VALUE = 283,           /* INTEGER_VALUE  */
    FLOAT_VALUE = 284,             /* FLOAT_VALUE  */
    BOOL_VALUE = 285,              /* BOOL_VALUE  */
    FALSE = 286,                   /* FALSE  */
    TRUE = 287,                    /* TRUE  */
    ASSIGN = 288,                  /* ASSIGN  */
    GT = 289,                      /* GT  */
    LT = 290,                      /* LT  */
    EQ = 291,                      /* EQ  */
    NEQ = 292,                     /* NEQ  */
    EGT = 293,                     /* EGT  */
    ELT = 294,                     /* ELT  */
    AND = 295,                     /* AND  */
    OR = 296,                      /* OR  */
    ADD = 297,                     /* ADD  */
    SUB = 298,                     /* SUB  */
    MUL = 299,                     /* MUL  */
    DIV = 300,                     /* DIV  */
    POW = 301                      /* POW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "yacc.ypp"

	Block* block;

	int dataType;
	int intval;
	Decl* decl;
	DeclList* declList;
	Stmt* stmt;
	StmtList* stmtList;
	Expr* expr;
	ExprList* exprList;

	FuncBody* funcbody;
	FuncImpl* funcImpl;
	FuncList* funcList;
	char Char;
	char Op;
	char* valueStr;
    string* Str;

#line 131 "../include/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_PARSER_HPP_INCLUDED  */

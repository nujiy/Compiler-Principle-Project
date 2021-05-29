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
    SEMICOLON = 258,               /* SEMICOLON  */
    COMMA = 259,                   /* COMMA  */
    LEFTP = 260,                   /* LEFTP  */
    RIGHTP = 261,                  /* RIGHTP  */
    LEFTB = 262,                   /* LEFTB  */
    RIGHTB = 263,                  /* RIGHTB  */
    LEFTSB = 264,                  /* LEFTSB  */
    RIGHTSB = 265,                 /* RIGHTSB  */
    MAIN = 266,                    /* MAIN  */
    RETURN = 267,                  /* RETURN  */
    FOR = 268,                     /* FOR  */
    WHILE = 269,                   /* WHILE  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    IDENTIFIER = 272,              /* IDENTIFIER  */
    INT = 273,                     /* INT  */
    FLOAT = 274,                   /* FLOAT  */
    BOOL = 275,                    /* BOOL  */
    INTEGER_VALUE = 276,           /* INTEGER_VALUE  */
    FLOAT_VALUE = 277,             /* FLOAT_VALUE  */
    BOOL_VALUE = 278,              /* BOOL_VALUE  */
    ASSIGN = 279,                  /* ASSIGN  */
    GT = 280,                      /* GT  */
    LT = 281,                      /* LT  */
    EQ = 282,                      /* EQ  */
    NEQ = 283,                     /* NEQ  */
    EGT = 284,                     /* EGT  */
    ELT = 285,                     /* ELT  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    ADD = 288,                     /* ADD  */
    SUB = 289,                     /* SUB  */
    MUL = 290,                     /* MUL  */
    DIV = 291,                     /* DIV  */
    POW = 292                      /* POW  */
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

#line 122 "../include/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_PARSER_HPP_INCLUDED  */

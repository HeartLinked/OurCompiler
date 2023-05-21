/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_ROOT_COMPILER_FLEX_BISON_PART1_BUILD_SYSY_TAB_HPP_INCLUDED
# define YY_YY_ROOT_COMPILER_FLEX_BISON_PART1_BUILD_SYSY_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "/root/compiler/Flex-Bison-Part1/src/sysy.y"

  #include <memory>
  #include <string>
  #include "AST.hpp"

#line 54 "/root/compiler/Flex-Bison-Part1/build/sysy.tab.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    RETURN = 259,
    AND = 260,
    OR = 261,
    EQ = 262,
    NE = 263,
    LE = 264,
    GE = 265,
    CONST = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    CONTINUE = 270,
    BREAK = 271,
    IDENT = 272,
    INT_CONST = 273
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "/root/compiler/Flex-Bison-Part1/src/sysy.y"

  std::string *str_val;
  int int_val;
  BaseAST *ast_val;   // AST
  vector<std::unique_ptr<BaseAST>> *ast_list_val; // AST list

#line 91 "/root/compiler/Flex-Bison-Part1/build/sysy.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::unique_ptr<BaseAST> &ast);

#endif /* !YY_YY_ROOT_COMPILER_FLEX_BISON_PART1_BUILD_SYSY_TAB_HPP_INCLUDED  */

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

#ifndef YY_GLFX_GLFXLALRPARSER_HPP_INCLUDED
# define YY_GLFX_GLFXLALRPARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef GLFXDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define GLFXDEBUG 1
#  else
#   define GLFXDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define GLFXDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined GLFXDEBUG */
#if GLFXDEBUG
extern int glfxdebug;
#endif

/* Token type.  */
#ifndef GLFXTOKENTYPE
# define GLFXTOKENTYPE
  enum glfxtokentype
  {
    SHADER = 258,
    PROGRAM = 259,
    INTERFACE = 260,
    IDENTIFIER = 261,
    STORAGEQ = 262,
    GL_FRAGDEPTH = 263,
    STORAGET = 264,
    SHADER_TYPE = 265,
    LP = 266,
    RP = 267,
    LB = 268,
    RB = 269,
    SC = 270,
    COMMA = 271,
    COLON = 272,
    EQUALS = 273,
    NUM = 274,
    INCLUDE = 275,
    SAMPLER = 276,
    FLOAT = 277,
    EMPTY_ARRAY_BRACKETS = 278
  };
#endif

/* Value type.  */
#if ! defined GLFXSTYPE && ! defined GLFXSTYPE_IS_DECLARED
typedef glfxstype GLFXSTYPE;
# define GLFXSTYPE_IS_TRIVIAL 1
# define GLFXSTYPE_IS_DECLARED 1
#endif


extern GLFXSTYPE glfxlval;

int glfxparse (void);

#endif /* !YY_GLFX_GLFXLALRPARSER_HPP_INCLUDED  */

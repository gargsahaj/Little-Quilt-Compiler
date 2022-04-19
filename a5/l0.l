%{
#include<string>
#include<iostream>

using namespace std;

#include "parse.tab.h"

%}
%option noyywrap
%%
"turn" {yylval.name=new string(yytext);return TURN;}

"sew"  {yylval.name=new string(yytext);return SEW;}

"a"    {yylval.name=new string(yytext);return A;}

"b"    {yylval.name=new string(yytext);return B;}

"hdRow" {yylval.name=new string(yytext);return HDROW;}

"tlRows" {yylval.name=new string(yytext);return TLROWS;}

"hdCol" {yylval.name=new string(yytext);return HDCOL;}

"tlCols" {yylval.name=new string(yytext);return TLCOLS;}

"("    {yylval.name=new string(yytext);return OB;}

")"    {yylval.name=new string(yytext);return CB;}

"let"  {yylval.name=new string(yytext);return LET;}

"in"   {yylval.name=new string(yytext);return IN;}

"end"   {yylval.name=new string(yytext);return END;}

"fun"   {yylval.name=new string(yytext);return FUN;}

"val"   {yylval.name=new string(yytext);return VAL;}

"="   {yylval.name=new string(yytext);return ASSIGN;}

[a-zA-Z_][0-9a-zA-Z_]*   {yylval.name=new string(yytext);return ID;}

","    {yylval.name=new string(yytext);return COM;}

[ \t\n]  ;

.      {return SYNERROR;}
%%

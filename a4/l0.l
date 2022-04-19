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
","    {yylval.name=new string(yytext);return COM;}
[ \t]  ;
.      {return SYNERROR;}
%%

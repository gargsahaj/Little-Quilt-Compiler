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
"("    {yylval.name=new string(yytext);return OB;}
")"    {yylval.name=new string(yytext);return CB;}
","    {yylval.name=new string(yytext);return COM;}
[ \t]  ;
.      {return SYNERROR;}
%%

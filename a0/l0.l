%{
	#include<stdio.h>
	#include"parse.tab.h"
%}
%option noyywrap
%%
"turn" {return TURN;}
"sew"  {return SEW;}
"a"    {return A;}
"b"    {return B;}
"("    {return OB;}
")"    {return CB;}
","    {return COM;}
.      ;
%%

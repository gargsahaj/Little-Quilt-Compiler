%{
#include<string>
#include<iostream>

using namespace std;

#include "parse.tab.h"

%}
%option noyywrap

digit  [0-9]
ws	[ \t\n]*
operator [-+*/=;]
letter [a-zA-Z_]

%%
{digit}+ 	{ 	
		        return NUM; 
		}

{operator}	{	return yytext[0];	}

{letter}({letter}|{digit})* {
			return ID;
		}
		
{ws}		;
.	{ 	
		string error_message;
		error_message =  "Illegal character `" + *yytext;
		error_message += "' on line " + yylineno;
	}


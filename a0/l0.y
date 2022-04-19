%{
#include<stdio.h>
#include<iostream>
using namespace std;
extern "C" void yyerror(char *s);

extern int yylex(void);
%}
%token TURN
%token SEW
%token A
%token B
%token OB
%token CB
%token COM
%start Start
%%
Start : Expr;
Expr : 		A
		| B
		;
Expr : TURN OB Expr CB 
		{cout<<"Turn\n";
		}
		|
		SEW OB Expr COM Expr CB 
		{cout<<"Sew\n";
		}
		;


%%
int main(void){
	yyparse();
}

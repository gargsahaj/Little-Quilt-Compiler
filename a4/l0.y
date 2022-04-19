%{
#include"l0.h"
#include"matrix.h"
#include"quadruple.h"
# include <stdio.h>
# include <iostream>
# include <string>
extern "C" void yyerror(char *s);

extern int yylex(void);

using namespace std;

%}
%union{
string *name;
class AST *ast;
}
%token SYNERROR
%token <name> HDROW
%token <name> TLROWS
%token <name> HDCOL
%token <name> TLCOLS
%token <name> TURN
%token <name> SEW
%token <name> A
%token <name> B
%token <name> OB
%token <name> CB
%token <name> COM
%type <ast> Expr
%start Start
%%
Start : Expr {  $1->make_cpp().write_list();
	};
Expr :  TURN OB Expr CB {$$=new Turn_AST($3,$1);}
	|
	SEW OB Expr COM Expr CB {$$=new Sew_AST($3,$5,$1);}
	|
	HDROW OB Expr CB {$$=new Hdrow_AST($3,$1);}
	|
	TLROWS OB Expr CB {$$=new Tlrows_AST($3,$1);}
	|
	HDCOL OB Expr CB {$$=new Hdcol_AST($3,$1);}
	|
	TLCOLS OB Expr CB {$$=new Tlcols_AST($3,$1);}
	|
	A {$$=new A_AST($1);}
	|
	B {$$=new B_AST($1);}
	;

%%
int main(void){
	yyparse();
}


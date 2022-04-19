%{
#include"l0.h"
#include"matrix.h"
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
Start : Expr {  AST::fout<<"#include<iostream>\n#include\"matrix.h\"\nusing namespace std;\nint main()\n{\n";
		$1->make_cpp();
		AST::fout<<"t"<<AST::count<<".display();\nreturn 0;\n}";
		AST::fout.close();
	};
Expr :  TURN OB Expr CB 
	{
	$$=new Turn_AST($3,$1);
	}
	|
	SEW OB Expr COM Expr CB 
	{
	$$=new Sew_AST($3,$5,$1);
	}
	|
	A {$$=new A_AST($1);}
	|
	B {$$=new B_AST($1);}
	;


%%
int main(void){
	yyparse();
}


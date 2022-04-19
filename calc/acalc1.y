%{
# include <stdio.h>
# include <iostream>
# include <string>
extern "C" void yyerror(char *s);

extern int yylex(void);

using namespace std;

%}

%token NUM ID
%left '+' '-'
%left '*' '/'
%right UMINUS
%start Start
%%

Start : StmtList
	;

StmtList : Stmt
	| StmtList Stmt
	;

Stmt : ID '=' Expr ';'
	| Expr ';'
	;

Expr : Expr '+' Expr			
	| Expr '*' Expr 		
	| Expr '/' Expr 		
	| Expr '-' Expr 		
	| '-' Expr	%prec UMINUS	
	| NUM
	| ID
	;
	
%%

int main()
{
	yyparse();
}

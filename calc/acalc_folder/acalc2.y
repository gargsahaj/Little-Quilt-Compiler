%{
# include <stdio.h>
# include <iostream>
# include <string>
# include <map>
extern "C" void yyerror(char *s);

extern int yylex(void);

using namespace std;

map <string, int> symtab;

%}
%union{
	int num;
	string * name;
}

%token <num> NUM 
%token <name> ID
%left '+' '-'
%left '*' '/'
%right UMINUS
%type <num> Expr

%start Start
%%

Start : StmtList
	;

StmtList : Stmt
	| StmtList Stmt
	;

Stmt : ID '=' Expr 
		{  
		   symtab[*$1] = $3; 
		   cout << "> " << *$1 << " = " << $3 << endl;
        	}
	| Expr 
		{ 
		   cout << "> " << $1 << endl;
        	}
	;

Expr : Expr '+' Expr			
		{ $$ = $1 + $3; }
	| Expr '*' Expr 		
		{ $$ = $1 * $3; }
	| Expr '/' Expr 		
		{ $$ = $1 / $3; }
	| Expr '-' Expr 		
		{ $$ = $1 - $3; }

	| NUM
	| ID
		{ $$ = symtab[*$1]; }
	;
	
%%

int main()
{
	yyparse();
}

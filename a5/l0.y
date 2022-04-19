%{
#include"l0.h"
#include"matrix.h"
#include"quadruple.h"
#include"symtab.h"
#include <stdio.h>
#include <iostream>
#include <string>
extern "C" void yyerror(char *s);

extern int yylex(void);

using namespace std;
AST *root;
Symtab_Stack STK;
Symbol_Entry Global_Entry;
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
%token <name> LET
%token <name> FUN
%token <name> VAL
%token <name> IN
%token <name> END
%token <name> ASSIGN
%token <name> ID
%token <name> A
%token <name> B
%token <name> OB
%token <name> CB
%token <name> COM
%type <ast> Expr
%type <ast> Decls
%type <ast> Formals
%type <ast> Actuals
%type <ast> Decl
%start Start
%%
Start : Expr { /*$1->make_cpp().write_list();*/ root=$1;
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

Expr : LET {Symtab tab;STK.push(tab);} Decls IN Expr END {$$=new Let_AST($3,$5);/*STK.stk[0].display();*/STK.pop();}
       |
       ID OB Actuals CB {$$=new Call_AST($1,$3);}
       |
       ID {int temp=STK.get_Entry(*$1); cout<<temp<<endl;
                if(Global_Entry.symbol_entry[temp].type=="val")  $$=new Call_Val_AST($1,temp);}
	;


Decls : Decl {$$=new Decl_AST($1,NULL);}
	| 
	Decl Decls {$$=new Decl_AST($1,$2);}
	;

Decl : FUN {Symtab tab;STK.push(tab);} ID OB Formals CB ASSIGN Expr {$$=new Fun_AST($3,$5,$8);STK.pop();}
       |
       VAL ID ASSIGN Expr {$$=new Val_AST($2,$4);STK.get_top()->insert_Entry($2,"val",$$);}
       ;

Formals : ID {$$=new Fparam_AST($1,NULL);}
	| ID COM Formals {$$=new Fparam_AST($1,$3);}
	;

Actuals : Expr {$$=new Aparam_AST($1,NULL);}
	| 
	Expr COM Actuals {$$=new Aparam_AST($1,$3);}
	;


%%
int main(int argc,char* argv[]){
	yyparse();
	root->evaluate().display();
	//root->print_tree();
	/*for(int i=1;i<argc;i++){
		if(string(argv[i])=="-qast")
			root->print_tree();
		else if(string(argv[i])=="-compile")
			root->make_cpp();
		else if(string(argv[i])=="-eval");
		else if(string(argv[i])=="-help");
		else if(string(argv[i])=="-tokens");
		else if(string(argv[i])=="-d");
		else if(string(argv[i])=="-symtab");
		else if(string(argv[i])=="-parse");
}
*/
}

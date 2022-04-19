#include<iostream>
#include<string.h>
using namespace std;
class AST{
public:
	string *token;
	virtual void print_tree()=0;
};
class Turn_AST:public AST{
public:
	AST *child;
	Turn_AST(AST* c,string *t);
void print_tree();
};
class Sew_AST:public AST{
public:
	AST *l_child;
	AST *r_child;
	Sew_AST(AST* lc,AST* rc,string *t);
	void print_tree();

};
class A_AST:public AST{
public:
	A_AST(string *t);
	void print_tree();
};
class B_AST:public AST{
public:
	B_AST(string *t);
	void print_tree();
};

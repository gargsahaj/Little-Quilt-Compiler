#ifndef AST_H
#define AST_H
#include<iostream>
#include<fstream>
#include<string.h>
#include"matrix.h"
#include"quadruple.h"

using namespace std;
class AST{
public:
	static int c;
	virtual void print_tree()=0;
	virtual Matrix evaluate()=0;
	virtual Quad_list make_cpp()=0;
};

class Turn_AST:public AST{
public:
	string *token;
	AST *child;
	Turn_AST(AST* c,string *t);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Sew_AST:public AST{
public:
	string *token;	
	AST *l_child;
	AST *r_child;
	Sew_AST(AST* lc,AST* rc,string *t);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class A_AST:public AST{
public:
	string *token;
	A_AST(string *t);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class B_AST:public AST{
public:
	string *token;
	B_AST(string *t);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Hdrow_AST:public AST{
public:
	string *token;
	AST *child;
	Hdrow_AST(AST* c,string *t);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Hdcol_AST:public AST{
public:
	string *token;
	AST *child;
	Hdcol_AST(AST* c,string *t);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Tlrows_AST:public AST{
public:
	string *token;
	AST *child;
	Tlrows_AST(AST* c,string *t);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Tlcols_AST:public AST{
public:
	string *token;
	AST *child;
	Tlcols_AST(AST* c,string *t);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Let_AST:public AST{
public:
	AST *decls;
	AST *expr;
	Let_AST(AST* decls,AST* expr);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Decl_AST:public AST{
public:
	AST* decl;
	AST* decls;	
	Decl_AST(AST* decl, AST* decls);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};


class Val_AST:public AST{
public:
	string *name;
	AST *expr;
	Val_AST(string *name,AST *expr);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Fun_AST:public AST{
public:
	string *name;
	AST *expr;
	AST *fplist;
	Fun_AST(string *name,AST* fplist,AST *expr);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Fparam_AST:public AST{
public:
	string *name;
	AST *fplist;
	Fparam_AST(string *name,AST *fplist);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Call_AST:public AST{
public:
	string *name;
	AST *aplist;
	Call_AST(string *name,AST *aplist);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Aparam_AST:public AST{
public:
	AST *expr;
	AST *aplist;
	Aparam_AST(AST *expr,AST *aplist);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};

class Call_Val_AST:public AST{
public:
	string *name;
	int ptr;
	Call_Val_AST(string *name,int ptr);
	void print_tree();
	Matrix evaluate();
	Quad_list make_cpp();
};
#endif

#ifndef AST_H
#define AST_H
#include<iostream>
#include<fstream>
#include<string.h>
#include"matrix.h"

using namespace std;
class AST{
public:
	string *token;
	static int count;
	virtual void print_tree()=0;
	virtual Matrix evaluate()=0;
	virtual int make_cpp()=0;
	static ofstream fout;
};

class Turn_AST:public AST{
public:
	AST *child;
	Turn_AST(AST* c,string *t);
	void print_tree();
	Matrix evaluate();
	int make_cpp();
};

class Sew_AST:public AST{
public:
	AST *l_child;
	AST *r_child;
	Sew_AST(AST* lc,AST* rc,string *t);
	void print_tree();
	Matrix evaluate();
	int make_cpp();
};

class A_AST:public AST{
public:
	A_AST(string *t);
	void print_tree();
	Matrix evaluate();
	int make_cpp();
};

class B_AST:public AST{
public:
	B_AST(string *t);
	void print_tree();
	Matrix evaluate();
	int make_cpp();
};

#endif

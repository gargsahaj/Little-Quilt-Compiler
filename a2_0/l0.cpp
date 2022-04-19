#include<iostream>
#include"l0.h"
#include"matrix.h"
#include<fstream>
using namespace std;

Turn_AST::Turn_AST(AST *c,string *t){
	child=c;
	token=t;
}
void Turn_AST::print_tree(){
	child->print_tree();
	cout<<*token<<" ";
}

int AST::count=-1;
ofstream AST::fout("gnrtd.cpp");

Sew_AST::Sew_AST(AST *lc,AST *rc,string *t){
	l_child=lc;
	r_child=rc;
	token=t;
}
Matrix Sew_AST::evaluate(){
	Matrix m1=this->l_child->evaluate();
	Matrix m2=this->r_child->evaluate();
	return m1.sew(m2);
}

Matrix Turn_AST::evaluate(){
	Matrix m=this->child->evaluate();
	return m.turn();
}

int Turn_AST::make_cpp(){
	int p=child->make_cpp();
	fout<<"Matrix t"<<++count<<"=t"<<p<<".turn();\n";
	return count;
}

void Sew_AST::print_tree(){
	l_child->print_tree();
	cout<<*token<<" ";
	r_child->print_tree();
}

int Sew_AST::make_cpp(){
	int p1=l_child->make_cpp();
	int p2=r_child->make_cpp();
	fout<<"Matrix t"<<++count<<"=t"<<p1<<".sew(t"<<p2<<");\n";
	return count;
}

A_AST::A_AST(string *t){
	token=t;
}

B_AST::B_AST(string *t){
	token=t;
}

void A_AST::print_tree(){
	cout<<*token<<" ";
}

int A_AST::make_cpp(){
	fout<<"Matrix t"<<++count<<"('a');\n";
	return count;
}

void B_AST::print_tree(){
	cout<<*token<<" ";
}

int B_AST::make_cpp(){
	fout<<"Matrix t"<<++count<<"('b');\n";
	return count;
}

Matrix A_AST::evaluate(){
	return Matrix('a');
}
Matrix B_AST::evaluate(){
	return Matrix('b');
}

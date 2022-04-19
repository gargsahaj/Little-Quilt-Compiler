#include<iostream>
#include"l0.h"
#include"matrix.h"
using namespace std;

Turn_AST::Turn_AST(AST *c,string *t){
	child=c;
	token=t;
}
void Turn_AST::print_tree(){
	child->print_tree();
	cout<<*token<<" ";
}

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
void Sew_AST::print_tree(){
	l_child->print_tree();
	cout<<*token<<" ";
	r_child->print_tree();
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

void B_AST::print_tree(){
	cout<<*token<<" ";
}
Matrix A_AST::evaluate(){
	return Matrix('a',0);
}
Matrix B_AST::evaluate(){
	return Matrix('b',0);
}

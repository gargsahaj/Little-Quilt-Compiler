#include<iostream>
#include"l0.h"
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


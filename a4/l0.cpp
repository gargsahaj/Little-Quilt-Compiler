#include<iostream>
#include"l0.h"
#include"matrix.h"
#include"quadruple.h"
#include<fstream>
using namespace std;

Turn_AST::Turn_AST(AST *c,string *t){
	child=c;
	token=t;
}

Hdrow_AST::Hdrow_AST(AST *c,string *t){
	child=c;
	token=t;
}

Tlrows_AST::Tlrows_AST(AST *c,string *t){
	child=c;
	token=t;
}

Hdcol_AST::Hdcol_AST(AST *c,string *t){
	child=c;
	token=t;
}

Tlcols_AST::Tlcols_AST(AST *c,string *t){
	child=c;
	token=t;
}
void Turn_AST::print_tree(){
	child->print_tree();
	cout<<*token<<" ";
}

void Hdrow_AST::print_tree(){
	child->print_tree();
	cout<<*token<<" ";
}


void Hdcol_AST::print_tree(){
	child->print_tree();
	cout<<*token<<" ";
}


void Tlrows_AST::print_tree(){
	child->print_tree();
	cout<<*token<<" ";
}


void Tlcols_AST::print_tree(){
	child->print_tree();
	cout<<*token<<" ";
}

int AST::count=-1;

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

Matrix Hdcol_AST::evaluate(){
	Matrix m=this->child->evaluate();
	return m.hdcol();
}

Matrix Hdrow_AST::evaluate(){
	Matrix m=this->child->evaluate();
	return m.hdrow();
}

Matrix Tlrows_AST::evaluate(){
	Matrix m=this->child->evaluate();
	return m.tlrows();
}

Matrix Tlcols_AST::evaluate(){
	Matrix m=this->child->evaluate();
	return m.tlcols();
}

Quad_list Turn_AST::make_cpp(){
	Quad_list q1=child->make_cpp();
	Quadruple *node=new Quadruple("turn",q1.tail->result,-1);
	q1.insert_node(node);
	return q1;
}

Quad_list Hdrow_AST::make_cpp(){
	Quad_list q1=child->make_cpp();
	Quadruple *node=new Quadruple("hdRow",q1.tail->result,-1);
	q1.insert_node(node);
	return q1;
}

Quad_list Hdcol_AST::make_cpp(){
	Quad_list q1=child->make_cpp();
	Quadruple *node=new Quadruple("hdCol",q1.tail->result,-1);
	q1.insert_node(node);
	return q1;
}

Quad_list Tlrows_AST::make_cpp(){
	Quad_list q1=child->make_cpp();
	Quadruple *node=new Quadruple("tlRows",q1.tail->result,-1);
	q1.insert_node(node);
	return q1;
}

Quad_list Tlcols_AST::make_cpp(){
	Quad_list q1=child->make_cpp();
	Quadruple *node=new Quadruple("tlCols",q1.tail->result,-1);
	q1.insert_node(node);
	return q1;
}

void Sew_AST::print_tree(){
	l_child->print_tree();
	cout<<*token<<" ";
	r_child->print_tree();
}

Quad_list Sew_AST::make_cpp(){
	Quad_list q1=l_child->make_cpp();
	Quad_list q2=r_child->make_cpp();
	Quadruple *node=new Quadruple("sew",q1.tail->result,q2.tail->result);
	Quad_list temp=q1.append_list(q2);
	temp.insert_node(node);
	return temp;
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

Quad_list A_AST::make_cpp(){
	return Quad_list(*token);
}

void B_AST::print_tree(){
	cout<<*token<<" ";
}

Quad_list B_AST::make_cpp(){
	return Quad_list(*token);
}

Matrix A_AST::evaluate(){
	return Matrix('a');
}
Matrix B_AST::evaluate(){
	return Matrix('b');
}

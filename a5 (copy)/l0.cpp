#include<iostream>
#include"l0.h"
#include"matrix.h"
#include"symtab.h"
#include"quadruple.h"
#include<fstream>
using namespace std;

extern Symbol_Entry Global_Entry;

A_AST::A_AST(string *t){
	token=t;
}

B_AST::B_AST(string *t){
	token=t;
}

Turn_AST::Turn_AST(AST *c,string *t){
	child=c;
	token=t;
}

Sew_AST::Sew_AST(AST *lc,AST *rc,string *t){
	l_child=lc;
	r_child=rc;
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

Val_AST::Val_AST(string *name,AST* expr){
	this->name=name;
	this->expr=expr;
}

Decl_AST::Decl_AST(AST* decl, AST* decls){
	this->decl=decl;
	this->decls=decls;
}

Let_AST::Let_AST(AST* decls,AST* expr){
	this->decls=decls;
	this->expr=expr;
}

Fun_AST::Fun_AST(string *name,AST* fplist,AST *expr){
	this->name=name;
	this->fplist=fplist;
	this->expr=expr;
}

Fparam_AST::Fparam_AST(string *name,AST *fplist){
	this->name=name;
	this->fplist=fplist;
}

Call_AST::Call_AST(string *name,AST *aplist){
	this->name=name;
	this->aplist=aplist;
}

Aparam_AST::Aparam_AST(AST *expr,AST *aplist){
	this->expr=expr;
	this->aplist=aplist;
}

Call_Val_AST::Call_Val_AST(string *name,int ptr){
	this->name=name;
	this->ptr=ptr;
}

void A_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"("<<*token<<"\n";
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void B_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"("<<*token<<"\n";
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}


void Turn_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"("<<*token<<"\n";
	child->print_tree();
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void Sew_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"("<<*token<<"\n";
	l_child->print_tree();
	r_child->print_tree();
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
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

void Let_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"(LET\n";
	decls->print_tree();
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"(IN-EXPR\n";
	expr->print_tree();
	c-=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void Val_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"(VAL "<<*name<<"=\n";
	expr->print_tree();
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void Decl_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++)
	cout<<" ";
	cout<<"(DECLS\n";
	decl->print_tree();
	if(decls!=NULL)
	{c-=4;
	decls->print_tree();
	c+=4;}
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void Fun_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"(FUN "<<*name<<"\n";
	fplist->print_tree();
	expr->print_tree();
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void Call_AST::print_tree(){
	c=+4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"(CALL FUN "<<*name<<"\n";
	aplist->print_tree();
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void Fparam_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"(FORMAL PARAM \n"<<*name<<"\n";
	if(fplist!=NULL)
	fplist->print_tree();
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void Aparam_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"(ACTUAL PARAMS \n";
	if(aplist!=NULL)
	aplist->print_tree();
	expr->print_tree();
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

void Call_Val_AST::print_tree(){
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"(CALL VAL\n";
	c+=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<"("<<*name<<"\n";
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
	for(int i=0;i<c;i++) cout<<" ";
	cout<<")\n";
	c-=4;
}

int AST::c=0;

Matrix A_AST::evaluate(){
	return Matrix('a');
}
Matrix B_AST::evaluate(){
	return Matrix('b');
}

Matrix Turn_AST::evaluate(){
	Matrix m=this->child->evaluate();
	return m.turn();
}


Matrix Sew_AST::evaluate(){
	Matrix m1=this->l_child->evaluate();
	Matrix m2=this->r_child->evaluate();
	return m1.sew(m2);
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

Matrix Let_AST::evaluate(){
	return expr->evaluate();
}

Matrix Val_AST::evaluate(){
	return expr->evaluate();
}

Matrix Fun_AST::evaluate(){

}

Matrix Call_AST::evaluate(){

}

Matrix Fparam_AST::evaluate(){
	fplist->evaluate();
	Matrix q;
	return q;
}

Matrix Aparam_AST::evaluate(){
	aplist->evaluate();
	Matrix q;
	return q;
}

Matrix Decl_AST::evaluate(){

}

Matrix Call_Val_AST::evaluate(){
	return Global_Entry.symbol_entry[ptr].ptr->evaluate();
}


Quad_list A_AST::make_cpp(){
	return Quad_list(*token);
}

Quad_list B_AST::make_cpp(){
	return Quad_list(*token);
}


Quad_list Turn_AST::make_cpp(){
	Quad_list q1=child->make_cpp();
	Quadruple *node=new Quadruple("turn",q1.tail->result,-1);
	q1.insert_node(node);
	return q1;
}

Quad_list Sew_AST::make_cpp(){
	Quad_list q1=l_child->make_cpp();
	Quad_list q2=r_child->make_cpp();
	Quadruple *node=new Quadruple("sew",q1.tail->result,q2.tail->result);
	Quad_list temp=q1.append_list(q2);
	temp.insert_node(node);
	return temp;
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

Quad_list Let_AST::make_cpp(){

}

Quad_list Val_AST::make_cpp(){

}

Quad_list Fun_AST::make_cpp(){

}

Quad_list Call_AST::make_cpp(){

}

Quad_list Fparam_AST::make_cpp(){

}

Quad_list Aparam_AST::make_cpp(){

}

Quad_list Decl_AST::make_cpp(){

}

Quad_list Call_Val_AST::make_cpp(){

}


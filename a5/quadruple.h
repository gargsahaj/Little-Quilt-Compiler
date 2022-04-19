#ifndef QUAD_H
#define QUAD_H
#include<string>
#include<fstream>
#include<iostream>
using namespace std;


class Quadruple{
	string oprtion;
	int oprnd1;
	int oprnd2;
	static int count;
public:
	Quadruple *next;
	int result;
	Quadruple(string token,int opd1,int opd2);
	string write_node();
};


class Quad_list{
public:
	Quadruple* head;
	Quadruple* tail;
	Quad_list();
	Quad_list(string s);
	void insert_node(Quadruple *node);
	Quad_list append_list(Quad_list q);
	void write_list();
};
#endif

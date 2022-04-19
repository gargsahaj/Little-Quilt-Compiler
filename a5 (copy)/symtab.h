#ifndef SYMTAB_H
#define SYMTAB_H
#include<iostream>
#include<string>
#include<map>
using namespace std;
class Symbol_Entry{
public:
	struct Entry{
		string name;
		string type;
		AST* ptr;
	}E;
	vector<Entry> symbol_entry;
	int insert_Entry(string name,string type,AST* ptr);
	void display();
};

class Symtab{
public:
	vector<int> symtab;
	void insert_Entry(string *name,string type,AST* ptr);
	int get_Entry(string name);
	void display();
};

class Symtab_Stack{
public:
	vector<Symtab> stk;
	Symtab_Stack();
	int top;
	void push(Symtab sym);
	void pop();
	void display();
	Symtab* get_top();
	int get_Entry(string name);
};
#endif

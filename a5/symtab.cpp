#include<iostream>
using namespace std;
#include<string>
#include"l0.h"
#include"symtab.h"

extern Symbol_Entry Global_Entry;

int Symbol_Entry::insert_Entry(string name,string type,AST *ptr){
	this->E.name=name;
	this->E.type=type;
	this->E.ptr=ptr;
	symbol_entry.push_back(E);
	return(symbol_entry.size()-1);
}

void Symbol_Entry::display(){
	for(int i=0;i<symbol_entry.size();i++){
		cout<<symbol_entry[i].name<<"\t";
		cout<<symbol_entry[i].type<<"\t";
		if(symbol_entry[i].ptr!=NULL)
		cout<<symbol_entry[i].ptr<<"\t";
		cout<<"\n";
	}
}

void Symtab::insert_Entry(string *name, string type,AST *ptr){
	symtab.push_back(Global_Entry.insert_Entry(*name,type,ptr));
}

int Symtab::get_Entry(string name){
  for(int i=0;i<symtab.size();i++){
      if(Global_Entry.symbol_entry[symtab[i]].name==name)
               return symtab[i];
  }
  return -1;
}

void Symtab::display(){
  for(int i=0;i<symtab.size();i++)
      cout<<symtab[i]<<" ";

}


//int Symtab_Stack::top=-1;
Symtab_Stack::Symtab_Stack(){
	top=-1;
}
void Symtab_Stack::push(Symtab sym){
	top++;	
	stk.push_back(sym);
}

void Symtab_Stack::pop(){
	if(top==-1) return;
	stk.pop_back();
	top--;
}

void Symtab_Stack::display(){
  	for(int i=0;i<stk.size();i++){
      		stk[i].display();
      		cout<<endl<<endl;
  	}
}

Symtab* Symtab_Stack::get_top(){
   	return &stk[top];
}

int Symtab_Stack::get_Entry(string name){
   	int temp;
   	for(int i=top;i>=0;i--){
        	temp=stk[i].get_Entry(name); 
        	if(temp!=-1)
            		return temp;        
   	}
   	return -1;
}


/*int main(){
	Symtab_Stack STK;
	Symtab sym;
	sym.insert_Entry("f","fun",NULL);
	STK.push(sym);
}*/

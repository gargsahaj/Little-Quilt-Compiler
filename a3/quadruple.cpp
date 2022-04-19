#include<iostream>
#include<string>
#include"quadruple.h"
#include"matrix.h"
using namespace std;


int Quadruple::count=0;
Quadruple::Quadruple(string token,int opd1,int opd2){
	oprtion=token;
	oprnd1=opd1;
	oprnd2=opd2;
	next=NULL;
	result=count++;
}

string Quadruple::write_node(){
	if(oprtion=="a")
		return "Matrix q"+to_string(result)+"(\'a\');\n";
	else if(oprtion=="b")
		return "Matrix q"+to_string(result)+"(\'b\');\n";
	else if(oprtion=="turn")
		return "Matrix q"+to_string(result)+"=q"+to_string(oprnd1)+".turn();\n";
	else if(oprtion=="sew")
		return "Matrix q"+to_string(result)+"=q"+to_string(oprnd1)+".sew(q"+to_string(oprnd2)+");\n";
}



Quad_list::Quad_list(){}

Quad_list::Quad_list(string s){
	Quadruple *node=new Quadruple(s,-1,-1);
	head=tail=node;
}

void Quad_list::insert_node(Quadruple *node){
	tail->next=node;
	tail=node;
}

Quad_list Quad_list::append_list(Quad_list q){
	Quad_list temp;
	tail->next=q.head;	
	temp.head=head;
	temp.tail=q.tail;
	return temp;
}

void Quad_list::write_list(){
	ofstream fout("gnrtd.cpp");
	Quadruple *temp=head;
	fout<<"#include<iostream>\n#include\"matrix.h\"\nusing namespace std;\n\nint main(){\n";
	while(temp!=NULL){
		fout<<temp->write_node();
		//cout<<temp->result;
		temp=temp->next;
}
	fout<<"q"<<tail->result<<".display();\nreturn 0;\n}";
	fout.close();
}

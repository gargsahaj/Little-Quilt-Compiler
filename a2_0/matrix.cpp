#include"l0.h"
#include"matrix.h"
#include<iostream>
#include<vector>
using namespace std;


Part::Part(char name,int no){
	this->name=name;
	this->state=no;
}
Part::Part(){}
void Part::rotat(){
	state=(state+1)%4;
}

void Part::display(){
	cout<<name<<state<<" ";
}

Matrix::Matrix(){}

Matrix::Matrix(char name){
	Part p(name,0);
	vector<Part> x;
	row=1;col=1;
	x.push_back(p);
	mat.push_back(x);
}

Matrix Matrix::sew(Matrix &m){
	try{
		if(this->row!=m.row)
			throw this->row;
	}
	catch(int x){
	cout<<"Sew Not Supported";
	exit(0);
	}
	Matrix M;
	M.row=m.row;
	M.col=this->col+m.col;
	vector <Part> temp;
	for(int i=0;i<this->row;i++){
		temp.clear();
		for(int j=0;j<this->col;j++)
			temp.push_back(this->mat[i][j]);
		for(int j=0;j<m.col;j++)
			temp.push_back(m.mat[i][j]);
		M.mat.push_back(temp);		
	}
	return M;
}

Matrix Matrix::turn(){
	Matrix M;
	M.row=this->col;
	M.col=this->row;
	vector<Part> x;
	for(int i=0;i<M.row;i++){
		x.clear();
		for(int j=M.col-1;j>=0;j--){
			x.push_back(this->mat[j][i]);
		}
		M.mat.push_back(x);
	}
	for(int i=0;i<M.row;i++)
		for(int j=0;j<M.col;j++)
			M.mat[i][j].rotat();
	return M;
}

void Matrix::display(){
	cout<<endl<<"ROWS: "<<row;
	cout<<endl<<"COLUMNS: "<<col<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			mat[i][j].display();
		cout<<"\n";	
	}
}

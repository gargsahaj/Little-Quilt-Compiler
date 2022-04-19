#ifndef MAT_H
#define MAT_H
#include<iostream>
#include<vector>

using namespace std;

class Part{
	char name;
	int state;
public: 
	Part();
	Part(char name,int no);
	void rotat();
	void display();
};

class Matrix{
	vector <vector<Part>> mat;
	int row;
	int col;
public:
	Matrix();
	Matrix(char name);
	Matrix turn();
	Matrix hdrow();
	Matrix hdcol();
	Matrix tlrows();
	Matrix tlcols();
	Matrix sew(Matrix &m);
	void display();
};
#endif

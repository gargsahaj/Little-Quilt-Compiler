#ifndef G_H
#define G_H
#include<iostream>
#include<string>
#include<fstream>
#include "Gcode.h"
using namespace std;


class Quadruple{
 private:
   string operation;
   int opd1;
   int opd2;
   static int count;
 public:
   int result;
   Quadruple *next;
   Quadruple(string op,int op1,int op2);
   string write_node();
};





class Gcode{
 public:
  Quadruple *head,*tail;
 public:
   Gcode();
   Gcode(string s);
   void insert_node(Quadruple *node);
   Gcode add_list(Gcode c);
   void write_list();
   
   
};


#endif

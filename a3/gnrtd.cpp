#include<iostream>
#include"matrix.h"
using namespace std;

int main(){
Matrix q0('a');
Matrix q1('b');
Matrix q2=q0.sew(q1);
Matrix q3=q2.turn();
Matrix q4('b');
Matrix q5('a');
Matrix q6=q4.sew(q5);
Matrix q7=q6.turn();
Matrix q8=q3.sew(q7);
q8.display();
return 0;
}
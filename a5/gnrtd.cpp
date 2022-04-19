#include<iostream>
#include"matrix.h"
using namespace std;

int main(){
Matrix q0('a');
Matrix q1('b');
Matrix q2=q0.sew(q1);
Matrix q3=q2.turn();
q3.display();
return 0;
}
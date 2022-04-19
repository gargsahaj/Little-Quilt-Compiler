#include<iostream>
#include"matrix.h"
using namespace std;
int main()
{
Matrix t0('a');
Matrix t1=t0.turn();
Matrix t2('b');
Matrix t3=t2.turn();
Matrix t4=t1.sew(t3);
t4.display();
return 0;
}
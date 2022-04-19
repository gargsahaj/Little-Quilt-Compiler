%{
#include<stdio.h>
int a=0;
int d=0;
%}
alphabet [a-zA-Z]
digit [0-9]
%%
{digit} {d++;}
{alphabet} {a++;}
"\n" {printf("There are %d alphabets and %d digits in sequence",a,d);}
%%

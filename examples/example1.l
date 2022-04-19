%{
	#include<stdio.h> 
%}
digit [0-9]
%%
{digit}+ {printf("digit");}
.        ;
%%

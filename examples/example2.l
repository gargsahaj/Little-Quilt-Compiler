%{
	#include<stdio.h>
	int i=0;
%}
digit [0-9]
%%
{digit} {i++;}
"\n"    {printf("There are %d digits in number",i);}
.       ;
%%

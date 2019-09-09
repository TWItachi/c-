#include <stdio.h>

main() 
{
	int f(int a,int b);//声明形参 
	int i=2,p;
	p=f(i,++i);
	printf("%d\n",p);
}

int f(int a,int b)//定义的函数 
{
	int c;
	if(a>b)
	    c=1; 
	else if(a==b)
		c=0;
	else 
		c=-1;
	return (c);
}//自右向左  

#include <stdio.h>

main() 
{
	int f(int a,int b);//�����β� 
	int i=2,p;
	p=f(i,++i);
	printf("%d\n",p);
}

int f(int a,int b)//����ĺ��� 
{
	int c;
	if(a>b)
	    c=1; 
	else if(a==b)
		c=0;
	else 
		c=-1;
	return (c);
}//��������  

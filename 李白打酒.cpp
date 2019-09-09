#include <stdio.h>
int i=0,j=2;
void f(int a,int b,int j)
{
	if(a>5||b>9)
		return ;
	if(a==5&&b==9)
	{
		if(j==1)
		{
			i++;return ;
		}
		else
			return;
	}
		f(a+1,b,j*2);
		f(a,b+1,j-1);
}

main()
{
	int a=5,b=10;
	f(0,0,2);
	printf("%d",i);
}

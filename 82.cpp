#include <stdio.h>

int f(int a)
{
	if(a<1)
		return 0;
	if(a==1)
		return 3;
	if(a==2)
		return 3;
	if(a==3)
		return 6;
	else
		return f(a-1)+f(a-2);
 } 

int main()
{
	int a,j;
	scanf("%d",&a);
	j=f(a);
	printf("%d",j);
	return 0;
} 

#include <stdio.h>

int main()
{
	int a,b,max;
	printf("please input two numbers:  ");
	scanf("%d%d",&a,&b);
	max=a>b?a:b;
	printf("%d",max);
}

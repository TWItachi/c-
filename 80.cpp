#include <stdio.h>
int a=4;

int f(int n)
{
	if(n==1||n==2)
		return 1;
	else
		return f(n-1)+f(n-2);
}

main()
{
	int j;
	j=f(a);
	printf("%d",j);	
}

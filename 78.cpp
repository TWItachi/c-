#include <stdio.h>
int n,j=1;
void f(int n)
{
	printf("%d %d\n",n,j);
	if(n==8)
	return ;
	if(n>1)
	{
		if(n%2==0)
		{
			j++;f(n/2);
		}
		else
		{
			j++;f(n*3+1);
		}
	}
}

int main()
{
	scanf("%d",&n);
	f(n);
	printf("%d",j);
	return 0;
}

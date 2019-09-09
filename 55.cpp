#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("color f4");
	int i,sum=0;
	do
	{
		sum=sum+i;
		i++;
	}while(i<=100);
	printf("%d",sum);
	return 0;
	
}

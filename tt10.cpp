#include <stdio.h>

main ()
{
	int a,b,sum=0,j=0;
	scanf("%d%d",&a,&b);
	if(a>b)
	{
		int temp;
		temp=a;
		a=b;
		b=temp;
	}
	for(;a<=b;a++)
	{
		sum=sum+a;
		printf("%5d",a);
		j++;
		if(j%5==0){printf("\n");}
	}
	if(j%5!=0)
		printf("\n");
	printf("Sum = %d",sum);
}

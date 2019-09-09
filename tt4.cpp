#include <stdio.h>

int main()
{
	int a,i,n=3,n1=0,sum,t=1,k=1;
	char b;
	scanf("%d %c",&a,&b);
	if(a<=6)
	{
		printf("%c\n",b);
		printf("%d",a-1);
	}
	else
	{
			while(1)
		{
			if(a>=n1+1)
				{
				n1=n1+2*n;
				n+=2;	
				}
			else
				break;
		}
		n1-=2*(n-2);
		n-=4;
		for(k=1;k<=n/2+1;k++)
		{
			for(int g=2;g<=k;g++)printf(" ");
			for(int t=0;t<=n-2*k+1;t++){printf("%c",b);}
			printf("\n");	
		}
		for(k=n/2;k>0;k--)
		{
		for(int g=k-1;g>0;g--)printf(" ");
		for(int t=0;t<=n-2*k+1;t++)printf("%c",b);
		printf("\n");
		}
		printf("%d",a-n1-1);}
	return 0;
} 

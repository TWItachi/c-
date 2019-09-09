#include <stdio.h>
#define M 1000 

int main()
{
	int day,mon,i,k,j,m=0,r;
	char a[9]={'a','b','c','d','e','f','g','h','i'},
	b[9]={'j','k','l','m','n','o','p','q','r'},
	c[9]={'s','t','u','v','w','x','y','z',' '},
	sum[M];
	printf("please input two numbers (month < 12 ,day < 31): ");
	scanf("%d%d",&mon,&day);
	mon%=3;
	if(mon==0)
	{
		for(i=0;i<=8;i++)
		{
			sum[m]=c[i];
			m++;
		}
		for(j=0;j<=8;j++)
		{
			sum[m]=b[j];
			m++;
		}
		for(k=0;k<=8;k++)
		{	
			sum[m]=a[k];
			m++;	
		}
	}
	if(mon==2)
	{
		for(j=0;j<=8;j++)
		{
			sum[m]=b[j];
			m++;
		}
		for(i=0;i<=8;i++)
		{
			sum[m]=c[i];
			m++;
		}
		for(k=0;k<=8;k++)
		{	
			sum[m]=a[k];
			m++;	
		}
	}		
		if(mon==1)
	{
			for(k=0;k<=8;k++)
		{	
			sum[m]=a[k];
			m++;
		}
			for(j=0;j<=8;j++)
		{
			sum[m]=b[j];
			m++;
		}
		for(i=0;i<=8;i++)
		{
			sum[m]=c[i];
			m++;
		}
	}
	r=28;
	for(i=0;i<day;i++)
	{
		sum[r]=sum[i];
		r++;
	}
	for(i=0;i<27;i++)
	{
		sum[i]=sum[day];
		day++;
	}
	for(i=0;i<27;i++)
		{
			printf("%c",sum[i]);	
		}
	return 0;
} 

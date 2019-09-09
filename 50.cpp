#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("color f4");
	printf("请输入路程s，质量w，基本运费p： ");
	int p,w,s;
	double f,d;
	scanf("%d%d%d",&s,&w,&p);
	if(s<250)
	{
	    d=0;
    }
	if(250<=s&&s<500)
	{
	    d=0.02;
    }
	if(500<=s&&s<1000)
	{
	    d=0.05;
	}
	if(1000<=s&&s<2000)
	{
	    d=0.08;
    }
	if(2000<=s&&s<3000)
	{
	    d=0.1;
    }
	if(3000<=s)
	{
	    d=0.15;
	}
	f=p*w*s*(1-d);
	printf("%lf",f);
	return 0;
}

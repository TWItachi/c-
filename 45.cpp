#include <stdio.h>

int main()
{
	printf("please input three munbers ");
	int a,b,c,max,min;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b&&b>c)
	{
		max=a,min=c;
		printf("max=%d,min=%d",max,min);
	}
	if(a>b&&a<c)
	{
		max=c,min=a;
		printf("max=%d,min=%d",max,min);
	}
	if(b>a&&a>c)
	{
	    max=b,min=c;
		printf("max=%d,min=%d",max,min);
    }
    if(c>a&&a>b)
    {
    	max=c,min=b;
		printf("mxa=%d,min=%d",max,min);
	}
	if(a>c&&c>b)
	{
		max=a,min=b;
		printf("max=%d,min=%d",max,min); 
	}
	if(b>c&&c>a)
	{
	    max=b,min=a;
	    printf("max=%d,min=%d",max,min);
    }
    return 0;
}


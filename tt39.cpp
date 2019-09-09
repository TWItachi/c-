#include <stdio.h>

int main()
{
	float a,b,t;
	scanf("%f %f",&a,&b);
	if(b==0)
		printf("%.0f/%.0f=Error",a,b,t);
	else if(b<0)
	{
		t=a/b;
		printf("%.0f/(%.0f)=%.2f",a,b,t);
	}
	else
	{
		t=a/b;
		printf("%.0f/%.0f=%.2f",a,b,t);
	}
	return 0;
}

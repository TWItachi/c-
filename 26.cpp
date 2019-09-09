#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c,s,area;
	scanf("%lf,%lf,%lf",&a,&b,&c);
	s=(a+b+c)/2.0;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("a=%7.2lf,b=%7.2lf,c=%7.2lf,s=%7.2lf\n",a,b,c,s); 
	printf("area=%7.2f\n",area);
}

#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c,disc,x1,x2,p,q;
	scanf("a=%lf,b=%lf,c=%lf,&a,&b,&c");
	disc=b*b-4*a*c;
	p=-b/(2*a);
	q=sqrt(disc)/(2*a);
	x1=p+q;
	x2=p-q;
	printf("\nx1=%5.2f\n,x2=%5.2f\n",x1,x2);
}

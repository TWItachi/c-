#include <stdio.h>
#include <math.h>

main()
{
	int a=2,b=3,c=2,i,m,n,k,g;
	int fac(int m);

	n=pow(a,c);
	m=pow(b,c);
	g=fac(n)+fac(m);
	printf("%d",g);
} 


int fac(int n)
{
	int i=1,s=1;
	for(i=1;i<=n;i++)
	{
		s=s*i;
	}
	return s;
}

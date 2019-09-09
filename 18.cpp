#include <stdio.h>

int main()
{
	int a=15;
	float b=123.1234567;
	double c=12345678.1234567;
	char d='p';
	printf("a=%d,%5d,%o,%x\n",a,a,a,a);
	printf("b=%f.%if,%5.4lf,%e\n",b,b,b,b);
	printf("c=%if,%f,%8.4f\n",c,c,c);
	printf("d=%c,%8c\n",c,c);
}

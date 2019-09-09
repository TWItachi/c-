#include <stdio.h>

int main()
{
	int a = 1;
	int b = 1;
	int c = 1;
	int d;
	for (int i = 4; i <= 20190324; ++i)
	{
		d = (a + b + c) % 10000;
		a = b;
		b = c;
		c = d;
	}
	printf("%d",d);
	return 0;
 } 



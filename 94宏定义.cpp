#include <stdio.h>
#define A(x) x;x;x;x;x;x;x;x;x;x;

int main()
{
	int n = 0;
	A(A(A(printf("%d",n++))));
	return 0;
 } 

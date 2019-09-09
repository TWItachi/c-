#include <stdio.h>

int main ()
{
	printf("please inout a charter ");
	char ch;
	scanf("%c",&ch);
	if('A'<=ch&&ch=<'Z')
	{
		printf("%c",ch+32);
	}
	else
	printf("%c",ch);
	return 0;
}

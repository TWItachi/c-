#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("color f4");
	int n=0;
	printf("input a string:\n");
	char a;
	while(a=(getchar()))
	{
	//	printf("%c",a);
		if(a=='\n') break;
		n++;
	//	//printf("%s",getchar);
	}


    printf("%d",n);
}

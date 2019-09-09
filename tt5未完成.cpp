#include <stdio.h>
#include <string.h>
#define M 1000

main()
{
	int a,s=0,A,b[M];
	char n[M]=" ";
	gets(n);
	a=strlen(n);
	A=a;
	for(int i=0;i<a;i++)
	{ 
		while(A)
		{
			if(n[s]-'0'==i)
			{
				b[i]=s++;A--;
			}
			else
			{
				A--;
			}
		}
	}
	for(int i=0;i<a;i++)
	{
		printf("%d",b[i]);
	}
}

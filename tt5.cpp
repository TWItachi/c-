#include <stdio.h>
#define M 1001
#include <string.h>

int main()
{
	int i,n,b[M]={0},j;
	char a[M]={};
	gets(a);
	n=strlen(a);
	
	for(j=0;j<=9;j++)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]-'0'==j)
			{
				b[j]+=1;
			}
		}
	}
	
	
	for(i=0;i<=9;i++)
	{
		if(b[i]==0)
		{
			continue;
		}
		else
			printf("%d:%d\n",i,b[i]);
	}
	return 0;
} 

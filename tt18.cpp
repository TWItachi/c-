#include <stdio.h>
#define M 20
#include <string.h>
 
int main()
{
	int i,j,temp,sum=0,b[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char a[M],c[16]={'1','0','X','9','8','7','6','5','4','3','2'};
	scanf("%d\n",&i);
//	getchar();
	while(i--)
	{
		sum=0;
		gets(a);
		j=strlen(a);
		for(int t=0;t<17;t++)
		{
			sum += (a[t] - '0')*b[t];
		}
		
		sum %= 11;
		
		if(c[sum] != a[17])
		{
			temp=1;
			printf("%s\n",a);
		}
	}
	if(temp==0)
	{
		printf("All passed");
	}
	return 0;
}

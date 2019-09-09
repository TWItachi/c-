#include <stdio.h>
#define  M 1000
#include <math.h>
 
int main()
{
	int i,x[M],y[M],j;
	float t[M],cnt;
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		scanf("%d %d",&x[j],&y[j]);
	}
	for(j=0;j<i;j++)
	{
		t[j]=(abs(x[j]-100)*0.9)*2;
		cnt=(y[j]-t[j])/t[j];
		if(cnt>-0.1&&cnt<0.1)
		{
			printf("You are wan mei!\n");
		}
		else if(cnt>=0.1)
		{
			printf("You are tai pang le!\n");
		}
		else
		{
			printf("You are tai shou le!\n");
		}
	}
	return 0;
}

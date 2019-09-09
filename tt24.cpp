#include <stdio.h> 
#define M 1000

main()
{
	int a,b[M],cnt1=0,cnt2=0;int i;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<a;i++)
	{
		if(b[i]%2==0)
		{
			cnt1++;
		}
		else
			cnt2++;
	}
	printf("%d %d",cnt2,cnt1);
}

#include <stdio.h>
#define M 1000

int main()
{
	int i,n,a[M]={0};
	printf("请输入n的值");
	scanf("%d",&n);
	printf("请输入n个数"); 
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);  	
	}
	for(i=n;i>0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}

#include <stdio.h>
#define M 1000

int main()
{
	int i,n,a[M]={0};
	printf("������n��ֵ");
	scanf("%d",&n);
	printf("������n����"); 
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

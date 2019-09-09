#include <stdio.h>

int main()
{
	int i,a[10]={0},min,k;
	printf("ÊäÈë10¸öÊı");
		
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	min=a[0];
	for(i=0;i<=9;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			k=i;
		}
	}
	printf("%d\n%d\n",min,k);
	return 0;
}

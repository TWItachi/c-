#include <stdio.h>
#define M 10//�� 
int main()  
{
	static int a[M]={-12,0,6,16,23,56,80,100,110,115};
	int n,low,mid,high,found;
	low=0;
	high=M-1;
	found=0;
	printf("Input a number to be seached:");
	#if(0)//����Ƕ�׵� 
	do
	{
		scanf("%d",&n);
		getchar();
	}while(n<a[0]||n>a[M-1]);
	#endif
	while(scanf("%d",&n)!=1)
	{
		printf("Illegal input !\n");
		getchar();//���һֱѭ�� 
	}
	while (low<=high)
	{
	mid=(low+high)/2;
	if(n==a[mid])
	{
		found=1;break;
	}
	else if(n>a[mid])
	    low=mid+1;
	else
		high=mid-1;
    }
		if(found==1)
		    printf("the index of %d is %d",n,mid);
		else
		    printf("There is not %d",n);
	return 0;
}

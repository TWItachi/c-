#include <stdio.h>

int main()
{
	int i,j,t;
	int a[10];
	printf("please input ten numbers :");//没什么卵用 
	for(i=0;i<10;i++)//动态赋值 
	    {
		    scanf("%d",&a[i]);
	    } 
	    for(j=0;j<=9;j++)//外循环控制次数 
		{
			for(i=0;i<=9-j;i++)//内循环保证所有都比到 
			{
				if(a[i]>a[i+1])
				{
					t=a[i];
					a[i]=a[i+1];//换位 
					a[i+1]=t;
				}
			}
		}
		  
		 for(i=0;i<=9;i++)
		 {
		 printf("%d ",a[i]);}
		 
		 printf("\n");
		 return 0;
}

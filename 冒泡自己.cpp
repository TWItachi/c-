#include <stdio.h>

int main()
{
	int i,j,t;
	int a[10];
	printf("please input ten numbers :");//ûʲô���� 
	for(i=0;i<10;i++)//��̬��ֵ 
	    {
		    scanf("%d",&a[i]);
	    } 
	    for(j=0;j<=9;j++)//��ѭ�����ƴ��� 
		{
			for(i=0;i<=9-j;i++)//��ѭ����֤���ж��ȵ� 
			{
				if(a[i]>a[i+1])
				{
					t=a[i];
					a[i]=a[i+1];//��λ 
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

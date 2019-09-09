#include<stdio.h>

main(void)
{

	int a[10],i;
	float j=0.0,k;
	printf("请输入10个学生的成绩:");
	int average(int a[10]);
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	j=average(a);
	k=j/10;
	printf("%f",k);
 } 
 
int average(int a[])
{
	int i;
	float j=0.0;
 	for(i=0;i<=9;i++)
 	{
 		j=j+a[i];
	}
	return (j);
 }

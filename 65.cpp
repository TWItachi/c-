#include <stdio.h>

main()
{
	int max(int x,int y);//形参
	int a,b,c;
	
	scanf("%d,%d",&a,&b);
	c=max(a,b);//实参
	printf("Max is %d",c);
}

int max(int x,int y)
{
	int z;
	z=x>y?x:y;
	
	return z;
}//记住逗号一定不要中文！！！ 
 

#include <stdio.h>

main()
{
	int max(int x,int y);//�β�
	int a,b,c;
	
	scanf("%d,%d",&a,&b);
	c=max(a,b);//ʵ��
	printf("Max is %d",c);
}

int max(int x,int y)
{
	int z;
	z=x>y?x:y;
	
	return z;
}//��ס����һ����Ҫ���ģ����� 
 

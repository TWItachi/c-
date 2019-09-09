#include <stdio.h>

#define Height 10
int calculate(int Long,int Width);

int main()
{
	int m_Long;
	int m_Width;
	int result;
	
	printf("长方形的高度是:%\n",Height);
	
	printf("长方形的长度是：\n");
	scanf("%d",&m_Long);
	
	printf("长方体的宽度是：\n");
	scanf("%d,%m_Width"); 
	
	result=calculate(m_Long,m_Width);
	printf("长方形的体积是：") ;
	printf("%d\n",result);
	
	return 0;
}
int calculate(int Long,int Width)
{
	int result=Long*Width*Height;
	return result;
}
 

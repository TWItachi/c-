#include <stdio.h>

#define Height 10
int calculate(int Long,int Width);

int main()
{
	int m_Long;
	int m_Width;
	int result;
	
	printf("�����εĸ߶���:%\n",Height);
	
	printf("�����εĳ����ǣ�\n");
	scanf("%d",&m_Long);
	
	printf("������Ŀ���ǣ�\n");
	scanf("%d,%m_Width"); 
	
	result=calculate(m_Long,m_Width);
	printf("�����ε�����ǣ�") ;
	printf("%d\n",result);
	
	return 0;
}
int calculate(int Long,int Width)
{
	int result=Long*Width*Height;
	return result;
}
 

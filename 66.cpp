#include <stdio.h> 
 
main()
{
	float max(float x,float y);
	float a,b;
	float c;
	
	scanf("%f%f",&a,&b);
	c=max(a,b);
	printf("Max is %f\n",c);
} 

float max(float x,float y)
{
	float z;
	z=x>y?x:y;
	
	return z;
}//ע�⣬���еĺ�����Ӧ�����ͱ�����ͬ��vc++6.0�л���־�����ʧ�����������devc++5.11�л�ֱ�ӱ�0������ 

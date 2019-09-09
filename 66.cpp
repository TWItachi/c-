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
}//注意，所有的函数对应的类型必须相同在vc++6.0中会出现精度损失的情况但是在devc++5.11中会直接报0！！！ 

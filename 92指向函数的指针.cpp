#include <stdio.h>

int max(int x,int y);
int min(int x,int y);
int add(int w,int z);
void process(int x,int y,int(*fun)(int,int));

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	
	process(a,b,max);
	process(a,b,min);
	process(a,b,add);
	return 0;
}

int max(int x,int y)
{
	int w;
	w=x>y?x:y;
	return w;
}
int min(int x,int y)
{
	int w;
	w=x<y?x:y;
	return w;
}
int add (int w,int z)
{
	int x;
	x=w+z;
	return x;
}
void process(int x,int y, int (*fun)(int ,int))
{
	int result;
	result=(*fun)(x,y);
	printf("%d\n",result);
}

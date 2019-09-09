#include <stdio.h>

int main()
{
	int p1,p2,a1,a2,a3,t=0,i=0;

	scanf("%d %d %d %d %d",&p1,&p2,&a1,&a2,&a3);
	if(a1==0)
		t++;	
	else
		i++;
	if(a2==0)
		t++;
	else
		i++;
	if(a3==0)
		t++;
	else
		i++;
	if(p1>p2&&t!=0)
		printf("The winner is a: %d + %d",p1,t);
	else if(p2>p1&&i!=0)
		printf("The winner is b: %d + %d",p2,i);
	else if(t==3)
		printf("The winner is a: %d + %d",p1,t);
	else
		printf("The winner is b: %d + %d",p2,i);

	return 0;
}

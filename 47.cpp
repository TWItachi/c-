#include <stdio.h>

int main()
{
	double a,b;
	char c;
	printf("input expression:a+(-,*,/)b\n");
	scanf("%lf%c%lf",&a,&c,&b);
	switch(c)
	{
	case '+':
		printf("%lf\n",a+b);
		break;
	case '-':
		printf("%lf\n",a-b);
		break;
	case '*':
		printf("%lf\n",a*b);
		break;
	case '/':
		printf("%lf\n",a/b);
		break;
		default:
		printf("input error\n");
	}
	return 0;
 } 

#include <stdio.h>
#define M 1000

int main()
{
	int n;
	float b;
	char a;
	scanf("%d",&n);
	getchar();
	while(n--) 
	{
		scanf("%c%f",&a,&b);
		getchar();
		if(a==70)
		{
			printf("%.2f\n",b*1.09);
		}
		else
		{
			printf("%.2f\n",b/1.09);continue;
		}
	}
	return 0;
}

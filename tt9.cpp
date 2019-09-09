#include <stdio.h>
#define M 1000
#include <math.h>

main()
{
	int a,b[M];int i=0;
	scanf("%d",&a);
	if(a<0)
	{
		printf("fu ");
	}
	a=abs(a);
	if(a==0)
	{
		printf("ling");
	}
	while(1)
	{
		if(a==0)
		{
			break;
		}
		b[i]=a%10;
		a/=10;
		i++;		
	}
	for(int j=i-1;j>=0;j--)
	{
		switch(b[j])
		{
			case 0: printf("ling");break;
			case 1: printf("yi");break;
			case 2: printf("er");break;
			case 3: printf("san");break;
			case 4: printf("si");break;
			case 5: printf("wu");break;
			case 6: printf("liu");break;
			case 7: printf("qi");break;
			case 8: printf("ba");break;
			case 9: printf("jiu");break;
		}
	if(j!=0)
	printf(" ");
	}
}

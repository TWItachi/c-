#include <stdio.h>

int main()
{
	int time1,time2,h1,min1;
	printf("please input teo numbers: \n");
	scanf("%d%d",&time1,&time2);
	
	if(time2>=0)
	{
		h1=time2/60;min1=time2%60;
		time1+=h1*100;time1+=min1;
		if(time1%100>=60)
		{
			time1-=60;
			time1+=100;
		}
		else
		{
			time1=time1+time2;
		}
	}
	else
		if(time2>-60)
		{
			time1-=40;
			time1+=time2;
		}
		else
		{
			min1=time1%60;
			if(time1%60>-min1)
			{
				time1+=time2;
			}
			else
			{
				printf("%d\n",time1);
				time1-=100;
				printf("%d\n",time1);
				time1=time1+60-time2;
				printf("%d\n",time1);
			}
		}
	printf("%d\n",time1);
	return 0;
} 

#include <stdio.h>

int main()
{
	int i;char j;
	scanf("%d %c",&i,&j);
	if(i%2==0)
	{
		for(int t=1;t<=i/2;t++)
		{
			for(int s=1;s<=i;s++)
			{
				printf("%c",j);
			}
		printf("\n");
		}
	}
	else
	{
		for(int t=1;t<=i/2+1;t++)
		{
			for(int s=1;s<=i;s++)
			{
				printf("%c",j);
			}
		printf("\n");
		}
	}
	return 0;
}
//������ż��ϵ����ҪϹ�����㣡
//ż����2
//����������һ 

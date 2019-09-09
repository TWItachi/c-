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
//分清奇偶关系，不要瞎鸡儿搞！
//偶数除2
//奇数除二加一 

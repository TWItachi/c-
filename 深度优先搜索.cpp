#include <stdio.h>

int a[100000],book[100000],j;
void dfs(int step)
{
	int i;
	if(step==j+1)
	{
		for(i=1;i<=j;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return ;
	}
	for(i=1;i<=j;i++)
	{
		if(book[i]==0)
		{
			a[step]=i;
			book[i]=1;
			
			dfs(step+1);
			
			book[i]=0; 
		}
	}
}

int main()
{
	scanf("%d",&j);
	dfs(1);
	return 0;
}

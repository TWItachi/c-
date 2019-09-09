#include <stdio.h>
int a[10],v[10],i=1,j=9,t=0;
int book[10];

void dfs(int step)
{
	int i;
		if(step>10)
			return;
		else if(step==3)
		{
			if(a[0]>a[1]||a[0]>a[2])
				return;
		}
		else if(step==6)
		{
			if (a[1]>a[3] || a[1]>a[4] || a[2]>a[4] || a[2]>a[5])
		 	return ;
		}
		else if(step==10)
		{
			if (a[3]>a[6] || a[3]>a[7] || a[4]>a[7] || a[4]>a[8] || a[5]>a[8] || a[5]>a[9])
		 	return ;t++;
		}

	for(i=0;i<10;i++)
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
	j=9;
	dfs(0);
	printf("%d",t);
	return 0;
}

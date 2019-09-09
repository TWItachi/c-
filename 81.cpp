#include <stdio.h>

void map(int i,int j);
int i=0,j=0,x=0;
int a[8][8]=
	{
	{0,0,1,1,1,1,1,1},
	{1,0,0,1,1,1,1,1},
	{1,1,0,0,1,1,1,1},
	{0,0,1,0,0,1,1,1},
	{1,1,1,1,0,0,0,1},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,0,0,0},	
	};
	
	
void map(int i,int j)
{
	if(j==7&&i==7)
	{
		x=1;return;
	}
	if(j>7||i>7)
		return ;
	else 
	{
		if(a[i][j]==0)
		{
			if(a[i+1][j]==0)
			{
				map(i+1,j);
			}
			if(a[i][j+1]==0)
			{
				map(i,j+1);
			}
		}
		else
		{
			i=j=7;
		}
	}
}


int main()
{
	map(i,j);
	if(x==1)
	{
		printf("YES");
	}
	else
		printf("NO");
	return 0;
 } 

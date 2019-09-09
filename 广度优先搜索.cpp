#include <stdio.h> 

struct note
{
	int x;
	int y;
	int f;
	int s;
}; //定义结构体变量。 
int main()
{
	struct note que[2501];
	int a[51][51]={0},book[51][51]={0};
	int next[4][2]={
					{0,1},
					{1,0},
					{0,-1},
					{-1,0}	
					};//分别向上下左右四个方向。 
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);//输入地图 
		}
	scanf("%d %d %d %d",&startx,&starty,&p,&q);//输入起点和终点 
	head=1;tail=1;
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].f=0;
	que[tail].s=0;
	tail++;
	book[startx][starty]=1;
	flag=0;//出队列的标志。 
	while(head<tail)
	{
		for(k=0;k<=3;k++)//遍历上下左右四个方向，这里要想清楚。 
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			if(tx<1||tx>n||ty<1||ty>m)
			{continue;}//判断是否越界 
			if(a[tx][ty]==0&&book[tx][ty]==0)
			{
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;
				que[tail].s=que[head].s+1;
				tail++;//head和tail有关系，这里有点问题。 
			}
			if(tx==p&&ty==q)//到终点，准备输出。 
			{
				flag=1;
				break;
			}
		}
	if(flag==1)
	{
		break;
	}
	head++;
	}
	printf("%d",que[tail-1].s);
	return 0;
}

/*广度优先搜索的核心就是队列，其主要是优先级的问题要想清楚，
其具体是一圈一圈向外搜索，其中分为八向搜索和四向搜索。*/ 

#include <stdio.h> 

struct note
{
	int x;
	int y;
	int f;
	int s;
}; //����ṹ������� 
int main()
{
	struct note que[2501];
	int a[51][51]={0},book[51][51]={0};
	int next[4][2]={
					{0,1},
					{1,0},
					{0,-1},
					{-1,0}	
					};//�ֱ������������ĸ����� 
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);//�����ͼ 
		}
	scanf("%d %d %d %d",&startx,&starty,&p,&q);//���������յ� 
	head=1;tail=1;
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].f=0;
	que[tail].s=0;
	tail++;
	book[startx][starty]=1;
	flag=0;//�����еı�־�� 
	while(head<tail)
	{
		for(k=0;k<=3;k++)//�������������ĸ���������Ҫ������� 
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			if(tx<1||tx>n||ty<1||ty>m)
			{continue;}//�ж��Ƿ�Խ�� 
			if(a[tx][ty]==0&&book[tx][ty]==0)
			{
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;
				que[tail].s=que[head].s+1;
				tail++;//head��tail�й�ϵ�������е����⡣ 
			}
			if(tx==p&&ty==q)//���յ㣬׼������� 
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

/*������������ĺ��ľ��Ƕ��У�����Ҫ�����ȼ�������Ҫ�������
�������һȦһȦ�������������з�Ϊ��������������������*/ 

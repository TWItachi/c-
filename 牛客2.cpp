#include <stdio.h>
int cnt;

int fun(int a,int b)
{
	
	int c=2;
	while(c){
		if(a%c==0 && a%c==0){
			cnt=c;
			c=0;
			return cnt;
		}
		else{
			c++;
		}
		if(c>b/2){
			c=0;
			return 0;
		}
	}
}


int main()
{
	int n,m,x,y,t,temp;
	float cnt1,cnt2;
	scanf("%d %d %d %d %d",&x,&y,&n,&m,&t);
	
	cnt1=float(n-1)/float(x-1);
	cnt2=float(m-1)/float(y-1);
	

	if(t==0){
		if(cnt1>cnt2){
		printf("%.3f",cnt2);
		}
		else{
			printf("%.3f",cnt1);
		}
	}
	else{
		temp=fun((m-1),(y-1));
		if(temp==0){
			if(cnt1>cnt2){
			printf("%d/%d",m-1,y-1);
		}
			else{
			printf("%d/%d",n-1,x-1);
			}	
		}
		else{
			m=(m-1)/cnt;
			n=(n-1)/cnt;
			x=(x-1)/cnt;
			y=(y-1)/cnt;
			if(cnt1>cnt2){
			printf("%d/%d",m,y);
		}
			else{
			printf("%d/%d",n,x);
			}	
		}
	}
	return 0;
}

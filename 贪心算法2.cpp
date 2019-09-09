#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1000005;
struct three{
	double w;//重量 
	double v;//价值 
	double p;//性价比 
}s[M];

bool cmp(three a,three b)
{
	return a.p>b.p;//根据每个宝物性价比由大到小排序 
}

int main()
{
	loop:
	int n;//n个宝物 
	double m;//表示背包大小
	cout<<"please input sum(coin) n and max weight m"<<endl;//输入宝物数量n以及承载能力m 
	cin>>n>>m;
	cout << "please input a coin weight and it's much"<<endl;//输入每个宝物重量与价格 
	for(int i=0;i<n;i++){
		cin>>s[i].w>>s[i].v;
		s[i].p=s[i].v/s[i].w;//每个宝物的价值 
	}
	sort(s,s+n,cmp);
	double sum=0.0;
	for(int i=0;i<n;i++){//按顺序排列
		if(m>s[i].w){
			m-=s[i].w;
			sum+=s[i].v;
		}
		else//如果宝物的重量小鱼毛驴的运载能力{
			sum+=m*s[i].p;
			break;
		}
	 
		cout<<"max value="<<sum<<endl;
		goto loop;
	return 0;
}


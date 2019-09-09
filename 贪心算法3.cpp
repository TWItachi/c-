#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Meet
{
	int beg;
	int end;
	int num;
}meet[1000];
//定义结构体
 
class setMeet{
	public:
		void init();
		void solve();
	private:
		int n,ans;
};
//会议总数，最大安排会议总数
 

void setMeet::init()
{
	int s,e;
	cout << "please input sum of meeting"<< endl;
	cin >> n;
	int i; 
	cout<< "please input open time and close time"<<endl;
	for(i=0;i<n;++i){
		cin>>s>>e;
		meet[i].beg=s;
		meet[i].end=e;
		meet[i].num=i+1;
	}
}

bool cmp(Meet x,Meet y)
{
	if(x.end == y.end){
		return x.beg > y.beg;
	}
	return x.end < y.end;
	
}	

void setMeet::solve()
{
	sort(meet,meet+n,cmp);//对会议结束排序
	cout << "The meetings that are sorted are as follows"<<endl;
	int i;
	cout<< "\t\tMeet number" << " Start time"<< " End time"<<endl;
	for(i=0;i<n;i++){
		cout<<"		"<< meet[i].num <<"\t\t"<< meet[i].beg <<"\t"<< meet[i].end <<endl;
	}
	cout <<"--------------------------------------------------------"<<endl;
	cout <<"The progress of select meeting:"	<<endl;
	cout <<"please change "<<meet[0].num<< " meeting" << endl;
	ans = 1;
	int last = meet[0].end;
	for( i = 1;i < n; i++)
	{
		if(meet[i].beg >= last){
			ans++;
			last = meet[i].end;
			cout <<"please change "<< meet[i].num <<" meeting"<<endl;
		}
	}
	cout<<"Up to "<< ans <<" meeting can be schedule"<<endl;
}

int main()
{
	setMeet sm;
	sm.init();
	sm.solve();
	return 0;
}
/*
10
3 4
1 4
5 7
2 5
5 9
3 8
8 11
6 10
8 12
12 14
*/

/*
5
1 3
5 6
2 4
3 5
3 4
*/

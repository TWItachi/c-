#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1000005;
struct three{
	double w;//���� 
	double v;//��ֵ 
	double p;//�Լ۱� 
}s[M];

bool cmp(three a,three b)
{
	return a.p>b.p;//����ÿ�������Լ۱��ɴ�С���� 
}

int main()
{
	loop:
	int n;//n������ 
	double m;//��ʾ������С
	cout<<"please input sum(coin) n and max weight m"<<endl;//���뱦������n�Լ���������m 
	cin>>n>>m;
	cout << "please input a coin weight and it's much"<<endl;//����ÿ������������۸� 
	for(int i=0;i<n;i++){
		cin>>s[i].w>>s[i].v;
		s[i].p=s[i].v/s[i].w;//ÿ������ļ�ֵ 
	}
	sort(s,s+n,cmp);
	double sum=0.0;
	for(int i=0;i<n;i++){//��˳������
		if(m>s[i].w){
			m-=s[i].w;
			sum+=s[i].v;
		}
		else//������������С��ë¿����������{
			sum+=m*s[i].p;
			break;
		}
	 
		cout<<"max value="<<sum<<endl;
		goto loop;
	return 0;
}


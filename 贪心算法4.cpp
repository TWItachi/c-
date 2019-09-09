#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <stack>

using namespace std;
const int N = 100;
const int INF = 1e7;

int map[N][N],dist[N],p[N],n,m;
bool flag[N];

void Dijkstar(int u)
{
	for(int i=1; i<=n; i++){
		dist[i] =map[u][i];
		flag[i]=false;
		if(dist[i]==INF){
			p[i]=-1;
		}
		else{
			p[i]=u;
		}
		dist[u] = 0;
	flag[u] = true;
	}	
	for(int i=1; i<=n; i++){
		int temp = INF,t = u;
		for(int j=1; j<=n; j++){
			if(!flag[j]&&dist[j]<temp){
				t=j;
				temp=dist[j];
			}
		}
		if(t==u){
			return;
		}
		flag[t] = true;

		for(int j=1;j<=n;j++){
			if(!flag[j] && map[t][j]<INF){
				if(dist[j]=dist[t]+map[t][j]){
					dist[j]=dist[t]+map[t][j];
					p[j]=t;
				}
			}
		}
	}
}

int main()
{
	int u,v,w,st;
	system("color f4");
	cout << "please input city sum :"<<endl;
	cin >> n;
	cout << "please input between city and city raods:"<<endl;
	cin >> m;
	cout << "please input city road and distance:"   << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=INF;
		} 
	} 
	while(m--)
	{
		cin >> u >> v >> w;
		map[u][v] =min(map[u][v],w);
	}
	cout << "please input xiaoming address" << endl;
	cin >> st;
	Dijkstar(st);
	cout <<"xiaoming now address"<<st<< endl;
	for(int i=1;i<=n;i++){
		cout << "xiaoming :"<<st<<" - "<<"bourn: "<<i<<endl;
		if(dist[i] == INF){
			cout << "sorry, no way"<<endl;
		}
		else{
			cout << "nearest :"<<dist[i]<<endl;	
		}
	}
	return 0;
}

/*
5
11
1 5 12
5 1 8
1 2 16
2 1 29
5 2 32
2 4 13
4 2 27
1 3 15
3 1 21
3 4 7
4 3 19
5
*/

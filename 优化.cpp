#include <iostream> 
#include <queue>
#include <cstring>
#include <windows.h>
using namespace std;

const int N = 100;
const int INF = 1e7;
int map[N][N],dist[N],n,m;
int flag[N];
struct Node{
	int u,step;
	Node(){};
	Node(int a,int sp){
		u=a;step=sp;
	}
	bool operator <(const Node& a)const { //重载<
		return step>a.step; 
	}
};
void Dijkstra(int st){
	priority_queue<Node> Q;
	Q.push(Node(st,0));
	memset(flag,0,sizeof(flag));
	for(int i=1;i<n;++i)
		dist[i]=INF;
	dist[st]=0;
	while(!Q.empty()){
		Node it=Q.top();
		Q.pop();
		int t=it.u;
		if(flag[t])
			continue;
		flag[t]=1;
		for(int i=1;i<=n;i++){
			if(!flag[i]&&map[t][i]<INF){
				if(dist[i]>dist[t]+map[t][i]){
					dist[i]=dist[t]+map[t][i];
					Q.push(Node(i,dist[i]));
				}
			}
		}
	}
}
int main()
{
	int u,v,w,st;
	system("color f4");
	cout << "please input the number of country"<<endl;
	cin >> n;
	cout << "please input the number of between country to cpuntry"<<endl;
	cin >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			map[i][j]=INF;
		}
	cout << "please input between country u to country v numbers w"<<endl; 
	while(m--)
	{
		cin>>u>>v>>w;
		map[u][v]=min(map[u][v],w);
	}
	cout << "input xiaoming place" <<endl;
	cin>>st;
	Dijkstra(st);
	cout << "小明所在位置: " <<st<<endl;
	for(int i=1;i<=n;i++){
		cout << "xiaoming: "<<st<<"--->"<<"要去的位置:"<<i;
		if(dist[i]==INF)
			cout<<"sorry,无法到达"<<endl;
		else 
			cout << " 最短距离为："<<dist[i]<<endl;
		}
	return 0;
}
/*
5
7
1 2 2
1 3 3
2 3 5
2 4 6
3 4 7
3 5 1
4 5 4
1
*/

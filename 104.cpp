#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct p{
	char a[3];
	int x,y;
}f[15];

int main(){
	int n;
	int flag = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>f[i].a>>f[i].x>>f[i].y;
	
		if((f[i].x>20||f[i].x<15)||(f[i].y>70||f[i].y<50))
			cout<<f[i].a<<endl;
		
	}
	return 0;
}

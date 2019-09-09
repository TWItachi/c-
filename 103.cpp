#include<stdio.h>
#include<iostream>
using namespace std;
char ma[100][100];
int main(){
	freopen("migong.txt","r",stdin);
	for(int i=1;i<=30;i++){
		for(int j=1;j<=50;j++){
			cin>>ma[i][j];
		}
	}
	for(int i=1;i<=30;i++){
		for(int j=1;j<=50;j++){
			cout<<ma[i][j];
		}cout<<endl;
	}
	return 0;
}

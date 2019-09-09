#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct people{
	int sex,height,weight;
}f[11];

int main()
{
	int n;
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		cin>>f[j].sex>>f[j].height>>f[j].weight;
		if(f[j].sex==0){
			if(f[j].height <129){
				printf("duo chi yu! ");
			}
			if(f[j].height == 129 ){
				printf("wan mei! ");
			}
			if(f[j].height > 129){
				printf("ni li hai! ");
			}
			if(f[j].weight < 25){
				printf("duo chi rou!");
			}
			if(f[j].weight > 25){
				printf("shao chi rou!");
			}
			if(f[j].weight == 25){
				printf("wan mei!");
			}
			printf("\n");
		}
		else{
				if(f[j].height <130){
				printf("duo chi yu! ");
			}
			if(f[j].height == 130 ){
				printf("wan mei! ");
			}
			if(f[j].height > 130){
				printf("ni li hai! ");
			}
			if(f[j].weight < 27){
				printf("duo chi rou!");
			}
			if(f[j].weight > 27){
				printf("shao chi rou!");
			}
			if(f[j].weight == 27){
				printf("wan mei!");
			}
			printf("\n");
		}
	}
	return 0; 
}

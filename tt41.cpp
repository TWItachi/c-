#include <stdio.h>
#define M 1001

int main(){
	int a[M],j;
	for(j=0;j<=1001;j++){
		scanf("%d",&a[j]);
		if(a[j] == 250){
			printf("%d",j+1);
			break;
		}
		else{
			continue;
		}
	}
	return 0;
}

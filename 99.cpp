#include <stdio.h>
#define M 200
#define N 50

int main()
{
	int a[N][M]={0},sum=0,i,j,k=0,sum1[M];
	
	for(j=0;j<20;j++){
		for(i=0;i<5;i++){
			scanf("%d",&a[j][i]);
		}
	}
	
	
	
	for(i=0;i<5;i++){
		for(j=0;j<20;j++){
			if(a[j][i] > a[j+1][i]){
				a[j+1][i] = a[j][i];
				sum1[k] = a[j+1][i]; 
				k++;
			}
			else{
				continue;
			}
		}
	}

	for(k=0;k<5;k++){
		sum += sum1[k];
	}
	printf("%d",sum);
	return 0;
}
/* 
97 90 0 0 0
92 85 96 0 0
0 0 0 0 93
0 0 0 80 86
89 83 97 0 0
82 86 0 0 0
0 0 0 87 90
0 97 96 0 0
0 0 89 0 0
95 99 0 0 0
0 0 96 97 0
0 0 0 93 98
94 91 0 0 0
0 83 87 0 0
0 0 98 97 98
0 0 0 93 86
98 83 99 98 81
93 87 92 96 98
0 0 0 89 92
0 99 96 95 81
*/
/*
97 90 0 0 0
92 85 96 0 0
0 0 0 0 93
89 83 97 0 0
82 86 0 0 0
0 0 0 87 90
0 91 96 0 0
0 0 89 0 0
95 99 0 0 0
0 0 96 97 0
0 0 0 93 98
94 91 0 0 0
0 83 87 0 0
0 0 98 97 98
0 0 0 93 86
98 83 99 98 81
0 0 0 80 86
93 87 92 96 98
0 0 0 89 92
0 99 96 95 81
*/
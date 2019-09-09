#include <stdio.h>

int main()
{
	int a=2019,n=0;
	for(int i=1;i<=1009;i++){
		for(int j=1;j<=2019;j++){
			for(int k=1;k<=2019;k++){
				if((i+j+k==2019)&&i!=2&&i!=4&&j!=2&&j!=4&&k!=2&&k!=4&&i!=j&&i!=k&&j!=k){
					n++;
				}
			}
		}
	}
	printf("%d");
	return 0;
}


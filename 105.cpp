#include <stdio.h>
#include <math.h>

int main(){
	float a,b,n;
	scanf("%f%f",&a,&b);
	n = a/b/b;
	
	printf("%.1f\n",n);
	
	if(n <= 25){
		printf("Hai Xing");
	}else{
		printf("PANG");
	}
	
	return 0;
} 

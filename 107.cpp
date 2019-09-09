#include <stdio.h>
#define M 60
#include <string.h>

int main()
{
	char a[M];
	int j=0;
	int n,temp=0;
	gets(a);
	n = strlen(a);
	
	if(a[0] == '-'){
		for(j=0;j<n;j++){
			if(a[j] == '2'){
			 temp++;
			}
		}
		if((a[j-1]-'0')%2 == 0){
			printf("%.2f%%",temp*1.5/(n-1)*2*100);
		}
		else{
			printf("%.2f%%",temp*1.5/(n-1)*100);
		}
	}
	
	else{
		for(j=0;j<n;j++){
			if(a[j] == '2'){
			 temp++;
			}
		}
		if((a[j-1]-'0')%2  == 0){
			printf("%.2f%%",temp*2.0/n*100);
		}
		else{
			printf("%.2f%%",temp*1.0/n*100);
		}
	}
	return 0;
}

/*345*/
/*0145*/
/*235*/

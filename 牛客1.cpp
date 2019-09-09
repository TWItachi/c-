#include <stdio.h>
#include <algorithm>
#define M 100001

using namespace std; 
int main()
{
	float rp,i=0;
	int n,a[M],cnt1,cnt2,temp=1;
	
	scanf("%d %f",&n,&rp);
	
	for(int j=0;j<n;j++){
		scanf("%d",&a[j]);
	}
	
	sort(a,a+n);
	
	for(int j=0;j<n;j++){
		if(rp>a[j]){
        	j++;
        	cnt1=j;
        	cnt2=j;
        	continue;
        }
        
		do{
			rp=(a[cnt1]+rp)/2;
		}while(cnt1--);
		
		while(cnt2 != n){
			if(rp<a[j]){
				rp=(rp+a[cnt2])/2;
				cnt2++;
			}
		
		}
		break;
	printf("%f",rp);
	return 0;
}
}

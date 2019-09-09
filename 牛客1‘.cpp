#include <stdio.h>
#include <algorithm>
#define M 100001

using namespace std; 
int main()
{
	float rp,i=0;int j=0;
	int n,a[M],cnt1,cnt2,temp=1;
	
	scanf("%d %f",&n,&rp);
	
	for(j=0;j<n;j++){
		scanf("%d",&a[j]);
	}
	
	sort(a,a+n);
	
 	for(j=0;j<=n;j++){
 		if(rp<a[j]){
 			rp=(rp+a[j])/2;
		}	
	}

	printf("%.3f",rp);
	return 0;
}


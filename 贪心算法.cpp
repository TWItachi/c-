#include <stdio.h>
#include <algorithm>
#include <iostream>



const int N = 1000005;

using namespace std;


double w[N];
int main()
{
	double c;
	int n;
	cout << "please inout number c and sum n："<<endl;
	cin>>c>>n;
	cout<<"please input things weight，ues space :"<<endl;
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	sort(w,w+n);
//	double tmp=0.0;
//	int ans=0;
//	for(int i=0;i<n;i++){
//		tmp+=w[i];
//		if(tmp<=c){
//			ans++;
//		}
//		else{
//			break;
//		}
//	}
	int tmp = 0,ans = n;
	for(int i=0;i<n;i++){
		tmp += w[i];
		if(tmp>=c){
			if(tmp==c){
				ans=i+1;
			}
			
			else{
				ans=i;
			}
		}
		break;
	} 
	cout<<"it can full things is Ans=";
	cout<<ans<<endl;
	return 0; 
}//注释掉的部分时间复杂度高，本身算法没错，for循环有问题。
 

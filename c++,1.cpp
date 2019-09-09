#include <iostream>

using namespace std; 

int main()
{
	int n=1;
	while(!((n%2==1)&&(n%3==2)&&(n%4==3)&&(n%5==4)&&(n%6==5)&&(n%7==0))){
		n++;
	}
	cout << "改进后可把n++改为n+=7，算法时间复杂度降低七倍"<<endl;
	cout << "Count the stairs = " << n << endl;
	return 1;
}//改进后可把n++改为n+=7，算法时间复杂度降低七倍。

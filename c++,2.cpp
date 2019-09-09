#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int prime(int n);
int main()
{
	int i,n;
	for(i=4;i<=2000;i+=2){
		for(n=2;n<i;n++){
			if(prime(n)){
				if(prime(i-n)){
					cout<< i << "=" << n <<"+"<<i-n<<endl;
					break;
				}
			}
		}
	}
	return 0;
}

int prime(int i)
{
	int j;
	if(i<=1){
		return 0;
	}
	if(i==2){
		return 1;
	}
	for(j=2;j<=(int)sqrt((double)i);j++){
		if(!(i%j)){
			return 0;
		}
	return 1;
	}
}

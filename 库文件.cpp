#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int a[] = {656,6,23,121,124,51,5,15,15,15},i;
	sort(a,a+10);
	for(i = 0;i<10;i++)
		printf("%d ",a[i]);
}

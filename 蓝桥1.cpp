#include <stdio.h>
#include<iostream>
#define M 100
#include <algorithm>
using namespace std;

int main()
{
	int i,a[M],b=0,j,t=0;
	scanf("%d",&i);
	while(i--)
	{
		t=0;
		while(getchar()!='\n')
		{
			scanf("%d",&a[t]);
			t++;
		}
		sort(a,a+t);
		
		
	}
	return 0;
}

#include <stdio.h>

struct cnt
{
	int year;
	int month;
	int day;
};
int fsum(int day[],int month,int day2)
{
	static int day1=0;
	static int i=0;
	if(i<month)
	{
		day1+=day[i++];
		fsum(day,month,day2);
	}
	else 
	{
		day1+=day2;
		return day1;
	}
}

int main()
{
	int day[13]={0,30,31,30,31,30,31,31,30,31,30,31};
	struct cnt cnt1;
	int sum;
	scanf("%d%d%d",&cnt1.year,&cnt1.month,&cnt1.day);
	sum=fsum(day,cnt1.month,cnt1.day);
	{
		sum+=1;
	}
	printf("%d",sum);
	return 0;
} 

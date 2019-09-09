#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("color f4");
	int cnt;
	printf("please input a  number ");
	scanf("%d",&cnt);
	if(cnt%4==0&&cnt%100!=0||cnt%400==0) 
	printf("这个年份是闰年！");
	else
	printf("这个年份不是闰年!"); 
	return 0;
}

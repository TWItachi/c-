#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("color f4");
	int cnt;
	printf("please input a  number ");
	scanf("%d",&cnt);
	if(cnt%4==0&&cnt%100!=0||cnt%400==0) 
	printf("�����������꣡");
	else
	printf("�����ݲ�������!"); 
	return 0;
}

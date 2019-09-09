#include <stdio.h>

int main()
{
	int a;
	printf("input integer number: ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:printf("Monday\n");
		case 2:printf("Tuesday\n");
		case 3:printf("Wednesday\n");
		case 4:printf("Thusday\n");
		case 5:printf("Friday\n");
		case 6:printf("Saturday\n");
		case 7:printf("Sunday\n");
		default:printf("error\n");
	}
}

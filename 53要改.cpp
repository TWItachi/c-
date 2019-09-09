#include <stdio.h>

int main()
{
	printf("请输入年份月份和日期：");
	int mon,day,all,cnt,year;
	scanf("%d%d%d",&year,&mon,&day);
	if(year%4==0&&year%100!=0||year%400==0) 
	{ 
	switch(mon){ 
	case 1:all=0;
	break;
	case 2:all=31;
	break;
	case 3:all=31+29;
	break;
	case 4:all=31+29+31;
	break;
	case 5:all=31+29+31+30;
	break;
	case 6:all=31+29+31+30+31;
	break;
	case 7:all=31+29+31+30+31+30;
	break;
	case 8:all=31+29+31+30+31+30+31;
	break;
	case 9:all=31+29+31+30+31+30+31+31;
	break;
	case 10:all=31+29+31+30+31+30+31+31+30;
	break;
	case 11:all=31+29+31+30+31+30+31+31+30+31;
	break;
	case 12:all=31+29+31+30+31+30+31+31+30+31+30;
	break;
	}
	} 
	else
	{
	switch(mon)
	{
	case 1:all=0;
	break;
	case 2:all=31;
	break;
	case 3:all=31+28;
	break;
	case 4:all=31+28+31;
	break;
	case 5:all=31+28+31+30;
	break;
	case 6:all=31+28+31+30+31;
	break;
	case 7:all=31+28+31+30+31+30;
	break;
	case 8:all=31+28+31+30+31+30+31;
	break;
	case 9:all=31+28+31+30+31+30+31+31;
	break;
	case 10:all=31+28+31+30+31+30+31+31+30;
	break;
	case 11:all=31+28+31+30+31+30+31+31+30+31;
	break;
	case 12:all=31+28+31+30+31+30+31+31+30+31+30;
	break;
}
}
	cnt=all+day;
	printf("%d",cnt);
	return 0;
} 

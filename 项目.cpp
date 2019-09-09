#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

int run[20]={31,29,31,30,31,30,31,31,30,31,30,31};
int ping[20]={31,28,31,30,31,30,31,31,30,31,30,31};
int flag=0;

void set_color(int color)
{
	//设置控制文本属性 ， 接收color来改变颜色 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

int pr(int y)     //判断闰年
{
	return ((y%400==0)||((y%4==0)&&(y%100!=0)));
}

int panduan(int year,int month,int day)   //判断输入是否正确 
{
	if(pr(year)){
		if(day>run[month-1]){flag=0;}
		else{flag=1;}
	}
	else{
		if(day>ping[month-1]){flag=0;}
		else{flag=1;} 
	}
	
	return flag;
}
int tianshu(int year,int month)        //计算天数函数
{
	int i,days;
	i=pr(year);
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:days=31;break;
		case 2:	if(i==1){
					days=29;
				}
		   		else{
				   	days=28;
				} 
				break;
		default:days=30;break;
	}
	return days;
}
int main()
{
	int i,m,n,totoldays=0,year,month,empty,days,sum,num1=0,cnt=1,num,qi;
	int day[32]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
	{
		printf("\n\n\n\t\t\t");
		printf("*********************************");
		set_color(cnt);
		set_color(cnt);
		printf("\n\n\n\t\t\t\t欢");
		Sleep(200);cnt++;
		set_color(cnt);
		printf("迎");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("来");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("到");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("万");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("年");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("历");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("!!!");
		Sleep(250);
		cnt++;
		printf("\n\n\n\t\t\t");
		set_color(cnt);
		printf("*********************************");
		Sleep(1800);
		system("cls");		
	}
	printf("\n\n\n");
	set_color(cnt);
	printf("\t请输入年份：");
	cnt++;
	scanf("%d",&year);
	set_color(cnt);
	printf("\t请输入月份：");
	cnt++;
	scanf("%d",&month);
	set_color(cnt);
	printf("\t请输入日期：");
	cnt++;
	scanf("%d",&days);
    panduan(year,month,days);
	if(flag==0){
		printf("没有这一天");
	}
	else{
		if(pr(year)){
			set_color(cnt);printf("\t%d年是闰年,%d年%d月有%d天\n\n\t今年生肖:",year,year,month,tianshu(year,month));cnt++;
		}
			
		else{
			set_color(cnt);printf("\t%d年是非闰年，%d年%d月有%d天\n\n\t今年生肖:",year,year,month,tianshu(year,month));cnt++;
		}
		switch(year%12){
			case 1:printf("鼠");break;
			case 2:printf("牛");break;
			case 3:printf("虎");break;
			case 4:printf("兔");break;
			case 5:printf("龙");break;
			case 6:printf("蛇");break;
			case 7:printf("马");break;
			case 8:printf("羊");break;
			case 9:printf("猴");break;
			case 10:printf("鸡");break;
			case 11:printf("狗");break;
			case 12:printf("猪");break;
		}	
		printf("\n\n");
		set_color(cnt);
		printf("\t星期一");
		cnt++;
		set_color(cnt);
		printf("\t星期二");
		cnt++;
		set_color(cnt);
		printf("\t星期三");
		cnt++;
		cnt=1;
		set_color(cnt);
		printf("\t星期四");
		set_color(cnt);
		cnt++;
		printf("\t星期五");cnt++;
		set_color(cnt);
		printf("\t星期六");
		cnt++;
		set_color(cnt);
		printf("\t星期天\n");
		cnt++;
		for(m=1;m<year;m++){	
			i=pr(m);;
			if(i==1){
				totoldays=totoldays+366;
			}
			else{
				totoldays=totoldays+365;
			}
		}
		for(n=1;n<month;n++){
			totoldays=totoldays+tianshu(year,n);
			num1=num1+tianshu(year,n);
		}	
		if(pr(year)){
			empty=1+totoldays%7;
		}
		else {
			empty=totoldays%7;
		}
			if(empty==7){
				empty=0;
			}	
			for(m=0;m<empty;m++){
				printf("\t");
				}
			for(m=0;m<tianshu(year,month);m++){
				if((m+empty)%7==0){
					printf("\n");
				}
				set_color(cnt);
				printf("\t%d",day[m]);
				cnt++;
				if(cnt == 14){
					cnt=1;
				}
			}
			printf("\n");
		sum=totoldays+days;
		set_color(cnt);
		printf("\t距公元元年%d天\n",sum);
		cnt++;
		num1=num1+days;
		set_color(cnt);
		printf("\t这是今年的第%d天\n",num1);
		num=num1%7;
		cnt++;
		switch(month){
			case 3:
			case 4:
			case 5: set_color(cnt);printf("\t第一季度");cnt++;break;
			case 6:
			case 7:
			case 8:	set_color(cnt);printf("\t第二季度");cnt++;break;
			case 9:
			case 10:
			case 11: set_color(cnt);printf("\t第三季度");cnt++;break;
			case 12:
			case 1:
			case 2: set_color(cnt);printf("\t第四季度");cnt++;break;
		} 
		qi=sum%7;
		if(qi==0){
			qi=7;
		}
		printf("\n\t星期%d\n",qi);
	} 
	getchar();getchar();
	return 0;
}


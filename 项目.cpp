#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

int run[20]={31,29,31,30,31,30,31,31,30,31,30,31};
int ping[20]={31,28,31,30,31,30,31,31,30,31,30,31};
int flag=0;

void set_color(int color)
{
	//���ÿ����ı����� �� ����color���ı���ɫ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

int pr(int y)     //�ж�����
{
	return ((y%400==0)||((y%4==0)&&(y%100!=0)));
}

int panduan(int year,int month,int day)   //�ж������Ƿ���ȷ 
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
int tianshu(int year,int month)        //������������
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
		printf("\n\n\n\t\t\t\t��");
		Sleep(200);cnt++;
		set_color(cnt);
		printf("ӭ");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("��");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("��");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("��");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("��");
		Sleep(250);
		cnt++;
		set_color(cnt);
		printf("��");
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
	printf("\t��������ݣ�");
	cnt++;
	scanf("%d",&year);
	set_color(cnt);
	printf("\t�������·ݣ�");
	cnt++;
	scanf("%d",&month);
	set_color(cnt);
	printf("\t���������ڣ�");
	cnt++;
	scanf("%d",&days);
    panduan(year,month,days);
	if(flag==0){
		printf("û����һ��");
	}
	else{
		if(pr(year)){
			set_color(cnt);printf("\t%d��������,%d��%d����%d��\n\n\t������Ф:",year,year,month,tianshu(year,month));cnt++;
		}
			
		else{
			set_color(cnt);printf("\t%d���Ƿ����꣬%d��%d����%d��\n\n\t������Ф:",year,year,month,tianshu(year,month));cnt++;
		}
		switch(year%12){
			case 1:printf("��");break;
			case 2:printf("ţ");break;
			case 3:printf("��");break;
			case 4:printf("��");break;
			case 5:printf("��");break;
			case 6:printf("��");break;
			case 7:printf("��");break;
			case 8:printf("��");break;
			case 9:printf("��");break;
			case 10:printf("��");break;
			case 11:printf("��");break;
			case 12:printf("��");break;
		}	
		printf("\n\n");
		set_color(cnt);
		printf("\t����һ");
		cnt++;
		set_color(cnt);
		printf("\t���ڶ�");
		cnt++;
		set_color(cnt);
		printf("\t������");
		cnt++;
		cnt=1;
		set_color(cnt);
		printf("\t������");
		set_color(cnt);
		cnt++;
		printf("\t������");cnt++;
		set_color(cnt);
		printf("\t������");
		cnt++;
		set_color(cnt);
		printf("\t������\n");
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
		printf("\t�๫ԪԪ��%d��\n",sum);
		cnt++;
		num1=num1+days;
		set_color(cnt);
		printf("\t���ǽ���ĵ�%d��\n",num1);
		num=num1%7;
		cnt++;
		switch(month){
			case 3:
			case 4:
			case 5: set_color(cnt);printf("\t��һ����");cnt++;break;
			case 6:
			case 7:
			case 8:	set_color(cnt);printf("\t�ڶ�����");cnt++;break;
			case 9:
			case 10:
			case 11: set_color(cnt);printf("\t��������");cnt++;break;
			case 12:
			case 1:
			case 2: set_color(cnt);printf("\t���ļ���");cnt++;break;
		} 
		qi=sum%7;
		if(qi==0){
			qi=7;
		}
		printf("\n\t����%d\n",qi);
	} 
	getchar();getchar();
	return 0;
}


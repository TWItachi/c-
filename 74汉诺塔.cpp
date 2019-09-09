#include<stdio.h>
void hbta(int n, char x, char y, char z);

 void hbta(int n, char x, char y, char z)
 {
 	if(n == 1)
 	{
 		printf("%c --> %c\n",x,z);
	}
	else
	{
		hbta(n-1,x,z,y);
		printf("hhh\n");
		printf("%c --> %c\n",x,z);
		printf("uuu\n");
		hbta(n-1,y,x,z);
		printf("ggg\n");
	}
	 
 }
 
 int main()
 {
 	int n;
	 printf("请输入一个数\n");
	 scanf("%d",&n);
	 hbta(n ,'x' , 'y' ,'z');
	 
	 return 0;	
 }

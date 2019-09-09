#include<stdio.h>
#include<string.h>
int main()
{
	char str1[10000],str2[10000];
	int a[10000]={0},b[10000]={0};
	int c[10000];
	scanf("%s %s",str1,str2);
	int lenstr1=strlen(str1);
	int lenstr2=strlen(str2);
	int xia=0;
	int t=0;
	for(int i=lenstr1-1,j=0;i>=0;i--,j++)
	{
		a[j]=str1[i]-'0';
	}
	for(int i=lenstr2-1,j=0;i>=0;i--,j++)
	{
		b[j]=str2[i]-'0';
	}
	int MAX=lenstr1>lenstr2?lenstr1:lenstr2;
	for(int i=0;i<MAX;i++)
	{
		c[i]=(a[i]+b[i]+t);
		t=c[i]/10;
		c[i]%=10;
	}
	if(t)printf("%d",t);
	for(int i=MAX-1;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");	
	return 0;
}

#include <stdio.h>
#include <string.h>
#define M 10000

int main()
{
	char a1[M]="",b1[M]="",a2[M]="",b2[M]="",c[M];
	int i,j,k,l,t=0;
	gets(a1);gets(b1);
	i=strlen(a1);j=strlen(b1);
	k=i>j?i:j;
	for(int k=i-1;k>=0;k--)a2[i-k-1]=a1[k];
	for(int k=j-1;k>=0;k--)b2[j-k-1]=b1[k];
//	printf("%s %s\n",a2,b2);
//	if(i<j)
//	{
//		i=j;
//	}
//	k=i;
//	l=i-1;
//	printf("%c %c\n",a1[0],b1[0]);
//	printf("%d\n",k);	
//	for(i=0;i<k;i++)
//	{
//	//		printf("%d\n",i);
//	//	printf(" %d %d   %c %c\n",i,l,a1[i],b1[i]);
//		a2[l]=a1[i];
//		b2[l]=b1[i];
//		l--;
//	
//		printf(" %d %d   %c %c\n",i,l+1,a2[i],b2[i]);
//	}
//printf("%s %s\n",a2,b2);
	for(int k=0;k<i;k++)if(a2[k]=='\0')a2[k]=0;
	for(int k=0;k<j;k++)if(b2[k]=='\0')b2[k]=0;
	for(l=0;l<k;l++)
	{
		printf("%c %c\n",a2[l],b2[l]);
		if((a2[l]+b2[l]-'0'-'0'+t)>=10)
		{
			c[l]=a2[l]+b2[l]-'0'-'0'+t-10;
			t=1;
		}
		else
		{
			c[l]=a2[l]+b2[l]-'0'-'0'+t; 
			t=0;
		}
	} 
	if(t)printf("1");
	for(i=k-1;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	
	return 0;
}

#include <stdio.h>
#include <string.h>
#define M 1000

int main()
{
	int i,x=0,y=0;
	char a[M],b[M],c[M];
	gets(a);
	for(i=0;i<(strlen(a));i++)
	{
		if(('a'<=a[i]&&a[i]<='z')||('A'<=a[i]&&a[i]<='Z'))
		{
			b[x]=a[i];x++;continue;
		}
	     if('0'<= a[i]&&a[i]<='9')
		{
			c[y]=a[i];y++;continue;
		}
	}
	puts(strcat(b,c));
	return 0;
}//ע�⣡0��9������������Ŵ�������Ӧ��ASCII��ֵ����Ϊ��������ַ�����
 

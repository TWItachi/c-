#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	system("color f4");
	printf("请输入路程s,基本运费p，货物重w，：");	
	int f,p,s,d,w;
	scanf("%d%d%d",&s,&p,&w);
	switch(s)
	{
    	case (s<250):
    	d=0;
    	break;
    	case (250<=s<500):
    	d=0.02;
	    break;
    	case(500<=s<1000):
    	d=0.05;
    	break;
    	case(1000<=s<2000):
    	d=0.08;
    	case(2000<=s<3000):
    	d=0.1;
    	break;
    	case(s>=3000):
    	d=0.15;
    	break;
    }
    f=p*w*s*(1-d);
    printf("%d",f);
    return 0;
}

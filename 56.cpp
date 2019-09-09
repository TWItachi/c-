#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("color f4"); 
	int i,sum=0;
	i=1;
	
	loop:if(i<=100)
	{
	    sum=sum+i;
	    i++;
	    goto loop;
    }
    printf("%d",sum);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("color f4");
	int r;
	double pi=3.14159,area;
	for(r=1;r<=10;r++)
	   {
	   	area=pi*r*r;
	   
	if(area>100)
	    {
		break;
	    } printf("r=%d,area=%g\n",r,area);
    }
   
	return 0;
	
}


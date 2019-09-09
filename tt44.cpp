#include <stdio.h>

main()
{
	int a,b,c;
	scanf("%d-%d-%d",&a,&b,&c);
	if(a<10&&b>10)
	printf("%d-0%d-%d",c,a,b);
	if(b<10&&a>10)
	printf("%d-%d-0%d",c,a,b);
	if(a<10&&b<10)
	printf("%d-0%d-0%d",c,a,b);
}

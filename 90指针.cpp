#include <stdio.h>

int main()
{
	void copy_string(char *form,char *to);
	
	char *a="i am a teacher";
	char b[]="you are a student.";
	
	printf("string a = %s\nstring b = %s\n",a,b);
	printf("copy string a to string b:\n");
	
	copy_string(a,b);
	
	printf("\nnstring a = %s\nstring b = %s\n",a,b);
	
	return 0;
}

void copy_string(char *form,char *to )
{
	int i=0;
	
	for(;*form != '\0';form++,to++)
	{
		
	}
	*to='\0';
}

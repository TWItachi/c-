#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>

#define LEN sizeof(struct student)

struct student *creat();
void print(struct student *head);

struct student
{
	int num;
	float score;
	struct student *next;
};

int n;

int main()
{
	struct student *stu;
	
	stu = creat();
	print( stu );
	
	printf("\n\n");
	system("pause");
	return 0;
}


struct student *creat()
{
	struct student *head;
	struct student *p1,*p2;
	
	p1=p2=(struct student*)malloc(LEN);
	
	printf("please enter the num :");
	scanf("%d",&p1->num);
	printf("please enter the score");
	scanf("%f",&p1->score);
	
	head=NULL;
	n = 0;
	
	while(p1->num)
	{
		n++;
		if (1==n)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 =p1;
		
		p1=(struct student *)malloc(LEN);
		
		printf("\nplease enter the num :");
		scanf("%d",&p1->num);
		printf("please enter the score :");
		scanf("%f",&p1->score);
		
	}
	
	p2->next = NULL;
	
	return head;
}

void print(struct student *head)
{
	struct student *p;
	printf("\nThere are %d records!\n\n",n);
	
	p = head;
	if (head)
	{
		do
		{
			printf("学号位%d的成绩是:%f\n",p->num,p->score);
			p= p->next;
		}while(p);
		
	}
}

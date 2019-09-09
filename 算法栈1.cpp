#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct
{ 
	ElemType *base;
	ElemType *top;
	int stackSize; 
}sqStack;

void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if( !s->base )
	{
		exit(0);
		s->top = s->base + s->stackSize; //�ʼ��ջ������ջ��
		s->stackSize = s->stackSize + STACKINCREMENT;
	}
	
	s->top= s->base; //�ʼ��ջ������ջ��
	s->stackSize = STACK_INIT_SIZE;//������ֵΪ100
}

void Push(sqStack *s, ElemType e)
{
	if( s->top - s->base >= s->stackSize )//��ջǰ�Ƚ����ж�
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if( !s->base )
		{
			exit(0);
		}
		s->top = s->base + s->stackSize; //�ʼ��ջ������ջ��
		s->stackSize = s->stackSize + STACKINCREMENT;
	}	
		*(s->top) = e;
		s->top++;
	
}		
void Pop(sqStack *s, ElemType *e)
{
	if( s->top == s->base ){
		return;}
	
	*e = *--(s->top);
}
	


int StackLen(sqStack s)
{
	return (s.top - s.base);//�м���˶���Ԫ�ز�
	
}

int main()
{
	ElemType c;
	sqStack s;
	int len, i, sum = 0;
	
	InitStack(&s);
	
	printf("�������������������#��ʾ������\n");
	scanf("%c", &c);
	
	while( c != '#')
	{
		Push(&s, c);
		scanf("%c", &c);
	}
	
	getchar();//��'\n'�ӻ�����ȥ�� 
	
	len = StackLen(s);
	printf("ջ�ĵ�ǰ�����ǣ� %d\n",len);
	
	for( i=0; i < len ; i++)
	{
		Pop(&s, &c);
		sum = sum + (c-48) *pow(2, i);
	}
	
	printf("ת��Ϊʮ��������: %d",sum);
	return 0;
}

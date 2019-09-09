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
		s->top = s->base + s->stackSize; //最开始，栈顶就是栈底
		s->stackSize = s->stackSize + STACKINCREMENT;
	}
	
	s->top= s->base; //最开始，栈顶就是栈底
	s->stackSize = STACK_INIT_SIZE;//容量赋值为100
}

void Push(sqStack *s, ElemType e)
{
	if( s->top - s->base >= s->stackSize )//入栈前先进行判断
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if( !s->base )
		{
			exit(0);
		}
		s->top = s->base + s->stackSize; //最开始，栈顶就是栈底
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
	return (s.top - s.base);//中间隔了多少元素差
	
}

int main()
{
	ElemType c;
	sqStack s;
	int len, i, sum = 0;
	
	InitStack(&s);
	
	printf("请输入二进制数，输入#表示结束！\n");
	scanf("%c", &c);
	
	while( c != '#')
	{
		Push(&s, c);
		scanf("%c", &c);
	}
	
	getchar();//把'\n'从缓冲区去掉 
	
	len = StackLen(s);
	printf("栈的当前容量是： %d\n",len);
	
	for( i=0; i < len ; i++)
	{
		Pop(&s, &c);
		sum = sum + (c-48) *pow(2, i);
	}
	
	printf("转化为十进制数是: %d",sum);
	return 0;
}

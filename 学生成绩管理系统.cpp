/**
 * 学生成绩管理系统（单链表实现）
 *
 * @author JindongFeng
 * @date 2019/06
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct Student{
	char id[15];          //学号
	char name[20];        //姓名
	float score;        //成绩
}Student;

typedef struct LNode {
	Student data;           //结点的数据域
	struct LNode *next;     //结点的指针域
} LNode, *LinkList;         //LinkList为指向结构体LNode的指针类型

int InitList_L(LNode *L) { //单链表的初始化，在此例子中这个函数没有用到
	//构造一个空的单链表L
	L=(LNode *)malloc(sizeof(LNode));   //生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL;                     //头结点的指针域置空
	return OK;
}

LNode *CreateList_R() { //后插法创建单链表
	LNode *L;
	L=(LNode *)malloc(sizeof(LNode));   //生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL;                     //头结点的指针域置空
	LNode *p, *r;
	r = L;                  //尾指针r指向头结点
	FILE *fp;               //创建文件流变量

    if((fp = fopen("scores.txt", "r")) == NULL){
         printf("不能打开文件！\n");
         return 0;
    }

    /* 以下两行代码的作用是跳过文件的第一行 */
    char buf[1024];
    fgets(buf, sizeof(buf), fp);

    while(!feof(fp)){
        p = (LNode *)malloc(sizeof(LNode));
        fscanf(fp,"%s	%s	%f\n",p->data.id,p->data.name,&p->data.score);  //参考fscanf函数
        p->next = NULL;
        r->next = p;           //将新结点*p插入尾结点*r之后
		r = p;                  //r指向新的尾结点*p
    }
    fclose(fp);
    return L;
}

LNode *Select_L(LinkList L, char id[]) {       //按学号查找，查找成功后返回该结点指针
	//在带头结点的单链表L中查找值为id的元素
	LinkList p;
	p = L->next;
	while (p && strcmp( p->data.id, id ) != 0)   //顺链域向后扫描，直到p为空或p所指结点的数据域等于id
		p = p->next;                            //p指向下一个结点
	return p;           //查找成功返回学号值为id的结点地址p，查找失败p为NULL
}

int ListInsert_L(LinkList L, int i, Student e) {            //单链表的插入
	//在带头结点的单链表L中第i个位置插入学生结构体值为e的新结点
	int j;
	LinkList p, s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}                           //查找第i-1个结点，p指向该结点
	if (!p || j > i - 1)
		return ERROR;
	s = (LNode *)malloc(sizeof(LNode));     //生成新结点*s
	s->data = e;            //将结点*s的数据域置为e
	s->next = p->next;      //将结点*s的指针域指向结点ai
	p->next = s;            //将结点*p的指针域指向结点*s
	return OK;
}

int ListDelete_L(LinkList L, char id[], char name[]) { //单链表的删除，输入的学号和姓名匹配后才能删除
	LinkList p, q;       //将待删除的结点记为p, q是p的前驱结点
	q = L;
	p = L->next;

	while (p && strcmp( p->data.id, id ) != 0){
        p = p->next;
        q = q->next;
	}

	if(!p){
        printf("找不到此学号的学生！");
        return 0;
    }
	if(strcmp( p->data.name, name ) != 0){  //参考strcmp函数
        printf("学号号和姓名不匹配！");
        return 0;
    }
	q->next = p->next;
	free(p);                       //释放删除结点的空间
	return OK;
} //ListDelete_L

int Modify_L(LinkList L, char id[], char name[]) {    //修改指定学号和姓名的学生成绩
	LinkList p;
	p = L->next;
    float newScore;
	while (p && strcmp( p->data.id, id ) != 0)
        p = p->next;

	if(!p){
        printf("找不到此学号的学生！");
        return 0;
    }
	if(strcmp( p->data.name, name ) != 0){
        printf("学号号和姓名不匹配！");
        return 0;
    }
    printf("请输入想修改的新成绩：");
    scanf("%f", &newScore);
    p->data.score = newScore;
	return OK;
}

//打印输出单链表
int show(LNode *L){
    LNode *p;
    p = L->next;
    int i=1;
    printf("序号\t学号\t\t姓名\t\t成绩\n");
    while(p){
        printf("%d\t%s\t%s\t\t%.1f\n",i,p->data.id,p->data.name,p->data.score);
        p = p->next;
        i++;
    }
}

//单链表版的冒泡排序
void BubbleSort(LinkList L){
	LinkList cur,tail;
	char temp1[15],temp2[20];
	cur=L->next;
	tail=NULL;
	if(cur==NULL||cur->next==NULL){
		return;
	}
	while(cur!=tail){
		while(cur->next!=tail){
			if(cur->data.score<cur->next->data.score){
				double temp=cur->data.score;
				cur->data.score=cur->next->data.score;
				cur->next->data.score=temp;
				strcpy(temp1,cur->data.id);      //参考字符串赋值函数strcpy
				strcpy(cur->data.id,cur->next->data.id);
				strcpy(cur->next->data.id,temp1);
				strcpy(temp2,cur->data.name);
				strcpy(cur->data.name,cur->next->data.name);
				strcpy(cur->next->data.name,temp2);
			}
			cur=cur->next;
		}
		tail=cur;
		cur=L->next;
	}
}

//菜单函数
void menu(){
    printf("\t\t\n");
	printf("\t\t          欢迎使用学生成绩管理系统\n");
	printf("\t\t\n");
	printf("\t\t*******************************************\n");
	printf("\t\t\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t~~                                       ~~\n");
	printf("\t\t~~          请按1：导入学生成绩！        ~~\n");
	printf("\t\t~~          请按2：查询学生成绩！        ~~\n");
    printf("\t\t~~          请按3：新增学生成绩！        ~~\n");
	printf("\t\t~~          请按4：删除学生成绩！        ~~\n");
	printf("\t\t~~          请按5：修改学生成绩！        ~~\n");
	printf("\t\t~~          请按6：学生成绩排序！        ~~\n");
	printf("\t\t~~          请按7：输出学生成绩！        ~~\n");
	printf("\t\t~~          请按0：退出系统！            ~~\n");
	printf("\t\t~~                                       ~~\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}

int main() {
    int index, status;
    char id[15],name[20];
    float score;
    LNode *L, *p;
    Student *stu;
	int choose = -1;
	while (choose!=0) {
		menu();
		printf("请选择：");
		scanf("%d",&choose);
		switch (choose) {
		case 1: //初始化一个单链表，从文件读取数据并使用后插法创建单链表
			L = CreateList_R();
			printf("导入 scores.txt 信息完毕\n\n");
			break;
		case 2: //单链表的按值查找
			printf("请输入所要查找的学生学号:");
            scanf("%s",id);
            p = Select_L(L,id);
            if (p != NULL) {
				printf("查找成功\n");
				printf("该学生成绩为：%s, %s, %.1f\n\n", p->data.id, p->data.name, p->data.score);
			} else
				printf("查找失败!\n\n");
			break;
		case 3: //单链表的插入
			printf("请输入新增学生的信息，包括：学号 姓名 成绩（用空格隔开）:");
			stu = (Student *)malloc(sizeof(Student));
			scanf("%s %s %f", stu->id, stu->name, &stu->score);
			printf("请输入待插入的位置:");
			scanf("%d", &index);
			if (ListInsert_L(L, index, *stu))
				printf("插入成功.\n\n");
			else
				printf("插入失败!\n\n");
			break;
		case 4: //单链表的删除
			printf("请输入所要删除的学生学号:");
            scanf("%s",id);
            printf("请输入所要删除的学生姓名:");
            scanf("%s",name);
            status = ListDelete_L(L,id,name);
            if (status)
				printf("该学生成绩信息删除成功！\n");
			else
				printf("删除失败!\n\n");
			break;
		case 5: //单链表的修改
			printf("请输入所要修改的学生学号:");
            scanf("%s",id);
            printf("请输入所要修改的学生姓名:");
            scanf("%s",name);
            status = Modify_L(L,id,name);
            if (status)
				printf("该学生成绩信息修改成功！\n\n");
			else
				printf("修改失败!\n\n");
			break;
        case 6: //单链表的排序
			printf("按成绩从高到低进行排序!\n");
			BubbleSort(L);
			printf("排序完毕！\n\n");
			break;
        case 7: //单链表的输出
			printf("当前学生成绩管理系统信息（链表）读出:\n");
			show(L);
			break;
		}
	}
	return 0;
}


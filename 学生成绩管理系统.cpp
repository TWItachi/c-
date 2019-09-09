/**
 * ѧ���ɼ�����ϵͳ��������ʵ�֣�
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
	char id[15];          //ѧ��
	char name[20];        //����
	float score;        //�ɼ�
}Student;

typedef struct LNode {
	Student data;           //����������
	struct LNode *next;     //����ָ����
} LNode, *LinkList;         //LinkListΪָ��ṹ��LNode��ָ������

int InitList_L(LNode *L) { //������ĳ�ʼ�����ڴ��������������û���õ�
	//����һ���յĵ�����L
	L=(LNode *)malloc(sizeof(LNode));   //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL;                     //ͷ����ָ�����ÿ�
	return OK;
}

LNode *CreateList_R() { //��巨����������
	LNode *L;
	L=(LNode *)malloc(sizeof(LNode));   //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL;                     //ͷ����ָ�����ÿ�
	LNode *p, *r;
	r = L;                  //βָ��rָ��ͷ���
	FILE *fp;               //�����ļ�������

    if((fp = fopen("scores.txt", "r")) == NULL){
         printf("���ܴ��ļ���\n");
         return 0;
    }

    /* �������д���������������ļ��ĵ�һ�� */
    char buf[1024];
    fgets(buf, sizeof(buf), fp);

    while(!feof(fp)){
        p = (LNode *)malloc(sizeof(LNode));
        fscanf(fp,"%s	%s	%f\n",p->data.id,p->data.name,&p->data.score);  //�ο�fscanf����
        p->next = NULL;
        r->next = p;           //���½��*p����β���*r֮��
		r = p;                  //rָ���µ�β���*p
    }
    fclose(fp);
    return L;
}

LNode *Select_L(LinkList L, char id[]) {       //��ѧ�Ų��ң����ҳɹ��󷵻ظý��ָ��
	//�ڴ�ͷ���ĵ�����L�в���ֵΪid��Ԫ��
	LinkList p;
	p = L->next;
	while (p && strcmp( p->data.id, id ) != 0)   //˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������id
		p = p->next;                            //pָ����һ�����
	return p;           //���ҳɹ�����ѧ��ֵΪid�Ľ���ַp������ʧ��pΪNULL
}

int ListInsert_L(LinkList L, int i, Student e) {            //������Ĳ���
	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ѧ���ṹ��ֵΪe���½��
	int j;
	LinkList p, s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}                           //���ҵ�i-1����㣬pָ��ý��
	if (!p || j > i - 1)
		return ERROR;
	s = (LNode *)malloc(sizeof(LNode));     //�����½��*s
	s->data = e;            //�����*s����������Ϊe
	s->next = p->next;      //�����*s��ָ����ָ����ai
	p->next = s;            //�����*p��ָ����ָ����*s
	return OK;
}

int ListDelete_L(LinkList L, char id[], char name[]) { //�������ɾ���������ѧ�ź�����ƥ������ɾ��
	LinkList p, q;       //����ɾ���Ľ���Ϊp, q��p��ǰ�����
	q = L;
	p = L->next;

	while (p && strcmp( p->data.id, id ) != 0){
        p = p->next;
        q = q->next;
	}

	if(!p){
        printf("�Ҳ�����ѧ�ŵ�ѧ����");
        return 0;
    }
	if(strcmp( p->data.name, name ) != 0){  //�ο�strcmp����
        printf("ѧ�źź�������ƥ�䣡");
        return 0;
    }
	q->next = p->next;
	free(p);                       //�ͷ�ɾ�����Ŀռ�
	return OK;
} //ListDelete_L

int Modify_L(LinkList L, char id[], char name[]) {    //�޸�ָ��ѧ�ź�������ѧ���ɼ�
	LinkList p;
	p = L->next;
    float newScore;
	while (p && strcmp( p->data.id, id ) != 0)
        p = p->next;

	if(!p){
        printf("�Ҳ�����ѧ�ŵ�ѧ����");
        return 0;
    }
	if(strcmp( p->data.name, name ) != 0){
        printf("ѧ�źź�������ƥ�䣡");
        return 0;
    }
    printf("���������޸ĵ��³ɼ���");
    scanf("%f", &newScore);
    p->data.score = newScore;
	return OK;
}

//��ӡ���������
int show(LNode *L){
    LNode *p;
    p = L->next;
    int i=1;
    printf("���\tѧ��\t\t����\t\t�ɼ�\n");
    while(p){
        printf("%d\t%s\t%s\t\t%.1f\n",i,p->data.id,p->data.name,p->data.score);
        p = p->next;
        i++;
    }
}

//��������ð������
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
				strcpy(temp1,cur->data.id);      //�ο��ַ�����ֵ����strcpy
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

//�˵�����
void menu(){
    printf("\t\t\n");
	printf("\t\t          ��ӭʹ��ѧ���ɼ�����ϵͳ\n");
	printf("\t\t\n");
	printf("\t\t*******************************************\n");
	printf("\t\t\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t~~                                       ~~\n");
	printf("\t\t~~          �밴1������ѧ���ɼ���        ~~\n");
	printf("\t\t~~          �밴2����ѯѧ���ɼ���        ~~\n");
    printf("\t\t~~          �밴3������ѧ���ɼ���        ~~\n");
	printf("\t\t~~          �밴4��ɾ��ѧ���ɼ���        ~~\n");
	printf("\t\t~~          �밴5���޸�ѧ���ɼ���        ~~\n");
	printf("\t\t~~          �밴6��ѧ���ɼ�����        ~~\n");
	printf("\t\t~~          �밴7�����ѧ���ɼ���        ~~\n");
	printf("\t\t~~          �밴0���˳�ϵͳ��            ~~\n");
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
		printf("��ѡ��");
		scanf("%d",&choose);
		switch (choose) {
		case 1: //��ʼ��һ�����������ļ���ȡ���ݲ�ʹ�ú�巨����������
			L = CreateList_R();
			printf("���� scores.txt ��Ϣ���\n\n");
			break;
		case 2: //������İ�ֵ����
			printf("��������Ҫ���ҵ�ѧ��ѧ��:");
            scanf("%s",id);
            p = Select_L(L,id);
            if (p != NULL) {
				printf("���ҳɹ�\n");
				printf("��ѧ���ɼ�Ϊ��%s, %s, %.1f\n\n", p->data.id, p->data.name, p->data.score);
			} else
				printf("����ʧ��!\n\n");
			break;
		case 3: //������Ĳ���
			printf("����������ѧ������Ϣ��������ѧ�� ���� �ɼ����ÿո������:");
			stu = (Student *)malloc(sizeof(Student));
			scanf("%s %s %f", stu->id, stu->name, &stu->score);
			printf("������������λ��:");
			scanf("%d", &index);
			if (ListInsert_L(L, index, *stu))
				printf("����ɹ�.\n\n");
			else
				printf("����ʧ��!\n\n");
			break;
		case 4: //�������ɾ��
			printf("��������Ҫɾ����ѧ��ѧ��:");
            scanf("%s",id);
            printf("��������Ҫɾ����ѧ������:");
            scanf("%s",name);
            status = ListDelete_L(L,id,name);
            if (status)
				printf("��ѧ���ɼ���Ϣɾ���ɹ���\n");
			else
				printf("ɾ��ʧ��!\n\n");
			break;
		case 5: //��������޸�
			printf("��������Ҫ�޸ĵ�ѧ��ѧ��:");
            scanf("%s",id);
            printf("��������Ҫ�޸ĵ�ѧ������:");
            scanf("%s",name);
            status = Modify_L(L,id,name);
            if (status)
				printf("��ѧ���ɼ���Ϣ�޸ĳɹ���\n\n");
			else
				printf("�޸�ʧ��!\n\n");
			break;
        case 6: //�����������
			printf("���ɼ��Ӹߵ��ͽ�������!\n");
			BubbleSort(L);
			printf("������ϣ�\n\n");
			break;
        case 7: //����������
			printf("��ǰѧ���ɼ�����ϵͳ��Ϣ����������:\n");
			show(L);
			break;
		}
	}
	return 0;
}


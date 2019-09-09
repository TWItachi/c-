#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
#include<string.h>

struct Student {
	int num;
	char name[20];
	int age;
	long long phone;
	struct Student *next;
};

struct Student *head = NULL;

void show();
void print(struct Student *head);
void search(struct Student *head);
struct Student* input();
void change(struct Student *head);
struct Student* del(struct Student* head);
struct Student* insert(struct Student *head,struct Student *temp);

int main () {
	show();
	return 0;
}

void show() {
	int exit = 1;
	int keep = 1;
	char choice;
	do {
		printf("   ************************ѧ����Ϣ����ϵͳ***********************************\n");  
        printf("   *                                                                         *\n");  
        printf("   *                       1.����ѧ����Ϣ                                    *\n");  
        printf("   *                       2.��ӡѧ����Ϣ                                    *\n");    
        printf("   *                       3.��ѯѧ����Ϣ                                    *\n");   
        printf("   *                       4.�޸�ѧ����Ϣ                                    *\n");      
        printf("   *                       5.�˳�ϵͳ                                        *\n");       
        printf("   ***************************************************************************\n");           
        printf("   �����빦�����: ");
        while(!scanf("%d",&choice)) {
        	printf("�����������������:");
        	fflush(stdin);
		}
		while(choice < 0 || choice >6) {
			printf("���������������������:");
			fflush(stdin); 
		}
		switch(choice) {
			case 1: {
				head = input();  
				keep = 0;
				system("pause");
				break;
			}
			case 2: {
				print(head);
				system("pause");
				break;
			} 
			case 3: {
				search(head);
				system("pause");
				break;
			}
			case 4: {
				change(head);
				break;
			} 
//			case 5 : {
//				if(keep == 0) {
//					printf("�ļ�δ���棬�Ƿ񱣴���˳�����y/n��");
//					fflush(stdin);
//					char temp;
//					temp = getchar();
//					if(temp == 'y'|| temp == 'Y') {
//						save();
//						exit = 0;
//					} 
//					else if(temp == 'n'|| temp == 'N') {
//						exit = 0;
//					}
//					else {
//						printf("��������");
//						system("pause"); 
//					}
//				}
//				else {
//					exit = 0;
//				}
//				break;
//			}
		}
		system("CLS");
	}while(exit == 1);
}
struct Student *input() {
	int cho;
	int number;
	struct Student *p1,*p2;
	char filename[20];
	FILE *read;
	head = NULL;
	printf("   ��ѡ��¼�뷽ʽ:\n");                      
    printf("   1.�ӵ�ǰ����¼��\n");  
    printf("   2.�����е��ļ�(txt�ļ�)¼��\n");  
    printf("   ��ѡ��: "); 
	while(!scanf("%d",&cho)) {
		printf("�����������������룺");
		fflush(stdin);
	}
	printf("\n");
	if(cho == 1) {
		printf("������ѧ������(1~1000)��");
		scanf("%d",&number);
		while(number <=0 || number >=1000) {
			printf("���������������������룺");
			fflush(stdin);
			scanf("%d",&number);
		}
		head = p1 = p2 =(struct Student*)malloc(sizeof(struct Student));
		printf("��������%d��ѧ��",number);
		printf("�밴�����¸�ʽ���룺��� ���� ���� �ֻ�����\n");
		 for(int i = 1;i <= number;i++) {
		 	printf("�������%d��ѧ������Ϣ\n",i);
		 	fflush(stdin);
		 	while(!scanf("%d %s %d %lld",&p2->num,&p2->name,&p2->age,&p2->phone)) {
		 		printf("������������������");
		 		fflush(stdin);
			 }
		 	if(number == 1) {
		 		p2->next = NULL;
			}
			else {
				head = insert(head,p2);
				p2 = (struct Student*)malloc(sizeof(struct Student));
			}
		 }
	}
	else {
		printf("�������ļ�����");
		while(!scanf("%s",filename)) {
			printf("�����������������룺");
			fflush(stdin);
		}
		strcat(filename,".txt");
		while((read = fopen(filename,"r")) == NULL) {
			printf("δ�ҵ����ļ���\n���������룺");
			fflush(stdin);
			scanf("%s",filename);
			strcat(filename,".txt"); 
		}
		if(!fscanf(read,"%d",&number)){
			printf("�ļ����ݳ���");
			fclose(read);
			fflush(stdin);
			return head;
		}
		p2 = p1 = (struct Student*) malloc(sizeof(struct Student));
		for(int i = 1;i <= number;i++) {
			if(!fscanf(read,"%d %s %d %lld",&p2->num,&p2->name,&p2->age,&p2->phone)) {
				fclose(read);
				p2 = head;
				p1 = p2->next;
				do {
					free(p2);
					p2 = p1;
					if(p1 != NULL) {
						p1 = p1->next;
					}
					else {
						break;
					}
				}while(p2 != NULL);
				printf("���ݴ��󣬽���¼��");
				return NULL;
			}
			if(number == 1) {
				p2->next = NULL; 
			}
			else {
				head = insert(head,p2);
				p2 = (struct Student*)malloc(sizeof(struct Student));
			}
		}
		fclose(read);
	}
	printf("�ɹ�¼�룡");
	return head;
}

struct Student* insert(struct Student *head,struct Student *temp) {
	struct Student *p1,*p2;
	if(temp == NULL) {
		printf("�밴�����¸�ʽ���룺��� ���� ���� �ֻ�����:");
		temp = (struct Student *)malloc(sizeof(struct Student));
		while(!scanf("%d %s %d %lld",&p2->num,&p2->name,&p2->age,&p2->phone)) {
			printf("������������������:");
			fflush(stdin);
		}
	}
	if(head == NULL) {
		head = temp;
		head->next = NULL;
	}
	else {
		p1 = p2 =head;
		while(temp->num > p2->num && p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		if(p1 == p2) {
			if(temp->num < p2->num) {
				head = temp;
				temp->next = p2;
			}
			else {
				p2->next = temp;
				temp->next = NULL;
			}
		}
		else {
			if(temp->num < p1->num) {
				p2->next = temp;
				temp->next = p1;
			}
			else {
				p1->next = temp;
				temp->num = NULL;
			}
		}
	
	}
	return head;
}
struct Student *del(struct Student *head) {
	int cho;
	int number;
	printf("������Ҫɾ����ѧ����ţ�");
	scanf("%d",&number);
	struct Student *p1,*p2;
	if(head == NULL) {
		printf("û�п�ɾ������Ϣ���˳�ɾ��"); 
		fflush(stdin); 
	}
	do {
		p1 = p2 = head;
		while(number != p1->num && p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		if(number == p1->num) {
			if(number == p1->num) {
				if(p1->next == NULL && p1 == head) {
					free(p1);
					head = NULL;
				}
				else if (head == p1) {
					head = p1->next;
					free(p1);
				}
				else {
					p2->next = p1->next;
					free(p1);
				}
			}
			printf("ɾ���ɹ�");
		}
		else {
			printf("��ѧ�Ų�����");
			fflush(stdin);
		}
		if(head == NULL) {
			printf("û�п�ɾ����Ϣ���˳�ɾ��");
			fflush(stdin); 
			return head;
		}
		else {
			printf("1,����ɾ��\n");
			printf("2������ɾ��\n");
			printf("��ѡ��:");
			scanf("%d",&cho);
			if(cho == 1) {
				printf("������Ҫɾ����ѧ����ţ�");
				scanf("%d",&number);
			}
			else if(cho!= 2) {
				printf("�������������˳�ɾ��");
			}
		}
	}while(cho == 1);
	return head;
}

void search(struct Student *head) {
	int cho;
	int temp;
	struct Student *p1,*p2;
	if(head == NULL) {
		printf("��ǰ����Ϊ�գ���������Ϣ������");
		fflush(stdin);
		return ;
	}
	p1 = head;
	printf("   1.��ѧ�Ų�ѯѧ����Ϣ\n");  
    printf("   2.��������ѯѧ����Ϣ\n");  
    printf("   ��ѡ��: ");
    while(!scanf("%d",&cho)) {
    	printf("����������������������:");
    	fflush(stdin);
		}
	while(cho != 1 &&cho != 2) {
		printf("��Ǹû�и�ѡ�����������:");
		fflush(stdin);
	}
	printf("\n");
	switch(cho) {
		case 1: {
			do {
				p1 = head;
				printf("��������Ҫ��ѯ��ѧ��");
				while(!scanf("%d",&temp)) {
					printf("������������������");
					fflush(stdin);
				}
				while(p1->num != temp) {
					if(p1->next == NULL) {
						break;
					}
					p1 = p1->next;
				}
				if(p1->num == temp) {
					printf("��ѧ������Ϣ����\n");
					printf("%d\t%s\t%d\t%lld\n",p1->num,p1->name,p1->age,p1->phone);
				}
				else {
					printf("û�и�ѧ����Ϣ\n");
				}
				cho = 0;
			}while(cho == 1);
			break;
		}	
		case 2 : {
			char name[20];
			do{
				p2 = head;
				if(1) {
					printf("��������Ҫ��ѯ������:");
					while(!scanf("%s",name)) {
						printf("����������������������");
						fflush(stdin);
					}
					while(strcmp(name,p2->name) != 0) {
						if(p2->next == NULL) {
							break;
						}
						else {
							p2 = p2->next;
						}
					} 
						if(strcmp(name,p2->name) == 0) {
							printf("��ѧ������Ϣ����\n");
							printf("%d\t%s\t%d\t%lld\n",p2->num,p2->name,p2->age,p2->phone);
							break;
						}
						else {
							printf("��ѯʧ�ܣ�");
							fflush(stdin);
							break;
						}
				}
				cho = 0;
			}while(cho == 2);
			break;
		}
			
	}
}

void print(struct Student *head) {
	int cho;
	struct Student *p1;
	if(head == NULL) {
		printf("�������ݣ���������Ϣ������");
		return ;
	}
	p1 = head;
	printf("��Ϣ�������¸�ʽ�����(ѧ�ţ����������䣬�ֻ�����)\n");
	while(p1 != NULL) {
		printf("%d\t%s\t%d\t%lld\n",p1->num,p1->name,p1->age,p1->phone);
		p1 = p1->next;
	}
}

void change(struct Student *head) {
	int check = 0;
	struct Student *p2,*p1;
	int number;
	int cho;
	int temp = 1; 
	if(head == NULL) {
		printf("�������ݣ���������Ϣ������");
		return ; 
	}
	printf("��������Ҫ�޸ĵ�ѧ�����");
	while(!scanf("%d",&number)) {
		printf("������������������");
		fflush(stdin); 
	}
	do {
		p1 = p2 = head;
		while(p1->num != number) {
			if(p1->next == NULL ) {
				break;
			}
			p2 = p1;
			p1 = p1->next;
			}
			if(p1->num == number ){
				printf("���ҵ���ѧ��\n");
				printf("��ѧ����ϢΪ����ѧ�ţ����������䣬�ֻ����룩");
				printf("%d\t%s\t%d\t%lld\n",p1->num,p1->name,p1->age,p1->phone);
				check = 1;
			}
			if(check) {
				printf("��ѡ��Ҫ�޸ĵ����ݣ�\n");
				printf("1.ѧ��\n");  
            	printf("2.����\n");  
            	printf("3.����\n");  
            	printf("4.�ֻ�����\n");
            	printf("������:");
            	while(!scanf("%d",&cho)) {
            		printf("����������������������");
      		      	fflush(stdin);
				}
				switch(cho) {
					case 1: {
						printf("   �������ѧ��������ѧ����Ϣ: ");  
                    	while(!scanf("%d",&p1->num))  
                    	{  
                    	    printf("   ���������Ϣ����,����������: ");  
                    	    fflush(stdin);  
                    	}  
						break;
					}
					case 2: {
						printf("   �������ѧ��������������Ϣ: ");  
             	       while(!scanf("%s",&p1->name))  
             	       {  
              	          printf("   ���������Ϣ����,����������: ");  
              	          fflush(stdin);  
              		    }  
						break;
					}
					case 3: {
						printf("   �������ѧ��������������Ϣ: ");  
                    	while(!scanf("%d",&p1->age))  
                    	{  
                    	    printf("   ���������Ϣ����,����������: ");  
                    	    fflush(stdin);  
                    	}  
						break;
					}
					case 4: {
						printf("   �������ѧ���������ֻ�����: ");  
                   		while(!scanf("%lld",&p1->phone))  
                    	{  
                        	printf("   ���������Ϣ����,����������: ");  
                        	fflush(stdin);  
                    	}  
						break;
					}
					if(cho == 1) {
						if(p1 == head) {
							head = head->next;
						}
						else if(p1->next == NULL) {
							p2->next = NULL; 
						}
						else {
							p2->next = p1->next;
						}
						head = insert(head,p1);
					}
					printf("�޸ĳɹ���");
				}
			}
			else {
				printf("�Ҳ�����ѧ����������");
			}
			
		if(check) {
			temp = 0;
		}
	}while(temp);
}

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
		printf("   ************************学生信息管理系统***********************************\n");  
        printf("   *                                                                         *\n");  
        printf("   *                       1.输入学生信息                                    *\n");  
        printf("   *                       2.打印学生信息                                    *\n");    
        printf("   *                       3.查询学生信息                                    *\n");   
        printf("   *                       4.修改学生信息                                    *\n");      
        printf("   *                       5.退出系统                                        *\n");       
        printf("   ***************************************************************************\n");           
        printf("   请输入功能序号: ");
        while(!scanf("%d",&choice)) {
        	printf("输入错误，请重新输入:");
        	fflush(stdin);
		}
		while(choice < 0 || choice >6) {
			printf("输入序号有误，请重新输入:");
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
//					printf("文件未保存，是否保存后退出？（y/n）");
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
//						printf("输入有误");
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
	printf("   请选择录入方式:\n");                      
    printf("   1.从当前窗口录入\n");  
    printf("   2.从已有的文件(txt文件)录入\n");  
    printf("   请选择: "); 
	while(!scanf("%d",&cho)) {
		printf("输入有误，请重新输入：");
		fflush(stdin);
	}
	printf("\n");
	if(cho == 1) {
		printf("请输入学生人数(1~1000)：");
		scanf("%d",&number);
		while(number <=0 || number >=1000) {
			printf("您的输入有误，请重新输入：");
			fflush(stdin);
			scanf("%d",&number);
		}
		head = p1 = p2 =(struct Student*)malloc(sizeof(struct Student));
		printf("共需输入%d个学生",number);
		printf("请按照以下格式输入：编号 姓名 年龄 手机号码\n");
		 for(int i = 1;i <= number;i++) {
		 	printf("请输入第%d个学生的信息\n",i);
		 	fflush(stdin);
		 	while(!scanf("%d %s %d %lld",&p2->num,&p2->name,&p2->age,&p2->phone)) {
		 		printf("输入有误，请重新输入");
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
		printf("请输入文件名：");
		while(!scanf("%s",filename)) {
			printf("输入有误，请重新输入：");
			fflush(stdin);
		}
		strcat(filename,".txt");
		while((read = fopen(filename,"r")) == NULL) {
			printf("未找到该文件！\n请重新输入：");
			fflush(stdin);
			scanf("%s",filename);
			strcat(filename,".txt"); 
		}
		if(!fscanf(read,"%d",&number)){
			printf("文件数据出错！");
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
				printf("数据错误，结束录入");
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
	printf("成功录入！");
	return head;
}

struct Student* insert(struct Student *head,struct Student *temp) {
	struct Student *p1,*p2;
	if(temp == NULL) {
		printf("请按照以下格式输入：编号 姓名 年龄 手机号码:");
		temp = (struct Student *)malloc(sizeof(struct Student));
		while(!scanf("%d %s %d %lld",&p2->num,&p2->name,&p2->age,&p2->phone)) {
			printf("输入有误，请重新输入:");
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
	printf("请输入要删除的学生编号：");
	scanf("%d",&number);
	struct Student *p1,*p2;
	if(head == NULL) {
		printf("没有可删除的信息，退出删除"); 
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
			printf("删除成功");
		}
		else {
			printf("该学号不存在");
			fflush(stdin);
		}
		if(head == NULL) {
			printf("没有可删除信息，退出删除");
			fflush(stdin); 
			return head;
		}
		else {
			printf("1,继续删除\n");
			printf("2，结束删除\n");
			printf("请选择:");
			scanf("%d",&cho);
			if(cho == 1) {
				printf("请输入要删除的学生编号：");
				scanf("%d",&number);
			}
			else if(cho!= 2) {
				printf("您的输入有误，退出删除");
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
		printf("当前数据为空，请输入信息后重试");
		fflush(stdin);
		return ;
	}
	p1 = head;
	printf("   1.按学号查询学生信息\n");  
    printf("   2.按姓名查询学生信息\n");  
    printf("   请选择: ");
    while(!scanf("%d",&cho)) {
    	printf("您的输入有误，请重新输入:");
    	fflush(stdin);
		}
	while(cho != 1 &&cho != 2) {
		printf("抱歉没有该选项，请重新输入:");
		fflush(stdin);
	}
	printf("\n");
	switch(cho) {
		case 1: {
			do {
				p1 = head;
				printf("请输入需要查询的学号");
				while(!scanf("%d",&temp)) {
					printf("您的输入有误，请重试");
					fflush(stdin);
				}
				while(p1->num != temp) {
					if(p1->next == NULL) {
						break;
					}
					p1 = p1->next;
				}
				if(p1->num == temp) {
					printf("该学生的信息如下\n");
					printf("%d\t%s\t%d\t%lld\n",p1->num,p1->name,p1->age,p1->phone);
				}
				else {
					printf("没有该学生信息\n");
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
					printf("请输入需要查询的姓名:");
					while(!scanf("%s",name)) {
						printf("您的输入有误，请重新输入");
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
							printf("该学生的信息如下\n");
							printf("%d\t%s\t%d\t%lld\n",p2->num,p2->name,p2->age,p2->phone);
							break;
						}
						else {
							printf("查询失败！");
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
		printf("暂无数据，请输入信息后重试");
		return ;
	}
	p1 = head;
	printf("信息将按以下格式输出：(学号，姓名，年龄，手机号码)\n");
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
		printf("暂无数据，请输入信息后重试");
		return ; 
	}
	printf("请输入需要修改的学生编号");
	while(!scanf("%d",&number)) {
		printf("您的输入有误，请重试");
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
				printf("已找到该学生\n");
				printf("该学生信息为：（学号，姓名，年龄，手机号码）");
				printf("%d\t%s\t%d\t%lld\n",p1->num,p1->name,p1->age,p1->phone);
				check = 1;
			}
			if(check) {
				printf("请选择要修改的内容：\n");
				printf("1.学号\n");  
            	printf("2.姓名\n");  
            	printf("3.年龄\n");  
            	printf("4.手机号码\n");
            	printf("请输入:");
            	while(!scanf("%d",&cho)) {
            		printf("您的输入有误，请重新输入");
      		      	fflush(stdin);
				}
				switch(cho) {
					case 1: {
						printf("   请输入该学生改正的学号信息: ");  
                    	while(!scanf("%d",&p1->num))  
                    	{  
                    	    printf("   输入改正信息有误,请重新输入: ");  
                    	    fflush(stdin);  
                    	}  
						break;
					}
					case 2: {
						printf("   请输入该学生改正的姓名信息: ");  
             	       while(!scanf("%s",&p1->name))  
             	       {  
              	          printf("   输入改正信息有误,请重新输入: ");  
              	          fflush(stdin);  
              		    }  
						break;
					}
					case 3: {
						printf("   请输入该学生改正的年龄信息: ");  
                    	while(!scanf("%d",&p1->age))  
                    	{  
                    	    printf("   输入改正信息有误,请重新输入: ");  
                    	    fflush(stdin);  
                    	}  
						break;
					}
					case 4: {
						printf("   请输入该学生改正的手机号码: ");  
                   		while(!scanf("%lld",&p1->phone))  
                    	{  
                        	printf("   输入改正信息有误,请重新输入: ");  
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
					printf("修改成功！");
				}
			}
			else {
				printf("找不到该学生，请重试");
			}
			
		if(check) {
			temp = 0;
		}
	}while(temp);
}

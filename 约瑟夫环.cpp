#include <iostream>
#include <stdlib.h>
using namespace std;

struct Joseph{
	int number;//ÿһ��Ԫ�ص����
	int password;//ÿһ��Ԫ�ص�����
	struct Joseph *next; //��һ���ڵ� 
}; 

typedef Joseph Node; //�Զ���������������Node 
//���������ǳ�ʼ��Լɪ�� 
Node *init(int n, int array[]) {
    int i = 1;
    Node *head;//����ͷ���
    Node *current;//����ǰ�ڵ�
    Node *next; //������һ���ڵ�
    current = static_cast<Node *>(malloc(sizeof(Node))); //malloc��̬�滮�ڴ� ������һ����СΪNode���ڴ沢��ǿ�ư��׵�ַ��Ϊcurrent 
    current->number = i;//��ʼ����һ���ڵ� 
    current->password = array[i - 1];//������0��ʼ����ʼ������ 
    head = current;//
    //��ʼ�ڶ��������ʼ�� 
    for (i = 2; i <= n; ++i) {
        next = static_cast<Node *>(malloc(sizeof(Node)));//ͬ����next 
        next->number = i;//��� 
        next->password = array[i - 1];//����Ϊarray�����С���Ӧ��ֵ 
        //�����������´����Ľڵ�
        current->next = next;
        current = next;
    }
    //β�ڵ����ӵ�ͷ��㣬�γ�ѭ������
    current->next = head;
    return head;//����ֵΪ 
}
void function(Node *head, int len, int password) {
    Node *pre; //ǰһ���ڵ�
    Node *next; //��һ���ڵ�
    Node *temp; //Ҫɾ���Ľڵ�
    next = head;//��ʼ��
    for (int i = 1; i < len; ++i) {
        pre = next->next;
        next = next->next;
    }
    //����������
    for (int i = 1; i <= len; ++i) {
        //�Ƚ�ָ���ƶ������е�ǰһ��
        for (int j = 1; j < password; ++j) {
            pre = pre->next;
        }
        temp = pre->next;//����Ҫɾ���Ľڵ�
        next = temp->next; //��һ���ڵ�
        password = temp->password; //�޸�����
        cout << temp->number << endl; //����������
        pre->next = next;//��������ȥ���м�ڵ�
        free(temp); //�ͷ��м�ڵ�
    }
}
int main() {
    //���ĳ���
    int len;
    cout << "����Լɪ�򻷵ĳ��ȣ�";
    cin >> len;
    int array[len];
    cout << "������m�ĳ�ʼֵ m:";
    int m;
    cin >> m;
    cout << "������ÿ���˵�����: " << endl;
    for (int i = 0; i < len; ++i) {
        cin >> array[i];
    }
//    int len = 7;
//    int array[] = {3, 1, 7, 2, 4, 8, 4};
//    int m = 6;
    //����Լɪ��
    Node *head = init(len, array);
    function(head, len, m);
    return 0;
}
/*���ȳ�ʼ��һ���ṹ�崢��Լɪ�򻷵�ÿ���������ָ����һ���ڵ��ָ��*/ 
/*Ȼ���ʼ��Լɪ�򻷵�ÿһ����ź����뼰ָ����һ���ڵ��ָ��*/
/*Ȼ��ʼ��ÿ��Ԫ�ظ�ֵ*/
/*1 2 3 4 5 6 7*/
/*3 1 7 2 4 8 4*/





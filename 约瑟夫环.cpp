#include <iostream>
#include <stdlib.h>
using namespace std;

struct Joseph{
	int number;//每一个元素的序号
	int password;//每一个元素的密码
	struct Joseph *next; //下一个节点 
}; 

typedef Joseph Node; //自定义申明数据类型Node 
//接下来我们初始化约瑟夫环 
Node *init(int n, int array[]) {
    int i = 1;
    Node *head;//链表头结点
    Node *current;//链表当前节点
    Node *next; //链表下一个节点
    current = static_cast<Node *>(malloc(sizeof(Node))); //malloc动态规划内存 ，分配一个大小为Node的内存并且强制把首地址换为current 
    current->number = i;//初始化第一个节点 
    current->password = array[i - 1];//数组由0开始，初始化密码 
    head = current;//
    //开始第二个往后初始化 
    for (i = 2; i <= n; ++i) {
        next = static_cast<Node *>(malloc(sizeof(Node)));//同理换成next 
        next->number = i;//序号 
        next->password = array[i - 1];//密码为array数组的小标对应的值 
        //连接链表与新创建的节点
        current->next = next;
        current = next;
    }
    //尾节点连接到头结点，形成循环链表
    current->next = head;
    return head;//返回值为 
}
void function(Node *head, int len, int password) {
    Node *pre; //前一个节点
    Node *next; //后一个节点
    Node *temp; //要删除的节点
    next = head;//初始化
    for (int i = 1; i < len; ++i) {
        pre = next->next;
        next = next->next;
    }
    //遍历所有人
    for (int i = 1; i <= len; ++i) {
        //先将指针移动到出列的前一个
        for (int j = 1; j < password; ++j) {
            pre = pre->next;
        }
        temp = pre->next;//保存要删除的节点
        next = temp->next; //下一个节点
        password = temp->password; //修改密码
        cout << temp->number << endl; //输出出列序号
        pre->next = next;//连接链表，去除中间节点
        free(temp); //释放中间节点
    }
}
int main() {
    //环的长度
    int len;
    cout << "输入约瑟夫环的长度：";
    cin >> len;
    int array[len];
    cout << "请输入m的初始值 m:";
    int m;
    cin >> m;
    cout << "请输入每个人的密码: " << endl;
    for (int i = 0; i < len; ++i) {
        cin >> array[i];
    }
//    int len = 7;
//    int array[] = {3, 1, 7, 2, 4, 8, 4};
//    int m = 6;
    //创建约瑟夫环
    Node *head = init(len, array);
    function(head, len, m);
    return 0;
}
/*首先初始化一个结构体储存约瑟夫环的每个序，密码和指向下一个节点的指针*/ 
/*然后初始化约瑟夫环的每一个序号和密码及指向下一个节点的指针*/
/*然后开始给每个元素赋值*/
/*1 2 3 4 5 6 7*/
/*3 1 7 2 4 8 4*/





#include <iostream>

using namespace std; 

int main()
{
	int n=1;
	while(!((n%2==1)&&(n%3==2)&&(n%4==3)&&(n%5==4)&&(n%6==5)&&(n%7==0))){
		n++;
	}
	cout << "�Ľ���ɰ�n++��Ϊn+=7���㷨ʱ�临�ӶȽ����߱�"<<endl;
	cout << "Count the stairs = " << n << endl;
	return 1;
}//�Ľ���ɰ�n++��Ϊn+=7���㷨ʱ�临�ӶȽ����߱���

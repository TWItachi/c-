#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
extern "C"
{
	WINBASEAPI HWND WINAPI GetConsoleWindow();
}
int main(int argc, char *argv[]) //���߳����н����������߳�Ҳ������
{
	HWND hwnd;
	HDC hdc;
	printf("There are some words in console window!\n�ڿ���̨�����л�ͼ!\n");
	system("Color 3D");
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	MoveToEx(hdc,100,100,NULL);

	LineTo(hdc, 200, 300);
	Rectangle(hdc, 10, 30, 300, 50);
	TextOut(hdc, 10, 10, _TEXT("Hello World\nYesNoConcel!"), 20);
	ReleaseDC(hwnd, hdc);
	getch();
	printf("After drawing!\n");
	return 0;
} //C:\Users\DATONG~1\AppData\Local\Temp\ccBCfKNt.o	��ɾ��4.cpp:(.text+0x68): undefined reference to `__imp_MoveToEx'

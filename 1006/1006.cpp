// 1006.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int S;		//十位的数字
	int B;		//百位的数字
	int G;		//个位的数字
	int flag;	//标记是哪种情况
	if (n >= 100 && n < 1000)
	{
		B = n / 100;
		S = n / 10 % 10;
		G = n % 10;
		flag = 1;
	}
	else if (n >= 10 && n < 100)
	{
		S = n / 10;
		G = n % 10;
		flag = 2;
	}
	else
	{
		G = n;
		flag = 3;
	}
	switch (flag)
	{
	case 1:
		for (int i = 0;i < B;i++)
		{
			cout << 'B';
		}
		for (int i = 0;i < S;i++)
		{
			cout << "S";
		}
		for (int i = 0;i < G;i++)
		{
			cout << i + 1;
		}
		cout << endl;
		break;
	case 2:
		for (int i = 0;i < S;i++)
		{
			cout << "S";
		}
		for (int i = 0;i < G;i++)
		{
			cout << i + 1;
		}
		cout << endl;
		break;
	case 3:
		for (int i = 0;i < G;i++)
		{
			cout << i + 1;
		}
		cout << endl;
		break;
	}
	getchar();
	getchar();
    return 0;
}


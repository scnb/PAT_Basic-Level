// 1036.cpp : 定义控制台应用程序的入口点。
//这道题比较简单，唯一要注意的就是题目要求计算行数时要四舍五入，所以0.5*N后必须要加0.5

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	char C;
	cin >> N >> C;
	int col = N;
	int row = 0.5*N + 0.5;
	for (int i = 0;i < row;i++)
	{
		if (i == 0 || i == row-1)
		{
			for (int j = 0;j < N;j++)
			{
				cout << C;
			}
			cout << endl;
		}
		else
		{
			cout << C;
			for (int j = 0;j < N - 2;j++)
			{
				cout << ' ';
			}
			cout << C;
			cout << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


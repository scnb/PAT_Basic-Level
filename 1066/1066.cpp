// 1066.cpp : 定义控制台应用程序的入口点。
//这道题思路也比较清晰，实现简单。重点还是用new来分配二维数组，以及调用iomanip中的setw和setfill函数来设定输出宽度和填充字符。

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int M, N;		//分别为图像的行数和列数
	int A, B;		//待过滤的灰度值区间端点
	int tmp;		//指定的替换灰度值
	cin >> M >> N >> A >> B >> tmp;
	int **point = new int*[M];
	for (int i = 0;i < M;i++)
	{
		point[i] = new int[N];
	}
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> point[i][j];
			if (point[i][j] >= A && point[i][j] <= B)
			{
				point[i][j] = tmp;
			}
		}
	}
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (j != N - 1)
			{
				cout << setw(3) << setfill('0') << point[i][j] << " ";
			}
			else
			{
				cout << setw(3) << setfill('0') << point[i][j] << endl;
			}
		}
	}
	getchar();
	getchar();
    return 0;
}


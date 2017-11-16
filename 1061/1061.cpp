// 1061.cpp : 定义控制台应用程序的入口点。
//这道题思路比较清晰，实现也比较简单。重要的一点是如何用new分配二维数组，参考第23到27行，先new出一个一维数组来，这个数组中的每一个元素都是一个数组的指针
//然后，再循环给每一个元素（指针）分配空间。

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int *score = new int[M];
	for (int i = 0;i < M;i++)
	{
		cin >> score[i];
	}
	int *ans = new int[M];
	for (int i = 0;i < M;i++)
	{
		cin >> ans[i];
	}
	//分配一个二维数组
	int **stu = new int*[N];
	for (int i = 0;i < N;i++)
	{
		stu[i] = new int[M];
	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> stu[i][j];
		}
	}
	int *sum = new int[N];
	for (int i = 0;i < N;i++)
	{
		sum[i] = 0;
		for (int j = 0;j < M;j++)
		{
			if (stu[i][j] == ans[j])
			{
				sum[i] += score[j];
			}
		}
	}
	for (int i = 0;i < N;i++)
	{
		cout << sum[i] << endl;
	}
	getchar();
	getchar();
    return 0;
}


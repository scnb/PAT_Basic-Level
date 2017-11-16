// 1008.cpp : 定义控制台应用程序的入口点。
//这道题如果不管其他限制条件的话，不难，而且我也没有按照题目要求的做，我没有对数组改变顺序，而是直接从中间某个元素开始
//输出，但是这样很有用，很简单。
//这道题的一个要点在于：要求移动数据的次数尽可能少，所以M应该取值为M%N。

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int *before = new int[N];
	for (int i = 0;i < N;i++)
	{
		cin >> before[i];
	}
	M = M % N;					//关键语句，题目还要求移动数据的次数尽可能少，当M>N=时，相当于有多循环的部分。
	{
		for (int i = N - M;i <N;i++)
		{
			cout << before[i] << " ";
		}
		for (int i = 0;i < N - M;i++)
		{
			if (i != N - M - 1)
			{
				cout << before[i] << " ";
			}
			else
			{
				cout << before[i] << endl;
			}
		}
	}
	getchar();
	getchar();
    return 0;
}


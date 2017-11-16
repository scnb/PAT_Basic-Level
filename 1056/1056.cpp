// 1056.cpp : 定义控制台应用程序的入口点。
//这道题很简单，没啥要特别注意的，另外，一开始想的是，可以组合成N*（N-1）个组合，可以用另外一个数组来把那些数存起来，其实完全不用，
//直接在循环中用sum加起来就可以了。

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int M = N*(N - 1);
	int *a = new int[N];
	for (int i = 0;i < N;i++)
	{
		cin >> a[i];
	}
	//int *b = new int[M];
	int sum = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (i != j)
			{
				sum += a[i] * 10 + a[j];
			}
		}
	}
	cout << sum << endl;
	getchar();
	getchar();
	return 0;
}


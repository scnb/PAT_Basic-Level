// 1038_plus.cpp : 定义控制台应用程序的入口点。
//看了csdn某人的博客才意识到，这道题的思路跟之前一道的题思路一样，即输入的数据的范围是连续且已知的，这样在输入的时候，就能以输入数据为索引进行数组元素的自增来实现计数。

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	int score[100] = { 0 };
	cin >> N;
	int tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		score[tmp]++;
	}
	int K;
	cin >> K;
	for (int i = 0;i < K;i++)
	{
		cin >> tmp;
		if (i != K - 1)
		{
			cout << score[tmp] << " ";
		}
		else
		{
			cout << score[tmp] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


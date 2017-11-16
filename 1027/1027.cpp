// 1027.cpp : 定义控制台应用程序的入口点。
//这道题比较简单，老套路了。重点考察行数与行中符号数、以及前导的空格数的关系

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	char sign;
	cin >> N >> sign;
	int sum = 1;			//最起码有一行
	int i = 1;				//最起码有一行
	for (int j=1;sum < N;j++)
	{
		if (sum + 2 * (2 * j + 1) <= N)
		{
			sum += 2 * (2 * j + 1);
			i += 2;
		}
		else
		{
			break;
		}
	}
	int rows = i;				//行数
	int leave = N - sum;		//表示剩余的符号数量
	for (int j = 0;j <= rows / 2;j++)
	{
		for (int m = 0;m < (rows - i) / 2;m++)
		{
			cout << " ";
		}
		for (int k = 0;k < i;k++)
		{
			cout << sign;
		}
		i = i - 2;
		cout << endl;
	}
	for (int j = 0;j < rows / 2;j++)
	{
		int num = 2 * (j + 1) + 1;
		for (int m = 0;m < (rows - num) / 2;m++)
		{
			cout << " ";
		}
		for (int k = 0;k < num;k++)
		{
			cout << sign;
		}
		cout << endl;
	}
	cout << leave << endl;
	getchar();
	getchar();
    return 0;
}


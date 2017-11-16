// 1013.cpp : 定义控制台应用程序的入口点。
//这道题思路还是比较清晰的，但是要注意的一点是素数的个数是比自然数的个数小很多的，所以题目要求可能取到第10000个素数，
//那么自然数的个数就要比100000还大，为了方便起见，我直接将自然数的个数设为200000个。

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int tmp[100000] = { 0 };
	int k = 0;
	int flag = 0;
	//先把所有的素数找出来
	for (int i = 2;i <= 200000;i++)
	{
		if (i == 2)
		{
			tmp[k++] = 2;
		}
		else
		{
			for (int j = 2;j <= sqrt(i);j++)
			{
				if (i%j == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				tmp[k++] = i;
			}
			flag = 0;
		}
	}
	int sign = 0;
	for (int i = M - 1;i < N;i++)
	{
		if (i == N - 1)
		{
			if (N - M + 1 % 10 == 0)
			{
				cout << tmp[i] << endl;
			}
			else
			{
				cout << tmp[i];
			}
		}
		else
		{
			if (sign < 9)
			{
				cout << tmp[i] << " ";
				sign++;
			}
			else
			{
				cout << tmp[i] << endl;
				sign = 0;
			}
		}
		
	}
	getchar();
	getchar();
    return 0;
}


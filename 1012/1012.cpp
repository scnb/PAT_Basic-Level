// 1012.cpp : 定义控制台应用程序的入口点。
//之前的版本只能得19分，不知道是哪一个测试点不能通过。
//参考了csdn上的博客，将程序作了修改，能够全部通过了。
/*
	①将计算余数那儿，修改成了先计算成num[i]%5，然后就不用在每个if-else中重复计算余数了。
	②将A1-A5定义成数组，原来是五个独立的int变量。
	③定义n[5]，来记录A1-A5中满足条件的数字个数，这样在输出时就能方便的判断哪一种应该输出N了。
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *num = new int[N];
	for (int i = 0;i < N;i++)
	{
		cin >> num[i];
	}
	int A[5] = { 0 };
	int n[5] = { 0 };			//分别记录A1-A5分别有多少个数字符合条件
	int sign = 1;				//正负号标记
	for (int i = 0;i < N;i++)
	{
		int tmp = num[i] % 5;
		if (tmp == 0 && num[i]%2==0)
		{
			A[0] += num[i];
			n[0]++;
		}
		else if (tmp == 1)
		{
			A[1] += sign * num[i];
			sign *= -1;
			n[1]++;
		}
		else if (tmp == 2)
		{
			A[2]++;
			n[2]++;
		}
		else if (tmp == 3)
		{
			A[3] += num[i];
			n[3]++;
		}
		else if (tmp == 4)
		{
			if (num[i] > A[4])
			{
				A[4] = num[i];
				n[4]++;
			}
		}
	}
	for (int i = 0;i < 5;i++)
	{
		if (n[i] != 0)
		{
			if (i == 3)
			{
				cout << setiosflags(ios::fixed) << setprecision(1) << (1.0)*A[i] / n[i] << " ";
			}
			else if (i == 4)
			{
				cout << A[i];
			}
			else
			{
				cout << A[i] << " ";
			}
		}
		else
		{
			if (i != 4)
			{
				cout << "N" << " ";
			}
			else
			{
				cout << "N";
			}
		}
	}
	getchar();
	getchar();
    return 0;
}
// 1001.cpp : 定义控制台应用程序的入口点。
//这道题比较中规中距，没有特别的地方，正常水平。

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	int count = 0;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
		}
		else
		{
			n = (3 * n + 1) / 2;
		}
		count++;
	}
	cout << count << endl;
    return 0;
}


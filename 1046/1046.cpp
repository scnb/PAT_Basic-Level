// 1046.cpp : 定义控制台应用程序的入口点。
//这道题真是···，我真的是想多了，因为做了前面几道题，所以特别注意存放数据的容器的选择。在这道题中明明用int变量来存放4个数就可以了，
//但是我一开始想的是用string数组来存放，结果遇到了一堆out of range的问题。

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;		//N回合
	int one = 0, two = 0;
	int a, b, s1, s2;
	for (int i = 0;i < N;i++)
	{
		cin >> a >> s1 >> b >> s2;
		if (a + b == s1 && a+b!=s2)
		{
			two++;
		}
		else if (a + b == s2 && a+b!=s1)
		{
			one++;
		}
		else
		{
			continue;
		}
	}
	
	cout << one << " " << two << endl;
	getchar();
	getchar();
    return 0;
}


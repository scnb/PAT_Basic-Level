// 1043.cpp : 定义控制台应用程序的入口点。
//这道题比较简单，思路比较清晰，实现起来也比较容易。要点就是遍历string变量，记录P、A、T、e、s、t的数量，并按顺序输出

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int count[6] = { 0 };
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] == 'P')
		{
			count[0]++;
		}
		else if (str[i] == 'A')
		{
			count[1]++;
		}
		else if (str[i] == 'T')
		{
			count[2]++;
		}
		else if (str[i] == 'e')
		{
			count[3]++;
		}
		else if (str[i] == 's')
		{
			count[4]++;
		}
		else if (str[i] == 't')
		{
			count[5]++;
		}
	}
	int sum = 0;
	for (int i = 0;i < 6;i++)
	{
		sum += count[i];
	}
	int P = 0, A = 0, T = 0, e = 0, s = 0, t = 0;
	for (int i = 0;i < sum;i++)
	{
		if (P < count[0])
		{
			cout << "P";
			P++;
		}
		if (A < count[1])
		{
			cout << "A";
			A++;
		}
		if (T < count[2])
		{
			cout << "T";
			T++;
		}
		if (e < count[3])
		{
			cout << 'e';
			e++;
		}
		if (s < count[4])
		{
			cout << "s";
			s++;
		}
		if (t < count[5])
		{
			cout << "t";
			t++;
		}
	}
	cout << endl;
	getchar();
	getchar();
    return 0;
}


// 1043.cpp : �������̨Ӧ�ó������ڵ㡣
//�����Ƚϼ򵥣�˼·�Ƚ�������ʵ������Ҳ�Ƚ����ס�Ҫ����Ǳ���string��������¼P��A��T��e��s��t������������˳�����

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


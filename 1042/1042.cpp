// 1042.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int count[26] = { 0 };			//������¼ÿ����ĸ���ֵĴ���
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			count[str[i] - 97]++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			count[str[i] - 65]++;
		}
	}
	int max = 0;
	for (int i = 0;i < 26;i++)
	{
		if (count[max] < count[i])
		{
			max = i;
		}
	}
	cout << char(max + 97) << " " << count[max] << endl;
	getchar();
	getchar();
    return 0;
}


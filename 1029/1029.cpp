// 1029.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚ�������ʵ��Ҳ�Ƚϼ򵥡���Ҫ���ǿ�ѭ���������������ж������ַ�������Щ�ַ�ȱʧ�ˡ�����Ϊ�˷����������Ҫ��ȱʧ��Сд�ַ�ת���ɴ�д�ַ���

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string normal;
	string real;
	cin >> normal;
	cin >> real;
	vector<char>lost;
	int i = 0, j = 0;
	for (int i = 0;i < normal.length();i++)
	{
		if (normal[i] != real[j])
		{
			if (normal[i] >= 'a' &&normal[i] <= 'z')
			{
				normal[i] -= 32;
			}
			lost.push_back(normal[i]);
			continue;
		}
		else
		{
			j++;
			continue;
		}
	}
	vector<char>final;
	int flag = 0;
	for (int i = 0;i < lost.size();i++)
	{
		for (int j = 0;j < final.size();j++)
		{
			if (lost[i] == final[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			final.push_back(lost[i]);
		}
		else
		{
			flag = 0;
		}
	}
	for (int i = 0;i < final.size();i++)
	{
		cout << final[i];
	}
	getchar();
	getchar();
    return 0;
}


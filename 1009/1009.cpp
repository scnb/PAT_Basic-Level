// 1009.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚϼ򵥣�����ʵ��������Щ���ѣ���Ҫ��ԭ��ѡ�õķ��ַ���������֮��Ļ���ת�治���ݡ�
/*
	���磬char���͵��ַ����ܴ��string��ı�����֮����˵����ô�ƿڣ�����Ϊstring��һ�������ͣ�������C++�����õı������ͣ�
	�����ڻ���ת��ʱ���ںܶ�ӡ�
	���������õ�����string�������洢���룬Ȼ����һ��vector��������ÿһ��Ԫ��Ϊstring���͵ı�������string�����е�ĳһ��Ԫ�ش浽vector�е�ĳһ��
	�����С��ڼ��漰�����Ƚ�str[i]ת��Ϊchar���ͣ�Ȼ��������vector���append���������ַ��浽vector�е�string�����С�
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int count = 1;
	int len = str.length();
	for (int i = 0;i < len;i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	if (count == 1)
	{
		cout << str << endl;
		getchar();
		return 0;
	}
	vector<string> a(count);
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0;i < len;i++)
	{
		if (str[i] == ' ')
		{
			for (;j < i;j++)
			{
				char tmp = str[j];
				a[k].push_back(tmp);
			}
			k++;
			j++;
		}
		if (k == count - 1)
		{
			for (int m = i + 1;m < len;m++)
			{
				char tmp = str[m];
				a[k].push_back(tmp);
			}
			break;
		}
	}
	for (int k = count - 1;k >= 0;k--)
	{
		if (k != 0)
		{
			cout << a[k] << " ";
		}
		else
		{
			cout << a[k] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


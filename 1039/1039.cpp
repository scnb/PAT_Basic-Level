// 1039.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·����򵥣�ʵ������Ҳ�Ƚ�˳����
/*
	Ҫ�����ڣ�
	���ڼ�¼capital��letter��num�����������ʱ��ע����������ȷ��������num���飬����str[i]Ҫ��'0'������0�жϣ�Ȼ��������str1[i]-48
	���ڵڶ���forѭ���ж��У������������str2��Ӧ���ַ�����ôӦ�ý������Ӧ��Ԫ�ؼ�1���Է�ֹstr2��ͬһ��Ԫ�ص��������str1�ж�Ӧ��Ԫ�����飬����:str1="abcYY2",str2="abcYYY2"����Ȼstr2�е�Y��str1�еĶ�һ��
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int capital[26] = { 0 };		//��¼str1��ÿ����д��ĸ�ĸ���
	int letter[26] = { 0 };			//��¼str1��ÿ��Сд��ĸ�ĸ���
	int num[10] = { 0 };			//��¼str1��ÿ�����ֵĸ���
	for (int i = 0;i < str1.length();i++)
	{
		if (str1[i] >= 'a'&&str1[i] <= 'z')
		{
			letter[str1[i] - 97]++;
		}
		else if (str1[i] >= 'A'&&str1[i] <= 'Z')
		{
			capital[str1[i] - 65]++;
		}
		else if (str1[i] >= '0' && str1[i] <= '9')
		{
			num[str1[i]-48]++;
		}
	}
	int flag = 0;			//������¼str2���Ƿ����ַ�����str1�У�����У���flag��1��count��1
	int count = 0;			//������¼str1��ȱ�ټ�������
	for (int i = 0;i < str2.length();i++)
	{
		if (str2[i] >= 'a'&&str2[i] <= 'z')
		{
			if (letter[str2[i] - 97] != 0)
			{
				letter[str2[i] - 97]--;
				continue;
			}
			else
			{
				flag = 1;
				count++;
			}
		}
		else if (str2[i] >= 'A'&&str2[i] <= 'Z')
		{
			if (capital[str2[i] - 65] != 0)
			{
				capital[str2[i] - 65]--;
				continue;
			}
			else
			{
				flag = 1;
				count++;
			}
		}
		else if (str2[i] >= '0' && str2[i] <= '9')
		{
			if (num[str2[i] - 48] != 0)
			{
				num[str2[i] - 48]--;
				continue;
			}
			else
			{
				flag = 1;
				count++;
			}
		}
	}
	if (flag == 0)
	{
		cout << "Yes " << str1.length() - str2.length() << endl;
	}
	else
	{
		cout << "No " << count << endl;
	}
	getchar();
	getchar();
    return 0;
}
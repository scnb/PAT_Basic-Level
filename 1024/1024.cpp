// 1024.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˵�Ѳ��ѣ�˵������Ҳ���ӣ���Ҫ�ľ���Ҫ����ע�����Ҫ�Ѳ������塢��ȫ��ע����������
/*
	����˼·���ٶ���string����������
			  ���жϵ�һ���ַ���+����-�������ñ�ǣ������-������vector�д���-
			  ��Ȼ��ѭ���������֣�ֱ������С����ֹͣ
			  ������С������ѭ���������֣�ֱ������E
			  ������E���ж���һ���ַ���+����-�������ñ��
			  ��ʣ�µ����ֶ���ָ����ֵ�Ĳ��֣��������ֵ�Ƕ���
			  �߽��з����жϣ�����sign��flag�ֱ�Ϊ���������������flagΪ��ʱ�����п���N��m�Ĵ�С���
	�����ص��õ���vector��insert������insert(�õ�����ָʾ��λ�ã����뼸���ַ�������ʡ�ԣ�������ʲô�ַ�/���֣�
	�����������insert����0��С���㡣
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string str;
	int m = 0;						//������¼С��������м�����
	int N = 0;						//������¼ָ����ֵ
	int flag;						//������¼ָ����������1��ʾ����0��ʾ��
	int sign = 0;					//��ʾ�������ֵ�������1��ʾ����0��ʾ��
	cin >> str;
	vector<int> num;
	if (str[0] == '-')			//�鿴��һ���ַ����ж�����
	{
		num.push_back('-');
		sign = 1;
	}
	int i = 1;
	while (str[i] != '.')
	{
		num.push_back(str[i]-'0');
		i++;
	}
	i++;
	while (str[i] != 'E')
	{
		num.push_back(str[i] - '0');
		i++;
		m++;
	}
	i++;
	if (str[i] == '+')
	{
		flag = 0;
	}
	else if (str[i] == '-')
	{
		flag = 1;
	}
	i++;
	int index = str.length() - i - 1;					//����ָ����ֵ�����м�λ
	for (;i < str.length();i++)
	{
		N += (str[i] - '0')*pow(10, index--);
	}

	if (flag == 1)													//��ʾӦ����ǰ�油0����N��
	{
		if (sign == 1)
		{
			vector<int>::iterator it = num.begin()+1;
			num.insert(it, N, 0);									//�ڵ�һ������ǰ����N��0
			it = num.begin() + 2;
			num.insert(it, '.');
		}
		else
		{
			vector<int>::iterator it = num.begin();
			num.insert(it, N, 0);
			it = num.begin() + 1;										//����С����
			num.insert(it, '.');
		}					
	}
	else															//��ʾӦ���ں��油0����N-m�������N����m��
	{
		if (N >= m)
		{
			vector<int>::iterator it = num.end();
			num.insert(it, N - m, 0);
		}
		else
		{
			vector<int>::iterator it = num.end() - (m - N);
			num.insert(it, '.');								//����С����
		}
	}
	for (int i = 0;i < num.size();i++)
	{
		if (num[i] == 45)
		{
			cout << "-";
		}
		else if (num[i] == '.')
		{
			cout << ".";
		}
		else
		{
			cout << num[i];
		}
	}
	getchar();
	getchar();
	return 0;
}
// 1023.cpp : �������̨Ӧ�ó������ڵ㡣
//����Ӧ��Ѱ�Ҵ���0���Ҵ��ڵ����ĸ�����ԭ���ĳ�����ֱ�Ӵ�1��ʼ�ģ��������̫ɵ�ˣ�û�п��ǵ�1�����ڵ����������
//��ȷ��˼·������Ӧ���жϵ�һ����0���Ҹ�����Ϊ0�����Ǽ�������Ϊn����Ȼ����vector�д���һ�������n��֮���ȴ�0���ڰ������n���ȥ������ٶ�������������ѭ����

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num[10] = { 0 };
	for (int i = 0;i < 10;i++)
	{
		cin >> num[i];
	}
	vector<int> min;
	int i = 1;
	while (num[i] == 0)
	{
		i++;
	}
	min.push_back(i);					//�ȴ�һ����ȥ���ڶ���������ÿ��ǲ���0
	
	for (int k = 0;k < num[0];k++)
	{
		min.push_back(0);
	}
	for (int j = 0;j < num[i] - 1;j++)
	{
		min.push_back(i);
	}
	for (i++;i < 10;i++)
	{
		for (int j = 0;j < num[i];j++)
		{
			min.push_back(i);
		}
	}
	for (int i = 0;i < min.size();i++)
	{
		cout << min[i];
	}
	getchar();
	getchar();
    return 0;
}


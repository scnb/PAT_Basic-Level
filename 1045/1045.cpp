// 1045.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˵����˼·�򵥣�������ȷʵû���������
//�����ǲο���CSDN������˼�����(http://blog.csdn.net/qq_30091945/article/details/54882075)�Ĳ��ͣ����У����Ĵ�������һ��ȱ�ݣ�
//������Ԫ�ظ���Ϊ0ʱ��ҲҪ������С����������Ԫ��ʱ����Ҫ�ж�һ���Ƿ����Ϊ0��

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<int> num;
	int tmp;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	int max = 0;
	vector<int> sorted = num;
	sort(sorted.begin(), sorted.end());
	vector<int> flag;
	for (int i = 0;i < num.size();i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
		if (num[i] == max && sorted[i] == max)
		{
			flag.push_back(max);
		}
	}
	cout << flag.size() << endl;
	if (flag.size() == 0)
	{
		cout << endl;
	}
	else
	{
		for (int i = 0;i < flag.size();i++)
		{
			if (i != flag.size() - 1)
			{
				cout << flag[i] << " ";
			}
			else
			{
				cout << flag[i] << endl;
			}
		}
	}
    return 0;
}
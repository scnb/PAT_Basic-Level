// 1064.cpp : �������̨Ӧ�ó������ڵ㡣
//�����Ƚϼ򵥣�ʵ��Ҳ�Ƚ����ס���Ҫע���һ������ĿҪ��Ĭ��һ�������Լ����Լ������ѣ�����������Ҫ��friend_num����ȫ����ֵΪ1

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int friend_num[37] = { 0 };				//��Ϊ��������������9999��������֤�������36
	for (int i = 0;i < 37;i++)
	{
		friend_num[i] = 1;
	}
	int N;
	cin >> N;
	vector<string> num;
	string tmp="";
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	int sum = 0;
	for (int i = 0;i < N;i++)
	{
		sum = 0;
		for (int j = 0;j < num[i].length();j++)
		{
			sum += int(num[i][j] - 48);
		}
		friend_num[sum]++;
	}
	int count = 0;						//��¼�ж��ٸ�����֤��
	vector<int> id;
	for (int i = 0;i < 37;i++)
	{
		if (friend_num[i] > 1)
		{
			count++;
			id.push_back(i);			//�Ѹ�����֤�ż�¼���������һ�Ҫ��������
		}
	}
	sort(id.begin(), id.end());
	cout << count << endl;
	for (int i = 0;i < count;i++)
	{
		if (i != count - 1)
		{
			cout << id[i] << " ";
		}
		else
		{
			cout << id[i] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
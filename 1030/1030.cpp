// 1030.cpp : �������̨Ӧ�ó������ڵ㡣
//������е��Ѷȣ�����ʵ�ֱȽϼ�
//���յ÷�22�֣�����3��

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, P;
	cin >> N >> P;
	vector<long> num;
	long tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	int count1 = 0;							//��¼��������������м���Ԫ��
	int count2 = 0;
	long M = num[N - 1];
	for (int i = 0;i < num.size();i++)
	{
		if (M <= num[i] * P)
		{
			count1 = num.size() - i;
			break;
		}
	}
	long m = num[0];
	for (int i = num.size() - 1;i >= 0;i--)
	{
		if (num[i] <= m*P)
		{
			count2 = i + 1;
			break;
		}
	}
	int count = 0;
	if (count1 >= count2)
	{
		count = count1;
	}
	else
	{
		count = count2;
	}
	cout << count << endl;
    return 0;
}
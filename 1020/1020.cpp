// 1020.cpp : �������̨Ӧ�ó������ڵ㡣
//�������Ҫע��һ�¼��㣺
//������Ŀ���������ۼ۶���������Ҳ����˵Ҫ���double��
//��������whileѭ���У����ܴ���iС��0������D������0�������Ҳ����˵D�����еĿ����������������Ҫ�ж�i�Ĵ�С��

#include "stdafx.h"
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N;
	double D;
	cin >> N >> D;
	vector<double>storage;
	vector<double>value;
	vector<double>price;
	map<double, int>flag;						//��¼ÿ���±��ĵ��۵Ĵ�С����������
	double tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		storage.push_back(tmp);
	}
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		value.push_back(tmp);
	}
	for (int i = 0;i < N;i++)					//����ÿ���±��ĵ���
	{
		price.push_back((value[i] * 1.0) / storage[i]);
		flag[price[i]] = i;
	}
	sort(price.begin(), price.end());
	double sum = 0.0;
	int i = price.size() - 1;					//iָ��price�����һ��Ԫ�أ������������Ǹ�
	while (D > 0)
	{
		int j = flag[price[i]];
		double current = storage[j];
		if (D >= current)
		{
			sum += value[j];
			D = D - current;
		}
		else
		{
			sum += price[i] * D;
			D = D - D;
		}
		i--;
		if (i < 0)
		{
			break;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
	system("pause");
    return 0;
}
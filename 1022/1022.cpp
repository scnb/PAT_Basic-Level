// 1022.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚ������������жϳ�A+B�Ĵ�С���ᳬ��int�����ֵ��Ȼ�󽫺�ͨ���۳��ķ�ʽ���D���ơ�
//�ж�ѭ��ֹͣ��������Ҫ����ע��һ�£���sumС��D��ʱ�򣬲���ֹͣѭ����������sum%D==0

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int A, B, D;
	cin >> A >> B >> D;
	vector<int>store;
	int sum = A + B;
	while (sum >= D)
	{
		store.push_back(sum%D);
		sum = sum / D;
	}
	store.push_back(sum);
	int len = store.size();
	for (int i = len-1;i >= 0;i--)
	{
		cout << store[i];
	}
	getchar();
	getchar();
    return 0;
}


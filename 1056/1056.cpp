// 1056.cpp : �������̨Ӧ�ó������ڵ㡣
//�����ܼ򵥣�ûɶҪ�ر�ע��ģ����⣬һ��ʼ����ǣ�������ϳ�N*��N-1������ϣ�����������һ������������Щ������������ʵ��ȫ���ã�
//ֱ����ѭ������sum�������Ϳ����ˡ�

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int M = N*(N - 1);
	int *a = new int[N];
	for (int i = 0;i < N;i++)
	{
		cin >> a[i];
	}
	//int *b = new int[M];
	int sum = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (i != j)
			{
				sum += a[i] * 10 + a[j];
			}
		}
	}
	cout << sum << endl;
	getchar();
	getchar();
	return 0;
}


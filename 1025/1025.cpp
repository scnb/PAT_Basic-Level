// 1025.cpp : �������̨Ӧ�ó������ڵ㡣
//������е㸴�ӣ���Ҫ�ú���һ�롣
//���÷�24�֣�����һ�֡�
//�ص㻹����ô����Ĵ洢���ݣ�����ʲô���ķ�ʽ��ʲô����˳�����洢���ݡ�
//��������������100000��Ԫ�ص����飬һ���Ե�ַΪ��������Žڵ��ֵ����һ����ǰһ���ڵ�ĵ�ַΪ�������洢��һ���ڵ�ĵ�ַ��
//Ȼ������������vector�������ֱ�˳���ŵ�ַ��ֵ��
//��󣬶�������vector���зֱ�ת����ת���ֵĳ���Ƚϼ򵥡�
//Ҫ�� 0 < N <= 100000  0 < K <=N

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
	int N, K;
	int value[100000];			//ͨ���Ե�ַΪ�������洢ÿ���ڵ��ֵ
	int address[100000];			//ͨ����ǰһ���ڵ�ĵ�ַΪ�������洢��һ���ڵ�ĵ�ַ
	int first;					//�洢�ڵ��׵�ַ��ֵ
	cin >> first >> N >> K;
	int add, val, next;
	freopen("input.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		cin >> add >> val >> next;
		value[add] = val;
		address[add] = next;
	}
	vector<int> addr;
	addr.push_back(first);
	vector<int> num;
	num.push_back(value[first]);
	for (int i = 1;i < N;i++)
	{
		addr.push_back(address[addr[i - 1]]);
		num.push_back(value[addr[i]]);
	}
	
	for (int i = 0;i < N;i += K)
	{
		if (N - i >= K)
		{
			int t = 1;
			for (int j = i;j < i + K / 2;j++,t++)
			{
				int tmp;
				tmp = addr[j];
				addr[j] = addr[i + K - t];
				addr[i + K - t] = tmp;
				tmp = num[j];
				num[j] = num[i + K - t];
				num[i + K - t] = tmp;
			}
		}
		else
		{
			break;
		}
	}

	for (int i = 0;i < N;i++)
	{
		if (i != N - 1)
		{
			cout << setw(5) << setfill('0') << addr[i] << " " << num[i] << " " << setw(5) << setfill('0') << addr[i + 1] << endl;
		}
		else
		{
			cout << setw(5) << setfill('0') << addr[i] << " " << num[i] << " " << -1 << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
// 1021.cpp : �������̨Ӧ�ó������ڵ㡣
//������ļ����£�����һ��python�汾���㷨�������������ʱ�����������Ե㲻��ͨ������֪����ʲôԭ��
//�Ժ������ʱ����������C++������һ���ٶȿ죬���Ǵ�Ҷ����õ�C++��Ѱ�Ҵ�ʱ���㡣
//�������ʵ�����ѣ���Ҫ��Ҫ���ǵ����������1000λ�ģ���˱���Ҫ���ַ��������ա�Ȼ����sort�㷨��string����������ǰ��Ԫ�ضԱ��Ƿ���ȣ���ü���������
//�Ѷ�Ӧ����ֵ��countֵ�ֱ�����һ�������������ֵ��

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>		//���������㷨
using namespace std;

int main()
{
	string N;
	int count = 1;
	int bit[1000] = { 0 };
	cin >> N;
	sort(N.begin(), N.end());
	for (int i = 0;i < N.length();i++)
	{
		if (N[i] == N[i + 1])
		{
			count++;
		}
		else
		{
			bit[N[i]-48] = count;
			count = 1;
		}
	}
	for (int i = 0;i<1000;i++)
	{
		if (bit[i] != 0)
		{
			cout << i << ":" << bit[i] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


// 1019.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚ���������Ҫ��Ҫѡ����ʵ����� (�� 
//����ѡ��������N�������룬Ȼ�󽫸�λ������vector�У���Ϊvector����ʹ���Լ��ĺ�algorithm�е���ת�����������ȽϷ���
//Ȼ�󣬲��ϵ�ѭ����֪��������Ĳ�ֵ����6174��break����whileѭ�����ڼ���Ҫ�Ĺ������ǰ��ַ���ת�����������������ж��Ƿ��break��Ȼ�����break�������ٰ�����ת���ַ�������ִ��ѭ����

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<char>a;
	vector<char>b;
	cin >> N;
	if (N % 1111 == 0)
	{
		cout << N <<" - " << N << " = " << "0000" << endl;
		getchar();
		getchar();
		return 0;
	}
	a.push_back(N / 1000);
	a.push_back(N % 1000 / 100);
	a.push_back(N % 100 / 10);
	a.push_back(N % 10);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i = 0;i < 4;i++)
	{
		b.push_back(a[3 - i]);
	}
	int A, B;
	while (1)
	{
		A = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] * 1;
		B = b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3] * 1;
		N = A - B;
		cout << setw(4) << setfill('0') << A << " - "<< setw(4) << setfill('0') << B << " = " << setw(4) << setfill('0') << N <<endl;
		if (N == 6174)
		{
			break;
		}
		else
		{
			a[0] = (N / 1000);
			a[1] = (N % 1000 / 100);
			a[2] = (N % 100 / 10);
			a[3] = (N % 10);
			sort(a.begin(), a.end());
			reverse(a.begin(), a.end());
			for (int i = 0;i < 4;i++)
			{
				b[i] = (a[3 - i]);
			}
		}
	}
	getchar();
	getchar();
    return 0;
}


// 1063.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚϼ򵥣�ʵ������Ҳ�Ƚ����ס�

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int max = 0;
	int sum = 0;
	int tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		sum += tmp*tmp;
		cin >> tmp;
		sum += tmp*tmp;
		if (sum > max)
		{
			max = sum;
		}
		sum = 0;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << sqrt(max) << endl;
	getchar();
	getchar();
    return 0;
}


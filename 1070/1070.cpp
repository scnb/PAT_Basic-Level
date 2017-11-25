// 1070.cpp : �������̨Ӧ�ó������ڵ㡣
//��������ǳ������ϵļ򵥣�����������25�ֵ��⡤����

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int N;
	vector<double> len;
	double tmp;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		len.push_back(tmp);
	}
	sort(len.begin(), len.end());
	double length = len[0];
	for (int i = 1;i < N;i++)
	{
		length = (length + len[i]) / 2;
	}
	if ((length - int(length)) >= 0.5)
	{
		cout << int(length - 0.5) << endl;
	}
	else
	{
		cout << int(length) << endl;
	}
    return 0;
}
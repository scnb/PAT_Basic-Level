// 1070.cpp : 定义控制台应用程序的入口点。
//这道题真是出乎意料的简单，不敢相信是25分的题···

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
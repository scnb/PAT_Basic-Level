// 1020.cpp : 定义控制台应用程序的入口点。
//这道题需要注意一下几点：
//①输入的库存量和总售价都是正数，也就是说要存成double型
//②在最后的while循环中，可能存在i小于0，但是D还大于0的情况，也就是说D比所有的库存总量还大，所以需要判断i的大小。

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
	map<double, int>flag;						//记录每种月饼的单价的大小，及其索引
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
	for (int i = 0;i < N;i++)					//计算每种月饼的单价
	{
		price.push_back((value[i] * 1.0) / storage[i]);
		flag[price[i]] = i;
	}
	sort(price.begin(), price.end());
	double sum = 0.0;
	int i = price.size() - 1;					//i指向price中最后一个元素，即单价最大的那个
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
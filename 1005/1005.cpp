// 1005.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int K;
	vector<int>num;
	int tmp;
	cin >> K;
	for (int i = 0;i < K;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	map<int, bool>relation_num;					//用来记录每个整数在进行3n+1猜想时的中间值
	for (int i = 0;i < K;i++)
	{
		int n = num[i];
		while (n != 1)
		{
			if (n % 2 == 0)
			{
				n = n / 2;
				relation_num[n] = true;
			}
			else
			{
				n = (3 * n + 1) / 2;
				relation_num[n] = true;
			}
		}
	}
	vector<int> key_num;						//存放关键数字
	for (int i = 0;i < K;i++)
	{
		if (relation_num[num[i]] != true)
		{
			key_num.push_back(num[i]);
		}
	}
	sort(key_num.begin(), key_num.end());
	int len = key_num.size();
	if (len != 0)
	{
		cout << key_num[len-1];
		for (int i=len-2;i>=0;i--)
		{
			cout << " " << key_num[i];
		}
	}
	getchar();
	getchar();
    return 0;
}


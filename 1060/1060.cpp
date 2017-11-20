// 1060.cpp : 定义控制台应用程序的入口点。
//这道题首先我自己想了一晚上，最终的得分是20分。并且我的实现比较复杂，需要考虑比较多的条件。
//最后，还是参考了一些博主的答案，发现他们大多用到是同一种算法，即对路程进行排序，并反向遍历，逐一判断是否比N-i大，
//如果，遇到某一里程不大于N-i，则表示上一个N-i为最大的E。

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<int> miles;
	int tmp;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		miles.push_back(tmp);
	}
	sort(miles.begin(),miles.end());
	int E = 0;
	if (miles[0] > N)
	{
		cout << N << endl;
	}
	else
	{
		for (int i = N - 1;i >= 0;i--)
		{
			if (miles[i] <= N - i)
			{
				E = N - i - 1;
				cout << E << endl;
				break;
			}
		}
	}
    return 0;
}
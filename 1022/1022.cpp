// 1022.cpp : 定义控制台应用程序的入口点。
//这道题思路比较清晰，首先判断出A+B的大小不会超过int的最大值，然后将和通过累除的方式拆成D进制。
//判断循环停止的条件需要额外注意一下：当sum小于D的时候，才能停止循环，而不是sum%D==0

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int A, B, D;
	cin >> A >> B >> D;
	vector<int>store;
	int sum = A + B;
	while (sum >= D)
	{
		store.push_back(sum%D);
		sum = sum / D;
	}
	store.push_back(sum);
	int len = store.size();
	for (int i = len-1;i >= 0;i--)
	{
		cout << store[i];
	}
	getchar();
	getchar();
    return 0;
}


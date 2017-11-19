// 1045.cpp : 定义控制台应用程序的入口点。
//这道题说起来思路简单，但是我确实没有想出来。
//本题是参考的CSDN博主：思雨独辰(http://blog.csdn.net/qq_30091945/article/details/54882075)的博客，其中，他的代码中有一处缺陷，
//即，在元素个数为0时，也要输出两行。所以在输出元素时，需要判断一下是否个数为0。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<int> num;
	int tmp;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	int max = 0;
	vector<int> sorted = num;
	sort(sorted.begin(), sorted.end());
	vector<int> flag;
	for (int i = 0;i < num.size();i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
		if (num[i] == max && sorted[i] == max)
		{
			flag.push_back(max);
		}
	}
	cout << flag.size() << endl;
	if (flag.size() == 0)
	{
		cout << endl;
	}
	else
	{
		for (int i = 0;i < flag.size();i++)
		{
			if (i != flag.size() - 1)
			{
				cout << flag[i] << " ";
			}
			else
			{
				cout << flag[i] << endl;
			}
		}
	}
    return 0;
}
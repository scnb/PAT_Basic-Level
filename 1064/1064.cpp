// 1064.cpp : 定义控制台应用程序的入口点。
//这道题比较简单，实现也比较容易。需要注意的一点是题目要求默认一个整数自己是自己的朋友，所以我们需要将friend_num数组全部赋值为1

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int friend_num[37] = { 0 };				//因为输入的最大数字是9999，则朋友证号最大是36
	for (int i = 0;i < 37;i++)
	{
		friend_num[i] = 1;
	}
	int N;
	cin >> N;
	vector<string> num;
	string tmp="";
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	int sum = 0;
	for (int i = 0;i < N;i++)
	{
		sum = 0;
		for (int j = 0;j < num[i].length();j++)
		{
			sum += int(num[i][j] - 48);
		}
		friend_num[sum]++;
	}
	int count = 0;						//记录有多少个朋友证号
	vector<int> id;
	for (int i = 0;i < 37;i++)
	{
		if (friend_num[i] > 1)
		{
			count++;
			id.push_back(i);			//把该朋友证号记录下来，并且还要进行排序
		}
	}
	sort(id.begin(), id.end());
	cout << count << endl;
	for (int i = 0;i < count;i++)
	{
		if (i != count - 1)
		{
			cout << id[i] << " ";
		}
		else
		{
			cout << id[i] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
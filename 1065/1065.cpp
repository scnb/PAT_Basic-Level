// 1065.cpp : 定义控制台应用程序的入口点。
//这道题中等难度，需要仔细想一想怎么分别确定某个本身就是个单身狗，还是他只是一个来去参加派对。
//重点在于如何判断他是否一个人去参加派对。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <stdlib.h>
using namespace std;

int main()
{
	int N, M;
	map<int,int> couple;
	for (int i = 0;i < 100000;i++)
	{
		couple[i] = -1;
	}
	int flag[100000] = { 0 };
	vector<int> visitor;
	vector<int> single;
	vector<int> count;					//记录落单的人数
	cin >> N;
	int tmp1;
	int tmp2;
	//freopen("input1.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		cin >> tmp1;
		cin >> tmp2;
		couple[tmp1] = tmp2;
		couple[tmp2] = tmp1;
	}
	getchar();
	cin >> M;
//	freopen("input2.txt", "r", stdin);
	for (int i = 0;i < M;i++)
	{
		cin >> tmp1;
		visitor.push_back(tmp1);
	}
	sort(visitor.begin(), visitor.end());
	for (int i = 0;i < M;i++)
	{
		int a = visitor[i];
		flag[a] += 1;
		flag[couple[a]] += 1;
	}
	for (int i = 0;i < M;i++)
	{
		if (couple[visitor[i]] == -1)				//这是本身就是单身的情况
		{
			count.push_back(i);						//记录落单人的索引
		}
		else if (flag[visitor[i]] != 2)										//这里考虑本来不是单身，但是只有一个人参加聚会的
		{
			count.push_back(i);
		}
	}
	int len = count.size();
	cout << len << endl;
	for (int i = 0;i < len;i++)
	{
		if (i != len - 1)
		{
			cout << setw(5) << setfill('0') << visitor[count[i]] << " ";
		}
		else
		{
			cout << setw(5) << setfill('0') << visitor[count[i]] << endl;
		}
	}
    return 0;
}
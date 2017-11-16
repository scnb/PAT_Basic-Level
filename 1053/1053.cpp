// 1053.cpp : 定义控制台应用程序的入口点。
//这道题给我一个很大的启示是：如果没有好的方法来存储数据时，那就直接进行计算
//惨痛的教训啊：首先我不应该只想着把数据存起来再计算，其实依次读一个数，然后进行相应的操作更容易完成任务。
//然后，我忘了for循环中的比较部分的值可以是未知的，只要在比价之前它有合适的值就可以。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int N;
	double e;
	int D;
	double possible_empty = 0.0;
	double empty = 0.0;
	cin >> N >> e >> D;
	for (int i = 0;i < N;i++)
	{
		int K;
		double tmp;
		int count = 0;
		cin >> K;
		for (int j = 0;j < K;j++)
		{
			cin >> tmp;
			if (tmp < e)
			{
				count++;
			}
		}
		if (count > K / 2)
		{
			if (K > D)
			{
				empty += 1;
			}
			else 
			{
				possible_empty += 1;
			}
		}
	}
	possible_empty = possible_empty / (N*1.0) * 100;
	empty = empty / (N*1.0) * 100;
	cout << setiosflags(ios::fixed) << setprecision(1) << possible_empty << "%" << " " << setiosflags(ios::fixed) << setprecision(1) << empty << "%" << endl;
	getchar();
	getchar();
    return 0;
}


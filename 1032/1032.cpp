// 1032.cpp : 定义控制台应用程序的入口点。
//这道题思路比较简单，实现也比较容易，但是第一版程序在测试时，有一个测试点超时。
/*
	所以我修改了第31-第34行，由两层for循环转成了一层for循环，直接从0到N-1循环，用id[i]-1作为sum的索引，这样就能直接把score[i]加到对应的学校上了。
	这样就可以解决超时的问题。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *id = new int[N];
	int *score = new int[N];
	int max = 0;					//学校编号最大的对应的索引
	for (int i = 0;i < N;i++)
	{
		cin >> id[i];
		cin >> score[i];
		if (id[max] < id[i])
		{
			max = i;
		}
	}
	int school = id[max];
	int *sum = new int[school] {0};
	for(int i=0;i<N;i++)
	{
		sum[id[i] - 1] += score[i];
	}
	int max_sum = 0;
	for (int i = 0;i < school;i++)
	{
		if (sum[max_sum] < sum[i])
		{
			max_sum = i;
		}
	}
	cout << max_sum+1 << " " << sum[max_sum] << endl;
	getchar();
	getchar();
    return 0;
}
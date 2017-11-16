// 1038.cpp : 定义控制台应用程序的入口点。
//统计同成绩学生
/*
	在查找相同分数的时候，两层for循环会超时
	改成二分法查找，还是会超时
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(vector<int>score, int N, int tmp);

int main()
{
	int N;
	cin >> N;
	vector<int>score;
	int tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		score.push_back(tmp);
	}
	int K;
	cin >> K;
	vector<int>find;
	vector<int>count;
	for (int i = 0;i < K;i++)
	{
		cin >> tmp;
		find.push_back(tmp);
		count.push_back(0);
	}
	sort(score.begin(), score.end());			//从小到大进行排序
	int i = 0, j = 0;
	for (i = 0;i < K;i++)
	{
		count[i] = BinarySearch(score, N, find[i]);
	}

	cout << count[0];
	for (int i = 1;i < K;i++)
	{
		cout << " " << count[i];
	}
	getchar();
	getchar();
    return 0;
}

int BinarySearch(vector<int>score, int N, int tmp)
{
	int left = 0, right = N - 1;
	int num = 0;
	int mid = 0;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (tmp < score[mid])
		{
			right = mid - 1;
		}
		else if (tmp > score[mid])
		{
			left = mid + 1;
		}
		else
		{
			break;
		}
	}
	if (tmp == score[mid])
	{
		for (int i = mid;i < N &&score[i] == tmp;i++)
		{
			num++;
		}
		for (int i = mid - 1;i >= 0 && score[i] == tmp;i--)
		{
			num++;
		}
	}
	return num;
}

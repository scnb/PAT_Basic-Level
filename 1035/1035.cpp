// 1035.cpp : 定义控制台应用程序的入口点。
//可以考虑将原始数组每分别进行一次插入排序和归并排序后就与第二个数组比较一下，这样绝对可以确定是哪种排序。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void print(vector<int> sorted_num);
bool is_Insert_sort(vector<int> a, vector<int> b, int & count);

int main()
{
	int N;
	cin >> N;
	vector<int> original_num;
	vector<int> sorted_num;
	int tmp;
	//freopen("input1.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		original_num.push_back(tmp);
	}
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		sorted_num.push_back(tmp);
	}
	int count = 0;
	if (is_Insert_sort(original_num, sorted_num, count))
	{
		cout << "Insertion Sort" << endl;
		if (count == 0)
		{
			print(sorted_num);
		}
		else
		{
			int wall = N - count - 1;						//定义“墙”的位置
			if (sorted_num[wall + 1] >= sorted_num[wall])
			{
				wall = wall + 1;
			}
			int current = sorted_num[wall + 1];
			int pos = 0;
			for (int i = 0;i <= wall;i++)
			{
				if (current <= sorted_num[i])
				{
					pos = i;							   //得到要插入的位置		
					break;
				}
			}
			for (int i = wall;i >= pos;i--)
			{
				sorted_num[i + 1] = sorted_num[i];
			}
			sorted_num[pos] = current;
			print(sorted_num);
		}
	}
	else											    //不是插入排序就是归并排序
	{
		int count = 0;									//记录经过了几个元素大小顺序发生了变化
		for (int i = 0;i < N;i++)
		{
			if (i != N - 1)
			{
				if (sorted_num[i + 1] < sorted_num[i])
				{
					count = i + 1;
					break;
				}
			}
		}
		//如果4*count<N就分别对前4*count个元素和后面的其他元素排序，否则的话就对整体排序
		if (4 * count <= N)
		{
			int tmp;
			for (int i = 0;i < 2*count;i++)				//先对前2*count个元素排序
			{
				for (int j = i;j < 2*count;j++)
				{
					if (sorted_num[j] < sorted_num[i])
					{
						tmp = sorted_num[j];
						sorted_num[j] = sorted_num[i];
						sorted_num[i] = tmp;
					}
				}
			}
			for (int i = 2*count;i < 4 * count;i++)		//再对中间2*count个元素排序
			{
				for (int j = i;j < 4 * count;j++)
				{
					if (sorted_num[j] < sorted_num[i])
					{
						tmp = sorted_num[j];
						sorted_num[j] = sorted_num[i];
						sorted_num[i] = tmp;
					}
				}
			}
			for (int i = 4 * count;i < N;i++)						//对最后的几个元素排序
			{
				for (int j = i;j < N;j++)
				{
					if (sorted_num[j] < sorted_num[i])
					{
						tmp = sorted_num[j];
						sorted_num[j] = sorted_num[i];
						sorted_num[i] = tmp;
					}
				}
			}
		}
		else
		{
			for (int i = 0;i < N;i++)
			{
				for (int j = i;j < N;j++)
				{
					if (sorted_num[j] < sorted_num[i])
					{
						tmp = sorted_num[j];
						sorted_num[j] = sorted_num[i];
						sorted_num[i] = tmp;
					}
				}
			}
		}
		cout << "Merge Sort" << endl;
		print(sorted_num);
	}
    return 0;
}

bool is_Insert_sort(vector<int> a, vector<int> b, int & count)
{
	count = 0;
	for (int i = b.size() - 1;i >= 0;i--)
	{
		if (b[i] == a[i])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1;i <= b.size() - count - 1;i++)
	{
		if (b[i - 1] <= b[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

void print(vector<int> sorted_num)
{
	cout << sorted_num[0];
	for (int i = 1;i < sorted_num.size();i++)
	{
		cout << " " << sorted_num[i];
	}
}
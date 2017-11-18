// 1025.cpp : 定义控制台应用程序的入口点。
//这道题有点复杂，需要好好想一想。
//最后得分24分，还差一分。
//重点还是怎么合理的存储数据，即以什么样的方式、什么样的顺序来存储数据。
//先声明两个包含100000个元素的数组，一个以地址为索引来存放节点的值，另一个以前一个节点的地址为索引，存储下一个节点的地址。
//然后，在声明两个vector，用来分别顺序存放地址和值。
//最后，对这两个vector进行分别反转。反转部分的程序比较简单。
//要求 0 < N <= 100000  0 < K <=N

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
	int N, K;
	int value[100000];			//通过以地址为索引，存储每个节点的值
	int address[100000];			//通过以前一个节点的地址为索引，存储下一个节点的地址
	int first;					//存储节点首地址的值
	cin >> first >> N >> K;
	int add, val, next;
	freopen("input.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		cin >> add >> val >> next;
		value[add] = val;
		address[add] = next;
	}
	vector<int> addr;
	addr.push_back(first);
	vector<int> num;
	num.push_back(value[first]);
	for (int i = 1;i < N;i++)
	{
		addr.push_back(address[addr[i - 1]]);
		num.push_back(value[addr[i]]);
	}
	
	for (int i = 0;i < N;i += K)
	{
		if (N - i >= K)
		{
			int t = 1;
			for (int j = i;j < i + K / 2;j++,t++)
			{
				int tmp;
				tmp = addr[j];
				addr[j] = addr[i + K - t];
				addr[i + K - t] = tmp;
				tmp = num[j];
				num[j] = num[i + K - t];
				num[i + K - t] = tmp;
			}
		}
		else
		{
			break;
		}
	}

	for (int i = 0;i < N;i++)
	{
		if (i != N - 1)
		{
			cout << setw(5) << setfill('0') << addr[i] << " " << num[i] << " " << setw(5) << setfill('0') << addr[i + 1] << endl;
		}
		else
		{
			cout << setw(5) << setfill('0') << addr[i] << " " << num[i] << " " << -1 << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
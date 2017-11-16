// 1021.cpp : 定义控制台应用程序的入口点。
//在这个文件夹下，还有一个python版本的算法，但是在评测的时候有两个测试点不能通过，不知道是什么原因。
//以后做题的时候尽量还是用C++来做，一是速度快，二是大家都是用的C++，寻找答案时方便。
//这道题其实并不难，主要是要考虑到输入的数是1000位的，因此必须要用字符串来接收。然后用sort算法对string进行排序，在前面元素对比是否相等，最好计数工作，
//把对应的数值和count值分别当做另一个数组的索引和值。

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>		//用于排序算法
using namespace std;

int main()
{
	string N;
	int count = 1;
	int bit[1000] = { 0 };
	cin >> N;
	sort(N.begin(), N.end());
	for (int i = 0;i < N.length();i++)
	{
		if (N[i] == N[i + 1])
		{
			count++;
		}
		else
		{
			bit[N[i]-48] = count;
			count = 1;
		}
	}
	for (int i = 0;i<1000;i++)
	{
		if (bit[i] != 0)
		{
			cout << i << ":" << bit[i] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


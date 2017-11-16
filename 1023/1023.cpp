// 1023.cpp : 定义控制台应用程序的入口点。
//首先应该寻找大于0并且存在的是哪个数，原来的程序是直接从1开始的，但是真的太傻了，没有考虑到1不存在的情况···
//正确的思路：首先应该判断第一大于0的且个数不为0的数是几（假设为n），然后，向vector中存入一个这个数n，之后先存0，在把其余的n存进去，最后再对其他的数进行循环。

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num[10] = { 0 };
	for (int i = 0;i < 10;i++)
	{
		cin >> num[i];
	}
	vector<int> min;
	int i = 1;
	while (num[i] == 0)
	{
		i++;
	}
	min.push_back(i);					//先存一个进去，第二个数必须得看是不是0
	
	for (int k = 0;k < num[0];k++)
	{
		min.push_back(0);
	}
	for (int j = 0;j < num[i] - 1;j++)
	{
		min.push_back(i);
	}
	for (i++;i < 10;i++)
	{
		for (int j = 0;j < num[i];j++)
		{
			min.push_back(i);
		}
	}
	for (int i = 0;i < min.size();i++)
	{
		cout << min[i];
	}
	getchar();
	getchar();
    return 0;
}


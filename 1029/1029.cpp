// 1029.cpp : 定义控制台应用程序的入口点。
//这道题思路比较清晰，实现也比较简单。主要就是靠循环和两个索引来判断两个字符串有哪些字符缺失了。并且为了方便输出，还要把缺失的小写字符转换成大写字符。

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string normal;
	string real;
	cin >> normal;
	cin >> real;
	vector<char>lost;
	int i = 0, j = 0;
	for (int i = 0;i < normal.length();i++)
	{
		if (normal[i] != real[j])
		{
			if (normal[i] >= 'a' &&normal[i] <= 'z')
			{
				normal[i] -= 32;
			}
			lost.push_back(normal[i]);
			continue;
		}
		else
		{
			j++;
			continue;
		}
	}
	vector<char>final;
	int flag = 0;
	for (int i = 0;i < lost.size();i++)
	{
		for (int j = 0;j < final.size();j++)
		{
			if (lost[i] == final[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			final.push_back(lost[i]);
		}
		else
		{
			flag = 0;
		}
	}
	for (int i = 0;i < final.size();i++)
	{
		cout << final[i];
	}
	getchar();
	getchar();
    return 0;
}


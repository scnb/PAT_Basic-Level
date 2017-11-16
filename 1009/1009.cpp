// 1009.cpp : 定义控制台应用程序的入口点。
//这道题思路比较简单，但是实现起来有些困难，主要是原来选用的放字符串的容器之间的互相转存不兼容。
/*
	比如，char类型的字符不能存放string类的变量。之所以说的这么绕口，是因为string是一个类类型，他不是C++的内置的变量类型，
	所以在互相转换时存在很多坑。
	本题最后采用的是用string变量来存储输入，然后定义一个vector变量，其每一个元素为string类型的变量，把string变量中的某一个元素存到vector中的某一个
	变量中。期间涉及到了先将str[i]转换为char类型，然后再利用vector类的append方法将该字符存到vector中的string变量中。
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int count = 1;
	int len = str.length();
	for (int i = 0;i < len;i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	if (count == 1)
	{
		cout << str << endl;
		getchar();
		return 0;
	}
	vector<string> a(count);
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0;i < len;i++)
	{
		if (str[i] == ' ')
		{
			for (;j < i;j++)
			{
				char tmp = str[j];
				a[k].push_back(tmp);
			}
			k++;
			j++;
		}
		if (k == count - 1)
		{
			for (int m = i + 1;m < len;m++)
			{
				char tmp = str[m];
				a[k].push_back(tmp);
			}
			break;
		}
	}
	for (int k = count - 1;k >= 0;k--)
	{
		if (k != 0)
		{
			cout << a[k] << " ";
		}
		else
		{
			cout << a[k] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


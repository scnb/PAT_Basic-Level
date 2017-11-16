// 1039.cpp : 定义控制台应用程序的入口点。
//这道题思路还算简单，实现起来也比较顺利。
/*
	要点在于：
	①在记录capital、letter和num这三个数组的时候，注意索引的正确表达，尤其是num数组，首先str[i]要与'0'而不是0判断，然后索引是str1[i]-48
	②在第二个for循环判断中，如果数组中有str2对应的字符，那么应该将数组对应的元素减1，以防止str2中同一个元素的数组多于str1中对应的元素数组，例如:str1="abcYY2",str2="abcYYY2"，显然str2中的Y比str1中的多一个
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int capital[26] = { 0 };		//记录str1中每个大写字母的个数
	int letter[26] = { 0 };			//记录str1中每个小写字母的个数
	int num[10] = { 0 };			//记录str1中每个数字的个数
	for (int i = 0;i < str1.length();i++)
	{
		if (str1[i] >= 'a'&&str1[i] <= 'z')
		{
			letter[str1[i] - 97]++;
		}
		else if (str1[i] >= 'A'&&str1[i] <= 'Z')
		{
			capital[str1[i] - 65]++;
		}
		else if (str1[i] >= '0' && str1[i] <= '9')
		{
			num[str1[i]-48]++;
		}
	}
	int flag = 0;			//用来记录str2中是否有字符不在str1中，如果有，则flag置1，count加1
	int count = 0;			//用来记录str1中缺少几个珠子
	for (int i = 0;i < str2.length();i++)
	{
		if (str2[i] >= 'a'&&str2[i] <= 'z')
		{
			if (letter[str2[i] - 97] != 0)
			{
				letter[str2[i] - 97]--;
				continue;
			}
			else
			{
				flag = 1;
				count++;
			}
		}
		else if (str2[i] >= 'A'&&str2[i] <= 'Z')
		{
			if (capital[str2[i] - 65] != 0)
			{
				capital[str2[i] - 65]--;
				continue;
			}
			else
			{
				flag = 1;
				count++;
			}
		}
		else if (str2[i] >= '0' && str2[i] <= '9')
		{
			if (num[str2[i] - 48] != 0)
			{
				num[str2[i] - 48]--;
				continue;
			}
			else
			{
				flag = 1;
				count++;
			}
		}
	}
	if (flag == 0)
	{
		cout << "Yes " << str1.length() - str2.length() << endl;
	}
	else
	{
		cout << "No " << count << endl;
	}
	getchar();
	getchar();
    return 0;
}
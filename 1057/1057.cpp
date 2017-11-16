// 1057.cpp : 定义控制台应用程序的入口点。
//这道题比较简答，思路比较清晰

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int sum = 0;
	getline(cin, str);
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') 
		{
			sum += int(str[i] - 65) + 1;
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			sum += int(str[i] - 97) + 1;
		}
	}
	int count1 = 0, count0 = 0;
	while (sum >= 2)
	{
		if (sum % 2 == 0)
		{
			count0++;
		}
		else
		{
			count1++;
		}
		sum /= 2;
	}
	if (sum == 1)
	{
		count1++;
	}
	cout << count0 << " " << count1 << endl;
	getchar();
	getchar();
    return 0;
}


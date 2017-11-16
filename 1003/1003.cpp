// 1003.cpp : 定义控制台应用程序的入口点。
//这道题真是经典，卡了我很长时间，也让我明白了一些道理：不要一上来就按照题意去一个条件一个条件的对应，
//应该看一看这些所有的条件能否总结出一个规律（或规则）来。
//另外，第3个条件我真是开始时没看懂，原来他说的是如果aPbTc成立，那么根据前两个条件能退出来a、b、c的关系甚至是数量
//然后，再来推aPbATca中的a、b、c的关系。
/*
	比如这道题中：先统计P、A、T分别的数量，如果他们的和等于字符串的长度，说明满足第一个条件。
				  判断P和T的数量是否大于1，则可判断是否满足第二个条件。
				  第二个条件和第三个条件可推出来：P前面A的数量乘以P和T之间A的数量等于T后面的A的数量。
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string *test = new string[n];
	for (int i = 0;i < n;i++)
	{
		cin >> test[i];
	}
	
	for (int i = 0;i < n;i++)
	{
		int count_p = 0, count_a = 0, count_t = 0;
		int pos_p = 0, pos_t = 0;
		int len = test[i].length();
		for (int j = 0;j < len;j++)
		{
			if (test[i][j] == 'P')
			{
				count_p++;
				pos_p = j;
			}
			if (test[i][j] == 'A')
			{
				count_a++;
			}
			if (test[i][j] == 'T')
			{
				count_t++;
				pos_t = j;
			}
		}
		if (count_p + count_a + count_t != len || pos_t - pos_p <= 1 || count_p > 1 || count_t > 1 || pos_p*(pos_t - pos_p - 1) != (len - pos_t - 1))
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


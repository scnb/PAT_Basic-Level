// 1048.cpp : 定义控制台应用程序的入口点。
//划重点：以个位为第1位，则个位一定是奇数位
//18分，还差两分
//看了网上郑州大学某学生的实现，他是把A或B通过在前面补0补齐到一样长来计算的。这样就大大节省了代码量。
//另外，可以不用vector而用string来存储加密后的数字，string有一个大优点是：改变加法中加数的顺序就能改变字符串连接的顺序：
//例如：str = '0'+str;	是把字符0加在str的前面，而str = str+'0'是把0加在str后面，这样就不用把vector逆序输出了

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	vector<char>out;
	int flag = 1;				//表示是奇数位
	int i;
	if (B.length() >= A.length())
	{
		int diff = B.length() - A.length();
		for (i = B.length() - 1;i >= diff;i--)
		{
			if (flag == 1)
			{
				int tmp = int(B[i] - 48) + int(A[i - diff] - 48);
				if (tmp == 10)
				{
					out.push_back('J');
				}
				else if (tmp == 11)
				{
					out.push_back('Q');
				}
				else if (tmp == 12)
				{
					out.push_back('K');
				}
				else
				{
					out.push_back(tmp % 13);
				}
				flag = 0;
			}
			else
			{
				int tmp = int(B[i] - 48) - int(A[i - diff] - 48);
				if (tmp < 0)
				{
					out.push_back(tmp + 10);
				}
				else
				{
					out.push_back(tmp);
				}
				flag = 1;
			}
		}
		for (i = diff - 1;i >= 0;i--)
		{
			out.push_back(int(B[i] - 48));		
		}
	}
	else if (B.length() < A.length())
	{
		int diff = A.length() - B.length();
		for (i = B.length() - 1;i >= 0;i--)
		{
			if (flag == 1)
			{
				int tmp = int(B[i] - 48) + int(A[i + diff] - 48);
				if (tmp == 10)
				{
					out.push_back('J');
				}
				else if (tmp == 11)
				{
					out.push_back('Q');
				}
				else if (tmp == 12)
				{
					out.push_back('K');
				}
				else
				{
					out.push_back(tmp % 13);
				}
				flag = 0;
			}
			else
			{
				int tmp = int(B[i] - 48) - int(A[i + diff] - 48);
				if (tmp < 0)
				{
					out.push_back(tmp + 10);
				}
				else
				{
					out.push_back(tmp);
				}
				flag = 1;
			}
		}
		for (i = diff - 1;i >= 0;i--)
		{
			if (flag == 1)
			{
				out.push_back(int(A[i] - 48));
				flag = 0;
			}
			else
			{
				out.push_back(10 - int(A[i]-48));
				flag = 1;
			}
		}
	}

	int j = out.size() - 1;
	while (int(out[j]) == 0)
	{
		j--;
	}
	for (int i=j;i >= 0;i--)
	{
		if (int(out[i]) > 9)
		{
			if (int(out[i]) == 74)
			{
				cout << "J";
			}
			else if (int(out[i]) == 81)
			{
				cout << "Q";
			}
			else if (int(out[i]) == 75)
			{
				cout << "K";
			}
		}
		else
		{
			cout << int(out[i]);
		}
	}
	getchar();
	getchar();
    return 0;
}
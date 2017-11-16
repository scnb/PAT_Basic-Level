// 1044.cpp : 定义控制台应用程序的入口点。
//有一些问题，并不是所有的单词都是3个字母的，需要分类讨论
/*
	上面的问题已经成功解决。主要还是要理解清题目的意思啊。火星文的进位后的12个高位数字是可以单独来表示地球数字的。
	比如tam表示13，则hel表示26，以此类推，maa表示39···
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string low_13[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string high_12[12] = { "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };

int main()
{
	int N;
	cin >> N;
	string *str = new string[N];
	getchar();												//这里加一句getchar()来接收上面输入时的回车键
	for (int i = 0;i < N;i++)
	{
		getline(cin, str[i]);
	}
	for (int i = 0;i < N;i++)
	{
		if (str[i][0] >= '0' && str[i][0] <= '9')			//如果是数字
		{
			int tmp = stoi(str[i]);
			if (tmp > 13 && tmp%13!=0)
			{
				int low = tmp % 13;							//计算余数
				int high = tmp / 13;						//计算商
				cout << high_12[high-1] << " " << low_13[low] << endl;
			}
			else if(tmp>=0 && tmp<=12)
			{
				cout << low_13[tmp] << endl;
			}
			else if (tmp % 13 == 0)
			{
				cout << high_12[(tmp / 13) - 1] << endl;
			}
		}
		else if (str[i].length() == 3 && str[i] != "tam")			//如果是单个火星文
		{
			for (int j = 0;j < 13;j++)
			{
				if (str[i] == low_13[j])
				{
					cout << j << endl;
				}
			}
			for (int j = 0;j < 12;j++)
			{
				if (str[i] == high_12[j])
				{
					cout << (j + 1) * 13 << endl;
				}
			}
		}
		else if (str[i] == "tam")
		{
			cout << 13 << endl;
		}
		else if (str[i] == "tret")
		{
			cout << 0 << endl;
		}
		else if (str[i].length() == 7)			//如果是两位的火星文
		{
			string low = "";
			string high = "";
			for (int j = 0;j < 3;j++)
			{
				high += str[i][j];
			}
			for (int j = 4;j < 7;j++)
			{
				low += str[i][j];
			}
			int sum = 0;
			for (int j = 0;j < 12;j++)
			{
				if (high == high_12[j])
				{
					sum += (j + 1) * 13;
				}
			}
			for (int j = 0;j < 13;j++)
			{
				if (low == low_13[j])
				{
					sum += j;
				}
			}
			cout << sum << endl;
		}
		else if (str[i].length() == 8)			//如果是两位的火星文
		{
			string low = "";
			string high = "";
			for (int j = 0;j < 3;j++)
			{
				high += str[i][j];
			}
			for (int j = 4;j < 8;j++)
			{
				low += str[i][j];
			}
			int sum = 0;
			for (int j = 0;j < 12;j++)
			{
				if (high == high_12[j])
				{
					sum += (j + 1) * 13;
				}
			}
			for (int j = 0;j < 13;j++)
			{
				if (low == low_13[j])
				{
					sum += j;
				}
			}
			cout << sum << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
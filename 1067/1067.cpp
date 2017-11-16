// 1067.cpp : 定义控制台应用程序的入口点。
//这道题思路比较清晰，实现比较简单
//注意在读取用户输入密码时，要使用geline(cin,tmp)，因为不能保证用户的输入中不包含空格，tab等

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	string right_answer;
	cin >> right_answer >> N;
	string tmp;
	vector<string> attempt;
	getchar();
	getline(cin, tmp);
	while (tmp != "#")
	{
		attempt.push_back(tmp);
		getline(cin, tmp);
	}
	int count = 0;									//记录输入次数
	for (int i = 0;i < attempt.size();i++)
	{
		if (count < N)
		{
			if (right_answer == attempt[i])
			{
				cout << "Welcome in" << endl;
				break;
			}
			else
			{
				cout << "Wrong password: " << attempt[i] << endl;
				count++;
				if (count == N)
				{
					cout << "Account locked" << endl;
					break;
				}
			}
		}
	}
	getchar();
	getchar();
    return 0;
}
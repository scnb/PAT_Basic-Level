// 1047.cpp : 定义控制台应用程序的入口点。
//思路比较清晰，实现起来也比较简单。

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int score[1000] = { 0 };
	int N;
	cin >> N;
	getchar();
	string *str = new string[N];
	for (int i = 0;i < N;i++)
	{
		getline(cin, str[i]);
	}
	for (int i = 0;i < N;i++)
	{
		int j = 0;
		string tmp = "";
		while (str[i][j] != '-')
		{
			tmp += str[i][j];
			j++;
		}
		int id = stoi(tmp) - 1;
		while (str[i][j] != ' ')
		{
			j++;
		}
		j++;
		tmp = "";
		for (;j < str[i].length();j++)
		{
			tmp += str[i][j];
		}
		score[id] += stoi(tmp);
	}
	int max = 0;
	for (int i = 0;i < 1000;i++)
	{
		if (score[max] < score[i])
		{
			max = i;
		}
	}
	cout << max + 1 << " " << score[max] << endl;
	getchar();
	getchar();
    return 0;
}


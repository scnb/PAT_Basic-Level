// 1004.cpp : 定义控制台应用程序的入口点。
//这道题思路比较清晰，实现也比较简单，重点在于进行成绩数组的比较时，姓名数组和学号数组也要随之变动。

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *score = new int[n];
	string *id = new string[n];
	string *name = new string[n];
	int score_tmp;
	string name_tmp;
	string id_tmp;
	for (int i = 0;i < n;i++)
	{
		cin >> name[i] >> id[i] >> score[i];
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (score[i] > score[j])
			{
				score_tmp = score[j];
				score[j] = score[i];
				score[i] = score_tmp;

				id_tmp = id[j];
				id[j] = id[i];
				id[i] = id_tmp;

				name_tmp = name[j];
				name[j] = name[i];
				name[i] = name_tmp;
			}
		}
	}
	cout << name[0] << " " << id[0] << endl;
	cout << name[n - 1] << " " << id[n - 1] << endl;
	getchar();
	getchar();
    return 0;
}


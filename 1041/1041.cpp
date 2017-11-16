// 1041.cpp : 定义控制台应用程序的入口点。
//这道题比较简单，根据题目描述很直观的想到思路。

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;		//考试人数
	int M;		//M个待查询的试机座位号码
	cin >> N;
	string *id = new string[N];	//14位的准考证号
	int *test = new int[N];		//1-N的试机座位号
	int *exam = new int[N];		//1-N的考试座位号
	for (int i = 0;i < N;i++)
	{
		cin >> id[i] >> test[i] >> exam[i];
	}
	getchar();
	cin >> M;
	
	int *find = new int[M];
	for (int i = 0;i < M;i++)
	{
		cin >> find[i];
	}

	int flag = 0;
	for (int i = 0;i < M;i++)
	{
		flag = 0;
		//对M个待查询号码进行查找
		for (int j = 0;j < N;j++)
		{
			if (test[j] == find[i])
			{
				flag = j;
				break;
			}
		}
		cout << id[flag] << " " << exam[flag] << endl;
	}
	delete[]id, test, exam;
	getchar();
	getchar();
    return 0;
}


// 1058.cpp : 定义控制台应用程序的入口点。
//考虑把后面的N行同学的答案一行一行的输入，每次用getline(cin,str)来接收一整行，检测起来也比较容易，用while循环来过滤掉空格和括号

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int *score = new int[M];					//M道题的分值
	int *num = new int[M];						//M道题的选项个数
	int *right_num = new int[M];				//M道题的正确选项个数
	int *count = new int[M]();					//M道题的错误次数，初始化为0
	int *sum = new int[N]();					//N个同学的得分情况
	int *id = new int[M];						//用于存放错误次数最多的题目的序号
	string *right_answer = new string[M]();		//M道题的正确选项
	string answer;								//每个同学每道题给出的回答
	string str;
	string tmp;
	//freopen("d:\\inputs.txt", "r", stdin);
	for (int i = 0;i < M;i++)
	{
		cin >> score[i] >> num[i] >> right_num[i];
		getline(cin, right_answer[i]);
	}
	for (int i = 0;i < N;i++)
	{
		int t = 0;					//表明现在是哪道题
		getline(cin, str);
		for (int j = 0;j < str.length();j++,t++)
		{
			while (str[j]==' ' || str[j]=='(' || str[j]==')')
			{
				j++;
			}
			int tmp_num;
			tmp_num = int(str[j++] - 48);
			if (tmp_num == right_num[t])
			{
				tmp = "";
				for (int k = 0;k < 2 * tmp_num;k++)		//读取每个同学给出的答案（不剔除空格）
				{
					tmp += str[j++];
				}
				if (tmp == right_answer[t])
				{
					sum[i] += score[t];
				}
				else
				{
					count[t]++;
				}
			}
			else
			{
				count[t]++;
				while (str[j] != ')')				//重点是这个地方，如果没有while循环把剩余的那些没用的字符吃掉的话，后面就全乱套了。
				{
					j++;
				}
			}
		}
	}

	for (int i = 0;i < N;i++)
	{
		cout << sum[i] << endl;
	}

	int max = 0;
	for (int i = 0;i < M;i++)
	{

		if (count[max] < count[i])
		{
			max = i;
		}
	}
	if (count[max] == 0)
	{
		cout << "Too simple" << endl;
		return 0;
	}
	else
	{
		cout << count[max];
		for (int i = 0;i < M;i++)
		{
			if (count[max] == count[i])
			{
				cout <<" "<< i + 1;
			}
		}
	}
	getchar();
	getchar();
    return 0;
}
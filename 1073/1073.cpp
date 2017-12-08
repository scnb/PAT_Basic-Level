// 1073.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct  wrong
{
	int Ti;
	int count = 0;
	char choice;
};

struct problem
{
	int score;
	int num;			//选项总个数 
	int right_num;		//正确选项个数 
	string answer;		//正确答案 
};

struct Student
{
	double sum = 0;

};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<problem> pro;
	vector<wrong> wro;
	for (int i = 0;i<M;i++)
	{
		wrong tmp_wro;
		wro.push_back(tmp_wro);
	}
	//freopen("input1.txt", "r", stdin);
	for (int i = 0;i<M;i++)
	{
		problem tmp_pro;
		cin >> tmp_pro.score;
		cin >> tmp_pro.num;
		cin >> tmp_pro.right_num;
		string tmp;
		for (int k = 0;k<tmp_pro.right_num;k++)
		{
			getchar();
			cin >> tmp;
			tmp_pro.answer += tmp;
		}
		pro.push_back(tmp_pro);
	}
	vector<Student> stu;
	Student tmp_stu;
	string tmp_str;
	int current = 0;
	freopen("input2.txt", "r", stdin);
	for (int i = 0;i<N;i++)
	{
		getline(cin, tmp_str);
		string tmp;
		string tmp_answer;
		int choice_num = 0;
		for (int k = 0;k<tmp_str.size();k++)
		{
			while (tmp_str[k] != '(' && k<tmp_str.size())
			{
				k++;
			}
			if (k >= tmp_str.size())
			{
				continue;
			}
			k++;
			tmp = tmp_str[k];
			choice_num = stoi(tmp);
			k++;
			if (choice_num == pro[current].right_num)
			{
				for (int j = 0;j<choice_num;j++,k++)
				{
					getchar();
					cin >> tmp;
					tmp_answer += tmp;
				}
				if (tmp_answer == pro[current].answer)
				{
					tmp_stu.sum += pro[current].score;
					stu.push_back(tmp_stu);
				}
				else if (tmp_answer<pro[current].answer)
				{
					tmp_stu.sum += 0.5*pro[current].score;
					stu.push_back(tmp_stu);
				}
				else
				{
					wro[current].count++;
				}
			}
			else
			{
				wro[current].count++;		//该题错误次数增加一次 
			}
			current++;
		}
	}
	for (int i = 0;i<N;i++)
	{
		cout << stu[i].sum << endl;
	}
	for (int i = 0;i<M;i++)
	{
		cout << wro[i].count << endl;
	}
	return 0;
}
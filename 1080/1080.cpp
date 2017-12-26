// 1080.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stdlib.h>
using namespace std;

int Max(int a, int b, int c);

struct Score
{
	string name;
	int sum = 0;
	int GP = -1;
	int GM = -1;
	int GN = -1;
	bool operator<(Score & A)
	{
		if (this->sum != A.sum)
		{
			return this->sum > A.sum;
		}
		else
		{
			return this->name < A.name;
		}
	}
};

struct Student
{
	string name;
	int GP = -1;
	int GM = -1;
	int GN = -1;
};

int main(int argc, char** argv)
{
	int P, M, N;
	cin >> P >> M >> N;
	int max = 0;
	max = Max(P, M, N);
	map<string, Student> stu;
	vector<Score> score;
	Score tmp_score;
	Student tmp_stu;
	//freopen("input.txt","r",stdin);
	for (int i = 0;i<P;i++)
	{
		cin >> tmp_stu.name >> tmp_stu.GP;
		stu[tmp_stu.name].GP = tmp_stu.GP;
	}
	for (int i = 0;i<M;i++)
	{
		cin >> tmp_stu.name >> tmp_stu.GM;
		stu[tmp_stu.name].GM = tmp_stu.GM;
	}
	for (int i = 0;i<N;i++)
	{
		cin >> tmp_stu.name >> tmp_stu.GN;
		stu[tmp_stu.name].GN = tmp_stu.GN;
		int sum = 0;
		if (stu[tmp_stu.name].GP >= 200)
		{
			if (stu[tmp_stu.name].GM>stu[tmp_stu.name].GN)
			{
				sum = 0.4*stu[tmp_stu.name].GM + 0.6*stu[tmp_stu.name].GN + 0.5;
			}
			else
			{
				sum = stu[tmp_stu.name].GN;
			}
			if (sum >= 60)
			{
				tmp_score.name = tmp_stu.name;
				tmp_score.sum = sum;
				tmp_score.GP = stu[tmp_stu.name].GP;
				tmp_score.GM = stu[tmp_stu.name].GM;
				tmp_score.GN = stu[tmp_stu.name].GN;
				score.push_back(tmp_score);
			}
		}
	}
	sort(score.begin(), score.end());
	for (int i = 0;i<score.size();i++)
	{
		cout << score[i].name << " " << score[i].GP << " " << score[i].GM << " " << score[i].GN << " " << score[i].sum << endl;
	}
	return 0;
}

int Max(int a, int b, int c)
{
	if (a >= b)
	{
		if (a >= c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (b >= c)
		{
			return b;
		}
		else
		{
			return c;
		}
	}
}
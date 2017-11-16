// 1028.cpp : 定义控制台应用程序的入口点。
//思路比较清晰，主要是把分类情况分清楚。
/*
	先是区分生日是否合理，不合理的年龄有：
	①年份<1814
	②年份==1814，并且年份<9 或 月份等于9 但日期<6
	③年份>2014
	④年份==2014，并且月份>9 或 月份等于9 但日期>6

	然后判断生日的大小：
	比如判断年龄最大的人：
	先判断年份是不是最小，若不是，则依次判断月份、日期。

	本题最终得分19分，有一个测试点遇到了段错误。
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	getchar();
	vector<string>birth;
	for (int i = 0;i < N;i++)
	{
		birth.push_back("");
	}
	int count = 0;					//记录合理的生日数
	for (int i = 0;i < N;i++)
	{
		getline(cin, birth[i]);
	}
	vector<int>year;
	vector<int>month;
	vector<int>day;
	vector<string>name;

	for (int i = 0;i < N;i++)
	{
		int y = 0, m = 0, d = 0;
		int j = 0;
		string tmp = "";
		while (birth[i][j] != ' ')
		{
			tmp += birth[i][j];
			j++;
		}
		j++;	//现在j指向年份的第一个数字
		y += (birth[i][j++] - '0') * 1000;
		y += (birth[i][j++] - '0') * 100;
		y += (birth[i][j++] - '0') * 10;
		y += (birth[i][j++] - '0') * 1;
		j++;	//现在j指向月份的第一个数字
		m += (birth[i][j++] - '0') * 10;
		m += (birth[i][j++] - '0') * 1;
		j++;	//现在j指向日期的第一个数字
		d += (birth[i][j++] - '0') * 10;
		d += (birth[i][j++] - '0') * 1;
		if (y < 1814)
		{
			continue;
		}
		else if (y == 1814 && (m < 9 || (m == 9 && d < 6)))
		{
			continue;
		}
		else if (y > 2014)
		{
			continue;
		}
		else if (y == 2014 && (m > 9 || (m == 9 && d > 6)))
		{
			continue;
		}
		else
		{
			count++;
			year.push_back(y);
			month.push_back(m);
			day.push_back(d);
			name.push_back(tmp);
		}
	}
	int max = 0, min = 0;			//分别记录年龄最大和最小之人的索引
	for (int i = 0;i < count;i++)
	{
		if (year[max] > year[i])
		{
			max = i;
		}
		else if (year[max] == year[i] && (month[max] > month[i] || (month[max] == month[i] && day[max] > day[i])))
		{
			max = i;
		}
		if (year[min] < year[i])
		{
			min = i;
		}
		else if (year[min] == year[i] && (month[min] < month[i] || (month[min] == month[i] && day[min] < day[i])))
		{
			min = i;
		}
	}
	cout << count << " " << name[max] << " " << name[min] << endl;
	getchar();
	getchar();
    return 0;
}


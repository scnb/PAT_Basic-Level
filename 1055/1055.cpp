// 1055.cpp : 定义控制台应用程序的入口点。
//这道题还可以，思路需要好好想一想。主要是搞清楚一下几点：
/*
	①每排 m = [N/K]个人，向下取整（在c++中用int强制类型转换自动向下取整）
	②最后一排有 N-m*(K-1)个人
	③前K-1排的人数相同，都为m
	④从后往前，一排比一排低
	⑤每一排，最高的站中间 [m/2]+1 (向下取整）实际在程序中并没有用到
	⑥在队伍里面围绕着最高的人，先左后右降序派对
	⑦若身高相同，则按名字升序排列，所以需要在结构体中重定义小于号，先按身高比价，再按名字比较

	若m是奇数，则最高值的输出顺序为第（m/2+1）位（从1开始数），而第一个输出的值的索引是m-2，向上向下步长都是2
	若m是偶数，则最高值的输出顺序为第（m/2+1）位（从1开始数），而第一个输出的值的索引是m-1，向上向下步长都是2
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct Student
{
	string name;
	int height;
	bool operator < (const struct Student & A)
	{
		if (this->height != A.height)
		{
			return this->height > A.height;
		}
		else
		{
			return this->name < A.name;
		}
	}
};

int main()
{
	int N, K;
	cin >> N >> K;
	int m = int(N / K);						//计算每排应该有多少人，向下取整
	int last_m = N - m*(K - 1);				//计算最后一排应该有多少人
	vector<struct Student> student;
	struct Student tmp;
	//freopen("input.txt", "r", stdin);	
	for (int i = 0;i < N;i++)
	{
		cin >> tmp.name >> tmp.height;
		student.push_back(tmp);
	}
	sort(student.begin(), student.end());
	//若m是奇数，则最高值的输出顺序为第（m/2+1）位（从1开始数），而第一个输出的值的索引是m-2，向上向下步长都是2
	//若m是偶数，则最高值的输出顺序为第（m/2+1）位（从1开始数），而第一个输出的值的索引是m-1，向上向下步长都是2
	int i = 0;									//作为当前排的最大值
	if (last_m % 2 == 0)						//若最后一排是偶数个人
	{
		int j = 0;
		int first = last_m - 1;
		for (j = first;j >= i;j -= 2)
		{
			cout << student[j].name << " ";
		}
		for (j = i;j < i + last_m;j += 2)		//改成i+last_m是为了和后面输出前K-1排的程序对应起来
		{
			if (j != i + last_m - 2)
			{
				cout << student[j].name << " ";
			}
			else
			{
				cout << student[j].name << endl;
			}
		}
		i = last_m;								//更新下一排的最大值
	}
	else										//若最后一排是奇数个人
	{
		int j = 0;
		int first = last_m - 2;
		for (j = first;j >= i;j -= 2)
		{
			cout << student[j].name << " ";
		}
		for (j = i;j < i + last_m;j += 2)
		{
			if (j != i + last_m - 1)
			{
				cout << student[j].name << " ";
			}
			else
			{
				cout << student[j].name << endl;
			}
		}
		i = last_m;
	}
	//对于前K-1排，每排m个人，即每m个人一组
	if (m % 2 != 0)								//若前K-1排每排有奇数个人
	{
		while (i < N)
		{
			int j;								//i是当前排的最高的人，将j的初值赋值为i
			int rel = m - 2;					//定义当前排第一个输出的人相对于最高的人的索引偏移量
			for (j = i + rel;j >= i;j -= 2)
			{
				cout << student[j].name << " ";
			}
			for (j = i;j < i + m;j += 2)
			{
				if (j != i + m - 1)				//对于奇数，是i+m-1
				{
					cout << student[j].name << " ";
				}
				else
				{
					cout << student[j].name << endl;
				}
			}
			i = i + m;
		}
	}
	else										//若前K-1排每排有偶数个人
	{
		while (i < N)
		{
			int j;								//i是当前排的最高的人，将j的初值赋值为i
			int rel = m - 1;					//定义当前排第一个输出的人相对于最高的人的索引偏移量
			for (j = i + rel;j >= i;j -= 2)
			{
				cout << student[j].name << " ";
			}
			for (j = i;j < i + m;j += 2)
			{
				if (j != i + m - 2)				//对于偶数，是i+m-2
				{
					cout << student[j].name << " ";
				}
				else
				{
					cout << student[j].name << endl;
				}
			}
			i = i + m;
		}
	}
	return 0;
}
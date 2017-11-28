// 1015.cpp : 定义控制台应用程序的入口点。
//灵活的使用结构体，并且在结构体中重定义<运算符，方便的用于sort排序
//结构体特别适用于对某一对象有多种属性的情况。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Student
{
	int id;
	int Cgrade;
	int Dgrade;
	bool operator < (const Student & A)							//定义sort的排序规则，先按总分降序，再按德分降序，最后按id升序
	{
		if (this->Cgrade + this->Dgrade != A.Cgrade + A.Dgrade)
		{
			return this->Cgrade + this->Dgrade > A.Cgrade + A.Dgrade;
		}
		else if (this->Dgrade != A.Dgrade)
		{
			return this->Dgrade > A.Dgrade;
		}
		else
		{
			return this->id < A.id;
		}
	}
};

int main()
{
	int N, L, H;
	cin >> N >> L >> H;
	vector<Student> student1, student2, student3, student4;			//定义四类考生
	Student tmp;
	int id, cai, de;
	freopen("input.txt", "r", stdin);
	int count = 0;
	for (int i = 0;i < N;i++)
	{
		cin >> id >> de >> cai;
		if (de >= L && cai >= L)
		{
			count++;
			if (cai >= H && de >= H)
			{
				tmp.Cgrade = cai;
				tmp.Dgrade = de;
				tmp.id = id;
				student1.push_back(tmp);
			}
			else if (de >= H)
			{
				tmp.Cgrade = cai;
				tmp.Dgrade = de;
				tmp.id = id;
				student2.push_back(tmp);
			}
			else if (de >= cai)
			{
				tmp.Cgrade = cai;
				tmp.Dgrade = de;
				tmp.id = id;
				student3.push_back(tmp);
			}
			else
			{
				tmp.Cgrade = cai;
				tmp.Dgrade = de;
				tmp.id = id;
				student4.push_back(tmp);
			}
		}
	}
	sort(student1.begin(), student1.end());
	sort(student2.begin(), student2.end());
	sort(student3.begin(), student3.end());
	sort(student4.begin(), student4.end());
	vector<Student>::iterator it;
	cout << count << endl;
	for (it = student1.begin();it != student1.end();it++)
	{
		cout << it->id << " " << it->Dgrade << " " << it->Cgrade;
		printf("\n");
	}
	for (it = student2.begin();it != student2.end();it++)
	{
		cout << it->id << " " << it->Dgrade << " " << it->Cgrade;
		printf("\n");
	}
	for (it = student3.begin();it != student3.end();it++)
	{
		cout << it->id << " " << it->Dgrade << " " << it->Cgrade;
		printf("\n");
	}
	for (it = student4.begin();it != student4.end();it++)
	{
		cout << it->id << " " << it->Dgrade << " " << it->Cgrade;
		printf("\n");
	}
    return 0;
}
// 1072.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct Student
{
	string name;
	int items;
	vector<int> id;
};

int forbidden[10000] = { 0 };

int main()
{
	int N, M;
	cin >> N >> M;
	int count_per = 0;
	int count_item = 0;
	int tmp;
	for (int i = 0;i<M;i++)
	{
		scanf("%d", &tmp);
		forbidden[tmp] = 1;
	}
	vector<Student> stu;
	int items = 0;
	for (int i = 0;i<N;i++)
	{
		Student tmp_stu;
		items = 0;
		cin >> tmp_stu.name;
		cin >> tmp_stu.items;
		for (int k = 0;k<tmp_stu.items;k++)
		{
			cin >> tmp;
			if (forbidden[tmp] == 1)
			{
				count_item++;
				items++;
				tmp_stu.id.push_back(tmp);
			}
		}
		if (items == 0)
		{
			continue;
		}
		else
		{
			stu.push_back(tmp_stu);
			count_per++;
		}
	}
	for (int i = 0;i<count_per;i++)
	{
		cout << stu[i].name << ": ";
		cout << setw(4) << setfill('0') << stu[i].id[0];
		for (int k = 1;k<stu[i].id.size();k++)
		{
			cout <<" "<< setw(4) << setfill('0') << stu[i].id[k];
		}
		cout << endl;
	}
	cout << count_per << " " << count_item << endl;
	return 0;
}

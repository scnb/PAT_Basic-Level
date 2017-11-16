// 1059.cpp : 定义控制台应用程序的入口点。
//居然把Are you kidding?中的k写成大写的了···
//这道题总的来说不是太难，只要把过程捋清楚，画出分支流程图来就好做了。
//难点在于，每一个分支的判断该怎样进行，比如：判断id是否存在，原来想的是写一个专门判断id是否存在的函数，通过折半查找来判断是否存在
//			这样会很费时间的，而如果事先定义好一个包含10000个数的数组，用来记录每个id是否存在，再检测的时候就方便的多了，同理还可以
//			记录每个id的排名，每个id被查询的次数，这样将极大地简化查询的过程。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

//bool Have_Id(int tmp,vector<int> id);		//判断id是否存在
bool is_sushu(int tmp);						//判断是不是素数;

int main()
{
	int N;
	int K;
	int count[10000] = { 0 };				//记录每个id被查询的次数
	int grade[10000] = { 0 };				//记录每个id的排名
	int flag[10000] = { 0 };				//记录某个id是否存在
	cin >> N;
	vector<int> id;
	int tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		grade[tmp] = i + 1;					//存储每个id的排名
		flag[tmp]++;						//表明存在该id
		id.push_back(tmp);
	}
	vector<int> sorted_id = id;						//定义从小到大排好序的vector便于折半查找
	cin >> K;
	vector<int> find_id;
	for (int i = 0;i < K;i++)
	{
		cin >> tmp;
		find_id.push_back(tmp);
	}
	sort(sorted_id.begin(), sorted_id.end());
	for (int i = 0;i < K;i++)
	{
		if (flag[find_id[i]] != 0)								//查看该id是否存在
		{
			if (count[find_id[i]] == 0)							//如果还没有被查询过
			{
				if (grade[find_id[i]] == 1)						//一等奖看的是id的排名，而不是id的值
				{
					cout << setw(4) << setfill('0') << find_id[i] << ": Mystery Award" << endl;
				}
				else if (is_sushu(grade[find_id[i]]))			//素数看的是排名，而不是id值
				{
					cout << setw(4) << setfill('0') << find_id[i] << ": Minion" << endl;
				}
				else
				{
					cout << setw(4) << setfill('0') << find_id[i] << ": Chocolate" << endl;
				}
				count[find_id[i]]++;
			}
			else
			{
				cout << setw(4) << setfill('0') << find_id[i] << ": Checked" << endl;
			}
		}
		else
		{
			cout << setw(4) << setfill('0') << find_id[i] << ": Are you kidding?" << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}

//bool Have_Id(int tmp, vector<int> id)		//判断是否存在该被查找的id
//{
//	int left = 0;
//	int right = id.size() - 1;
//	int mid = (left+right)/2;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (tmp == id[mid])
//		{
//			return true;
//		}
//		if (tmp < id[mid])
//		{
//			right = mid - 1;
//		}
//		else if (tmp > id[mid])
//		{
//			left = mid + 1;
//		}
//	}
//	return false;
//}

bool is_sushu(int tmp)		//判断是不是素数
{
	int flag = 0;
	if (tmp == 1)
	{
		return false;
	}
	else if (tmp == 2)
	{
		return true;
	}
	else
	{
		for (int i = 2;i <= sqrt(tmp);i++)
		{
			if (tmp % i == 0)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}	
}
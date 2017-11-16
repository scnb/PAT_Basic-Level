// 1049.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<double>list;
	double sum = 0;
	double num = 0;
	for (int i = 0;i < N;i++)
	{
		cin >> num;
		list.push_back(num);
	}
	for (int i = 0;i < N;i++)
	{
		sum += list[i] * (i + 1.0)*(N - i);
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
	getchar();
	getchar();
    return 0;
}

//一种三层循环的实现方法，但是会超时
	/*for (int i = 0;i < list.size();i++)
	{
		for (int j = i+1;j <= list.size();j++)
		{
			for (int k = i;k < j;k++)
			{
				sum += list[k];
			}
		}
	}*/

	//他妈的，两层循环还超时
	/*for (int i = 0;i < len;i++)
	{
		for (int j = len - i;j > 0;j--)
		{
			sum += j*list[len - j];
		}
	}*/
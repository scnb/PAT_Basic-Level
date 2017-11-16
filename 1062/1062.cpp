// 1062.cpp : 定义控制台应用程序的入口点。
//本题只考虑了真分数（且是正的）的情况。这样分析起来就会简便许多。
//另外，以K为分母的最间分数是在N1/M1和N2/M2的开区间之间
//目前得分19分

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N1, M1, N2, M2, K;
	cin >> N1;
	getchar();
	cin >> M1;
	getchar();
	cin >> N2;
	getchar();
	cin >> M2;
	getchar();
	cin >> K;

	double down = N1*1.0 / M1;
	double up = N2*1.0 / M2;
	vector<int> fenzi;			//用来存储有可能的分子
	int i = 1;					//因为是正分数，所以不会有0
	double tmp = i*1.0 / K;
	int flag = 0;
	while (tmp < up)
	{
		if (tmp > down)
		{
			if (i == 1)
			{
				fenzi.push_back(i);
			}
			else if (i == 2)
			{
				if (K % 2 == 0)
				{
					i++;
					continue;
				}
				else
				{
					fenzi.push_back(i);
				}
			}
			else
			{
				for (int j = 2;j <= i;j++)					//循环判断是不是有公约数
				{
					if (i%j == 0 && K%j == 0)				//分子和分母有公约数即可以整除同一个数
					{
						flag = 1;
					}
				}
				if (flag == 0)
				{
					fenzi.push_back(i);
				}
				else
				{
					flag = 0;
				}
			}
		}
		i++;
		tmp = i*1.0 / K;
	}

	cout << fenzi[0] << "/" << K;
	for (int i = 1;i < fenzi.size();i++)
	{
		cout << " " << fenzi[i] << "/" << K;
	}
	getchar();
	getchar();
    return 0;
}
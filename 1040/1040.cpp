// 1040.cpp : 定义控制台应用程序的入口点。
//三重循环会超时
//这里参考了CSDN网友思雨独辰的博客，他的实现思路确实无比精妙。


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	/*vector<int> P;
	vector<int> A;
	vector<int> T;
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] == 'P')
		{
			P.push_back(i);
		}
		else if (str[i] == 'A')
		{
			if (P.size() != 0 && str[i] > P[0])
			{
				A.push_back(i);
			}
		}
		else if (str[i] == 'T')
		{
			if (P.size() != 0 && A.size() != 0 && str[i] > A[0])
			{
				T.push_back(i);
			}
		}
	}
	int count = 0;
	for (int i = 0;i < P.size();i++)
	{
		for (int j = 0;j < A.size();j++)
		{
			if (P[i] > A[j])
			{
				continue;
			}
			for (int k = 0;k < T.size();k++)
			{
				if (A[j] > T[k])
				{
					continue;
				}
				else
				{
					count++;
				}
			}
		}
	}*/

	int P = 0;
	int PA = 0;
	int PAT = 0;
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] == 'P')
		{
			P++;							//统计这个P之前有多少个P
		}
		if (str[i] == 'A')
		{
			PA = (P + PA) % 1000000007;		//统计之前有多少PA组合，再加上现在的这个A与之前的P组成的PA组合

		}
		if (str[i] == 'T')
		{
			PAT = (PA + PAT) % 1000000007;	//统计之前有多少PAT组合，再加上现在的这个T与之前的AT组成的PAT组合
		}
	}
	cout << PAT << endl;
	return 0;
}


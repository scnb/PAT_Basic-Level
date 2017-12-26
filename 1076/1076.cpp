// 1076.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv)
{
	int N;
	cin >> N;
	vector<int> num;
	string ans;
	freopen("input.txt", "r", stdin);
	for (int i = 0;i<N;i++)
	{
		for (int j = 0;j<4;j++)
		{
			cin >> ans;
			if (ans[2] == 'T')
			{
				num.push_back(int(ans[0]) - 64);
			}
		}
	}
	for (int i = 0;i<N;i++)
	{
		cout << num[i];
	}
	return 0;
}

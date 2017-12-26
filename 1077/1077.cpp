// 1077.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int N, M;
	cin >> N >> M;
	vector<int> score;
	int G2 = 0;
	int G1 = 0;
	int tmp = 0;
	//freopen("input.txt","r",stdin);
	for (int i = 0;i<N;i++)
	{
		vector<int> tmp_score;
		scanf("%d", &G2);
		for (int k = 0;k<N - 1;k++)
		{
			scanf("%d", &tmp);
			if (tmp >= 0 && tmp <= M)
			{
				tmp_score.push_back(tmp);
			}
		}
		sort(tmp_score.begin(), tmp_score.end());
		int sum = 0;
		for (int j = 1;j<tmp_score.size() - 1;j++)
		{
			sum += tmp_score[j];
		}
		G1 = sum*1.0 / (tmp_score.size() - 2);
		double tmp_sum = (G1*1.0 + G2*1.0) / 2;
		score.push_back(tmp_sum + 0.5);
	}
	for (int i = 0;i<N;i++)
	{
		cout << score[i] << endl;
	}
	return 0;
}

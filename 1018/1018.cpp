// 1018.cpp : 定义控制台应用程序的入口点。
//重难点：用vector创建二维数组: vector<vector<int>> matrix(M,vector<int>(N))	创建出了一个M*N的二维数组
//这道题思路比较清晰，但是实现起来有难点。最重要的点就是选择合适的容器（数据结构）来存放数据，在本题中选用了vector创建的二维数组，事实证明，这个数据结构还是很好用的。


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<char>> log(N, vector<char>(0));
	string tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		log[i].push_back(tmp[0]);
		cin >> tmp;
		log[i].push_back(tmp[0]);
	}
	int count1_J = 0, count1_B = 0, count1_C = 0;		//分别记录以J、B、C取胜的次数
	int count2_J = 0, count2_B = 0, count2_C = 0;
	int equal = 0;										//甲乙二人的平局次数是相同的
	for (int i = 0;i < log.size();i++)
	{
		if (log[i][0] == log[i][1])
		{
			equal++;
		}
		else if (log[i][0] == 'C'&&log[i][1] == 'J')
		{
			count1_C++;
		}
		else if (log[i][0] == 'J'&&log[i][1] == 'B')
		{
			count1_J++;
		}
		else if (log[i][0] == 'B'&&log[i][1] == 'C')
		{
			count1_B++;
		}
		else if (log[i][0] == 'C'&&log[i][1] == 'B')
		{
			count2_B++;
		}
		else if (log[i][0] == 'J'&&log[i][1] == 'C')
		{
			count2_C++;
		}
		else if (log[i][0] == 'B'&&log[i][1] == 'J')
		{
			count2_J++;
		}
	}
	int count1 = count1_J + count1_C + count1_B;
	int count2 = count2_J + count2_C + count2_B;
	cout << count1 << " " << equal << " " << N - equal - count1 << endl;
	cout << count2 << " " << equal << " " << N - equal - count2 << endl;
	char most1, most2;
	double fre1[3], fre2[3];
	fre1[2] = count1_J *1.0 / N;
	fre1[0] = count1_B *1.0 / N;
	fre1[1] = count1_C *1.0 / N;
	fre2[2] = count2_J *1.0 / N;
	fre2[0] = count2_B *1.0 / N;
	fre2[1] = count2_C *1.0 / N;
	if (fre1[0] >= fre1[1] && fre1[0] >= fre1[2])
	{
		cout << "B" << " ";
	}
	else if (fre1[1] >= fre1[0] && fre1[1] >= fre1[2])
	{
		cout << "C" << " ";
	}
	else if (fre1[2] >= fre1[0] && fre1[2] >= fre1[1])
	{
		cout << "J" << " ";
	}
	
	if (fre2[0] >= fre2[1] && fre2[0] >= fre2[2])
	{
		cout << "B";
	}
	else if (fre2[1] >= fre2[0] && fre2[1] >= fre2[2])
	{
		cout << "C";
	}
	else if (fre2[2] >= fre2[0] && fre2[2] >= fre2[1])
	{
		cout << "J";
	}
	getchar();
	getchar();
    return 0;
}


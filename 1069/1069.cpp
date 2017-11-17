// 1069.cpp : 定义控制台应用程序的入口点。
//这道题比较简单，但是有一个地方需要特别注意，就是当遇到一个已经获奖的id时，不能简单的将i+1，而应该循环判断直到当前i指向的id没有得过奖。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	int M, N, S;						//注意，是M次转发而不是M个网友
	cin >> M >> N >> S;
	vector<string>id;
	vector<string>winner;
	map<string, int>count;
	string tmp = "";
	for (int i = 0;i < M;i++)
	{
		cin >> tmp;
		id.push_back(tmp);
		count[tmp] = 0;
	}
	int i = 0;
	for (i = S - 1;i < M;i+=N)
	{
		if (count[id[i]] < 1)
		{
			winner.push_back(id[i]);
			count[id[i]]++;
		}
		else
		{
			while (count[id[i]] >= 1)		//应该加入while循环来检测是否已经获奖，而不能简单的写成i+=1
			{
				i++;
			}
			if (i < M)						//还需要判断i+1后是否超出vector容器的大小
			{
				winner.push_back(id[i]);
				count[id[i]]++;
			}
		}
	}
	if (winner.size() == 0)
	{
		cout << "Keep going..." << endl;
	}
	else
	{
		for (int i = 0;i < winner.size();i++)
		{
			cout << winner[i] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
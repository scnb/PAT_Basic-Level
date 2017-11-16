// 1052.cpp : 定义控制台应用程序的入口点。
//What the fuck?这题是20分的水平吗？

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string *hand = new string[10];
	string *eye = new string[10];
	string *mouth = new string[10];
	string tmp1, tmp2, tmp3;
	getline(cin, tmp1);
	getline(cin, tmp2);
	getline(cin, tmp3);
	int j = 0;
	for (int i = 0;i < tmp1.length();i++)
	{
		if (tmp1[i] != '[' && tmp1[i] != ']')
		{
			hand[j] += tmp1[i];
		}
		if (tmp1[i] == ']')
		{
			j++;
		}
	}
	int nhand = j;
	j = 0;
	for (int i = 0;i < tmp2.length();i++)
	{
		if (tmp2[i] != '['&&tmp2[i] != ']')
		{
			eye[j] += tmp2[i];
		}
		if (tmp2[i] == ']')
		{
			j++;
		}
	}
	int neye = j;
	j = 0;
	for (int i = 0;i < tmp3.length();i++)
	{
		if (tmp3[i] != '['&&tmp3[i] != ']')
		{
			mouth[j] += tmp3[i];
		}
		if (tmp3[i] == ']')
		{
			j++;
		}
	}
	int nmouth = j;
	int K;
	cin >> K;
	string *req = new string[K];
	getchar();
	char num;
	for (int i = 0;i < K;i++)
	{
		cin>>num;
		if(num!=' ')
		{
			req[i] += num;
		}
	}
	j = 0;
	string tmp = "";
	int flag = 0;
	for (int i = 0;i < K;i++)
	{
		if (int(req[i][j] - 48) <= nhand)			//左手
		{
			tmp += hand[int(req[i][j++]) - 48];
		}
		else
		{
			flag = 1;
		}
		tmp += "(";
		if (int(req[i][j] - 48) <= neye)			//左眼
		{
			tmp += eye[int(req[i][j++]) - 48];
		}
		else
		{
			flag = 1;
		}
		if (int(req[i][j] - 48) <= nmouth)
		{
			tmp += mouth[int(req[i][j++] - 48)];	//口
		}
		else
		{
			flag = 1;
		}
		if (int(req[i][j] - 48) <= nmouth)
		{
			tmp += eye[int(req[i][j++] - 48)];		//右眼
		}
		else
		{
			flag = 1;
		}
		tmp += ")";
		if (int(req[i][j] - 48) <= nhand)
		{
			tmp += hand[int(req[i][j++]) - 48];	//右手
		}
		else
		{
			flag = 1;
		}
		if (flag == 0)
		{
			cout << tmp << endl;
		}
		else
		{
			cout << "Are you kidding me? @\/@" << endl;
		}
		j = 0;
	}
	getchar();
	getchar();
    return 0;
}


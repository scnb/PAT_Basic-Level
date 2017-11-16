// 1037.cpp : 定义控制台应用程序的入口点。
//这道题思路比较简单，实现起来稍微麻烦一点，主要是要分类的情况比较多，可以想个办法来简化一下程序。

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string P;
	string A;
	cin >> P;
	cin >> A;
	int G1 = 0, S1 = 0, K1 = 0;
	int G2 = 0, S2 = 0, K2 = 0;
	int i = 0;
	string tmp = "";
	while (P[i] != '.')
	{
		tmp += P[i];
		i++;
	}
	G1 = stoi(tmp);				//字符串自动转成int
	tmp = "";
	i++;						//越过点号，指向下一个开始的数字
	while (P[i] != '.')
	{
		tmp += P[i];
		i++;
	}
	S1 = stoi(tmp);
	tmp = "";
	i++;
	for (;i < P.length();i++)
	{
		tmp += P[i];
	}
	K1 = stoi(tmp);

	tmp = "";
	i = 0;
	while (A[i] != '.')
	{
		tmp += A[i];
		i++;
	}
	G2 = stoi(tmp);				//字符串自动转成int
	tmp = "";
	i++;						//越过点号，指向下一个开始的数字
	while (A[i] != '.')
	{
		tmp += A[i];
		i++;
	}
	S2 = stoi(tmp);
	tmp = "";
	i++;
	for (;i < A.length();i++)
	{
		tmp += A[i];
	}
	K2 = stoi(tmp);
	int flag = 0;			//如果flag为0，说明A大于P,则用A减P，否则用P减A，并且在输出时加上正号
	if (G2 > G1)
	{
		int G3 = 0, S3 = 0, K3 = 0;
		if (K2 >= K1)
		{
			K3 = K2 - K1;
		}
		else
		{
			K3 = K2 + 29 - K1;
			S2 -= 1;
		}
		if (S2 >= S1)
		{
			S3 = S2 - S1;
		}
		else
		{
			S3 = S2 + 17 - S1;
			G2 -= 1;
		}
		G3 = G2 - G1;
		cout << G3 << "." << S3 << "." << K3 << endl;
	}
	else if (G2 == G1)
	{
		int G3 = 0, S3 = 0, K3 = 0;
		G3 = G2 - G1;
		if (S2 > S1)
		{
			if (K2 >= K1)
			{
				K3 = K2 - K1;
			}
			else if (K2 < K1)
			{
				K3 = K2 + 29 - K1;
				S2 -= 1;
			}
			S3 = S2 - S1;
			cout << G3 << "." << S3 << "." << K3 << endl;
		}
		else if (S2 == S1)
		{
			S3 = S2 - S1;
			if (K2 >= K1)
			{
				K3 = K2 - K1;
				cout << G3 << "." << S3 << "." << K3 << endl;
			}
			else
			{
				K3 = K1 - K2;
				cout <<"-"<< G3 << "." << S3 << "." << K3 << endl;
			}
		}
		else if (S2 < S1)
		{
			if (K1 >= K2)
			{
				K3 = K1 - K2;
			}
			else
			{
				K3 = K1 + 29 - K2;
				S1 -= 1;
			}
			S3 = S1 - S2;
		}
	}
	else if (G2 < G1)
	{
		int G3 = 0, S3 = 0, K3 = 0;
		if (K1 >= K2)
		{
			K3 = K1 - K2;
		}
		else
		{
			K3 = K1 + 29 - K2;
			S1 -= 1;
		}
		if (S1 >= S2)
		{
			S3 = S1 - S2;
		}
		else
		{
			S3 = S1 + 17 - S2;
			G1 -= 1;
		}
		G3 = G1 - G2;
		cout << "-" << G3 << "." << S3 << "." << K3 << endl;
	}
	getchar();
	getchar();
    return 0;
}
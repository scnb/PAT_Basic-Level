// 1074.cpp : 定义控制台应用程序的入口点。
//最终19分，还差一点

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string N;		//进制表
	string add1;
	string add2;
	cin >> N;
	cin >> add1;
	cin >> add2;
	int len1 = add1.size();
	int len2 = add2.size();
	string tmp = "";
	int min = 0, max = 0;
	for (int i = 0;i < abs(len2 - len1);i++)
	{
		tmp += '0';
	}
	if (len1 < len2)
	{
		add1 = tmp + add1;
		max = len2;
	}
	else
	{
		add2 = tmp + add2;
		max = len1;
	}
	int len = N.size();
	int carry = 0;
	string sum;
	string tmp1;
	string tmp2;
	string tmp3;
	int div;
	int tmp_sum;
	int t = len - 1;
	for (int i = max - 1;i >= 0;i--)
	{
		tmp1 = add1[i];
		tmp2 = add2[i];
		tmp3 = N[t--];
		div = stoi(tmp3);		//当前位的进制
		if (div == 0)
		{
			div += 10;
		}
		tmp_sum = stoi(tmp1) + stoi(tmp2) + carry;
		carry = tmp_sum / div;
		sum += tmp_sum - carry*div;
	}
	sum += carry;				//有可能最高位还存在进位，所以要再加一下carry
	int i = sum.size() - 1;		//上一步增加了carry，则sum的大小也变了
	while (sum[i]+0 == 0)
	{
		i--;
	}
	for (;i >= 0;i--)
	{
		cout << (sum[i]+0);
	}
    return 0;
}
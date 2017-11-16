// 1031.cpp : 定义控制台应用程序的入口点。
//这道题不难···，但是一遇到有关在字符串中同时存在字符和数字的时候，进行判断时就会出现问题。
/*
	比如：在这道题中，我被第50行那个判断卡住了，原来写的是只判断（M[Z]!=(id[i][17]-'0'），但是这样只对数字有效，并不对字符'X'有效，
		  因此需要两个判断条件同时成立才可行。
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };	//定义权重数组，对应身份证号的前17位
	char  M[11] = { 1,0,'X',9,8,7,6,5,4,3,2 };
	int N;
	int flag = 0;		//标记身份证号是否有问题，若有问题则置1
	int count = 0;		//记录有多少个身份证号有问题
	cin >> N;
	string *id = new string[N];
	for (int i = 0;i < N;i++)
	{
		cin >> id[i];
	}

	for (int i = 0;i < N;i++)
	{
		int sum = 0;
		flag = 0;
		for (int j = 0;j < 17;j++)
		{
			if (id[i][j] >= '0' && id[i][j] <= '9')
			{
				sum += (id[i][j] - '0') * weight[j];
			}
			else
			{
				flag = 1;
				count++;
				break;
			}
		}
		if (flag == 1)
		{
			cout << id[i] << endl;
		}
		else
		{
			int Z = sum % 11;
			if ((M[Z] != (id[i][17])) && M[Z] != (id[i][17] - '0'))
			{
				count++;
				cout << id[i] << endl;
			}
		}
	}
	if (count == 0)
	{
		cout << "All passed" << endl;
	}
	delete[]id;
	getchar();
	getchar();
    return 0;
}


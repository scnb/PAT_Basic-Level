// 1024.cpp : 定义控制台应用程序的入口点。
//这道题说难不难，说不复杂也复杂，主要的就是要列请注意事项，要把步骤想清、想全。注意分类情况。
/*
	本题思路：①定义string来接收输入
			  ②判断第一个字符是+还是-，并做好标记，如果是-，则向vector中存入-
			  ③然后循环存入数字，直到遇到小数点停止
			  ④跳过小数点再循环存入数字，直到遇到E
			  ⑤跳过E，判断下一个字符是+还是-，并做好标记
			  ⑥剩下的数字都是指数的值的部分，计算出该值是多少
			  ⑦进行分类判断，考虑sign和flag分别为正负的情况，对于flag为正时，还有考虑N和m的大小情况
	本题重点用到了vector的insert方法：insert(用迭代器指示的位置，插入几个字符（可以省略），插入什么字符/数字）
	所以在最后，用insert插入0和小数点。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string str;
	int m = 0;						//用来记录小数点后面有几个数
	int N = 0;						//用来记录指数的值
	int flag;						//用来记录指数的正负，1表示负，0表示正
	int sign = 0;					//表示整个数字的正负，1表示负，0表示正
	cin >> str;
	vector<int> num;
	if (str[0] == '-')			//查看第一个字符，判断正负
	{
		num.push_back('-');
		sign = 1;
	}
	int i = 1;
	while (str[i] != '.')
	{
		num.push_back(str[i]-'0');
		i++;
	}
	i++;
	while (str[i] != 'E')
	{
		num.push_back(str[i] - '0');
		i++;
		m++;
	}
	i++;
	if (str[i] == '+')
	{
		flag = 0;
	}
	else if (str[i] == '-')
	{
		flag = 1;
	}
	i++;
	int index = str.length() - i - 1;					//计算指数的值部分有几位
	for (;i < str.length();i++)
	{
		N += (str[i] - '0')*pow(10, index--);
	}

	if (flag == 1)													//表示应该在前面补0，补N个
	{
		if (sign == 1)
		{
			vector<int>::iterator it = num.begin()+1;
			num.insert(it, N, 0);									//在第一个数字前插入N个0
			it = num.begin() + 2;
			num.insert(it, '.');
		}
		else
		{
			vector<int>::iterator it = num.begin();
			num.insert(it, N, 0);
			it = num.begin() + 1;										//插入小数点
			num.insert(it, '.');
		}					
	}
	else															//表示应该在后面补0，补N-m个（如果N大于m）
	{
		if (N >= m)
		{
			vector<int>::iterator it = num.end();
			num.insert(it, N - m, 0);
		}
		else
		{
			vector<int>::iterator it = num.end() - (m - N);
			num.insert(it, '.');								//插入小数点
		}
	}
	for (int i = 0;i < num.size();i++)
	{
		if (num[i] == 45)
		{
			cout << "-";
		}
		else if (num[i] == '.')
		{
			cout << ".";
		}
		else
		{
			cout << num[i];
		}
	}
	getchar();
	getchar();
	return 0;
}
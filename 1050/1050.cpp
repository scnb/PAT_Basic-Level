// 1050.cpp : 定义控制台应用程序的入口点。
/*原来计算m和n的方法是错误的，没有考虑全面，比如说N=26这种情况，采用新的算法*/
//目前存在运行超时和段错误，还是有些问题没有考虑到
//上面的段错误问题出现在没有考虑到N是素数这一特殊情况，当N是素数时，其只能是一维数组，顺序输出，所以单独考虑。
//还存在一个超时问题

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

bool is_Prime(int N);

int main()
{
	int N;
	cin >> N;
	vector<int> num;
	int tmp;
	//freopen("input4.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	int m = 0, n = 0, min = N;
	if (is_Prime(N))
	{
		for (int i = N - 1;i >= 0;i--)
		{
			cout << num[i] << endl;
		}
		return 0;
	}
	else
	{
		int sqt = (int)sqrt(N);
		for (int i = 1;i <= sqt;i++)
		{
			if (N%i == 0)
				n = i;
		}
		m = N / n;
	}
	
	vector<vector<int>> mat;				//定义螺旋矩阵
	for (int i = 0;i < m;i++)
	{
		vector<int> temp;
		for (int j = 0;j < n;j++)
		{
			temp.push_back(0);
		}
		mat.push_back(temp);
	}
	int count = 0;
	int row = 0, col = 0;
	int i = 0, j = 0;
	while (count != N)								//这一块算法稍有点复杂，有一个测试点超时
	{
		//正向行
		for (j = col;j < n - col;j++)
		{
			mat[row][j] = num[N - count - 1];
			count++;
		}
		//正向列
		for (i = row + 1;i < m - row;i++)
		{
			mat[i][j - 1] = num[N - count - 1];
			count++;
		}
		//反向行
		for (j = n - col - 2;j >= col;j--)
		{
			mat[i - 1][j] = num[N - count - 1];
			count++;
		}
		//反向列
		for (i = m - row - 2;i >= row + 1;i--)
		{
			mat[i][j + 1] = num[N - count - 1];
			count++;
		}
		row++;
		col++;
	}
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (j != n - 1)
			{
				cout << mat[i][j] << " ";
			}
			else
			{
				cout << mat[i][j];
			}
		}
		cout << endl;
	}
    return 0;
}

bool is_Prime(int N)
{
	if (N == 1)
	{
		return false;
	}
	else if (N == 2)
	{
		return true;
	}
	else
	{
		for (int i = 2;i <= sqrt(N);i++)
		{
			if (N%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}
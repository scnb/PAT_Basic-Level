// 1050.cpp : �������̨Ӧ�ó������ڵ㡣
/*ԭ������m��n�ķ����Ǵ���ģ�û�п���ȫ�棬����˵N=26��������������µ��㷨*/
//Ŀǰ�������г�ʱ�Ͷδ��󣬻�����Щ����û�п��ǵ�
//����Ķδ������������û�п��ǵ�N��������һ�����������N������ʱ����ֻ����һά���飬˳����������Ե������ǡ�
//������һ����ʱ����

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
	
	vector<vector<int>> mat;				//������������
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
	while (count != N)								//��һ���㷨���е㸴�ӣ���һ�����Ե㳬ʱ
	{
		//������
		for (j = col;j < n - col;j++)
		{
			mat[row][j] = num[N - count - 1];
			count++;
		}
		//������
		for (i = row + 1;i < m - row;i++)
		{
			mat[i][j - 1] = num[N - count - 1];
			count++;
		}
		//������
		for (j = n - col - 2;j >= col;j--)
		{
			mat[i - 1][j] = num[N - count - 1];
			count++;
		}
		//������
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
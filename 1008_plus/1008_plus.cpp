// 1008_plus.cpp : 定义控制台应用程序的入口点。
//这是一种符合题目要求的，没有耍小聪明的方法。

#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int *a,int i, int j);
void reverse(int *tmp, int n, int m);
void revote(int *tmp, int n, int m);

int main()
{
	int N, M;
	cin >> N >> M;
	int *arr = new int[N];
	for (int i = 0;i < N;i++)
	{
		cin >> arr[i];
	}
	if (M == 0 || N == 1)
	{
		int i;
		for (i = 0;i < N - 1;i++)
		{
			cout << arr[i] << " ";
		}
		cout << arr[i] << endl;
	}
	else
	{
		M = N - M%N;
		revote(arr, N, M);
		int i;
		for (i = 0;i < N-1;i++)
		{
			cout << arr[i] << " ";
		}
		cout << arr[i] << endl;
	}
	getchar();
	getchar();
    return 0;
}

void swap(int *a,int i, int j)
{
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void reverse(int *tmp, int n, int m)
{
	while (n < m)
	{
		swap(tmp, n, m);
		n++;
		m--;
	}
}

void revote(int *tmp, int n, int m)
{
	reverse(tmp, 0, m - 1);
	reverse(tmp, m, n-1);
	reverse(tmp, 0, n - 1);
}
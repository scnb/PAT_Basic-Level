// 1061.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚ�������ʵ��Ҳ�Ƚϼ򵥡���Ҫ��һ���������new�����ά���飬�ο���23��27�У���new��һ��һά����������������е�ÿһ��Ԫ�ض���һ�������ָ��
//Ȼ����ѭ����ÿһ��Ԫ�أ�ָ�룩����ռ䡣

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int *score = new int[M];
	for (int i = 0;i < M;i++)
	{
		cin >> score[i];
	}
	int *ans = new int[M];
	for (int i = 0;i < M;i++)
	{
		cin >> ans[i];
	}
	//����һ����ά����
	int **stu = new int*[N];
	for (int i = 0;i < N;i++)
	{
		stu[i] = new int[M];
	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> stu[i][j];
		}
	}
	int *sum = new int[N];
	for (int i = 0;i < N;i++)
	{
		sum[i] = 0;
		for (int j = 0;j < M;j++)
		{
			if (stu[i][j] == ans[j])
			{
				sum[i] += score[j];
			}
		}
	}
	for (int i = 0;i < N;i++)
	{
		cout << sum[i] << endl;
	}
	getchar();
	getchar();
    return 0;
}


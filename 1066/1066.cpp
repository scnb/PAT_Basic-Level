// 1066.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·Ҳ�Ƚ�������ʵ�ּ򵥡��ص㻹����new�������ά���飬�Լ�����iomanip�е�setw��setfill�������趨�����Ⱥ�����ַ���

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int M, N;		//�ֱ�Ϊͼ�������������
	int A, B;		//�����˵ĻҶ�ֵ����˵�
	int tmp;		//ָ�����滻�Ҷ�ֵ
	cin >> M >> N >> A >> B >> tmp;
	int **point = new int*[M];
	for (int i = 0;i < M;i++)
	{
		point[i] = new int[N];
	}
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> point[i][j];
			if (point[i][j] >= A && point[i][j] <= B)
			{
				point[i][j] = tmp;
			}
		}
	}
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (j != N - 1)
			{
				cout << setw(3) << setfill('0') << point[i][j] << " ";
			}
			else
			{
				cout << setw(3) << setfill('0') << point[i][j] << endl;
			}
		}
	}
	getchar();
	getchar();
    return 0;
}


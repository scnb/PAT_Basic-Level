// 1062.cpp : �������̨Ӧ�ó������ڵ㡣
//����ֻ��������������������ģ���������������������ͻ�����ࡣ
//���⣬��KΪ��ĸ������������N1/M1��N2/M2�Ŀ�����֮��
//Ŀǰ�÷�19��

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N1, M1, N2, M2, K;
	cin >> N1;
	getchar();
	cin >> M1;
	getchar();
	cin >> N2;
	getchar();
	cin >> M2;
	getchar();
	cin >> K;

	double down = N1*1.0 / M1;
	double up = N2*1.0 / M2;
	vector<int> fenzi;			//�����洢�п��ܵķ���
	int i = 1;					//��Ϊ�������������Բ�����0
	double tmp = i*1.0 / K;
	int flag = 0;
	while (tmp < up)
	{
		if (tmp > down)
		{
			if (i == 1)
			{
				fenzi.push_back(i);
			}
			else if (i == 2)
			{
				if (K % 2 == 0)
				{
					i++;
					continue;
				}
				else
				{
					fenzi.push_back(i);
				}
			}
			else
			{
				for (int j = 2;j <= i;j++)					//ѭ���ж��ǲ����й�Լ��
				{
					if (i%j == 0 && K%j == 0)				//���Ӻͷ�ĸ�й�Լ������������ͬһ����
					{
						flag = 1;
					}
				}
				if (flag == 0)
				{
					fenzi.push_back(i);
				}
				else
				{
					flag = 0;
				}
			}
		}
		i++;
		tmp = i*1.0 / K;
	}

	cout << fenzi[0] << "/" << K;
	for (int i = 1;i < fenzi.size();i++)
	{
		cout << " " << fenzi[i] << "/" << K;
	}
	getchar();
	getchar();
    return 0;
}
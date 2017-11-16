// 1053.cpp : �������̨Ӧ�ó������ڵ㡣
//��������һ���ܴ����ʾ�ǣ����û�кõķ������洢����ʱ���Ǿ�ֱ�ӽ��м���
//��ʹ�Ľ�ѵ���������Ҳ�Ӧ��ֻ���Ű����ݴ������ټ��㣬��ʵ���ζ�һ������Ȼ�������Ӧ�Ĳ����������������
//Ȼ��������forѭ���еıȽϲ��ֵ�ֵ������δ֪�ģ�ֻҪ�ڱȼ�֮ǰ���к��ʵ�ֵ�Ϳ��ԡ�

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int N;
	double e;
	int D;
	double possible_empty = 0.0;
	double empty = 0.0;
	cin >> N >> e >> D;
	for (int i = 0;i < N;i++)
	{
		int K;
		double tmp;
		int count = 0;
		cin >> K;
		for (int j = 0;j < K;j++)
		{
			cin >> tmp;
			if (tmp < e)
			{
				count++;
			}
		}
		if (count > K / 2)
		{
			if (K > D)
			{
				empty += 1;
			}
			else 
			{
				possible_empty += 1;
			}
		}
	}
	possible_empty = possible_empty / (N*1.0) * 100;
	empty = empty / (N*1.0) * 100;
	cout << setiosflags(ios::fixed) << setprecision(1) << possible_empty << "%" << " " << setiosflags(ios::fixed) << setprecision(1) << empty << "%" << endl;
	getchar();
	getchar();
    return 0;
}


// 1038_plus.cpp : �������̨Ӧ�ó������ڵ㡣
//����csdnĳ�˵Ĳ��Ͳ���ʶ����������˼·��֮ǰһ������˼·һ��������������ݵķ�Χ����������֪�ģ������������ʱ�򣬾�������������Ϊ������������Ԫ�ص�������ʵ�ּ�����

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	int score[100] = { 0 };
	cin >> N;
	int tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		score[tmp]++;
	}
	int K;
	cin >> K;
	for (int i = 0;i < K;i++)
	{
		cin >> tmp;
		if (i != K - 1)
		{
			cout << score[tmp] << " ";
		}
		else
		{
			cout << score[tmp] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


// 1008.cpp : �������̨Ӧ�ó������ڵ㡣
//�������������������������Ļ������ѣ�������Ҳû�а�����ĿҪ���������û�ж�����ı�˳�򣬶���ֱ�Ӵ��м�ĳ��Ԫ�ؿ�ʼ
//������������������ã��ܼ򵥡�
//������һ��Ҫ�����ڣ�Ҫ���ƶ����ݵĴ����������٣�����MӦ��ȡֵΪM%N��

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int *before = new int[N];
	for (int i = 0;i < N;i++)
	{
		cin >> before[i];
	}
	M = M % N;					//�ؼ���䣬��Ŀ��Ҫ���ƶ����ݵĴ����������٣���M>N=ʱ���൱���ж�ѭ���Ĳ��֡�
	{
		for (int i = N - M;i <N;i++)
		{
			cout << before[i] << " ";
		}
		for (int i = 0;i < N - M;i++)
		{
			if (i != N - M - 1)
			{
				cout << before[i] << " ";
			}
			else
			{
				cout << before[i] << endl;
			}
		}
	}
	getchar();
	getchar();
    return 0;
}


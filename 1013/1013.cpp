// 1013.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·���ǱȽ������ģ�����Ҫע���һ���������ĸ����Ǳ���Ȼ���ĸ���С�ܶ�ģ�������ĿҪ�����ȡ����10000��������
//��ô��Ȼ���ĸ�����Ҫ��100000����Ϊ�˷����������ֱ�ӽ���Ȼ���ĸ�����Ϊ200000����

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int tmp[100000] = { 0 };
	int k = 0;
	int flag = 0;
	//�Ȱ����е������ҳ���
	for (int i = 2;i <= 200000;i++)
	{
		if (i == 2)
		{
			tmp[k++] = 2;
		}
		else
		{
			for (int j = 2;j <= sqrt(i);j++)
			{
				if (i%j == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				tmp[k++] = i;
			}
			flag = 0;
		}
	}
	int sign = 0;
	for (int i = M - 1;i < N;i++)
	{
		if (i == N - 1)
		{
			if (N - M + 1 % 10 == 0)
			{
				cout << tmp[i] << endl;
			}
			else
			{
				cout << tmp[i];
			}
		}
		else
		{
			if (sign < 9)
			{
				cout << tmp[i] << " ";
				sign++;
			}
			else
			{
				cout << tmp[i] << endl;
				sign = 0;
			}
		}
		
	}
	getchar();
	getchar();
    return 0;
}


// 1012.cpp : �������̨Ӧ�ó������ڵ㡣
//֮ǰ�İ汾ֻ�ܵ�19�֣���֪������һ�����Ե㲻��ͨ����
//�ο���csdn�ϵĲ��ͣ������������޸ģ��ܹ�ȫ��ͨ���ˡ�
/*
	�ٽ����������Ƕ����޸ĳ����ȼ����num[i]%5��Ȼ��Ͳ�����ÿ��if-else���ظ����������ˡ�
	�ڽ�A1-A5��������飬ԭ�������������int������
	�۶���n[5]������¼A1-A5���������������ָ��������������ʱ���ܷ�����ж���һ��Ӧ�����N�ˡ�
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *num = new int[N];
	for (int i = 0;i < N;i++)
	{
		cin >> num[i];
	}
	int A[5] = { 0 };
	int n[5] = { 0 };			//�ֱ��¼A1-A5�ֱ��ж��ٸ����ַ�������
	int sign = 1;				//�����ű��
	for (int i = 0;i < N;i++)
	{
		int tmp = num[i] % 5;
		if (tmp == 0 && num[i]%2==0)
		{
			A[0] += num[i];
			n[0]++;
		}
		else if (tmp == 1)
		{
			A[1] += sign * num[i];
			sign *= -1;
			n[1]++;
		}
		else if (tmp == 2)
		{
			A[2]++;
			n[2]++;
		}
		else if (tmp == 3)
		{
			A[3] += num[i];
			n[3]++;
		}
		else if (tmp == 4)
		{
			if (num[i] > A[4])
			{
				A[4] = num[i];
				n[4]++;
			}
		}
	}
	for (int i = 0;i < 5;i++)
	{
		if (n[i] != 0)
		{
			if (i == 3)
			{
				cout << setiosflags(ios::fixed) << setprecision(1) << (1.0)*A[i] / n[i] << " ";
			}
			else if (i == 4)
			{
				cout << A[i];
			}
			else
			{
				cout << A[i] << " ";
			}
		}
		else
		{
			if (i != 4)
			{
				cout << "N" << " ";
			}
			else
			{
				cout << "N";
			}
		}
	}
	getchar();
	getchar();
    return 0;
}
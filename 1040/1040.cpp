// 1040.cpp : �������̨Ӧ�ó������ڵ㡣
//����ѭ���ᳬʱ
//����ο���CSDN����˼������Ĳ��ͣ�����ʵ��˼·ȷʵ�ޱȾ��


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	/*vector<int> P;
	vector<int> A;
	vector<int> T;
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] == 'P')
		{
			P.push_back(i);
		}
		else if (str[i] == 'A')
		{
			if (P.size() != 0 && str[i] > P[0])
			{
				A.push_back(i);
			}
		}
		else if (str[i] == 'T')
		{
			if (P.size() != 0 && A.size() != 0 && str[i] > A[0])
			{
				T.push_back(i);
			}
		}
	}
	int count = 0;
	for (int i = 0;i < P.size();i++)
	{
		for (int j = 0;j < A.size();j++)
		{
			if (P[i] > A[j])
			{
				continue;
			}
			for (int k = 0;k < T.size();k++)
			{
				if (A[j] > T[k])
				{
					continue;
				}
				else
				{
					count++;
				}
			}
		}
	}*/

	int P = 0;
	int PA = 0;
	int PAT = 0;
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] == 'P')
		{
			P++;							//ͳ�����P֮ǰ�ж��ٸ�P
		}
		if (str[i] == 'A')
		{
			PA = (P + PA) % 1000000007;		//ͳ��֮ǰ�ж���PA��ϣ��ټ������ڵ����A��֮ǰ��P��ɵ�PA���

		}
		if (str[i] == 'T')
		{
			PAT = (PA + PAT) % 1000000007;	//ͳ��֮ǰ�ж���PAT��ϣ��ټ������ڵ����T��֮ǰ��AT��ɵ�PAT���
		}
	}
	cout << PAT << endl;
	return 0;
}


// 1048.cpp : �������̨Ӧ�ó������ڵ㡣
//���ص㣺�Ը�λΪ��1λ�����λһ��������λ
//18�֣���������
//��������֣�ݴ�ѧĳѧ����ʵ�֣����ǰ�A��Bͨ����ǰ�油0���뵽һ����������ġ������ʹ���ʡ�˴�������
//���⣬���Բ���vector����string���洢���ܺ�����֣�string��һ�����ŵ��ǣ��ı�ӷ��м�����˳����ܸı��ַ������ӵ�˳��
//���磺str = '0'+str;	�ǰ��ַ�0����str��ǰ�棬��str = str+'0'�ǰ�0����str���棬�����Ͳ��ð�vector���������

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	vector<char>out;
	int flag = 1;				//��ʾ������λ
	int i;
	if (B.length() >= A.length())
	{
		int diff = B.length() - A.length();
		for (i = B.length() - 1;i >= diff;i--)
		{
			if (flag == 1)
			{
				int tmp = int(B[i] - 48) + int(A[i - diff] - 48);
				if (tmp == 10)
				{
					out.push_back('J');
				}
				else if (tmp == 11)
				{
					out.push_back('Q');
				}
				else if (tmp == 12)
				{
					out.push_back('K');
				}
				else
				{
					out.push_back(tmp % 13);
				}
				flag = 0;
			}
			else
			{
				int tmp = int(B[i] - 48) - int(A[i - diff] - 48);
				if (tmp < 0)
				{
					out.push_back(tmp + 10);
				}
				else
				{
					out.push_back(tmp);
				}
				flag = 1;
			}
		}
		for (i = diff - 1;i >= 0;i--)
		{
			out.push_back(int(B[i] - 48));		
		}
	}
	else if (B.length() < A.length())
	{
		int diff = A.length() - B.length();
		for (i = B.length() - 1;i >= 0;i--)
		{
			if (flag == 1)
			{
				int tmp = int(B[i] - 48) + int(A[i + diff] - 48);
				if (tmp == 10)
				{
					out.push_back('J');
				}
				else if (tmp == 11)
				{
					out.push_back('Q');
				}
				else if (tmp == 12)
				{
					out.push_back('K');
				}
				else
				{
					out.push_back(tmp % 13);
				}
				flag = 0;
			}
			else
			{
				int tmp = int(B[i] - 48) - int(A[i + diff] - 48);
				if (tmp < 0)
				{
					out.push_back(tmp + 10);
				}
				else
				{
					out.push_back(tmp);
				}
				flag = 1;
			}
		}
		for (i = diff - 1;i >= 0;i--)
		{
			if (flag == 1)
			{
				out.push_back(int(A[i] - 48));
				flag = 0;
			}
			else
			{
				out.push_back(10 - int(A[i]-48));
				flag = 1;
			}
		}
	}

	int j = out.size() - 1;
	while (int(out[j]) == 0)
	{
		j--;
	}
	for (int i=j;i >= 0;i--)
	{
		if (int(out[i]) > 9)
		{
			if (int(out[i]) == 74)
			{
				cout << "J";
			}
			else if (int(out[i]) == 81)
			{
				cout << "Q";
			}
			else if (int(out[i]) == 75)
			{
				cout << "K";
			}
		}
		else
		{
			cout << int(out[i]);
		}
	}
	getchar();
	getchar();
    return 0;
}
// 1044.cpp : �������̨Ӧ�ó������ڵ㡣
//��һЩ���⣬���������еĵ��ʶ���3����ĸ�ģ���Ҫ��������
/*
	����������Ѿ��ɹ��������Ҫ����Ҫ�������Ŀ����˼���������ĵĽ�λ���12����λ�����ǿ��Ե�������ʾ�������ֵġ�
	����tam��ʾ13����hel��ʾ26���Դ����ƣ�maa��ʾ39������
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string low_13[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string high_12[12] = { "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };

int main()
{
	int N;
	cin >> N;
	string *str = new string[N];
	getchar();												//�����һ��getchar()��������������ʱ�Ļس���
	for (int i = 0;i < N;i++)
	{
		getline(cin, str[i]);
	}
	for (int i = 0;i < N;i++)
	{
		if (str[i][0] >= '0' && str[i][0] <= '9')			//���������
		{
			int tmp = stoi(str[i]);
			if (tmp > 13 && tmp%13!=0)
			{
				int low = tmp % 13;							//��������
				int high = tmp / 13;						//������
				cout << high_12[high-1] << " " << low_13[low] << endl;
			}
			else if(tmp>=0 && tmp<=12)
			{
				cout << low_13[tmp] << endl;
			}
			else if (tmp % 13 == 0)
			{
				cout << high_12[(tmp / 13) - 1] << endl;
			}
		}
		else if (str[i].length() == 3 && str[i] != "tam")			//����ǵ���������
		{
			for (int j = 0;j < 13;j++)
			{
				if (str[i] == low_13[j])
				{
					cout << j << endl;
				}
			}
			for (int j = 0;j < 12;j++)
			{
				if (str[i] == high_12[j])
				{
					cout << (j + 1) * 13 << endl;
				}
			}
		}
		else if (str[i] == "tam")
		{
			cout << 13 << endl;
		}
		else if (str[i] == "tret")
		{
			cout << 0 << endl;
		}
		else if (str[i].length() == 7)			//�������λ�Ļ�����
		{
			string low = "";
			string high = "";
			for (int j = 0;j < 3;j++)
			{
				high += str[i][j];
			}
			for (int j = 4;j < 7;j++)
			{
				low += str[i][j];
			}
			int sum = 0;
			for (int j = 0;j < 12;j++)
			{
				if (high == high_12[j])
				{
					sum += (j + 1) * 13;
				}
			}
			for (int j = 0;j < 13;j++)
			{
				if (low == low_13[j])
				{
					sum += j;
				}
			}
			cout << sum << endl;
		}
		else if (str[i].length() == 8)			//�������λ�Ļ�����
		{
			string low = "";
			string high = "";
			for (int j = 0;j < 3;j++)
			{
				high += str[i][j];
			}
			for (int j = 4;j < 8;j++)
			{
				low += str[i][j];
			}
			int sum = 0;
			for (int j = 0;j < 12;j++)
			{
				if (high == high_12[j])
				{
					sum += (j + 1) * 13;
				}
			}
			for (int j = 0;j < 13;j++)
			{
				if (low == low_13[j])
				{
					sum += j;
				}
			}
			cout << sum << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
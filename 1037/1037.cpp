// 1037.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚϼ򵥣�ʵ��������΢�鷳һ�㣬��Ҫ��Ҫ���������Ƚ϶࣬��������취����һ�³���

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string P;
	string A;
	cin >> P;
	cin >> A;
	int G1 = 0, S1 = 0, K1 = 0;
	int G2 = 0, S2 = 0, K2 = 0;
	int i = 0;
	string tmp = "";
	while (P[i] != '.')
	{
		tmp += P[i];
		i++;
	}
	G1 = stoi(tmp);				//�ַ����Զ�ת��int
	tmp = "";
	i++;						//Խ����ţ�ָ����һ����ʼ������
	while (P[i] != '.')
	{
		tmp += P[i];
		i++;
	}
	S1 = stoi(tmp);
	tmp = "";
	i++;
	for (;i < P.length();i++)
	{
		tmp += P[i];
	}
	K1 = stoi(tmp);

	tmp = "";
	i = 0;
	while (A[i] != '.')
	{
		tmp += A[i];
		i++;
	}
	G2 = stoi(tmp);				//�ַ����Զ�ת��int
	tmp = "";
	i++;						//Խ����ţ�ָ����һ����ʼ������
	while (A[i] != '.')
	{
		tmp += A[i];
		i++;
	}
	S2 = stoi(tmp);
	tmp = "";
	i++;
	for (;i < A.length();i++)
	{
		tmp += A[i];
	}
	K2 = stoi(tmp);
	int flag = 0;			//���flagΪ0��˵��A����P,����A��P��������P��A�����������ʱ��������
	if (G2 > G1)
	{
		int G3 = 0, S3 = 0, K3 = 0;
		if (K2 >= K1)
		{
			K3 = K2 - K1;
		}
		else
		{
			K3 = K2 + 29 - K1;
			S2 -= 1;
		}
		if (S2 >= S1)
		{
			S3 = S2 - S1;
		}
		else
		{
			S3 = S2 + 17 - S1;
			G2 -= 1;
		}
		G3 = G2 - G1;
		cout << G3 << "." << S3 << "." << K3 << endl;
	}
	else if (G2 == G1)
	{
		int G3 = 0, S3 = 0, K3 = 0;
		G3 = G2 - G1;
		if (S2 > S1)
		{
			if (K2 >= K1)
			{
				K3 = K2 - K1;
			}
			else if (K2 < K1)
			{
				K3 = K2 + 29 - K1;
				S2 -= 1;
			}
			S3 = S2 - S1;
			cout << G3 << "." << S3 << "." << K3 << endl;
		}
		else if (S2 == S1)
		{
			S3 = S2 - S1;
			if (K2 >= K1)
			{
				K3 = K2 - K1;
				cout << G3 << "." << S3 << "." << K3 << endl;
			}
			else
			{
				K3 = K1 - K2;
				cout <<"-"<< G3 << "." << S3 << "." << K3 << endl;
			}
		}
		else if (S2 < S1)
		{
			if (K1 >= K2)
			{
				K3 = K1 - K2;
			}
			else
			{
				K3 = K1 + 29 - K2;
				S1 -= 1;
			}
			S3 = S1 - S2;
		}
	}
	else if (G2 < G1)
	{
		int G3 = 0, S3 = 0, K3 = 0;
		if (K1 >= K2)
		{
			K3 = K1 - K2;
		}
		else
		{
			K3 = K1 + 29 - K2;
			S1 -= 1;
		}
		if (S1 >= S2)
		{
			S3 = S1 - S2;
		}
		else
		{
			S3 = S1 + 17 - S2;
			G1 -= 1;
		}
		G3 = G1 - G2;
		cout << "-" << G3 << "." << S3 << "." << K3 << endl;
	}
	getchar();
	getchar();
    return 0;
}
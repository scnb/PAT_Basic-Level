// 1046.cpp : �������̨Ӧ�ó������ڵ㡣
//��������ǡ������������������ˣ���Ϊ����ǰ�漸���⣬�����ر�ע�������ݵ�������ѡ�����������������int���������4�����Ϳ����ˣ�
//������һ��ʼ�������string��������ţ����������һ��out of range�����⡣

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;		//N�غ�
	int one = 0, two = 0;
	int a, b, s1, s2;
	for (int i = 0;i < N;i++)
	{
		cin >> a >> s1 >> b >> s2;
		if (a + b == s1 && a+b!=s2)
		{
			two++;
		}
		else if (a + b == s2 && a+b!=s1)
		{
			one++;
		}
		else
		{
			continue;
		}
	}
	
	cout << one << " " << two << endl;
	getchar();
	getchar();
    return 0;
}


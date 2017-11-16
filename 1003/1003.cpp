// 1003.cpp : �������̨Ӧ�ó������ڵ㡣
//��������Ǿ��䣬�����Һܳ�ʱ�䣬Ҳ����������һЩ������Ҫһ�����Ͱ�������ȥһ������һ�������Ķ�Ӧ��
//Ӧ�ÿ�һ����Щ���е������ܷ��ܽ��һ�����ɣ����������
//���⣬��3�����������ǿ�ʼʱû������ԭ����˵�������aPbTc��������ô����ǰ�����������˳���a��b��c�Ĺ�ϵ����������
//Ȼ��������aPbATca�е�a��b��c�Ĺ�ϵ��
/*
	����������У���ͳ��P��A��T�ֱ��������������ǵĺ͵����ַ����ĳ��ȣ�˵�������һ��������
				  �ж�P��T�������Ƿ����1������ж��Ƿ�����ڶ���������
				  �ڶ��������͵������������Ƴ�����Pǰ��A����������P��T֮��A����������T�����A��������
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string *test = new string[n];
	for (int i = 0;i < n;i++)
	{
		cin >> test[i];
	}
	
	for (int i = 0;i < n;i++)
	{
		int count_p = 0, count_a = 0, count_t = 0;
		int pos_p = 0, pos_t = 0;
		int len = test[i].length();
		for (int j = 0;j < len;j++)
		{
			if (test[i][j] == 'P')
			{
				count_p++;
				pos_p = j;
			}
			if (test[i][j] == 'A')
			{
				count_a++;
			}
			if (test[i][j] == 'T')
			{
				count_t++;
				pos_t = j;
			}
		}
		if (count_p + count_a + count_t != len || pos_t - pos_p <= 1 || count_p > 1 || count_t > 1 || pos_p*(pos_t - pos_p - 1) != (len - pos_t - 1))
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}


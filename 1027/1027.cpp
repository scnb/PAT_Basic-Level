// 1027.cpp : �������̨Ӧ�ó������ڵ㡣
//�����Ƚϼ򵥣�����·�ˡ��ص㿼�����������з��������Լ�ǰ���Ŀո����Ĺ�ϵ

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	char sign;
	cin >> N >> sign;
	int sum = 1;			//��������һ��
	int i = 1;				//��������һ��
	for (int j=1;sum < N;j++)
	{
		if (sum + 2 * (2 * j + 1) <= N)
		{
			sum += 2 * (2 * j + 1);
			i += 2;
		}
		else
		{
			break;
		}
	}
	int rows = i;				//����
	int leave = N - sum;		//��ʾʣ��ķ�������
	for (int j = 0;j <= rows / 2;j++)
	{
		for (int m = 0;m < (rows - i) / 2;m++)
		{
			cout << " ";
		}
		for (int k = 0;k < i;k++)
		{
			cout << sign;
		}
		i = i - 2;
		cout << endl;
	}
	for (int j = 0;j < rows / 2;j++)
	{
		int num = 2 * (j + 1) + 1;
		for (int m = 0;m < (rows - num) / 2;m++)
		{
			cout << " ";
		}
		for (int k = 0;k < num;k++)
		{
			cout << sign;
		}
		cout << endl;
	}
	cout << leave << endl;
	getchar();
	getchar();
    return 0;
}


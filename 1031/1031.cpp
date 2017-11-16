// 1031.cpp : �������̨Ӧ�ó������ڵ㡣
//����ⲻ�ѡ�����������һ�����й����ַ�����ͬʱ�����ַ������ֵ�ʱ�򣬽����ж�ʱ�ͻ�������⡣
/*
	���磺��������У��ұ���50���Ǹ��жϿ�ס�ˣ�ԭ��д����ֻ�жϣ�M[Z]!=(id[i][17]-'0'������������ֻ��������Ч���������ַ�'X'��Ч��
		  �����Ҫ�����ж�����ͬʱ�����ſ��С�
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };	//����Ȩ�����飬��Ӧ���֤�ŵ�ǰ17λ
	char  M[11] = { 1,0,'X',9,8,7,6,5,4,3,2 };
	int N;
	int flag = 0;		//������֤���Ƿ������⣬������������1
	int count = 0;		//��¼�ж��ٸ����֤��������
	cin >> N;
	string *id = new string[N];
	for (int i = 0;i < N;i++)
	{
		cin >> id[i];
	}

	for (int i = 0;i < N;i++)
	{
		int sum = 0;
		flag = 0;
		for (int j = 0;j < 17;j++)
		{
			if (id[i][j] >= '0' && id[i][j] <= '9')
			{
				sum += (id[i][j] - '0') * weight[j];
			}
			else
			{
				flag = 1;
				count++;
				break;
			}
		}
		if (flag == 1)
		{
			cout << id[i] << endl;
		}
		else
		{
			int Z = sum % 11;
			if ((M[Z] != (id[i][17])) && M[Z] != (id[i][17] - '0'))
			{
				count++;
				cout << id[i] << endl;
			}
		}
	}
	if (count == 0)
	{
		cout << "All passed" << endl;
	}
	delete[]id;
	getchar();
	getchar();
    return 0;
}


// 1041.cpp : �������̨Ӧ�ó������ڵ㡣
//�����Ƚϼ򵥣�������Ŀ������ֱ�۵��뵽˼·��

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;		//��������
	int M;		//M������ѯ���Ի���λ����
	cin >> N;
	string *id = new string[N];	//14λ��׼��֤��
	int *test = new int[N];		//1-N���Ի���λ��
	int *exam = new int[N];		//1-N�Ŀ�����λ��
	for (int i = 0;i < N;i++)
	{
		cin >> id[i] >> test[i] >> exam[i];
	}
	getchar();
	cin >> M;
	
	int *find = new int[M];
	for (int i = 0;i < M;i++)
	{
		cin >> find[i];
	}

	int flag = 0;
	for (int i = 0;i < M;i++)
	{
		flag = 0;
		//��M������ѯ������в���
		for (int j = 0;j < N;j++)
		{
			if (test[j] == find[i])
			{
				flag = j;
				break;
			}
		}
		cout << id[flag] << " " << exam[flag] << endl;
	}
	delete[]id, test, exam;
	getchar();
	getchar();
    return 0;
}


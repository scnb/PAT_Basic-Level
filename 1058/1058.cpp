// 1058.cpp : �������̨Ӧ�ó������ڵ㡣
//���ǰѺ����N��ͬѧ�Ĵ�һ��һ�е����룬ÿ����getline(cin,str)������һ���У��������Ҳ�Ƚ����ף���whileѭ�������˵��ո������

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int *score = new int[M];					//M����ķ�ֵ
	int *num = new int[M];						//M�����ѡ�����
	int *right_num = new int[M];				//M�������ȷѡ�����
	int *count = new int[M]();					//M����Ĵ����������ʼ��Ϊ0
	int *sum = new int[N]();					//N��ͬѧ�ĵ÷����
	int *id = new int[M];						//���ڴ�Ŵ������������Ŀ�����
	string *right_answer = new string[M]();		//M�������ȷѡ��
	string answer;								//ÿ��ͬѧÿ��������Ļش�
	string str;
	string tmp;
	//freopen("d:\\inputs.txt", "r", stdin);
	for (int i = 0;i < M;i++)
	{
		cin >> score[i] >> num[i] >> right_num[i];
		getline(cin, right_answer[i]);
	}
	for (int i = 0;i < N;i++)
	{
		int t = 0;					//�����������ĵ���
		getline(cin, str);
		for (int j = 0;j < str.length();j++,t++)
		{
			while (str[j]==' ' || str[j]=='(' || str[j]==')')
			{
				j++;
			}
			int tmp_num;
			tmp_num = int(str[j++] - 48);
			if (tmp_num == right_num[t])
			{
				tmp = "";
				for (int k = 0;k < 2 * tmp_num;k++)		//��ȡÿ��ͬѧ�����Ĵ𰸣����޳��ո�
				{
					tmp += str[j++];
				}
				if (tmp == right_answer[t])
				{
					sum[i] += score[t];
				}
				else
				{
					count[t]++;
				}
			}
			else
			{
				count[t]++;
				while (str[j] != ')')				//�ص�������ط������û��whileѭ����ʣ�����Щû�õ��ַ��Ե��Ļ��������ȫ�����ˡ�
				{
					j++;
				}
			}
		}
	}

	for (int i = 0;i < N;i++)
	{
		cout << sum[i] << endl;
	}

	int max = 0;
	for (int i = 0;i < M;i++)
	{

		if (count[max] < count[i])
		{
			max = i;
		}
	}
	if (count[max] == 0)
	{
		cout << "Too simple" << endl;
		return 0;
	}
	else
	{
		cout << count[max];
		for (int i = 0;i < M;i++)
		{
			if (count[max] == count[i])
			{
				cout <<" "<< i + 1;
			}
		}
	}
	getchar();
	getchar();
    return 0;
}
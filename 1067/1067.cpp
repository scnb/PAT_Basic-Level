// 1067.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚ�������ʵ�ֱȽϼ�
//ע���ڶ�ȡ�û���������ʱ��Ҫʹ��geline(cin,tmp)����Ϊ���ܱ�֤�û��������в������ո�tab��

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	string right_answer;
	cin >> right_answer >> N;
	string tmp;
	vector<string> attempt;
	getchar();
	getline(cin, tmp);
	while (tmp != "#")
	{
		attempt.push_back(tmp);
		getline(cin, tmp);
	}
	int count = 0;									//��¼�������
	for (int i = 0;i < attempt.size();i++)
	{
		if (count < N)
		{
			if (right_answer == attempt[i])
			{
				cout << "Welcome in" << endl;
				break;
			}
			else
			{
				cout << "Wrong password: " << attempt[i] << endl;
				count++;
				if (count == N)
				{
					cout << "Account locked" << endl;
					break;
				}
			}
		}
	}
	getchar();
	getchar();
    return 0;
}
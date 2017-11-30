// 1055.cpp : �������̨Ӧ�ó������ڵ㡣
//����⻹���ԣ�˼·��Ҫ�ú���һ�롣��Ҫ�Ǹ����һ�¼��㣺
/*
	��ÿ�� m = [N/K]���ˣ�����ȡ������c++����intǿ������ת���Զ�����ȡ����
	�����һ���� N-m*(K-1)����
	��ǰK-1�ŵ�������ͬ����Ϊm
	�ܴӺ���ǰ��һ�ű�һ�ŵ�
	��ÿһ�ţ���ߵ�վ�м� [m/2]+1 (����ȡ����ʵ���ڳ����в�û���õ�
	���ڶ�������Χ������ߵ��ˣ�������ҽ����ɶ�
	���������ͬ���������������У�������Ҫ�ڽṹ�����ض���С�ںţ��Ȱ���߱ȼۣ��ٰ����ֱȽ�

	��m�������������ֵ�����˳��Ϊ�ڣ�m/2+1��λ����1��ʼ����������һ�������ֵ��������m-2���������²�������2
	��m��ż���������ֵ�����˳��Ϊ�ڣ�m/2+1��λ����1��ʼ����������һ�������ֵ��������m-1���������²�������2
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct Student
{
	string name;
	int height;
	bool operator < (const struct Student & A)
	{
		if (this->height != A.height)
		{
			return this->height > A.height;
		}
		else
		{
			return this->name < A.name;
		}
	}
};

int main()
{
	int N, K;
	cin >> N >> K;
	int m = int(N / K);						//����ÿ��Ӧ���ж����ˣ�����ȡ��
	int last_m = N - m*(K - 1);				//�������һ��Ӧ���ж�����
	vector<struct Student> student;
	struct Student tmp;
	//freopen("input.txt", "r", stdin);	
	for (int i = 0;i < N;i++)
	{
		cin >> tmp.name >> tmp.height;
		student.push_back(tmp);
	}
	sort(student.begin(), student.end());
	//��m�������������ֵ�����˳��Ϊ�ڣ�m/2+1��λ����1��ʼ����������һ�������ֵ��������m-2���������²�������2
	//��m��ż���������ֵ�����˳��Ϊ�ڣ�m/2+1��λ����1��ʼ����������һ�������ֵ��������m-1���������²�������2
	int i = 0;									//��Ϊ��ǰ�ŵ����ֵ
	if (last_m % 2 == 0)						//�����һ����ż������
	{
		int j = 0;
		int first = last_m - 1;
		for (j = first;j >= i;j -= 2)
		{
			cout << student[j].name << " ";
		}
		for (j = i;j < i + last_m;j += 2)		//�ĳ�i+last_m��Ϊ�˺ͺ������ǰK-1�ŵĳ����Ӧ����
		{
			if (j != i + last_m - 2)
			{
				cout << student[j].name << " ";
			}
			else
			{
				cout << student[j].name << endl;
			}
		}
		i = last_m;								//������һ�ŵ����ֵ
	}
	else										//�����һ������������
	{
		int j = 0;
		int first = last_m - 2;
		for (j = first;j >= i;j -= 2)
		{
			cout << student[j].name << " ";
		}
		for (j = i;j < i + last_m;j += 2)
		{
			if (j != i + last_m - 1)
			{
				cout << student[j].name << " ";
			}
			else
			{
				cout << student[j].name << endl;
			}
		}
		i = last_m;
	}
	//����ǰK-1�ţ�ÿ��m���ˣ���ÿm����һ��
	if (m % 2 != 0)								//��ǰK-1��ÿ������������
	{
		while (i < N)
		{
			int j;								//i�ǵ�ǰ�ŵ���ߵ��ˣ���j�ĳ�ֵ��ֵΪi
			int rel = m - 2;					//���嵱ǰ�ŵ�һ����������������ߵ��˵�����ƫ����
			for (j = i + rel;j >= i;j -= 2)
			{
				cout << student[j].name << " ";
			}
			for (j = i;j < i + m;j += 2)
			{
				if (j != i + m - 1)				//������������i+m-1
				{
					cout << student[j].name << " ";
				}
				else
				{
					cout << student[j].name << endl;
				}
			}
			i = i + m;
		}
	}
	else										//��ǰK-1��ÿ����ż������
	{
		while (i < N)
		{
			int j;								//i�ǵ�ǰ�ŵ���ߵ��ˣ���j�ĳ�ֵ��ֵΪi
			int rel = m - 1;					//���嵱ǰ�ŵ�һ����������������ߵ��˵�����ƫ����
			for (j = i + rel;j >= i;j -= 2)
			{
				cout << student[j].name << " ";
			}
			for (j = i;j < i + m;j += 2)
			{
				if (j != i + m - 2)				//����ż������i+m-2
				{
					cout << student[j].name << " ";
				}
				else
				{
					cout << student[j].name << endl;
				}
			}
			i = i + m;
		}
	}
	return 0;
}
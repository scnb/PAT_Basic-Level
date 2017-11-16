// 1028.cpp : �������̨Ӧ�ó������ڵ㡣
//˼·�Ƚ���������Ҫ�ǰѷ�������������
/*
	�������������Ƿ����������������У�
	�����<1814
	�����==1814���������<9 �� �·ݵ���9 ������<6
	�����>2014
	�����==2014�������·�>9 �� �·ݵ���9 ������>6

	Ȼ���ж����յĴ�С��
	�����ж����������ˣ�
	���ж�����ǲ�����С�������ǣ��������ж��·ݡ����ڡ�

	�������յ÷�19�֣���һ�����Ե������˶δ���
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	getchar();
	vector<string>birth;
	for (int i = 0;i < N;i++)
	{
		birth.push_back("");
	}
	int count = 0;					//��¼�����������
	for (int i = 0;i < N;i++)
	{
		getline(cin, birth[i]);
	}
	vector<int>year;
	vector<int>month;
	vector<int>day;
	vector<string>name;

	for (int i = 0;i < N;i++)
	{
		int y = 0, m = 0, d = 0;
		int j = 0;
		string tmp = "";
		while (birth[i][j] != ' ')
		{
			tmp += birth[i][j];
			j++;
		}
		j++;	//����jָ����ݵĵ�һ������
		y += (birth[i][j++] - '0') * 1000;
		y += (birth[i][j++] - '0') * 100;
		y += (birth[i][j++] - '0') * 10;
		y += (birth[i][j++] - '0') * 1;
		j++;	//����jָ���·ݵĵ�һ������
		m += (birth[i][j++] - '0') * 10;
		m += (birth[i][j++] - '0') * 1;
		j++;	//����jָ�����ڵĵ�һ������
		d += (birth[i][j++] - '0') * 10;
		d += (birth[i][j++] - '0') * 1;
		if (y < 1814)
		{
			continue;
		}
		else if (y == 1814 && (m < 9 || (m == 9 && d < 6)))
		{
			continue;
		}
		else if (y > 2014)
		{
			continue;
		}
		else if (y == 2014 && (m > 9 || (m == 9 && d > 6)))
		{
			continue;
		}
		else
		{
			count++;
			year.push_back(y);
			month.push_back(m);
			day.push_back(d);
			name.push_back(tmp);
		}
	}
	int max = 0, min = 0;			//�ֱ��¼����������С֮�˵�����
	for (int i = 0;i < count;i++)
	{
		if (year[max] > year[i])
		{
			max = i;
		}
		else if (year[max] == year[i] && (month[max] > month[i] || (month[max] == month[i] && day[max] > day[i])))
		{
			max = i;
		}
		if (year[min] < year[i])
		{
			min = i;
		}
		else if (year[min] == year[i] && (month[min] < month[i] || (month[min] == month[i] && day[min] < day[i])))
		{
			min = i;
		}
	}
	cout << count << " " << name[max] << " " << name[min] << endl;
	getchar();
	getchar();
    return 0;
}


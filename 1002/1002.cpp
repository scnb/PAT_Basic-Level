// 1002.cpp : �������̨Ӧ�ó������ڵ㡣
//��ʵ����̫���ˣ�һ��ʼ�����n�Ƕ����long�͵ģ����������϶�����һ�������ƣ�������Ŀ��˵n�����ֵ�������10��100�η�������
//��Ҫ�Ƕ�����������Ҳ�����׼����������ֱ�ӱ�ʾ��ô�������
//��ʱ������Ҫ�ú��������˸�������10��100�η���Ŀ�ģ���������һ���ַ�����������ʾ��ô�����������10��100�η������ֻ��Ҫһ������100��Ԫ�ص��ַ������顣


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char n[100] = { 0 };
	vector<int> a;
	cin >> n;
	int sum = 0;
	int tmp = 0;
	for (int i = 0;n[i] != 0;i++)
	{
		sum += int(n[i]) - 48;
	}
	
	tmp = 0;
	while (sum > 0)
	{
		tmp = sum % 10;
		a.push_back(tmp);
		sum = (sum - tmp) / 10;
	}
	reverse(a.begin(), a.end());
	for (int i = 0;i < a.size();i++)
	{
		if (i != (a.size() - 1))
		{
			switch (a[i])
			{
			case 0:cout << "ling ";break;
			case 1:cout << "yi ";break;
			case 2:cout << "er ";break;
			case 3:cout << "san ";break;
			case 4:cout << "si ";break;
			case 5:cout << "wu ";break;
			case 6:cout << "liu ";break;
			case 7:cout << "qi ";break;
			case 8:cout << "ba ";break;
			case 9:cout << "jiu ";break;
			}
		}
		else
		{
			switch (a[i])
			{
			case 0:cout << "ling";break;
			case 1:cout << "yi";break;
			case 2:cout << "er";break;
			case 3:cout << "san";break;
			case 4:cout << "si";break;
			case 5:cout << "wu";break;
			case 6:cout << "liu";break;
			case 7:cout << "qi";break;
			case 8:cout << "ba";break;
			case 9:cout << "jiu";break;
			}
		}
	}
	getchar();
	getchar();
    return 0;
}


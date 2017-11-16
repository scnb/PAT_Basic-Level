// 1014.cpp : �������̨Ӧ�ó������ڵ㡣
//�����������⣺һ�������Ŀ����˼������Ҫ����ж��������ڶ���������Ҫ�ģ�
/*
	��Ŀ����˼���Ƚ����ַ����еڼ�����ͬ���ַ���ע���ǵڼ��ԣ�Ҳ����˵�����ͬ���ַ��������ַ���������ͬһλ�õģ�
	�ж������������ڣ���дӢ����ĸ����A��G����������һ��������
			  ��Сʱ����ͬ���ַ�����0��9���A��N
			  �۷��ӣ���һ����ͬ��Ӣ����ĸ���ڵ�λ�ã���A��Z���a��z
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string s[4];
	for (int i = 0;i < 4;i++)
	{
		cin >> s[i];
	}

	char Day;
	char Hour;
	int Min;
	int len1 = s[0].length();
	int len2 = s[1].length();
	int len;
	if (len1 < len2)
	{
		len = len1;
	}
	else
	{
		len = len2;
	}
	int i;
	for (i = 0;i < len;i++)
	{
		if (s[0][i] == s[1][i] && (s[0][i] >= 'A' && s[0][i] <= 'G'))
		{
			Day = s[0][i];
			break;
		}
	}
	for (int j = i + 1;j < len;j++)
	{
		if (s[0][j] == s[1][j] && ((s[0][j] >= 'A' && s[0][j] <= 'N') || (s[0][j] >= '0' && s[0][j] <= '9')))
		{
			Hour = s[0][j];
			break;
		}
	}
	int len3 = s[2].length();
	int len4 = s[3].length();
	if (len3 < len4)
	{
		len = len3;
	}
	else
	{
		len = len4;
	}
	for (int i = 0;i < len;i++)
	{
		if ((s[2][i] == s[3][i]) && ((s[2][i] >= 'A' &&s[2][i] <= 'Z') ||(s[2][i]>='a' && s[2][i]<='z')))
		{
			Min = i;
			break;
		}
	}
	switch (Day)
	{
	case 'A':cout << "MON ";break;
	case 'B':cout << "TUE ";break;
	case 'C':cout << "WED ";break;
	case 'D':cout << "THU ";break;
	case 'E':cout << "FRI ";break;
	case 'F':cout << "SAT ";break;
	case 'G':cout << "SUN ";break;
	}

	if (Hour >= '0' && Hour <= '9')
	{
		cout << setw(2) << setfill('0') << Hour << ":";
	}
	else
	{
		cout << Hour - 'A' + 10 << ":";
	}


	cout << setw(2) << setfill('0') << Min;

	getchar();
	getchar();
    return 0;
}


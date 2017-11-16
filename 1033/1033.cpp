// 1033.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string first;
	string second;
	cin >> first >> second;
	vector<char>bad_num;		//��Ż��������ּ�
	vector<char>bad_char;		//��Ż�������ĸ�����Դ�д������
	vector<char>bad_sign;		//��Ż����ķ��ż������� ���ţ����. ����-��
	int flag_space = 0;			//��ǿո���Ƿ񻵵���1��ʾ����0��ʾ�ã�
	int flag_capital = 0;		//����ϵ����Ƿ񻵵���1��ʾ����0��ʾ�ã�����������򲻴��ڴ�д��ĸ
	for (int i = 0;i < first.length();i++)
	{
		if (first[i] == '_')
		{
			flag_space = 1;
		}
		else if (first[i] == '+')
		{
			flag_capital = 1;
		}
		else if (first[i] == ',' || first[i] == '.' || first[i] == '-')
		{
			bad_sign.push_back(first[i]);
		}
		else if (first[i] >= '0' && first[i] <= '9')
		{
			bad_num.push_back(first[i]);
		}
		else if (first[i] >= 'A' && first[i] <= 'Z')			//Ӣ����ĸ�Ļ����Դ�д��ĸ����
		{
			bad_char.push_back(first[i]);
		}
	}


	if (flag_capital == 0)									//�����������д�ַ�
	{
		for (int i = 0;i < second.length();i++)
		{
			int flag = 0;									//�Ƿ������������ı��
			//�����Сд��ĸ
			if (second[i] >= 'a' && second[i] <= 'z')
			{
				char tmp = second[i] - 32;					//��Сд��ĸת���ɴ�д��ĸ
				for (int j = 0;j < bad_char.size();j++)
				{
					if (bad_char[i] == tmp)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cout << second[i];
					continue;
				}
			}
			//����Ǵ�д��ĸ
			else if (second[i] >= 'A' && second[i] <= 'Z')
			{
				for (int j = 0;j < bad_char.size();j++)
				{
					if (bad_char[j] == second[i])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cout << second[i];
					continue;
				}
			}
			//���������
			else if (second[i] >= '0' && second[i] <= '9')
			{
				for (int j = 0;j < bad_num.size();j++)
				{
					if (bad_num[j] == second[i])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cout << second[i];
					continue;
				}
			}
			//����Ƿ���
			else if (second[i] == ',' || second[i] == '.' || second[i] == '-')
			{
				for (int j = 0;j < bad_sign.size();j++)
				{
					if (second[i] == bad_sign[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cout << second[i];
					continue;
				}
			}
			//������»���
			else if (second[i] == '_')
			{
				if (flag_space == 0)
				{
					cout << second[i];
					continue;
				}
			}
		}
	}
	else if(flag_capital == 1)					//�������������д�ַ�
	{
		for (int i = 0;i < second.length();i++)
		{
			int flag = 0;						//�Ƿ������������ı��
			//�����Сд��ĸ
			if (second[i] >= 'a' && second[i] <= 'z')
			{
				char tmp = second[i] - 32;		//��Сд��ĸת���ɴ�д��ĸ
				for (int j = 0;j < bad_char.size();j++)
				{
					if (bad_char[j] == tmp)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cout << second[i];
					continue;
				}
			}
			//����Ǵ�д��ĸ
			else if (second[i] >= 'A' && second[i] <= 'Z')
			{
				continue;
			}
			//���������
			else if (second[i] >= '0' && second[i] <= '9')
			{
				for (int j = 0;j < bad_num.size();j++)
				{
					if (bad_num[j] == second[i])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cout << second[i];
					continue;
				}
			}
			//����Ƿ���
			else if (second[i] == ',' || second[i] == '.' || second[i] == '-')
			{
				for (int j = 0;j < bad_sign.size();j++)
				{
					if (second[i] == bad_sign[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cout << second[i];
					continue;
				}
			}
			//������»���
			else if (second[i] == '_')
			{
				if (flag_space == 0)
				{
					cout << second[i];
					continue;
				}
			}
		}
	}
	cout << endl;
	getchar();
	getchar();
    return 0;
}
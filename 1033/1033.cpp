// 1033.cpp : 定义控制台应用程序的入口点。
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
	vector<char>bad_num;		//存放坏掉的数字键
	vector<char>bad_char;		//存放坏掉的字母键（以大写给出）
	vector<char>bad_sign;		//存放坏掉的符号键（包括 逗号，点号. 横线-）
	int flag_space = 0;			//标记空格键是否坏掉（1表示坏，0表示好）
	int flag_capital = 0;		//标记上档键是否坏掉（1表示坏，0表示好）如果坏掉，则不存在大写字母
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
		else if (first[i] >= 'A' && first[i] <= 'Z')			//英文字母的坏键以大写字母给出
		{
			bad_char.push_back(first[i]);
		}
	}


	if (flag_capital == 0)									//即可以输出大写字符
	{
		for (int i = 0;i < second.length();i++)
		{
			int flag = 0;									//是否可以正常输出的标记
			//如果是小写字母
			if (second[i] >= 'a' && second[i] <= 'z')
			{
				char tmp = second[i] - 32;					//将小写字母转换成大写字母
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
			//如果是大写字母
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
			//如果是数字
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
			//如果是符号
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
			//如果是下划线
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
	else if(flag_capital == 1)					//即不可以输出大写字符
	{
		for (int i = 0;i < second.length();i++)
		{
			int flag = 0;						//是否可以正常输出的标记
			//如果是小写字母
			if (second[i] >= 'a' && second[i] <= 'z')
			{
				char tmp = second[i] - 32;		//将小写字母转换成大写字母
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
			//如果是大写字母
			else if (second[i] >= 'A' && second[i] <= 'Z')
			{
				continue;
			}
			//如果是数字
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
			//如果是符号
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
			//如果是下划线
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
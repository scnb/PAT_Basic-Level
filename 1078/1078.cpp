// 1078.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
using namespace std;


int main()
{
	string choice;
	cin >> choice;
	string output;
	string str;
	freopen("input1.txt", "r", stdin);
	//getchar();
	getline(cin, str);
	if (choice == "C") //ѹ�� 
	{
		char tmp;
		int i = 0;
		int len = str.length();
		while (i<len)
		{
			int count = 0;
			tmp = str[i];
			while (str[i] == tmp)
			{
				i++;
				count++;
			}
			if (count>1 && count <10)
			{
				output += (count + '0');
				output += tmp;
			}
			else if (count >= 10)
			{
				string tmp_str = "";
				while (count > 0)
				{
					tmp_str = char(count % 10 + '0') + tmp_str;
					count = count / 10;
				}
				output += tmp_str;
				output += tmp;
			}
			else
			{
				output += tmp;
			}
		}
		cout << output << endl;
	}
	else if (choice == "D")
	{
		int tmp_count;
		int i = 0;
		char tmp;
		int len = str.length();
		while (i<len)
		{
			tmp_count = str[i] - 48;
			if (tmp_count >= 0 && tmp_count <= 9)
			{
				i++;
				while ((str[i] - 48) >= 0 && (str[i] - 48) <= 9)
				{
					tmp_count = tmp_count * 10 + (str[i] - 48);
					i++;
				}

				tmp = str[i];
				for (int j = 0;j<tmp_count - 1;j++)
				{
					cout << tmp;
				}
				tmp_count = 0;
			}
			else
			{
				cout << str[i];
				i++;
			}
		}
	}
	return 0;
}
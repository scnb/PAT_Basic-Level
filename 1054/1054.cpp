// 1054.cpp : 定义控制台应用程序的入口点。
//用二叉树来考虑分类，这样思考的话会比较清晰一些
//最后得分17分，还需要再改进

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int N;
	float sum = 0;
	cin >> N;
	int flag = 0;
	int i, j;
	int pos = 0;
	int count = 0;
	int count_right = 0;
	int negative = 0;
	for (i = 0;i < N;i++)
	{
		count = 0;
		pos = 0;
		flag = 0;
		negative = 0;
		string tmp = "";
		cin >> tmp;
		for (j = 0;j < tmp.length();j++)
		{
			if ((tmp[j] >= '0' && tmp[j] <= '9') || tmp[j]=='.' || tmp[j]=='-')
			{
				if (tmp[j] == '.')
				{
					pos = j;
					count++;
				}
				if (tmp[j] == '-')
				{
					negative++;
				}
				continue;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			cout << "ERROR: " << tmp << " is not a legal number" << endl;
			continue;
		}
		else if (negative > 1)
		{
			cout << "ERROR: " << tmp << " is not a legal number" << endl;
		}
		else if (negative == 1 && tmp[0]!='-')
		{
			cout << "ERROR: " << tmp << " is not a legal number" << endl;
		}
		else
		{
			if (count > 1)
			{
				cout << "ERROR: " << tmp << " is not a legal number" << endl;
			}
			else if(count==1)
			{
				if (tmp.length() - 1 - pos <= 2)
				{
					float num = stof(tmp);
					if (num >= -1000.0 && num <= 1000.0)
					{
						sum += num;
						count_right++;
					}
				}
				else
				{
					cout << "ERROR: " << tmp << " is not a legal number" << endl;
				}
			}
			else
			{
				float num = stof(tmp);
				if (num >= -1000.0 && num <= 1000.0)
				{
					sum += num;
					count_right++;
				}
				else
				{
					cout << "ERROR: " << tmp << " is not a legal number" << endl;
				}
			}
		}
	}

	if (count_right > 0)
	{
		if (count_right == 1)
		{
			cout << "The average of 1 number is " <<setiosflags(ios::fixed)<<setprecision(2)<< sum << endl;
		}
		else
		{
			cout << "The average of " << count_right << " numbers is " << setiosflags(ios::fixed) << setprecision(2) << sum / count_right << endl;
		}
	}
	else
	{
		cout << "The average of " << count_right << " numbers is Undefined" << endl;
	}
	getchar();
	getchar();
    return 0;
}


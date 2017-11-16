// 1002.cpp : 定义控制台应用程序的入口点。
//我实在是太蠢了，一开始输入的n是定义成long型的，但是这样肯定会用一定的限制，而且题目中说n的最大值不会大于10的100次方，但是
//我要是动动脑子想象也能明白计算机不可能直接表示那么大的数。
//这时，我们要好好理解出题人告诉我们10的100次方的目的，即可以用一个字符串数组来表示这么大的数！！！10的100次方，最多只需要一个包含100个元素的字符串数组。


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


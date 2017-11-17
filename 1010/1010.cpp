// 1010.cpp : 定义控制台应用程序的入口点。
//这道题其实不是很难的，但是疏忽了两点：
/*
	①在接收输入时，因为是不确定个数的，所以不能用固定的循环，我开始没有找到合适的判断输入已经结束的方法。在看了某个的博客之后，
	  才意识到企图用cin>>tmp来接收\n判断输入结束是不可能的，因为tmp是int型的。正确的方法是用getchar()来接收下一个字符看是不是\n
	  来判断是否输入结束
	②没有正确理解题目中特别说明的零多项式的意思，因为我看在输入和输出格式的说明中都明确强调了都是非零多项式。事实上，当输入是
	  一个常数时，那么输出就会是0 0
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> orgin;
	vector<int> after;
	int tmp;
	while (1)
	{
		cin >> tmp;
		orgin.push_back(tmp);
		if (getchar() == '\n')
		{
			break;
		}
	}
	if (orgin.size() == 2 && orgin[1] == 0)
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	for (int i = 0;i < orgin.size();i+=2)
	{
		if (orgin[i + 1] != 0)
		{
			after.push_back(orgin[i] * orgin[i + 1]);
			after.push_back(orgin[i + 1] - 1);
		}
		else
		{
			break;
		}
	}
	if (after.size() != 0)
	{
		cout << after[0];
		for (int i = 1;i < after.size();i++)
		{
			cout << " " << after[i];
		}
	}
	system("pause");
    return 0;
}
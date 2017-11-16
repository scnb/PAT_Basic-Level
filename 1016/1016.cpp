// 1016.cpp : 定义控制台应用程序的入口点。
//这道貌似很简单的题暴露了我很多的问题：
/*
	①对字符串数组的知识点有很多都遗忘了，因为要求的输入是不大于10的10次方，这个值是很大的，因此考虑把数字当成字符串输入并保存在字符串数组中
	②虽然把大的数字存进了字符串数组里，但是它其实是以ASCII码的形式存的，因此不能取出来就用，需用强制转换为int并减去-48
	③for循环当中的结束条件：A[i]!=0，这里的0是整数的0，而不是ASCII的0。因为直接取A[i]其实是char类型的，而我们一开始将A数组都复制为了整数0。
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char A[10] = { 0 };
	char B[10] = { 0 };
	int Da = 0, Db = 0;
	int Pa=0, Pb=0;
	int base = 1;
	cin >> A >> Da >> B >> Db;
	for (int i = 0;A[i] != 0;i++)
	{
		if (int(A[i])-48 == Da)
		{
			Pa += base*Da;
			base *= 10;
		}
	}
	base = 1;
	for (int i = 0;B[i] != 0;i++)
	{
		if (int(B[i])-48 == Db)
		{
			Pb += base*Db;
			base *= 10;
		}
	}
	cout << Pa + Pb << endl;
	getchar();
	getchar();
    return 0;
}


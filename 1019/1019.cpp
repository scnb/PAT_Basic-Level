// 1019.cpp : 定义控制台应用程序的入口点。
//这道题思路比较清晰，主要是要选择合适的容器 (逃 
//本题选择用整形N接收输入，然后将给位拆解存在vector中，因为vector可以使用自己的和algorithm中的逆转和排序函数，比较方便
//然后，不断的循环，知道计算出的差值等于6174后break跳出while循环。期间主要的工作就是把字符串转成整形相减，输出，判断是否该break，然后或者break，或者再把整形转成字符串，再执行循环。

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<char>a;
	vector<char>b;
	cin >> N;
	if (N % 1111 == 0)
	{
		cout << N <<" - " << N << " = " << "0000" << endl;
		getchar();
		getchar();
		return 0;
	}
	a.push_back(N / 1000);
	a.push_back(N % 1000 / 100);
	a.push_back(N % 100 / 10);
	a.push_back(N % 10);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i = 0;i < 4;i++)
	{
		b.push_back(a[3 - i]);
	}
	int A, B;
	while (1)
	{
		A = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] * 1;
		B = b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3] * 1;
		N = A - B;
		cout << setw(4) << setfill('0') << A << " - "<< setw(4) << setfill('0') << B << " = " << setw(4) << setfill('0') << N <<endl;
		if (N == 6174)
		{
			break;
		}
		else
		{
			a[0] = (N / 1000);
			a[1] = (N % 1000 / 100);
			a[2] = (N % 100 / 10);
			a[3] = (N % 10);
			sort(a.begin(), a.end());
			reverse(a.begin(), a.end());
			for (int i = 0;i < 4;i++)
			{
				b[i] = (a[3 - i]);
			}
		}
	}
	getchar();
	getchar();
    return 0;
}


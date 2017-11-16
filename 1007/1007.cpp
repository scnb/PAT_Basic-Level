// 1007.cpp : 定义控制台应用程序的入口点。
//这道题暴露了我的一个知识漏洞：即快速判断一个数是不是质数
/*
	①大家都知道对于一个数N从2到N-1不停循环来判断是最蠢的一种方法
	②快速判断的方法：我原来记错了，即把第23行写成了k<=i/2，这种办法还远远不是最快速的方法，最快速的方法应该是k<=sqrt(i)
	  因为一个数能分解成两个相等的数相乘，那么对于任一个数进行判断即可判断N是否是质数。
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *tmp = new int[N];
	int j = 0;
	int count = 0;
	int flag = 0;
	tmp[j++] = 2;
	for (int i = 3;i <= N;i++)
	{
		for (int k = 2;k <= sqrt(i);k++)
		{
			if (i%k == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			tmp[j] = i;
			if (tmp[j] - tmp[j - 1] == 2)
			{
				count++;
			}
			j++;
		}
		flag = 0;
	}

	//for (int i = 0;i < j-1;i++)
	//{
	//	if (tmp[i + 1] - tmp[i] == 2)
	//	{
	//		count++;
	//	}
	//}
	cout << count << endl;
	delete[] tmp;
	getchar();
	getchar();
    return 0;
}
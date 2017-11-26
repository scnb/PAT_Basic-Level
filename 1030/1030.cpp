// 1030.cpp : 定义控制台应用程序的入口点。
//这道题中等难度，但是实现比较简单
//最终得分22分，还差3分
//最后，采用了另外的一种方法，这种方法就是每次固定一个最小值（从数组第一个元素开始，每次循环最小值取到后一个元素）,然后寻找符合完美数列
//的最大值，并且记下中间有多少个元素(count)，并用这个count值更新下一次的最大值起始位置。

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, P;
	cin >> N >> P;
	vector<long> num;
	long tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	int count = 1;
	int i, j;
	for (i = 0;i < N;i++)
	{
		for (j = i + count;j < N;j++)
		{
			if (num[j] <= num[i] * P)
			{
				count = j - i + 1;
			}
			else
			{
				break;
			}
		}
	}
	cout << count << endl;
    return 0;
}

/*原来的做法，得分22分，还差3分，目前没有找出BUG*/

//int count1 = 0;										//正向循环记录最多完美数列中有几个元素
//int count2 = 0;										//反向循环~~~
//long M = num[N - 1];								//M是最大值
//for (int i = 0;i < num.size();i++)
//{
//	if (M <= num[i] * P)
//	{
//		count1 = num.size() - i;
//		break;
//	}
//}
//long m = num[0];									//m是最小值
//for (int i = num.size() - 1;i >= 0;i--)
//{
//	if (num[i] <= m*P)
//	{
//		count2 = i + 1;
//		break;
//	}
//}
//int count = 0;
//if (count1 >= count2)
//{
//	count = count1;
//}
//else
//{
//	count = count2;
//}
//cout << count << endl;
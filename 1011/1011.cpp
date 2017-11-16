// 1011.cpp : 定义控制台应用程序的入口点。
//这道题乍一看非常简单，但是很容易就直接把A、B、C的数字定义成int型的，这样就犯了大错，因为可能A和B相加的结果会超过int变量的范围。
//所以要把它们定义成long型的。
//另外，这道题的格式也需要注意，是先输入一行T表示一共有多少组，然后一行一行的接收输入，输入完后，再一行一行的输出。

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;		//测试用例的个数
	long *A = new long[T];
	long *B = new long[T];
	long *C = new long[T];
	

	for (int i = 0;i < T;i++)
	{
		scanf_s("%ld %ld %ld", &A[i], &B[i], &C[i]);
		
	}
	for (int i = 0;i < T;i++)
	{
		if (A[i] + B[i] > C[i])
		{
			cout << "Case #" << i+1 << ": true" << endl;
		}
		else
		{
			cout << "Case #" << i+1 << ": false" << endl;
		}
	}
	delete[] A, B, C;
	getchar();
	getchar();
    return 0;
}


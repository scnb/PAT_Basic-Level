// 1011.cpp : �������̨Ӧ�ó������ڵ㡣
//�����էһ���ǳ��򵥣����Ǻ����׾�ֱ�Ӱ�A��B��C�����ֶ����int�͵ģ������ͷ��˴����Ϊ����A��B��ӵĽ���ᳬ��int�����ķ�Χ��
//����Ҫ�����Ƕ����long�͵ġ�
//���⣬�����ĸ�ʽҲ��Ҫע�⣬��������һ��T��ʾһ���ж����飬Ȼ��һ��һ�еĽ������룬���������һ��һ�е������

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;		//���������ĸ���
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


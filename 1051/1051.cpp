// 1051.cpp : �������̨Ӧ�ó������ڵ㡣
//���������ѧ�Ϻ�������⣬����������ϴ���һЩ�ӡ�
/*
	��Ϊ�ǽ�ȡС������λ��������Ի�����������룬�����A����(-0.005��0]֮��Ļ����ͻᱻʡ�Գ�-0.00��ע����ȻС����λ����ȷ������
	ȴ����һ�����ţ�����Ҫ�Ѵ���(-0.005,0]֮�����������ó���������
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	double R1, P1, R2, P2;
	cin >> R1 >> P1 >> R2 >> P2;
	double A, B;
	A = R1*R2*cos(P1 + P2);
	B = R1*R2*sin(P1 + P2);
	if (A > -0.005 && A <= 0)
	{
		cout << "0.00";
		if (B <= 0 && B>-0.005)
		{
			cout << "+0.00i" << endl;
		}
		else if (B >= 0)
		{
			cout<<"+" << setiosflags(ios::fixed) << setprecision(2) << B << "i" << endl;
		}
		else
		{
			B = fabs(B);
			cout << "-" << setiosflags(ios::fixed) << setprecision(2) << B << "i" << endl;
		}
	}
	else
	{
		cout << setiosflags(ios::fixed)<<setprecision(2)<<A;
		if (B <= 0 && B>-0.005)
		{
			cout << "+0.00i" << endl;
		}
		else if (B >= 0)
		{
			cout << "+" << setiosflags(ios::fixed) << setprecision(2) << B << "i" << endl;
		}
		else
		{
			B = fabs(B);
			cout << "-" << setiosflags(ios::fixed) << setprecision(2) << B << "i" << endl;
		}
	}
	
	getchar();
	getchar();
	return 0;
}


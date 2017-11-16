// 1051.cpp : 定义控制台应用程序的入口点。
//这道题在数学上很容易理解，但是在输出上存在一些坑。
/*
	因为是截取小数点两位输出，所以会进行四舍五入，而如果A处于(-0.005，0]之间的话，就会被省略成-0.00，注意虽然小数点位数正确，但是
	却多了一个负号，所以要把处于(-0.005,0]之间的情况单独拿出来分析。
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


// 1026.cpp : 定义控制台应用程序的入口点。
//这道题不难，但是有两个点要注意一下，
/*
	①：计算N时要强制转换成double，防止把小数点弄丢，小数点对于最后的秒数有着至关重要的作用
	②：在输出时要求时分秒都是两位数，所以可能需要在前面补0，这时就用到了iomanip中的setw和setfill函数，一个用来设置输出位宽，一个用来
		决定前面应该补什么字符
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int C1, C2;
	cin >> C1 >> C2;
	int diff = C2 - C1;
	double N = (double)diff / 100;		//记录总的秒数
	int H = N / 3600;
	int M = (N - H * 3600) / 60;
	int S = ((N - H * 3600 - M * 60)+0.5);
	cout << setw(2)<<setfill('0')<<H << ":" << setw(2) << setfill('0')<< M << ":" << setw(2) << setfill('0')<<S << endl;
	getchar();
	getchar();
    return 0;
}


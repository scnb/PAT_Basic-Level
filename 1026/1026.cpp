// 1026.cpp : �������̨Ӧ�ó������ڵ㡣
//����ⲻ�ѣ�������������Ҫע��һ�£�
/*
	�٣�����NʱҪǿ��ת����double����ֹ��С����Ū����С�������������������������Ҫ������
	�ڣ������ʱҪ��ʱ���붼����λ�������Կ�����Ҫ��ǰ�油0����ʱ���õ���iomanip�е�setw��setfill������һ�������������λ��һ������
		����ǰ��Ӧ�ò�ʲô�ַ�
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
	double N = (double)diff / 100;		//��¼�ܵ�����
	int H = N / 3600;
	int M = (N - H * 3600) / 60;
	int S = ((N - H * 3600 - M * 60)+0.5);
	cout << setw(2)<<setfill('0')<<H << ":" << setw(2) << setfill('0')<< M << ":" << setw(2) << setfill('0')<<S << endl;
	getchar();
	getchar();
    return 0;
}


// 1016.cpp : �������̨Ӧ�ó������ڵ㡣
//���ò�ƺܼ򵥵��Ⱪ¶���Һܶ�����⣺
/*
	�ٶ��ַ��������֪ʶ���кܶ඼�����ˣ���ΪҪ��������ǲ�����10��10�η������ֵ�Ǻܴ�ģ���˿��ǰ����ֵ����ַ������벢�������ַ���������
	����Ȼ�Ѵ�����ִ�����ַ����������������ʵ����ASCII�����ʽ��ģ���˲���ȡ�������ã�����ǿ��ת��Ϊint����ȥ-48
	��forѭ�����еĽ���������A[i]!=0�������0��������0��������ASCII��0����Ϊֱ��ȡA[i]��ʵ��char���͵ģ�������һ��ʼ��A���鶼����Ϊ������0��
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


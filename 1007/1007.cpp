// 1007.cpp : �������̨Ӧ�ó������ڵ㡣
//����Ⱪ¶���ҵ�һ��֪ʶ©�����������ж�һ�����ǲ�������
/*
	�ٴ�Ҷ�֪������һ����N��2��N-1��ͣѭ�����ж��������һ�ַ���
	�ڿ����жϵķ�������ԭ���Ǵ��ˣ����ѵ�23��д����k<=i/2�����ְ취��ԶԶ��������ٵķ���������ٵķ���Ӧ����k<=sqrt(i)
	  ��Ϊһ�����ֽܷ��������ȵ�����ˣ���ô������һ���������жϼ����ж�N�Ƿ���������
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
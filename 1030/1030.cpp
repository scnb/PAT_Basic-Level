// 1030.cpp : �������̨Ӧ�ó������ڵ㡣
//������е��Ѷȣ�����ʵ�ֱȽϼ�
//���յ÷�22�֣�����3��
//��󣬲����������һ�ַ��������ַ�������ÿ�ι̶�һ����Сֵ���������һ��Ԫ�ؿ�ʼ��ÿ��ѭ����Сֵȡ����һ��Ԫ�أ�,Ȼ��Ѱ�ҷ�����������
//�����ֵ�����Ҽ����м��ж��ٸ�Ԫ��(count)���������countֵ������һ�ε����ֵ��ʼλ�á�

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

/*ԭ�����������÷�22�֣�����3�֣�Ŀǰû���ҳ�BUG*/

//int count1 = 0;										//����ѭ����¼��������������м���Ԫ��
//int count2 = 0;										//����ѭ��~~~
//long M = num[N - 1];								//M�����ֵ
//for (int i = 0;i < num.size();i++)
//{
//	if (M <= num[i] * P)
//	{
//		count1 = num.size() - i;
//		break;
//	}
//}
//long m = num[0];									//m����Сֵ
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
// 1032.cpp : �������̨Ӧ�ó������ڵ㡣
//�����˼·�Ƚϼ򵥣�ʵ��Ҳ�Ƚ����ף����ǵ�һ������ڲ���ʱ����һ�����Ե㳬ʱ��
/*
	�������޸��˵�31-��34�У�������forѭ��ת����һ��forѭ����ֱ�Ӵ�0��N-1ѭ������id[i]-1��Ϊsum����������������ֱ�Ӱ�score[i]�ӵ���Ӧ��ѧУ���ˡ�
	�����Ϳ��Խ����ʱ�����⡣
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *id = new int[N];
	int *score = new int[N];
	int max = 0;					//ѧУ������Ķ�Ӧ������
	for (int i = 0;i < N;i++)
	{
		cin >> id[i];
		cin >> score[i];
		if (id[max] < id[i])
		{
			max = i;
		}
	}
	int school = id[max];
	int *sum = new int[school] {0};
	for(int i=0;i<N;i++)
	{
		sum[id[i] - 1] += score[i];
	}
	int max_sum = 0;
	for (int i = 0;i < school;i++)
	{
		if (sum[max_sum] < sum[i])
		{
			max_sum = i;
		}
	}
	cout << max_sum+1 << " " << sum[max_sum] << endl;
	getchar();
	getchar();
    return 0;
}
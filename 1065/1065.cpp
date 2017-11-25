// 1065.cpp : �������̨Ӧ�ó������ڵ㡣
//������е��Ѷȣ���Ҫ��ϸ��һ����ô�ֱ�ȷ��ĳ��������Ǹ�������������ֻ��һ����ȥ�μ��ɶԡ�
//�ص���������ж����Ƿ�һ����ȥ�μ��ɶԡ�

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <stdlib.h>
using namespace std;

int main()
{
	int N, M;
	map<int,int> couple;
	for (int i = 0;i < 100000;i++)
	{
		couple[i] = -1;
	}
	int flag[100000] = { 0 };
	vector<int> visitor;
	vector<int> single;
	vector<int> count;					//��¼�䵥������
	cin >> N;
	int tmp1;
	int tmp2;
	//freopen("input1.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		cin >> tmp1;
		cin >> tmp2;
		couple[tmp1] = tmp2;
		couple[tmp2] = tmp1;
	}
	getchar();
	cin >> M;
//	freopen("input2.txt", "r", stdin);
	for (int i = 0;i < M;i++)
	{
		cin >> tmp1;
		visitor.push_back(tmp1);
	}
	sort(visitor.begin(), visitor.end());
	for (int i = 0;i < M;i++)
	{
		int a = visitor[i];
		flag[a] += 1;
		flag[couple[a]] += 1;
	}
	for (int i = 0;i < M;i++)
	{
		if (couple[visitor[i]] == -1)				//���Ǳ�����ǵ�������
		{
			count.push_back(i);						//��¼�䵥�˵�����
		}
		else if (flag[visitor[i]] != 2)										//���￼�Ǳ������ǵ�������ֻ��һ���˲μӾۻ��
		{
			count.push_back(i);
		}
	}
	int len = count.size();
	cout << len << endl;
	for (int i = 0;i < len;i++)
	{
		if (i != len - 1)
		{
			cout << setw(5) << setfill('0') << visitor[count[i]] << " ";
		}
		else
		{
			cout << setw(5) << setfill('0') << visitor[count[i]] << endl;
		}
	}
    return 0;
}
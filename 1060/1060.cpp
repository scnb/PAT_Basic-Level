// 1060.cpp : �������̨Ӧ�ó������ڵ㡣
//������������Լ�����һ���ϣ����յĵ÷���20�֡������ҵ�ʵ�ֱȽϸ��ӣ���Ҫ���ǱȽ϶��������
//��󣬻��ǲο���һЩ�����Ĵ𰸣��������Ǵ���õ���ͬһ���㷨������·�̽������򣬲������������һ�ж��Ƿ��N-i��
//���������ĳһ��̲�����N-i�����ʾ��һ��N-iΪ����E��

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<int> miles;
	int tmp;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		miles.push_back(tmp);
	}
	sort(miles.begin(),miles.end());
	int E = 0;
	if (miles[0] > N)
	{
		cout << N << endl;
	}
	else
	{
		for (int i = N - 1;i >= 0;i--)
		{
			if (miles[i] <= N - i)
			{
				E = N - i - 1;
				cout << E << endl;
				break;
			}
		}
	}
    return 0;
}
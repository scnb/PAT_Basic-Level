// 1069.cpp : �������̨Ӧ�ó������ڵ㡣
//�����Ƚϼ򵥣�������һ���ط���Ҫ�ر�ע�⣬���ǵ�����һ���Ѿ��񽱵�idʱ�����ܼ򵥵Ľ�i+1����Ӧ��ѭ���ж�ֱ����ǰiָ���idû�еù�����

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	int M, N, S;						//ע�⣬��M��ת��������M������
	cin >> M >> N >> S;
	vector<string>id;
	vector<string>winner;
	map<string, int>count;
	string tmp = "";
	for (int i = 0;i < M;i++)
	{
		cin >> tmp;
		id.push_back(tmp);
		count[tmp] = 0;
	}
	int i = 0;
	for (i = S - 1;i < M;i+=N)
	{
		if (count[id[i]] < 1)
		{
			winner.push_back(id[i]);
			count[id[i]]++;
		}
		else
		{
			while (count[id[i]] >= 1)		//Ӧ�ü���whileѭ��������Ƿ��Ѿ��񽱣������ܼ򵥵�д��i+=1
			{
				i++;
			}
			if (i < M)						//����Ҫ�ж�i+1���Ƿ񳬳�vector�����Ĵ�С
			{
				winner.push_back(id[i]);
				count[id[i]]++;
			}
		}
	}
	if (winner.size() == 0)
	{
		cout << "Keep going..." << endl;
	}
	else
	{
		for (int i = 0;i < winner.size();i++)
		{
			cout << winner[i] << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}
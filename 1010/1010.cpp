// 1010.cpp : �������̨Ӧ�ó������ڵ㡣
//�������ʵ���Ǻ��ѵģ�������������㣺
/*
	���ڽ�������ʱ����Ϊ�ǲ�ȷ�������ģ����Բ����ù̶���ѭ�����ҿ�ʼû���ҵ����ʵ��ж������Ѿ������ķ������ڿ���ĳ���Ĳ���֮��
	  ����ʶ����ͼ��cin>>tmp������\n�ж���������ǲ����ܵģ���Ϊtmp��int�͵ġ���ȷ�ķ�������getchar()��������һ���ַ����ǲ���\n
	  ���ж��Ƿ��������
	��û����ȷ�����Ŀ���ر�˵���������ʽ����˼����Ϊ�ҿ�������������ʽ��˵���ж���ȷǿ���˶��Ƿ������ʽ����ʵ�ϣ���������
	  һ������ʱ����ô����ͻ���0 0
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> orgin;
	vector<int> after;
	int tmp;
	while (1)
	{
		cin >> tmp;
		orgin.push_back(tmp);
		if (getchar() == '\n')
		{
			break;
		}
	}
	if (orgin.size() == 2 && orgin[1] == 0)
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	for (int i = 0;i < orgin.size();i+=2)
	{
		if (orgin[i + 1] != 0)
		{
			after.push_back(orgin[i] * orgin[i + 1]);
			after.push_back(orgin[i + 1] - 1);
		}
		else
		{
			break;
		}
	}
	if (after.size() != 0)
	{
		cout << after[0];
		for (int i = 1;i < after.size();i++)
		{
			cout << " " << after[i];
		}
	}
	system("pause");
    return 0;
}
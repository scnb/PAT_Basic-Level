// 1075.cpp : �������̨Ӧ�ó������ڵ㡣
//22��

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <map>
using namespace std;

struct Node
{
	int address;
	int data;
	int next;
};

int main()
{
	int first, N, K;
	cin >> first >> N >> K;
	map<int, int> order;
	map<int, int> index;
	map<int, int> data;
	vector<Node> node;
	vector<int> negative;		//���渺ֵ������
	vector<int> smaller;		//����С�ڵ���K��ֵ������
	vector<int> greater;		//�������K��ֵ������
	freopen("input.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		Node tmp_node;
		cin >> tmp_node.address >> tmp_node.data >> tmp_node.next;
		order[tmp_node.address] = tmp_node.next;
		index[tmp_node.address] = i;
		data[tmp_node.address] = tmp_node.data;
		node.push_back(tmp_node);
	}
	int current = first;
	for (int i = 0;i < N;i++)
	{
		if (data[current] < 0)
		{
			negative.push_back(index[current]);
		}
		else if (data[current] <= K)
		{
			smaller.push_back(index[current]);
		}
		else if (data[current] > K)
		{
			greater.push_back(index[current]);
		}
		current = order[current];
	}
	int count1 = negative.size();
	int count2 = smaller.size();
	int count3 = greater.size();
	for (int i = 0;i < count1 - 1;i++)
	{
		node[negative[i]].next = node[negative[i + 1]].address;
	}
	if (count1 > 0)//���и���
	{
		if (count2 > 0) //����С�ڵ���K����
		{
			node[negative[count1 - 1]].next = node[smaller[0]].address;
		}
		else if (count3 > 0) //��û��С�ڵ���K���������д���K����
		{
			node[negative[count1 - 1]].next = node[greater[0]].address;
		}
		else
		{
			node[negative[count1 - 1]].next = -1;
		}
	}


	for (int i = 0;i < count2 - 1;i++)
	{
		node[smaller[i]].next = node[smaller[i + 1]].address;
	}
	if (count2 > 0) //����С�ڵ���K����
	{
		if (count3 > 0)
		{
			node[smaller[count2 - 1]].next = node[greater[0]].address;
		}
		else
		{
			node[smaller[count2 - 1]].next = -1;
		}
	}

	for (int i = 0;i < count3 - 1;i++)
	{
		node[greater[i]].next = node[greater[i + 1]].address;
	}
	if (count3 > 0)
	{
		node[greater[count3 - 1]].next = -1;
	}

	for (int i = 0;i < count1 - 1;i++)
	{
		cout << setw(5) << setfill('0') << node[negative[i]].address << " " << node[negative[i]].data << " " << setw(5) << setfill('0') << node[negative[i]].next << endl;
	}
	if (count1 > 0)
	{
		if (count2 > 0)
		{
			cout << setw(5) << setfill('0') << node[negative[count1 - 1]].address << " " << node[negative[count1 - 1]].data << " " << setw(5) << setfill('0') << node[negative[count1 - 1]].next << endl;
		}
		else if (count3 > 0)
		{
			cout << setw(5) << setfill('0') << node[negative[count1 - 1]].address << " " << node[negative[count1 - 1]].data << " " << setw(5) << setfill('0') << node[negative[count1 - 1]].next << endl;
		}
		else
		{
			cout << setw(5) << setfill('0') << node[negative[count1 - 1]].address << " " << node[negative[count1 - 1]].data << " " << node[negative[count1 - 1]].next << endl;
		}
	}
	
	for (int i = 0;i < count2-1;i++)
	{
		cout << setw(5) << setfill('0') << node[smaller[i]].address << " " << node[smaller[i]].data << " " << setw(5) << setfill('0') << node[smaller[i]].next << endl;
	}
	if (count2 > 0)
	{
		if (count3 > 0)
		{
			cout << setw(5) << setfill('0') << node[smaller[count2 - 1]].address << " " << node[smaller[count2 - 1]].data << " " << setw(5) << setfill('0') << node[smaller[count2 - 1]].next << endl;
		}
		else
		{
			cout << setw(5) << setfill('0') << node[smaller[count2 - 1]].address << " " << node[smaller[count2 - 1]].data << " " << node[smaller[count2 - 1]].next << endl;
		}
	}
	
	for (int i = 0;i < count3 - 1;i++)
	{
		cout << setw(5) << setfill('0') << node[greater[i]].address << " " << node[greater[i]].data << " " << setw(5) << setfill('0') << node[greater[i]].next << endl;
	}
	if (count3 > 0)
	{
		cout << setw(5) << setfill('0') << node[greater[count3 - 1]].address << " " << node[greater[count3 - 1]].data << " " << node[greater[count3 - 1]].next << endl;
	}
    return 0;
}
// 1068.cpp : �������̨Ӧ�ó������ڵ㡣
//����������е��Ѷȣ�
/*
	�ѵ�٣�Ҫ��¼ÿ�����س��ֵĴ�������Ϊ����Ҫ�ҵ��Ǹ������Ƕ�һ�޶��ģ���ÿ��������[0,2^24)��ʹ������int count[16777216]�����
			���Ը���map��һSTL���洢
	�ѵ�ڣ�������Щ����ȷ������Ŀ�������У���˵���õ����ɫ������Χ8���������ص���ɫ���ִ�,�������8�����صĻ���ֻ��ɨ��������Ȧ
			Ȼ��ʵ������ʱ������Ҫɨ����������
	�ѵ�ۣ�Ҫɨ�����������Ʊ���ЩԪ����Χֻ��3��Ԫ�أ��Ľǣ�����ЩԪ����Χֻ��5��Ԫ�أ��ıߣ�������ȦԪ����Χ����8��Ԫ��
			��ô��Ҫ���ࡣ��һ����һ��ʼ�õı��취������if�Ը���������з��ࡣ
			�ڲο���ĳ�˵Ĳ��ͺ�http://blog.csdn.net/qq_22194315/article/details/60470130������ѧϰ�����������������ֱ��¼һ��Ԫ����Χ�˸�Ԫ������ڸ�Ԫ�غᡢ�������ϵ�������Ȼ����ѭ�������
			�ټ�һ���ж���ΧԪ�������Ƿ���ȷ�ĺ���(check_coordinate)����������ʵ����ĿҪ��
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <stdlib.h>
using namespace std;
bool check_coordinate(int x, int y, int N, int M);

int dx[8] = { -1,-1,-1,0,0,1,1,1 };				//�е���������һ��Ԫ����Χ�˸�Ԫ������ڸ�Ԫ�غ������ϵ�����
int dy[8] = { -1,0,1,-1,1,-1,0,1 };				//�е���������һ��Ԫ����Χ�˸�Ԫ������ڸ�Ԫ���������ϵ�����

int main()
{
	int N, M, TOL;
	map<int, int>count;							//��map��ʵ�ּ�¼ÿ��Ԫ�صĸ����������������2^24�η���Ԫ�ػ����
	cin >> M >> N >> TOL;
	vector<vector<int>> point;
	int tmp;
	//freopen("inputs.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		vector<int> append;
		for (int j = 0;j < M;j++)
		{
			cin >> tmp;
			count[tmp] = 0;
			append.push_back(tmp);
		}
		point.push_back(append);
	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			count[point[i][j]]++;
		}
	}
	//�ԣ�N-1��*��M-1��������Ԫ�ؽ��б����������Ƿ�Ψһ��������Χ��8��Ԫ��ɫ�����TOL
	int flag = 0;				//ָʾɫ���Ƿ񳬹�TOL��0��ʾ������1��ʾû����
	int col;					//��¼���������ĵ����������1��ʼ
	int raw;					//��¼���������ĵ����������1��ʼ
	vector<int>fit;				//�����洢���������ĵ��ֵ

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			int current = point[i][j];
			if (count[current] != 1)
			{
				continue;
			}
			else
			{
				for (int k = 0;k < 8;k++)
				{
					if (check_coordinate(i + dx[k], j + dy[k], N, M))
					{
						if (abs(current - point[i + dx[k]][j + dy[k]])<=TOL)
						{
							flag = 1;
						}
					}
				}
				
				if (flag == 0)
				{
					col = j + 1;
					raw = i + 1;
					fit.push_back(current);
				}
				else
				{
					flag = 0;
				}
			}
		}
	}
	
	if (fit.size() == 0)
	{
		cout<< "Not Exist" << endl;
	}
	else if (fit.size() == 1)
	{
		cout << "(" << col << ", " << raw << "): " << fit[0] << endl;
	}
	else
	{
		cout << "Not Unique" << endl;
	}
	getchar();
	getchar();
    return 0;
}

bool check_coordinate(int x, int y,int N,int M)				//�жϵ�ǰԪ�ص���������������Ԫ���Ƿ����
{
	if (x < 0 || y < 0 || x >= N || y >= M)
	{
		return false;
	}
	return true;
}
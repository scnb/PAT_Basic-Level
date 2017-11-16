// 1068.cpp : 定义控制台应用程序的入口点。
//这道题属于中等难度：
/*
	难点①：要记录每个像素出现的次数，因为我们要找的那个像素是独一无二的，而每个像素是[0,2^24)，使用数组int count[16777216]会溢出
			所以改用map这一STL来存储
	难点②：题意有些不明确，在题目的描述中，是说“该点的颜色与其周围8个相邻像素的颜色差充分大”,如果考虑8个像素的话，只能扫描矩阵的内圈
			然而实际评测时发现需要扫描整个矩阵。
	难点③：要扫描整个矩阵，势必有些元素周围只有3个元素（四角），有些元素周围只有5个元素（四边），而内圈元素周围都有8个元素
			那么就要分类。这一点我一开始用的笨办法，即用if对各个情况进行分类。
			在参考了某人的博客后（http://blog.csdn.net/qq_22194315/article/details/60470130），我学习了他用两个数组来分别记录一个元素周围八个元素相对于该元素横、纵坐标上的增量，然后在循环检测中
			再加一个判断周围元素坐标是否正确的函数(check_coordinate)，即可轻松实现题目要求。
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

int dx[8] = { -1,-1,-1,0,0,1,1,1 };				//行的增量，即一个元素周围八个元素相对于该元素横坐标上的增量
int dy[8] = { -1,0,1,-1,1,-1,0,1 };				//列的增量，即一个元素周围八个元素相对于该元素纵坐标上的增量

int main()
{
	int N, M, TOL;
	map<int, int>count;							//用map来实现记录每个元素的个数，若用数组分配2^24次方个元素会溢出
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
	//对（N-1）*（M-1）的所有元素进行遍历，看其是否唯一并且与周围的8个元素色差都超过TOL
	int flag = 0;				//指示色差是否超过TOL，0表示超过，1表示没超过
	int col;					//记录满足条件的点的列数，从1开始
	int raw;					//记录满足条件的点的行数，从1开始
	vector<int>fit;				//用来存储满足条件的点的值

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

bool check_coordinate(int x, int y,int N,int M)				//判断当前元素的坐标加上增量后该元素是否存在
{
	if (x < 0 || y < 0 || x >= N || y >= M)
	{
		return false;
	}
	return true;
}
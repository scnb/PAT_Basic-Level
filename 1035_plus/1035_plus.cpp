// 1035_plus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

bool Merge_Sort(vector<int> &A, vector<int> B, int N);
void Merge(vector<int> &a, int low, int mid, int high);
bool Insert_Sort(vector<int> &A, vector<int> & B, int N);
bool check(vector<int> a, vector<int> b);
void Print(vector<int> a);

bool is_Insert = false;
bool is_Merge = false;

int main()
{
	int N;
	cin >> N;
	int tmp = 0;
	vector<int> original_num;
	vector<int> sorted_num;
	//freopen("input1.txt", "r", stdin);
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		original_num.push_back(tmp);
	}
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		sorted_num.push_back(tmp);
	}
	vector<int> C = original_num;
	bool flag1 = Merge_Sort(original_num, sorted_num, N);
	if (flag1)
	{
		return 0;
	}
	else
	{
		bool flag2 = Insert_Sort(C, sorted_num, N);
		return 0;
	}
}

bool check(vector<int> a, vector<int> b)		//检查当前排序结果是否与题目给定的排序相同
{
	bool flag = true;
	for (int i = 0;i < a.size();i++)
	{
		if (a[i] != b[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void Print(vector<int> a)
{
	cout << a[0];
	for (int i = 1;i < a.size();i++)
	{
		cout << " " << a[i];
	}
}

//两种插入排序算法都可以

bool Insert_Sort(vector<int> &a, vector<int> & b, int len)
{
	bool Is_Insert = false;
	for (int j = 1;j < len;j++)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
		if (Is_Insert)
		{
			cout << "Insertion Sort" << endl;
			Print(a);
			break;
		}
		else if(check(a,b))
		{
			Is_Insert = true;
		}
	}
	return Is_Insert;
}

//bool Insert_Sort(vector<int> &A, vector<int> & B, int N)
//{
//	bool isInsert = false;
//	int i, j;
//	for (i = 1; i < N; i++) 
//	{
//		int tmp = A[i];
//		for (j = i; j > 0 && A[j - 1] > tmp; j--)
//		{
//			A[j] = A[j - 1];
//		}
//		A[j] = tmp;
//		if (isInsert) 
//		{
//			cout << "Insertion Sort" << endl;
//			Print(A);
//			break;
//		}
//		else if (check(A,B)) 
//		{
//			isInsert = true;
//		}
//	}
//	return isInsert;
//}


void Merge(vector<int>& a, int low, int mid, int high)		//每一次进行Merge操作前，前半部分和后半部分都是分别排好序的
{
	vector<int> t;
	for (int i = 0;i < high - low;i++)
	{
		t.push_back(0);
	}
	int i = low, j = mid, k = 0;

	while (i < mid && j < high) 
	{
		if (a[i] <= a[j])
			t[k++] = a[i++];
		else
			t[k++] = a[j++];
	}

	while (i < mid)
		t[k++] = a[i++];
	while (j < high)
		t[k++] = a[j++];

	for (i = low, k = 0; i < high; i++) 
	{
		a[i] = t[k++];
	}
}

bool Merge_Sort(vector<int>& A, vector<int> B, int N)
{
	int i, j;
	bool isMerge = false;
	for (i = 1; i < N; i *= 2) 
	{
		for (j = 0; j < N; j += i * 2) 
		{
			if (j + i * 2 <= N) 
			{
				Merge(A, j, j + i, j + i * 2);
			}
			else if (j + i <= N) 
			{
				Merge(A, j, j + i, N);
			}
		}
		if (isMerge) 
		{
			cout << "Merge Sort" << endl;
			Print(A);
			break;
		}
		else if (check(A, B))
		{
			isMerge = true;
		}
	}
	return isMerge;
}
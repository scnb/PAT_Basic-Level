// 1059.cpp : �������̨Ӧ�ó������ڵ㡣
//��Ȼ��Are you kidding?�е�kд�ɴ�д���ˡ�����
//������ܵ���˵����̫�ѣ�ֻҪ�ѹ����������������֧����ͼ���ͺ����ˡ�
//�ѵ����ڣ�ÿһ����֧���жϸ��������У����磺�ж�id�Ƿ���ڣ�ԭ�������дһ��ר���ж�id�Ƿ���ڵĺ�����ͨ���۰�������ж��Ƿ����
//			������ܷ�ʱ��ģ���������ȶ����һ������10000���������飬������¼ÿ��id�Ƿ���ڣ��ټ���ʱ��ͷ���Ķ��ˣ�ͬ������
//			��¼ÿ��id��������ÿ��id����ѯ�Ĵ���������������ؼ򻯲�ѯ�Ĺ��̡�

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

//bool Have_Id(int tmp,vector<int> id);		//�ж�id�Ƿ����
bool is_sushu(int tmp);						//�ж��ǲ�������;

int main()
{
	int N;
	int K;
	int count[10000] = { 0 };				//��¼ÿ��id����ѯ�Ĵ���
	int grade[10000] = { 0 };				//��¼ÿ��id������
	int flag[10000] = { 0 };				//��¼ĳ��id�Ƿ����
	cin >> N;
	vector<int> id;
	int tmp;
	for (int i = 0;i < N;i++)
	{
		cin >> tmp;
		grade[tmp] = i + 1;					//�洢ÿ��id������
		flag[tmp]++;						//�������ڸ�id
		id.push_back(tmp);
	}
	vector<int> sorted_id = id;						//�����С�����ź����vector�����۰����
	cin >> K;
	vector<int> find_id;
	for (int i = 0;i < K;i++)
	{
		cin >> tmp;
		find_id.push_back(tmp);
	}
	sort(sorted_id.begin(), sorted_id.end());
	for (int i = 0;i < K;i++)
	{
		if (flag[find_id[i]] != 0)								//�鿴��id�Ƿ����
		{
			if (count[find_id[i]] == 0)							//�����û�б���ѯ��
			{
				if (grade[find_id[i]] == 1)						//һ�Ƚ�������id��������������id��ֵ
				{
					cout << setw(4) << setfill('0') << find_id[i] << ": Mystery Award" << endl;
				}
				else if (is_sushu(grade[find_id[i]]))			//����������������������idֵ
				{
					cout << setw(4) << setfill('0') << find_id[i] << ": Minion" << endl;
				}
				else
				{
					cout << setw(4) << setfill('0') << find_id[i] << ": Chocolate" << endl;
				}
				count[find_id[i]]++;
			}
			else
			{
				cout << setw(4) << setfill('0') << find_id[i] << ": Checked" << endl;
			}
		}
		else
		{
			cout << setw(4) << setfill('0') << find_id[i] << ": Are you kidding?" << endl;
		}
	}
	getchar();
	getchar();
    return 0;
}

//bool Have_Id(int tmp, vector<int> id)		//�ж��Ƿ���ڸñ����ҵ�id
//{
//	int left = 0;
//	int right = id.size() - 1;
//	int mid = (left+right)/2;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (tmp == id[mid])
//		{
//			return true;
//		}
//		if (tmp < id[mid])
//		{
//			right = mid - 1;
//		}
//		else if (tmp > id[mid])
//		{
//			left = mid + 1;
//		}
//	}
//	return false;
//}

bool is_sushu(int tmp)		//�ж��ǲ�������
{
	int flag = 0;
	if (tmp == 1)
	{
		return false;
	}
	else if (tmp == 2)
	{
		return true;
	}
	else
	{
		for (int i = 2;i <= sqrt(tmp);i++)
		{
			if (tmp % i == 0)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}	
}
// 1017.cpp : �������̨Ӧ�ó������ڵ㡣
//˼·�������λ�����λ����λ��λ�ĳ�
//��Ȼ˼·�ܿ��������ˣ�����ʵ���������ǻ��˲��ٹ�����Ҫԭ�����ڲ���ѡ����ʵ�������ʢ�ű�����A��
//ԭ��ѡ������string��ʢ��A�������ں�������ʱ��Ƚ��鷳����Ƶ��ַ���int������ת������Ҳ����Ϊ�Լ��ܳ�ʱ�䲻��C++��
//�����ַ�����Щ�������ò���ˡ�
//���ѡ�õ��ǲ�ȡstring����������A��Ȼ��ת�浽vector�С�����Ϊvector���ͱ�������ֱ����cin�����룩
//vector���ͱ���ֱ�Ӷ���Ϊint�͵ģ������Ժ�������ǳ����㡣

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int>A;				//��������������1000λ��������
	string A_tmp;
	int B;						//������1λ������
	vector<int>Q;				//��
	int R;						//����
	int div;					//ÿ��������ʵ�ʵı�����
	cin >> A_tmp;
	for (int i = 0;i < A_tmp.length();i++)
	{
		A.push_back(A_tmp[i] - '0');
	}
	cin >> B;
	int count = 0;							//�����̵�λ��
	int len = A.size();
											//�ȿ��ǵ�һλ�Ƿ���ڳ���
	if (A[0] >= B)
	{
		Q.push_back( A[0] / B );			//����õ��̴���Q��
		R = A[0] % B;						//���㱾�����������
	}
	else if (A[0] < B && len != 1)
	{
		R = A[0] % B;
	}
	else if (A[0] < B && len == 1)
	{
		Q.push_back(0);
		R = A[0] % B;
	}

	for (int i = 1;i<len;i++)
	{
		div = R * 10 + A[i];
		Q.push_back(div / B);
		R = div % B;
	}

	for (int i = 0;i < Q.size();i++)
	{
		cout << Q[i];
	}
	cout << " " << R;
	getchar();
	getchar();
    return 0;
}


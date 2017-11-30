// 1034.cpp : �������̨Ӧ�ó������ڵ㡣
///(��o��)/~~
/*
	���ȣ���tm�����ˣ�������Ϊ������ж��ѣ������Ұ����⸴�ӻ��ˡ�
	������ֻҪ80���г�����ܸ㶨������������300���С�����
	�򵥷���Ӧ���������ģ���Ҫ������Ŀ��˵ʲô������ k a b�ͰѶ������ķ�������취����������ʽ��û��Ҫ��
	�ڶ������ݵ�ʱ��Ҳ���ð����ַ���������������ֱ����scanf("%d")���ܰ����ִ��ַ�����ɸѡ������
	��Ҫ�ѷ�������k a b����ʽ�����Ǳ�����ԭ������������һ��print�������ڸú������ٽ�����ת���������ʽ���
	���÷����ķ��Ӻͷ�ĸ��ʽ���ں͡�����������������൱���㣬���磺
	�ͣ�a/b + c/d = (a*d+b*c)/(b*d)
	�a/b - c/d = (a*d-b*c)/(b*d)
	����a/b * c/d = (a*c)/(b*d)
	�̣�a/b * c/d = (a*d)/(b*c)
	����Ҳ�Ͳ��õ�����������ˣ���Ϊ���ڷ��ž��ڷ����У�Ȼ�����Զ����print�����оͿ��Ժܷ���Ľ��д������
	print����Ҫ��ɵĹ��ܣ����������������ʽ����������ж��������Ƿ������

	���⣬��Ϊԭ����Ѱ�����Լ�����ӳ���ʱ�����Բ����˴��ͨ�õ�gcd�������ܹ���Ѹ�ٵ��ҵ����Լ��
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void fenshu2num(struct fenshu tmp1, struct num & tmp2);
void make_fenshu_easy(struct fenshu & tmp_fenshu);
void show_equation(vector<struct num> b, struct num tmp_num, char sign);
void show_single_num(struct num tmp);
long long min_num(long long a, long long b);
int gcd(long long a, long long b);			//������Լ���ĺ���


struct num
{
	long long k;			//��������
	long long a;			//������
	long long b;			//����ĸ
	int flag = 1;   //����
};

struct fenshu
{
	long long fenzi;
	long long fenmu;
	int flag = 1;					//-1��ʾ����1��ʾ��
};

int main()
{
	vector<struct fenshu> a;
	vector<struct num> b;
	struct fenshu tmp_a;
	string tmp_str;
	string num = "";
	for (int i = 0;i < 2;i++)		//��������ַ����ֽ�����������ķ��Ӻͷ�ĸ������¼���ǵķ���
	{
		cin >> tmp_str;
		int j = 0;
		if (tmp_str[j] == '-')
		{
			tmp_a.flag = -1;
			j++;
		}
		else
		{
			tmp_a.flag = 1;
		}
		while (tmp_str[j] != '/')
		{
			num += tmp_str[j];
			j++;
		}
		tmp_a.fenzi = stol(num);
		num = "";
		j++;
		while (j < tmp_str.length())
		{
			num += tmp_str[j];
			j++;
		}
		tmp_a.fenmu = stol(num);
		num = "";
		a.push_back(tmp_a);
	}
	//���ڻ����ʽ��Ҫ�ҳ����ǵ����Լ��
	for (int i = 0;i < 2;i++)
	{
		make_fenshu_easy(a[i]);
	}
	for (int i = 0;i < 2;i++)
	{
		struct num tmp_b;
		fenshu2num(a[i], tmp_b);
		b.push_back(tmp_b);
	}
	
	//�ټӷ�
	struct num tmp_num;
	struct fenshu tmp_fenshu;
	tmp_fenshu.fenmu = a[0].fenmu*a[1].fenmu;
	tmp_fenshu.fenzi = a[0].fenzi*a[1].fenmu*a[0].flag + a[1].fenzi*a[0].fenmu*a[1].flag;
	if (tmp_fenshu.fenzi < 0)
	{
		tmp_fenshu.flag = -1;
		tmp_fenshu.fenzi = abs(tmp_fenshu.fenzi);
	}
	else
	{
		tmp_fenshu.flag = 1;
	}
	make_fenshu_easy(tmp_fenshu);
	fenshu2num(tmp_fenshu, tmp_num);
	show_equation(b, tmp_num, '+');

	//�ڼ���
	tmp_fenshu.fenmu = a[0].fenmu*a[1].fenmu;
	tmp_fenshu.fenzi = a[0].fenzi*a[1].fenmu*a[0].flag - a[1].fenzi*a[0].fenmu*a[1].flag;
	if (tmp_fenshu.fenzi < 0)
	{
		tmp_fenshu.flag = -1;
		tmp_fenshu.fenzi = abs(tmp_fenshu.fenzi);
	}
	else
	{
		tmp_fenshu.flag = 1;
	}
	make_fenshu_easy(tmp_fenshu);
	fenshu2num(tmp_fenshu, tmp_num);
	show_equation(b, tmp_num, '-');
	//�۳˷�
	tmp_fenshu.fenmu = a[0].fenmu*a[1].fenmu;
	tmp_fenshu.fenzi = a[0].fenzi*a[0].flag*a[1].fenzi*a[1].flag;
	if (tmp_fenshu.fenzi < 0)
	{
		tmp_fenshu.flag = -1;
		tmp_fenshu.fenzi = abs(tmp_fenshu.fenzi);
	}
	else
	{
		tmp_fenshu.flag = 1;
	}
	make_fenshu_easy(tmp_fenshu);
	fenshu2num(tmp_fenshu, tmp_num);
	show_equation(b, tmp_num, '*');
	//�ܳ�������������ĸΪ0�����Inf
	tmp_fenshu.fenmu = a[0].fenmu*a[1].fenzi;
	tmp_fenshu.fenzi = a[0].fenzi*a[0].flag*a[1].fenmu*a[1].flag;
	if (tmp_fenshu.fenzi < 0)
	{
		tmp_fenshu.flag = -1;
		tmp_fenshu.fenzi = abs(tmp_fenshu.fenzi);
	}
	else
	{
		tmp_fenshu.flag = 1;
	}
	make_fenshu_easy(tmp_fenshu);
	fenshu2num(tmp_fenshu, tmp_num);
	show_equation(b, tmp_num, '/');
    return 0;
}

int gcd(long long a, long long b)															//������Լ���ĺ���
{
	if (a == 0)
	{
		return b;
	}
	gcd(b%a, a);
}

void make_fenshu_easy(struct fenshu & tmp_fenshu)
{
	//int max_yueshu = 1;														//��ʼ�����Լ��Ϊ1
	//for (int j = 1;j <= (min(tmp_fenshu.fenzi, tmp_fenshu.fenmu));j++)		//min(fenzi,fenmu)�ҳ����Լ��
	//{
	//	if (tmp_fenshu.fenzi % j == 0 && tmp_fenshu.fenmu % j == 0)
	//	{
	//		max_yueshu = j;
	//	}
	//}
	//tmp_fenshu.fenzi /= max_yueshu;
	//tmp_fenshu.fenmu /= max_yueshu;
	/*����ĺ�����Щ���ӣ����ܻᳬʱ*/
	int b = gcd(tmp_fenshu.fenzi, tmp_fenshu.fenmu);
	tmp_fenshu.fenzi /= b;
	tmp_fenshu.fenmu /= b;
}

void fenshu2num(struct fenshu tmp1, struct num & tmp2)
{
	tmp2.flag = tmp1.flag;
	if (tmp1.fenmu == 0)
	{
		tmp2.k = 0;
		tmp2.a = 0;
		tmp2.b = 0;
	}
	else
	{
		tmp2.k = tmp1.fenzi / tmp1.fenmu;
		tmp2.a = tmp1.fenzi % tmp1.fenmu;
		tmp2.b = tmp1.fenmu;
	}
}

long long min_num(long long a, long long b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void show_single_num(struct num tmp)
{
	if (tmp.k == 0)
	{
		if (tmp.flag == -1)
		{
			cout << "(-";
		}
		if (tmp.a == 0)
		{
			cout << 0;
		}
		else
		{
			cout << tmp.a;
			if (tmp.b != 0)
			{
				cout << "/" << tmp.b;
			}
		}
		if (tmp.flag == -1)
		{
			cout << ")";
		}
	}
	else
	{
		if (tmp.flag == -1)
		{
			cout << "(-" << tmp.k;
		}
		else
		{
			cout << tmp.k;
		}
		if (tmp.a != 0)
		{
			cout << " " << tmp.a;
			if (tmp.b != 0)
			{
				cout << "/" << tmp.b;
			}
		}
		if (tmp.flag == -1)
		{
			cout << ")";
		}
	}
}

void show_equation(vector<struct num> b, struct num tmp_num, char sign)
{
	if (sign == '+')
	{
		show_single_num(b[0]);
		cout << " " << sign << " ";
		show_single_num(b[1]);
		cout << " = ";
		show_single_num(tmp_num);
		cout << endl;
	}
	else if (sign == '-')
	{
		show_single_num(b[0]);
		cout << " " << sign << " ";
		show_single_num(b[1]);
		cout << " = ";
		show_single_num(tmp_num);
		cout << endl;
	}
	else if (sign == '*')
	{
		show_single_num(b[0]);
		cout << " " << sign << " ";
		show_single_num(b[1]);
		cout << " = ";
		show_single_num(tmp_num);
		cout << endl;
	}
	else if (sign == '/')
	{
		show_single_num(b[0]);
		cout << " " << sign << " ";
		show_single_num(b[1]);
		cout << " = ";
		if (b[1].k == 0 && b[1].a == 0)
		{
			cout << "Inf";
		}
		else
		{
			show_single_num(tmp_num);
		}
		cout << endl;
	}
}
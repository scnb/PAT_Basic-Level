// 1034.cpp : 定义控制台应用程序的入口点。
///(ㄒoㄒ)/~~
/*
	首先，我tm作对了，不是因为这道题有多难，而是我把问题复杂化了。
	本来，只要80多行程序就能搞定，但是我用了300多行···
	简单方法应该是这样的：不要看到题目中说什么最简分数 k a b就把读进来的分数都想办法化成那种形式，没必要！
	在读入数据的时候，也不用按照字符串读进来，而是直接用scanf("%d")就能把数字从字符串中筛选出来。
	不要把分数化成k a b的形式，而是保留其原样，单独定义一个print函数，在该函数中再将分数转换成最简形式输出
	采用分数的分子和分母形式对于和、差、积、商四种运算相当方便，比如：
	和：a/b + c/d = (a*d+b*c)/(b*d)
	差：a/b - c/d = (a*d-b*c)/(b*d)
	积：a/b * c/d = (a*c)/(b*d)
	商：a/b * c/d = (a*d)/(b*c)
	这样也就不用单独保存符号了，因为现在符号就在分子中，然后在自定义的print函数中就可以很方便的进行处理输出
	print函数要完成的功能：将分数化成最简形式，并输出，判断正负及是否加括号

	另外，因为原来的寻找最大公约数的子程序超时，所以采用了大家通用的gcd函数，能够很迅速的找到最大公约数
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
int gcd(long long a, long long b);			//求解最大公约数的函数


struct num
{
	long long k;			//整数部分
	long long a;			//最简分子
	long long b;			//最简分母
	int flag = 1;   //符号
};

struct fenshu
{
	long long fenzi;
	long long fenmu;
	int flag = 1;					//-1表示负，1表示正
};

int main()
{
	vector<struct fenshu> a;
	vector<struct num> b;
	struct fenshu tmp_a;
	string tmp_str;
	string num = "";
	for (int i = 0;i < 2;i++)		//把输入的字符串分解成两个分数的分子和分母，并记录他们的符号
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
	//对于化简分式，要找出他们的最大公约数
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
	
	//①加法
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

	//②减法
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
	//③乘法
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
	//④除法，若除法分母为0，输出Inf
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

int gcd(long long a, long long b)															//求解最大公约数的函数
{
	if (a == 0)
	{
		return b;
	}
	gcd(b%a, a);
}

void make_fenshu_easy(struct fenshu & tmp_fenshu)
{
	//int max_yueshu = 1;														//初始化最大公约数为1
	//for (int j = 1;j <= (min(tmp_fenshu.fenzi, tmp_fenshu.fenmu));j++)		//min(fenzi,fenmu)找出最大公约数
	//{
	//	if (tmp_fenshu.fenzi % j == 0 && tmp_fenshu.fenmu % j == 0)
	//	{
	//		max_yueshu = j;
	//	}
	//}
	//tmp_fenshu.fenzi /= max_yueshu;
	//tmp_fenshu.fenmu /= max_yueshu;
	/*上面的函数有些复杂，可能会超时*/
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
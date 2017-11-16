// 1017.cpp : 定义控制台应用程序的入口点。
//思路：从最高位到最低位，两位两位的除
//虽然思路很快就想出来了，但是实现起来还是花了不少功夫，主要原因在于不能选择合适的容器来盛放被除数A。
//原来选的是用string来盛放A，但是在后续计算时会比较麻烦（设计到字符和int整数的转换），也是因为自己很长时间不用C++了
//对于字符串这些东西忘得差不多了。
//最后选用的是采取string来接收输入A，然后转存到vector中。（因为vector类型变量不能直接用cin来输入）
//vector类型变量直接定义为int型的，这样对后续计算非常方便。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int>A;				//被除数，不超过1000位的正整数
	string A_tmp;
	int B;						//除数，1位正整数
	vector<int>Q;				//商
	int R;						//余数
	int div;					//每次运算中实际的被除数
	cin >> A_tmp;
	for (int i = 0;i < A_tmp.length();i++)
	{
		A.push_back(A_tmp[i] - '0');
	}
	cin >> B;
	int count = 0;							//计算商的位数
	int len = A.size();
											//先考虑第一位是否大于除数
	if (A[0] >= B)
	{
		Q.push_back( A[0] / B );			//将求得的商存在Q中
		R = A[0] % B;						//计算本次运算的余数
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


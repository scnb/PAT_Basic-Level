// 1071.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int T, K;
	cin >> T >> K;
	int n1, b, t, n2;
	for (int i = 0;i<K;i++)
	{
		scanf("%d %d %d %d", &n1, &b, &t, &n2);
		if (t <= T)
		{
			if (n2 - n1 > 0 && b == 1)  //�Ķ��� 
			{
				T += t;
				cout << "Win " << t << "! Total = " << T << "." << endl;
			}
			else if (n2 - n1 < 0 && b == 0)   //�Ķ��� 
			{
				T += t;
				cout << "Win " << t << "!  Total = " << T << "." << endl;
			}
			else
			{
				T -= t;
				if (T>0)
				{
					cout << "Lose " << t << ".  Total = " << T << "." << endl;
				}
				else if (T == 0)
				{
					cout << "Lose " << t << ".  Total = " << T << "." << endl;
					cout << "Game Over." << endl;
					break;
				}
				else
				{
					cout << "Game Over." << endl;
					break;
				}
			}
		}
		else
		{
			cout << "Not enough tokens.  Total = " << T << "." << endl;
		}
	}
    return 0;
}
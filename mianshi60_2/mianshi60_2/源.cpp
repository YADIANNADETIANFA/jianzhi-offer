// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<double>>A(2, vector<double>(6 * n + 1, 0));
		int flag = 0;//此种flag替换

		for (int i = 1; i <= 6; ++i)
		{
			A[flag][i] = 1;
		}
		for (int i = 2; i <= n; ++i)//第二个及之后骰子
		{
			for (int j = 0; j <= i - 1; ++j)
				A[1 - flag][j] = 0;

			if (i & 1 == 1)
			{
				int End = i + (i * 5 + 1) / 2 ;
				int Start = i;
				for (int j = i * 6; j >= End; --j)
				{
					A[1 - flag][j] = 0;//要有一个归零处理

					for (int k = j - 1; (k >= j - 6) && (k >= 1); k--)
					{
						A[1 - flag][j] += A[flag][k];
					}
					A[1 - flag][Start++] = A[1 - flag][j];//根据左右对称，使计算量少一半
				}
				flag = 1 - flag;//此种flag替换
			}
			else
			{
				int End = i + (i * 5) / 2;
				int Start = i;
				for (int j = i * 6; j >= End; --j)
				{
					A[1 - flag][j] = 0;//要有一个归零处理

					for (int k = j - 1; (k >= j - 6) && (k >= 1); k--)
					{
						A[1 - flag][j] += A[flag][k];
					}
					A[1 - flag][Start++] = A[1 - flag][j];//根据左右对称，使计算量少一半
				}
				flag = 1 - flag;//此种flag替换
			}
		}
		double MAX = pow(6, n);
		if (n & 1 == 1)
		{
			for (int i = n; i <= 6 * n; ++i)
			{
				double res = A[0][i] / MAX;
				cout << res << endl;
			}
		}
		else
		{
			for (int i = n; i <= 6 * n; ++i)
			{
				double res = A[1][i] / MAX;
				cout << res << endl;
			}
		}
	}
	return 0;
}

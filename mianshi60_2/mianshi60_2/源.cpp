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
		int flag = 0;//����flag�滻

		for (int i = 1; i <= 6; ++i)
		{
			A[flag][i] = 1;
		}
		for (int i = 2; i <= n; ++i)//�ڶ�����֮������
		{
			for (int j = 0; j <= i - 1; ++j)
				A[1 - flag][j] = 0;

			if (i & 1 == 1)
			{
				int End = i + (i * 5 + 1) / 2 ;
				int Start = i;
				for (int j = i * 6; j >= End; --j)
				{
					A[1 - flag][j] = 0;//Ҫ��һ�����㴦��

					for (int k = j - 1; (k >= j - 6) && (k >= 1); k--)
					{
						A[1 - flag][j] += A[flag][k];
					}
					A[1 - flag][Start++] = A[1 - flag][j];//�������ҶԳƣ�ʹ��������һ��
				}
				flag = 1 - flag;//����flag�滻
			}
			else
			{
				int End = i + (i * 5) / 2;
				int Start = i;
				for (int j = i * 6; j >= End; --j)
				{
					A[1 - flag][j] = 0;//Ҫ��һ�����㴦��

					for (int k = j - 1; (k >= j - 6) && (k >= 1); k--)
					{
						A[1 - flag][j] += A[flag][k];
					}
					A[1 - flag][Start++] = A[1 - flag][j];//�������ҶԳƣ�ʹ��������һ��
				}
				flag = 1 - flag;//����flag�滻
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

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main()//考虑A数组里面会有0的出现，代码可以进一步优化，使计算量更少
{
	int n=0;
	while (cin >> n)
	{
		vector<int> A(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}

		vector<int> X_mine(n, 0);
		X_mine[0] = 1;
		for (int i = 1; i <= n-1; ++i)
		{
			X_mine[i] = X_mine[i - 1] * A[n - i];
		}

		vector<int> Y_mine(n, 0);
		Y_mine[0] = 1;
		for (int i = 1; i <= n - 1; ++i)
		{
			Y_mine[i] = Y_mine[i - 1] * A[i-1];
		}

		vector<int> B(n, 0);
		for (int i = 0; i <= n - 1; ++i)
		{
			B[i] = Y_mine[i] * X_mine[n - 1 - i];
			cout << B[i] << endl;
		}
	}
	return 0;
}
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

void FindPro(int up_side, vector<double>& the_pro_res, int num_of_square, int n, int last_sum=0, double last_pro=1)//num_of_square从1开始,last_sum从0开始，last_pro从1开始
{
	if (num_of_square == n+1)
	{
		the_pro_res[last_sum] += last_pro;
		return;
	}
	for (int i = 1; i <= 6; ++i)
	{
		if (last_sum + i <= up_side)//根据左右对称的规律，节省一半计算量
		{
			FindPro(up_side, the_pro_res, num_of_square + 1, n, last_sum + i, last_pro / 6);
		}
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		int up_side = 0;
		if (n & 1 == 1)
		{
			up_side = (5 * n + 1) / 2 + n-1;
		}
		else 
			up_side = (5 * n + 1) / 2 + n;

		vector<double> the_pro_res(6*n + 1, 0);
		FindPro(up_side, the_pro_res, 1, n, 0, 1);

		if (n & 1 == 0)
		{
			int j = n;
			for (int i = 6 * n; i > (5 * n + 1) / 2 + n; --i)
			{
				the_pro_res[i] = the_pro_res[j++];
			}
		}
		else
		{
			int j = n;
			for (int i = (6 * n); i > ((5 * n + 1) / 2 + n - 1); --i)
			{
				the_pro_res[i] = the_pro_res[j++];
			}
		}

		for (int i = 1; i <= 6 * n; ++i)
		{
			printf("%f\n", the_pro_res[i]);
		}
		cout << endl;
	}
	return 0;
}

//也可以从1+3=4   2+2=4  3+1=4的规律想想
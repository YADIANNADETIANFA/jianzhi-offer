// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		vector<int> num(n,0);
		for (int i = 0; i < n; ++i)
		{
			cin >> num[i];
		}

		int min = num[0];
		int mairu = num[1];
		int res = mairu - min;

		for (int i = 2; i <= n - 1; ++i)
		{
			mairu = num[i];
			if (min > num[i - 1])
				min = num[i - 1];
			int temp = mairu - min;
			if (temp > res)
				res = temp;
		}
		cout << res << endl;
	}
	return 0;
}

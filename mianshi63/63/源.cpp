//只扫描一次数组
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
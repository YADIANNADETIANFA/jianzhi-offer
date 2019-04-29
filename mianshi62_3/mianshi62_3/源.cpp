#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (n < 1 || m < 1)
		{
			cout << -1 << endl;//这里要写cout<<-1<<endl;  要是return -1的话，就跳出while循环了，cin就没用了
			continue;
		}
		int last = 0;
		
		for (int i = 2; i <= n; ++i)
			last = (last + m) % i;
		cout << last << endl;
	}
	return 0;
}
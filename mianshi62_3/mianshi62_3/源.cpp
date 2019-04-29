// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。
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

// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。
//利用容器list解决，但是Test("Test6", 4000, 997, 1027);明显要比自己定义链表要慢得多，可能是erase的原因
#include<cstdio>
#include<iostream>
#include<list>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		list<int> List;
		for (int i = 0; i < n ; ++i)
		{
			List.push_back(i);
		}

		list<int>::iterator iter= List.begin();

		while (List.size() != 1)
		{
			for (int i = 1; i < m; ++i)
			{
				iter++;
				if (iter == List.end())
					iter = List.begin();

			}
			iter=List.erase(iter);//容器改动后，要重定义迭代器
			if (iter == List.end())//别忘了，如果指向end，要处理一下
				iter = List.begin();
		}
		cout << *(List.begin()) << endl;
	}
	return 0;
}

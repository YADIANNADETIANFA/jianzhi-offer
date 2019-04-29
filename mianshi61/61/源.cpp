#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	while (true)
	{
		vector<int> A(14, 0);
		bool jixu = true;
		for (int i = 0; i < 5; ++i)
		{
			int temp;
			cin >> temp;
			if (temp != 0 && A[temp] != 0)//一个数字出现了2次及以上，直接不可能顺子
			{
				jixu = false;
				cout << "false" << endl;
				break;
			}
			else if (temp == 0 && A[temp] >= 2)//不能出现3个王牌
			{
				jixu = false;
				cout << "false" << endl;
				break;
			}
			else
			{
				++A[temp];
			}
		}
		if (jixu)
		{
			vector<int>::iterator iter1 = A.begin() + 1;
			vector<int>::iterator iter2 = A.end()-1;

			while (iter1!=A.end() && *iter1 == 0)//找除了王牌外，最小的数值
			{
				iter1++;
			}

			while (iter2 != A.begin() && *iter2 == 0)//找最大的数值
			{
				--iter2;
			}
			int dis = iter2 - iter1 + 1;//最小最大数值长是多少
			if (dis==5)
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}
		}
	}
	return 0;
}
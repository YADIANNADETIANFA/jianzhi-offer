// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
#include<iostream>
#include<cstdio>
using namespace std;

void PrintClock(int** num, int m, int n)//m为总行数，n为总列数
{
	if (num == nullptr || m <= 0 || n <= 0)
		return;

	if (m == 1)//仅一行
	{
		for (int i = 0; i <= n - 1; ++i)
			cout << num[0][i]<<" ";
		return;
	}
	if (n == 1)//仅一列
	{
		for (int i = 0; i <= m - 1; ++i)
			cout << num[i][0] << " ";
		return;
	}

	int Kmax = 0;//总圈数
	if ((m >> 1) > (n >> 1))
		Kmax = (n >> 1);
	else
		Kmax = (m >> 1);

	for (int k = 0; k < Kmax; ++k)//分别打印一圈的四周
	{
		for (int i = k; i <= n - 1 - k; ++i)
			cout << num[k][i] << " ";
		for (int i = k + 1; i <= m - 1 - k; ++i)
			cout << num[i][n - 1 - k] << " ";
		for (int i = n - 1 - k - 1; i >= k; --i)
			cout << num[m - 1 - k][i] << " ";
		for (int i = m - 1 - k - 1; i >= k + 1; --i)
			cout << num[i][k] << " ";

	}

	if ((m & 1) == 1 && m < n)//行是奇数，那就差中间一行没有打
	{
		for (int i = 0 + Kmax; i <= n - 1 - Kmax; ++i)
			cout << num[(m >> 1) + 0][i] << " ";
		return;
	}

	if ((n & 1) == 1 && n < m)//列是奇数，那就差中间一列没有打
	{
		for (int i = 0 + Kmax; i <= m - 1 - Kmax; ++i)
			cout << num[i][(n >> 1) + 0] << " ";
		return;
	}

}

void Test(const char* testname, int** num, int m, int n)
{
	if (testname != nullptr)
		printf("%s begin:\n",testname);
	PrintClock(num, m, n);
}

void ConstructNum(int** num,int m ,int n)
{
	for (int i = 0; i < m; ++i)
	{
		num[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			num[i][j] = i * n + j + 1;
		}
	}

}

void test1()
{
	int** num = new int*[4];
	ConstructNum(num, 4, 4);
	Test("test1", num, 4, 4);
	
	for (int i = 0; i < 4; ++i)
	{
		delete[] num[i];
	}
	delete[] num;
	cout << endl;
}

void test2()
{
	int** num = new int*[1];
	ConstructNum(num, 1, 1);
	Test("test2", num, 1, 1);

	for (int i = 0; i < 1; ++i)
	{
		delete[] num[i];
	}
	delete[] num;
	cout << endl;
}

void test3()
{
	int** num = new int*[5];
	ConstructNum(num, 5, 1);
	Test("test3", num, 5, 1);

	for (int i = 0; i < 5; ++i)
	{
		delete[] num[i];
	}
	delete[] num;
	cout << endl;
}

void test4()
{
	int** num = new int*[5];
	ConstructNum(num, 5, 2);
	Test("test4", num, 5, 2);

	for (int i = 0; i < 5; ++i)
	{
		delete[] num[i];
	}
	delete[] num;
	cout << endl;
}

void test5()
{
	int** num = new int*[1];
	ConstructNum(num, 1, 5);
	Test("test5", num, 1, 5);

	for (int i = 0; i < 1; ++i)
	{
		delete[] num[i];
	}
	delete[] num;
	cout << endl;
}


void test6()
{
	int** num = new int*[3];
	ConstructNum(num, 3, 5);
	Test("test6", num, 3, 5);

	for (int i = 0; i < 3; ++i)
	{
		delete[] num[i];
	}
	delete[] num;
	cout << endl;
}

void test7()
{
	int** num = new int*[5];
	ConstructNum(num, 5, 3);
	Test("test7", num, 5, 3);

	for (int i = 0; i < 5; ++i)
	{
		delete[] num[i];
	}
	delete[] num;
	cout << endl;
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
}

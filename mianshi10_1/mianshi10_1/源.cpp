#include<cstdio>//printf头文件

long long Fibonacci_Solution1(unsigned n)//long long为长整型64位；unsigned int可缩写为unsigned
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n > 1)
	{
		return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
	}
}

long long Fibonacci_Solution2(unsigned n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	int data0 = 0;
	int data1 = 1;
	for (int i = 2; i <= n; ++i)
	{
		int mid = data1;
		data1 = data0 + data1;
		data0 = mid;
	}
	return data1;
}

void Test(int n, int excepted)
{
	if (Fibonacci_Solution1(n) == excepted)
	{
		printf("Solution1 succeed.\n");
	}
	else
	{
		printf("Solution1 failed.\n");
	}

	if (Fibonacci_Solution2(n) == excepted)
	{
		printf("Solution2 succeed.\n");
	}
	else
	{
		printf("Solution2 failed.\n");
	}
}

int main()
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);
	Test(40, 102334155);
	
	return 0;
	
}
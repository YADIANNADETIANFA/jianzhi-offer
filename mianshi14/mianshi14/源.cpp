// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int maxproductAftercutting1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 2;
	if (length == 3)
		return 3;
	int* production = new int[length + 1];
	production[0] = 0;
	production[1] = 1;
	production[2] = 2;
	production[3] = 3;

	for (int i = 4; i <= length; ++i)
	{
		int max = 0;
		production[i] = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			max = production[j] * production[i - j];
			if (max > production[i])
			{
				production[i] = max;
			}
		}
	}
	int result = production[length];
	delete[] production;
	return result;
}

int maxproductAftercutting2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 2;
	if (length == 3)
		return 3;
	if (length == 4)
		return 4;

	int timeOfcut = 0;
	/*while (length >=5)//²»ÓÃwhileÑ­»·£¬ÀË·ÑÐÔÄÜ
	{
		++timeOfcut;
		length -= 3;
	}*/
	timeOfcut = length / 3;
	int remainLength = length - 3 * timeOfcut;
	if (remainLength == 1)
	{
		timeOfcut -= 1;
		remainLength += 3;
		return (int)(pow(3, timeOfcut))*(int)(remainLength);
	}
	if (remainLength == 2)
	{
		return (int)(pow(3, timeOfcut))*(int)(remainLength);
	}
	return (int)(pow(3, timeOfcut));
}

void Test(const char* testname,int length,int expected)
{
	int result1 = maxproductAftercutting1(length);
	if (result1 == expected)
		cout <<testname<< "Solution1 pass." << endl;
	else
		cout << testname << "Solution1 fail." << endl;

	int result2 = maxproductAftercutting2(length);
	if (result2 == expected)
		cout << testname << "Solution2 pass." << endl;
	else
		cout << testname << "Solution2 fail." << endl;
}

void test1()
{
	Test("test1", 1, 0);
}

void test2()
{
	Test("test2", 2, 2);
}

void test3()
{
	Test("test3", 9, 27);
}

int main()
{
	test1();
	test2();
	test3();
}

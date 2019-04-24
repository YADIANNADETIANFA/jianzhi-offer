#include<cstdio>
#include<exception>

using namespace std;

void theDifferentNum(int* data, int length,int& result)//引用传值，省着try里面东西传不出来
{
	if (data == nullptr || length <= 0)
		throw exception("Bad Parameters");

	int bitSum[3] = { 0 };//全部做0处理，并且默认数组里面全是1~7的数字

	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if ((data[i] >> j) & 1 == 1)
				++bitSum[j];
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		if ((bitSum[i] % 3) != 0)//是求余，不是整除运算！
			result += (1 << i);
	}

	return;
}

void Test(const char* testname, int* data, int length, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	int result = 0;

	try
	{
		theDifferentNum(data, length, result);
	}
	catch (exception& e)
	{
		printf("Bad Parameters\n");
		return;
	}
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void Test1()
{
	int numbers[] = { 1, 1, 2, 2, 2, 1, 3 };
	int expected = 3;
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字的大小位于中间
void Test2()
{
	int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
	int expected = 4;
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字是最大的
void Test3()
{
	int numbers[] = { 4, 4, 1, 1, 1, 7, 4 };
	int expected = 7;
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test4()
{
	int expected = 0;
	Test("Test4", nullptr, 0, expected);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}


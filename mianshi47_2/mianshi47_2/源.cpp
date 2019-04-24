//无重复运算的迭代方法
#include<cstdio>
#include<algorithm>

using namespace std;

int getMaxValue1(const int* value, int rows, int cols)
{
	if (value == nullptr || rows <= 0 || cols <= 0)
		return 0;

	int** maxValue = new int*[rows];//二维创建！
	for (int i = 0; i < rows; ++i)
		maxValue[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int up_value = 0;
			int left_value = 0;

			if (i > 0)
				up_value = maxValue[i - 1][j];
			if (j > 0)
				left_value = maxValue[i][j - 1];

			maxValue[i][j] = max(up_value, left_value) + value[i*cols + j];
		}
	}

	int maxGet = maxValue[rows - 1][cols - 1];

	for (int i = 0; i < rows; ++i)//释放二维！
		delete[] maxValue[i];
	delete[] maxValue;

	return maxGet;
}

//优化，占用更少的辅助空间，主要思路：只保留一行的最值表，并对其不断进行更新
int getMaxValue2(const int* value, int rows, int cols)
{
	if (value == nullptr || rows <= 0 || cols <= 0)
		return 0;

	int* maxValue = new int[cols];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int up_value = 0;
			int left_value = 0;

			if (i > 0)
				up_value = maxValue[j];
			if (j > 0)
				left_value = maxValue[j - 1];

			maxValue[j] = max(up_value, left_value) + value[i*cols+j];
		}
	}

	int maxGet = maxValue[cols-1];

	delete[] maxValue;

	return maxGet;
}

void Test(const char*testname, const int* value, int row, int col, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	int result1 = getMaxValue1(value, row, col);
	int result2 = getMaxValue2(value, row, col);
	if (result1 == expected && result2==expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test1()
{
	const int value[] = { 1,2,3,4,5,6,7,8,9 };
	Test("test1", value, 3, 3, 29);
}

void test2()
{
	const int value[] = { 1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5 };
	Test("test2", value, 4, 4, 53);
}

void test3()
{
	const int value[] = { 1,10,3,8 };
	Test("test3", value, 1, 4, 22);
}

void test4()
{
	const int value[] = { 1,12,5,3 };
	Test("test4", value, 4, 1, 21);
}

void test5()
{
	const int value[] = { 3 };
	Test("test5", value, 1, 1, 3);
}

void test6()
{
	Test("test6", nullptr, 0, 0, 0);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	return 0;
}
//最原始的递归求解法
#include<cstdio>
#include<algorithm>//max头

using namespace std;//std::max

int getMaxValueCore(const int* value, int row, int col, int row_now, int col_now);

int getMaxValue(const int* value, int row, int col)
{
	if (value == nullptr || row <= 0 || col <= 0)
		return 0;

	int row_now = 1;
	int col_now = 1;
	return getMaxValueCore(value, row, col, row_now, col_now);
}

int getMaxValueCore(const int* value, int row, int col, int row_now, int col_now)
{
	if (row_now < row && col_now < col)
		return value[(row_now - 1)*col + col_now - 1] + max(getMaxValueCore(value, row, col, row_now + 1, col_now), getMaxValueCore(value, row, col, row_now, col_now + 1));
	if (row_now == row && col_now < col)
		return value[(row - 1)*col + col_now - 1] + getMaxValueCore(value, row, col, row_now, col_now + 1);
	if (row_now < row && col_now == col)
		return value[(row_now - 1)*col + col - 1] + getMaxValueCore(value, row, col, row_now + 1, col_now);
	if (row_now == row && col_now == col)
		return value[(row_now - 1)*col + col - 1];
}

void Test(const char*testname, const int* value, int row, int col,int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	int result = getMaxValue(value, row, col);
	if (result == expected)
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

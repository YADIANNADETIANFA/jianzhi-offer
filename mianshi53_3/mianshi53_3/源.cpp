// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
// 现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
// 1, 3, 5}中，数字3和它的下标相等。
#include<cstdio>

using namespace std;

int ValueEqualIndexCore(int*, int, int, int);
int ValueEqualIndex(int* data, int length)
{
	if (data == nullptr || length <= 0)
		return -1;
	int start = 0;
	int end = length - 1;
	return ValueEqualIndexCore(data, length, start, end);
}

int ValueEqualIndexCore(int* data, int length, int start, int end)
{
	if (start == end)
	{
		if (data[start] == start)
			return start;
		else
			return -1;
	}
	int middle = start + (end - start) / 2;
	if (data[middle] == middle)
		return middle;
	else if (data[middle] > middle)
	{
		if (middle == 0)
			return -1;
		else
			return ValueEqualIndexCore(data, length, start, middle - 1);
	}
	else
	{
		if (middle == length - 1)
			return -1;
		else
			return ValueEqualIndexCore(data, length, middle + 1, end);
	}
}

void Test(const char* testname, int* data, int length,int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = ValueEqualIndex(data, length);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test1()
{
	int data[]= { -3, -1, 1, 3, 5 };
	Test("test1", data, sizeof(data) / sizeof(int), 3);
}

void test2()
{
	int data[] = { 0, 1, 3, 5, 6 };
	Test("test2", data, sizeof(data) / sizeof(int), 0);
}

void test3()
{
	int data[] = { -1, 0, 1, 2, 4 };
	Test("test3", data, sizeof(data) / sizeof(int), 4);
}

void test4()
{
	int data[] = { -1, 0, 1, 2, 5 };
	Test("test4", data, sizeof(data) / sizeof(int), -1);
}

void test5()
{
	int data[] = { 0 };
	Test("test5", data, sizeof(data) / sizeof(int), 0);
}

void test6()
{
	int data[] = { 10 };
	Test("test6", data, sizeof(data) / sizeof(int), -1);
}

void test7()
{
	Test("test7", nullptr, 0, -1);
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

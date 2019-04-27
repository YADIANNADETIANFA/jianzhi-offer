// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。
#include<cstdio>

int FirstIndexCore(int*, int, int, int, int);
int LastIndexCore(int*, int, int, int, int);

int FirstIndex(int* data, int length, int k)
{
	int start = 0;
	int end = length - 1;
	return FirstIndexCore(data, length, start, end, k);
}
int FirstIndexCore(int* data, int length, int start, int end, int k)
{
	if (start == end && data[start] == k)//只剩一点，其他点均不行，那就只需考虑该点即可，不必考虑其他点了
		return start;
	else if(start==end)
		return -1;

	int middle = start + (end - start) / 2;
	if (data[middle] == k)
	{
		if (middle == 0)//middle是有机会取到两边极限值的
			return middle;
		else if (data[middle - 1] < k)
			return middle;
		else
			return FirstIndexCore(data, length, start, middle - 1, k);
	}
	else if (data[middle] > k)
		return FirstIndexCore(data, length, start, middle - 1, k);
	else
		return FirstIndexCore(data, length, middle + 1, end, k);
}

int LastIndex(int* data, int length, int k)
{
	int start = 0;
	int end = length - 1;
	return LastIndexCore(data, length, start, end, k);
}

int LastIndexCore(int* data, int length, int start, int end, int k)
{
	if (start == end && data[start] == k)
		return start;
	else if(start==end)
		return -1;

	int middle = start + (end - start) / 2;
	if (data[middle] == k)
	{
		if (middle == length - 1)
			return middle;
		else if (data[middle + 1] > k)
			return middle;
		else
			return LastIndexCore(data, length, middle+1, end, k);
	}
	else if (data[middle] > k)
		return LastIndexCore(data, length, start, middle-1, k);
	else
		return LastIndexCore(data, length, middle + 1, end, k);
}

int GetNum(int* data, int length, int k)
{
	if (data == nullptr || length <= 0 || k<data[0] || k>data[length - 1])//保证k在数组范围之内，k可以不在数组中，但是k必须在数组大小范围之内
		return 0;

	int startIndex = FirstIndex(data, length, k);
	int endIndex = LastIndex(data, length, k);

	if (startIndex >= 0 && endIndex >= 0)
		return endIndex - startIndex + 1;
	else
		return 0;
}


void Test(const char*testname, int* data, int length,int k, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = GetNum(data, length, k);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test1()
{
	int data[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
	Test("test1", data, sizeof(data) / sizeof(int), 3, 4);
}

void test2()
{
	int data[] = { 3, 3, 3, 3, 4, 5 };
	Test("test2", data, sizeof(data) / sizeof(int), 3, 4);
}

void test3()
{
	int data[] = { 1, 2, 3, 3, 3, 3 };
	Test("test3", data, sizeof(data) / sizeof(int), 3, 4);
}

void test4()
{
	int data[] = { 1, 3, 3, 3, 3, 4, 5 };
	Test("test4", data, sizeof(data) / sizeof(int), 2, 0);
}

void test5()
{
	int data[] = { 1, 3, 3, 3, 3, 4, 5 };
	Test("test5", data, sizeof(data) / sizeof(int), 0, 0);
}

void test6()
{
	int data[] = { 1, 3, 3, 3, 3, 4, 5 };
	Test("test6", data, sizeof(data) / sizeof(int), 0, 0);
}

void test7()
{
	int data[] = { 3, 3, 3, 3 };
	Test("test7", data, sizeof(data) / sizeof(int), 3, 4);
}

void test8()
{
	int data[] = { 3, 3, 3, 3 };
	Test("test8", data, sizeof(data) / sizeof(int), 4, 0);
}

void test9()
{
	int data[] = { 3 };
	Test("test9", data, sizeof(data) / sizeof(int), 3, 1);
}

void test10()
{
	int data[] = { 3 };
	Test("test10", data, sizeof(data) / sizeof(int), 4, 0);
}

void test11()
{
	Test("test11", nullptr, 0, 0, 0);
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
	test8();
	test9();
	test10();
	test11();

	return 0;
}

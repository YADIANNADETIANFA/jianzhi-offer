#include<cstdio>

using namespace std;

int theLostNumCore(int*, int, int, int);

int theLostNum(int* data, int length)//length为n的值；   n个数字，范围0~n-1，数组长度n-1，这三个关系不理清后面会乱的
{
	if (data == nullptr || length <= 1)
		return -1;

	//if (length == 1)//没办法表示int型的空数组。。。
	//	return 0;

	int start = 0;
	int end = length - 2;
	return theLostNumCore(data, length, start, end);
}

int theLostNumCore(int* data, int length, int start, int end)
{
	if (start == end)
	{
		if (data[start] == start + 1)
			return start;
		else if (start == length - 2)//{0 1 2 3 4}这样情况，最终会集中到4这一点，不能因为不满足data[start] == start + 1就return -1.因为这时是最后一点，要返回下一个未出现的点作为结果
			return start + 1;
		else
			return -1;

	}
	int middle = start + (end - start) / 2;
	if (data[middle] == middle + 1)
	{
		if (middle == 0)
			return 0;
		else if (data[middle - 1] == middle)
			return theLostNumCore(data, length, start, middle - 1);
		else if (data[middle - 1] == middle - 1)
			return middle;
	}
	else
		return theLostNumCore(data, length, middle + 1, end);
}

void Test(const char* testname, int* data, int length, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = theLostNum(data, length);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test1()
{
	int data[] = { 1,2,3,4,5 };
	Test("test1", data, sizeof(data) / sizeof(int) + 1, 0);
}

void test2()
{
	int data[] = { 0,1,2,3,4};
	Test("test2", data, sizeof(data) / sizeof(int) + 1, 5);
}

void test3()
{
	int data[] = { 0,1,2,4,5 };
	Test("test3", data, sizeof(data) / sizeof(int) + 1, 3);
}

void test4()
{
	int data[] = { 1 };
	Test("test4", data, sizeof(data) / sizeof(int) + 1, 0);
}

void test5()
{
	int data[] = { 0 };
	Test("test5", data, sizeof(data) / sizeof(int) + 1, 1);
}

void test6()
{
	Test("test6", nullptr, 0, -1);
}

/*void test7()
{
	int data[] = {};//表示出错，没办法表示空的int数组
	Test("test7", data, sizeof(data) / sizeof(int) + 1, 0);
}*/

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
// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
#include<cstdio>
#include<exception>

using namespace std;

void theNumPair(int* data, int length, int s,int& num1,int& num2)//与其让start和end两个指针传出来，不如在函数内部设立指针，而直接把num1和num2传出来，这样更简单不易出错！！！
{
	if (data == nullptr || length < 2)
		throw exception("Bad Parameter");//这里是不用return的！！！

	int i = 0;
	int j = length - 1;

	if (data[i] + data[j] == s)
	{
		num1 = data[i];
		num2 = data[j];
		return;
	}

	while (data[i] + data[j] != s)
	{
		while ((data[i] + data[j] > s) && (i != j - 1))
			j = j - 1;
		while ((data[i] + data[j] < s) && (i != j - 1))
			i = i + 1;
		if ((i == j - 1) && (data[i] + data[j] != s))
			throw exception("Bad Parameter");
	}
	num1 = data[i];
	num2 = data[j];
	return;
}

void Test(const char* testname, int* data, int length, int s)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int num1 = 0;
	int num2 = 0;
	try
	{
		theNumPair(data, length, s, num1, num2);
	}
	catch (exception& e)
	{
		printf("Bad Parameter\n");
		return;
	}
	printf("%d,%d\n", num1, num2);
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
	int data[] = { 1, 2, 4, 7, 11, 15 };
	Test("Test1", data, sizeof(data) / sizeof(int), 15 );
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test2", data, sizeof(data) / sizeof(int), 17 );
}

// 不存在和为s的两个数字
void Test3()
{
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test3", data, sizeof(data) / sizeof(int), 10 );
}

// 鲁棒性测试
void Test4()
{
	Test("Test4", nullptr, 0, 0 );
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}

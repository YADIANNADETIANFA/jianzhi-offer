// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个吃出现一次的数字。
#include<cstdio>
#include<exception>

using namespace std;//引用大法好

int theFirstDifferentBit(int* data, int length)//我们只考虑了0和正整数，没有考虑负数的情况
{
	if (data == nullptr || length <= 1)
		return -1;
	int resultXORAll = 0;
	for (int i = 0; i < length; ++i)
		resultXORAll ^= data[i];
	if (resultXORAll == 0)//即没有不同数字，数组内数字全相同
		return -1;
	else
	{
		int k = 1;
		while (resultXORAll != 1)
		{
			++k;
			resultXORAll = resultXORAll >> 1;
		}
		return k;
	}
}

void theDifferentNum(int* data, int length, int k, int& num1, int& num2)//返回两个值的，就用引用来完成
{
	if (k == -1)
		throw exception("Error Parameter");

	for (int i = 0; i < length; ++i)
	{
		if ((data[i] >> (k - 1)) & 1 == 1)//默认有且一定有两个不同的数字，不会出现只有一个不同数字，或者出现3个及以上不同数字的情况
			num1 ^= data[i];
		else
			num2 ^= data[i];
	}
}

void Test(const char* testname, int* data, int length,int expected1,int expected2)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int theFirstDifBit = theFirstDifferentBit(data, length);
	int num1 = 0;
	int num2 = 0;
	try
	{
		theDifferentNum(data, length, theFirstDifBit, num1, num2);
	}
	catch(exception& e)
	{
		printf("Error Parameter\n");
		return;//catch之后还是会继续执行后面的if语句的，所以在这里我们加return
	}
	if ((num1 == expected1 && num2 == expected2) || (num1 == expected2 && num2 == expected1))
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test1()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	Test("test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void test2()
{
	int data[] = { 4,6 };
	Test("test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void test3()
{
	int data[] = { 4,6,1,1,1,1 };//{ 4,6,1,1,1,1 }可以，但是{ 4,6,1,1,1 }不可以，因为3个1相互异或后结果是1，不是0！！即相同的数字必须成对出现该程序才适用
	Test("test3", data, sizeof(data) / sizeof(int), 4, 6);
}

void test4()
{
	int data[] = { 1,1,1,1 };
	Test("test4", data, sizeof(data) / sizeof(int), -1, -1);
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}

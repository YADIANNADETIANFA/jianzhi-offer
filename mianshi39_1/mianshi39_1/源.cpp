// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。
//方法1，缺点是要改变原数组
#include<cstdio>
#include<exception>
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

bool CheckInvalidArray(int* number, int length);
int Partition(int* number, int length, int start, int end);
bool CheckMoreThanHalf(int* number, int length, int result);
int RandomInRange(int start, int end);
void Swap(int* data1, int* data2);

int MoreThanHalfNum(int* number, int length)
{
	if (CheckInvalidArray(number, length))
		return 0;
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(number, length, start, end);

	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(number, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(number, length, start, end);
		}
	}

	int result = number[middle];
	if (!CheckMoreThanHalf(number, length, result))
		return 0;

	return result;
}

bool CheckInvalidArray(int* number, int length)
{
	if (number == nullptr || length <= 0)
		return true;

	return false;
}

bool CheckMoreThanHalf(int* number, int length, int result)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (number[i] == result)
			++times;
	}
	if (times * 2 > length)
		return true;

	return false;
}

int Partition(int* number, int length, int start, int end)
{
	if (number == nullptr || length <= 0 || start < 0 || end >= length)
		throw exception("Invalid Parameters");

	int index = RandomInRange(start, end);
	Swap(&number[index], &number[end]);
	int small = start-1;//small是start-1!!!!!不是-1!!!!!!
	for (index = start; index < end; ++index)
	{
		if (number[index] < number[end])
		{
			++small;
			if (small != index)
				Swap(&number[small], &number[index]);
		}
	}
	
	++small;
	Swap(&number[small], &number[end]);
	return small;
}

void Swap(int* data1, int* data2)
{
	int temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

int RandomInRange(int start, int end)
{
	if (start < end)
	{
		srand(time(NULL));
		return start + rand() % (end + 1 - start);
	}
	return start;
}

void Test(const char*testname, int* number,int length, int ExcepNum)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	try//try中局部变量在try外无法使用，解决方法：在任何函数内部不使用任何异常处理，而在调用处进行异常处理
	{
		int result = MoreThanHalfNum(number, length);
		if (result == ExcepNum)
			printf("Pass\n");
		else
			printf("Fail\n");

	}
	catch (exception& e)
	{
		printf("Invalid Parameters.\n");
	}
}

void test1()
{
	int number[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Test("test1", number, sizeof(number) / sizeof(int), 2);
}

void test2()
{
	int number[] = { 1, 2, 3, 2, 2, 3, 5, 4, 4 };
	Test("test2", number, sizeof(number) / sizeof(int), 0);
}

void test3()
{
	int number[] = { 2,2,2,2,2,1,3,4,5 };
	Test("test3", number, sizeof(number) / sizeof(int), 2);
}

void test4()
{
	int number[] = { 1,3,4,5,2,2,2,2,2 };
	Test("test4", number, sizeof(number) / sizeof(int), 2);
}

void test5()
{
	int number[] = { 2 };
	Test("test5", number, sizeof(number) / sizeof(int), 2);
}

void test6()
{
	Test("test6", nullptr, 0, 0);
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

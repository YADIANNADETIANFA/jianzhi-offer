// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
#include<cstdio>

int NumOfInverseCore(int*, int*, int, int);

int NumOfInverse(int*data, int length)
{
	if (data == nullptr || length <= 0)
		return 0;

	int* copy = new int[length];//默认初始化为0？,是乱码,要对其进行初始化；另外归并算法也需要对其进行赋初值
	for (int i = 0; i < length; ++i)
		copy[i] = data[i];

	int start = 0;
	int end = length - 1;

	int count = NumOfInverseCore(data, copy, start, end);
	delete[] copy;//面试的时候别忘了，不然炸了
	return count;
}

int NumOfInverseCore(int* data, int* copy, int start, int end)
{
	
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;
	int left = NumOfInverseCore(copy, data, start, start + length);//归并算法，两个容器相互交替着归并，见数据结构455
	int right = NumOfInverseCore(copy, data, start + length + 1, end);

	int i = start + length;
	int j = end;
	int count = 0;
	int copyIndex = end;
	while (i >= start && j >= start + length + 1)//这里设计的很精妙，学习一下
	{
		if (data[i] > data[j])
		{
			count += j - start - length;
			copy[copyIndex--] = data[i--];
		}
		else
		{
			copy[copyIndex--] = data[j--];
		}
	}

	if (i < start)//很明显，与for的条件相重复，可以省略；而且这两个for循环只有一个会被执行，因为跳出上面while循环只会有i、j其中一个不符合循环
	{
		for (; j >= start + length + 1; --j)
			copy[copyIndex--] = data[j];
	}
	if (j < start + length + 1)
	{
		for (; i >= start; --i)
			copy[copyIndex--] = data[i];
	}

	return left + right + count;
}

void Test(const char* testname, int* data, int length, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = NumOfInverse(data, length);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void Test1()
{
	int data[] = { 1, 2, 3, 4, 7, 6, 5 };
	int expected = 3;

	Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
	int data[] = { 6, 5, 4, 3, 2, 1 };
	int expected = 15;

	Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
	int data[] = { 1, 2, 3, 4, 5, 6 };
	int expected = 0;

	Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
	int data[] = { 1 };
	int expected = 0;

	Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
	int data[] = { 1, 2 };
	int expected = 0;

	Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
	int data[] = { 2, 1 };
	int expected = 1;

	Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
	int data[] = { 1, 2, 1, 2, 1 };
	int expected = 3;

	Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
	int expected = 0;

	Test("Test8", nullptr, 0, expected);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	return 0;
}

// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
#include<cstdio>
#include<exception>
using namespace std;

int MinInOrder(int*, int, int);
int Min(int* num, int length)
{
	if (num == nullptr || length <= 0)
		throw exception("Bad Parameters.");
	int index1 = 0;
	int index2 = length - 1;
	int mid = index1;
	while (num[index1] >= num[index2])
	{
		if (index2 - index1 == 1)
		{
			mid = index2;
			break;
		}
		mid = (index2 + index1) / 2;
		if (num[mid] > num[index2])
		{
			index1 = mid;
		}
		if (num[mid] < num[index2])
		{
			index2 = mid;
		}
		if (num[mid] == num[index2])
		{
			if (num[index1] == num[index2])
				return MinInOrder(num, index1, index2);
			index2 = mid;
		}
	}
	return num[mid];
}

int MinInOrder(int* num, int index1, int index2)
{
	int result = num[index1];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (result > num[i])
			result = num[i];
	}
	return result;
}

void Test(int* num, int length,int expected)
{
	try
	{
		int result = Min(num, length);
		if (result == expected)
			printf("Search Success.\n");
		else
			printf("Search Fail.\n");
	}
	catch (exception& e)
	{
		printf("Bad Parameters.\n");
	}
}
int main()
{
	int num1[] = { 3,4,5,1,2 };
	Test(num1, 5, 1);

	int num2[] = { 3,3,4,5,5,1,2,2 };
	Test(num2, 8, 1);

	int num3[] = { 1,2,3,4,5 };
	Test(num3, 5, 1);

	int num4[] = { 1 };
	Test(num4, 1, 1);

	Test(nullptr, 1, 1);

}

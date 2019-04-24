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
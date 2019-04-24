#include<iostream>

int CountNum(const int& start, const int& end, const int* a, const int& length);//先声明，不然会出现“CountNum找不到标识符”的报错
int getDuplication(const int *a, int length)
{
	if(a==nullptr || length<2)
	{
		return -1;
	}
	for (int i = 0; i < length; ++i)//强制使得没有重复数的话，直接返回-1
	{
		if (a[i] >= length || a[i] < 1)
		{
			return -1;
		}
	}
	//int middle = (length - 1) / 2;  //除法很慢
	int start = 1;
	int end = length - 1;
	while (end >= start)//>=还是>?
	{
		int middle = ((end - start) >> 1 )+ start;//测试，如果结果不是整数，移位结果是什么？,应该是取整值
		int num = CountNum(start, middle, a, length);
		if (middle - start + 1 < num)
		{
			end = middle;
		}
		else
		{
			start = middle;
		}
		if (start == end)
		{
			return num;
		}
	}
	
}
int CountNum(const int& start, const int& end, const int* a,const int& length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (a[i] >= start && a[i] <= end)
		{
			++count;
		}
	}
	return count;
}

void Test1()
{
	int a[8] = { 2,3,5,4,3,2,6,7 };
	int result = getDuplication(a, 8);
	printf("Expect result:%u or %u.\n", 2, 3);
	printf("The actual result:%u.\n", result);
}

void Test2()
{
	int a[8] = { 1,2,3,4,5,6,7,8 };
	int result = getDuplication(a, 8);
	printf("Expect result:%d.\n", -1);
	printf("The actual result:%d.\n", result);
}

void Test3()
{
	int* a = nullptr;
	int result = getDuplication(a, 2);
	printf("Expect result:%d.\n", -1);
	printf("The actual result:%d.\n", result);
}
int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}
// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
#include<cstdio>
#include<exception>

using namespace std;

void Print(int, int);

void PrintAllSequence(int s)
{
	if (s < 3)
		throw exception("Bad Parameter");
	int start = s / 2;
	int end = start + 1;
	int sum = start + end;

	if (sum == s)
		Print(start, end);

	while (start >= 1)
	{
		if (sum == s)
		{
			sum = sum + start - 1 + start - 2 - end;
			start -= 2;
			end -= 1;
			if (start >= 1 && sum == s)
				Print(start, end);
		}
		else if (sum < s)
		{
			sum = sum + start - 1;
			start -= 1;
			if (start >= 1 && sum == s)
				Print(start, end);
		}
		else if (sum > s && start != end - 1)//´ó2
		{
			sum = sum - end; 
			end -= 1;
			if (sum == s)
				Print(start, end);
		}
		else//´ó1
		{
			sum = sum + start - 1 - end;
			start -= 1;
			end -= 1;
			if (start >= 1 && sum == s)
				Print(start, end);
		}
	}
	return;
}

void Print(int start, int end)
{
	for (int i = start; i <= end; ++i)
	{
		printf("%d\t", i);
	}
	printf("\n");
}

void Test(const char* testname,int s)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	try
	{
		PrintAllSequence(s);
	}
	catch (exception& e)
	{
		printf("Bad Parameter\n");
		return;
	}
	return;
}

int main()
{
	Test("test1", 1);
	Test("test2", 3);
	Test("test3", 4);
	Test("test4", 9);
	Test("test5", 15);
	Test("test6", 100);

	return 0;
}

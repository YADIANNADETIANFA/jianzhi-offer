// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，
#include<cstdio>
#include<vector>
#include<deque>

using namespace std;

vector<int> maxInWindows(const vector<int>num, unsigned int size)//还可以返回vector<int>，学着点！
{
	vector<int> maxInWindows;//初始默认为空

	if (num.size() >= size && size > 0)
	{
		deque<int> index;
		for (int i = 0; i < size; ++i)
		{
			while (!index.empty() && num[i] >= num[index.front()])
				index.pop_back();
			index.push_back(i);
		}
		maxInWindows.push_back(num[index.front()]);

		for (int i = size; i < num.size(); ++i)
		{
			if (index.front() <= (i - size))
				index.pop_front();

			if (!index.empty() && num[i] >= num[index.front()])
			{
				if (!index.empty())
					index.clear();
				index.push_back(i);
				maxInWindows.push_back(num[index.front()]);
			}
			else if(!index.empty() && num[i]<num[index.front()])
			{
				maxInWindows.push_back(num[index.front()]);

				while (num[i] >= num[index.back()])
					index.pop_back();
				index.push_back(i);
			}
			else
			{
				index.push_back(i);
				maxInWindows.push_back(num[index.front()]);
			}
		}
	}
	return maxInWindows;
}

vector<int> Getvector(int* num, int size)
{
	vector<int> vectornum;
	for (int i = 0; i < size; ++i)
		vectornum.push_back(num[i]);

	return vectornum;
}
void Test(const char* testname, vector<int>& num, vector<int>& expected, unsigned int size)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	vector<int> result = maxInWindows(num, size);
	vector<int>::const_iterator iterResult = result.begin();
	vector<int>::const_iterator iterExpected = expected.begin();

	while (iterResult != result.end() && iterExpected != expected.end())//用迭代器来判断
	{
		if (*iterResult != *iterExpected)
		{
			printf("Fail\n");
			break;
		}
		++iterResult;
		++iterExpected;
	}
	printf("Pass\n");
}

void test1()
{
	int num[] = { 2,3,4,2,6,2,5,1 };
	vector<int> vectornum = Getvector(num, sizeof(num) / sizeof(int));
	
	int expected[] = { 4,4,6,6,6,5 };
	vector<int> vectorexp = Getvector(expected, sizeof(expected) / sizeof(int));

	unsigned int size = 3;

	Test("test1", vectornum, vectorexp, size);
	return;
}

void test2()
{
	int num[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
	vector<int> vectornum = Getvector(num, sizeof(num) / sizeof(int));

	int expected[] = { 3, 3, 5, 5, 6, 7 };
	vector<int> vectorexp = Getvector(expected, sizeof(expected) / sizeof(int));

	unsigned int size = 3;

	Test("test2", vectornum, vectorexp, size);
	return;
}

void test3()
{
	int num[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	vector<int> vectornum = Getvector(num, sizeof(num) / sizeof(int));

	int expected[] = { 7, 9, 11, 13, 15 };
	vector<int> vectorexp = Getvector(expected, sizeof(expected) / sizeof(int));

	unsigned int size = 4;

	Test("test3", vectornum, vectorexp, size);
	return;
}

void test4()
{
	int num[] = { 16, 14, 12, 10, 8, 6, 4 };
	vector<int> vectornum = Getvector(num, sizeof(num) / sizeof(int));

	int expected[] = { 16, 14, 12 };
	vector<int> vectorexp = Getvector(expected, sizeof(expected) / sizeof(int));

	unsigned int size = 5;

	Test("test4", vectornum, vectorexp, size);
	return;
}

void test5()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vectornum = Getvector(num, sizeof(num) / sizeof(int));

	int expected[] = { 10, 14, 12, 11 };
	vector<int> vectorexp = Getvector(expected, sizeof(expected) / sizeof(int));

	unsigned int size = 1;

	Test("test5", vectornum, vectorexp, size);
	return;
}

void test6()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vectornum = Getvector(num, sizeof(num) / sizeof(int));

	int expected[] = { 14};
	vector<int> vectorexp = Getvector(expected, sizeof(expected) / sizeof(int));

	unsigned int size = 4;

	Test("test6", vectornum, vectorexp, size);
	return;
}

void test7()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vectornum = Getvector(num, sizeof(num) / sizeof(int));
	vector<int> vectorexp;

	unsigned int size = 0;

	Test("test7", vectornum, vectorexp, size);
	return;
}

void test8()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vectornum = Getvector(num, sizeof(num) / sizeof(int));

	vector<int> vectorexp;

	unsigned int size = 5;

	Test("test8", vectornum, vectorexp, size);
	return;
}

void test9()
{

	vector<int> vectornum;


	vector<int> vectorexp;

	unsigned int size = 5;

	Test("test9", vectornum, vectorexp, size);
	return;
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

	return 0;
}


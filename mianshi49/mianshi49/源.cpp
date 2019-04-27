// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。
#include<cstdio>

int Min(int a, int b, int c)//a，b，c是否相等无所谓，只要得到最小值就行
{
	int small = 0;
	if (a < b)
		small = a;
	else
		small = b;
	if (small < c)
		return small;
	else
		return c;
}

int GettheUgly(int index)
{
	if (index <= 0)
		return 0;
	int* ptheUglyArray = new int[index];
	ptheUglyArray[0] = 1;
	int nextUglyIndex = 1;
	
	int* pMultiply2 = ptheUglyArray;
	int* pMultiply3 = ptheUglyArray;
	int* pMultiply5 = ptheUglyArray;

	while (nextUglyIndex < index)
	{
		int min_num = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		ptheUglyArray[nextUglyIndex] = min_num;

		if (min_num == *pMultiply2 * 2)
			++pMultiply2;//指针也可以这样++
		if (min_num == *pMultiply3 * 3)
			++pMultiply3;
		if (min_num == *pMultiply5 * 5)
			++pMultiply5;


		/*if (min_num == *pMultiply2 * 2)//注意，这里不可以使用else if，因为min_num == *pMultiply2 * 2 == *pMultiply3 * 3这种情况是存在的！！这样的话++pMultiply2与++pMultiply3都需要被执行！
			++pMultiply2;                //即存在值相等的情况，2*3=6,3*2=6.
		else if (min_num == *pMultiply3 * 3)
			++pMultiply3;
		else 
			++pMultiply5;*/

		++nextUglyIndex;
	}

	int ugly = ptheUglyArray[index - 1];
	delete[] ptheUglyArray;
	return ugly;
}

void Test(const char*testname, int index, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = GettheUgly(index);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	Test("test1",1, 1);
	Test("test2", 2, 2);
	Test("test3", 3, 3);
	Test("test4", 4, 4);
	Test("test5", 5, 5);
	Test("test6", 6, 6);
	Test("test7", 7, 8);
	Test("test8", 8, 9);
	Test("test9", 9, 10);
	Test("test10", 10, 12);
	Test("test11", 11, 15);
	Test("test12", 1500, 859963392);
	Test("test13", 0, 0);

	return 0;
}

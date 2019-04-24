#include<cstdio>

int Min(int a, int b, int c)//a��b��c�Ƿ��������ν��ֻҪ�õ���Сֵ����
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
			++pMultiply2;//ָ��Ҳ��������++
		if (min_num == *pMultiply3 * 3)
			++pMultiply3;
		if (min_num == *pMultiply5 * 5)
			++pMultiply5;


		/*if (min_num == *pMultiply2 * 2)//ע�⣬���ﲻ����ʹ��else if����Ϊmin_num == *pMultiply2 * 2 == *pMultiply3 * 3��������Ǵ��ڵģ��������Ļ�++pMultiply2��++pMultiply3����Ҫ��ִ�У�
			++pMultiply2;                //������ֵ��ȵ������2*3=6,3*2=6.
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
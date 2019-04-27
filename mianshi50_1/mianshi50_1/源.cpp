// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。
#include<cstdio>

char FirstShowExistOne(const char* pstring)//指向常量指针，即指针可以变化，但是指向的变量不能变，当然了，这里的const并不是必须的
{
	if (pstring == nullptr)
		return '\0';

	const int ListSize = 256;
	int* phashlist = new int[ListSize];
	for (int i = 0; i < ListSize; ++i)
		phashlist[i] = 0;

	const char* phashkey = pstring;
	while (*phashkey != '\0')
		phashlist[*(phashkey++)]++;//看好，这两种地方，都是可以使用++的

	//开始二次扫描该字符串
	phashkey = pstring;
	while (*phashkey != '\0')
	{
		if (phashlist[*phashkey] == 1)
			return *phashkey;
		else
			phashkey++;
	}
	return '\0';
}

void Test(const char* testname, const char* pstring, char expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	char result = FirstShowExistOne(pstring);
	if (result == expected)//这里两个char可以使用==,比较的是ASCII值
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	Test("test1", "google", 'l');
	Test("test2", "aabccdbd", '\0');
	Test("test3", "abcdefg", 'a');
	Test("test4", nullptr, '\0');

	return 0;
}

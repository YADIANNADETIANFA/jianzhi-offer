// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。
#include<cstdio>
#include<cstdlib>
#include<cstring>


const int g_MaxNumLength = 10;
char* g_strCombine1 = new char[g_MaxNumLength*2 + 1];
char* g_strCombine2 = new char[g_MaxNumLength*2 + 1];

int compare(const void* strNumber1, const void* strNumber2);

void PrintMinNumber(int* number, int length)
{
	if (number == nullptr || length <= 0)
		return;

	char** strNumber = new char*[length];//二维的

	for (int i = 0; i < length; ++i)
	{
		strNumber[i] = new char[g_MaxNumLength + 1];
		sprintf_s(strNumber[i], g_MaxNumLength + 1, "%u", number[i]);
	}

	qsort(strNumber, length, sizeof(strNumber[0]), compare);//和sort功能差不多，要记着

	for (int j = 0; j < length; ++j)
		printf("%s", strNumber[j]);
	printf("\n");

	for (int i = 0; i < length; ++i)//这里留意一下，要分别进行delete！！！！
		delete[] strNumber[i];
	delete[] strNumber;
}

int compare(const void* strNumber1, const void* strNumber2)
{
	strcpy_s(g_strCombine1, g_MaxNumLength * 2 + 1, *(const char**)strNumber1);//强制转换
	strcat_s(g_strCombine1, g_MaxNumLength * 2 + 1, *(const char**)strNumber2);

	strcpy_s(g_strCombine2, g_MaxNumLength * 2 + 1, *(const char**)strNumber2);
	strcat_s(g_strCombine2, g_MaxNumLength * 2 + 1, *(const char**)strNumber1);
	/*strcpy_s(g_strCombine1, g_MaxNumLength * 2 + 1, (const char*)strNumber1);//不知道为什么，这个就是不好使，先记着得了
	strcat_s(g_strCombine1, g_MaxNumLength * 2 + 1, (const char*)strNumber2);

	strcpy_s(g_strCombine2, g_MaxNumLength * 2 + 1, (const char*)strNumber2);
	strcat_s(g_strCombine2, g_MaxNumLength * 2 + 1, (const char*)strNumber1);*/

	return strcmp(g_strCombine1, g_strCombine2);
}

void Test(const char* testname, int* number, int length, const char* expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	printf("The expected result is:%s\n", expected);
	printf("The actual result is:");
	PrintMinNumber(number, length);
	printf("\n");
}

void test1()
{
	int number[] = { 3,5,1,4,2 };
	Test("test1", number, sizeof(number) / sizeof(int), "12345");
}

void test2()
{
	int number[] = { 3,32,321 };
	Test("test2", number, sizeof(number) / sizeof(int), "321323");
}

void test3()
{
	int number[] = { 3,323,32123 };
	Test("test3", number, sizeof(number) / sizeof(int), "321233233");
}

void test4()
{
	int number[] = { 1,11,111 };
	Test("test4", number, sizeof(number) / sizeof(int), "111111");
}

void test5()
{
	int number[] = { 321 };
	Test("test5", number, sizeof(number) / sizeof(int), "321");
}

void test6()
{
	Test("test6", nullptr, 0, "");
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

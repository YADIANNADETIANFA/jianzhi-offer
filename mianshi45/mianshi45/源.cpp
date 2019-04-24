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

	char** strNumber = new char*[length];//��ά��

	for (int i = 0; i < length; ++i)
	{
		strNumber[i] = new char[g_MaxNumLength + 1];
		sprintf_s(strNumber[i], g_MaxNumLength + 1, "%u", number[i]);
	}

	qsort(strNumber, length, sizeof(strNumber[0]), compare);//��sort���ܲ�࣬Ҫ����

	for (int j = 0; j < length; ++j)
		printf("%s", strNumber[j]);
	printf("\n");

	for (int i = 0; i < length; ++i)//��������һ�£�Ҫ�ֱ����delete��������
		delete[] strNumber[i];
	delete[] strNumber;
}

int compare(const void* strNumber1, const void* strNumber2)
{
	strcpy_s(g_strCombine1, g_MaxNumLength * 2 + 1, *(const char**)strNumber1);//ǿ��ת��
	strcat_s(g_strCombine1, g_MaxNumLength * 2 + 1, *(const char**)strNumber2);

	strcpy_s(g_strCombine2, g_MaxNumLength * 2 + 1, *(const char**)strNumber2);
	strcat_s(g_strCombine2, g_MaxNumLength * 2 + 1, *(const char**)strNumber1);
	/*strcpy_s(g_strCombine1, g_MaxNumLength * 2 + 1, (const char*)strNumber1);//��֪��Ϊʲô��������ǲ���ʹ���ȼ��ŵ���
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
#include<cstdio>

bool scanInteger(const char**);
bool scanUnsignedInteger(const char**);

bool isNumber(const char* str)
{
	if (str == nullptr)
		return false;

	bool numberic = scanInteger(&str);//�����÷�ʽ���ݺ� ** �ǲ�����ʲô����֮�����������˻�Ϊָ������ȥ�����һ��

	if (*str == '.')
	{
		++str;
		numberic = scanUnsignedInteger(&str) || numberic;
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		numberic = scanInteger(&str) && numberic;
	}
	return numberic && ((*str) == '\0');//����м���ʲô�����������ַ�������ͻ�ֱ�ӷ���һ��false
}

bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while ((**str) != '\0' && (**str) >= '0' && (**str) <= '9')
		++(*str);
	return (*str) > before;
}

bool scanInteger(const char** str)
{
	if ((**str) == '+' || (**str) == '-')
		++(*str);
	return scanUnsignedInteger(str);
}

void Test(const char* testname,const char* str,bool expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	if (isNumber(str) == expected)
		printf("Pass.\n");
	else
		printf("Fail.\n");
}

int main()
{
	Test("Test1", "100", true);
	Test("Test2", "123.45e+6", true);
	Test("Test3", "+500", true);
	Test("Test4", "5e2", true);
	Test("Test5", "3.1416", true);
	Test("Test6", "600.", true);
	Test("Test7", "-.123", true);
	Test("Test8", "-1E-16", true);
	Test("Test9", "1.79769313486232E+308", true);

	printf("\n\n");

	Test("Test10", "12e", false);
	Test("Test11", "1a3.14", false);
	Test("Test12", "1+23", false);
	Test("Test13", "1.2.3", false);
	Test("Test14", "+-5", false);
	Test("Test15", "12e+5.4", false);
	Test("Test16", ".", false);
	Test("Test17", ".e1", false);
	Test("Test18", "e1", false);
	Test("Test19", "+.", false);
	Test("Test20", "", false);
	Test("Test21", nullptr, false);
	return 0;
}
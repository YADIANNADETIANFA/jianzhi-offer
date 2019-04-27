// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是
#include<cstdio>

bool scanInteger(const char**);
bool scanUnsignedInteger(const char**);

bool isNumber(const char* str)
{
	if (str == nullptr)
		return false;

	bool numberic = scanInteger(&str);//按引用方式传递和 ** 是不是有什么相似之处；且数组退化为指针正好去配合这一点

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
	return numberic && ((*str) == '\0');//如果中间有什么其他无意义字符，这里就会直接返回一个false
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

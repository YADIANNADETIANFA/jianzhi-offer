#include<cstdio>
#include<cstring>//strlenͷ

using namespace std;

void Reverse(char* Begin, char* End)
{
	while (Begin < End)
	{
		char temp = *Begin;
		*Begin = *End;
		*End = temp;
		Begin++;
		End--;
	}
	return;
}

void ReverseSequence(char* str)
{
	if (str == nullptr || *str == '\0')
		return;

	char* Begin = str;
	char* End = str;
	while (*End != '\0')
		++End;
	--End;
	Reverse(Begin, End);

	while (*Begin != '\0')
	{
		if (*Begin == ' ')
			++Begin;
		End = Begin;
		while (*End != ' '&&*End != '\0')
			++End;
		--End;
		Reverse(Begin, End);
		Begin = End + 1;
	}
	return;
}

void LeftRotateStr(char* str, int n, int length)
{
	if (str == nullptr || *str == '\0' || n < 0 || length <= 0)
		return;
	char* Begin = str;
	char* End = str;
	while (*End != '\0')
		++End;
	--End;
	Reverse(Begin, End);
	int reverseIndex = n % length;
	End = Begin + length - reverseIndex - 1;
	Reverse(Begin, End);
	if (*(End + 1) != '\0')
		Reverse(End + 1, Begin + length - 1);
	return;
}



void Test(const char* testname, char* str1, char* str2, int n)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	if (str1 != nullptr)
		printf("Str1: %s\n", str1);
	else
		printf("Str1 is nullptr\n");

	ReverseSequence(str1);
	if (str1 != nullptr)
		printf("After ReverseSquence, Str1: %s\n", str1);
	else
		printf("After ReverseSquence, Str1 is nullptr\n");

	printf("\n");

	if (str2 != nullptr)
	{
		printf("Str2: %s\n", str2);
		int length = strlen(str2);
		LeftRotateStr(str2, n, length);
		printf("After LeftRotateStr, Str2: %s\n", str2);
	}
	else
	{
		int length = 0;
		printf("Str2 is nullptr\n");
		LeftRotateStr(str2, n, length);
		printf("After LeftRotateStr, Str2 is nullptr\n");
	}

}

void test1()
{
	char str1[] = "I am a student.";
	char str2[] = "abcdefg";//  2
	Test("test1", str1, str2, 2);
}

void test2()
{
	char str1[] = "Wonderful";
	char str2[] = "abcdefg";//  1
	Test("test2", str1, str2, 1);
}

void test3()
{
	//nullptr
	char str2[] = "abcdefg";//  6
	Test("test3", nullptr, str2, 6);
}

void test4()
{
	char str1[] = "";//""
	//nullptr
	Test("test4", str1, nullptr, 0);
}

void test5()
{
	char str1[] = "     ";
	char str2[] = "abcdefg";//  0
	Test("test5", str1, str2, 0);
}

void test6()
{
	char str1[] = "     ";
	char str2[] = "abcdefg";//  7
	Test("test6", str1, str2, 7);
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
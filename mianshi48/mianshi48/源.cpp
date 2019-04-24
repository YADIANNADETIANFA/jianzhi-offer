//有关答案的基本蛮力法，需要了解一下；另外，现在没那实力，打印出该字符串，只能得出长度值
//可以使用回溯法打印所有最长子字符串，即第一遍求出最大长度，第二遍已知最大长度逐个检查字符串，看是否无重复字符，如果没有重复字符，就打印出该字符串。回溯法!!!!!!
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int longestSubstringWithoutDuplication(const string& str)
{
	int currentLength = 0;
	int maxLength = 0;

	int* position = new int[26];
	for (int i = 0; i < 26; ++i)
		position[i] = -1;
	
	for (int i = 0; i < str.size(); ++i)
	{
		int preIndex = position[str[i] - 'a'];
		if (preIndex<0 || i - preIndex>currentLength)
			++currentLength;
		else
		{
			if (currentLength > maxLength)
				maxLength = currentLength;
			currentLength = i - preIndex;
		}
		position[str[i] - 'a'] = i;
	}
	if (currentLength > maxLength)
		maxLength = currentLength;
	delete[] position;
	return maxLength;
}

void test(const string& input, int expected)
{
	int output = longestSubstringWithoutDuplication(input);
	if (output == expected)
		cout << "Solution 1 passed, with input: " << input << endl;
	else
		cout << "Solution 1 FAILED, with input: " << input << endl;
}


void test1()
{
	const std::string input = "abcacfrar";
	int expected = 4;
	test(input, expected);
}

void test2()
{
	const std::string input = "acfrarabc";
	int expected = 4;
	test(input, expected);
}

void test3()
{
	const std::string input = "arabcacfr";
	int expected = 4;
	test(input, expected);
}

void test4()
{
	const std::string input = "aaaa";
	int expected = 1;
	test(input, expected);
}

void test5()
{
	const std::string input = "abcdefg";
	int expected = 7;
	test(input, expected);
}

void test6()
{
	const std::string input = "aaabbbccc";
	int expected = 2;
	test(input, expected);
}

void test7()
{
	const std::string input = "abcdcba";
	int expected = 4;
	test(input, expected);
}

void test8()
{
	const std::string input = "abcdaef";
	int expected = 6;
	test(input, expected);
}

void test9()
{
	const std::string input = "a";
	int expected = 1;
	test(input, expected);
}

void test10()
{
	const std::string input = "";
	int expected = 0;
	test(input, expected);
}

int main(int argc, char* argv[])
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
	test10();

	return 0;
}
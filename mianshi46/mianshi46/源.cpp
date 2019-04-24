#include<cstdio>
#include<string>

using namespace std;

void NumOfTranslation(string& numTostr, string::iterator Begin, string::iterator End, int& count);//string也是一种容器，而且这里最好加上引用

int GetTrans(int number)
{
	if (number < 0)
		return 0;
	string numTostr = to_string(number);//string使用std，to_string函数可用
	int count = 0;
	NumOfTranslation(numTostr, numTostr.begin(), numTostr.end(), count);
	return count;
}

void NumOfTranslation(string& numTostr, string::iterator Begin, string::iterator End, int& count)//递归求解
{
	if (Begin == End)
		return ;
	else if ((Begin + 1) == End)
	{
		++count;//什么时候翻译到了最好，即翻译完成了，count才+1
		return;
	}
	else if ((Begin + 2) == End)
	{
		NumOfTranslation(numTostr, Begin + 1, End, count);
		if (((*Begin - '0') * 10 + *(Begin + 1) - '0') <= 25 && (*Begin-'0') != 0)//约束条件有两个，一个是不超25，另一个是不能翻译 00 01 这样的两位字符
			++count;//同上，什么时候翻译到了最好，即翻译完成了，count才+1
		return;
	}
	else//((Begin + 2) < End)，也即后面还有两位以上的字符
	{
		NumOfTranslation(numTostr, Begin + 1, End, count);
		if (((*Begin - '0') * 10 + *(Begin + 1) - '0') <= 25 && (*Begin - '0') != 0)
			NumOfTranslation(numTostr, Begin + 2, End, count);
		return;
	}
}

void Test(const char* testname, int number, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	int result = GetTrans(number);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	Test("test1", 0, 1);
	Test("test2", 10, 2);
	Test("test3", 125, 3);
	Test("test4", 126, 2);
	Test("test5", 426, 1);
	Test("test6", 100, 2);
	Test("test7", 101, 2);
	Test("test8", 12258, 5);
	Test("test9", -100, 0);

	return 0;
}

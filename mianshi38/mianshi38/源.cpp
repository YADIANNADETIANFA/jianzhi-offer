#include<cstdio>
#include<iostream>
using namespace std;

void Permutation(char* pstr, char* pBegin);

void Permutation(char* pstr)
{
	if (pstr == nullptr)
		return;

	Permutation(pstr, pstr);
}

void Permutation(char* pstr, char* pBegin)
{
	if (*pBegin == '\0')
		printf("%s\n", pstr);
	else
	{
		for (char* ch = pBegin; *ch != '\0'; ++ch)
		{
			char temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
			Permutation(pstr, pBegin + 1);
			temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
		}
	}
}

void Test(const char*testname, char* pstr)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	Permutation(pstr);
	cout << endl;
}

void test1()
{
	//char* pstr[] = "abc";//会报错的，就算修改了属性 语言，程序也照样执行不了
	char pstr[] = "abc";//这里注意一下，char* pstr1 = "abc";定义出来的是个常量；而char pstr2[] = "abc";定义出来的是个数组。
	Test("test1", pstr);//pstr1指向字符常量区，不能改变其指向的内容；pstr2空间分配在堆栈上，可以对数组进行修改
}

void test2()
{
	char pstr[] = "aaa";
	Test("test2", pstr);
}

void test3()
{
	char pstr[] = "a";
	Test("test3", pstr);
}

void test4()
{
	char pstr[] = " ";
	Test("test4", pstr);
}

void test5()
{
	Test("test5", nullptr);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}

#include<cstdio>
#include<limits>

using namespace std;

class CharOperation
{
public:
	CharOperation() : index(0)
	{
		for (int i = 0; i < 256; ++i)
			charIndex[i] = -1;
	}

	void Insert(char ch)
	{
		if (charIndex[ch] == -1)
			charIndex[ch] = index;
		else if (charIndex[ch] >= 0)
			charIndex[ch] = -2;

		++index;
	}

	char FindFirstShow()
	{
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();//需要limits的头； 
		                                          //numeric_limits<double>::max () 是函数，返回编译器允许的 double 型数 最大值。
			                                      //类似的 numeric_limits<int>::max()  返回 编译器允许的 int 型数 最大值。
			                                      //需包含头文件  #include <limits>
		for (int i = 0; i < 256; ++i)
		{
			if (charIndex[i] >= 0 && charIndex[i] <= minIndex)
			{
				ch = (char)i;
				minIndex = charIndex[i];
			}
		}
		return ch;
	}
private:
	int index;
	int charIndex[256];
};

void Test(const char* testname, CharOperation Charstream, char expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	char result = Charstream.FindFirstShow();
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	CharOperation Charstream;

	Charstream.Insert('g');
	Test("test1", Charstream,  'g');

	Charstream.Insert('o');
	Test("test2", Charstream,  'g');

	Charstream.Insert('o');
	Test("test3", Charstream,  'g');

	Charstream.Insert('g');
	Test("test4", Charstream,  '\0');

	Charstream.Insert('l');
	Test("test5", Charstream,  'l');

	Charstream.Insert('e');
	Test("test6", Charstream,  'l');

	return 0;
}

/*void Test(const char* testname, CharOperation Charstream,char input, char expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

    Charstream.Insert(input);

	char result = Charstream.FindFirstShow();
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()//在Test里面实现Insert，其插入的对象是Charstream的拷贝，出了Test函数后该拷贝消失，原Charstream并未发生改变，所以里面永远只会有一个字符！
{
	CharOperation Charstream;

	
	Test("test1", Charstream,'g', 'g');

	
	Test("test2", Charstream,'o', 'g');

	
	Test("test3", Charstream,'o', 'g');

	
	Test("test4", Charstream,'g', '\0');

	
	Test("test5", Charstream,'l', 'l');

	
	Test("test6", Charstream,'e', 'l');

	return 0;
}*/
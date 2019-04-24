#include<iostream>
#include<cstdio>
using namespace std;

bool Increament(char*, int, int);
void PrintNumber(char*, int, int);


void Solution(int n)//ASCII表128个字符中可显示字符没有100个，一个字符做不到显示出1~99啊
{                       //除非我们自己造一个类似的字符表
	if (n <= 0)
		return;


	int even = 0;
	if (n & 1 == 1)
	{
		char* number = new char[((n + 1) >> 1) + 1];
		for (int i = 0; i <= ((n + 1) >> 1) - 1; ++i)
			number[i] = '!';
		number[(n + 1) >> 1] = '\0';
		while (!Increament(number, n, even))
		{
			PrintNumber(number, n, even);
		}
		delete[] number;
	}
	else
	{
		char*number = new char[(n >> 1) + 1];
		even = 1;
		for (int i = 0; i <= (n >> 1) - 1; ++i)
			number[i] = '!';
		number[n >> 1] = '\0';
		while (!Increament(number, n, even))
		{
			PrintNumber(number, n, even);
		}
		delete[] number;
	}

}

bool Increament(char* number, int n, int even)
{
	bool Overflow = false;
	int nTakeOver = 0;

	if (even == 1)
	{
		for (int i = (n >> 1) - 1; i >= 0; --i)
		{
			unsigned long Sum = number[i] - '!' + nTakeOver;
			if (i == (n >> 1) - 1)
				++Sum;
			if (Sum == 100)
			{
				if (i == 0)
					Overflow = true;
				nTakeOver = 1;
				Sum -= 100;
				number[i] = '!';
			}
			else
			{
				number[i] = '!' + Sum;
				break;
			}
		}
	}
	else
	{
		for (int i = ((n + 1) >> 1) - 1; i >= 0; --i)
		{
			unsigned long Sum = number[i] - '!' + nTakeOver;
			if (i == ((n + 1) >> 1) - 1)
			{
				++Sum;
			}
			if (Sum == 10 && i == 0)
				Overflow = true;
			if (Sum == 100)
			{
				nTakeOver = 1;
				Sum -= 100;
				number[i] = '!';
			}
			else
			{
				number[i] = '!' + Sum;
				break;
			}
		}
	}
	return Overflow;
}

void PrintNumber(char* number,int n, int even)
{
	if (even == 1)
	{
		int i = 0;
		while (number[i] == '!')
			++i;
		for (int j = i; j < (n >> 1); ++j)
			printf("%u", number[j] - '!');
		printf("\t");


	}
	else
	{
		int i = 0;
		while (number[i] == '!')
			++i;
		for (int j = i; j < ((n + 1) >> 1); ++j)
			printf("%u", number[j] - '!');
		printf("\t");
	}
}

void Test(const char*testname, int n)
{
	cout << testname << " begin,n=" << n << endl;
	cout << "Solution1: " << endl;
	Solution(n);
	cout << endl;
}

void test1()
{
	Test("test1", 1);
}

void test2()
{
	Test("test2", 2);
}

void test3()
{
	Test("test3", 3);
}

void test4()
{
	Test("test4", 0);
}

void test5()
{
	Test("test5", -1);
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
#include<cstdio>
#include<iostream>
using namespace std;

bool Increment(char*, int);
void PrintNumber(char*, int);
void Solution3Core(char*, int, int);

void Solution1(int n)
{
	if (n <= 0)
		return;
	int i = 0;
	int number = 1;
	while (i++ < n)
	{
		number = number * 10;
	}
	for (int j = 1; j < number; ++j)
		printf("%d\t", j);
}

void Solution2(int n)
{
	if (n <= 0)
		return;
	char*number = new char[n + 1];
	for (int i = 0; i < n; ++i)
		number[i] = '0';
	number[n] = '\0';

	while (!Increment(number, n))
		PrintNumber(number, n);
	delete[] number;
}

bool Increment(char* number, int n)
{
	bool Overflow = false;
	int nTakeover = 0;
	
	for (int i = n - 1; i >= 0; --i)
	{
		int value = number[i] - '0' + nTakeover;
		if (i == n - 1)
			++value;
		if (value == 10)
		{
			if (i == 0)
				Overflow = true;
			else
			{
				nTakeover = 1;
				value -= 10;
				number[i] = '0';
			}
			
		}
		else
		{
			number[i] = value + '0';
			break;
		}
	}
	return Overflow;
}

void PrintNumber(char* number, int n)//该函数只打印一个number
{
	int i = 0;
	while (number[i] == '0')
		++i;
	if (i == n)
		return;
	for (int j = i; j < n; ++j)
		printf("%c", number[j]);
	printf("\t");
}


void Solution3(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; ++i)
	{
		number[0] = '0' + i;
		Solution3Core(number, n, 1);
	}
	delete[] number;
}

void Solution3Core(char* number, int n, int index)
{
	if (index == n)
	{
		PrintNumber(number, n);
		return;
	}
	
	for (int i = 0; i < 10; ++i)
	{
		number[index] = '0' + i;
		Solution3Core(number, n, index + 1);
	}
}

void Test(const char*testname, int n)
{
	cout << testname << " begin,n=" <<n<< endl;
	cout << "Solution1: " << endl;
	Solution1(n);
	cout << endl;
	cout << "Solution2: " << endl;
	Solution2(n);
	cout << endl;
	cout << "Solution3: " << endl;
	Solution3(n);
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
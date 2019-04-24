#include<cmath>
#include<iostream>
using namespace std;

double Power_Of_Unsigned_exponent(double, unsigned);
bool equal(double, double);
bool InvalidInput = false;//全局变量，每个函数都调用得到
double Power(double base, int exponent)
{
	InvalidInput = false;//每次调用Power都重置一遍InvalidInput，省着test6开始的时候，InvalidInput用的还是test5的true！！！
	if (equal(base, 0.0) && exponent <= 0.0)
	{
		InvalidInput = true;
		return 0.0;
	}
	if (exponent < 0)
	{
		unsigned absolute_exponent = -exponent;
		double result = Power_Of_Unsigned_exponent(base, absolute_exponent);
		result = 1.0 / result;
		return result;
	}
	else
	{
		double result = Power_Of_Unsigned_exponent(base, exponent);
		return result;
	}
}

double Power_Of_Unsigned_exponent(double base, unsigned exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	if (exponent & 1 == 1)
	{
		double result = Power_Of_Unsigned_exponent(base, exponent >> 1);//exponent >> 1与exponent=exponent >> 1是两种不同的东西
			result = result * result*base;
			return result;
	}
	else
	{
		double result = Power_Of_Unsigned_exponent(base, exponent >> 1);
		result *= result;
		return result;
	}
}

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

void Test(const char* testname,double base, int exponent,double expectedResult,bool expectedFlag)
{
	double result = Power(base, exponent);
	if (equal(result, expectedResult) && InvalidInput==expectedFlag)
		cout << testname << ' ' << "Pass." << endl;
	else
		cout << testname << ' ' << "Fail." << endl;
}

void test1()
{
	Test("test1", 2, 3, 8, false);
}

void test2()
{
	Test("test2", -2, 3, -8, false);
}

void test3()
{
	Test("test3", 2, -3, 0.125, false);
}

void test4()
{
	Test("test4", 2, 0, 1, false);
}

void test5()
{
	Test("test5", 0, 0, 0, true);
}

void test6()
{
	Test("test6", 0, 4, 0, false);
}

void test7()
{
	Test("test7", 0, -4, 0, true);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}

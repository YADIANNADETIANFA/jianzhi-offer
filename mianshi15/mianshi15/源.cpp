// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
#include<cstdio>
using namespace std;

int NumberOf1_Solution1(int n)//将n直接向右移动，容易出现死循环
{
	int count = 0;
	while (n)
	{
		if (n & 1)
		{
			++count;
		}
		n = n >> 1;
	}
	return count;
}

int NumberOf1_Solution2(int n)//将校验位向左移动，直至移动16次清零
{
	int count = 0;
	unsigned int check = 1;
	while (check)
	{
		if (n & check)
		{
			++count;
		}
		check = check << 1;
	}
	return count;
}


int NumberOf1_Solution3(int n)//较完美的减一与运算，循环次数较少
{
	int count = 0;
	while (n)
	{
		++count;
		n = ((n - 1)&n);
	}
	return count;
}

/*int NumberOf1_Solution4(int n)//对n的正负分开考虑，至少优于方法2
{
	int count = 0;
	if (n >= 0)
	{
		while (n)
		{
			if (n & 1)
			{
				++count;
			}
			n = n >> 1;
		}
		return count;
	}
	else
	{
		
		int absolute_n = ~n;
		//++count;
		while (absolute_n)
		{
			if (absolute_n & 1)
			{
				++count;
			}
			absolute_n=absolute_n >> 1;
		}
		return count;
	}
}*/

void Test(int number, unsigned int expected)
{
	/*int actual = NumberOf1_Solution1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);*/

	int actual = NumberOf1_Solution2(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	actual = NumberOf1_Solution3(number);
	if (actual == expected)
		printf("Solution3: Test for %p passed.\n", number);
	else
		printf("Solution3: Test for %p failed.\n", number);

	/*actual = NumberOf1_Solution4(number);
	if (actual == expected)
		printf("Solution4: Test for %p passed.\n", number);
	else
		printf("Solution4: Test for %p failed.\n", number);*/

	printf("\n");
}

int main(int argc, char* argv[])
{
	// 输入0，期待的输出是0
	Test(0, 0);

	// 输入1，期待的输出是1
	Test(1, 1);

	// 输入10，期待的输出是2
	Test(10, 2);

	// 输入0x7FFFFFFF，期待的输出是31
	Test(0x7FFFFFFF, 31);

	// 输入0xFFFFFFFF（负数），期待的输出是32
	Test(0xFFFFFFFF, 32);//虽然是-1，却要输出补码的1的个数

	// 输入0x80000000（负数），期待的输出是1
	Test(0x80000000, 1);

	return 0;
}



/*#include <stdio.h>
int absolute_value(int num)
{
	if (num < 0)
	{
		num = ~(num - 1);
	}
	return num;
}
int main()
{
	printf("%d\n", absolute_value(5));
	printf("%d\n", absolute_value(-5));
	printf("%d\n", absolute_value(0));
	//return 0;
	int b = -5;
	int c = ~(b);
	printf("%d", c);
	return 0;
}*/






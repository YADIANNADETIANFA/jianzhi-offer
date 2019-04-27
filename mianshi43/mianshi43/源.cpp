// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。
#include<cstdio>
#include<cstring>//strlen头

using namespace std;

int NumberOf1(const char* strN);
int PowerBase10(int n);

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
		return 0;
	char strN[50];
	//sprintf(strN, "%d", n);
	sprintf_s(strN, "%d", n);//新版数字转字符串

	return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
	unsigned int length = strlen(strN);

	if (length == 1)//就一位的单独考虑
	{
		if ((*(strN)-'0') >= 1)
			return 1;
		else
			return 0;
	}
	//首先处理最高位
	int Sum = 0;
	if ((*(strN)-'0') > 1)
	{
		Sum+= PowerBase10(length - 1);//最高位大于1的情况，等于1满贯
	}
	else
	{
		++Sum;
		for (int i = 1; i < length; ++i)//最高位等于1的情况，等于后面数的个数再加1
			Sum += (*(strN + i) - '0')*PowerBase10(length - 1 - i);//要记得减去‘0’！！
	}
	//处理后面的非最高位
	for (int i = 1; i < length; ++i)
	{
		int forward_value = 0;//某一非最高位的前方
		int back_value = 0;//某一非最高位的后方

		for (int j = 0; j < i; ++j)
			forward_value += ((*(strN + j) - '0')*PowerBase10(i - j - 1));//前方有多少个数，该位就有多少个1的满贯
		if ((*(strN + i)-'0') > 1)//如果该位自己本身就大于1，则再加一个满贯
			++forward_value;
		else if ((*(strN + i) - '0') == 1)//如果该位自己本身等于1，则再加后面数的个数再加1
		{
			++back_value;
			for (int k = i+1; k < length; ++k)
				back_value += (*(strN + k) - '0')*PowerBase10(length - 1 - k);
		}
		Sum += forward_value * PowerBase10(length - i - 1)+back_value;
	}
	return Sum;
}

int PowerBase10(int n)
{
	int result = 1;
	while (n >= 1)
	{
		result *= 10;
		--n;
	}
	return result;
}

void Test(const char* testname, int n, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = NumberOf1Between1AndN(n);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");

}

int main()
{
	Test("test1", 1, 1);
	Test("test2", 5, 1);
	Test("test3", 10, 2);
	Test("test4", 55, 16);
	Test("test5", 99, 20);
	Test("test6", 10000, 4001);
	Test("test7", 21345, 18821);
	Test("test8", 0, 0);

	return 0;
}

// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。
#include<vector>
#include<cstdio>
using namespace std;

bool IsPopOrder(vector<int> pInput, vector<int> pOutput, int length)
{
	if (pInput.size() != pOutput.size() || length <= 0)
		return false;

	int num = length - 1;
	while (pInput[num] != pOutput[0])//根据栈的感觉，从后往前可能匹配的会快一点儿
	{                                 //找到第一个相等的值
		num -= 1;
		if (num < 0)
			return false;
	}

	int num_left = num;//对应好第一个相等的值后，接下来第二个output的值只能等于第一个input的值的左边一个值或右边一个值
	int num_right = num;
	int now_left = pOutput[0];//利用不重复性，将第一次对应成功的值作为后续的不可能取到的点
	int now_right = pOutput[0];

	if (num_left > 0)
	{
		num_left -= 1;//input左值左移
		now_left = pInput[num_left];
	}
	if (num_right < length - 1)
	{
		num_right += 1;//右值右移
		now_right = pInput[num_right];
	}

	for (int i = 1; i <= length - 1; ++i)//开始对应后续的几个值
	{
		if (pOutput[i] != now_left && pOutput[i] != now_right)
			return false;


		if (pOutput[i] == now_left)
		{
			if (i == length - 1)//output走到头了，即对应完了
				return true;
			if (num_left > 0)
			{
				num_left -= 1;
				now_left = pInput[num_left];
			}
			else
				now_left = pOutput[0];
		}

		if (pOutput[i] == now_right)
		{
			if (i == length - 1)//同上
				return true;
			if (num_right < length - 1)
			{
				num_right += 1;
				now_right = pInput[num_right];
			}
			else
				now_right = pOutput[0];
		}
	}
	return true;
}

void Test(const char* testname, vector<int> pInput, vector<int> pOutput, int length,bool expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	bool result = IsPopOrder(pInput, pOutput, length);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");

}

void test1()
{
	vector<int> pInput = { 1,2,3,4,5 };
	vector<int> pOutput = { 4,5,3,2,1 };
	Test("test1", pInput, pOutput, 5, true);
}

void test2()
{
	vector<int> pInput = { 1,2,3,4,5 };
	vector<int> pOutput = { 4,5,3,1,2 };
	Test("test2", pInput, pOutput, 5, false);
}

void test3()
{
	vector<int> pInput;
	vector<int> pOutput;
	Test("test3", pInput, pOutput, 0, false);
}

void test4()
{
	vector<int> pInput = { 1,2,3,4 };
	vector<int> pOutput = { 4,5,3,2,1 };
	Test("test4", pInput, pOutput, 4, false);
}

void test5()
{
	vector<int> pInput = {1};
	vector<int> pOutput = {1};
	Test("test5", pInput, pOutput, 1, true);
}

void test6()
{
	vector<int> pInput = { 1 };
	vector<int> pOutput = { 2 };
	Test("test6", pInput, pOutput, 1, false);
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

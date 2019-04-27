// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
#include<cstdio>
#include"BinaryTreeNode.h"
#include<iostream>
using namespace std;

bool VerifySequenceOfBST(int sequence[], int length)
{
	if (length < 0)//参数非法
		return false;
	if (sequence == nullptr || length == 0)//如果子树为空，返回true
		return true;

	if (sequence != nullptr && length == 1)//如果子树就一个点就无需再向下递归了，返回true
		return true;

	int Root = sequence[length - 1];
	int* left_sequence = new int[length]();
	int* right_sequence = new int[length]();
	int left_length = 0;
	int right_length = 0;

	int i = 0;
	while (sequence[i] < Root && i < length - 1)
	{
		left_sequence[i] = sequence[i];
		++left_length;
		++i;
	}

	while (sequence[i] > Root && i < length - 1)
	{
		right_sequence[i - left_length] = sequence[i];
		++right_length;
		++i;
	}

	if (i != length - 1)
		return false;
	else
	{
		bool left_tree = VerifySequenceOfBST(left_sequence, left_length);
		bool right_tree = VerifySequenceOfBST(right_sequence, right_length);
		return(left_tree && right_tree);
	}

	delete[] left_sequence;
	delete[] right_sequence;
}

void test1()
{
	printf("test1 begin:\n");
	int sequence[] = { 4,8,6,12,16,14,10 };
	bool result = VerifySequenceOfBST(sequence, 7);
	if (result == true)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test2()
{
	printf("test2 begin:\n");
	int sequence[] = { 4,6,7,5 };
	bool result = VerifySequenceOfBST(sequence, 4);
	if (result == true)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test3()
{
	printf("test3 begin:\n");
	int sequence[] = { 1,2,3,4,5 };
	bool result = VerifySequenceOfBST(sequence, 5);
	if (result == true)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test4()
{
	printf("test4 begin:\n");
	int sequence[] = { 5,4,3,2,1 };
	bool result = VerifySequenceOfBST(sequence, 5);
	if (result == true)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test5()
{
	printf("test5 begin:\n");
	int sequence[] = { 5 };
	bool result = VerifySequenceOfBST(sequence, 1);
	if (result == true)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test6()
{
	printf("test6 begin:\n");
	int sequence[] = { 7,4,6,5 };
	bool result = VerifySequenceOfBST(sequence, 4);
	if (result == false)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test7()
{
	printf("test7 begin:\n");
	int sequence[] = { 4,6,12,8,16,14,10 };
	bool result = VerifySequenceOfBST(sequence, 7);
	if (result == false)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test8()
{
	printf("test8 begin:\n");
	bool result = VerifySequenceOfBST(nullptr, 0);
	if (result == true)
		printf("Pass\n");
	else
		printf("Fail\n");
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
	test8();
	return 0;
}

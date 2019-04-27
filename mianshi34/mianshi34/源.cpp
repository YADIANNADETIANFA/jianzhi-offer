// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
#include<cstdio>
#include<iostream>
#include<vector>
#include"BinaryTreeNode.h"
using namespace std;

void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum);

BinaryTreeNode* ConstructTree(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->p_left = nullptr;
	pNode->p_right = nullptr;

	return pNode;
}

void ConnectNodes(BinaryTreeNode* pRoot, BinaryTreeNode* pleft, BinaryTreeNode* pright)
{
	if (pRoot == nullptr)
		return;

	pRoot->p_left = pleft;
	pRoot->p_right = pright;
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	BinaryTreeNode* pleft = pRoot->p_left;
	BinaryTreeNode* pright = pRoot->p_right;

	delete pRoot;
	pRoot = nullptr;

	DestroyTree(pleft);
	DestroyTree(pright);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
		return;
	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum)
{
	currentSum += pRoot->m_value;
	path.push_back(pRoot->m_value);
	bool isLeaf = (pRoot->p_left == nullptr) && (pRoot->p_right == nullptr);
	if (isLeaf && currentSum == expectedSum)
	{
		printf("A path is found:");
		vector<int>::iterator it1 = path.begin();//C++Primer有关于迭代器类型的说明
		for (; it1 != path.end(); ++it1)
			printf("%d\t", *it1);
		cout << endl;
	}
	if (pRoot->p_left != nullptr)
		FindPath(pRoot->p_left, expectedSum, path, currentSum);
	if (pRoot->p_right != nullptr)
		FindPath(pRoot->p_right, expectedSum, path, currentSum);

	path.pop_back();
}

void Test(const char* testname, BinaryTreeNode* pRoot,int expectedSum)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	FindPath(pRoot, expectedSum);
	cout << endl;
}

void test1()
{
	BinaryTreeNode* pNode10 = ConstructTree(10);
	BinaryTreeNode* pNode5 = ConstructTree(5);
	BinaryTreeNode* pNode12 = ConstructTree(12);
	BinaryTreeNode* pNode4 = ConstructTree(4);
	BinaryTreeNode* pNode7 = ConstructTree(7);

	ConnectNodes(pNode10, pNode5, pNode12);
	ConnectNodes(pNode5, pNode4, pNode7);

	printf("Two paths shoule be found in test1\n");

	Test("test1", pNode10, 22);
	DestroyTree(pNode10);

}

void test2()
{
	BinaryTreeNode* pNode10 = ConstructTree(10);
	BinaryTreeNode* pNode5 = ConstructTree(5);
	BinaryTreeNode* pNode12 = ConstructTree(12);
	BinaryTreeNode* pNode4 = ConstructTree(4);
	BinaryTreeNode* pNode7 = ConstructTree(7);

	ConnectNodes(pNode10, pNode5, pNode12);
	ConnectNodes(pNode5, pNode4, pNode7);

	printf("No path shoule be found in test2\n");

	Test("test2", pNode10, 15);
	DestroyTree(pNode10);

}

void test3()
{
	BinaryTreeNode* pNode5 = ConstructTree(5);
	BinaryTreeNode* pNode4 = ConstructTree(4);
	BinaryTreeNode* pNode3 = ConstructTree(3);
	BinaryTreeNode* pNode2 = ConstructTree(2);
	BinaryTreeNode* pNode1 = ConstructTree(1);

	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);
	ConnectNodes(pNode2, pNode1, nullptr);

	printf("One path shoule be found in test3\n");

	Test("test3", pNode5, 15);
	DestroyTree(pNode5);

}

void test4()
{
	BinaryTreeNode* pNode1 = ConstructTree(1);
	BinaryTreeNode* pNode2 = ConstructTree(2);
	BinaryTreeNode* pNode3 = ConstructTree(3);
	BinaryTreeNode* pNode4 = ConstructTree(4);
	BinaryTreeNode* pNode5 = ConstructTree(5);

	ConnectNodes(pNode1, pNode2, nullptr);
	ConnectNodes(pNode2, pNode3, nullptr);
	ConnectNodes(pNode3, pNode4, nullptr);
	ConnectNodes(pNode4, pNode5, nullptr);

	printf("No path shoule be found in test4\n");

	Test("test4", pNode1, 16);
	DestroyTree(pNode1);

}

void test5()
{
	BinaryTreeNode* pNode1 = ConstructTree(1);

	printf("One path shoule be found in test5\n");

	Test("test5", pNode1, 1);
	DestroyTree(pNode1);

}

void test6()
{

	printf("No path shoule be found in test6\n");

	Test("test6", nullptr, 0);

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

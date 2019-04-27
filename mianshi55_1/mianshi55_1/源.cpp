// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
#include<cstdio>
#include"BinaryTreeNode.h"

using namespace std;

BinaryTreeNode* ConstructNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

void ConnectNodes(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;
	else
	{
		pRoot->pLeft = pLeft;
		pRoot->pRight = pRight;
	}
}
void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	else
	{
		DestroyTree(pRoot->pLeft);
		DestroyTree(pRoot->pRight);
		delete pRoot;
		pRoot = nullptr;
	}
}

int TheDepth(BinaryTreeNode* pRoot) 
{
	if (pRoot == nullptr)
		return 0;
	int left = TheDepth(pRoot->pLeft);
	int right = TheDepth(pRoot->pRight);

	return (left > right) ? (left + 1) : (right + 1);
}

void Test(const char* testname, BinaryTreeNode* pRoot, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = TheDepth(pRoot);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test1()
{
	BinaryTreeNode* pNode1 = ConstructNode(1);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode6 = ConstructNode(6);
	BinaryTreeNode* pNode7 = ConstructNode(7);

	ConnectNodes(pNode1, pNode2, pNode3);
	ConnectNodes(pNode2, pNode4, pNode5);
	ConnectNodes(pNode3, nullptr, pNode6);
	ConnectNodes(pNode5, pNode7, nullptr);

	Test("Test1", pNode1, 4);

	DestroyTree(pNode1);
}

void test2()
{
	BinaryTreeNode* pNode1 = ConstructNode(1);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode5 = ConstructNode(5);

	ConnectNodes(pNode1, pNode2, nullptr);
	ConnectNodes(pNode2, pNode3, nullptr);
	ConnectNodes(pNode3, pNode4, nullptr);
	ConnectNodes(pNode4, pNode5, nullptr);

	Test("Test2", pNode1, 5);

	DestroyTree(pNode1);
}

void test3()
{
	BinaryTreeNode* pNode1 = ConstructNode(1);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode5 = ConstructNode(5);

	ConnectNodes(pNode1, nullptr, pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode5);

	Test("Test3", pNode1, 5);

	DestroyTree(pNode1);
}


void test4()
{
	BinaryTreeNode* pNode1 = ConstructNode(1);
	Test("Test4", pNode1, 1);

	DestroyTree(pNode1);
}


void test5()
{
	Test("Test5", nullptr, 0);
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

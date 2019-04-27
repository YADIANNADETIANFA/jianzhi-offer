// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
#include<cstdio>
#include<iostream>
#include<stack>
#include"Binary_TreeNode.h"
using namespace std;

void MirrorRecursively(Binary_TreeNode* pRoot)//递归方式
{
	if (pRoot == nullptr)
		return;

	Binary_TreeNode* pNode = pRoot->m_pleft;
	pRoot->m_pleft = pRoot->m_pright;
	pRoot->m_pright = pNode;

	MirrorRecursively(pRoot->m_pleft);
	MirrorRecursively(pRoot->m_pright);
}

Binary_TreeNode* ConstructNode(double value)
{
	Binary_TreeNode* pNode = new Binary_TreeNode();
	pNode->m_value = value;
	pNode->m_pleft = nullptr;
	pNode->m_pright = nullptr;

	return pNode;
}

void MirrorIteratively(Binary_TreeNode* pRoot)//对应的迭代方式
{
	if (pRoot == nullptr)
		return;

	stack<Binary_TreeNode*> stackTreeNode;//头文件stack
	stackTreeNode.push(pRoot);

	while (stackTreeNode.size() > 0)
	{
		Binary_TreeNode* pNode = stackTreeNode.top();
		stackTreeNode.pop();
		Binary_TreeNode* ptemp = pNode->m_pleft;
		pNode->m_pleft = pNode->m_pright;
		pNode->m_pright = ptemp;

		if (!pNode->m_pleft)
			stackTreeNode.push(pNode->m_pleft);
		if (!pNode->m_pright)
			stackTreeNode.push(pNode->m_pright);
	}
}



void ConnectNodes(Binary_TreeNode* pRoot, Binary_TreeNode* pleft, Binary_TreeNode* pright)
{
	if (pRoot != nullptr)
	{
		pRoot->m_pleft = pleft;
		pRoot->m_pright = pright;
	}
}

void DestroyTree(Binary_TreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		Binary_TreeNode* pleft = pRoot->m_pleft;//和之前一样，在这里pleft和pright已经是相对独立的存在
		Binary_TreeNode* pright = pRoot->m_pright;

		delete pRoot;//故不会受到这里的影响
		pRoot = nullptr;

		DestroyTree(pleft);
		DestroyTree(pright);
	}
}

void PrintPreorder(Binary_TreeNode* pRoot)//前序画出二叉树
{
	if (pRoot != nullptr)
	{
		cout << pRoot->m_value << " ";
		PrintPreorder(pRoot->m_pleft);
		PrintPreorder(pRoot->m_pright);
	}
	else
		return;
}

void Test(const char* testname, Binary_TreeNode* pRoot)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	printf("The original Tree:\n");//正序
	PrintPreorder(pRoot);
	cout << endl;
	printf("After MirrorRecursively:\n");//镜像
	MirrorRecursively(pRoot);
	PrintPreorder(pRoot);
	cout << endl;
	printf("After MirrorIteratively:\n");//再次被调回为正序
	MirrorRecursively(pRoot);
	PrintPreorder(pRoot);
	cout << endl;
	
}

void test1()
{
	Binary_TreeNode* pNode8 = ConstructNode(8);
	Binary_TreeNode* pNode6 = ConstructNode(6);
	Binary_TreeNode* pNode10 = ConstructNode(10);
	Binary_TreeNode* pNode5 = ConstructNode(5);
	Binary_TreeNode* pNode7 = ConstructNode(7);
	Binary_TreeNode* pNode9 = ConstructNode(9);
	Binary_TreeNode* pNode11 = ConstructNode(11);

	ConnectNodes(pNode8, pNode6, pNode10);
	ConnectNodes(pNode6, pNode5, pNode7);
	ConnectNodes(pNode10, pNode9, pNode11);

	Test("test1", pNode8);

	DestroyTree(pNode8);
}

void test2()
{
	Binary_TreeNode* pNode8 = ConstructNode(8);
	Binary_TreeNode* pNode7 = ConstructNode(7);
	Binary_TreeNode* pNode6 = ConstructNode(6);
	Binary_TreeNode* pNode5 = ConstructNode(5);
	Binary_TreeNode* pNode4 = ConstructNode(4);

	ConnectNodes(pNode8, pNode7, nullptr);
	ConnectNodes(pNode7, pNode6, nullptr);
	ConnectNodes(pNode6, pNode5, nullptr);
	ConnectNodes(pNode5, pNode4, nullptr);

	Test("test2", pNode8);

	DestroyTree(pNode8);
}

void test3()
{
	Binary_TreeNode* pNode8 = ConstructNode(8);
	Binary_TreeNode* pNode7 = ConstructNode(7);
	Binary_TreeNode* pNode6 = ConstructNode(6);
	Binary_TreeNode* pNode5 = ConstructNode(5);
	Binary_TreeNode* pNode4 = ConstructNode(4);

	ConnectNodes(pNode8, nullptr, pNode7);
	ConnectNodes(pNode7, nullptr, pNode6);
	ConnectNodes(pNode6, nullptr, pNode5);
	ConnectNodes(pNode5, nullptr, pNode4);

	Test("test3", pNode8);

	DestroyTree(pNode8);
}

void test4()
{
	Test("test4", nullptr);
}

void test5()
{
	Binary_TreeNode* pNode8 = ConstructNode(8);

	Test("test5", pNode8);

	DestroyTree(pNode8);
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





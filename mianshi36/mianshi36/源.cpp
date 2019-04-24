#include<cstdio>
#include<iostream>
#include"BinaryTreeNode.h"
using namespace std;


void ConvertNode(BinaryTreeNode* pRoot, BinaryTreeNode** pLastNodeInList);

BinaryTreeNode* ConstructNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->m_pleft = nullptr;
	pNode->m_right = nullptr;

	return pNode;
}

void ConnectNodes(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (!pRoot)
		return;
	pRoot->m_pleft = pLeft;
	pRoot->m_right = pRight;
}

void PriMidOrder(BinaryTreeNode* pRoot)
{
	if (!pRoot)
		return;

	PriMidOrder(pRoot->m_pleft);
	printf("%d\t", pRoot->m_value);
	PriMidOrder(pRoot->m_right);
}

void DestroyList(BinaryTreeNode* pRoot)//树的结构已被改变，要删除的是链表的结构
{
	if (!pRoot)
		return;
	                       //作用的有pRoot，pNode，pNext三个量，两个玩不来的
	BinaryTreeNode* pNode = pRoot->m_right;//我们设计的是左连之前的，右连之后的
	delete pRoot;
	pRoot = nullptr;
	while (pNode)
	{
		BinaryTreeNode* pNext = pNode->m_right;
		delete pNode;
		pNode = pNext;
	}
}

BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pLastNodeInList = nullptr;
	ConvertNode(pRoot, &pLastNodeInList);

	BinaryTreeNode* pHeadOfList = pLastNodeInList;//得到的是最尾巴，我们逆流而上找到头部
	while (pHeadOfList != nullptr && pHeadOfList->m_pleft != nullptr)
		pHeadOfList = pHeadOfList->m_pleft;
	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pRoot, BinaryTreeNode** pLastNodeInList)
{
	if (pRoot == nullptr)
		return;
	BinaryTreeNode* pCurrent = pRoot;

	if (pCurrent->m_pleft != nullptr)//1部分
		ConvertNode(pCurrent->m_pleft, pLastNodeInList);

	pCurrent->m_pleft = *pLastNodeInList;//2部分
	if (*pLastNodeInList != nullptr)
		(*pLastNodeInList)->m_right = pCurrent;
	*pLastNodeInList = pCurrent;

	if (pCurrent->m_right != nullptr)//3部分
		ConvertNode(pCurrent->m_right, pLastNodeInList);
}

void PrintDoubleLinkedList(BinaryTreeNode* pRoot)
{
	printf("The nodes from left to right are:\n");
	BinaryTreeNode* pNode = pRoot;
	while (pNode)
	{
		printf("%d\t", pNode->m_value);
		if (pNode->m_right == nullptr)//很精妙，为了后续pNode的使用，防止pNode跑到nullptr的位置!!!
			break;
		pNode = pNode->m_right;
	}
	cout << endl;

	printf("The nodes from right to left are:\n");
	while (pNode)//直接使用前面的pNode!!!
	{
		printf("%d\t", pNode->m_value);
		if (pNode->m_pleft == nullptr)
			break;
		pNode = pNode->m_pleft;
	}
	cout << endl;
}

void Test(const char* testname, BinaryTreeNode* pRoot)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	printf("Print PreOrderTree:\n");
	PriMidOrder(pRoot);
	cout << endl;

	BinaryTreeNode* pHeadList = Convert(pRoot);
	PrintDoubleLinkedList(pHeadList);
}

void test1()
{
	BinaryTreeNode* pNode10 = ConstructNode(10);
	BinaryTreeNode* pNode6 = ConstructNode(6);
	BinaryTreeNode* pNode14 = ConstructNode(14);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode8 = ConstructNode(8);
	BinaryTreeNode* pNode12 = ConstructNode(12);
	BinaryTreeNode* pNode16 = ConstructNode(16);

	ConnectNodes(pNode10, pNode6, pNode14);
	ConnectNodes(pNode6, pNode4, pNode8);
	ConnectNodes(pNode14, pNode12, pNode16);

	Test("test1", pNode10);

	DestroyList(pNode10);
}

void test2()
{
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode1 = ConstructNode(1);


	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);
	ConnectNodes(pNode2, pNode1, nullptr);

	Test("test2", pNode5);

	DestroyList(pNode5);
}

void test3()
{
	BinaryTreeNode* pNode1 = ConstructNode(1);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode5 = ConstructNode(5);


	ConnectNodes(pNode1, nullptr,pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode5);

	Test("test3", pNode1);

	DestroyList(pNode1);
}

void test4()
{
	BinaryTreeNode* pNode1 = ConstructNode(1);

	Test("test4", pNode1);

	DestroyList(pNode1);
}

void test5()
{

	Test("test5", nullptr);

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


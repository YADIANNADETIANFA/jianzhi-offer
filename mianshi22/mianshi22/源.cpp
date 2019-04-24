#include"ListNode.h"
#include<cstdio>
#include<iostream>
using namespace std;

ListNode* CreateNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_value = value;
	pNode->m_pNext = nullptr;
	return pNode;
}

void ConnectedNodes(ListNode* p1, ListNode* p2)
{
	if (p1 == nullptr)
	{
		printf("Error Parameters.\n");
		exit(1);
	}
	else
	{
		p1->m_pNext = p2;
	}
}

void PrintList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	printf("Print start:\n");
	if (pNode == nullptr)
		return;
	else
	{
		while (pNode != nullptr)
		{
			printf("%d\t", pNode->m_value);
			pNode = pNode->m_pNext;
		}
		printf("Print end.\n");
	}
}

void DestroyList(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

ListNode* FindKthToTail(ListNode* pHead, unsigned k)//两个指针搞定一切
{
	if (pHead == nullptr || k == 0)
		return nullptr;
	ListNode* pFirst = pHead;
	ListNode* pSecond = nullptr;
	for (int i = 1; i < k; ++i)
	{
		if (pFirst->m_pNext != nullptr)
			pFirst = pFirst->m_pNext;
		else
			return nullptr;
	}

	pSecond = pHead;
	while (pFirst->m_pNext != nullptr)
	{
		pFirst = pFirst->m_pNext;
		pSecond = pSecond->m_pNext;
	}
	return pSecond;
}

void Test(const char*testname, ListNode* pHead, unsigned k,int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	ListNode* pNode = FindKthToTail(pHead, k);
	if (pNode == nullptr)
	{
		printf("Error Parameter.\n");
		return;
	}
	if (pNode->m_value == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
	cout << endl;
}

void test1()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode2 = CreateNode(2);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode4 = CreateNode(4);
	ListNode* pNode5 = CreateNode(5);

	ConnectedNodes(pNode1, pNode2);
	ConnectedNodes(pNode2, pNode3);
	ConnectedNodes(pNode3, pNode4);
	ConnectedNodes(pNode4, pNode5);

	Test("test1", pNode1, 2, 4);

	DestroyList(pNode1);
}

void test2()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode2 = CreateNode(2);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode4 = CreateNode(4);
	ListNode* pNode5 = CreateNode(5);

	ConnectedNodes(pNode1, pNode2);
	ConnectedNodes(pNode2, pNode3);
	ConnectedNodes(pNode3, pNode4);
	ConnectedNodes(pNode4, pNode5);

	Test("test2", pNode1, 1, 5);

	DestroyList(pNode1);
}

void test3()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode2 = CreateNode(2);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode4 = CreateNode(4);
	ListNode* pNode5 = CreateNode(5);

	ConnectedNodes(pNode1, pNode2);
	ConnectedNodes(pNode2, pNode3);
	ConnectedNodes(pNode3, pNode4);
	ConnectedNodes(pNode4, pNode5);

	Test("test3", pNode1, 5, 1);

	DestroyList(pNode1);
}

void test4()
{

	Test("test4", nullptr, 1, 0);

}

void test5()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode2 = CreateNode(2);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode4 = CreateNode(4);
	ListNode* pNode5 = CreateNode(5);

	ConnectedNodes(pNode1, pNode2);
	ConnectedNodes(pNode2, pNode3);
	ConnectedNodes(pNode3, pNode4);
	ConnectedNodes(pNode4, pNode5);

	Test("test5", pNode1, 6, 4);

	DestroyList(pNode1);
}

void test6()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode2 = CreateNode(2);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode4 = CreateNode(4);
	ListNode* pNode5 = CreateNode(5);

	ConnectedNodes(pNode1, pNode2);
	ConnectedNodes(pNode2, pNode3);
	ConnectedNodes(pNode3, pNode4);
	ConnectedNodes(pNode4, pNode5);

	Test("test6", pNode1, 0, 4);

	DestroyList(pNode1);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}
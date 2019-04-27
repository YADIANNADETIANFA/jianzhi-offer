// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。
#include"ListNode.h"
#include<cstdio>
#include<iostream>
using namespace std;


bool isRoop = false;


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

ListNode* meetNode(ListNode* pHead)
{
	if (pHead == nullptr || pHead->m_pNext == nullptr)
		return nullptr;

	ListNode* pFast = pHead->m_pNext;
	ListNode* pSlow = pHead;
	while (pFast != pSlow)
	{
		if (pSlow->m_pNext != nullptr)
		{
			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
		}
		else
			return nullptr;

		if (pFast->m_pNext != nullptr)
			pFast = pFast->m_pNext;
		else
			return nullptr;
	}

	ListNode* pNode = pFast;
	isRoop = true;
	return pNode;
}

ListNode* FindEntryOfRoop(ListNode* pHead, ListNode* pNode)
{
	ListNode* pFast = pNode->m_pNext;
	ListNode* pSlow = pNode;

	int num = 1;

	while (pFast != pSlow)
	{
		pFast = pFast->m_pNext;
		++num;
	}

	ListNode* pNode1 = pHead;//并不知道链中节点的总数目，n-num找入口是行不通的
	ListNode* pNode2 = pHead;

	for (int i = 1; i <= num; ++i)
	{
		pNode1 = pNode1->m_pNext;
	}
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	return pNode1;
}

void Test(const char*testname, ListNode* pHead, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n",testname);

	ListNode* meeting = meetNode(pHead);
	if (meeting == nullptr)
	{
		printf("No roop here.\n");
		return;
	}
	else
	{
		ListNode* entry = FindEntryOfRoop(pHead, meeting);
		if (entry->m_value == expected)
			printf("Pass\n");
		else
			printf("Fail\n");
	}
	cout << endl;
}

void test1()
{
	ListNode* pNode1 = CreateNode(1);

	Test("test1", pNode1, 0);

	DestroyList(pNode1);

}

void test2()
{
	ListNode* pNode1 = CreateNode(1);
	ConnectedNodes(pNode1, pNode1);

	Test("test2", pNode1, 1);

	delete pNode1;//带环的必须要手动删
	pNode1 = nullptr;
	//DestroyList(pNode1);//带环的这么删可删不了
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
	ConnectedNodes(pNode5, pNode3);

	Test("test3", pNode1, 3);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
	//DestroyList(pNode1);
}

void test4()
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
	ConnectedNodes(pNode5, pNode1);

	Test("test4", pNode1, 1);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
	//DestroyList(pNode1);
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
	ConnectedNodes(pNode5, pNode5);

	Test("test5", pNode1, 5);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
	//DestroyList(pNode1);
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


	Test("test6", pNode1, 1);

	DestroyList(pNode1);
}

void test7()
{
	Test("test7", nullptr, 0);


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

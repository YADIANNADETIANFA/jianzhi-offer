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

ListNode* ReverseList(ListNode* pHead)//原链表发生了改变，因其就是对原链表身上进行的操作；要保持原链表不变，除非新建一链表，把原链表内容逐一复制过去，予以保留
{                                      //注意，只复制值，不复制指针地址，不然变一个另一个也会跟着变！！
	if (pHead == nullptr)
		return nullptr;
	if (pHead->m_pNext == nullptr)
		return pHead;

	ListNode* pFirst = pHead;
	ListNode* pSecond = pHead->m_pNext;
	ListNode* pThird = pHead->m_pNext->m_pNext;

	//ListNode* pFirst = pHead;
	//ListNode* pSecond = pFirst->m_pNext;
	//ListNode* pThird = pSecond->m_pNext;

	//pFirst->m_pNext = nullptr;
	pHead->m_pNext = nullptr;

	while (pThird != nullptr)
	{
		pSecond->m_pNext = pFirst;
		pFirst = pSecond;
		pSecond = pThird;
		pThird = pThird->m_pNext;
	}
	pSecond->m_pNext = pFirst;

	return pSecond;
}

void Test(const char* testname, ListNode* pHead, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	printf("Original List:\n");
	PrintList(pHead);
	printf("After reverse:\n");
	ListNode* Reverse = ReverseList(pHead);
	PrintList(Reverse);
	if (Reverse == nullptr)
	{
		printf("Error Parameter\n");
		return;
	}

	if (Reverse->m_value == expected)
		printf("Pass\n");
	else
		printf("Fail\n");

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

	Test("test1", pNode1, 5);
}

void test2()
{
	ListNode* pNode1 = CreateNode(1);

	Test("test2", pNode1, 1);
}

void test3()
{
	Test("test3", nullptr, 0);
}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}








/*#include <cstdio>
#include "ListNode.h"
#include<iostream>


ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nKey = value;
	pNode->m_pNext = nullptr;
	return pNode;
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

void ConnectListNodes(ListNode* p1, ListNode* p2)
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
			printf("%d\t", pNode->m_nKey);
			pNode = pNode->m_pNext;
		}
		printf("Print end.\n");
	}
}

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = nullptr;
	ListNode* pNode = pHead;
	ListNode* pPrev = nullptr;
	while (pNode != nullptr)
	{
		//pNode->m_pNext = pPrev;//ListNode* pNext = pNode->m_pNext;受影响
		ListNode* pNext = pNode->m_pNext;

		if (pNext == nullptr)
			pReversedHead = pNode;

		pNode->m_pNext = pPrev;//ListNode* pNext = pNode->m_pNext;不受影响//那链表改变是怎么实现联动的？？

		pPrev = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
	printf("The original list is: \n");
	PrintList(pHead);

	ListNode* pReversedHead = ReverseList(pHead);

	printf("The reversed list is: \n");
	PrintList(pReversedHead);

	return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
	Test(nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}*/
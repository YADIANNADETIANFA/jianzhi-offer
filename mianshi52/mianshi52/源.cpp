#include<cstdio>
#include<stack>
#include"ListNode.h"

using namespace std;

ListNode* ConstructNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_pNext = nullptr;
	pNode->m_value = value;
	return pNode;
}

void ConnectNodes(ListNode* pNode1, ListNode* pNode2)
{
	if (pNode1 == nullptr)
		return;
	pNode1->m_pNext = pNode2;
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
	return;
}

void DestroyNode(ListNode* pNode)//当链表有重复节点的时候，只能一个点一个点这样删！！！
{
	if (pNode == nullptr)
		return;
	delete pNode;
	pNode = nullptr;
}
ListNode* FindtheFirstSame1(ListNode* pHead1, ListNode* pHead2)//用两个堆栈来完成
{
	if (pHead1 == nullptr || pHead2 == nullptr)
		return nullptr;         //可以返回nullptr！

	ListNode* pNode1 = pHead1;
	stack<ListNode*> st1;
	ListNode* pNode2 = pHead2;
	stack<ListNode*> st2;

	while (pNode1 != nullptr)
	{
		st1.push(pNode1);
		pNode1 = pNode1->m_pNext;
	}
	while (pNode2 != nullptr)
	{
		st2.push(pNode2);
		pNode2 = pNode2->m_pNext;
	}

	while ((!st1.empty()) && (!st2.empty()) && (st1.top() == st2.top()))
	{
		st1.pop();
		st2.pop();
	}

	if (st1.empty() && st2.empty())//从最开始就是相同节点
		return pHead1;
	else if (st1.empty() || st2.empty())
		return nullptr;
	else
	{
		ListNode* pFind = st1.top();
		return pFind->m_pNext;
	}
}

ListNode* FindtheFirstSame2(ListNode* pHead1, ListNode* pHead2)//利用长度来解决问题
{
	if (pHead1 == nullptr || pHead2 == nullptr)
		return nullptr;

	int len1 = 0;
	int len2 = 0;

	ListNode* pNode1 = pHead1;
	ListNode* pNode2 = pHead2;

	while (pNode1 != nullptr)
	{
		++len1;
		pNode1 = pNode1->m_pNext;
	}
	while (pNode2 != nullptr)
	{
		++len2;
		pNode2 = pNode2->m_pNext;
	}

	int dis = len1 - len2;
	ListNode* plong = pHead1;
	ListNode* pshort = pHead2;
	if (len1 < len2)
	{
		plong = pHead2;
		pshort = pHead1;
		dis = len2 - len1;
	}
	for (int i = 1; i <= dis; ++i)
		plong = plong->m_pNext;
	while (plong != nullptr && pshort != nullptr && plong != pshort)
	{
		plong = plong->m_pNext;
		pshort = pshort->m_pNext;
	}

	if (plong == nullptr || pshort == nullptr)
		return nullptr;
	else
		return plong;
}

void Test(const char* testname, ListNode* pHead1, ListNode* pHead2, ListNode* expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	ListNode* result1 = FindtheFirstSame1(pHead1, pHead2);
	ListNode* result2 = FindtheFirstSame2(pHead1, pHead2);
	if (expected == result1 && expected == result2)
		printf("Pass\n");
	else
		printf("Fail\n");
	return;
}

void test1()
{
	ListNode* pNode1 = ConstructNode(1);
	ListNode* pNode2 = ConstructNode(2);
	ListNode* pNode3 = ConstructNode(3);
	ListNode* pNode4 = ConstructNode(4);
	ListNode* pNode5 = ConstructNode(5);
	ListNode* pNode6 = ConstructNode(6);
	ListNode* pNode7 = ConstructNode(7);

	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode6);
	ConnectNodes(pNode6, pNode7);

	ConnectNodes(pNode4, pNode5);
	ConnectNodes(pNode5, pNode6);

	Test("test1", pNode1, pNode4, pNode6);

	DestroyNode(pNode1);
	DestroyNode(pNode2);
	DestroyNode(pNode3);
	DestroyNode(pNode4);
	DestroyNode(pNode5);
	DestroyNode(pNode6);
	DestroyNode(pNode7);

	return;
}

void test2()
{
	ListNode* pNode1 = ConstructNode(1);
	ListNode* pNode2 = ConstructNode(2);
	ListNode* pNode3 = ConstructNode(3);
	ListNode* pNode4 = ConstructNode(4);
	ListNode* pNode5 = ConstructNode(5);
	ListNode* pNode6 = ConstructNode(6);
	ListNode* pNode7 = ConstructNode(7);

	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode4);

	ConnectNodes(pNode5, pNode6);
	ConnectNodes(pNode6, pNode7);

	Test("test2", pNode1, pNode5, nullptr);

	DestroyList(pNode1);
	DestroyList(pNode5);

	return;
}

void test3()
{
	ListNode* pNode1 = ConstructNode(1);
	ListNode* pNode2 = ConstructNode(2);
	ListNode* pNode3 = ConstructNode(3);
	ListNode* pNode4 = ConstructNode(4);
	ListNode* pNode5 = ConstructNode(5);
	ListNode* pNode6 = ConstructNode(6);
	ListNode* pNode7 = ConstructNode(7);

	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode4);
	ConnectNodes(pNode4, pNode7);

	ConnectNodes(pNode5, pNode6);
	ConnectNodes(pNode6, pNode7);

	Test("test3", pNode1, pNode5, pNode7);

	DestroyNode(pNode1);
	DestroyNode(pNode2);
	DestroyNode(pNode3);
	DestroyNode(pNode4);
	DestroyNode(pNode5);
	DestroyNode(pNode6);
	DestroyNode(pNode7);

	return;
}

void test4()
{
	ListNode* pNode1 = ConstructNode(1);
	ListNode* pNode2 = ConstructNode(2);
	ListNode* pNode3 = ConstructNode(3);
	ListNode* pNode4 = ConstructNode(4);
	ListNode* pNode5 = ConstructNode(5);
	ListNode* pNode6 = ConstructNode(6);
	ListNode* pNode7 = ConstructNode(7);

	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode4);
	ConnectNodes(pNode4, pNode5);
	ConnectNodes(pNode5, pNode6);
	ConnectNodes(pNode6, pNode7);

	Test("test4", pNode1, pNode1, pNode1);

	DestroyList(pNode1);

	return;
}

void test5()
{
	ListNode* pNode1 = ConstructNode(1);
	ListNode* pNode2 = ConstructNode(2);
	ListNode* pNode3 = ConstructNode(3);
	ListNode* pNode4 = ConstructNode(4);
	ListNode* pNode5 = ConstructNode(5);


	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode4);
	ConnectNodes(pNode4, pNode5);

	Test("test5", pNode1, nullptr, nullptr);

	DestroyList(pNode1);

	return;
}

void test6()
{

	Test("test6", nullptr, nullptr, nullptr);

	return;
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
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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr && pHead2 != nullptr)
		return pHead2;
	if (pHead1 != nullptr && pHead2 == nullptr)
		return pHead1;
	if (pHead1 == nullptr && pHead2 == nullptr)
		return nullptr;

	ListNode* select1 = pHead1;
	ListNode* select2 = pHead2;
	ListNode* smallHead = nullptr;

	if (pHead1->m_value > pHead2->m_value)
	{
		smallHead = pHead2;
		select2 = select2->m_pNext;
	}
	else
	{
		smallHead = pHead1;
		select1 = select1->m_pNext;
	}

	while (select1 != nullptr && select2 != nullptr)
	{
		if (select1->m_value > select2->m_value)
		{
			smallHead->m_pNext = select2;//smallHead���������ش�ͷ��ʼ�༭����������ԭ��
			select2 = select2->m_pNext;//���˺þö�û�н���취������ֻ���õݹ��ˣ������߲�ͨ��whileѭ�����Ժܺõ��ƶ�λ��ָ�룬���Ƕ�ͷ���Ĺ̶����䣬�����Ѻ�
		}
		else
		{
			smallHead->m_pNext = select1;
			select1 = select1->m_pNext;
		}
	}

	if (select1 == nullptr)//select1��2����ͬʱΪ�յģ���Ϊһ��ֻȡһ������
	{
		smallHead->m_pNext = select2;
	}
	else
	{
		smallHead->m_pNext = select1;
	}
	return smallHead;
}

// ====================���Դ���====================
ListNode* Test(const char* testName, ListNode* pHead1, ListNode* pHead2)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The first list is:\n");
	PrintList(pHead1);

	printf("The second list is:\n");
	PrintList(pHead2);

	printf("The merged list is:\n");
	ListNode* pMergedHead = Merge(pHead1, pHead2);
	PrintList(pMergedHead);

	/*printf("Original first list:\n");//��Ȼ�������ϣ�ԭ����ָ���ѷ����ı䣡Ҳ����˵���˴𰸲�δռ�ö���ռ�
	PrintList(pHead1);

	printf("Original second list:\n");
	PrintList(pHead2);*/

	printf("\n\n");

	return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode5 = CreateNode(5);

	ConnectedNodes(pNode1, pNode3);
	ConnectedNodes(pNode3, pNode5);

	ListNode* pNode2 = CreateNode(2);
	ListNode* pNode4 = CreateNode(4);
	ListNode* pNode6 = CreateNode(6);

	ConnectedNodes(pNode2, pNode4);
	ConnectedNodes(pNode4, pNode6);

	ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

	DestroyList(pMergedHead);
}

// �������������ظ�������
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode5 = CreateNode(5);

	ConnectedNodes(pNode1, pNode3);
	ConnectedNodes(pNode3, pNode5);

	ListNode* pNode2 = CreateNode(1);
	ListNode* pNode4 = CreateNode(3);
	ListNode* pNode6 = CreateNode(5);

	ConnectedNodes(pNode2, pNode4);
	ConnectedNodes(pNode4, pNode6);

	ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

	DestroyList(pMergedHead);
}

// ��������ֻ��һ������
// list1: 1
// list2: 2
void Test3()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode2 = CreateNode(2);

	ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

	DestroyList(pMergedHead);
}

// һ������Ϊ������
// list1: 1->3->5
// list2: ������
void Test4()
{
	ListNode* pNode1 = CreateNode(1);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode5 = CreateNode(5);

	ConnectedNodes(pNode1, pNode3);
	ConnectedNodes(pNode3, pNode5);

	ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

	DestroyList(pMergedHead);
}

// ��������Ϊ������
// list1: ������
// list2: ������
void Test5()
{
	ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}
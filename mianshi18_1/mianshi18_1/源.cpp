#include <cstdio>
#include "ListNode.h"
#include<iostream>
using namespace std;

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
		return;

	// Ҫɾ���Ľ�㲻��β���
	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	// ����ֻ��һ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	// �������ж����㣬ɾ��β���
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void PrintList(ListNode* pHead)//�����ӡ����
{
	cout << "PrintList start:" << endl;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}
	cout << "PrintList end." << endl;
}

ListNode* CreateListNode(int value)//��������ڵ�
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;
	return pNode;

}

void ConnectListNodes(ListNode* p1, ListNode* p2)//������������ڵ�
{
	if (p1 == nullptr)
	{
		cout << "Error to connect two nodes." << endl;
		exit(1);//��ʾ���̵ķ������˳�
	}
	p1->m_pNext = p2;
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;//����Ĳ�����ָ�룬�ʶ�����е�ɾ�����������˸ú���֮��ɾ��Ҳ�ǳ����ġ����������Ļ���������Ҫ����pNode���ݽ��أ�ֱ��pHead�Լ��Ǹ㲻����
		pNode = pHead;
	}
}
void PrintListNode(ListNode* pNode)
{
	if(pNode != nullptr)
		cout << pNode->m_nValue << endl;
}

// ====================���Դ���====================
void Test(ListNode* pListHead, ListNode* pNode)
{
	printf("The original list is: \n");
	PrintList(pListHead);

	printf("The node to be deleted is: \n");
	PrintListNode(pNode);

	DeleteNode(&pListHead, pNode);

	printf("The result list is: \n");
	PrintList(pListHead);
}

// �������ж����㣬ɾ���м�Ľ��
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

	Test(pNode1, pNode3);

	DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void Test2()
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

	Test(pNode1, pNode5);

	DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
void Test3()
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

	Test(pNode1, pNode1);

	DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1, pNode1);//ע�⣡��Test4��5��û���ֶ�����DestroyList�ģ�����
	DestroyList(pNode1);
}

// ����Ϊ��
void Test5()
{
	Test(nullptr, nullptr);//ע�⣡��Test4��5��û���ֶ�����DestroyList�ģ�����
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
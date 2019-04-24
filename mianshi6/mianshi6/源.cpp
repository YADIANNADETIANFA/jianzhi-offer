#include<iostream>
#include<stack>
#include "Lish.h"//�Լ�дͷ�ļ���������Ľṹ����ʽ
//using std::stack;//C++Primer74ҳ
using namespace std;

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	cout << "PrintListReversingly_Iteratively start:" << endl;
	stack<ListNode*> nodes;//����һ��ջ
	ListNode*pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nKey);
		nodes.pop();
	}
	cout << "PrintListReversingly_Iteratively end." << endl;
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
	//cout << "PrintListReversingly_Recursively start:" << endl;
	if (pHead != nullptr)
	{
		PrintListReversingly_Recursively(pHead->m_pNext);
		printf("%d\t", pHead->m_nKey);//�Ҹо����ﲻ�����������Ҳ������������
	}
	//cout << "PrintListReversingly_Recursively end." << endl;
}

void PrintList(ListNode* pHead)//�����ӡ����
{
	cout << "PrintList start:" << endl;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nKey);
		pNode = pNode->m_pNext;
	}
	cout << "PrintList end." << endl;
}

ListNode* CreatListNode(int value)//��������ڵ�
{
	ListNode* pNode = new ListNode();
	pNode->m_nKey = value;
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

void Test(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("Start PrintListReversingly_Recursively:\n");
	PrintListReversingly_Recursively(pHead);
	printf("End PrintListReversingly_Recursively.\n");
}

void Test1()//1 2 3 4 5
{
	printf("Test1:\n");
	ListNode* p1 = CreatListNode(1);
	ListNode* p2 = CreatListNode(2);
	ListNode* p3 = CreatListNode(3);
	ListNode* p4 = CreatListNode(4);
	ListNode* p5 = CreatListNode(5);
	ConnectListNodes(p1, p2);
	ConnectListNodes(p2, p3);
	ConnectListNodes(p3, p4);
	ConnectListNodes(p4, p5);
	Test(p1);
	DestroyList(p1);
}

void Test2()//1
{
	printf("Test2 start:\n");
	ListNode* p1 = CreatListNode(1);
	Test(p1);
	DestroyList(p1);
}

void Test3()//������
{
	printf("Test3 start:\n");
	Test(nullptr);
}

int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}




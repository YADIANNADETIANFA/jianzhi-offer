// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
#include<iostream>
#include<stack>
#include "Lish.h"//自己写头文件，即链表的结构体形式
//using std::stack;//C++Primer74页
using namespace std;

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	cout << "PrintListReversingly_Iteratively start:" << endl;
	stack<ListNode*> nodes;//创建一个栈
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
		printf("%d\t", pHead->m_nKey);//我感觉这里不用像答案那样，也可以正常运行
	}
	//cout << "PrintListReversingly_Recursively end." << endl;
}

void PrintList(ListNode* pHead)//正序打印链表
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

ListNode* CreatListNode(int value)//创建链表节点
{
	ListNode* pNode = new ListNode();
	pNode->m_nKey = value;
	pNode->m_pNext = nullptr;
	return pNode;
	
}

void ConnectListNodes(ListNode* p1, ListNode* p2)//链接两个链表节点
{
	if (p1 == nullptr)
	{
		cout << "Error to connect two nodes." << endl;
		exit(1);//表示进程的非正常退出
	}
	p1->m_pNext = p2;
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;//输入的参数是指针，故对其进行的删除操作，出了该函数之后，删除也是成立的。。。这样的话，还必须要借用pNode来递进呢，直接pHead自己是搞不来的
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

void Test3()//空链表
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




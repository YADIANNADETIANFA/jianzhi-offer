// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。
#include"ListNode.h"
#include<iostream>
#include<cstdio>
using namespace std;

void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode->m_pNext != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool isDuplication = false;
		if (pNode->m_value == pNext->m_value)
			isDuplication = true;

		if (!isDuplication)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_value;
			while (pNext->m_pNext != nullptr && pNext->m_value == value)//有重复的就开删
			{
				delete pNode;
				pNode = nullptr;
				pNode = pNext;
				pNext = pNext->m_pNext;
			}

			if (pNode->m_value != pNext->m_value)//跳出while循环的可能之一
			{
				delete pNode;
				pNode = nullptr;
				pNode = pNext;
				if (pPreNode != nullptr)//前面还是有没删的元素的
				{
					pPreNode->m_pNext = pNode;
				}
				else//从头一直删到了这里，前面啥都没留
				{
					*pHead = pNode;
				}
			}
			else//跳出循环可能之二，最末尾是两个一样的，全给删掉
			{
				delete pNode;
				pNode = nullptr;
				delete pNext;
				pNext = nullptr;//while (pNode->m_pNext != nullptr)再执行就会报错，故下面放两个return
				if (pPreNode != nullptr)//前面还是有没删的元素的
				{
					pPreNode->m_pNext = nullptr;
					return;
				}
				else//从头一直删,啥都没留
				{
					*pHead = nullptr;
					return;
				}
			}
		}
	}
}

void PrintList(ListNode* pHead)
{
	cout << "Print start:" << endl;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_value);
		pNode = pNode->m_pNext;
	}
	cout << "Print end." << endl;
}

ListNode* CreatNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_value = value;
	pNode->m_pNext = nullptr;
	return pNode;
}

void ConnectNodes(ListNode* p1, ListNode* p2)
{
	if (p1 == nullptr)
	{
		cout << "Error to connected two nodes." << endl;
		exit(1);
	}
	p1->m_pNext = p2;
}

void DestroyedList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void Test(const char* testname, ListNode** pHead)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	PrintList(*pHead);
	DeleteDuplication(pHead);
	cout << "After DeleteDuplication:" << endl;
	PrintList(*pHead);
}

void test1()
{
	ListNode* pNode1 = CreatNode(1);
	ListNode* pNode2 = CreatNode(2);
	ListNode* pNode3 = CreatNode(3);
	ListNode* pNode4 = CreatNode(3);
	ListNode* pNode5 = CreatNode(4);
	ListNode* pNode6 = CreatNode(4);
	ListNode* pNode7 = CreatNode(5);

	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode4);
	ConnectNodes(pNode4, pNode5);
	ConnectNodes(pNode5, pNode6);
	ConnectNodes(pNode6, pNode7);

	Test("test1", &pNode1);//这里参数为&
	DestroyedList(pNode1);
}

void test2()
{
	ListNode* pNode1 = CreatNode(1);
	ListNode* pNode2 = CreatNode(2);
	ListNode* pNode3 = CreatNode(3);
	ListNode* pNode4 = CreatNode(4);
	ListNode* pNode5 = CreatNode(5);
	ListNode* pNode6 = CreatNode(6);
	ListNode* pNode7 = CreatNode(7);

	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode4);
	ConnectNodes(pNode4, pNode5);
	ConnectNodes(pNode5, pNode6);
	ConnectNodes(pNode6, pNode7);

	Test("test2", &pNode1);//这里参数为&
	DestroyedList(pNode1);
}

void test3()
{
	ListNode* pNode1 = CreatNode(1);
	ListNode* pNode2 = CreatNode(1);
	ListNode* pNode3 = CreatNode(1);
	ListNode* pNode4 = CreatNode(1);
	ListNode* pNode5 = CreatNode(1);
	ListNode* pNode6 = CreatNode(1);
	ListNode* pNode7 = CreatNode(2);

	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode4);
	ConnectNodes(pNode4, pNode5);
	ConnectNodes(pNode5, pNode6);
	ConnectNodes(pNode6, pNode7);

	Test("test3", &pNode1);//这里参数为&
	DestroyedList(pNode1);
}

void test4()
{
	ListNode* pNode1 = CreatNode(1);
	ListNode* pNode2 = CreatNode(1);
	ListNode* pNode3 = CreatNode(1);
	ListNode* pNode4 = CreatNode(1);
	ListNode* pNode5 = CreatNode(1);
	ListNode* pNode6 = CreatNode(1);
	ListNode* pNode7 = CreatNode(1);

	ConnectNodes(pNode1, pNode2);
	ConnectNodes(pNode2, pNode3);
	ConnectNodes(pNode3, pNode4);
	ConnectNodes(pNode4, pNode5);
	ConnectNodes(pNode5, pNode6);
	ConnectNodes(pNode6, pNode7);

	Test("test4", &pNode1);//这里参数为&
	DestroyedList(pNode1);
}

void test5()
{
	ListNode* pNode1 = CreatNode(1);
	ListNode* pNode2 = CreatNode(2);

	ConnectNodes(pNode1, pNode2);

	Test("test5", &pNode1);//这里参数为&
	DestroyedList(pNode1);
}

void test6()
{
	ListNode* pNode1 = CreatNode(1);


	Test("test6", &pNode1);//这里参数为&
	DestroyedList(pNode1);
}

void test7()
{
	ListNode* pNode1 = CreatNode(1);
	ListNode* pNode2 = CreatNode(1);

	ConnectNodes(pNode1, pNode2);

	Test("test7", &pNode1);//这里参数为&
	DestroyedList(pNode1);
}

void test8()
{
	ListNode* pNode1 = nullptr;
	Test("test8", &pNode1);//这里参数为&
	//Test("test8", nullptr);//下面这两个都不对
	//Test("test8", &nullptr);//常量没法&  ！！   这里相当于借助ListNode* pNode1完成的nullptr的处理工作
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
	test8();
	return 0;
}

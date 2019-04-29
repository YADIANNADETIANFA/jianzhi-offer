#include"ListNode.h"
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

ListNode* ConstructNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_value = value;
	pNode->m_pNext = nullptr;
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
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<ListNode*> List;//iostream输入链表值，不知道怎么才能把链表连起来，for不出来。所以先都存起来，然后慢慢连
		for (int i = 0; i < n; ++i)
		{
			ListNode* pNode = ConstructNode(i);
			List.push_back(pNode);
		}
		ListNode* pHead = List[0];
		for (int i = 0; i < n-1; ++i)//链表连好
		{
			List[i]->m_pNext = List[i + 1];
		}

		List[n - 1]->m_pNext = pHead;//链表循环

		int num = n;
		ListNode* pNode=pHead;
		while (num != 1)
		{
			for (int i = 1; i < m-1; ++i)
			{
				pNode = pNode->m_pNext;
			}
			ListNode* pTemp=pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
			delete pTemp;
			pNode = pNode->m_pNext;
			num--;
		}
		cout << pNode->m_value << endl;
		delete pNode;
		pNode = nullptr;
	}
	return 0;
}


// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
#include<cstdio>//printf函数头文件
#include"BinaryTreeNode.h"

BinaryTreeNode* CreateNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->p_left = nullptr;
	pNode->p_right = nullptr;
	pNode->p_parent = nullptr;

	return pNode;
}

void ConnectNodes(BinaryTreeNode* Parent, BinaryTreeNode* Pleft,BinaryTreeNode* Pright)
{
	if (Parent != nullptr)
	{
		Parent->p_left = Pleft;
		Parent->p_right = Pright;
	}
	if (Pleft != nullptr)
	{
		Pleft->p_parent = Parent;
	}
	if (Pright != nullptr)
	{
		Pright->p_parent = Parent;
	}
}

void PrintNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("The value of the node is:%d.\n", pNode->m_value);
	}
	else
		printf("This node is null.\n");
}

void PrintTree(BinaryTreeNode* pRoot)
{
	PrintNode(pRoot);
	if (pRoot != nullptr)
	{
		if (pRoot->p_left != nullptr)
		{
			PrintTree(pRoot->p_left);
		}
		if (pRoot->p_right != nullptr)
		{
			PrintTree(pRoot->p_right);
		}

	}
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->p_left;
		BinaryTreeNode* pRight = pRoot->p_right;
		delete pRoot;
		pRoot = nullptr;
		DestroyTree(pLeft);//和链表一样，看来这样的删除操作是正确的，内存被收回了，但是指针还是可以用的看来
		DestroyTree(pRight);
	}
}

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;
	BinaryTreeNode* pNext = nullptr;
	if (pNode->p_right != nullptr)
	{
		pNext = pNode->p_right;
		while (pNext->p_left != nullptr)
			pNext = pNext->p_left;

	}
	else if(pNode->p_parent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->p_parent;
		if (pParent->p_left == pCurrent)
		{
			pNext = pParent;
		}
		else
		{
			while (pParent->p_parent != nullptr)
			{
				pCurrent = pCurrent->p_parent;
				pParent = pParent->p_parent;
				if (pParent->p_left == pCurrent)
				{
					pNext = pParent;
					break;
				}
			}
		}
	}
	return pNext;
}

void Test(const char* TestName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
	if (TestName != nullptr)
		printf("%s begin:\n", TestName);
	BinaryTreeNode* pNext = GetNext(pNode);
	if (pNext == expected)
		printf("pass!\n");
	else
		printf("false!\n");

}

void Test1()
{
	BinaryTreeNode* pNode8 = CreateNode(8);
	BinaryTreeNode* pNode6 = CreateNode(6);
	BinaryTreeNode* pNode10 = CreateNode(10);
	BinaryTreeNode* pNode5 = CreateNode(5);
	BinaryTreeNode* pNode7 = CreateNode(7);
	BinaryTreeNode* pNode9 = CreateNode(9);
	BinaryTreeNode* pNode11 = CreateNode(11);

	ConnectNodes(pNode8, pNode6, pNode10);
	ConnectNodes(pNode6, pNode5, pNode7);
	ConnectNodes(pNode10, pNode9, pNode11);

	Test("Test1", pNode8, pNode9);
	Test("Test1", pNode6, pNode7);
	Test("Test1", pNode10, pNode11);
	Test("Test1", pNode5, pNode6);
	Test("Test1", pNode7, pNode8);
	Test("Test1", pNode9, pNode10);
	Test("Test1", pNode11, nullptr);

	DestroyTree(pNode8);

}

void Test2()
{
	BinaryTreeNode* pNode5 = CreateNode(5);
	BinaryTreeNode* pNode4 = CreateNode(4);
	BinaryTreeNode* pNode3 = CreateNode(3);
	BinaryTreeNode* pNode2 = CreateNode(2);

	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);

	Test("Test2", pNode5, nullptr);
	Test("Test2", pNode4, pNode5);
	Test("Test2", pNode3, pNode4);
	Test("Test2", pNode2, pNode3);

	DestroyTree(pNode5);
}

void Test3()
{
	BinaryTreeNode* pNode5 = CreateNode(5);
	Test("Test3", pNode5, nullptr);
	DestroyTree(pNode5);
}

int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}

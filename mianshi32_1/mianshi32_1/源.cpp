// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
#include<cstdio>
#include"BinaryTreeNode.h"
#include<deque>
#include<iostream>
#include<stack>
using namespace std;

BinaryTreeNode* ConstructNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->p_left = nullptr;
	pNode->p_right = nullptr;

	return pNode;
}

void ConnectNodes(BinaryTreeNode* pRoot, BinaryTreeNode* pleft,BinaryTreeNode* pright)
{
	if (!pRoot)
		return;
	pRoot->p_left = pleft;
	pRoot->p_right = pright;
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (!pRoot)
		return;
	BinaryTreeNode* pleft = pRoot->p_left;
	BinaryTreeNode* pright = pRoot->p_right;

	delete pRoot;
	pRoot = nullptr;

	DestroyTree(pleft);
	DestroyTree(pright);
}

void PrintFromTopToButtom(BinaryTreeNode* pRoot)
{
	if (!pRoot)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		printf("%d\t", pNode->m_value);

		if (pNode->p_left)
			dequeTreeNode.push_back(pNode->p_left);
		if (pNode->p_right)
			dequeTreeNode.push_back(pNode->p_right);
	}
}

void Print_row(BinaryTreeNode* pRoot)
{
	if (!pRoot)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);

	int now_num = 1;
	int next_num = 0;

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		--now_num;
		printf("%d\t", pNode->m_value);

		if (pNode->p_left)
		{
			dequeTreeNode.push_back(pNode->p_left);
			++next_num;
		}
		if (pNode->p_right)
		{
			dequeTreeNode.push_back(pNode->p_right);
			++next_num;
		}

		if (now_num == 0)
		{
			cout << endl;
			now_num = next_num;
			next_num = 0;
		}
	}
}

void Print_row_snake(BinaryTreeNode* pRoot)
{
	if (!pRoot)
		return;

	stack<BinaryTreeNode*> stackNodes1;
	stack<BinaryTreeNode*> stackNodes2;

	bool snake = false;//false：打印1栈，并向2栈压入
	                   //true：打印2栈，并向1栈压入
	printf("%d\t", pRoot->m_value);//把头结点先自己打出来
	cout << endl;

	if (pRoot->p_right)//保证传进栈里面的，不会含有空指针
		stackNodes1.push(pRoot->p_right);
	if (pRoot->p_left)
		stackNodes1.push(pRoot->p_left);

	while (stackNodes1.size() || stackNodes2.size())//什么时候两个栈全空了，那就是打完了
	{
		if (!snake)
		{
			BinaryTreeNode* pNode = stackNodes1.top();
			stackNodes1.pop();
			printf("%d\t", pNode->m_value);
			if (pNode->p_left)
				stackNodes2.push(pNode->p_left);
			if (pNode->p_right)
				stackNodes2.push(pNode->p_right);
		}
		else
		{
			BinaryTreeNode* pNode = stackNodes2.top();
			stackNodes2.pop();
			printf("%d\t", pNode->m_value);
			if (pNode->p_right)
				stackNodes1.push(pNode->p_right);
			if (pNode->p_left)
				stackNodes1.push(pNode->p_left);
		}
		if (stackNodes1.empty() && snake == false)//打完一行了
		{
			snake = true;
			cout << endl;
		}
		if (stackNodes2.empty() && snake == true)//同上
		{
			snake = false;
			cout << endl;
		}
	}
}

void test1()
{
	printf("test1 begin:\n");
	BinaryTreeNode* pNode10 = ConstructNode(10);
	BinaryTreeNode* pNode6 = ConstructNode(6);
	BinaryTreeNode* pNode14 = ConstructNode(14);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode8 = ConstructNode(8);
	BinaryTreeNode* pNode12 = ConstructNode(12);
	BinaryTreeNode* pNode16 = ConstructNode(16);

	ConnectNodes(pNode10, pNode6, pNode14);
	ConnectNodes(pNode6, pNode4, pNode8);
	ConnectNodes(pNode14, pNode12, pNode16);

	printf("PrintFromTopToBottom\n");
	PrintFromTopToButtom(pNode10);
	cout << endl;

	printf("Print_row\n");
	Print_row(pNode10);
	cout << endl;

	printf("Print_row_snake\n");
	Print_row_snake(pNode10);
	cout << endl;
	DestroyTree(pNode10);
}

void test2()
{
	printf("test2 begin:\n");
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode1 = ConstructNode(1);


	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);
	ConnectNodes(pNode2, pNode1, nullptr);

	printf("PrintFromTopToBottom\n");
	PrintFromTopToButtom(pNode5);
	cout << endl;

	printf("Print_row\n");
	Print_row(pNode5);
	cout << endl;

	printf("Print_row_snake\n");
	Print_row_snake(pNode5);
	cout << endl;
	DestroyTree(pNode5);
}

void test3()
{
	printf("test3 begin:\n");
	BinaryTreeNode* pNode1 = ConstructNode(1);

	printf("PrintFromTopToBottom\n");
	PrintFromTopToButtom(pNode1);
	cout << endl;

	printf("Print_row\n");
	Print_row(pNode1);
	cout << endl;

	printf("Print_row_snake\n");
	Print_row_snake(pNode1);
	cout << endl;
	DestroyTree(pNode1);
}

void test4()
{
	printf("test4 begin:\n");

	printf("PrintFromTopToBottom\n");
	PrintFromTopToButtom(nullptr);
	cout << endl;

	printf("Print_row\n");
	Print_row(nullptr);
	cout << endl;

	printf("Print_row_snake\n");
	Print_row_snake(nullptr);
	cout << endl;
}

int main()//总会忘记main然后检测出不可知错误
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}

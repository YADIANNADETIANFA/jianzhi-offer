// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。
#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
#include"Binary_TreeNode.h"
using namespace std;

Binary_TreeNode* ConstructNode(double value)
{
	Binary_TreeNode* pNode = new Binary_TreeNode();
	pNode->m_value = value;
	pNode->m_pleft = nullptr;
	pNode->m_pright = nullptr;
	return pNode;
}

void ConnectNodes(Binary_TreeNode* pRoot, Binary_TreeNode* pleft, Binary_TreeNode* pright)
{
	if (pRoot != nullptr)
	{
		pRoot->m_pleft = pleft;
		pRoot->m_pright = pright;
	}
}

void DestroyTree(Binary_TreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		Binary_TreeNode* pleft = pRoot->m_pleft;
		Binary_TreeNode* pright = pRoot->m_pright;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pleft);
		DestroyTree(pright);
	}
}

bool isSymmetrical_Recursively(Binary_TreeNode*, Binary_TreeNode*);//书上方法1，递归算法

bool isSymmetrical_Recursively(Binary_TreeNode* pRoot)
{
	return isSymmetrical_Recursively(pRoot, pRoot);
}
bool isSymmetrical_Recursively(Binary_TreeNode* pRoot1, Binary_TreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;
	if (pRoot1->m_value != pRoot2->m_value)
		return false;
	else
		return isSymmetrical_Recursively(pRoot1->m_pleft, pRoot2->m_pright) && isSymmetrical_Recursively(pRoot1->m_pright, pRoot2->m_pleft);
}

bool isSymmetrical_Iteratively(Binary_TreeNode* pRoot)//由上自己推导出的迭代算法
{
	stack<Binary_TreeNode*> stackNode;

	if (pRoot == nullptr)
		return true;

	stackNode.push(pRoot->m_pright);
	stackNode.push(pRoot->m_pleft);

	while (stackNode.size() > 0)
	{
		Binary_TreeNode* pLEFT = stackNode.top();
		stackNode.pop();
		Binary_TreeNode* pRIGHT = stackNode.top();
		stackNode.pop();

		if (pLEFT == nullptr && pRIGHT == nullptr)
			continue;
		if (pLEFT == nullptr || pRIGHT == nullptr)
			return false;
		if (pLEFT->m_value != pRIGHT->m_value)
			return false;
		else
		{
			stackNode.push(pLEFT->m_pright);
			stackNode.push(pRIGHT->m_pleft);
			stackNode.push(pRIGHT->m_pright);
			stackNode.push(pLEFT->m_pleft);
		}
	}
	return true;
}
                                                           //最原始的方法，就是利用容器打出来挨个比较，就知道对不对称了
void PrintPreorder(Binary_TreeNode* pRoot,vector<int>& v1)//把vector给返回出来，是很糟糕的想法
{                                                         //正常人对于复杂的结果，都是用参数引用来处理的
	vector<int> PreorderList;
	if (pRoot != nullptr)
	{
		cout << pRoot->m_value << " ";
		v1.push_back(pRoot->m_value);
		PrintPreorder(pRoot->m_pleft, v1);
		PrintPreorder(pRoot->m_pright, v1);
	}
	else
	{
		cout << -1 << " ";
		v1.push_back(-1);
	}
	
}

void PrintPri_Symmetricorder(Binary_TreeNode* pRoot,vector<int>& v2)
{
	vector<int> Pri_SymmetricList;
	if (pRoot != nullptr)
	{
		cout << pRoot->m_value << " ";
		v2.push_back(pRoot->m_value);
		PrintPri_Symmetricorder(pRoot->m_pright,v2);
		PrintPri_Symmetricorder(pRoot->m_pleft,v2);
	}
	else
	{
		cout << -1 << " ";
		v2.push_back(-1);
	}
	
}

void Test(const char* testname, Binary_TreeNode* pRoot, bool expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	bool result1 = isSymmetrical_Recursively(pRoot);
	printf("isSymmetrical_Recursively:\n");
	if (result1 == expected)
		printf("Pass\n");
	else
		printf("Fail\n");

	bool result2 = isSymmetrical_Iteratively(pRoot);
	printf("isSymmetrical_Iteratively:\n");
	if (result2 == expected)
		printf("Pass\n");
	else
		printf("Fail\n");

	printf("Print method:\n");

	vector<int> PreorderList;//引用传递参数，代替vector作为返回值这一幼稚麻烦的操作！！！
	vector<int> Pri_SymmetricList;
	PrintPreorder(pRoot, PreorderList);
	cout << endl;
	PrintPri_Symmetricorder(pRoot, Pri_SymmetricList);
	cout << endl;

	bool isSame = true;
	for (int i = 0; i < PreorderList.size(); ++i)
	{
		if (PreorderList[i] != Pri_SymmetricList[i])
		{
			isSame = false;
		}
	}
	if (isSame == expected)
		printf("Pass\n");
	else
		printf("Fail\n");

	PreorderList.clear();
	Pri_SymmetricList.clear();//删除内容
	vector <int>().swap(PreorderList);//回收空间
	vector <int>().swap(Pri_SymmetricList);

}

void test1()
{
	Binary_TreeNode* pNode8 = ConstructNode(8);
	Binary_TreeNode* pNode61 = ConstructNode(6);
	Binary_TreeNode* pNode62 = ConstructNode(6);
	Binary_TreeNode* pNode51 = ConstructNode(5);
	Binary_TreeNode* pNode71 = ConstructNode(7);
	Binary_TreeNode* pNode72 = ConstructNode(7);
	Binary_TreeNode* pNode52 = ConstructNode(5);

	ConnectNodes(pNode8, pNode61, pNode62);
	ConnectNodes(pNode61, pNode51, pNode71);
	ConnectNodes(pNode62, pNode72, pNode52);

	Test("test1", pNode8, true);

	DestroyTree(pNode8);
}

void test2()
{
	Binary_TreeNode* pNode8 = ConstructNode(8);
	Binary_TreeNode* pNode61 = ConstructNode(6);
	Binary_TreeNode* pNode9 = ConstructNode(9);
	Binary_TreeNode* pNode51 = ConstructNode(5);
	Binary_TreeNode* pNode71 = ConstructNode(7);
	Binary_TreeNode* pNode72 = ConstructNode(7);
	Binary_TreeNode* pNode52 = ConstructNode(5);

	ConnectNodes(pNode8, pNode61, pNode9);
	ConnectNodes(pNode61, pNode51, pNode71);
	ConnectNodes(pNode9, pNode72, pNode52);

	Test("test2", pNode8, false);

	DestroyTree(pNode8);
}

void test3()
{
	Binary_TreeNode* pNode8 = ConstructNode(8);
	Binary_TreeNode* pNode61 = ConstructNode(6);
	Binary_TreeNode* pNode62 = ConstructNode(6);
	Binary_TreeNode* pNode51 = ConstructNode(5);
	Binary_TreeNode* pNode71 = ConstructNode(7);
	Binary_TreeNode* pNode72 = ConstructNode(7);

	ConnectNodes(pNode8, pNode61, pNode62);
	ConnectNodes(pNode61, pNode51, pNode71);
	ConnectNodes(pNode62, pNode72, nullptr);

	Test("test3", pNode8, false);

	DestroyTree(pNode8);
}

void test4()
{
	Binary_TreeNode* pNode5 = ConstructNode(5);
	Binary_TreeNode* pNode31 = ConstructNode(3);
	Binary_TreeNode* pNode32 = ConstructNode(3);
	Binary_TreeNode* pNode41 = ConstructNode(4);
	Binary_TreeNode* pNode42 = ConstructNode(4);
	Binary_TreeNode* pNode21 = ConstructNode(2);
	Binary_TreeNode* pNode22 = ConstructNode(2);
	Binary_TreeNode* pNode11 = ConstructNode(1);
	Binary_TreeNode* pNode12 = ConstructNode(1);

	ConnectNodes(pNode5, pNode31, pNode32);
	ConnectNodes(pNode31, pNode41, nullptr);
	ConnectNodes(pNode32, nullptr, pNode42);
	ConnectNodes(pNode41, pNode21, nullptr);
	ConnectNodes(pNode42, nullptr, pNode22);
	ConnectNodes(pNode21, pNode11, nullptr);
	ConnectNodes(pNode22, nullptr, pNode12);

	Test("test4", pNode5, true);

	DestroyTree(pNode5);
}

void test5()
{
	Binary_TreeNode* pNode5 = ConstructNode(5);
	Binary_TreeNode* pNode31 = ConstructNode(3);
	Binary_TreeNode* pNode32 = ConstructNode(3);
	Binary_TreeNode* pNode41 = ConstructNode(4);
	Binary_TreeNode* pNode42 = ConstructNode(4);
	Binary_TreeNode* pNode6 = ConstructNode(6);
	Binary_TreeNode* pNode22 = ConstructNode(2);
	Binary_TreeNode* pNode11 = ConstructNode(1);
	Binary_TreeNode* pNode12 = ConstructNode(1);

	ConnectNodes(pNode5, pNode31, pNode32);
	ConnectNodes(pNode31, pNode41, nullptr);
	ConnectNodes(pNode32, nullptr, pNode42);
	ConnectNodes(pNode41, pNode6, nullptr);
	ConnectNodes(pNode42, nullptr, pNode22);
	ConnectNodes(pNode6, pNode11, nullptr);
	ConnectNodes(pNode22, nullptr, pNode12);

	Test("test5", pNode5, false);

	DestroyTree(pNode5);
}

void test6()
{
	Binary_TreeNode* pNode5 = ConstructNode(5);
	Binary_TreeNode* pNode31 = ConstructNode(3);
	Binary_TreeNode* pNode32 = ConstructNode(3);
	Binary_TreeNode* pNode41 = ConstructNode(4);
	Binary_TreeNode* pNode42 = ConstructNode(4);
	Binary_TreeNode* pNode21 = ConstructNode(2);
	Binary_TreeNode* pNode22 = ConstructNode(2);
	Binary_TreeNode* pNode12 = ConstructNode(1);

	ConnectNodes(pNode5, pNode31, pNode32);
	ConnectNodes(pNode31, pNode41, nullptr);
	ConnectNodes(pNode32, nullptr, pNode42);
	ConnectNodes(pNode41, pNode21, nullptr);
	ConnectNodes(pNode42, nullptr, pNode22);
	ConnectNodes(pNode21, nullptr, nullptr);
	ConnectNodes(pNode22, nullptr, pNode12);

	Test("test6", pNode5, false);

	DestroyTree(pNode5);
}

void test7()
{
	Binary_TreeNode* pNode1 = ConstructNode(1);
	Test("test7", pNode1, true);
	DestroyTree(pNode1);
}

void test8()
{
	Test("test8", nullptr, true);
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

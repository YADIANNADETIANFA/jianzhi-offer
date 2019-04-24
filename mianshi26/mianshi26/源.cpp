#include"Binary_TreeNode.h"
#include<cstdio>
#include<iostream>
using namespace std;


bool Equal(double, double);
bool DoesTree1HaveTree2(Binary_TreeNode*, Binary_TreeNode*);

bool HasSubtree(Binary_TreeNode* pRoot1, Binary_TreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 != nullptr && pRoot2 != nullptr)
	{
		if (Equal(pRoot1->m_value, pRoot2->m_value))
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->m_pleft, pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->m_pright, pRoot2);
	}
	return result;
}

bool DoesTree1HaveTree2(Binary_TreeNode* pRoot1, Binary_TreeNode* pRoot2)
{
	bool result_left = false;
	bool result_right = false;

	if (pRoot1->m_pleft == nullptr && pRoot2->m_pleft == nullptr)
		result_left = true;
	else if (pRoot1->m_pleft != nullptr && pRoot2->m_pleft == nullptr)
		result_left = true;
	else if (pRoot1->m_pleft == nullptr && pRoot2->m_pleft != nullptr)
	{
		result_left = false;
		return false;
	}
	else
	{
		if (Equal(pRoot1->m_pleft->m_value, pRoot2->m_pleft->m_value))
		{
			result_left = DoesTree1HaveTree2(pRoot1->m_pleft, pRoot2->m_pleft);
			if (result_left == false)
				return false;
		}
		else
		{
			result_left = false;
			return false;
		}
	}


	if (pRoot1->m_pright == nullptr && pRoot2->m_pright == nullptr)
		result_right = true;
	else if (pRoot1->m_pright != nullptr && pRoot2->m_pright == nullptr)
		result_right = true;
	else if (pRoot1->m_pright == nullptr && pRoot2->m_pright != nullptr)
	{
		result_right = false;
		return false;
	}
	else
	{
		if (Equal(pRoot1->m_pright->m_value, pRoot2->m_pright->m_value))
		{
			result_right = DoesTree1HaveTree2(pRoot1->m_pright, pRoot2->m_pright);
			if (result_right == false)
				return false;
		}
		else
		{
			result_right = false;
			return false;
		}
	}

	return result_left && result_right;
}

bool Equal(double value1, double value2)
{
	if ((value1 - value2 > -0.0000001) && (value1 - value2 < 0.0000001))
		return true;
	else
		return false;
}

Binary_TreeNode* ConstructNode(double value)
{
	Binary_TreeNode* pNode = new Binary_TreeNode();
	pNode->m_value = value;
	pNode->m_pleft = nullptr;
	pNode->m_pright = nullptr;

	return pNode;
}

void ConnectedNodes(Binary_TreeNode* pRoot, Binary_TreeNode* pLeft,Binary_TreeNode* pRight)
{
	if (pRoot != nullptr)
	{
		pRoot->m_pleft = pLeft;
		pRoot->m_pright = pRight;
	}
}

void DestroyTree(Binary_TreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		Binary_TreeNode* pLeft = pRoot->m_pleft;
		Binary_TreeNode* pRight = pRoot->m_pright;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

void Test(const char* testname, Binary_TreeNode* pRoot1, Binary_TreeNode* pRoot2, bool expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	bool result = HasSubtree(pRoot1, pRoot2);
	if (result == expected)
		printf("Pass.\n");
	else
		printf("Fail.\n");

	cout << endl;
}

void test1()
{
	Binary_TreeNode* pNodeA1 = ConstructNode(8);
	Binary_TreeNode* pNodeA2 = ConstructNode(8);
	Binary_TreeNode* pNodeA3 = ConstructNode(7);
	Binary_TreeNode* pNodeA4 = ConstructNode(9);
	Binary_TreeNode* pNodeA5 = ConstructNode(2);
	Binary_TreeNode* pNodeA6 = ConstructNode(4);
	Binary_TreeNode* pNodeA7 = ConstructNode(7);

	ConnectedNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectedNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectedNodes(pNodeA5, pNodeA6, pNodeA7);


	Binary_TreeNode* pNodeB1 = ConstructNode(8);
	Binary_TreeNode* pNodeB2 = ConstructNode(9);
	Binary_TreeNode* pNodeB3 = ConstructNode(2);

	ConnectedNodes(pNodeB1, pNodeB2, pNodeB3);

	Test("test1", pNodeA1, pNodeB1, true);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

void test2()
{
	Binary_TreeNode* pNodeA1 = ConstructNode(8);
	Binary_TreeNode* pNodeA2 = ConstructNode(8);
	Binary_TreeNode* pNodeA3 = ConstructNode(7);
	Binary_TreeNode* pNodeA4 = ConstructNode(9);
	Binary_TreeNode* pNodeA5 = ConstructNode(3);
	Binary_TreeNode* pNodeA6 = ConstructNode(4);
	Binary_TreeNode* pNodeA7 = ConstructNode(7);

	ConnectedNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectedNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectedNodes(pNodeA5, pNodeA6, pNodeA7);


	Binary_TreeNode* pNodeB1 = ConstructNode(8);
	Binary_TreeNode* pNodeB2 = ConstructNode(9);
	Binary_TreeNode* pNodeB3 = ConstructNode(2);

	ConnectedNodes(pNodeB1, pNodeB2, pNodeB3);

	Test("test2", pNodeA1, pNodeB1, false);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

void test3()
{
	Binary_TreeNode* pNodeA1 = ConstructNode(8);
	Binary_TreeNode* pNodeA2 = ConstructNode(8);
	Binary_TreeNode* pNodeA3 = ConstructNode(9);
	Binary_TreeNode* pNodeA4 = ConstructNode(2);
	Binary_TreeNode* pNodeA5 = ConstructNode(5);


	ConnectedNodes(pNodeA1, pNodeA2, nullptr);
	ConnectedNodes(pNodeA2, pNodeA3, nullptr);
	ConnectedNodes(pNodeA3, pNodeA4, nullptr);
	ConnectedNodes(pNodeA4, pNodeA5, nullptr);


	Binary_TreeNode* pNodeB1 = ConstructNode(8);
	Binary_TreeNode* pNodeB2 = ConstructNode(9);
	Binary_TreeNode* pNodeB3 = ConstructNode(2);

	ConnectedNodes(pNodeB1, pNodeB2, nullptr);
	ConnectedNodes(pNodeB2, pNodeB3, nullptr);


	Test("test3", pNodeA1, pNodeB1, true);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

void test4()
{
	Binary_TreeNode* pNodeA1 = ConstructNode(8);
	Binary_TreeNode* pNodeA2 = ConstructNode(8);
	Binary_TreeNode* pNodeA3 = ConstructNode(9);
	Binary_TreeNode* pNodeA4 = ConstructNode(2);
	Binary_TreeNode* pNodeA5 = ConstructNode(5);


	ConnectedNodes(pNodeA1, pNodeA2, nullptr);
	ConnectedNodes(pNodeA2, pNodeA3, nullptr);
	ConnectedNodes(pNodeA3, pNodeA4, nullptr);
	ConnectedNodes(pNodeA4, pNodeA5, nullptr);


	Binary_TreeNode* pNodeB1 = ConstructNode(8);
	Binary_TreeNode* pNodeB2 = ConstructNode(9);
	Binary_TreeNode* pNodeB3 = ConstructNode(3);

	ConnectedNodes(pNodeB1, pNodeB2, nullptr);
	ConnectedNodes(pNodeB2, pNodeB3, nullptr);


	Test("test4", pNodeA1, pNodeB1, false);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

void test5()
{
	Binary_TreeNode* pNodeA1 = ConstructNode(8);
	Binary_TreeNode* pNodeA2 = ConstructNode(8);
	Binary_TreeNode* pNodeA3 = ConstructNode(9);
	Binary_TreeNode* pNodeA4 = ConstructNode(2);
	Binary_TreeNode* pNodeA5 = ConstructNode(5);


	ConnectedNodes(pNodeA1, nullptr,pNodeA2);
	ConnectedNodes(pNodeA2, nullptr,pNodeA3);
	ConnectedNodes(pNodeA3, nullptr,pNodeA4);
	ConnectedNodes(pNodeA4, nullptr,pNodeA5);


	Binary_TreeNode* pNodeB1 = ConstructNode(8);
	Binary_TreeNode* pNodeB2 = ConstructNode(9);
	Binary_TreeNode* pNodeB3 = ConstructNode(2);

	ConnectedNodes(pNodeB1, nullptr,pNodeB2);
	ConnectedNodes(pNodeB2, nullptr,pNodeB3);


	Test("test5", pNodeA1, pNodeB1, true);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

void test6()
{
	Binary_TreeNode* pNodeA1 = ConstructNode(8);
	Binary_TreeNode* pNodeA2 = ConstructNode(8);
	Binary_TreeNode* pNodeA3 = ConstructNode(9);
	Binary_TreeNode* pNodeA4 = ConstructNode(2);
	Binary_TreeNode* pNodeA5 = ConstructNode(5);


	ConnectedNodes(pNodeA1, nullptr, pNodeA2);
	ConnectedNodes(pNodeA2, nullptr, pNodeA3);
	ConnectedNodes(pNodeA3, nullptr, pNodeA4);
	ConnectedNodes(pNodeA4, nullptr, pNodeA5);


	Binary_TreeNode* pNodeB1 = ConstructNode(8);
	Binary_TreeNode* pNodeB2 = ConstructNode(9);
	Binary_TreeNode* pNodeB3 = ConstructNode(3);
	Binary_TreeNode* pNodeB4 = ConstructNode(2);

	ConnectedNodes(pNodeB1, nullptr, pNodeB2);
	ConnectedNodes(pNodeB2, pNodeB3, pNodeB4);


	Test("test6", pNodeA1, pNodeB1, false);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

void test7()
{
	Binary_TreeNode* pNodeB1 = ConstructNode(8);
	Binary_TreeNode* pNodeB2 = ConstructNode(9);
	Binary_TreeNode* pNodeB3 = ConstructNode(3);
	Binary_TreeNode* pNodeB4 = ConstructNode(2);

	ConnectedNodes(pNodeB1, nullptr, pNodeB2);
	ConnectedNodes(pNodeB2, pNodeB3, pNodeB4);

	Test("Test7", nullptr, pNodeB1, false);

	DestroyTree(pNodeB1);
}

void test8()
{
	Binary_TreeNode* pNodeA1 = ConstructNode(8);
	Binary_TreeNode* pNodeA2 = ConstructNode(9);
	Binary_TreeNode* pNodeA3 = ConstructNode(3);
	Binary_TreeNode* pNodeA4 = ConstructNode(2);

	ConnectedNodes(pNodeA1, nullptr, pNodeA2);
	ConnectedNodes(pNodeA2, pNodeA3, pNodeA4);

	Test("Test8", pNodeA1, nullptr, false);

	DestroyTree(pNodeA1);
}

void test9()
{
	Test("Test9", nullptr, nullptr, false);
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
	test9();

	return 0;
}
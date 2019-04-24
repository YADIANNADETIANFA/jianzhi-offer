#include<cstdio>
#include"BinaryTreeNode.h"

using namespace std;

BinaryTreeNode* MidOrderCore(BinaryTreeNode*, unsigned int, unsigned int&,bool&);//�����&

BinaryTreeNode* ConstructNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

void ConnectNodes(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;
	else
	{
		pRoot->pLeft = pLeft;
		pRoot->pRight = pRight;
	}
}
void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	else
	{
		DestroyTree(pRoot->pLeft);
		DestroyTree(pRoot->pRight);
		delete pRoot;
		pRoot = nullptr;
	}
}

BinaryTreeNode* MidOrder(BinaryTreeNode* pRoot, unsigned int k)
{
	if (pRoot == nullptr || k <= 0)
		return nullptr;

	unsigned int m = 0;
	bool is_continue = true;
	return MidOrderCore(pRoot, k, m,is_continue);
}

BinaryTreeNode* MidOrderCore(BinaryTreeNode* pRoot, unsigned int k, unsigned int& m,bool& is_continue)//�����&
{
	BinaryTreeNode* target = nullptr;//�����ǽ���������������ｨһ��target����������MidOrderCore�ķ��ز���
	if (pRoot != nullptr)
	{                                                                                //ѧϰһ�����ϵĽ��˼·
		if (is_continue)
		{
			target = MidOrderCore(pRoot->pLeft, k, m,is_continue);
		}
		if (m == k - 1)
		{
			is_continue = false;
			++m;
			return pRoot;
		}
			//return pRoot;
		//else//�����ⲻ�ܼӣ�mҪ����ÿһ�ζ����£���Ȼ��Զ���Ƿ���������ڵ���
		++m;//�м�㲻�У�ҲҪ++m
		if (is_continue)//û�����������ƣ�target�ܱ������
		{
			target = MidOrderCore(pRoot->pRight, k, m,is_continue);
		}
	}
	//else//��֤���k���������ܽڵ�������Ȼ��nullptr���Ա�����
		return target;
}

void Test(const char* testname, BinaryTreeNode* pRoot, unsigned int k, BinaryTreeNode* pExpected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	BinaryTreeNode* pResult = MidOrder(pRoot, k);
	if (pResult == pExpected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void testA()
{
	BinaryTreeNode* pNode8 = ConstructNode(8);
	BinaryTreeNode* pNode6 = ConstructNode(6);
	BinaryTreeNode* pNode10 = ConstructNode(10);
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode7 = ConstructNode(7);
	BinaryTreeNode* pNode9 = ConstructNode(9);
	BinaryTreeNode* pNode11 = ConstructNode(11);

	ConnectNodes(pNode8, pNode6, pNode10);
	ConnectNodes(pNode6, pNode5, pNode7);
	ConnectNodes(pNode10, pNode9, pNode11);

	Test("testA1", pNode8, 0, nullptr);
	Test("testA2", pNode8, 1, pNode5);
	Test("testA3", pNode8, 2, pNode6);
	Test("testA4", pNode8, 3, pNode7);
	Test("testA5", pNode8, 4, pNode8);
	Test("testA6", pNode8, 5, pNode9);
	Test("testA7", pNode8, 6, pNode10);
	Test("testA8", pNode8, 7, pNode11);
	Test("testA9", pNode8, 8, nullptr);

	DestroyTree(pNode8);
}

void testB()
{
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode1 = ConstructNode(1);

	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);
	ConnectNodes(pNode2, pNode1, nullptr);

	Test("testB1", pNode5, 0, nullptr);
	Test("testB2", pNode5, 1, pNode1);
	Test("testB3", pNode5, 2, pNode2);
	Test("testB4", pNode5, 3, pNode3);
	Test("testB5", pNode5, 4, pNode4);
	Test("testB6", pNode5, 5, pNode5);
	Test("testB7", pNode5, 6, nullptr);


	DestroyTree(pNode5);
}

void testC()
{
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode1 = ConstructNode(1);

	ConnectNodes(pNode1, nullptr, pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode5);

	Test("testC1", pNode1, 0, nullptr);
	Test("testC2", pNode1, 1, pNode1);
	Test("testC3", pNode1, 2, pNode2);
	Test("testC4", pNode1, 3, pNode3);
	Test("testC5", pNode1, 4, pNode4);
	Test("testC6", pNode1, 5, pNode5);
	Test("testC7", pNode1, 6, nullptr);


	DestroyTree(pNode1);
}

void testD()
{
	BinaryTreeNode* pNode = ConstructNode(1);

	Test("testD1", pNode, 0, nullptr);
	Test("TestD2", pNode, 1, pNode);

	DestroyTree(pNode);
}

void testE()
{

	Test("testE1", nullptr, 0, nullptr);
	Test("TestE2", nullptr, 1, nullptr);

}

int main()
{
	testA();
	printf("\n");
	testB();
	printf("\n");
	testC();
	printf("\n");
	testD();
	printf("\n");
	testE();
	return 0;
}
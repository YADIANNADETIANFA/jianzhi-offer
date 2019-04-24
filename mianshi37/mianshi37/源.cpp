#include<cstdio>
#include<iostream>
#include<fstream>
#include"BinaryTreeNode.h"
using namespace std;

bool ReadStream(istream& stream, int* number);

void Serialize(const BinaryTreeNode* pRoot, ostream& stream)//�Ѷ�������ӡ��.txt�ļ�
{
	if (pRoot == nullptr)
	{
		stream << "$,";
		return;
	}
	stream << pRoot->m_value << ',';//����cout��׼�������ǲ����ӡ��������ȥ��
	Serialize(pRoot->m_pleft, stream);
	Serialize(pRoot->m_pright, stream);
}

/*void Deserialize(BinaryTreeNode* pRoot, istream& stream)//һάָ��������
{
	int number;
	if (ReadStream(stream, &number))
	{
		pRoot = new BinaryTreeNode();//��Ҫ������ǣ���nullptr��Ϊ��������Ԫ�صĶ������ڵ�
		pRoot->m_value = number;
		pRoot->m_pleft = nullptr;
		pRoot->m_pright = nullptr;

		Deserialize(pRoot->m_pleft, stream);//pRoot->m_pleft����һ����nullptr����nullptr->m_value = number;���޷�ʵ�ֵ�
		Deserialize(pRoot->m_pright, stream);
	}
	
}*/

void Deserialize(BinaryTreeNode** pRoot, istream& stream)//���һάָ�����˼��,    ��ʱpRoot��ָ�룬*pRoot������
{
	int number;
	if (ReadStream(stream, &number))
	{
		BinaryTreeNode *pRootNew = new BinaryTreeNode();
		pRootNew->m_value = number;
		pRootNew->m_pleft = nullptr;
		pRootNew->m_pright = nullptr;
		*pRoot = pRootNew;

		Deserialize(&((*pRoot)->m_pleft), stream);
		Deserialize(&((*pRoot)->m_pright), stream);
	}
}

bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';//�����������ڵĴ����壬������Ϊ����ʽ�ϵĳ�ʼ��������
	char ch;
	stream >> ch;
	int i = 0;
	while (!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}
	bool isNumberic = false;
	if (i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);//��ʱ�е�ͣ���������Ǹ���������ͣ�ģ�ֻҪ���벻�����֣��͸���ͣ������������
		isNumberic = true;     //����atoi�������һ���ǿո��ַ����ڣ������ֻ�����������ʼ������ת����֮���⵽������(���������� \0) �ַ�ʱֹͣת�������������������򣬷�����
	}
	return isNumberic;
}

bool isSameTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;
	if (pRoot1->m_value != pRoot2->m_value)
		return false;

	return isSameTree(pRoot1->m_pleft, pRoot2->m_pleft) && isSameTree(pRoot1->m_pright, pRoot2->m_pright);
}

BinaryTreeNode* ConstructNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->m_pleft = nullptr;
	pNode->m_pright = nullptr;

	return pNode;
}

void ConnectNodes(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;
	pRoot->m_pleft = pLeft;
	pRoot->m_pright = pRight;
}

void PrintPreOrder(const BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	printf("%d\t", pRoot->m_value);
	PrintPreOrder(pRoot->m_pleft);
	PrintPreOrder(pRoot->m_pright);

}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	BinaryTreeNode* pLeft = pRoot->m_pleft;
	BinaryTreeNode* pRight = pRoot->m_pright;
	delete pRoot;
	pRoot == nullptr;

	DestroyTree(pLeft);
	DestroyTree(pRight);
}

void Test(const char* testname, const BinaryTreeNode* pRoot)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	printf("PrintPreOrder the tree:\n");
	PrintPreOrder(pRoot);
	cout << endl;

	const char* fileName = "test.txt";
	ofstream fileOut(fileName);//�Լ���������test.txt���ġ���������

	Serialize(pRoot, fileOut);
	fileOut.close();

	ifstream fileIn1(fileName);//���л��󣬼�����������ӡ��.txt�ļ��󣬶�һ�¸�.txt�ļ�������������
	char ch;
	//while (!fileIn1.eof())//���ֶ��һ�е����⣬����������޸�
	while(fileIn1.peek()!=EOF)
	{
		fileIn1 >> ch;
		cout << ch;
	}
	fileIn1.close();
	cout << endl;

	ifstream fileIn2(fileName);//׼����ʼ�����л�����.txt������ת��Ϊ������
	BinaryTreeNode* pRootOut = nullptr;
	Deserialize(&pRootOut, fileIn2);//pRootOut��nullptr��û������������ݡ����ǵ�Ŀ���Ǹı�pRootOutָ���ָ�򣬶����Ǹı�pRootOut�����ݡ���ȡ��άָ�롣
	fileIn2.close();

	PrintPreOrder(pRootOut);

	if (isSameTree(pRoot, pRootOut))
		printf("The deserialized tree is same as the original tree.\n");
	else
		printf("The deserialized tree is NOT same as the original tree.\n");

	DestroyTree(pRootOut);//����ɾ�������л����ɵĶ�������ʵ��ԭʼ��������Сtest�н���ɾ��
}

void test0()
{
	BinaryTreeNode* pNode1 = ConstructNode(1);
	BinaryTreeNode* pNode2 = ConstructNode(2);
	BinaryTreeNode* pNode3 = ConstructNode(3);

	ConnectNodes(pNode1, pNode2, pNode3);

	Test("test0", pNode1);

	DestroyTree(pNode1);
}

void test1()
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

	Test("test1", pNode8);

	DestroyTree(pNode8);
}

void test2()
{
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode2 = ConstructNode(2);

	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);

	Test("test2", pNode5);

	DestroyTree(pNode5);
}

void test3()
{
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode4 = ConstructNode(4);
	BinaryTreeNode* pNode3 = ConstructNode(3);
	BinaryTreeNode* pNode2 = ConstructNode(2);

	ConnectNodes(pNode5, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode2);

	Test("test3", pNode5);

	DestroyTree(pNode5);
}

void test4()
{
	BinaryTreeNode* pNode5 = ConstructNode(5);

	Test("test4", pNode5);

	DestroyTree(pNode5);
}

void test5()
{
	BinaryTreeNode* pNode1 = ConstructNode(5);
	BinaryTreeNode* pNode2 = ConstructNode(5);
	BinaryTreeNode* pNode3 = ConstructNode(5);
	BinaryTreeNode* pNode4 = ConstructNode(5);
	BinaryTreeNode* pNode5 = ConstructNode(5);
	BinaryTreeNode* pNode61 = ConstructNode(5);
	BinaryTreeNode* pNode62 = ConstructNode(5);
	BinaryTreeNode* pNode71 = ConstructNode(5);
	BinaryTreeNode* pNode72 = ConstructNode(5);

	ConnectNodes(pNode1, nullptr, pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, pNode4, nullptr);
	ConnectNodes(pNode4, pNode5, nullptr);
	ConnectNodes(pNode5, pNode61, pNode62);
	ConnectNodes(pNode61, pNode71, nullptr);
	ConnectNodes(pNode62, nullptr, pNode72);

	Test("test5", pNode1);

	DestroyTree(pNode1);
}

void test6()
{
	Test("test6", nullptr);

}

int main()
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	return 0;
}
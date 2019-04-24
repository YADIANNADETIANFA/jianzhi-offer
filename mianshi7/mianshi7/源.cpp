#include"BinaryTreeNode.h"
#include<exception>
#include<iostream>
#include<cstdio>//cstdio�еĺ������Ƕ�����һ�����ֿռ�std����ģ����Ҫ����������ֿռ�ĺ���������ü�std::�������ļ�������use namespace std
using namespace std;

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
	{
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nvalue = rootValue;
	root->m_pleft = root->m_pright = nullptr;//��һ������ȷ��������������ͬ����Ҫ����BinaryTreeNode�ĸ���ز���

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
		{
			return root;
		}
		else
		{
			throw exception();//exception��һ����,��Ҫ�����쳣��ͷ�ļ�exception
		}
	}

	int* rootInorder = startInorder;
	while (*rootInorder != rootValue && rootInorder != endInorder)
	{
		++rootInorder;
	}
	if (rootInorder == endInorder && *rootInorder != rootValue)
	{
		throw exception();
	}
	int length = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + length;
	if (length > 0)//֤������������
	{
		root->m_pleft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if ((endInorder - rootInorder) > 0)//���������ڣ�����Ҳ���ж�
	{
		root->m_pright = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

void printPreorder(BinaryTreeNode* t)
{
	if (t != nullptr)
	{
		cout << t->m_nvalue << " ";
		printPreorder(t->m_pleft);
		printPreorder(t->m_pright);
	}
	else
	{
		return;
	}
}

void DestroyTree(BinaryTreeNode* t)
{
	while (t != nullptr)
	{
		//BinaryTreeNode* left = t->m_pleft;
		//BinaryTreeNode* right = t->m_pright;
		//delete t;
		DestroyTree(t->m_pleft);
		DestroyTree(t->m_pright);
		delete t;//delete��freeֻ�����ָ����ָ����ڴ��ͷŵ��ˣ���û�а�ָ�뱾��ɵ�����free��delete֮��
		         //����Ҫ��ָ�������ڴ��ָ����Ϊ�գ���p=NULL������ָ��ָ����ڴ�ռ���Ȼ�ͷ��ˣ�����ָ��p��ֵ���Ǽ�¼���ǿ��ַ���õ�ַ��Ӧ���ڴ���������p�ͳ��ˡ�Ұָ�롱��
		t = nullptr;//���Ǳ����Ҫ���ɵ�ϰ�ߣ���
	}
}

void Test(const char* testname, int*preorder, int* inorder, int length)
{
	if (testname != nullptr)
	{
		printf("%s beings:\n", testname);
	}
	printf("The preorder sequence: ");
	for (int i = 0; i < length; ++i)
	{
		cout << preorder[i] << " ";
	}
	cout << endl;
	printf("The inorder sequence: ");
	for (int i = 0; i < length; ++i)
	{
		cout << inorder[i] << " ";
	}
	cout << endl;
	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		printPreorder(root);
		DestroyTree(root);
	}
	catch (exception& e)//exception���࣬e��һ��ʵ��
	{
		printf("Invalid Input.\n");//����I����i������������ĸ���������������Ǵ�дI
	}

}

void Test1()//��ͨ������
{
	const int length = 8;
	int preorder[length] = { 1,2,4,7,3,5,6,8 };
	int inorder[length] = { 4,7,2,1,5,3,8,6 };
	Test("Test1", preorder, inorder, length);
	cout << endl;
}

void Test2()//���нڵ㶼û���ҽڵ�
{
	const int length = 5;
	int preorder[length] = {1,2,3,4,5};
	int inorder[length] = {5,4,3,2,1};
	Test("Test2", preorder, inorder, length);
	cout << endl;
}

void Test3()//���нڵ㶼û����ڵ�
{
	const int length = 5;
	int preorder[length] = {1,2,3,4,5};
	int inorder[length] = {1,2,3,4,5};
	Test("Test3", preorder, inorder, length);
	cout << endl;
}

void Test4()//ֻ��һ���ڵ�
{
	const int length = 1;
	int preorder[length] = {1};
	int inorder[length] = {1};
	Test("Test4", preorder, inorder, length);
	cout << endl;
}

void Test5()//��ȫ������
{
	const int length = 7;
	int preorder[length] = {1,2,4,5,3,6,7};
	int inorder[length] = {4,2,5,1,6,3,7};
	Test("Test5", preorder, inorder, length);
	cout << endl;
}

void Test6()//��ָ��
{
	//const int length = 8;
	//int preorder[length] = { 1,2,4,7,3,5,6,8 };
	//int inorder[length] = { 4,7,2,1,5,3,8,6 };
	Test("Test6", nullptr, nullptr, 0);
	cout << endl;
}

void Test7()//�����в�ƥ��
{
	const int length = 7;
	int preorder[length] = {1,2,4,5,3,6,7};
	int inorder[length] = {4,2,8,1,6,3,7};
	Test("Test7", preorder, inorder, length);
	cout << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	return 0; 
}

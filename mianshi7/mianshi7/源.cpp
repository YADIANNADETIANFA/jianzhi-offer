// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。
#include"BinaryTreeNode.h"
#include<exception>
#include<iostream>
#include<cstdio>//cstdio中的函数都是定义在一个名字空间std里面的，如果要调用这个名字空间的函数，必须得加std::或者在文件中声明use namespace std
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
	root->m_pleft = root->m_pright = nullptr;//下一步就是确定这两个参数，同样需要集齐BinaryTreeNode四个相关参数

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
		{
			return root;
		}
		else
		{
			throw exception();//exception是一个类,需要处理异常的头文件exception
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
	if (length > 0)//证明左子树存在
	{
		root->m_pleft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if ((endInorder - rootInorder) > 0)//右子树存在，这样也可判断
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
		delete t;//delete和free只负责把指针所指向的内存释放掉了，并没有把指针本身干掉。在free和delete之后，
		         //都需要把指向清理内存的指针置为空，即p=NULL，否则指针指向的内存空间虽然释放了，但是指针p的值还是记录的那块地址，该地址对应的内存是垃圾，p就成了“野指针”。
		t = nullptr;//这是必须的要养成的习惯！！
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
	catch (exception& e)//exception是类，e是一个实例
	{
		printf("Invalid Input.\n");//看看I还是i，看到底输出哪个。。。。输出的是大写I
	}

}

void Test1()//普通二叉树
{
	const int length = 8;
	int preorder[length] = { 1,2,4,7,3,5,6,8 };
	int inorder[length] = { 4,7,2,1,5,3,8,6 };
	Test("Test1", preorder, inorder, length);
	cout << endl;
}

void Test2()//所有节点都没有右节点
{
	const int length = 5;
	int preorder[length] = {1,2,3,4,5};
	int inorder[length] = {5,4,3,2,1};
	Test("Test2", preorder, inorder, length);
	cout << endl;
}

void Test3()//所有节点都没有左节点
{
	const int length = 5;
	int preorder[length] = {1,2,3,4,5};
	int inorder[length] = {1,2,3,4,5};
	Test("Test3", preorder, inorder, length);
	cout << endl;
}

void Test4()//只有一个节点
{
	const int length = 1;
	int preorder[length] = {1};
	int inorder[length] = {1};
	Test("Test4", preorder, inorder, length);
	cout << endl;
}

void Test5()//完全二叉树
{
	const int length = 7;
	int preorder[length] = {1,2,4,5,3,6,7};
	int inorder[length] = {4,2,5,1,6,3,7};
	Test("Test5", preorder, inorder, length);
	cout << endl;
}

void Test6()//空指针
{
	//const int length = 8;
	//int preorder[length] = { 1,2,4,7,3,5,6,8 };
	//int inorder[length] = { 4,7,2,1,5,3,8,6 };
	Test("Test6", nullptr, nullptr, 0);
	cout << endl;
}

void Test7()//两序列不匹配
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

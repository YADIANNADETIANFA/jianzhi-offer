// 面试题68：树中两个结点的最低公共祖先
// 题目：输入两个树结点，求它们的最低公共祖先。
#include"BinaryTreeNode.h"
#include<cstdio>
#include<iostream>
#include<vector>
#include<list>

using namespace std;

BinaryTreeNode* ConstructNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->m_pleft = nullptr;
	pNode->m_p_right = nullptr;

	return pNode;
}

void ConnectNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;
	pRoot->m_pleft = pLeft;
	pRoot->m_p_right;
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	DestroyTree(pRoot->m_pleft);
	DestroyTree(pRoot->m_p_right);

	delete pRoot;
	pRoot = nullptr;
}

bool GetNodePath(BinaryTreeNode* pRoot, BinaryTreeNode* pNode, list<BinaryTreeNode*>& path)//二叉树中，找到某一节点的路径
{
	if (pRoot == pNode)
	{
		path.push_back(pRoot);
		return true;
	}
	
	path.push_back(pRoot);
	/*                  用于非二叉树的情况
	bool found =false;
	vector<TreeNode*>::iterator iter=pRoot->m_vChildren.begin();
	While(!found && iter!=pRoot->m_vChildren.end())
	{
	    found=GetNodePath(*iter,pNode,path);
		iter++;
	}

	if(!found)
	    path.pop_back();

	return found; 
	*/
	bool found1 = GetNodePath(pRoot->m_pleft,pNode,path);
	bool found2 = GetNodePath(pRoot->m_p_right, pNode, path);
	if (!found1 && !found2)
	{
		path.pop_back();
		return false;
	}
	return true;
}

BinaryTreeNode* GetLastParent(list<BinaryTreeNode*> path1, list<BinaryTreeNode*> path2)//两个链表找最后相同的节点
{
	BinaryTreeNode* pLastParent = nullptr;
	list<BinaryTreeNode*>::iterator iter1 = path1.begin();
	list<BinaryTreeNode*>::iterator iter2 = path2.begin();
	
	while (iter1 != path1.end() && iter2 != path2.end())
	{
		if (*iter1 == *iter2)
		{
			pLastParent = *iter1;
			iter1++;
			iter2++;
		}
		else
			return pLastParent;
	}
	return pLastParent;
}

BinaryTreeNode* GetLastCommonNode(BinaryTreeNode* pRoot, BinaryTreeNode* pNode1, BinaryTreeNode* pNode2)//主函数
{
	if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
		return nullptr;

	list<BinaryTreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);
	list<BinaryTreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	return GetLastParent(path1, path2);
}


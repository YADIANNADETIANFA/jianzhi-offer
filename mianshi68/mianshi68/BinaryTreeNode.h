#pragma once
#include<vector>
using namespace std;

struct BinaryTreeNode
{
	int m_value;
	BinaryTreeNode* m_pleft;
	BinaryTreeNode* m_p_right;
	//vector<TreeNode*> m_vChildren;//用于非二叉树的情况
};
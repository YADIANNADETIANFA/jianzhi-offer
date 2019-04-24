#pragma once//保证头文件只被编译一次
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
struct BinaryTreeNode
{
	int m_value;
	BinaryTreeNode* p_left;
	BinaryTreeNode* p_right;
	BinaryTreeNode* p_parent;
};
#endif // !BINARYTREENODE_H


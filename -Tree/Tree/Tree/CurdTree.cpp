#include"Tree.h"
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;


//插入节点 -  通用二叉树插入
//常用于构建完全二叉树
TreeNode* insertLevelOrder(TreeNode* root, int val)
{
	if (!root)return new TreeNode(val);
	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* node = q.front(); q.pop();

		if (!node->left)
		{
			node->left = new TreeNode(val);
			return root;
		}
		else
		{
			q.push(node->left);
		}

		if (!node->right)
		{
			node->right = new TreeNode(val);
		}
		else
		{
			q.push(node->right);
		}
	}
	return root;
}


//查找节点，按值查找目标节点
TreeNode* findNode(TreeNode* root, int target)
{
	if (!root)return nullptr;
	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* node = q.front(); q.pop();
		if (node->val == target)return node;

		if (node->left)q.push(node->left);
		if (node->right)q.push(node->right);
	}
	return nullptr;

}


//删除节点 -  通用二叉树按值删除 -  非搜索树
TreeNode* deleteNode(TreeNode* root, int key)
{
	if (!root)return nullptr;
	if (!root->left && !root->right)
	{
		if (root->val == key)
		{
			delete root;
			return nullptr;
		}
		else
		{
			return root;
		}
	}
	TreeNode* keyNode = nullptr;
	TreeNode* last = nullptr;
	TreeNode* parent = nullptr;

	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* node = q.front(); q.pop();
		if (node->val == key)keyNode = node;
		if (node->left)
		{
			parent = node;
			last = node->left;
			q.push(node->left);
		}
		if (node->right)
		{
			parent = node;
			last = node->right;
			q.push(node->right);
		}
	}
	if (keyNode)
	{
		keyNode->val = last->val;

		//删除最深节点
		if (parent->right == last)
		{
			delete parent->right;
			parent->right = nullptr;
		}
		else
		{
			delete parent->left;
			parent->left = nullptr;
		}
	}
	return root;
	
}
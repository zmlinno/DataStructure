#pragma once
#include"recursive.h"
#include<algorithm>
//AVL树和基本树
//jiben
using namespace std;

TreeNode::TreeNode(int x) :val(x),left(nullptr),right(nullptr){}

BinaryTree::BinaryTree():root(nullptr){}
BinaryTree::~BinaryTree() { destrotTree(root); }

BinaryTree::~BinaryTree()
{
	destrotTree(root);
}

void BinaryTree::destrotTree(TreeNode* node)
{
	if (!node)return;
	destrotTree(node->left);
	destrotTree(node->right);
	delete node;
}
int BinaryTree::getHeight(TreeNode* node)
{
	return node ? node->height : 0;
}


int BinaryTree::getBalance(TreeNode* node)
{
	return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

TreeNode* BinaryTree::rotateRight(TreeNode* y)
{
	TreeNode* x = y->left;
	TreeNode* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	return x;
}


TreeNode* BinaryTree::insert(TreeNode* node, int val)
{
	if (!node)return new TreeNode(val);
	if (val < node->val)
	{
		node->left = insert(node->left, val);
	}
	else
	{
		node->right = insert(node->right, val);
	}
	return node;
}


void BinaryTree::insert(int val)
{
	root = insert(root, val);
}

void BinaryTree::inorderTraversal()
{
	inorderTraversal(root);
	cout << endl;
}

void BinaryTree::inorderTraversal(TreeNode* node)
{
	if (!node)return;
	inorderTraversal(node->left);
	cout << node->val << " ";
	inorderTraversal(node->right);
}

int BinaryTree::maxDepth()
{
	return maxDepth(root);
}

int BinaryTree::maxDepth(TreeNode* node)
{
	if (!node)return 0;
	int left = maxDepth(node->left);
	int right = maxDepth(node->right);
	return 1 + max(left, right);
}


bool BinaryTree::search(int target)
{
	return search(root, target);
}

bool BinaryTree::search(TreeNode* node, int target)
{
	if (!node)return false;
	if (node->val  == target) return true;
	if (target < node->val)
	{
		return search(node->left, target);
	}
	else
	{
		return search(node->right, target);
	}
}

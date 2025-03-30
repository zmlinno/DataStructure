#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>

struct TreeNode
{
	int val;
	int height;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x); //构造函数
};

class BinaryTree
{
public:
	BinaryTree(); //构造函数
	~BinaryTree();//析构函数

	void insert(int val); //插入节点 
	void remove(int val); //删除节点
	void inorderTraversal(); //中序遍历
	int maxDepth(); //求最大深度
	bool search(int target);  //查找某个值

private:
	TreeNode* root;

	//内部递归函数
	TreeNode* insert(TreeNode* node, int val);
	TreeNode* deleteNode(TreeNode* node, int val);
	TreeNode* minValueNode(TreeNode* node);
	void inorderTraversal(TreeNode* node);
	int maxDepth(TreeNode* node);
	bool search(TreeNode* node, int target);
	void destrotTree(TreeNode* node); //释放内存


	//平衡相关
	int getHeight(TreeNode* node);
	int getBalance(TreeNode* node);
	TreeNode* rotateLeft(TreeNode* node);
	TreeNode* rotateRight(TreeNode* node);
	TreeNode* balance(TreeNode* node);

};
#endif // !BINARYTREE_H

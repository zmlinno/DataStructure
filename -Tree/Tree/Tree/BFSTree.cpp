#include"BFSTree.h"


//构造函数实现
BFSTreeNode::BFSTreeNode(int x)
{
	val = x;
	left = nullptr;
	right = nullptr;
}
BFSTreeNode* insertBST(BFSTreeNode* root, int val)
{
	if (!root)return new BFSTreeNode(val);

	if (val < root->val)
	{
		root->left = insertBST(root->left, val);
	}
	else if (val > root->val)
	{
		root->right = insertBST(root->right, val);
	}
	return root;
}



BFSTreeNode* searchBST(BFSTreeNode* root, int target)
{
	//bst查找节点
	if (!root || root->val == target)return root;
	if (target < root->val)
	{
		return searchBST(root->left, target);
	}
	else
		return searchBST(root->right, target);
}


//迭代实现
BFSTreeNode* searchBSTIter(BFSTreeNode* root, int target)
{
	while (root)
	{
		if (target == root->val) return root;
		else if (target < root->val) root = root->left;
		else root = root->right;
	}
	return nullptr;
}




//bst删除节点
BFSTreeNode* deleteBST(BFSTreeNode* root, int key)
{
	if (!root)return nullptr;

	if (key < root->val)
	{
		root->left = deleteBST(root->left, key);
	}
	else if (key > root->val)
	{
		root->right = deleteBST(root->right, key);
	}
	else
	{
		//情况1 无子
		if (!root->left && !root->right)
		{
			delete root;
			return nullptr;
		}

		//情况2 只有右子
		else if(!root->left)
		{
			BFSTreeNode* temp = root->right;
			delete root;
			return temp;
		}
		//情况3 只有左子
		else if (!root->right)
		{
			BFSTreeNode* temp = root->left;
			delete root;
			return temp;
		}

		//情况4 两个子节点
		BFSTreeNode* succ = root->right;
		while (succ->left)succ = succ->left; //找中序
		root->val = succ->val; //用后继值替换
		root->right = deleteBST(root->right, succ->val);
	}
	return root;
}



void printInOrder(BFSTreeNode* root)
{
	if (!root)return;
	printInOrder(root->left);
	cout << root->val << " ";
	printInOrder(root->right);
}

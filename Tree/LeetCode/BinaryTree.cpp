#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
#include<algorithm>

//递归版中序遍历
void Solution::inorder(TreeNode* root, vector<int>& res)
{
	if (!root)return;
	inorder(root->left,res);
	res.push_back(root->val);
	inorder(root->right,res);
}


//递归调用接口
vector<int>Solution::inorderTraversalRecursive(TreeNode* root)
{
	vector<int>res;
	inorder(root, res);
	return res;
}

//迭代版中序遍历
vector<int>Solution::inorderTraversal(TreeNode* root)
{
	vector<int>res;
	stack<TreeNode*>st;
	TreeNode* curr = root;

	while (curr || st.empty())
	{
		while (curr)
		{
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		res.push_back(curr->val);
		curr = curr->right;
	}
	return res;
}





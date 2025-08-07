#include"Tree.h"
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


//1.非递归中序遍历
//栈模拟
void printInOrderIterative(TreeNode* root)
{
	stack<TreeNode*>stk;
	TreeNode* curr = root;

	while (curr || !stk.empty())
	{
		while (curr)
		{
			stk.push(curr);
			curr = curr->left;
		}
		curr = stk.top(); stk.pop();
		cout << curr->val << " ";
		curr = curr->right;
	}

}


//2.非递归前序遍历
void printPreOrderIterative(TreeNode* root)
{
	if (!root)return;
	stack<TreeNode*>stk;
	stk.push(root);

	while (!stk.empty())
	{
		TreeNode* node = stk.top(); stk.pop();
		cout << node->val << " ";

		//先压右，在压左
		if (node->right)stk.push(node->right);
		if (node->left)stk.push(node->left);
	}
}


//3.双栈法
void printPostOrderIterative(TreeNode* root)
{
	if (!root)return;
	stack<TreeNode*>stk1, stk2;

	stk1.push(root);
	while (!stk1.empty())
	{
		TreeNode* node = stk1.top(); stk1.pop();
		stk2.push(node);
		if (node->left)stk1.push(node->left);
		if (node->right)stk1.push(node->right);
	}
	while (!stk2.empty())
	{
		cout << stk2.top()->val << " ";
		stk2.pop();
	}
}
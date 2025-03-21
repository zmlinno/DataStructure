#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"

int main()
{
	//构造测试二叉树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution sol;

	//递归方式 遍历
	vector<int>recursiveResult = sol.inorderTraversalRecursive(root);
	cout << "递归中序遍历: ";
	for (int num : recursiveResult)
	{
		cout << num << " ";
	}
	cout << endl;

	//迭代方式遍历
	vector<int>iterativeResult = sol.inorderTraversal(root);
	cout << "迭代中序遍历: ";
	for (int num : iterativeResult)
	{
		cout << num << " ";
	}
	cout << endl;

	Solution solution;

	//手动创建二叉树
	//TreeNode* root = new TreeNode(3);
	//root->left = new TreeNode(9);
	//root->right = new TreeNode(20);
	//root->right->left = new TreeNode(15);
	//root->right->right = new TreeNode(7);

	cout << "二叉树的最大的深度: " << solution.maxDepth(root) << endl;
	cout << endl;
	return 0;
}
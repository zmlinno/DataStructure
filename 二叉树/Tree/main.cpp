#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};


//前序遍历
void printPerOrder(TreeNode* node)
{
	if (node == nullptr)return;;
	cout << node->val << " ";
	printPerOrder(node->left);
	printPerOrder(node->right);
	// 1 2 4 5 3
}

//中序遍历
void Inorder(TreeNode* node)
{
	if (node == nullptr)return;
	Inorder(node->left);
	cout << node->val << " ";
	Inorder(node->right);
}

//判断叶子节点 - 没有子节点的节点
bool isLeaf(TreeNode* node)
{
	return node != nullptr && node->left == nullptr && node->right == nullptr;
}

//获取最大高度
int treeHeight(TreeNode* node)
{
	if (node == nullptr)return 0;
	return 1 + max(treeHeight(node->left), treeHeight(node->right));
}

//统计节点总数函数
int countNodes(TreeNode* node)
{
	if (node == nullptr)return 0;
	return 1 + countNodes(node->left) + countNodes(node->right);
}


//代码访问子节点
void printArrayTree(int tree[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "节点数: " << tree[i] << endl;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < size)
		{
			cout << "左子树: " << tree[l] << endl;
		}
		if (r > size)
		{
			cout << "右子树: " << tree[r] << endl;
		}
		cout << endl;
	}
}


//顺序结构中查找某个值是否存在
bool findInArrayTree(int tree[], int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (tree[i] == target)
		{
			return true;
		}
		return false;
	}
}
//内存释放防止泄漏
void DeleteTree(TreeNode* node)
{
	if (node == nullptr)return;
	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;

}
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	printPerOrder(root);
	cout << endl;
	//节点4是子叶节点吗
	cout << "节点 4 是叶子节点吗？" << (isLeaf(root->left->left) ? "是" : "否") << endl;
	//打印最大高度
	cout << treeHeight(root) << endl;
	//打印总节点数
	cout << countNodes(root) << endl;

	int tree[] = { 1,2,3,4,5 };
	int size = sizeof(tree) / sizeof(tree[0]);

	cout << "查找3" << (findInArrayTree(tree, size, 3) ? "找到了" : "没找到") << endl;
	cout << "查找6" << (findInArrayTree(tree, size, 6) ? "找到了" : "没找到") << endl;
	return 0;
}
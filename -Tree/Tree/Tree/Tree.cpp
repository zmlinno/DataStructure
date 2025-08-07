#include "Tree.h"
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
TreeNode::TreeNode(int x)
{
    val = x;
    left = nullptr;
    right = nullptr;
}


bool isLeaf(TreeNode* node) {
    return node != nullptr && node->left == nullptr && node->right == nullptr;
}

int treeHeight(TreeNode* node) {
    if (node == nullptr) return 0;
    return 1 + max(treeHeight(node->left), treeHeight(node->right));
}



TreeNode* insertLeverder(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (!node->left) {
            node->left = new TreeNode(val);
            return root;
        }
        else q.push(node->left);
        if (!node->right) {
            node->right = new TreeNode(val);
            return root;
        }
        else q.push(node->right);
    }
    return root;
}

//二叉树层序遍历 - 使用队列
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}


//后序遍历
void printPostOrder(TreeNode* node)
{
    if (node == nullptr)return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->val << " "; 
    //左右中
    
}


void printZhongXu(TreeNode* node)
{
    if (node == nullptr)return;
    printZhongXu(node->left);
    cout << node->val << " ";
    printZhongXu(node->right);
    
}


void printPreOrder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}



//关于链式结构的完全二叉树根节点
//从数组构建链式结构的完全二叉树
TreeNode* buildFromArray(int arr[], int n)
{
    if (n == 0)return nullptr;

    //创建所有节点
    TreeNode** nodes = new TreeNode * [n];
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new TreeNode(arr[i]);
    }

    //连接左右子节点
    for (int i = 0; i < n; i++)
    {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        if (leftIndex < n)nodes[i]->left = nodes[leftIndex];
        if (rightIndex < n)nodes[i]->right = nodes[rightIndex];
    }

    TreeNode* root = nodes[0];
    delete[] nodes;
    return root;
 }





//判断是否为完全二叉树
bool isCompleteTree(TreeNode* root)
{
    //思路 - 层序遍历 + 标记遇到空姐点

    if (!root)return true;
    queue<TreeNode*>q;
    q.push(root);
    bool reachedNull = false;

    while (!q.empty())
    {
        TreeNode* node = q.front(); q.pop();
        if (node == nullptr)
        {
            reachedNull = true;
        }
        else
        {
            if (reachedNull)return false; //后面出现非空节点，不合法
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}
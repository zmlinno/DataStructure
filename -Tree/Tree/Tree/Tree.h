#ifndef Tree_hpp
#define Tree_hpp


#pragma once
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x);
};

bool isLeaf(TreeNode* node);
int treeHeight(TreeNode* node);
void printPreOrder(TreeNode* node);
void printLevelOrder(TreeNode* root);
//后序遍历
void printPostOrder(TreeNode* node);
//中序遍历
void printZhongXu(TreeNode* node);
TreeNode* insertLeverder(TreeNode* root, int val);
TreeNode* insertLevelOrder(TreeNode* root, int val);

//关于链式结构的完全二叉树根节点
TreeNode* buildFromArray(int arr[], int n);

//判断是否为完全二叉树
bool isCompleteTree(TreeNode* root);


//非递归三种排序
//1.非递归中序遍历
void printInOrderIterative(TreeNode* root);
//2.非递归前序遍历
void printPreOrderIterative(TreeNode* root);
//3.双栈法
void printPostOrderIterative(TreeNode* root);


//二叉树的增删查改节点
//插入节点，通用二叉树插入
TreeNode* insertLevelOrder(TreeNode* root, int val);
//查找节点，按值查找目标节点
TreeNode* findNode(TreeNode* root, int target);
//删除节点
TreeNode* deleteNode(TreeNode* root, int key);
#endif /* Tree_hpp */

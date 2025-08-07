#ifndef BFS_HPP
#define BFS_HPP
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

struct BFSTreeNode
{
	int val;
	BFSTreeNode* left;
	BFSTreeNode* right;
	BFSTreeNode(int x);
};
BFSTreeNode* insertBST(BFSTreeNode* root, int val);

//bst查找节点
BFSTreeNode* searchBST(BFSTreeNode* root, int target);


//迭代实现 - 面试常考
BFSTreeNode* searchBSTIter(BFSTreeNode* root, int target);


//BST删除节点 - 难点
BFSTreeNode* deleteBST(BFSTreeNode* root, int key);

void printInOrder(BFSTreeNode* root);


#endif
#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 解决方案类
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root);  // 迭代遍历
    vector<int> inorderTraversalRecursive(TreeNode* root); // 递归遍历



    //104
    int maxDepth(TreeNode* root)
    {
        if (!root)return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;

    }

private:
    void inorder(TreeNode* root, vector<int>& res);
};

#endif // BINARYTREE_H
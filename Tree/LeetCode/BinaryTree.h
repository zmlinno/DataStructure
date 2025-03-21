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



    //对称
    bool isSymmetric(TreeNode* root)
    {
        if (!root)return true;
        return isMiior(root->left, root->right);
    }

    bool isMiior(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)return true;//两个都为空，返回true
        if (!left || !right)return false;//其中一个为空，不对称
        if (left->val != right->val)return false;

        return isMiior(left->left, right->right) && (left->right, right->left);
    }



private:
    void inorder(TreeNode* root, vector<int>& res);
};

#endif // BINARYTREE_H

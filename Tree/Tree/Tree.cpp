//
//  Tree.cpp
//  Tree
//
//  Created by 张木林 on 7/19/25.
//

#include "Tree.hpp"
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

void printPreOrder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

TreeNode* insertLevelOrder(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (!node->left) {
            node->left = new TreeNode(val);
            return root;
        } else q.push(node->left);
        if (!node->right) {
            node->right = new TreeNode(val);
            return root;
        } else q.push(node->right);
    }
    return root;
}

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


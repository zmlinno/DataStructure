//
//  AVLTree.cpp
//  Tree
//
//  Created by 张木林 on 4/3/25.
//

#include "AVLTree.hpp"
#include<iostream>
#include<algorithm>

BTNode::BTNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroy(root);
}

void AVLTree::destroy(BTNode* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}


//获取节点高度
int AVLTree::getHeight(BTNode* node) {
    return node ? node->height : 0;
}


//获取节点平衡因子
int AVLTree::getBalance(BTNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

//左旋结构调整
BTNode* AVLTree::rotateLeft(BTNode* x) {
    BTNode* y = x->right;
    BTNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

BTNode* AVLTree::rotateRight(BTNode* y) {
    BTNode* x = y->left;
    BTNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

BTNode* AVLTree::balance(BTNode* node) {
    if (!node) return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    // LL
    if (balance > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);

    // LR
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RR
    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);

    // RL
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

BTNode* AVLTree::insert(BTNode* node, int val) {
    if (!node) return new BTNode(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node;

    return balance(node);
}

void AVLTree::insert(int val) {
    root = insert(root, val);
}

BTNode* AVLTree::minValueNode(BTNode* node) {
    BTNode* current = node;
    while (current->left)
        current = current->left;
    return current;
}

BTNode* AVLTree::remove(BTNode* node, int val) {
    if (!node) return node;

    if (val < node->val)
        node->left = remove(node->left, val);
    else if (val > node->val)
        node->right = remove(node->right, val);
    else {
        if (!node->left || !node->right) {
            BTNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        } else {
            BTNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = remove(node->right, temp->val);
        }
    }

    return balance(node);
}

void AVLTree::remove(int val) {
    root = remove(root, val);
}

void AVLTree::inorder() {
    inorder(root);
    cout << endl;
}

void AVLTree::inorder(BTNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

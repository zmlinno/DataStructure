//
//  CharBinaryTree.hpp
//  Tree
//
//  Created by 张木林 on 4/1/25.
//

#ifndef CharBinaryTree_hpp
#define CharBinaryTree_hpp

#include <stdio.h>
#include <iostream>
#include <queue>

typedef char BTDataType;

struct BTNode
{
    BTDataType data;
    BTNode* left;
    BTNode* right;
    
    BTNode(BTDataType val);
};

//构建销毁
BTNode* BinaryTreeCreate(const char* str,int& index);
void BinaryTreeDestroy(BTNode*& root);

//节点信息
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root,int k);
BTNode* BinaryTreeFind(BTNode* root,BTDataType x);

//遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);


// 判断完全二叉树
bool BinaryTreeComplete(BTNode* root);

#endif /* CharBinaryTree_hpp */

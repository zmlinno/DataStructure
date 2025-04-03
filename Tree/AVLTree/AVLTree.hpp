//
//  AVLTree.hpp
//  Tree
//
//  Created by 张木林 on 4/3/25.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <stdio.h>
#include<iostream>
using namespace std;

struct BTNode
{
    int val;
    int height;
    BTNode* left;
    BTNode* right;
    
    BTNode(int x);
};

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    
    void insert(int val);
    void remove(int val);
    void inorder();//中序遍历
private:
    BTNode* root;
    
    
    //内部递归函数
    BTNode* insert(BTNode* node,int val);
    BTNode* remove(BTNode* node,int val);
    BTNode* minValueNode(BTNode* node);
    
    void inorder(BTNode* node);
    void destroy(BTNode* node);
    
    //平衡操作
    int getHeight(BTNode* node);
    int getBalance(BTNode* node);
    BTNode* balance(BTNode* node);
    BTNode* rotateLeft(BTNode* node);
    BTNode* rotateRight(BTNode* node);
    
};
#endif /* AVLTree_hpp */

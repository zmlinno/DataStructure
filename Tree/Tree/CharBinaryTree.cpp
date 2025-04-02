//
//  CharBinaryTree.cpp
//  Tree
//
//  Created by 张木林 on 4/1/25.
//

#include "CharBinaryTree.hpp"
using namespace std;

BTNode::BTNode(BTDataType val):data(val),left(nullptr),right(nullptr){}

//根据先序字符串构建二叉树
BTNode* BinaryTreeCreate(const char* str,int& index)
{
    if(!str[index] || str[index] == '#')
    {
        index++;
        return nullptr;
    }
    
    BTNode* node = new BTNode(str[index++]);
    node->left = BinaryTreeCreate(str, index);
    node->right = BinaryTreeCreate(str,index);
    return node;
}


//递归销毁二叉树
void BinaryTreeDestroy(BTNode*& root)
{
    if(!root)return;
    BinaryTreeDestroy(root->left);
    BinaryTreeDestroy(root->right);
    delete root;
    root = nullptr;
}



//统计所有节点个数
int BinaryTreeSize(BTNode* root)
{
    if(!root) return 0;
    return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

//统计叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return BinaryTreeLeafSize(root->left)+BinaryTreeLeafSize(root->right);
}


//第k层的节点数量
int BinaryTreeLevelKSize(BTNode* root, int k) {
    if (!root || k <= 0) return 0;
    if (k == 1) return 1;
    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}


BTNode* BinaryTreeFind(BTNode*root,BTDataType x)
{
    if(!root)return nullptr;
    if(root->data == x)return root;
    BTNode* left = BinaryTreeFind(root->left, x);
    if(left)return left;
    return BinaryTreeFind(root->right, x);
}


void BinaryTreePrevOrder(BTNode* root)
{
    if(!root)return;
    cout<<root->data<<" ";
    BinaryTreePrevOrder(root->left);
    BinaryTreePrevOrder(root->right);
}


void BinaryTreeInOrder(BTNode* root)
{
    if(!root)return;
    BinaryTreeInOrder(root->left);
    cout<<root->data<<" ";
    BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
    if(!root)return;
    BinaryTreePostOrder(root->left);
    BinaryTreePostOrder(root->right);
    cout<<root->data<<" ";
}


//层序遍历 BFS
void BinaryTreeLevelOrder(BTNode* root)
{
    if(!root)return;
    queue<BTNode*> q;
    q.push(root);
    while(!q.empty())
    {
        BTNode* cur = q.front();q.pop();
        cout<<cur->data<<" ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}


//判断是否为完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
    if(!root)return true;
    
    queue<BTNode*>q;
    q.push(root);
    bool mustBeLeaf = false;
    
    while(!q.empty())
    {
        BTNode* node = q.front();q.pop();
        
        if(node->left)
        {
            if(mustBeLeaf)return false;
            q.push(node->left);
        }
        else
        {
            mustBeLeaf = true;
        }
        
        if(node->right)
        {
            if(mustBeLeaf)return false;
            q.push(node->right);
        }
        else
        {
            mustBeLeaf = true;
        }
    }
    return true;
}

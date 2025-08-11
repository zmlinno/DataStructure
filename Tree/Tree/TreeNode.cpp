//
//  TreeNode.cpp
//  Tree
//
//  Created by 张木林 on 8/8/25.
//

#include "TreeNode.hpp"
#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;


//TreeNode构造函数
TreeNode::TreeNode(int v)
{
    val = v;
    left = nullptr;
    right = nullptr;
}


//BinaryTree构造函数
BinaryTree::BinaryTree()
{
    root = nullptr;
}


//我们先创建一个简单的二叉树
void BinaryTree::createDemoTree()
{
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
}


//前序遍历
void BinaryTree::preorder(TreeNode *node)
{
    if(node)
    {
        cout<<node->val<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}


void BinaryTree::printPreorder()
{
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
}

//中序遍历
void BinaryTree::inorder(TreeNode *node)
{
    if(node)
    {
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }
}

void BinaryTree::printInorder()
{
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
}

//后序遍历
void BinaryTree::postorder(TreeNode *node)
{
    if(node)
    {
        postorder(node->left);
        postorder(node->right);
        cout<<node->val<<" ";
    }
}

void BinaryTree::printPostorder()
{
    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
}


//层序遍历
void BinaryTree::printLevelOrder()
{
    cout<<"Level Order: ";
    if(!root)return;
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        cout<<node->val<<" ";
        
        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }
            
    }
    cout<<endl;
    
}




//路径总和
int BinaryTree::dfs(TreeNode* node,long long targetSum)
{
    if(!node)return 0;
    int count = (node->val == targetSum) ? 1:0;
    count += dfs(node->left,targetSum - node->val);
    count += dfs(node->right,targetSum - node->val);
    return count;
}

int BinaryTree::pathSum(TreeNode *root, int targetSum)
{
    if(!root)return 0;
    
    return dfs(root,targetSum)
    + pathSum(root->left,targetSum)
    + pathSum(root->right,targetSum);
}

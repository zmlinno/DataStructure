//
//  Tree.hpp
//  Tree
//
//  Created by 张木林 on 7/19/25.
//

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
TreeNode* insertLevelOrder(TreeNode* root, int val);
void printLevelOrder(TreeNode* root);
#endif /* Tree_hpp */

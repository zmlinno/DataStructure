//
//  TreeNode.hpp
//  Tree
//
//  Created by 张木林 on 8/8/25.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v); //构造函数声明
};


//定于树的结构
class BinaryTree
{
private:
    TreeNode* root;
    
    //辅助递归函数
    void preorder(TreeNode* node);
    void inorder(TreeNode* node);
    void postorder(TreeNode* node);
    
public:
    BinaryTree();
    
    void createDemoTree();
    void printPreorder();
    void printInorder();
    void printPostorder();
    
    //层序遍历函数
    void printLevelOrder();
};
#endif /* TreeNode_hpp */

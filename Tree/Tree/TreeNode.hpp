//
//  TreeNode.hpp
//  Tree
//
//  Created by 张木林 on 8/8/25.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include<vector>
#include<unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x);
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
    
    int dfs(TreeNode* node,long long targetSum);
    
    
public:
    BinaryTree();
    TreeNode* getRoot()
    {
        return root;
    }
    
    void createDemoTree();
    void printPreorder();
    void printInorder();
    void printPostorder();
    
    //层序遍历函数
    void printLevelOrder();
    
    //路径总和3
    int pathSum(TreeNode* root,int targetSum);
    
    
    
};
#endif /* TreeNode_hpp */

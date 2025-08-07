//
//  main.cpp
//  Tree
//
//  Created by 张木林 on 7/19/25.
//


#include <iostream>
#include "Tree.hpp"
using namespace std;

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "前序遍历: ";
    printPreOrder(root);
    cout << endl;

    cout << "高度: " << treeHeight(root) << endl;

    root = insertLevelOrder(root, 6);
    cout << "层序遍历: ";
    printLevelOrder(root);

    return 0;
}

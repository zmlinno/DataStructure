//
//  main.cpp
//  Tree
//
//  Created by 张木林 on 8/8/25.
//

#include <iostream>
#include"TreeNode.hpp"
int main(int argc, const char * argv[]) {
    BinaryTree tree;
    tree.createDemoTree();
    
    tree.printPreorder();
    tree.printInorder();
    tree.printPostorder();
    tree.printLevelOrder();
    
    BinaryTree tree1;
    tree1.createDemoTree();
    cout << tree1.pathSum(tree.getRoot(), 8) << endl;
    return 0;
}

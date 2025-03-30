#pragma once
#include"recursive.h"

int main() {
    BinaryTree tree;

    // 插入数据构造树
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);

    // 中序遍历
    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal();

    // 求最大深度
    std::cout << "Max Depth: " << tree.maxDepth() << std::endl;

    // 查找值
    int val = 4;
    std::cout << "Search " << val << ": "
        << (tree.search(val) ? "Found" : "Not Found") << std::endl;

    return 0;
}
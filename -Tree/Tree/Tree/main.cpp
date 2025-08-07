#include <iostream>
//#include "Tree.h"
#include"BFSTree.h"
using namespace std;

int main() {
    //TreeNode* root = new TreeNode(1);
    //root->left = new TreeNode(2);
    //root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);

    //cout << "前序遍历: ";
    //printPreOrder(root);
    //cout << endl;

    //cout << "高度: " << treeHeight(root) << endl;

    //root = insertLevelOrder(root, 6);
    //cout << "层序遍历: ";
    //printLevelOrder(root);

    ////后序遍历
    //cout << "后序遍历: ";
    //printPostOrder(root);

    //cout << endl;

    //cout << "中序遍历: ";
    //printZhongXu(root);

    //cout << endl;

    //int arr[] = { 1,2,3,4,5,6 };
    //int size = sizeof(arr) / sizeof(arr[0]);
    //TreeNode* root1 = buildFromArray(arr, size);
    //cout << "层序遍历构建出来的时: ";
    //printLevelOrder(root1);


    //关于BFS二叉搜索树增删查改
    BFSTreeNode* root = nullptr;
    root = insertBST(root, 10);
    insertBST(root, 5);
    insertBST(root, 15);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 12);
    insertBST(root, 18);

    // BST 构建完成后：
    printInOrder(root);  // 3 5 7 10 12 15 18

    // 查找
    BFSTreeNode* node = searchBST(root, 7);
    cout << (node ? "找到7" : "未找到7") << endl;

    // 删除
    root = deleteBST(root, 10);  // 删除根节点
    printInOrder(root);  // 应变成 3 5 7 12 15 18（10 被删除）

    //BST 构建完成后
    
    return 0;
}
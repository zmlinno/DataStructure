#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;



// 定义二叉树节点
struct TreeNode {
    int data;               // 数据域
    TreeNode* left;         // 指向左子节点
    TreeNode* right;        // 指向右子节点

    // 构造函数
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 二叉树类
class BinaryTree {
public:
    TreeNode* root; // 树的根节点

    // 构造函数
    BinaryTree() : root(nullptr) {}

    // 插入节点
    void insert(int val) {
        root = insertNode(root, val);
    }

    
    //前序遍历
    void PostorderTravelsal()
    {
        preorder(root);
        cout << endl;
    }
    // 中序遍历（递归）
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }

    //后序遍历
    void PosorderTraversal()
    {
        postorder(root);
        cout << endl;
    }

private:
    // 递归插入节点
    TreeNode* insertNode(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->data) {
            node->left = insertNode(node->left, val);
        }
        else {
            node->right = insertNode(node->right, val);
        }
        return node;
    }
    //递归前序遍历
    void preorder(TreeNode* node)
    {
        if (node == nullptr)return;
        //前序遍历
        //根-左-右
        cout << node->data << " "; //根
        preorder(node->left);
        preorder(node->right);
    }

    // 递归中序遍历
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    //递归后续遍历
    void postorder(TreeNode* node)
    {
        if (node == nullptr)return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

// 主函数
int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "前序遍历结果: ";
    tree.PostorderTravelsal();

    cout << "中序遍历结果: ";
    tree.inorderTraversal(); // 输出应为 2 3 4 5 6 7 8

    cout << "后序遍历结果: ";
    tree.PosorderTraversal();

    return 0;
}
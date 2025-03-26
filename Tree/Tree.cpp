#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//二叉树


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


    void printAllLeftSubtree()
    {
        if (root && root->left)
        {
            cout << "所有左子树的值: ";
            printLeftSubtree(root->left);
            cout << endl;
        }
        else
        {
            cout << "树没有左子树: " << endl;
        }
    }

    void printAllRigthSubtree()
    {
        if (root && root->right)
        {
            cout << "右子树的值: " << endl;
            printRightSubtree(root->right);
            cout << endl;
        }
        else
        {
            cout << "没有右子树的值" << endl;
        }
    }


    void deleKey(int key)
    {
        root = deleteNode(root, key);
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

    //如果说我们只打印左子树的值
    void printLeftSubtree(TreeNode* node)
    {
        if (node == nullptr)return;
        cout << node->data << " ";
        printLeftSubtree(node->left);
    }

    void printRightSubtree(TreeNode* node)
    {
        if (node == nullptr)return;
        cout << node->data << " ";
        printRightSubtree(node->right);
    }



    //删除
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (!root)return nullptr;

        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);//递归寻找要删除的节点

        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
   
        else
        {
            //找到要删除的节点
            //情况1 叶子节点 直接删除
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }

            //情况2 只有一个子节点，用子节点代替当前节点
            if (!root->left) //只有右子节点
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
                
            }

            if (!root->right)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //情况3，有两个子节点
            //找到中序后继 - 右子树的最小值
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    TreeNode* findMin(TreeNode* node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    

};

// 主函数
int main() {
    BinaryTree tree;
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    tree.insert(6);
    tree.insert(10);
    tree.insert(11);
    tree.insert(1);
    tree.insert(12);
    tree.insert(0);


    //cout << "前序遍历结果: ";
    //tree.PostorderTravelsal();

    //cout << "中序遍历结果: ";
    //tree.inorderTraversal(); // 输出应为 2 3 4 5 6 7 8

    //cout << "后序遍历结果: ";
    //tree.PosorderTraversal();
    
  /*  tree.printAllLeftSubtree();
    cout << endl;

    tree.printAllRigthSubtree();*/


    //cout << "中序遍历删除前: ";
    //tree.inorderTraversal();

    //删除6
    tree.deleKey(6);
    cout << "中序遍历删除后: ";
    tree.inorderTraversal();
    cout << endl;

    return 0;
}

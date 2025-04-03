//
//  main.cpp
//  Tree
//
//  Created by 张木林 on 4/1/25.
//

#include <iostream>
//#include"CharBinaryTree.hpp"
#include"AVLTree/AVLTree.hpp"
using namespace std;


int main()
{
//    const char* str = "ABD##E#H##CF##G##";
//    int index = 0;
//    BTNode* root = BinaryTreeCreate(str, index);
//    
//    cout<<"前序: ";
//    BinaryTreePrevOrder(root);
//    cout<<"\n中序: ";
//    BinaryTreeInOrder(root);
//    cout<<"\n后序: ";
//    BinaryTreePostOrder(root);
//    cout<<"\n层序: ";
//    BinaryTreeLevelOrder(root);
//    
//    
//    cout<<"\n节节点数: "<<BinaryTreeSize(root)<<endl;
//    cout<<"叶子节点数: "<<BinaryTreeLeafSize(root)<<endl;
//    cout<<"第三层节点数: "<<BinaryTreeLevelKSize(root, 3)<<endl;
//    cout<<"查找节点: "<<(BinaryTreeFind(root, 'E')? "找到了":"没找到")<<endl;
//    cout<<"是否完全二叉树: "<<(BinaryTreeComplete(root) ? "是" : "否")<<endl;
//    
//    BinaryTreeDestroy(root);
    
    
    
    
    //这是关于AVL树的输出
    AVLTree tree;
    
    int arr[] = {10,20,30,40,50,25};
    for(int val:arr)
    
        tree.insert(val);
        
        cout<<"中序遍历(插入后自动平衡): ";
        tree.inorder();
        
        tree.remove(30);
        cout<<"中序遍历(删除30后自动平衡):";
        tree.inorder();
        
        tree.remove(50);
        cout<<"中序遍历 (删除50后自动平衡):";
        tree.inorder();
        
        return 0;
    
}

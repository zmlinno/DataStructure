//
//  List.hpp
//  List
//
//  Created by 张木林 on 7/23/25.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int val):data(val),next(nullptr){} //构造函数
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();              // 构造函数
    ~LinkedList();             // 析构函数

    void insertAtTail(int value);       // 尾插 //尾插
    void printList() const; //打印链表
    void deleteList(); //删除链表
    Node* searchNode(int value);//查找节点
    bool deleteNode(int value); //删除指定节点
    void insertAfter(Node* curr,int value); //在链表中间插入节点
    
    void swap5and6(Node* head,int value);
    
};

#endif /* List_hpp */

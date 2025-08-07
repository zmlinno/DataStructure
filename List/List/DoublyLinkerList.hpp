//
//  DoublyLinkerList.hpp
//  List
//
//  Created by 张木林 on 7/24/25.
//

#ifndef DoublyLinkerList_hpp
#define DoublyLinkerList_hpp

#include <stdio.h>
#include<iostream>
using namespace std;
struct DNode
{
    int data;
    DNode* prev;
    DNode* next;
    
    DNode(int val):data(val),prev(nullptr),next(nullptr){}
};


class DoublyLinkedList
{
private:
    DNode* head;
    DNode* tail;
    
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void insertAtHead(int value); //头插
    void insertAtTail(int value); //尾插
    bool deleteNode(int value); //删除指定值
    DNode* searchNode(int value); //查找
    void printForward()const;  //从头到尾
    void printBackward()const; //从尾到头
    void clear(); //清空链表
    
    //在指定节点之前插入
    void insertBefore(DNode*node,int value);
    //在指定节点之后插入
    void insertAfter(DNode* node,int value);
    
    //删除头节点
    void deleteHead();
    //删除尾节点
    void deleteTaile();
    
    //计算链表长度
    int getLength()const;
    
    //判断是否为空
    bool isEmpty()const;
    
    
};
#endif /* DoublyLinkerList_hpp */

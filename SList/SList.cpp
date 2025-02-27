//
//  SList.cpp
//  DataStructure
//
//  Created by 张木林 on 2/28/25.
//

#include "SList.h"
#include<iostream>
using namespace std;


//打印链表
void SinglyLinkedList::printList()
{
    ListNode* temp = head;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<NULL<<" ";
    
}


//头插
void SinglyLinkedList::pushFront(int x)
{
    ListNode* tail = head;
    ListNode* NewNode = new ListNode(x);
    
    NewNode->next = head;
    tail = NewNode;
    
}

//尾插
void SinglyLinkedList::pushBack(int x)
{
    ListNode* tail = head;
    ListNode* NewNode = new ListNode(x);
    
    if(!head)
    {
        head = NewNode;
        return;
    }
    while(tail->next)
    {
        tail = tail->next;
        
    }
    tail->next = NewNode;
    
}


//头删
void SinglyLinkedList::popFront()
{
    if(!head)return;
    
    ListNode* tail = head;
    head = head->next;
    delete tail;
}


//尾删
void SinglyLinkedList::popBack()
{
    if(!head)return;
    if(!head->next)
    {
        delete head;
        head = nullptr;
        return;
    }
    
    ListNode* tail = head;
    ListNode* curr = nullptr;
    
    while(tail->next)
    {
        curr = tail;
        tail = tail->next;
    }
    curr->next = nullptr;
    delete tail;
    
}



//查找节点
ListNode* SinglyLinkedList::find(int x)
{
    ListNode* tail = head;
    if(tail->val != x)
    {
        tail = tail->next;
        return tail;
    }
    else
    {
        return nullptr;
    }
}


void SinglyLinkedList::insertAfter(ListNode *pos,int x)
{
    if(!pos)return;
    ListNode* NewNode = new ListNode(x);
    NewNode->next = pos->next;
    pos->next = NewNode;
}


//在指定节点之前插入
void SinglyLinkedList::insertBefore(ListNode *pos, int x)
{
    if(!head||head == pos)
    {
        pushFront(x);
        return;
    }
    
    ListNode* tail = head;
    ListNode* NewNode = new ListNode(x);
    while(tail->next != pos)
    {
        tail = tail->next;
    }
    
    if(tail->next)
    {
        NewNode->next = tail->next;
        tail->next = NewNode;
    }
    
}


//删除指定节点
void SinglyLinkedList::eraseNode(ListNode *pos)
{
    if(!pos||head)return;
    if(head == pos)
    {
        popFront();
        return;
    }
    ListNode* tail = head;
    while(tail->next != pos)
    {
        tail = tail->next;
    }
    if(tail->next)
    {
        tail->next = pos->next;
        delete pos;
    }
    
}



//删除某个节点的下一个节点
void SinglyLinkedList::eraseAfter(ListNode *pos)
{
    if(!pos||(pos->next))return;
    
    ListNode* temp = pos->next;
    pos->next = temp->next;
    delete temp;
    
    
}

//释放整个链表
void SinglyLinkedList::destroy()
{
    ListNode* temp;
    while(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

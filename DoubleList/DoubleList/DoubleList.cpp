//
//  DoubleList.cpp
//  DoubleList
//
//  Created by 张木林 on 8/25/25.
//

#include "DoubleList.hpp"
#include<stdlib.h>
#include<assert.h>
#include<iostream>
using namespace std;

//创建链表  - 带头加循环
ListNode* ListCreate()
{
    ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
    assert(pHead);
    pHead->_next = pHead;
    pHead->_prev = pHead;
    return pHead;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
    assert(pHead);
    ListNode* cur = pHead->_next;
    while(cur != pHead)
    {
        ListNode* next = cur->_next;
        free(cur);
        cur = next;
    }
    free(pHead);
    
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
    assert(pHead);
    ListNode* cur = pHead->_next;
    while(cur != pHead)
    {
        cout<<cur->_data<<" ";
        cur = cur->_next;
    }
    cout<<"\n"<<endl;
}


// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    assert(newNode);
    
    newNode->_data = x;
    ListNode* tail = pHead->_prev;
    
    newNode->_next = pHead;
    newNode->_prev = tail;
    tail->_next = newNode;
    pHead->_prev = newNode;
}


// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
    assert(pHead);
    if(pHead->_next == pHead)return;
    
    ListNode* tail = pHead->_prev;
    ListNode* prev = tail->_prev;
    
    prev->_next = pHead;
    pHead->_prev = prev;
    
    free(tail);
    
}



// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListInsert(pHead->_next, x);
}


// 双向链表头删
void ListPopFront(ListNode* pHead)
{
    assert(pHead);
    if(pHead->_next == pHead)return;
    ListErase(pHead->_next);
    
}


// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListNode* cur = pHead->_next;
    while(cur != pHead)
    {
        if(cur->_data == x)
        {
            return cur;
        }
        cur = cur->_next;
    }
    return NULL;
}


// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);
    ListNode* prev = pos->_prev;
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    
    assert(newNode);
    newNode->_data = x;
    
    newNode->_next = pos;
    newNode->_prev = prev;
    prev->_next = newNode;
    pos->_prev = newNode;
}



// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* prev = pos->_prev;
    
    ListNode* next = pos->_next;
    
    prev->_next = next;
    next->_prev = prev;
    
    free(pos);
}

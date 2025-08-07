//
//  DoublyLinkerList.cpp
//  List
//
//  Created by 张木林 on 7/24/25.
//

#include "DoublyLinkerList.hpp"
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = tail = nullptr;
}
DoublyLinkedList::~DoublyLinkedList()
{
    clear();
}
void DoublyLinkedList::insertAtHead(int value)
{
    //头插
    DNode* newNode = new DNode(value);
    newNode->next = head;
    if(head)head->prev = newNode;
    head = newNode;
    if(!tail)tail = newNode;
}


void DoublyLinkedList::insertAtTail(int value)
{
    //尾插
    DNode* newNode = new DNode(value);
    newNode->prev = tail;
    if(tail)tail->next = newNode;
    tail = newNode;
    if(!head)head = newNode;
}


//删除指定值
bool DoublyLinkedList::deleteNode(int value)
{
    DNode* temp = head;
    while(temp && temp->data != value)
    {
        temp = temp->next;
    }
    if(!temp)return false;
    if(temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    
    delete temp;
    return true;
}


DNode* DoublyLinkedList::searchNode(int value)
{
    //查找
    DNode* temp = head;
    while(temp)
    {
        if(temp->data == value)return temp;
        temp = temp->next;
    }
    return nullptr;
}


//从头到尾
void DoublyLinkedList::printForward() const
{
    DNode* temp = head;
    while(temp)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


//从尾到头
void DoublyLinkedList::printBackward() const
{
    DNode* temp = tail;
    while(temp)
    {
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


//在指定节点之前插入
void DoublyLinkedList::insertBefore(DNode *node, int value)
{
    if(!node)return;
    
    DNode* newNode = new DNode(value);
    newNode->next = node;
    newNode->prev = node->prev;
    
    if(node->prev)
        node->prev->next = newNode;
    else
        head = newNode; //如果node是头部
    node->prev = newNode;
}

//在指定节点之后插入
void DoublyLinkedList::insertAfter(DNode *node, int value)
{
    if(!node)return;
    DNode* newNode = new DNode(value);
    newNode->prev = node;
    newNode->next = node->next;
    
    if(node->next)
        node->next->prev = newNode;
    else
        tail = newNode; //如果node是尾部
    node->next = newNode;
}


//删除头节点
void DoublyLinkedList::deleteHead()
{
    
}

void DoublyLinkedList::clear()
{
    while(head)
    {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}


//删除尾节点
void DoublyLinkedList::deleteTaile()
{
    if(!tail)return;
    DNode* temp = tail;
    tail = tail->prev;
    
    if(tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
}



//计算链表长度
int DoublyLinkedList::getLength()const
{
    int count = 0;
    DNode* temp = head;
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//判断是否为空
bool DoublyLinkedList::isEmpty()const
{
    return head == nullptr;
}


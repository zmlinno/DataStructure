//
//  List.cpp
//  List
//
//  Created by 张木林 on 7/23/25.
//

#include "List.hpp"
#include<iostream>
using namespace std;



LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    deleteList();
}

//尾插
void LinkedList::insertAtTail(int value) {
    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

Node* LinkedList::searchNode(int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return nullptr; // 没找到
}


//在链表中间插入节点
void insertAfter(Node* curr,int value)
{
    if(!curr)return;//安全检查 -  curr不能为空
    Node* newnode = new Node(value);
    newnode->next = curr->next;
    curr->next = newnode;
}

//删除指定节点
bool LinkedList::deleteNode(int value)
{
    if(!head)return false;
    
    //特殊情况如果是头节点
    if(head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    Node* prev = head;
    Node* curr = head->next;
    while(curr != nullptr)
    {
        if(curr->data ==  value)
        {
            prev->next = curr->next;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}



void LinkedList::printList() const {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void LinkedList::deleteList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

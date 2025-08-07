//
//  main.cpp
//  List
//
//  Created by 张木林 on 7/23/25.
//

#include <iostream>
using namespace std;
//#include"List.hpp"
//#include"DoublyLinkerList.hpp"
//#include"LeetCode.hpp"
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

void swap(ListNode* head)
{
    ListNode* temp = head;
    while(temp != nullptr && temp->val != 4)
    {
        temp = temp->next;
    }
    if(temp&& temp->next && temp->next->next)
    {
        ListNode* five = temp->next;
        ListNode* six = five->next;
        ListNode* seven = six->next;
        
        temp->next = six;
        six->next = five;
        five->next = seven;
    }
}

void printList(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main() {
    
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for(int i = 2;i<=8;i++)
    {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    
    cout<<"原始链表: ";
    printList(head);
    
    swap(head);
    cout<<"交换后链表: ";
    printList(head);
    
    
//    cout<<"<单链表>"<<endl;
//    LinkedList list;
//
//    list.insertAtTail(10);
//    list.insertAtTail(20);
//    list.insertAtTail(30);
//    list.insertAtTail(40);
//    list.insertAtTail(50);
//    list.insertAtTail(60);
//    
//
//    list.printList();  // 输出: 10 -> 20 -> 30 -> NULL

//    Node* found = list.searchNode(20);
//    if (found)
//        cout << "Found node: " << found->data << endl;
//    else
//        cout << "Node not found" << endl;
    
    
//    cout<<endl;
//    cout<<"<双链表>"<<endl;
//    
//    
//    //双链表
//    DoublyLinkedList lists;
//    lists.insertAtHead(20);
//    lists.insertAtHead(10);
//    lists.insertAtTail(30);
//    lists.insertAtTail(40);
//    
//    cout<<"Forward: ";
//    lists.printForward();
//    
//    cout<<"Backward: ";
//    lists.printBackward();
//    
//    cout<<"Deleting 20...";
//    lists.deleteNode(30);
//    lists.printForward();
//    
//    DNode* found1 = lists.searchNode(30);
//    
//    if(found1)
//        cout<<"Found node: "<<found1->data<<endl;
//    else
//        cout<<"Not Found"<<endl;
    

    return 0;
}

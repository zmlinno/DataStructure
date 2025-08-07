//
//  LeetCode.cpp
//  List
//
//  Created by 张木林 on 7/25/25.
//

#include "LeetCode.hpp"
#include<iostream>
#include<stack>
using namespace std;




ListNode* Solution::Printf()
{
    if(!head)return head;
    while(head)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    return head;
}
//BM1反转链表
ListNode* Solution::ReverseList(ListNode *head)
{
    if(!head)return head;
    ListNode* prev = nullptr;
    ListNode* temp = head;
    while(temp)
    {
        ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        head = next;
    }
    return prev;
}


//LeetCode234 回文链表
bool isPalindrome(ListNode* head)
{
    if(!head||!head->next)return true;
    
    //1.快慢指针找到中间节点
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //2.需要反转后半部分链表
    ListNode* prev = nullptr;
    while(slow)
    {
        ListNode* nextnode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextnode;
    }
    
    //3.逐个比较前半部分和反转后的后半部分
    ListNode* left = head;
    ListNode* right = prev;
    while(right)
    {
        //只需要比较后半部分的长度
        if(left->val != right->val)return false;
        left = left->next;
        right = right->next;
    }
    return true;
}


//BM2链表指定区间反转
ListNode* reverseBetween(ListNode*head, int m,int n)
{
    if(!head||m == n)return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* pre = &dummy;
    
    for(int i = 1;i<m;i++)
    {
        pre = pre->next;
    }
    
    ListNode* curr = pre->next;
    for(int i = 0;i<n-m;i++)
    {
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = pre->next;
        pre->next = temp;
    }
    return dummy.next;
}




//判断是否有环
bool hasCycle(ListNode* head)
{
    if(!head||!head->next)return false;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast && fast->next)
    {
        if(slow == fast)return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false; //没有相遇，说明无环
}


//BM9 删除链表的倒数第N个节点
ListNode* removeNthFromEnd(ListNode*head,int n)
{
    if(!head || n<=0) return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i = 0;i<n;i++)
    {
        if(fast)fast = fast->next;
        else return head;
    }
    
    //如果fast为null，那么就是删除头节点
    if(!fast)
    {
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return head;
    
}




//BM10 两个链表的第一个公共结点
ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2)
{
    if(!pHead1||!pHead2) return nullptr;
    
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    
    while(p1 != p2)
    {
        p1 = p1? p1->next:pHead2;
        p2 = p2? p2->next:pHead1;
    }
    return p1;
}


//BM11 链表相加 二
ListNode* addInList(ListNode* head1, ListNode* head2)
{
    stack<int>s1,s2;
    
    while(head1)
    {
        s1.push(head1->val);
        head1 = head1->next;
    }
    
    while(head2)
    {
        s2.push(head2->val);
        head2 = head2->next;
    }
    
    int carry = 0;
    ListNode* result = nullptr;
    
    while(!s1.empty() || !s2.empty()|| carry)
    {
        int sum = carry;
        if(!s1.empty())
        {
            sum += s1.top();
            s1.pop();
        }
        
        if(!s2.empty())
        {
            sum += s2.top();
            s2.pop();
        }
        
        carry = sum/10;
        ListNode* node = new ListNode(sum % 10);
        node->next = result;
        result = node;
    }
    return result;
    
}

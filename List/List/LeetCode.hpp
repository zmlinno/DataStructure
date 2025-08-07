//
//  LeetCode.hpp
//  List
//
//  Created by 张木林 on 7/25/25.
//

#ifndef LeetCode_hpp
#define LeetCode_hpp

#include <stdio.h>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};


class Solution
{
public:
    ListNode* Printf();
    ListNode* ReverseList(ListNode* head);
    bool isPalindrome(ListNode* head);
    ListNode* reverseBetween(ListNode*head, int m,int n);
    
    //判断是否有环
    bool hasCycle(ListNode* head);
    //BM9 删除链表的倒数第n个节点
    ListNode* removeNthFromEnd(ListNode*head,int n);
    
    //BM10 两个链表的第一个公共结点
    ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2);
    
    //BM11 链表相加 二
    ListNode* addInList(ListNode* head1, ListNode* head2);
    
private:
    ListNode* head;
    
};
#endif /* LeetCode_hpp */

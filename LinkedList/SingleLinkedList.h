#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//这不是单链表的增删查改，是leetcode链表题目
struct ListNode
{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(nullptr){}

};

//反转链表函数
ListNode* reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* prev1 = nullptr;
    int n = 1;
    if(curr->next == nullptr)
    {
        return nullptr;
    }
    else if(curr->next->next == nullptr)
    {
        return curr->next;
    }
    else
    {
    while(curr)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        //curr->next = prev; //反转指针

        //curr = next;
    }
    //int n = 1;
    for(int i = 1;i<n-1;i++)
    {
        if(!prev->next)return head; //n超过链表长度，直接返回
        prev = prev->next;

    }

    //删除节点
    ListNode* nodeToDelete = prev->next;
    if(nodeToDelete)
    {
        prev->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    while(prev)
    {
       // ListNode* prev1 = nullptr;
        ListNode* next = prev->next;

        prev->next = prev1;
        prev1 = prev;
        prev = next;
    }
}
    return prev1;
    
    //return prev;


    //return prev;

}



//删除倒数第N个节点
ListNode* removeNthFromEnd(ListNode* head,int n)
{
    ListNode* dummy = new ListNode(0); //虚拟头节点
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    //快指针先走n+1步，使得快慢指针相距n
    for(int i = 0;i<=n;i++)
    {
        fast = fast->next;
    }

    //快慢指针同时移动，直到快指针到达链表末尾
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    //删除倒数第n个节点
    ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}




//力扣160 相交链表
//找到两个链表的相交节点
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
{
    if(!headA || headB) return nullptr;
    ListNode* pA = headA;
    ListNode* pB = headB;

    while(pA != pB)
    {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
        //这个代码的意思就是，如果pA不是nullptr，就移动到pa->next
        //如果pa走完了headA，变成了null，就跳到headb开始便利
        //同理
    }

    return pA;
}



//力扣环形链表
bool hasCycle(ListNode* head)
{
    if(!head||!head->next) return false; //如果只有0或1个节点，直接返回

    ListNode* slow = head->next;
    ListNode* fast = head->next->next;

    while(fast && fast->next) //fast走到null
    {
        slow = slow->next; //慢指针走一步
        fast = fast->next->next; //快指针走两步

        if(slow == fast)
        {
            return true;
        }
    }
    return false;

}

//力扣21 合并两个有序链表
ListNode *mergeTwoList(ListNode* list1,ListNode* list2)
{
    ListNode *dummy = new ListNode(-1); //创建哨兵节点
    ListNode *tail = dummy; //维护最终链表的指针
    
    while(list1 && list2)
    {
        if(list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next; //移动尾指针
    }
    //处理剩余元素
    if(list1)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }
    return dummy->next;
}
ListNode *addTwoNumbers(ListNode *l1,ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;
    int carry = 0;

    while(l1||l2||carry)
    {
        int sum = carry;
        if(l1)
        {
            sum += l1->val;
            l1 = l1->next;

        }
        if(l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum/10; //计算进位
        sum = sum%10; //计算当前位

        tail->next = new ListNode(sum);
        tail = tail->next;
    }
    return dummy->next;
}

//力扣24 两两交换链表中的节点
ListNode* TwoNode(ListNode*head)
{
    if(!head||!head->next)return;
    ListNode* dummy = new ListNode(0);
    ListNode* prev = dummy;

    while(prev->next && prev->next->next)
    {
        ListNode* first = prev->next;
        ListNode* second = prev->next->next;

        //交换两两节点
        first->next = second->next;
        second->next = first;
        prev->next = second;

        //移动prev指针到下一对需要交换到节点
        prev = first;
    }
    return dummy->next;

}

// 困难反转前k个节点的函数
ListNode* reverSNodes(ListNode* head,int k)
{
    if(!head||k<=1)return head;

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    //搜索到k+1个节点
    ListNode* tail = head;
    for(int i = 0;i<k && tail;i++)
    {
        tail = tail->next;

    }
    //反转前k个节点
    for(int i = 0;i<k&&curr;i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //连接剩余部分
    head->next = tail;
    return prev;
}


// 力扣25 困难 反转 k 个节点的链表部分 这个是真的解答
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head; // 如果链表为空或 k=1，直接返回

    // 计算链表长度
    ListNode* temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* curr = head;

    while (length >= k) {
        ListNode* tail = curr;
        ListNode* nextGroup = curr->next;

        // 反转 k 个节点
        ListNode* prevNode = nullptr;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }

        // 连接反转部分
        prev->next = prevNode;
        tail->next = curr;
        prev = tail;

        length -= k;
    }

    return dummy.next;
}



//力扣148 排序链表-中等
//找到链表中的中点如快慢指针
ListNode* getMid(ListNode*head)
{
    ListNode* slow = head,*fast = head,*prev = nullptr;
    while(fast&&fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev)prev->next = nullptr;//断开链表
    return slow;
}

//合并两个有序链表
ListNode* merge(ListNode*h1,ListNode*h2)
{
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(h1&&h2)
    {
        if(h1->val < h2->val)
        {
            tail->next = h1;
            h1 = h1->next;
        }
        else
        {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }
    tail->next = h1?h1:h2;
    return dummy.next;
}

//归并排序链表
ListNode* sortList(ListNode* head)
{
    if(!head||!head->next)return head;
    ListNode* mid = getMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left,right);
}





//创建链表
// 创建链表
ListNode* createList(initializer_list<int> vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy->next;
}


//打印
void printList(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    
}

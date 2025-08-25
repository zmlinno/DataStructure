//
//  main.cpp
//  DoubleList
//
//  Created by 张木林 on 8/25/25.
//

#include <iostream>
#include "DoubleList.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    
    ListNode* plist = ListCreate();

    ListPushBack(plist, 10);
    ListPushBack(plist, 20);
    ListPushBack(plist, 30);
    ListPushFront(plist, 5);

    printf("初始链表：");
    ListPrint(plist);

    ListPopBack(plist);
    printf("尾删后：");
    ListPrint(plist);

    ListPopFront(plist);
    printf("头删后：");
    ListPrint(plist);

    ListNode* pos = ListFind(plist, 10);
    if (pos)
    {
        ListInsert(pos, 99);
        printf("在10前插入99：");
        ListPrint(plist);

        ListErase(pos);
        printf("删除值为10的节点后：");
        ListPrint(plist);
    }

    ListDestory(plist);
    return 0;
}

//
//  main.cpp
//  DataStructure
//
//  Created by 张木林 on 2/28/25.
//

#include "SList.cpp"
#include<iostream>
using namespace std;

int main()
{
    SinglyLinkedList list;
    
    //尾插
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.printList();
    
    cout<<endl;
    return 0;
    
}

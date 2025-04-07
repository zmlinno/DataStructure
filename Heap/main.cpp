//
//  main.cpp
//  Heap
//
//  Created by 张木林 on 4/7/25.
//

#include <iostream>
#include"Heap.hpp"
using namespace std;

int main()
{
    Heap h;
    
    h.Push(10);
    h.Push(20);
    h.Push(30);
    h.Push(40);
    h.Push(50);
    h.Push(60);
    
    cout<<"Heap Top "<<h.Top()<<endl;
    
    while(!h.Empty())
    {
        cout<<h.Top()<<" ";
        h.Pop();
    }
    cout<<endl;
    return 0;
}

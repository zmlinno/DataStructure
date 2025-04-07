//
//  Heap.hpp
//  Heap
//
//  Created by 张木林 on 4/7/25.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>
#pragma once
#include<vector>
using namespace std;
class Heap
{
public:
    Heap();//构造函数
    ~Heap();//析构函数
    
    void Push(int val); //插入元素
    void Pop();//删除堆顶
    int Top() const;//获取堆顶
    int Size() const;//获取大小
    bool Empty()const;//判断是否为空
    
private:
    vector<int>_data;
    
    void AdjustUp(int child);//向上调整
    void AdjustDows(int parent);//向下调整
};
#endif /* Heap_hpp */

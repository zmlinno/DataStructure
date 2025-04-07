//
//  Heap.cpp
//  Heap
//
//  Created by 张木林 on 4/7/25.
//

#include "Heap.hpp"
#include<stdexcept>
#include<algorithm>
using namespace std;
Heap::Heap(){}

Heap::~Heap(){}


void Heap::Push(int val)
{
    _data.push_back(val);
    AdjustUp(_data.size()-1);
}


void Heap::Pop()
{
    if(_data.empty())return;
    swap(_data[0],_data.back());
    _data.pop_back();
    AdjustDows(0);
}


int Heap::Top()const
{
    if(_data.empty())
        throw::runtime_error("Heap is empty!");
    return _data[0];
}

int Heap::Size()const
{
    return _data.size();
}


//判断是否为空
bool Heap::Empty()const
{
    return _data.empty();
}


void Heap::AdjustUp(int child)
{
    int parent = (child-1)/2;
    while(child>0 && _data[child] > _data[parent])
    {
        swap(_data[child],_data[parent]);
        child = parent;
        parent = (child-1)/2;
    }
    
}


void Heap::AdjustDows(int parent)
{
    //int child = parent * 2+1;
    //int size = _data.size();
    //这里上面这个警告是因为.size()返回的是size_t,
    //而我定义的是int所以下面是更好的写法
    size_t child = parent * 2+1;
    size_t size = _data.size();
    while(child<size)
    {
        if(child+1<size && _data[child+1]>_data[child])
            child++;
        
        if(_data[child]>_data[parent])
        {
            swap(_data[child],_data[parent]);
            parent = child;
            child = parent*2+1;
        }
        else
        {
            break;
        }
            
    }
}

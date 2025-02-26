

#include "Stack.h"
#include <iostream>
#include <cassert>
using namespace std；
Stack::Stack() : _a(nullptr), _top(0), _capacity(0) {}

Stack::~Stack() { delete[] _a; }

void Stack::Expand() {
    int newCapacity = _capacity == 0 ? 4 : _capacity * 2;
    STDataType* newArray = new STDataType[newCapacity];
    for (int i = 0; i < _top; ++i) newArray[i] = _a[i];
    delete[] _a;
    _a = newArray;
    _capacity = newCapacity;
}

void Stack::Push(STDataType data) {
    if (_top >= _capacity) Expand();
    _a[_top++] = data;
}

void Stack::Pop() {
    assert(_top > 0);
    --_top;
}

STDataType Stack::Top() const {
    assert(_top > 0);
    return _a[_top - 1];
}

int Stack::Size() const { return _top; }

bool Stack::Empty() const { return _top == 0; }

// class Stack
// {
// private:
//         STDataType* _a;//存储元素的动态数组
//         int _top; //栈顶索引
//         int _capacity;//栈的容量

//         //扩容函数
//         void Expand()
//         {
//                 int newCapacity = _capacity == 0?4:_capacity *2;
//                 STDataType* newArray = new STDataType[newCapacity];

//                 //复制原有数据
//                 for(int i = 0;i<_top;i++)
//                 {
//                         newArray[i] = _a[i];
//                 }

//                 //释放旧空间
//                 delete[] _a;
//                 _a = newArray;
//                 _capacity = newCapacity;
//         }

// public:
//         //构造函数 初始化栈
//         Stack() :_a(nullptr),_top(0),_capacity(0){}

//         //析构函数- 销毁栈
//         ~Stack()
//         {
//                 delete[]_a;
//         }

//         //入栈
//         void StackPush(STDataType data)
//         {
//                 if(_top >= _capacity)
//                 {
//                         Expand();//容量不足的扩容
//                 }
//                 _a[_top++] = data;
//         }

//         //出栈
//         void StackPop()
//         {
//                 assert(_top>0);
//                 --_top;
//         } 

//         //获取栈顶元素
//         STDataType StackTop()
//         {
//                 assert(_top>0);
//                 return _a[_top-1];//在这里为何-1呢
//         }

//         //获取栈的大小
//         int StackSize()const
//         {
//                 return _top;
//         }

//         //检查栈是否为空
//         bool StackEmpty()
//         {
//                 return _top == 0;
//         }
// };

// #endif // STACK_H



#include "Stack.h"
#include <iostream>
#include <cassert>

Stack::Stack() : _a(nullptr), _top(0), _capacity(0) {}

Stack::~Stack() { delete[] _a; }

void Stack::Expand() {
    int newCapacity = _capacity == 0 ? 4 : _capacity * 2;
    STDataType* newArray = new STDataType[newCapacity];
    for (int i = 0; i < _top; ++i) newArray[i] = _a[i];
    delete[] _a;
    _a = newArray;
    _capacity = newCapacity;
}

void Stack::Push(STDataType data) {
    if (_top >= _capacity) Expand();
    _a[_top++] = data;
}

void Stack::Pop() {
    assert(_top > 0);
    --_top;
}

STDataType Stack::Top() const {
    assert(_top > 0);
    return _a[_top - 1];
}

int Stack::Size() const { return _top; }

bool Stack::Empty() const { return _top == 0; }

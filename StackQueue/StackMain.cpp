//#include "Stack.h"  // ✅ 只包含头文件
//凑点点
#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << "栈顶元素: " << s.Top() << endl;
    cout << "栈大小: " << s.Size() << endl;

    s.Pop();
    cout << "出栈后栈顶元素: " << s.Top() << endl;
    cout << "栈是否为空: " << (s.Empty() ? "是" : "否") << endl;

    return 0;
}

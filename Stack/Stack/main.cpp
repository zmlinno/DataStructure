//
//  main.cpp
//  Stack
//
//  Created by 张木林 on 8/25/25.
//

#include <iostream>
#include"Stack.hpp"
using namespace std;

int main()
{
    Stack st;
    StackInit(&st);

    StackPush(&st, 10);
    StackPush(&st, 20);
    StackPush(&st, 30);
    StackPush(&st, 40);
    StackPush(&st, 50); // 动态扩容应该会发生在这里

    while (!StackEmpty(&st))
    {
        std::cout << "栈顶元素: " << StackTop(&st) << std::endl;
        StackPop(&st);
    }

    StackDestroy(&st);
    return 0;
}

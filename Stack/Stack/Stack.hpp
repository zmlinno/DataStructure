//
//  Stack.hpp
//  Stack
//
//  Created by 张木林 on 8/25/25.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
    STDataType* _a;
    int _top;        // 栈顶
    int _capacity;  // 容量
}Stack;
// 初始化栈
void StackInit(Stack* ps);
// 入栈
void StackPush(Stack* ps, STDataType data);
// 出栈
void StackPop(Stack* ps);
// 获取栈顶元素
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps);
// 销毁栈
void StackDestroy(Stack* ps); 
#endif /* Stack_hpp */

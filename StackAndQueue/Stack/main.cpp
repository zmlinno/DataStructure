//
//  main.cpp
//  DataStructure
//
//  Created by 张木林 on 3/11/25.
//

#include "Stack.cpp"
#include<stdio.h>
using namespace std;
int main()
{
    Stack s;
    StackInit(&s);
    
    //入栈
    StackPush(&s, 10);
    StackPush(&s, 20);
    StackPush(&s, 30);
    StackPush(&s, 40);
    StackPush(&s, 50);
    StackPush(&s, 60);
    
    printf("栈顶元素: %d\n",StackTop(&s));
    printf("栈大小: %d\n",StackSize(&s));
    
    
    //出栈
    StackPop(&s);
    printf("出栈后的元素: %d\n",StackTop(&s));
    printf("栈大小: %d\n",StackSize(&s));
    
    
    //继续出栈
    StackPop(&s);
    StackPop(&s);
    printf("栈是否为空: %s\n",StackEmpty(&s) ? "是" :"否");
    
    //释放栈
    StackDestroy(&s);
    
    return 0;
}



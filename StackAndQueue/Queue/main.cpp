//
//  main.cpp
//  DataStructure
//
//  Created by 张木林 on 3/11/25.
//

#include "Queue.cpp"
int main()
{
    Queue q;
    QueueInit(&q);

    // 入队测试
    QueuePush(&q, 10);
    QueuePush(&q, 20);
    QueuePush(&q, 30);
    QueuePush(&q, 40);
    QueuePush(&q, 50);

    printf("队列头部元素: %d\n", QueueFront(&q));
    printf("队列尾部元素: %d\n", QueueBack(&q));
    printf("队列大小: %d\n", QueueSize(&q));

    // 出队测试
    QueuePop(&q);
    printf("出队后队列头部元素: %d\n", QueueFront(&q));
    printf("队列大小: %d\n", QueueSize(&q));

    // 继续出队
    QueuePop(&q);
    QueuePop(&q);
    printf("队列是否为空: %s\n", QueueEmpty(&q) ? "是" : "否");

    // 释放队列
    QueueDestroy(&q);

    return 0;
}

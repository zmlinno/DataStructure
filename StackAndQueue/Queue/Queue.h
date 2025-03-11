//
//  Queue.hpp
//  DataStructure
//
//  Created by 张木林 on 3/11/25.

#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//在定义一个数据类型
typedef int QDataType;
// 链式结构：表示队列
typedef struct QListNode
{
    struct QListNode* _next;
    QDataType _data;
}QNode;

// 队列的结构
typedef struct Queue
{
    QNode* _front;
    QNode* _rear;
}Queue;

// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);


#endif // __QUEUE_H__

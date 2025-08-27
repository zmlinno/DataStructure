//
//  Queue.cpp
//  Queue
//
//  Created by 张木林 on 8/27/25.
//

#include "Queue.hpp"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
using namespace std;


// 初始化队列
void QueueInit(Queue* q)
{
    assert(q);
    q->_front = q->_rear = NULL;
}


// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
    assert(q);
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    
    if(!newNode)
    {
        perror("malloc fail");
        exit(-1);
    }
    newNode->_data = data;
    newNode->_next = NULL;
    
    if(q->_rear == NULL)
    {
        q->_front = q->_rear = newNode;
    }
    else
    {
        q->_rear->_next = newNode;
        q->_rear = newNode;
    }
}

// 队头出队列
void QueuePop(Queue* q)
{
    assert(q);
    assert(q->_front);
    
    QNode* del = q->_front;
    q->_front = q->_front->_next;
    free(del);
    
    if(q->_front == NULL)
    {
        q->_rear = NULL;
    }
}


// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
    assert(q);
    assert(q->_front);
    
    return q->_front->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
    assert(q);
    assert(q->_rear);
    return q->_rear->_data;
    
}


// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
    assert(q);
    int size = 0;
    QNode* cur = q->_front;
    while(cur)
    {
        size++;
        cur = cur->_next;
    }
    return size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
    assert(q);
    return q->_front == NULL;
}

// 销毁队列
void QueueDestroy(Queue* q)
{
    assert(q);
    QNode* cur = q->_front;
    while(cur)
    {
        QNode* next = cur->_next;
        free(cur);
        cur = next;
    }
    q->_front = q->_rear = NULL;
}




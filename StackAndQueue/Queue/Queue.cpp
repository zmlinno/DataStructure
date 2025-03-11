//
//  Queue.cpp
//  DataStructure
//
//  Created by 张木林 on 3/11/25.
//

#include"Queue.h"
#include<iostream>
#include<stdio.h>
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
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    if(!newNode)
    {
        printf("分配失败\n");
        exit(-1);
    }
    newNode->_data = data;
    newNode->_next = NULL;
    
    if(q->_rear == NULL) //空队列
    {
        q->_front = q->_rear = newNode;
    }
    else
    {
        q->_rear->_next = newNode;
        q->_rear = newNode;
    }
    
}


// 队头出队列(队头删除）
void QueuePop(Queue* q)
{
    assert(q);
    if(q->_front == NULL)
    {
        return;
    }
    
    QNode* temp = q->_front;
    q->_front = q->_front->_next;
    
    free(temp);
    
    if(q->_front == NULL)//如果出队后为空队列，需要更新_rear
    {
        q->_rear = NULL;
    }
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
    assert(q);
    assert(q->_front != NULL); //确保队列为非空
    return q->_front->_data;
}


// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
    assert(q);
    assert(q->_front != NULL);
    return q->_rear->_data;
    
}


// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
    assert(q);
    int count = 0;
    QNode* cur = q->_front;
    while(cur)
    {
        count++;
    }
    return count;
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
    while(q->_front)
    {
        QueuePop(q);
    }
    q->_rear = NULL;
}

//队列是一种先进先出（FIFO）的数据结构，可以使用数组或链表等不同的方式来实现。以下是使用数组和链表两种方式在C语言中实现队列的基础结构：
//使用数组实现队列
//使用数组实现队列时，通常需要一个固定大小的数组以及两个指针（或索引）来追踪队列的前端和后端。

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX_SIZE 100

typedef struct {
    int items[QUEUE_MAX_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 检查队列是否为空
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// 检查队列是否已满
int isFull(Queue* q) {
    return q->rear == QUEUE_MAX_SIZE - 1;
}

// 入队
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("队列已满，无法入队。\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d 入队成功。\n", value);
}

// 出队
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("队列为空，无法出队。\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        // 队列变空，重置指针
        initializeQueue(q);
    }
    return item;
}

// 主函数，用于测试队列功能
int main() {
    Queue q;
    initializeQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d 出队。\n", dequeue(&q));
    printf("%d 出队。\n", dequeue(&q));
    enqueue(&q, 40);
    printf("%d 出队。\n", dequeue(&q));
    // 队列应为空
    if (dequeue(&q) == -1) {
        printf("队列为空。\n");
    }
    return 0;
}
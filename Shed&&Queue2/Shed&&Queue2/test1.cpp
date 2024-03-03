//在C语言中，我们可以使用队列这种数据结构来实现栈的操作。由于队列是一
//种先进先出（First In First Out, FIFO）的数据结构，而栈是一种后进先出
//（Last In First Out, LIFO）的数据结构，所以这种实现方式会在效率上有一
//些折中。通常，使用队列实现栈有两种方式：链队列和数组队列。
//下面是一个使用数组实现的固定大小队列来模拟栈的基本操作的示例代码：

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 判断队列是否为空
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// 判断队列是否已满
int isFull(Queue* q) {
    return q->rear == STACK_SIZE - 1;
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
    q->data[q->rear] = value;
    printf("%d 入队成功。\n", value);
}

// 出队
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("队列已空，无法出队。\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    if (q->front > q->rear) { // 队列中只有一个元素
        initQueue(q);
    }
    return value;
}

// 初始化栈
void initStack(Queue* q) {
    // 由于栈和队列共享相同的结构，我们只需要初始化队列
    // 初始化队列的同时也就初始化了栈
    initQueue(q);
}

// 压栈
void push(Queue* q, int value) {
    // 入队操作模拟压栈
    enqueue(q, value);
}

// 弹栈
int pop(Queue* q) {
    // 出队操作模拟弹栈
    return dequeue(q);
}

// 主函数，用于测试
int main() {
    Queue q;
    initStack(&q);

    push(&q, 1);
    push(&q, 2);
    push(&q, 3);

    printf("%d 弹栈。\n", pop(&q));
    printf("%d 弹栈。\n", pop(&q));

    push(&q, 4);
    printf("%d 弹栈。\n", pop(&q));

    return 0;
}
//
//在这个实现中，栈通过一个队列来存储元素。为了使栈的操作能够模拟后进先出的特性，
//我们在压栈时将元素放入队列的尾部，而在弹栈时则从队列的头部取出元素。这样，队
//列的入队操作对应于栈的压栈操作，而出队操作对应于栈的弹栈操作。
//请注意，这个实现是针对固定大小的栈，如果你需要一个可变大小的栈，可以使用链表
//来实现，这样在空间上更加灵活，但在实现上会稍微复杂一些。
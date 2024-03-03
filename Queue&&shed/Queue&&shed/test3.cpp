//在C语言中，我们可以使用栈这种数据结构来实现队列的操作。由于栈是一种
//后进先出（Last In First Out, LIFO）的数据结构，而队列是一种先进先出
//（First In First Out, FIFO）的数据结构，所以这种实现方式会在效率上有
//一些折中。通常，使用栈实现队列有两种方式：链栈和数组栈。
//下面是一个使用数组实现的固定大小栈来模拟队列的基本操作的示例代码：

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
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
    return q->rear == QUEUE_SIZE - 1;
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

// 主函数，用于测试
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("%d 出队。\n", dequeue(&q));
    printf("%d 出队。\n", dequeue(&q));

    enqueue(&q, 4);
    printf("%d 出队。\n", dequeue(&q));

    return 0;
}

//在这个实现中，队列的入队操作（enqueue）对应于栈的压栈操作，而出队操
//作（dequeue）对应于栈的弹栈操作。为了使出队操作能够从栈的尾部取出元
//素，我们在入队时将元素放入栈的尾部，而出队时则从栈的头部取出元素，这
//样就模拟了队列的先进先出的特性。
//请注意，这个实现是针对固定大小的队列，如果你需要一个可变大小的队列，
//可以使用链表来实现，这样在空间上更加灵活，但在实现上会稍微复杂一些。
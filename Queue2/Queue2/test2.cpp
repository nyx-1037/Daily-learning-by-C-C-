//使用链表实现队列
//使用链表实现队列时，通常需要两个结构体：一个用于节点，一个用于队列本身。队列的头节点即为队列的前端。

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

// 初始化队列
void initializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// 检查队列是否为空
int isEmpty(Queue* q) {
    return q->rear == NULL;
}

// 入队
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败。\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
    }
    else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    printf("%d 入队成功。\n", value);
}

// 出队

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("队列为空，无法出队。\n");
        return -1;
    }
    Node* temp = q->front;
    int item = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        // 队列为空，释放空间
        free(temp);
        q->rear = NULL;
    }
    else {
        // 队首指针不变，释放temp节点空间
        free(temp);
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

//在这个实现中，我们创建了一个Node结构体，它包含一个int类型的data字段
//和一个指向下一个节点的指针next。Queue结构体包含两个指针，一个指向队
//列的前端（front），另一个指向队列的后端（rear）。
//列的前端（front），另一个指向队列的后端（rear）。
//enqueue函数向队列添加一个新的节点，而dequeue函数从队列的前端移除一
//个节点并返回其data字段中的值。如果队列空，dequeue函数会返回 - 1。
//请注意，上述代码示例是为了演示目的而简化的。在实际应用中，您可能需
//要添加更多的错误检查和功能，比如动态分配内存失败的处理、释放队列中
//所有节点的内存等。此外，为了提高效率和可扩展性，您可能还需要考虑使
//用更为复杂的数据结构或算法。
//������һ���Ƚ��ȳ���FIFO�������ݽṹ������ʹ�����������Ȳ�ͬ�ķ�ʽ��ʵ�֡�������ʹ��������������ַ�ʽ��C������ʵ�ֶ��еĻ����ṹ��
//ʹ������ʵ�ֶ���
//ʹ������ʵ�ֶ���ʱ��ͨ����Ҫһ���̶���С�������Լ�����ָ�루����������׷�ٶ��е�ǰ�˺ͺ�ˡ�

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX_SIZE 100

typedef struct {
    int items[QUEUE_MAX_SIZE];
    int front;
    int rear;
} Queue;

// ��ʼ������
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// �������Ƿ�Ϊ��
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// �������Ƿ�����
int isFull(Queue* q) {
    return q->rear == QUEUE_MAX_SIZE - 1;
}

// ���
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("�����������޷���ӡ�\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d ��ӳɹ���\n", value);
}

// ����
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("����Ϊ�գ��޷����ӡ�\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        // ���б�գ�����ָ��
        initializeQueue(q);
    }
    return item;
}

// �����������ڲ��Զ��й���
int main() {
    Queue q;
    initializeQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d ���ӡ�\n", dequeue(&q));
    printf("%d ���ӡ�\n", dequeue(&q));
    enqueue(&q, 40);
    printf("%d ���ӡ�\n", dequeue(&q));
    // ����ӦΪ��
    if (dequeue(&q) == -1) {
        printf("����Ϊ�ա�\n");
    }
    return 0;
}
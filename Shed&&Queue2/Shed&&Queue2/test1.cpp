//��C�����У����ǿ���ʹ�ö����������ݽṹ��ʵ��ջ�Ĳ��������ڶ�����һ
//���Ƚ��ȳ���First In First Out, FIFO�������ݽṹ����ջ��һ�ֺ���ȳ�
//��Last In First Out, LIFO�������ݽṹ����������ʵ�ַ�ʽ����Ч������һ
//Щ���С�ͨ����ʹ�ö���ʵ��ջ�����ַ�ʽ�������к�������С�
//������һ��ʹ������ʵ�ֵĹ̶���С������ģ��ջ�Ļ���������ʾ�����룺

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int front;
    int rear;
} Queue;

// ��ʼ������
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// �ж϶����Ƿ�����
int isFull(Queue* q) {
    return q->rear == STACK_SIZE - 1;
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
    q->data[q->rear] = value;
    printf("%d ��ӳɹ���\n", value);
}

// ����
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("�����ѿգ��޷����ӡ�\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    if (q->front > q->rear) { // ������ֻ��һ��Ԫ��
        initQueue(q);
    }
    return value;
}

// ��ʼ��ջ
void initStack(Queue* q) {
    // ����ջ�Ͷ��й�����ͬ�Ľṹ������ֻ��Ҫ��ʼ������
    // ��ʼ�����е�ͬʱҲ�ͳ�ʼ����ջ
    initQueue(q);
}

// ѹջ
void push(Queue* q, int value) {
    // ��Ӳ���ģ��ѹջ
    enqueue(q, value);
}

// ��ջ
int pop(Queue* q) {
    // ���Ӳ���ģ�ⵯջ
    return dequeue(q);
}

// �����������ڲ���
int main() {
    Queue q;
    initStack(&q);

    push(&q, 1);
    push(&q, 2);
    push(&q, 3);

    printf("%d ��ջ��\n", pop(&q));
    printf("%d ��ջ��\n", pop(&q));

    push(&q, 4);
    printf("%d ��ջ��\n", pop(&q));

    return 0;
}
//
//�����ʵ���У�ջͨ��һ���������洢Ԫ�ء�Ϊ��ʹջ�Ĳ����ܹ�ģ�����ȳ������ԣ�
//������ѹջʱ��Ԫ�ط�����е�β�������ڵ�ջʱ��Ӷ��е�ͷ��ȡ��Ԫ�ء���������
//�е���Ӳ�����Ӧ��ջ��ѹջ�����������Ӳ�����Ӧ��ջ�ĵ�ջ������
//��ע�⣬���ʵ������Թ̶���С��ջ���������Ҫһ���ɱ��С��ջ������ʹ������
//��ʵ�֣������ڿռ��ϸ���������ʵ���ϻ���΢����һЩ��
//��C�����У����ǿ���ʹ��ջ�������ݽṹ��ʵ�ֶ��еĲ���������ջ��һ��
//����ȳ���Last In First Out, LIFO�������ݽṹ����������һ���Ƚ��ȳ�
//��First In First Out, FIFO�������ݽṹ����������ʵ�ַ�ʽ����Ч������
//һЩ���С�ͨ����ʹ��ջʵ�ֶ��������ַ�ʽ����ջ������ջ��
//������һ��ʹ������ʵ�ֵĹ̶���Сջ��ģ����еĻ���������ʾ�����룺

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
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
    return q->rear == QUEUE_SIZE - 1;
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

// �����������ڲ���
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("%d ���ӡ�\n", dequeue(&q));
    printf("%d ���ӡ�\n", dequeue(&q));

    enqueue(&q, 4);
    printf("%d ���ӡ�\n", dequeue(&q));

    return 0;
}

//�����ʵ���У����е���Ӳ�����enqueue����Ӧ��ջ��ѹջ�����������Ӳ�
//����dequeue����Ӧ��ջ�ĵ�ջ������Ϊ��ʹ���Ӳ����ܹ���ջ��β��ȡ��Ԫ
//�أ����������ʱ��Ԫ�ط���ջ��β����������ʱ���ջ��ͷ��ȡ��Ԫ�أ���
//����ģ���˶��е��Ƚ��ȳ������ԡ�
//��ע�⣬���ʵ������Թ̶���С�Ķ��У��������Ҫһ���ɱ��С�Ķ��У�
//����ʹ��������ʵ�֣������ڿռ��ϸ���������ʵ���ϻ���΢����һЩ��
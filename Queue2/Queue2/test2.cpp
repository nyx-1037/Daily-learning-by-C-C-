//ʹ������ʵ�ֶ���
//ʹ������ʵ�ֶ���ʱ��ͨ����Ҫ�����ṹ�壺һ�����ڽڵ㣬һ�����ڶ��б������е�ͷ�ڵ㼴Ϊ���е�ǰ�ˡ�

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

// ��ʼ������
void initializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// �������Ƿ�Ϊ��
int isEmpty(Queue* q) {
    return q->rear == NULL;
}

// ���
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ�ܡ�\n");
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
    printf("%d ��ӳɹ���\n", value);
}

// ����

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("����Ϊ�գ��޷����ӡ�\n");
        return -1;
    }
    Node* temp = q->front;
    int item = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        // ����Ϊ�գ��ͷſռ�
        free(temp);
        q->rear = NULL;
    }
    else {
        // ����ָ�벻�䣬�ͷ�temp�ڵ�ռ�
        free(temp);
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

//�����ʵ���У����Ǵ�����һ��Node�ṹ�壬������һ��int���͵�data�ֶ�
//��һ��ָ����һ���ڵ��ָ��next��Queue�ṹ���������ָ�룬һ��ָ���
//�е�ǰ�ˣ�front������һ��ָ����еĺ�ˣ�rear����
//�е�ǰ�ˣ�front������һ��ָ����еĺ�ˣ�rear����
//enqueue������������һ���µĽڵ㣬��dequeue�����Ӷ��е�ǰ���Ƴ�һ
//���ڵ㲢������data�ֶ��е�ֵ��������пգ�dequeue�����᷵�� - 1��
//��ע�⣬��������ʾ����Ϊ����ʾĿ�Ķ��򻯵ġ���ʵ��Ӧ���У���������
//Ҫ��Ӹ���Ĵ�����͹��ܣ����綯̬�����ڴ�ʧ�ܵĴ����ͷŶ�����
//���нڵ���ڴ�ȡ����⣬Ϊ�����Ч�ʺͿ���չ�ԣ������ܻ���Ҫ����ʹ
//�ø�Ϊ���ӵ����ݽṹ���㷨��
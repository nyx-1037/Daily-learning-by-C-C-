//������һ��ʹ������ʵ�ֵĹ̶���Сջ��C����ʾ�����롣���ջ���Խ���ѹջ��push���͵�ջ��pop��������

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

// ��ʼ��ջ
void initStack(Stack* s) {
    s->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* s) {
    return s->top == -1;
}

// �ж�ջ�Ƿ�����
int isFull(Stack* s) {
    return s->top == STACK_SIZE - 1;
}

// ѹջ
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("ջ�������޷�ѹջ��\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
    printf("%d ѹջ�ɹ���\n", value);
}

// ��ջ
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("ջ�ѿգ��޷���ջ��\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

// �����������ڲ���
int main() {
    Stack s;
    initStack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d ��ջ��\n", pop(&s));
    printf("%d ��ջ��\n", pop(&s));

    push(&s, 4);
    printf("%d ��ջ��\n", pop(&s));

    return 0;
}

//�����ʵ���У�ջͨ��һ������ data ���洢Ԫ�أ���������� top ��ʾջ����λ�á�
//��ʼʱ��ջΪ�գ�top ��ֵΪ - 1����Ԫ�ر�ѹ��ջʱ��top ��ֵ���ӣ�Ԫ�ر��洢��
//data[top] ��λ�á���Ԫ�ر�����ջʱ��top ��ֵ���٣��Ӷ��Ƴ��������Ԫ�ء�
//��ע�⣬���ʵ������Թ̶���С��ջ���������Ҫһ���ɱ��С��ջ������ʹ������
//��ʵ�֣������ڿռ��ϸ���������ʵ���ϻ���΢����һЩ��
//下面是一个使用数组实现的固定大小栈的C语言示例代码。这个栈可以进行压栈（push）和弹栈（pop）操作。

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(Stack* s) {
    return s->top == STACK_SIZE - 1;
}

// 压栈
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("栈已满，无法压栈。\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
    printf("%d 压栈成功。\n", value);
}

// 弹栈
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("栈已空，无法弹栈。\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

// 主函数，用于测试
int main() {
    Stack s;
    initStack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d 弹栈。\n", pop(&s));
    printf("%d 弹栈。\n", pop(&s));

    push(&s, 4);
    printf("%d 弹栈。\n", pop(&s));

    return 0;
}

//在这个实现中，栈通过一个数组 data 来存储元素，数组的索引 top 表示栈顶的位置。
//初始时，栈为空，top 的值为 - 1。当元素被压入栈时，top 的值增加，元素被存储在
//data[top] 的位置。当元素被弹出栈时，top 的值减少，从而移除最上面的元素。
//请注意，这个实现是针对固定大小的栈，如果你需要一个可变大小的栈，可以使用链表
//来实现，这样在空间上更加灵活，但在实现上会稍微复杂一些。
#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    int data;           // ������
    struct Node* next;  // ָ����
} Node;

// ����һ���µĽڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ������ͷ����ӽڵ�
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// ������β����ӽڵ�
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// ��ӡ����
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// �ͷ�����ռ�
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

// ����������ʾ���ʹ����������
int main() {
    Node* head = NULL;

    // ��ӽڵ�
    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    insertAtTail(&head, 4);

    // ��ӡ����
    printList(head);

    // �ͷ�����ռ�
    freeList(head);

    return 0;
}
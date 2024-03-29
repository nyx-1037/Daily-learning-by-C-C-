#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ͼ��ڵ㼯��
typedef struct Book {
    int id;
    char name[50];
    float price;//������
    struct Book* next;//��һ���ڵ��ָ����
} Book;

// ��������
void addBook(Book** head, int id, const char* name, float price, int position);//���ͼ��Ľӿ�
void displayBooks(const Book* head);//��ѯͼ��Ľӿ�
void deleteBook(Book** head, int id);//ɾ��ͼ��Ľӿ�
void updateBook(Book** head, int id, const char* name, float price);//����ͼ�����ݵĽӿ�
int findBookPosition(const Book* head, int id);//����ͼ��ڵ�λ�õĽӿ�

int main() {
    Book* head = NULL;//ͷָ���ÿ�
    int choice, id, position;
    char name[50];
    float price;

    while (1) {
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("****************************************************\n");
        printf("************** Mr.Nie��ͼ�����ϵͳ ****************\n");
        printf("******************* 1. ���ͼ�� ********************\n");
        printf("******************* 2. ��ʾͼ�� ********************\n");
        printf("******************* 3. ɾ��ͼ�� ********************\n");
        printf("***************** 4. ����ͼ����Ϣ ******************\n");
        printf("********************* 5. �˳� **********************\n");
        printf("****************************************************\n");
        printf("����������ѡ��");
        scanf("%d", &choice);
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        switch (choice) {
        case 1:
            printf("������ͼ��ID��");
            scanf("%d", &id);
            printf("������ͼ�����ƣ�");
            scanf("%s", name);
            printf("������ͼ��۸�");
            scanf("%f", &price);
            printf("������ͼ��λ�ã�1-ĩβ��2-��ͷ����");
            scanf("%d", &position);
            addBook(&head, id, name, price, position);
            break;
        case 2:
            displayBooks(head);
            break;
        case 3:
            printf("������Ҫɾ����ͼ��ID��");
            scanf("%d", &id);
            deleteBook(&head, id);
            break;
        case 4:
            printf("������Ҫ���µ�ͼ��ID��");
            scanf("%d", &id);
            printf("�������µ�ͼ�����ƣ�");
            scanf("%s", name);
            printf("�������µ�ͼ��۸�");
            scanf("%f", &price);
            updateBook(&head, id, name, price);
            break;
        case 5:
            exit(0);
        default:
            printf("��Ч��ѡ������������\n");
        }
    }

    return 0;
}

//���ͼ��ĺ������
void addBook(Book** head, int id, const char* name, float price, int position) {
    Book* newBook = (Book*)malloc(sizeof(Book));//��̬�ڴ����ͼ����Ϣ�洢�ռ�
    newBook->id = id;
    strcpy(newBook->name, name);
    newBook->price = price;
    newBook->next = NULL;

    if (position == 1) {
        newBook->next = *head;
        *head = newBook;
    }
    else {
        Book* current = *head;
        while (current->next != NULL && current->next->id < id) {
            current = current->next;
        }
        newBook->next = current->next;
        current->next = newBook;
    }
}

//��ѯͼ��ĺ������
void displayBooks(const Book* head) {
    const Book* current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->id);
        printf("���ƣ� %s\n", current->name);
        printf("�۸� %.2f\n", current->price);
        printf("\n");
        current = current->next;
    }
}

//ɾ��ͼ��ĺ������
void deleteBook(Book** head, int id) {
    Book* current = *head;
    Book* previous = NULL;
    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("δ�ҵ�IDΪ%d��ͼ��\n", id);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    }
    else {
        previous->next = current->next;
    }
    free(current);
    printf("��ɾ��IDΪ%d��ͼ��\n", id);
}

//����ͼ�����ݵĺ������
void updateBook(Book** head, int id, const char* name, float price) {
    Book* current = *head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("δ�ҵ�IDΪ%d��ͼ��\n", id);
        return;
    }
    strcpy(current->name, name);
    current->price = price;
    printf("�Ѹ���IDΪ%d��ͼ����Ϣ\n", id);
}

//����ͼ��ڵ�λ�õĺ������
int findBookPosition(const Book* head, int id) {
    int position = 1;
    const Book* current = head;
    while (current != NULL && current->id < id) { //�жϲ���
        position++;
        current = current->next;
    }
    return position;
}

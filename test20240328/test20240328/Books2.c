#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义图书节点集合
typedef struct Book {
    int id;
    char name[50];
    float price;//数据域
    struct Book* next;//下一个节点的指针域
} Book;

// 函数声明
void addBook(Book** head, int id, const char* name, float price, int position);//添加图书的接口
void displayBooks(const Book* head);//查询图书的接口
void deleteBook(Book** head, int id);//删除图书的接口
void updateBook(Book** head, int id, const char* name, float price);//更新图书数据的接口
int findBookPosition(const Book* head, int id);//查找图书节点位置的接口

int main() {
    Book* head = NULL;//头指针置空
    int choice, id, position;
    char name[50];
    float price;

    while (1) {
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("****************************************************\n");
        printf("************** Mr.Nie的图书管理系统 ****************\n");
        printf("******************* 1. 添加图书 ********************\n");
        printf("******************* 2. 显示图书 ********************\n");
        printf("******************* 3. 删除图书 ********************\n");
        printf("***************** 4. 更新图书信息 ******************\n");
        printf("********************* 5. 退出 **********************\n");
        printf("****************************************************\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        switch (choice) {
        case 1:
            printf("请输入图书ID：");
            scanf("%d", &id);
            printf("请输入图书名称：");
            scanf("%s", name);
            printf("请输入图书价格：");
            scanf("%f", &price);
            printf("请输入图书位置（1-末尾，2-开头）：");
            scanf("%d", &position);
            addBook(&head, id, name, price, position);
            break;
        case 2:
            displayBooks(head);
            break;
        case 3:
            printf("请输入要删除的图书ID：");
            scanf("%d", &id);
            deleteBook(&head, id);
            break;
        case 4:
            printf("请输入要更新的图书ID：");
            scanf("%d", &id);
            printf("请输入新的图书名称：");
            scanf("%s", name);
            printf("请输入新的图书价格：");
            scanf("%f", &price);
            updateBook(&head, id, name, price);
            break;
        case 5:
            exit(0);
        default:
            printf("无效的选择，请重新输入\n");
        }
    }

    return 0;
}

//添加图书的函数设计
void addBook(Book** head, int id, const char* name, float price, int position) {
    Book* newBook = (Book*)malloc(sizeof(Book));//动态内存分配图书信息存储空间
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

//查询图书的函数设计
void displayBooks(const Book* head) {
    const Book* current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->id);
        printf("名称： %s\n", current->name);
        printf("价格： %.2f\n", current->price);
        printf("\n");
        current = current->next;
    }
}

//删除图书的函数设计
void deleteBook(Book** head, int id) {
    Book* current = *head;
    Book* previous = NULL;
    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("未找到ID为%d的图书\n", id);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    }
    else {
        previous->next = current->next;
    }
    free(current);
    printf("已删除ID为%d的图书\n", id);
}

//更新图书数据的函数设计
void updateBook(Book** head, int id, const char* name, float price) {
    Book* current = *head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("未找到ID为%d的图书\n", id);
        return;
    }
    strcpy(current->name, name);
    current->price = price;
    printf("已更新ID为%d的图书信息\n", id);
}

//查找图书节点位置的函数设计
int findBookPosition(const Book* head, int id) {
    int position = 1;
    const Book* current = head;
    while (current != NULL && current->id < id) { //判断查找
        position++;
        current = current->next;
    }
    return position;
}

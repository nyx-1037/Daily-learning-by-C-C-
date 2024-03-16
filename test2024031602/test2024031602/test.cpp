#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//设置一本书的信息，作为一个结构体
struct Book {
    unsigned int id;//书的编号
    char name[100];//书的名称
    float price;//书的价格
};


//声明查询图书信息的函数接口
void displayBooks(struct Book books[], int n);
//用结构体指针和计数器指针接收查询现有图书信息

//声明添加图书信息的函数接口
void addBook(struct Book books[], int* n, unsigned int id, const char* name, float price);
//用结构体指针和计数器指针接收现有图书信息，用形参创建接收新的书籍信息，后放置在新建结构体中

//声明删除图书信息的函数接口
void deleteBook(struct Book books[], int* n, unsigned int id);
//用结构体指针和计数器指针接收现有图书信息，以书籍信息编号为标准来删除对应书籍信息

int main() {
    struct Book books[100];  // 假设系统最多管理100本书
    int n = 0;  // 当前书籍数量，数量计数器
    int choice;
    system("color 34");
    while (1) {
        printf("********************************\n");
        printf("***** Mr.Nie的图书管理系统 *****\n");
        printf("*********1. 显示所有书籍 *******\n");
        printf("*********2. 添加书籍 ***********\n");
        printf("*********3. 删除书籍 ***********\n");
        printf("*********4. 退出 ***************\n");
        printf("请选择操作>>");
        scanf("%d", &choice);
        printf("********************************\n");

        system("cls");

        switch (choice) {
        case 1:
            displayBooks(books, n);
            break;
        case 2:
        {
            int id;
            char name[100];
            float price;
            printf("********************************\n");
            printf("请输入书籍编号：");
            scanf("%d", &id);
            printf("请输入书籍名称：");
            scanf("%s", name);
            printf("请输入书籍价格：");
            scanf("%f", &price);
            printf("********************************\n");
            addBook(books, &n, id, name, price);
            break;
        }
        case 3:
        {
            int id;
            printf("请输入要删除的书籍编号：");
            scanf("%d", &id);
            deleteBook(books, &n, id);
            break;
        }
        case 4:
            exit(0);
        default:
            printf("无效的选择，请重新选择。\n");
        }
    }

    return 0;
}

//编写书籍信息查询的函数接口
void displayBooks(struct Book books[], int n) { 
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("书籍编号\t\t书籍名称\t\t价格\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", books[i].id, books[i].name, books[i].price);
        
    }
    printf("^^^^^^^^\t\t^^^^^^^^\t\t^^^^\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

//编写书籍信息补充的函数接口
void addBook(struct Book books[], int* n, unsigned  int id, const char* name, float price) {
    if (*n >= 100) {
        printf("书籍数量已达上限\n");
        return;
    }
    books[*n].id = id;
    strcpy(books[*n].name, name);
    books[*n].price = price;
    (*n)++;
    printf("该书籍信息添加成功\n");
}

//编写书籍信息删除的函数接口
void deleteBook(struct Book books[], int* n, unsigned int id) {
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            printf("该书籍信息删除成功\n");
            break;
        }
    }
    if (!found) {
        printf("未找到该编号的书籍，请重试\n");
    }
}
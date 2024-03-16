#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����һ�������Ϣ����Ϊһ���ṹ��
struct Book {
    unsigned int id;//��ı��
    char name[100];//�������
    float price;//��ļ۸�
};


//������ѯͼ����Ϣ�ĺ����ӿ�
void displayBooks(struct Book books[], int n);
//�ýṹ��ָ��ͼ�����ָ����ղ�ѯ����ͼ����Ϣ

//�������ͼ����Ϣ�ĺ����ӿ�
void addBook(struct Book books[], int* n, unsigned int id, const char* name, float price);
//�ýṹ��ָ��ͼ�����ָ���������ͼ����Ϣ�����βδ��������µ��鼮��Ϣ����������½��ṹ����

//����ɾ��ͼ����Ϣ�ĺ����ӿ�
void deleteBook(struct Book books[], int* n, unsigned int id);
//�ýṹ��ָ��ͼ�����ָ���������ͼ����Ϣ�����鼮��Ϣ���Ϊ��׼��ɾ����Ӧ�鼮��Ϣ

int main() {
    struct Book books[100];  // ����ϵͳ������100����
    int n = 0;  // ��ǰ�鼮����������������
    int choice;
    system("color 34");
    while (1) {
        printf("********************************\n");
        printf("***** Mr.Nie��ͼ�����ϵͳ *****\n");
        printf("*********1. ��ʾ�����鼮 *******\n");
        printf("*********2. ����鼮 ***********\n");
        printf("*********3. ɾ���鼮 ***********\n");
        printf("*********4. �˳� ***************\n");
        printf("��ѡ�����>>");
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
            printf("�������鼮��ţ�");
            scanf("%d", &id);
            printf("�������鼮���ƣ�");
            scanf("%s", name);
            printf("�������鼮�۸�");
            scanf("%f", &price);
            printf("********************************\n");
            addBook(books, &n, id, name, price);
            break;
        }
        case 3:
        {
            int id;
            printf("������Ҫɾ�����鼮��ţ�");
            scanf("%d", &id);
            deleteBook(books, &n, id);
            break;
        }
        case 4:
            exit(0);
        default:
            printf("��Ч��ѡ��������ѡ��\n");
        }
    }

    return 0;
}

//��д�鼮��Ϣ��ѯ�ĺ����ӿ�
void displayBooks(struct Book books[], int n) { 
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("�鼮���\t\t�鼮����\t\t�۸�\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", books[i].id, books[i].name, books[i].price);
        
    }
    printf("^^^^^^^^\t\t^^^^^^^^\t\t^^^^\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

//��д�鼮��Ϣ����ĺ����ӿ�
void addBook(struct Book books[], int* n, unsigned  int id, const char* name, float price) {
    if (*n >= 100) {
        printf("�鼮�����Ѵ�����\n");
        return;
    }
    books[*n].id = id;
    strcpy(books[*n].name, name);
    books[*n].price = price;
    (*n)++;
    printf("���鼮��Ϣ��ӳɹ�\n");
}

//��д�鼮��Ϣɾ���ĺ����ӿ�
void deleteBook(struct Book books[], int* n, unsigned int id) {
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            printf("���鼮��Ϣɾ���ɹ�\n");
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ��ñ�ŵ��鼮��������\n");
    }
}
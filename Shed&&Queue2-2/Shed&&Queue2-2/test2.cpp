//��C������ʵ�����������ݽṹͨ��ʹ�ýڵ�ṹ������ʾ����ÿһ����֧��
//���潫��һ���򵥵����ӣ�ʵ��һ��������������ÿ���ڵ������ݺ�ָ�������ӽڵ��ָ�롣

#include <stdio.h>
#include <stdlib.h>

// �������Ľڵ�ṹ��
typedef struct TreeNode {
    int data;           // �ڵ�洢������
    struct TreeNode* left;  // ָ�����ӽڵ��ָ��
    struct TreeNode* right; // ָ�����ӽڵ��ָ��
} TreeNode;

// �����½ڵ�ĺ���
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ����ڵ㵽���ĺ���
TreeNode* insertNode(TreeNode* root, int data, int* error) {
    // ������ڵ�Ϊ�գ������½ڵ���Ϊ���ڵ�
    if (root == NULL) {
        return createNode(data);
    }
    // �����ǰ�ڵ�������Ѿ����ڣ����ش���
    if (root->data == data) {
        *error = 1;
        return root;
    }
    // ���뵽������
    if (data < root->data) {
        root->left = insertNode(root->left, data, error);
    }
    // ���뵽������
    else {
        root->right = insertNode(root->right, data, error);
    }
    return root;
}

// ����������ĸ�������
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// �����������ڲ�����������
int main() {
    TreeNode* root = NULL;
    int error = 0;

    // ����һ���򵥵Ķ���������
    root = insertNode(root, 50, &error);
    insertNode(root, 30, &error);
    insertNode(root, 70, &error);
    insertNode(root, 20, &error);
    insertNode(root, 40, &error);
    insertNode(root, 60, &error);
    insertNode(root, 80, &error);

    // ���������������ӡ���
    printf("��������������Ľ����\n");
    inorder(root);
    printf("\n");

    return 0;
}

//���������ʾ���У�
//������һ��TreeNode�ṹ�壬���а����˽ڵ�Ļ�����Ϣ��
//createNode�������ڴ����µ����ڵ㡣
//insertNode��������������������в����µĽڵ㡣
//inorder�������ڽ���������������Ƕ�����������һ�ֱ�׼������ʽ�����Եõ�����õĽڵ����С�
//��main�����У�������һ���򵥵Ķ������������������������������֤���Ĳ��빦�ܡ�
//��ע�⣬�������ֻ��һ��������ʾ����ʵ��Ӧ���п��ܻ���Ҫ����Ĺ��ܣ�
//����ɾ���ڵ㡢���ҽڵ㡢ƽ�����ȡ����ң�����ʵ����Ҫ�����Ľṹ�ͽڵ����ݿ���Ҳ��������ͬ��
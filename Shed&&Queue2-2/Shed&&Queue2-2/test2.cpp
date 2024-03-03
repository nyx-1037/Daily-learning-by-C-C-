//在C语言中实现树这种数据结构通常使用节点结构体来表示树的每一个分支。
//下面将举一个简单的例子，实现一个二叉树，其中每个节点有数据和指向左右子节点的指针。

#include <stdio.h>
#include <stdlib.h>

// 定义树的节点结构体
typedef struct TreeNode {
    int data;           // 节点存储的数据
    struct TreeNode* left;  // 指向左子节点的指针
    struct TreeNode* right; // 指向右子节点的指针
} TreeNode;

// 创建新节点的函数
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点到树的函数
TreeNode* insertNode(TreeNode* root, int data, int* error) {
    // 如果根节点为空，创建新节点作为根节点
    if (root == NULL) {
        return createNode(data);
    }
    // 如果当前节点的数据已经存在，返回错误
    if (root->data == data) {
        *error = 1;
        return root;
    }
    // 插入到左子树
    if (data < root->data) {
        root->left = insertNode(root->left, data, error);
    }
    // 插入到右子树
    else {
        root->right = insertNode(root->right, data, error);
    }
    return root;
}

// 中序遍历树的辅助函数
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 主函数，用于测试上述功能
int main() {
    TreeNode* root = NULL;
    int error = 0;

    // 创建一个简单的二叉搜索树
    root = insertNode(root, 50, &error);
    insertNode(root, 30, &error);
    insertNode(root, 70, &error);
    insertNode(root, 20, &error);
    insertNode(root, 40, &error);
    insertNode(root, 60, &error);
    insertNode(root, 80, &error);

    // 中序遍历树，并打印结果
    printf("中序遍历二叉树的结果：\n");
    inorder(root);
    printf("\n");

    return 0;
}

//在这个代码示例中：
//定义了一个TreeNode结构体，其中包含了节点的基本信息。
//createNode函数用于创建新的树节点。
//insertNode函数用于向二叉搜索树中插入新的节点。
//inorder函数用于进行中序遍历，这是二叉搜索树的一种标准遍历方式，可以得到排序好的节点序列。
//在main函数中，创建了一个简单的二叉搜索树，并进行了中序遍历以验证树的插入功能。
//请注意，这个代码只是一个基础的示例，实际应用中可能还需要更多的功能，
//比如删除节点、查找节点、平衡树等。而且，根据实际需要，树的结构和节点数据可能也会有所不同。
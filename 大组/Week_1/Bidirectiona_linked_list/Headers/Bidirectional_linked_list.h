#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// 结点结构体
struct node {
    int data;
    struct node* pre;
    struct node* next;
};

// 在链表末尾追加节点
void append(struct node* head, int data);

// 在链表头部插入节点
void prepend(struct node* head, int data);

// 删除链表中的元素
void delete_node(struct node* head, int data);

// 显示链表中的元素
void display(struct node* head);

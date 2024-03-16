#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//单链表ADT
// 结点结构体
struct node {
    int data;
    struct node* next;
};

// 在链表末尾追加元素
void append(struct node* head, int data);

// 在链表前插入元素
void prepend(struct node* head, int data);

// 删除链表中的元素
void delete_node(struct node* head, int data);

// 显示链表中的元素
void display(struct node* head);

// 调换链表中奇偶位置的元素
void Change(struct node* head);

// 查找链表中的中间节点
struct node* Find_Middle(struct node* head);

// 使链表成环
void Cricle(struct node* head);

// 判断链表是否成环
void Find_Cricle(struct node* head);

// 非递归方式反转链表
void Reverse_linked(struct node* head);

// 递归方式反转链表
struct node* Recursion(struct node* pre, struct node* current, struct node* head);

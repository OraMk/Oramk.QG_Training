#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// ���ṹ��
struct node {
    int data;
    struct node* pre;
    struct node* next;
};

// ������ĩβ׷�ӽڵ�
void append(struct node* head, int data);

// ������ͷ������ڵ�
void prepend(struct node* head, int data);

// ɾ�������е�Ԫ��
void delete_node(struct node* head, int data);

// ��ʾ�����е�Ԫ��
void display(struct node* head);

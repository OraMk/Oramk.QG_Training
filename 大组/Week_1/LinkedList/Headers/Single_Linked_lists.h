#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//������ADT
// ���ṹ��
struct node {
    int data;
    struct node* next;
};

// ������ĩβ׷��Ԫ��
void append(struct node* head, int data);

// ������ǰ����Ԫ��
void prepend(struct node* head, int data);

// ɾ�������е�Ԫ��
void delete_node(struct node* head, int data);

// ��ʾ�����е�Ԫ��
void display(struct node* head);

// ������������żλ�õ�Ԫ��
void Change(struct node* head);

// ���������е��м�ڵ�
struct node* Find_Middle(struct node* head);

// ʹ����ɻ�
void Cricle(struct node* head);

// �ж������Ƿ�ɻ�
void Find_Cricle(struct node* head);

// �ǵݹ鷽ʽ��ת����
void Reverse_linked(struct node* head);

// �ݹ鷽ʽ��ת����
struct node* Recursion(struct node* pre, struct node* current, struct node* head);

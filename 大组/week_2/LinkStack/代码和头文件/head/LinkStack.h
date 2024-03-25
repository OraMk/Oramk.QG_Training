#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;
typedef enum Priority
{
	larger = 1,
	Less = -1,
	equal = 0
} Priority;
typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct DoubleStackNode
{
	double data;
	struct DoubleStackNode *next;
}DoubleStackNode, *DoubleLinkStackPtr;

typedef  struct  LinkStack
{
	DoubleLinkStackPtr doubletop;
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
Status DoublegetTopLStack(LinkStack *s,double *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status DoublepushLStack(LinkStack *s,double data);//��ջ
Status popLStack(LinkStack *s,ElemType *data);//��ջ
Status DoublepopLStack(LinkStack *s,double *data);//��ջ



#endif 

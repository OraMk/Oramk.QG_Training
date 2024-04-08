//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;


//栈的结构体
typedef int ElemType;

typedef  struct StackNode
{
	NodePtr data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;


typedef  struct  LinkStack
{
	
	StackNode* top;
	int	count;
}LinkStack;


//链式队列结构
typedef struct node
{
    NodePtr data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} QNode;

typedef struct Lqueue
{
    QNode *front;                   //队头
    QNode *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr, ElemType);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr, ElemType);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr, ElemType);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));


Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status pushLStack(LinkStack *s,NodePtr root);//入栈
StackNode* popLStack(LinkStack *s);//出栈
StackNode* getTopLStack(LinkStack *s);//得到栈顶元素

void InitLQueue(LQueue *Q);//初始化队列
Status IsEmptyLQueue(const LQueue *Q);//判断队列是否为空
Status EnLQueue(LQueue *Q, NodePtr data);//入队操作
QNode* DeLQueue(LQueue *Q);//出队操作
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H

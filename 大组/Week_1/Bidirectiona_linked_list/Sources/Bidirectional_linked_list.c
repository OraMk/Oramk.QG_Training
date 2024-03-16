#include "Bidirectional_linked_list.h"



//在链表末尾添加节点
void append(struct node * head , int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* lastnode = head;
    newnode->data = data;
    newnode->next = NULL;
    //判断是否为空链表
    if (lastnode->next == NULL)
    {
        lastnode->next = newnode;//连接链表
        return;
    }
    else{
        while (lastnode->next)//遍历链表查找末节点
        {
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
        newnode->pre = lastnode;//双向指针
        
    }
}
//在链表头添加结点
void prepend(struct node* head,int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if (head->next == NULL)//判断是否为空链表
    {
        head->next = newnode;
        newnode->next = NULL;
        newnode->pre = NULL;
    }
    else
    {
        newnode->next = head->next;
        head->next->pre = newnode;//形成双向链表
        head->next = newnode;
        newnode->pre = NULL;
    }
    
    
}

//删除链表中的元素
void delete_node(struct node* head,int data)
{
    struct node* temp = head->next;
    struct node* pre = head;
    while (temp!=NULL)
    {
        if(temp->data == data)
        {
            pre->next = temp->next;
            temp->next->pre = pre;//形成双向链表
            free(temp);
            temp = pre->next;
        }
        else{
            pre = temp;
            temp = temp ->next;
        }
        
    }
    
    
}

//显示链表中的元素
void display(struct node * head)
{
    
    if (head->next!=NULL)//判断是否空链表
    {
        struct node* current = head->next;
        while (current)
    {
        printf("%d",current->data);
        current = current->next;
    }
    printf("\n");
    }
    
    
    
}

int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->pre = NULL;
    head->next = NULL; // 初始化头节点
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 7);
    append(head, 8);
    append(head, 9);//添加元素
    prepend(head, 0);//在头添加元素
    display(head);  //显示链表
    delete_node(head, 1); // 删除
    display(head);  //显示链表
    Sleep(1000*2);
    return 0;
}

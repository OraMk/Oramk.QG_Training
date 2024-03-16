#include "Single_Linked_lists.h"

//实现单链表ADT


//在链表末尾追加元素
void append(struct node* head,int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* lastnode = head;
    newnode->data = data;
    newnode->next = NULL;
    //判断是否为空链表
    if (lastnode->next == NULL)
    {
        lastnode->next = newnode;
        return;
    }
    else{
        while (lastnode->next)//遍历链表查找末节点
        {
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
        
        
    }
    
}
//在链表前插入元素
void prepend(struct node* head,int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if (head->next == NULL)//判断是否为空链表
    {
        head->next = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head->next;
        head->next = newnode;
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
    
    if (head!=NULL)//判断是否空链表
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

void Change(struct node* head)//调换链表中奇偶
{
    struct node * pre = head;
    struct node * next = head;
    struct node * current = head;
    if (head != NULL)
    {
        current = head ->next;
        next = head ->next->next;
    }
    while (next->next != NULL && next != NULL)
    {
        
        pre ->next = next;
        current->next = next->next;
        next->next = current;
        pre = current;
        current=current->next;
        next=current->next;
    }
    
}
struct node* Find_Middle(struct  node* head)//查找中间结点
{
    if (head!=NULL)
    {
        struct node * slow = head;
        struct node * fast = head;
        while (fast && fast ->next)//判断fast是否走到未结点
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }
        //退出循环即找到未节点
        //则slow为中间节点
        printf("%d\n",slow->data);
        return slow;
        
    }
    
    
}
void Cricle(struct node* head)//使得链表成环
{
    struct node* lastnode = head;
    while (lastnode->next)
    {
        lastnode = lastnode->next;
    }
    lastnode->next = head;
    
}
void Find_Cricle(struct  node* head)//判断是否成环
{
    if (head!=NULL)
    {
        struct node * slow = head;
        struct node * fast = head;
        slow = slow ->next;
        fast = fast ->next ->next;
        while (fast != slow  && (fast && fast ->next ))//判断fast是否走到未结点或者是否成环
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }   
        if (fast == NULL || fast->next == NULL)//判断是否因为走到末结点而退出循环
        {
            printf("NO\n");
            return; 
        }else
        {
            printf("YES\n");
            return;
        }
        
        
        
    }
    
    
}
//反转链表
void Reverse_linked(struct node*head)
{
    struct node * pre,*current,*next,*temp;
    pre = head;
    current = head->next;
    next = current->next;
    while (next->next)//遍历链表并查找末结点
    {
        temp = next->next;//临时存储暂不进行反转的结点
        next->next = current;//反转链表
        if (pre == head)//判断是否为头结点
        {
            current->next = NULL;//反转后为末尾指向空
        }
        
        current = temp;//获取临时储存的结点
        pre = next;//将这次反转的末尾赋值给pre指针
        next = current->next;//获取未反转的结点的下一节点
        current->next = pre;//将下一次要反转链表的头指针的next指针反转给上一次反转的未结点
        
    }
    next->next = current;
    head->next = next;
}
//递归方式反转链表
struct node * Recursion(struct node * pre,struct node *current, struct node * head)
{   
    if (current == NULL)//查找到反转前的末结点
    {
        head->next = pre;//将头指向末结点
        return pre;
    }
    struct node* next = current->next;
    if (pre == head)//若为反转前的头结点
    {
        current->next = NULL;
    }
    else
    {
        current->next = pre;//将当前的结点的next指针指向前结点
    }
    return Recursion(current,next,head);//递归

    
    
    
    
}
int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
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
    Find_Middle(head);//查找中间
    display(head);  //显示链表
    Reverse_linked(head);//用非递归反转链表
    display(head);  //显示调换后的链表
    Recursion(head,head->next,head);//用递归反转链表
    display(head);  //显示调换后的链表
    Change(head);   //调换奇偶
    display(head);  //显示调换后的链表
    delete_node(head, 1); // 删除
    display(head);  //显示链表
    Find_Middle(head);//查找中间
    Find_Cricle(head);//判断是否成环
    Cricle(head);//使链表成环
    Find_Cricle(head);//再次判断
    Sleep(1000*2);
    return 0;
    
}
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
struct node* Initial()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->pre = NULL;
    head->next = NULL; // 初始化头节点
    return head;
}
void Enum(){
    struct node * head = NULL;
    int chose = 0;
    int data = 0;
    struct node * middle = NULL;
    printf("=======================\n");
    printf("=====1.创建链表========\n");
    printf("===2.在链表头插入结点====\n");
    printf("===3.在链表尾部插入结点==\n");
    printf("====4.删除链表结点======\n");
    printf("====5.显示链表中的元素==\n");
    printf("========6.清屏  =======\n");
    printf("========0.退出==========\n");
    while (1)
    {   
    printf("请输入选项:");
    scanf("%d",&chose);
    switch(chose)
    {
        case 1:head = Initial();
        printf("已创建好链表头指针\n");
        
        break;
        case 3:
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        printf("请输入要插入的数据:");
        scanf("%d",&data);
        append(head, data);
        printf("插入成功\n");
        break;
        case 2:
       if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        printf("请输入要插入的数据:");
        scanf("%d",&data);
        prepend(head, data);
        printf("插入成功\n");
        break;
        case 4:
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        printf("请输入要删除的数据:");
        scanf("%d",&data);
        delete_node(head,data);
        printf("删除成功\n");
        break;
        case 5:
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        display(head);
        break;
        case 6:
        system("cls");
        break;
        case 0:
        exit(0);
        break;
    }
    
    
    }
    
    
    


}

int main()
{
   
    Enum();
    return 0;
}
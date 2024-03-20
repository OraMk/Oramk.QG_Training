#include "Single_Linked_lists.h"

//实现单链表ADT


//在链表末尾追加元素
void append(struct node* head,int data)
{
    struct node* p = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* lastnode = head;
    newnode->data = data;
    newnode->next = NULL;
    boolean cricle = FALSE;
    
    //判断是否为空链表
    if (lastnode->next == NULL)
    {
        lastnode->next = newnode;
        return;
    }
    else{
        lastnode = lastnode->next;
        if (lastnode!=NULL)
        {
            while (lastnode->next!=NULL && lastnode->next != head->next)//遍历链表查找末节点
        {
            lastnode = lastnode->next;
                if (lastnode->next == head->next)
            {
                cricle=TRUE;
            }
            
        }
        lastnode->next = newnode;
        if (cricle)
        {
            newnode->next=head->next;
        }
        
        }
        
        
        
        
    }
    
}
//在链表前插入元素
void prepend(struct node* head,int data)
{       
    struct node* p = head;
    boolean cricle = FALSE;
    if (p != NULL)
    {
        p = p->next;
        if(p != NULL)
        {
            
            while (p->next)
        {
            if (p->next == head->next)
            {
                cricle = TRUE;
                break;
            }
            p = p->next;
        }
        }
        
        
        
    }
    
   
    
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
    
    if (cricle)
    {
        p->next = newnode;
    }
    
    
    
    
}

//删除链表中的元素
void delete_node(struct node* head,int data)
{
    
    struct node* temp = head->next;
    struct node* pre = head;
    if (temp!=NULL)
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
    
    while (temp!=NULL && temp->next!=head->next)
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
    struct node* current = head->next;
    
    if (head!=NULL)//判断是否空链表
    {
        
        if (current)
    {
        printf("%d",current->data);
        current = current->next;
    }
    
    while (current && current != head->next)
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
    if (head->next != NULL)
    {
        current = head ->next;
        next = head ->next->next;
    }
    // while (next != NULL && next->next != NULL)
    while(next!=NULL && next->next != head->next )
    {
        
        pre ->next = next;
        current->next = next->next;
        next->next = current;
        pre = current;
        current=current->next;
        if (current == NULL)
        {
            break;
        }
        
        next=current->next;
    }
    
}
struct node* Find_Middle(struct  node* head)//查找中间结点
{
    
    if (head!=NULL)
    {
        struct node * slow = head;
        struct node * fast = head;
        if (fast && fast ->next  )//判断fast是否走到未结点
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }
         while (fast && fast ->next  && fast->next != head->next )//判断fast是否走到未结点
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }
        
        //退出循环即找到未节点
        //则slow为中间节点

        return slow;
        
    }
    return NULL;
    
    
}
void Cricle(struct node* head)//使得链表成环
{
   
    struct node* lastnode = head;
    while (lastnode->next)
    {
        lastnode = lastnode->next;
    }
    lastnode->next = head->next;
    
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
    while (next->next && next->next != head->next )//遍历链表并查找末结点
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
    
    if (current == NULL || (pre != head && current == head->next))//查找到反转前的末结点
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
struct node * Initial()
{
    
     struct node* head = (struct node*)malloc(sizeof(struct node));
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
    printf("====6.调换链表中奇偶====\n");
    printf("====7.查找中间结点======\n");
    printf("=8.使得链表成环(首尾相连)=\n");
    printf("====9.判断是否成环======\n");
    printf("====10.反转链表=========\n");
    printf("====11.递归方式反转链表==\n");
    printf("========12.清屏  =======\n");
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
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        Change(head);
        printf("调换成功\n");
        break;
        case 7:
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        middle = Find_Middle(head);
        if (middle != NULL)
        {
            printf("已查找到\n");
            printf("数据为%d\n",middle->data);
        }
        else{
            printf("未查找到\n");
        }
        break;
        case 8:
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        Cricle(head);
        printf("已成环状\n");
        break;
        case 9:
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        Find_Cricle(head);
        break;
        case 10:
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        Reverse_linked(head);
        printf("已经反转\n");
        break;
        case 11:
        if(head==NULL){
        printf("链表未初始化，请先初始化\n");
        break;
    }
        Recursion(head,head->next,head);
        printf("已经反转\n");
        break;
        case 12:
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
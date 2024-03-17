# 链表

## 单向链表

### 链表节点的定义

```c
struct node{

int data;

struct node * next; 

};
```



### 链表的初始化

```c
struct node * initial()
{
    struct node* head =(struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    return head;
 }
```



### 在链表末尾追加元素

```c
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
```



### 在链表前追加元素

```c
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
```



### 删除链表中的元素

```c
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
```

### 显示链表中的元素

```c
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

```



### 调换链表中的奇偶项

```c
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
```

### 查找中间结点

```c
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
```

### 判断链表是否成环

```c
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
```

### 反转链表

#### 非递归

```c
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
```

#### 递归

```c
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
```

---



## 双向链表

### 链表节点的定义

```c
struct node{
int data;
    
struct node* pre;
    
struct node* next;
    
};
```

### 链表的初始化

```c
struct node * intial()
{
  struct node* head = (struct node*)malloc(sizeof(struct node));
    head->pre = NULL;
    head ->next = NULL;
    return head;
}
```

### 在链表末尾添加节点

```c
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
```

### 在链表头添加结点

```c
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
```

### 删除链表中的元素

```c
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
```

### 显示链表中的数据

```
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
```


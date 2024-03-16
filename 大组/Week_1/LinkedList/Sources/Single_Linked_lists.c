#include "Single_Linked_lists.h"

//ʵ�ֵ�����ADT


//������ĩβ׷��Ԫ��
void append(struct node* head,int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* lastnode = head;
    newnode->data = data;
    newnode->next = NULL;
    //�ж��Ƿ�Ϊ������
    if (lastnode->next == NULL)
    {
        lastnode->next = newnode;
        return;
    }
    else{
        while (lastnode->next)//�����������ĩ�ڵ�
        {
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
        
        
    }
    
}
//������ǰ����Ԫ��
void prepend(struct node* head,int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if (head->next == NULL)//�ж��Ƿ�Ϊ������
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

//ɾ�������е�Ԫ��
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
//��ʾ�����е�Ԫ��
void display(struct node * head)
{
    
    if (head!=NULL)//�ж��Ƿ������
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

void Change(struct node* head)//������������ż
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
struct node* Find_Middle(struct  node* head)//�����м���
{
    if (head!=NULL)
    {
        struct node * slow = head;
        struct node * fast = head;
        while (fast && fast ->next)//�ж�fast�Ƿ��ߵ�δ���
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }
        //�˳�ѭ�����ҵ�δ�ڵ�
        //��slowΪ�м�ڵ�
        printf("%d\n",slow->data);
        return slow;
        
    }
    
    
}
void Cricle(struct node* head)//ʹ������ɻ�
{
    struct node* lastnode = head;
    while (lastnode->next)
    {
        lastnode = lastnode->next;
    }
    lastnode->next = head;
    
}
void Find_Cricle(struct  node* head)//�ж��Ƿ�ɻ�
{
    if (head!=NULL)
    {
        struct node * slow = head;
        struct node * fast = head;
        slow = slow ->next;
        fast = fast ->next ->next;
        while (fast != slow  && (fast && fast ->next ))//�ж�fast�Ƿ��ߵ�δ�������Ƿ�ɻ�
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }   
        if (fast == NULL || fast->next == NULL)//�ж��Ƿ���Ϊ�ߵ�ĩ�����˳�ѭ��
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
//��ת����
void Reverse_linked(struct node*head)
{
    struct node * pre,*current,*next,*temp;
    pre = head;
    current = head->next;
    next = current->next;
    while (next->next)//������������ĩ���
    {
        temp = next->next;//��ʱ�洢�ݲ����з�ת�Ľ��
        next->next = current;//��ת����
        if (pre == head)//�ж��Ƿ�Ϊͷ���
        {
            current->next = NULL;//��ת��Ϊĩβָ���
        }
        
        current = temp;//��ȡ��ʱ����Ľ��
        pre = next;//����η�ת��ĩβ��ֵ��preָ��
        next = current->next;//��ȡδ��ת�Ľ�����һ�ڵ�
        current->next = pre;//����һ��Ҫ��ת�����ͷָ���nextָ�뷴ת����һ�η�ת��δ���
        
    }
    next->next = current;
    head->next = next;
}
//�ݹ鷽ʽ��ת����
struct node * Recursion(struct node * pre,struct node *current, struct node * head)
{   
    if (current == NULL)//���ҵ���תǰ��ĩ���
    {
        head->next = pre;//��ͷָ��ĩ���
        return pre;
    }
    struct node* next = current->next;
    if (pre == head)//��Ϊ��תǰ��ͷ���
    {
        current->next = NULL;
    }
    else
    {
        current->next = pre;//����ǰ�Ľ���nextָ��ָ��ǰ���
    }
    return Recursion(current,next,head);//�ݹ�

    
    
    
    
}
int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL; // ��ʼ��ͷ�ڵ�
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 7);
    append(head, 8);
    append(head, 9);//���Ԫ��
    prepend(head, 0);//��ͷ���Ԫ��
    Find_Middle(head);//�����м�
    display(head);  //��ʾ����
    Reverse_linked(head);//�÷ǵݹ鷴ת����
    display(head);  //��ʾ�����������
    Recursion(head,head->next,head);//�õݹ鷴ת����
    display(head);  //��ʾ�����������
    Change(head);   //������ż
    display(head);  //��ʾ�����������
    delete_node(head, 1); // ɾ��
    display(head);  //��ʾ����
    Find_Middle(head);//�����м�
    Find_Cricle(head);//�ж��Ƿ�ɻ�
    Cricle(head);//ʹ����ɻ�
    Find_Cricle(head);//�ٴ��ж�
    Sleep(1000*2);
    return 0;
    
}
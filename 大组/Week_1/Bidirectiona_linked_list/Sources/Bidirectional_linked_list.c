#include "Bidirectional_linked_list.h"



//������ĩβ��ӽڵ�
void append(struct node * head , int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* lastnode = head;
    newnode->data = data;
    newnode->next = NULL;
    //�ж��Ƿ�Ϊ������
    if (lastnode->next == NULL)
    {
        lastnode->next = newnode;//��������
        return;
    }
    else{
        while (lastnode->next)//�����������ĩ�ڵ�
        {
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
        newnode->pre = lastnode;//˫��ָ��
        
    }
}
//������ͷ��ӽ��
void prepend(struct node* head,int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if (head->next == NULL)//�ж��Ƿ�Ϊ������
    {
        head->next = newnode;
        newnode->next = NULL;
        newnode->pre = NULL;
    }
    else
    {
        newnode->next = head->next;
        head->next->pre = newnode;//�γ�˫������
        head->next = newnode;
        newnode->pre = NULL;
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
            temp->next->pre = pre;//�γ�˫������
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
    
    if (head->next!=NULL)//�ж��Ƿ������
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
    display(head);  //��ʾ����
    delete_node(head, 1); // ɾ��
    display(head);  //��ʾ����
    Sleep(1000*2);
    return 0;
}

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
struct node* Initial()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->pre = NULL;
    head->next = NULL; // ��ʼ��ͷ�ڵ�
    return head;
}
void Enum(){
    struct node * head = NULL;
    int chose = 0;
    int data = 0;
    struct node * middle = NULL;
    printf("=======================\n");
    printf("=====1.��������========\n");
    printf("===2.������ͷ������====\n");
    printf("===3.������β��������==\n");
    printf("====4.ɾ��������======\n");
    printf("====5.��ʾ�����е�Ԫ��==\n");
    printf("========6.����  =======\n");
    printf("========0.�˳�==========\n");
    while (1)
    {   
    printf("������ѡ��:");
    scanf("%d",&chose);
    switch(chose)
    {
        case 1:head = Initial();
        printf("�Ѵ���������ͷָ��\n");
        
        break;
        case 3:
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        printf("������Ҫ���������:");
        scanf("%d",&data);
        append(head, data);
        printf("����ɹ�\n");
        break;
        case 2:
       if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        printf("������Ҫ���������:");
        scanf("%d",&data);
        prepend(head, data);
        printf("����ɹ�\n");
        break;
        case 4:
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        printf("������Ҫɾ��������:");
        scanf("%d",&data);
        delete_node(head,data);
        printf("ɾ���ɹ�\n");
        break;
        case 5:
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
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
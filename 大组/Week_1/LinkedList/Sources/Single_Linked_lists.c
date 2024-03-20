#include "Single_Linked_lists.h"

//ʵ�ֵ�����ADT


//������ĩβ׷��Ԫ��
void append(struct node* head,int data)
{
    struct node* p = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* lastnode = head;
    newnode->data = data;
    newnode->next = NULL;
    boolean cricle = FALSE;
    
    //�ж��Ƿ�Ϊ������
    if (lastnode->next == NULL)
    {
        lastnode->next = newnode;
        return;
    }
    else{
        lastnode = lastnode->next;
        if (lastnode!=NULL)
        {
            while (lastnode->next!=NULL && lastnode->next != head->next)//�����������ĩ�ڵ�
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
//������ǰ����Ԫ��
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
    
    if (cricle)
    {
        p->next = newnode;
    }
    
    
    
    
}

//ɾ�������е�Ԫ��
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
//��ʾ�����е�Ԫ��
void display(struct node * head)
{
    struct node* current = head->next;
    
    if (head!=NULL)//�ж��Ƿ������
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

void Change(struct node* head)//������������ż
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
struct node* Find_Middle(struct  node* head)//�����м���
{
    
    if (head!=NULL)
    {
        struct node * slow = head;
        struct node * fast = head;
        if (fast && fast ->next  )//�ж�fast�Ƿ��ߵ�δ���
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }
         while (fast && fast ->next  && fast->next != head->next )//�ж�fast�Ƿ��ߵ�δ���
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }
        
        //�˳�ѭ�����ҵ�δ�ڵ�
        //��slowΪ�м�ڵ�

        return slow;
        
    }
    return NULL;
    
    
}
void Cricle(struct node* head)//ʹ������ɻ�
{
   
    struct node* lastnode = head;
    while (lastnode->next)
    {
        lastnode = lastnode->next;
    }
    lastnode->next = head->next;
    
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
    while (next->next && next->next != head->next )//������������ĩ���
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
    
    if (current == NULL || (pre != head && current == head->next))//���ҵ���תǰ��ĩ���
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
struct node * Initial()
{
    
     struct node* head = (struct node*)malloc(sizeof(struct node));
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
    printf("====6.������������ż====\n");
    printf("====7.�����м���======\n");
    printf("=8.ʹ������ɻ�(��β����)=\n");
    printf("====9.�ж��Ƿ�ɻ�======\n");
    printf("====10.��ת����=========\n");
    printf("====11.�ݹ鷽ʽ��ת����==\n");
    printf("========12.����  =======\n");
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
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        Change(head);
        printf("�����ɹ�\n");
        break;
        case 7:
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        middle = Find_Middle(head);
        if (middle != NULL)
        {
            printf("�Ѳ��ҵ�\n");
            printf("����Ϊ%d\n",middle->data);
        }
        else{
            printf("δ���ҵ�\n");
        }
        break;
        case 8:
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        Cricle(head);
        printf("�ѳɻ�״\n");
        break;
        case 9:
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        Find_Cricle(head);
        break;
        case 10:
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        Reverse_linked(head);
        printf("�Ѿ���ת\n");
        break;
        case 11:
        if(head==NULL){
        printf("����δ��ʼ�������ȳ�ʼ��\n");
        break;
    }
        Recursion(head,head->next,head);
        printf("�Ѿ���ת\n");
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
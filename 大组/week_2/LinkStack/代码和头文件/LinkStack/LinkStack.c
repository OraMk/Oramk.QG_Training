#include "LinkStack.h"
Status initLStack(LinkStack *s){
    s->count = 0;
    s->top = NULL;
    s->doubletop = NULL;
}//��ʼ��ջ

Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if (s->top!=NULL)
    {
        return ERROR;
    }
    else
    return SUCCESS;
    
}
Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
    if (isEmptyLStack(s))
    {
        printf("Ϊ��ջ�޷���ȡջ��Ԫ��\n");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

Status clearLStack(LinkStack *s)//���ջ
{
    if (isEmptyLStack(s))
    {
        printf("Ϊ��ջ��������\n");
        return ERROR;
    }
    
    LinkStackPtr temp ;
    while (s->top)
    {   temp = s->top;
        s->top = s->top->next;
        s->count--;
        free(temp);
       
       
    }
    
     return SUCCESS;
}
Status destroyLStack(LinkStack *s)//����ջ
{
    if(clearLStack(s))
    {
        free(s);
        return SUCCESS;
        
    }
    return ERROR;
}
Status LStackLength(LinkStack *s,int *length)//���ջ����
{
    if (isEmptyLStack(s))
    {
       printf("Ϊ��ջ������\n");
        return ERROR;
    }
    
    *length = s->count;
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = data;
    p->next = NULL;
    if (isEmptyLStack(s))
    {
        s->top = p;
    }
    else{
        p->next = s->top;
        s->top = p;
    }
    s->count++;
    return SUCCESS;
    
}

Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
    if (!isEmptyLStack(s))
    {
        *data = s->top->data;
        LinkStackPtr p = s->top;
        s->top = s->top->next;
        free(p);
        p = NULL;
        s->count--;
        return SUCCESS;
        
    }
    
        return ERROR;
}
void Enum(){
    LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);
    printf("1.��ջ\n");
    printf("2.��ջ\n");
    printf("3.���ջ����\n");
    printf("4.�õ�ջ��Ԫ��\n");
    printf("5.�ж�ջ��\n");
    printf("6.���ջ\n");
    printf("7.����ջ\n");
    printf("8.��ʼ��ջ(Ĭ���Ѿ���ʼ��)\n");
    printf("0.�˳�\n");
    int chose = 0;
    int data = 0;
    int length = 0;
    while (1)
    {   
    printf("������ѡ��:");
    scanf("%d",&chose);
    switch(chose)
    {
        case 1:
        if (s==NULL)
        {
            printf("ջ������,���ȳ�ʼ��");
            break;
        }
        
        printf("������Ҫ���������:");
        scanf("%d",&data);
        pushLStack(s,data);
        printf("����ɹ�\n");
        break;
        case 2:
        if (s==NULL)
        {
            printf("ջ������,���ȳ�ʼ��\n");
            break;
        }
        if (popLStack(s,&data) == SUCCESS)
        {
            printf("��ջ�ɹ�����Ϊ:%d\n",data);
        }else printf("ջ��������\n");
        
        
       
        break;
        case 3:
        if (s==NULL)
        {
            printf("ջ������,���ȳ�ʼ��\n");
            break;
        }
        
        if (LStackLength(s,&length) == SUCCESS)
        {
            printf("ջ�ĳ���Ϊ:%d\n",length);
        }else printf("ջ��������\n");
        
        break;
        case 4:
        if (s==NULL)
        {
            printf("ջ������,���ȳ�ʼ��\n");
            break;
        }
        if (getTopLStack(s,&data) == SUCCESS)
        {
            printf("ջ��Ԫ��Ϊ:%d\n",data);
        }else printf("ջ��������\n");
        
        break;
        case 5:
        if (s==NULL)
        {
            printf("ջ������,���ȳ�ʼ��\n");
            break;
        }
        if(isEmptyLStack(s)==ERROR)
        {
            printf("ջ��������\n");
        }
        else{
            printf("ջ��\n");
        }
        
        break;
        case 6:
        if (s==NULL)
        {
            printf("ջ������,���ȳ�ʼ��\n");
            break;
        }
        clearLStack(s);
        printf("�����ջ\n");
        break;
        case 7:
        destroyLStack(s);
        printf("������ջ\n");
        s = NULL;
        break;
        case 8:
        s = (LinkStack *)malloc(sizeof(LinkStack));
        initLStack(s);
        printf("�ѳ�ʼ��\n");
        break;
        default:
        printf("��������,������\n");
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
    
    
}
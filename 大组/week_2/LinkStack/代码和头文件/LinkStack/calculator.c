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
Status isDoubleEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if (s->doubletop != NULL)
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
Status DoublegetTopLStack(LinkStack *s,double *e)//�õ�ջ��Ԫ��
{
    if (isEmptyLStack(s))
    {
        printf("Ϊ��ջ�޷���ȡջ��Ԫ��\n");
        return ERROR;
    }
    *e = s->doubletop->data;
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
Status DoublepushLStack(LinkStack *s,double data)//��ջ
{
    DoubleLinkStackPtr p = (DoubleLinkStackPtr)malloc(sizeof(DoubleStackNode));
    p->data = data;
    p->next = NULL;
    if (isDoubleEmptyLStack(s))
    {
        s->doubletop = p;
    }
    else{
        p->next = s->doubletop;
        s->doubletop = p;
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
Status DoublepopLStack(LinkStack *s,double *data)//��ջ
{
        if (!isDoubleEmptyLStack(s))
    {
        *data = s->doubletop->data;
        DoubleLinkStackPtr p = s->doubletop;
        s->doubletop = s->doubletop->next;
        free(p);
        p = NULL;
        s->count--;
        return SUCCESS;
    }
    
        return ERROR;
}
//�ж���������ȼ�
Priority judgment(LinkStack *s , char c)
{
    if (s->count == 0 || s->top == NULL)
    {
        return larger;
    }
    
    if (c == '*' || c =='/')
    {
        if (s->top->data == '*' || s->top->data == '/')
        {
            return equal;
        }
        else{
            return larger;
        }
        
    }
    if (c == '+' || c =='-')
    {
        if (s->top->data == '+' || s->top->data == '-')
        {
            return equal;
        }
        else if (s->top->data == '*' || s->top->data == '/'){
            return Less;
        }
        else{
            return larger;
        }
        
    }
    return Less;
    
    
}
//��������1.����׺���ʽת��Ϊ��׺���ʽ
int* transformed(char Calculations[],LinkStack *s,int* Suffix_expressions)
{
    int num = strlen(Calculations);
    int n = 0;
    ElemType *e = (ElemType *)malloc(sizeof(ElemType));
    ElemType *temp = (ElemType *)malloc(sizeof(ElemType));
    Suffix_expressions[n++]=' ';
    for (int i = 0; i < num; i++)
    {
        if (Calculations[i] >= '0' && Calculations[i] <= '9' ||Calculations[i] == '.')//���ֻ���С�����ֱ����������
        {
            Suffix_expressions[n++]=Calculations[i];
        }
        else if (Calculations[i] != ')'&&(Calculations[i] == '('||Calculations[i] == '+' ||Calculations[i] == '-' ||Calculations[i] == '*' ||Calculations[i] == '/' ))//�����ź��������ջ
        {   
            while(judgment(s,Calculations[i]) != larger && Calculations[i] != '('){//�ж��Ƿ�Ϊֱ��ѹջ�����
            Suffix_expressions[n++]=' ';
            if (getTopLStack(s,e))//��ջ�������ݳ�ջ
            {
                
                if (s->top->data=='(')//���ջ�к��������������������ź�ֹͣ����ջ�е�ȫ���������ջ
                {
                    break;
                }
                popLStack(s,&Suffix_expressions[n++]);
                if (Calculations[i] != '(')
            {
                Suffix_expressions[n++]=' ';
            }
            }
            
        }
        
            pushLStack(s,Calculations[i]);
            if (Calculations[i] != '(' && Suffix_expressions[n-1] != ' ')
            {
                Suffix_expressions[n++]=' ';
            }
            
            
        }
        else if (Calculations[i] == ')')
        {   
            while (1)
            {
                getTopLStack(s,e);
                if (*e == '(')
                {
                popLStack(s,&Suffix_expressions[n]);
                Suffix_expressions[n] = ' ';
                break;
                }
                Suffix_expressions[n++]=' ';
                popLStack(s,&Suffix_expressions[n++]);
            }
            
            
            
        }
        
        
        

    }
    Suffix_expressions[n++]=' ';

    while (popLStack(s,&Suffix_expressions[n]))
    {   
        n++;
        Suffix_expressions[n++]=' ';
    }
    Suffix_expressions[n]='\0';
    return Suffix_expressions;
    
}

//ͨ����׺����ʽ������
double calculator(LinkStack *s , int expressions[])
{
    s->top = NULL;
    double *n1 = (double *)malloc(sizeof(double));
    double *n2 = (double *)malloc(sizeof(double));
    double *ret = (double *)malloc(sizeof(double));
    int before;
    int after;
    int n = 0;
    char num1[10000];
    char Suffix_expressions[100];
    int i = 0;
    for ( i = 0; i < 100; i++)
    {
        Suffix_expressions[i] = expressions[i];
        if (Suffix_expressions[i]=='\0')
        {
            break;
        }
        
    }
    
    for (int i = 0; i < strlen(Suffix_expressions); i++)
    {
        if (Suffix_expressions[n++]==' ')
    {
        before = n;
        break;
    }
    }
    
        for (int i = before; i < strlen(Suffix_expressions); i++)
        {
            if (Suffix_expressions[n]==' ' && Suffix_expressions[n]!='\0')
            {
                
               after = n;
               
                if (Suffix_expressions[after-1]>='0'&&Suffix_expressions[after-1]<='9')
                {
                    strncpy(num1,Suffix_expressions+before,after-before);
                    num1[after-before]='\0';
                    *n1 = atof(num1);
                    DoublepushLStack(s,*n1);
                }
            else if (Suffix_expressions[after-1]=='+'||Suffix_expressions[after-1]=='-'||Suffix_expressions[after-1]=='*'||Suffix_expressions[after-1]=='/')
            {
                    DoublepopLStack(s, n2);
                    DoublepopLStack(s, n1);
                    switch(Suffix_expressions[after-1])
                    {
                        case '+':  *ret = (*n1) + (*n2);
                                    break;
                        case '-':  *ret = (*n1) - (*n2);
                                    break;
                        case '*':  *ret = (*n1) * (*n2);
                                    break;
                        case '/':  *ret = 1.0*(*n1) / (*n2);
                                    break;
                    }
                    DoublepushLStack(s,*ret);
            
                }
       
                before = after;
            }
            n++;
        }
        DoublegetTopLStack(s,ret);
        double result = * ret;
        return result;
        
        

    
}
int main()
{
    char n1[1000];
    LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
    int Suffix_expressions[1000];
    initLStack(s);
    while (1)
    {
    printf("����������ʽ(���峤�Ȳ�Ҫ����999���ַ�):");
    gets(n1);
    transformed(n1,s,Suffix_expressions);
    double ret = calculator(s,Suffix_expressions);
    printf("\n���Ϊ%.3f\n",ret);
    }
     
}
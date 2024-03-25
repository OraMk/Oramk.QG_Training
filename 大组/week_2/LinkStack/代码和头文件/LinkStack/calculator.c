#include "LinkStack.h"
Status initLStack(LinkStack *s){
    s->count = 0;
    s->top = NULL;
    s->doubletop = NULL;
}//初始化栈

Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
    if (s->top!=NULL)
    {
        return ERROR;
    }
    else
    return SUCCESS;
    
}
Status isDoubleEmptyLStack(LinkStack *s)//判断栈是否为空
{
    if (s->doubletop != NULL)
    {
        return ERROR;
    }
    else
    return SUCCESS;
    
}
Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
    if (isEmptyLStack(s))
    {
        printf("为空栈无法获取栈顶元素\n");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}
Status DoublegetTopLStack(LinkStack *s,double *e)//得到栈顶元素
{
    if (isEmptyLStack(s))
    {
        printf("为空栈无法获取栈顶元素\n");
        return ERROR;
    }
    *e = s->doubletop->data;
    return SUCCESS;
}
Status clearLStack(LinkStack *s)//清空栈
{
    if (isEmptyLStack(s))
    {
        printf("为空栈无需销毁\n");
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
Status destroyLStack(LinkStack *s)//销毁栈
{
    if(clearLStack(s))
    {
        free(s);
        return SUCCESS;
    }
    return ERROR;
}
Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
    if (isEmptyLStack(s))
    {
       printf("为空栈无数据\n");
        return ERROR;
    }
    
    *length = s->count;
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)//入栈
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
Status DoublepushLStack(LinkStack *s,double data)//入栈
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
Status popLStack(LinkStack *s,ElemType *data)//出栈
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
Status DoublepopLStack(LinkStack *s,double *data)//出栈
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
//判断运算符优先级
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
//四则运算1.将中缀表达式转化为后缀表达式
int* transformed(char Calculations[],LinkStack *s,int* Suffix_expressions)
{
    int num = strlen(Calculations);
    int n = 0;
    ElemType *e = (ElemType *)malloc(sizeof(ElemType));
    ElemType *temp = (ElemType *)malloc(sizeof(ElemType));
    Suffix_expressions[n++]=' ';
    for (int i = 0; i < num; i++)
    {
        if (Calculations[i] >= '0' && Calculations[i] <= '9' ||Calculations[i] == '.')//数字或者小数点就直接载入数组
        {
            Suffix_expressions[n++]=Calculations[i];
        }
        else if (Calculations[i] != ')'&&(Calculations[i] == '('||Calculations[i] == '+' ||Calculations[i] == '-' ||Calculations[i] == '*' ||Calculations[i] == '/' ))//左括号和运算符入栈
        {   
            while(judgment(s,Calculations[i]) != larger && Calculations[i] != '('){//判断是否为直接压栈运算符
            Suffix_expressions[n++]=' ';
            if (getTopLStack(s,e))//将栈顶的数据出栈
            {
                
                if (s->top->data=='(')//如果栈中含有左括号则遇到左括号后停止否则将栈中的全部运算符出栈
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

//通过后缀运算式计算结果
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
    printf("请输入运算式(整体长度不要大于999个字符):");
    gets(n1);
    transformed(n1,s,Suffix_expressions);
    double ret = calculator(s,Suffix_expressions);
    printf("\n结果为%.3f\n",ret);
    }
     
}
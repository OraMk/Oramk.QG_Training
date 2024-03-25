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
void Enum(){
    LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);
    printf("1.入栈\n");
    printf("2.出栈\n");
    printf("3.检测栈长度\n");
    printf("4.得到栈顶元素\n");
    printf("5.判断栈空\n");
    printf("6.清空栈\n");
    printf("7.销毁栈\n");
    printf("8.初始化栈(默认已经初始化)\n");
    printf("0.退出\n");
    int chose = 0;
    int data = 0;
    int length = 0;
    while (1)
    {   
    printf("请输入选项:");
    scanf("%d",&chose);
    switch(chose)
    {
        case 1:
        if (s==NULL)
        {
            printf("栈已销毁,请先初始化");
            break;
        }
        
        printf("请输入要插入的数据:");
        scanf("%d",&data);
        pushLStack(s,data);
        printf("插入成功\n");
        break;
        case 2:
        if (s==NULL)
        {
            printf("栈已销毁,请先初始化\n");
            break;
        }
        if (popLStack(s,&data) == SUCCESS)
        {
            printf("出栈成功数据为:%d\n",data);
        }else printf("栈中无数据\n");
        
        
       
        break;
        case 3:
        if (s==NULL)
        {
            printf("栈已销毁,请先初始化\n");
            break;
        }
        
        if (LStackLength(s,&length) == SUCCESS)
        {
            printf("栈的长度为:%d\n",length);
        }else printf("栈中无数据\n");
        
        break;
        case 4:
        if (s==NULL)
        {
            printf("栈已销毁,请先初始化\n");
            break;
        }
        if (getTopLStack(s,&data) == SUCCESS)
        {
            printf("栈顶元素为:%d\n",data);
        }else printf("栈中无数据\n");
        
        break;
        case 5:
        if (s==NULL)
        {
            printf("栈已销毁,请先初始化\n");
            break;
        }
        if(isEmptyLStack(s)==ERROR)
        {
            printf("栈中有数据\n");
        }
        else{
            printf("栈空\n");
        }
        
        break;
        case 6:
        if (s==NULL)
        {
            printf("栈已销毁,请先初始化\n");
            break;
        }
        clearLStack(s);
        printf("已清空栈\n");
        break;
        case 7:
        destroyLStack(s);
        printf("已销毁栈\n");
        s = NULL;
        break;
        case 8:
        s = (LinkStack *)malloc(sizeof(LinkStack));
        initLStack(s);
        printf("已初始化\n");
        break;
        default:
        printf("输入有误,请重试\n");
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
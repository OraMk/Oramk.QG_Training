#include "LQueue.h"

void InitLQueue(LQueue *Q){//初始化队列
    Q->front = NULL;
    Q->rear = Q->front;
    Q->length = 0;
}	
Status IsEmptyLQueue(const LQueue *Q){//检查队列是否为空
    if(Q->length == 0)return TRUE;
    else return FALSE;
}
Status GetHeadLQueue(LQueue *Q, void *e){//查看头元素
    if (IsEmptyLQueue(Q))
    {
        printf("队列为空无数据\n");
        return FALSE;
    }
    switch (type)
        {
        case 'c':
            *(char*)e = *(char *)Q->front->data;
            break;
        case 'd':
            *(int*)e = *(int *)Q->front->data;
            break;
        case 'f':
            *(double*)e = *(double *)Q->front->data;
            break;
        case 's':
            strcpy((char*)e,(char *)Q->front->data);
            break;
        }
    
    return TRUE;
}
int LengthLQueue(LQueue *Q){//确定队列长度
    if (IsEmptyLQueue)
    {
        printf("队列为空无数据\n");
        return FALSE;
    }
    
    return Q->length;
}
Status EnLQueue(LQueue *Q, void *data){//入队
    Node * newNode = (Node*)malloc(sizeof(Node));//获取内存
    if (newNode == NULL) {//判断是否获取成功
        printf("error\n");
        return FALSE;
    }
    newNode->data = data;//存入数据
    newNode->next = NULL;
    if (IsEmptyLQueue(Q))//判断是否为空队列
    {
        Q->front = newNode; 
    }else Q->rear->next = newNode;

    Q->rear = newNode;
    Q->length++;
    return TRUE;
}
void* DeLQueue(LQueue *Q){//出队操作
    if (IsEmptyLQueue(Q))//判断是否为空队列
    {
        printf("队列为空，无法实现出队操作\n");
        return FALSE;
    }
    Node * temp = Q->front;
    void* data = Q->front->data;
    Q->front = temp->next;
    free(temp);
    Q->length--;
    if (Q->front==NULL)//判断是否为空队列
    {
        Q->rear = Q->front;
    }
    
    return data;

    
}
void ClearLQueue(LQueue *Q){//清空队列
    if (Q->length == 0)
    {
        printf("队列已经为空无需清空\n");
        return;
    }
    
    while (!IsEmptyLQueue(Q))//循环查询队列是否为空
    {
        DeLQueue(Q);//出队操作直到空队列
    }
    return;
}
void DestoryLQueue(LQueue *Q){//销毁队列
    if (Q->length != 0)
    {
        ClearLQueue(Q);

    }
        free(Q);
        Q = NULL;
        return;
    

}
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){//遍历函数操作
    if (IsEmptyLQueue(Q))
    {
        printf("队列为空队列,无法遍历\n");
        return FALSE;
    }
    
    Node *current = Q->front;

    while (current != NULL) {//遍历队列
        foo(current->data);//调用操作函数
        current = current->next;
    }
    printf("\n");
    return TRUE; // 遍历完成，返回成功
}
void LPrint(void *q){//操作函数

    if (strcmp(datatype,"char")==0)
    {
        printf("%c ",*((char*)q));
    }
    else if (strcmp(datatype,"int")==0)
    {
        printf("%d ",*((int*)q));
    }
    else if (strcmp(datatype,"double")==0)
    {
        printf("%.3f ",*((double*)q));
    }
    else if (strcmp(datatype,"char[]")==0)
    {
        printf("%s ",((char*)q));
    }
    
    
}
void Enum()
{
    LQueue * Q = (LQueue *)malloc(sizeof(LQueue));
    InitLQueue(Q);
     while (1)
    {
        printf("请输入数据类型(char,int,double,char[])\n");
        gets(datatype);
        //判断是否输入正确
        if (!(strcmp(datatype,"char")==0||strcmp(datatype,"int")==0||strcmp(datatype,"double")==0||strcmp(datatype,"char[]")==0))
        {
        printf("输入错误，请重试\n");
        continue;
        }
        break;
    }
    if (strcmp(datatype,"char")==0)
    {
        type = 'c';
    }
    else if (strcmp(datatype,"int")==0)
    {
       type = 'd';
    }
    else if (strcmp(datatype,"double")==0)
    {
        type = 'f';
    }
    else if (strcmp(datatype,"char[]")==0)
    {
        type = 's';
    }
    printf("此次队列数据为%s类型\n",datatype);
    printf("1.初始化队列(默认已经初始化)\n");
    printf("2.入队\n");
    printf("3.出队列\n");
    printf("4.检查队列是否为空\n");
    printf("5.查看头元素\n");
    printf("6.获取队列长度\n");
    printf("7.清空队列\n");
    printf("8.销毁队列\n");
    printf("9.遍历函数操作\n");
    printf("0.退出\n");
    int chose = 0;
    void* data;
    int length = 0;
    while (1)
    {
        printf("请输入选项:");
        while (scanf("%d", &chose) != 1) {
        printf("输入无效，请重新输入一个整数：");

        // 清空输入缓冲区
        fflush(stdin);
    }
    switch(chose)
    {
        case 1:if (Q != NULL)
        {
            printf("队列已初始化无需初始化\n");
            break;
        }else
        {
            Q = (LQueue *)malloc(sizeof(LQueue));
            InitLQueue(Q);
            printf("初始化完成\n");
            break;
        }
        case 2:if (Q == NULL)
        {
            printf("队列未初始化请先初始化\n");
            break;
        }
        printf("请输入要入队的数据(%s类型)\n",datatype);
            switch (type)
            {
            case 'c':
            getchar();
            data = (char *)malloc(sizeof(1));
            *(char*)data=getchar();
            
            
            break;
            case 'd':
            data = (int *)malloc(sizeof(4));
            scanf("%d",(int*)data);
            break;
            case 'f':
            data = (double *)malloc(sizeof(double));
            scanf("%f",(double*)data);
            break;
            case 's':
            data = (char *)malloc(sizeof(100));
            scanf("%s",(char*)data);
            break;
            }
        EnLQueue(Q,data);
        break;
        case 3:
            if (Q == NULL)
            {
                printf("队列未初始化请先初始化\n");
                break;
            }
            if (IsEmptyLQueue(Q))
            {
            printf("队列为空无数据无法执行出队操作\n");
            break;
            }
            data = DeLQueue(Q);
            switch (type)
            {
            case 'c':
                printf("出队操作成功，数据为%c\n",*(char*)data);
                break;
            case 'd':
                printf("出队操作成功，数据为%d\n",*(int*)data);
                break;
            case 'f':
                printf("出队操作成功，数据为%.3f\n",*(double*)data);
                break;
            case 's':
                printf("出队操作成功，数据为%s\n",*(double*)data);
                break;
            }
            break;
        case 4:
            if (Q == NULL)
            {
                printf("队列未初始化请先初始化\n");
                break;
            }
            if (IsEmptyLQueue(Q))
            {
                printf("队列为空\n");
            }else printf("队列未空\n");
            break;
        case 5:
            if (Q == NULL)
            {
                printf("队列未初始化请先初始化\n");
                break;
            }
            if (IsEmptyLQueue(Q))
            {
                printf("队列为空\n");
                break;
            }
            GetHeadLQueue(Q,data);
            switch (type)
            {
            case 'c':
                printf("数据为%c\n",*(char*)data);
                break;
            case 'd':
                printf("数据为%d\n",*(int*)data);
                break;
            case 'f':
                printf("数据为%.3f\n",*(double*)data);
                break;
            case 's':
                printf("数据为%s\n",*(double*)data);
                break;
            }
        break;
        case 6:
        if (Q == NULL)
        {
            printf("队列未初始化请先初始化\n");
            break;
        }
         if (IsEmptyLQueue(Q))
        {
            printf("队列为空无数据\n");
            break;
        }
        length = Q->length;
        printf("队列长度为%d\n",length);
        break;
        case 7:
        if (Q == NULL)
        {
            printf("队列未初始化请先初始化\n");
            break;
        }
        if (IsEmptyLQueue(Q))
        {
            printf("队列为空\n");
            break;
        }
        ClearLQueue(Q);
        printf("已清空\n");
        break;
        case 8:
        if (Q == NULL)
        {
            printf("队列未初始化请先初始化\n");
            break;
        }
        DestoryLQueue(Q);
        printf("已经销毁\n");
        Q = NULL;
        break;
        case 9:
        if (Q == NULL)
        {
            printf("队列未初始化请先初始化\n");
            break;
        }
        TraverseLQueue(Q,LPrint);
        printf("遍历完成\n");
        break;
        case 0:
        exit(0);
        break;
        default:
        printf("输入错误，请重试\n");
        break;
    }
    }
    
}

int main()
{
    Enum();
}
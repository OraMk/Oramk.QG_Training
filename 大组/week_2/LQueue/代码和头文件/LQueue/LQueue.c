#include "LQueue.h"

void InitLQueue(LQueue *Q){//��ʼ������
    Q->front = NULL;
    Q->rear = Q->front;
    Q->length = 0;
}	
Status IsEmptyLQueue(const LQueue *Q){//�������Ƿ�Ϊ��
    if(Q->length == 0)return TRUE;
    else return FALSE;
}
Status GetHeadLQueue(LQueue *Q, void *e){//�鿴ͷԪ��
    if (IsEmptyLQueue(Q))
    {
        printf("����Ϊ��������\n");
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
int LengthLQueue(LQueue *Q){//ȷ�����г���
    if (IsEmptyLQueue)
    {
        printf("����Ϊ��������\n");
        return FALSE;
    }
    
    return Q->length;
}
Status EnLQueue(LQueue *Q, void *data){//���
    Node * newNode = (Node*)malloc(sizeof(Node));//��ȡ�ڴ�
    if (newNode == NULL) {//�ж��Ƿ��ȡ�ɹ�
        printf("error\n");
        return FALSE;
    }
    newNode->data = data;//��������
    newNode->next = NULL;
    if (IsEmptyLQueue(Q))//�ж��Ƿ�Ϊ�ն���
    {
        Q->front = newNode; 
    }else Q->rear->next = newNode;

    Q->rear = newNode;
    Q->length++;
    return TRUE;
}
void* DeLQueue(LQueue *Q){//���Ӳ���
    if (IsEmptyLQueue(Q))//�ж��Ƿ�Ϊ�ն���
    {
        printf("����Ϊ�գ��޷�ʵ�ֳ��Ӳ���\n");
        return FALSE;
    }
    Node * temp = Q->front;
    void* data = Q->front->data;
    Q->front = temp->next;
    free(temp);
    Q->length--;
    if (Q->front==NULL)//�ж��Ƿ�Ϊ�ն���
    {
        Q->rear = Q->front;
    }
    
    return data;

    
}
void ClearLQueue(LQueue *Q){//��ն���
    if (Q->length == 0)
    {
        printf("�����Ѿ�Ϊ���������\n");
        return;
    }
    
    while (!IsEmptyLQueue(Q))//ѭ����ѯ�����Ƿ�Ϊ��
    {
        DeLQueue(Q);//���Ӳ���ֱ���ն���
    }
    return;
}
void DestoryLQueue(LQueue *Q){//���ٶ���
    if (Q->length != 0)
    {
        ClearLQueue(Q);

    }
        free(Q);
        Q = NULL;
        return;
    

}
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){//������������
    if (IsEmptyLQueue(Q))
    {
        printf("����Ϊ�ն���,�޷�����\n");
        return FALSE;
    }
    
    Node *current = Q->front;

    while (current != NULL) {//��������
        foo(current->data);//���ò�������
        current = current->next;
    }
    printf("\n");
    return TRUE; // ������ɣ����سɹ�
}
void LPrint(void *q){//��������

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
        printf("��������������(char,int,double,char[])\n");
        gets(datatype);
        //�ж��Ƿ�������ȷ
        if (!(strcmp(datatype,"char")==0||strcmp(datatype,"int")==0||strcmp(datatype,"double")==0||strcmp(datatype,"char[]")==0))
        {
        printf("�������������\n");
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
    printf("�˴ζ�������Ϊ%s����\n",datatype);
    printf("1.��ʼ������(Ĭ���Ѿ���ʼ��)\n");
    printf("2.���\n");
    printf("3.������\n");
    printf("4.�������Ƿ�Ϊ��\n");
    printf("5.�鿴ͷԪ��\n");
    printf("6.��ȡ���г���\n");
    printf("7.��ն���\n");
    printf("8.���ٶ���\n");
    printf("9.������������\n");
    printf("0.�˳�\n");
    int chose = 0;
    void* data;
    int length = 0;
    while (1)
    {
        printf("������ѡ��:");
        while (scanf("%d", &chose) != 1) {
        printf("������Ч������������һ��������");

        // ������뻺����
        fflush(stdin);
    }
    switch(chose)
    {
        case 1:if (Q != NULL)
        {
            printf("�����ѳ�ʼ�������ʼ��\n");
            break;
        }else
        {
            Q = (LQueue *)malloc(sizeof(LQueue));
            InitLQueue(Q);
            printf("��ʼ�����\n");
            break;
        }
        case 2:if (Q == NULL)
        {
            printf("����δ��ʼ�����ȳ�ʼ��\n");
            break;
        }
        printf("������Ҫ��ӵ�����(%s����)\n",datatype);
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
                printf("����δ��ʼ�����ȳ�ʼ��\n");
                break;
            }
            if (IsEmptyLQueue(Q))
            {
            printf("����Ϊ���������޷�ִ�г��Ӳ���\n");
            break;
            }
            data = DeLQueue(Q);
            switch (type)
            {
            case 'c':
                printf("���Ӳ����ɹ�������Ϊ%c\n",*(char*)data);
                break;
            case 'd':
                printf("���Ӳ����ɹ�������Ϊ%d\n",*(int*)data);
                break;
            case 'f':
                printf("���Ӳ����ɹ�������Ϊ%.3f\n",*(double*)data);
                break;
            case 's':
                printf("���Ӳ����ɹ�������Ϊ%s\n",*(double*)data);
                break;
            }
            break;
        case 4:
            if (Q == NULL)
            {
                printf("����δ��ʼ�����ȳ�ʼ��\n");
                break;
            }
            if (IsEmptyLQueue(Q))
            {
                printf("����Ϊ��\n");
            }else printf("����δ��\n");
            break;
        case 5:
            if (Q == NULL)
            {
                printf("����δ��ʼ�����ȳ�ʼ��\n");
                break;
            }
            if (IsEmptyLQueue(Q))
            {
                printf("����Ϊ��\n");
                break;
            }
            GetHeadLQueue(Q,data);
            switch (type)
            {
            case 'c':
                printf("����Ϊ%c\n",*(char*)data);
                break;
            case 'd':
                printf("����Ϊ%d\n",*(int*)data);
                break;
            case 'f':
                printf("����Ϊ%.3f\n",*(double*)data);
                break;
            case 's':
                printf("����Ϊ%s\n",*(double*)data);
                break;
            }
        break;
        case 6:
        if (Q == NULL)
        {
            printf("����δ��ʼ�����ȳ�ʼ��\n");
            break;
        }
         if (IsEmptyLQueue(Q))
        {
            printf("����Ϊ��������\n");
            break;
        }
        length = Q->length;
        printf("���г���Ϊ%d\n",length);
        break;
        case 7:
        if (Q == NULL)
        {
            printf("����δ��ʼ�����ȳ�ʼ��\n");
            break;
        }
        if (IsEmptyLQueue(Q))
        {
            printf("����Ϊ��\n");
            break;
        }
        ClearLQueue(Q);
        printf("�����\n");
        break;
        case 8:
        if (Q == NULL)
        {
            printf("����δ��ʼ�����ȳ�ʼ��\n");
            break;
        }
        DestoryLQueue(Q);
        printf("�Ѿ�����\n");
        Q = NULL;
        break;
        case 9:
        if (Q == NULL)
        {
            printf("����δ��ʼ�����ȳ�ʼ��\n");
            break;
        }
        TraverseLQueue(Q,LPrint);
        printf("�������\n");
        break;
        case 0:
        exit(0);
        break;
        default:
        printf("�������������\n");
        break;
    }
    }
    
}

int main()
{
    Enum();
}
#include "binary_sort_tree.h"

//ջ
Status initLStack(LinkStack *s){//��ʼ��ջ
    s->count = 0;
    s->top = NULL;

}

Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if (s->top != NULL && s->count != 0 )
    {
        return failed;
    }
    else
    return succeed;
    
}
Status pushLStack(LinkStack *s,NodePtr root)//��ջ
{
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    p->data = root;
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
    return succeed;
    
}

StackNode* popLStack(LinkStack *s)//��ջ
{
    if (!isEmptyLStack(s))
    {
        StackNode* p = s->top;
        s->top = s->top->next;
        s->count--;
        return p;
        
    }
    
        return failed;
}
StackNode* getTopLStack(LinkStack *s){//��ȡջ��Ԫ�أ�����ջ
    if (!isEmptyLStack(s))
    {
        
        StackNode* p = s->top;
        return p;
        
    }
    
        return failed;
}


//����
void InitLQueue(LQueue *Q){//��ʼ������
    Q->front = NULL;
    Q->rear = Q->front;
    Q->length = 0;
}

Status IsEmptyLQueue(const LQueue *Q){//�ж϶����Ƿ�Ϊ��
    if(Q->length == 0)return succeed;
    else return failed;
}

//��Ӳ���
Status EnLQueue(LQueue *Q, NodePtr data){
    QNode * newNode = (QNode*)malloc(sizeof(QNode));//��ȡ�ڴ�
    if (newNode == NULL) {//�ж��Ƿ��ȡ�ɹ�
        printf("error\n");
        return failed;
    }
    newNode->data = data;//��������
    newNode->next = NULL;
    if (IsEmptyLQueue(Q))//�ж��Ƿ�Ϊ�ն���
    {
        Q->front = newNode; 
    }else Q->rear->next = newNode;

    Q->rear = newNode;
    Q->length++;
    return succeed;
}
QNode* DeLQueue(LQueue *Q){//���Ӳ���
    if (IsEmptyLQueue(Q))//�ж��Ƿ�Ϊ�ն���
    {
        return failed;
    }
    QNode * temp = Q->front;
    // NodePtr data = Q->front->data;
    Q->front = temp->next;
    // free(temp);
    Q->length--;
    if (Q->front==NULL)//�ж��Ƿ�Ϊ�ն���
    {
        Q->rear = Q->front;
    }
    
    return temp;
}

//��
Status BST_init(BinarySortTreePtr binarySortTree){//��ʼ����

    binarySortTree->root = NULL;
    return succeed;
}
//����Ԫ��
Status BST_insert(BinarySortTreePtr binarySortTree , ElemType data){
    NodePtr p = (NodePtr)malloc(sizeof(Node));
    p->left = NULL;
    p->right = NULL;
    p->value = data;
    NodePtr temp = binarySortTree->root;
    NodePtr parent = NULL;
    //�жϸ����Ƿ��н��
    if (binarySortTree->root == NULL)
    {
        binarySortTree->root = p;
        return succeed;
    }

    while (temp != NULL) {
        parent = temp;
        if (data < temp->value) {//���ݱȸý�������С ������ڵ�
            temp = temp->left;
        } else if (data > temp->value) {//���ݱȸý������ݴ� �����ҽڵ�
            temp = temp->right;
        } else {
            free(p); // ��������Ѵ��������У����ͷ��½ڵ㲢����
            return failed;
        }
    }
    if (data < parent->value)
    {
        parent->left = p;
    }else{
        parent->right = p;
    }
    return succeed;
}
//ɾ��Ԫ��
Status BST_delete(BinarySortTreePtr binarySortTree , ElemType data){
    NodePtr temp = binarySortTree->root;
    NodePtr parent = NULL;//����
    NodePtr min = NULL ; //�ȸ��ڵ�����С���
    NodePtr minParent = NULL ; //�ȸ��ڵ�����С���ĸ��ڵ�
    parent = temp;
    while (temp != NULL)
    {      
        
        if (temp->value > data)//�����ֵ��
        {
            parent = temp;
            temp = temp->left;
        }
        else if (temp->value < data)//�����ֵС
        {
            parent = temp;
            temp = temp->right;
        }
        else{//�ҵ���
            if (temp->left == NULL && temp->right == NULL)//ɾ���ĺ���ΪҶ�ڵ�
            {
                if (temp == binarySortTree->root)//�ж��Ƿ�Ϊ�����
                {
                    free(temp);
                    binarySortTree->root = NULL;
                    return succeed;
                }
                
                if (temp == parent->left )
                {
                    parent->left = NULL;
                }else{
                    parent->right= NULL;
                }
                free(temp);//��������ڴ�
                return succeed;
            }else if (temp->left != NULL && temp->right != NULL)//ɾ�����������ӵĽ��
            {
                minParent = temp;
                min = temp->right;
                int right = 0;
                while (min->left)//���Ҵ���Ҫɾ��������С���
                {
                    minParent = min;
                    min = min->left;
                    right = 1;
                }
                temp->value = min->value;//����ֵ
                if (right == 0)
                {
                minParent->right = min->right;//�����ڵ���ҽڵ�������С�����ҽ��(ΪnullҲ����)                  
                }
                else{
                minParent->left = min->right;//�����ڵ����ڵ�������С�����ҽ��(ΪnullҲ����) 
                }
                
                free(min);
                return succeed;
            }
            else{//ɾ����ֻ��һ���ӽ��
                if (temp == binarySortTree->root)//�ж��Ƿ�Ϊ�����
                {
                    if (temp->left)
                    {
                        binarySortTree->root = temp->left;
                        free(temp);
                    }else{
                        binarySortTree->root = temp->right;
                        free(temp);
                    }
                    return succeed;
                    
                }else
                {
                    if (temp == parent->left )//�ж������ĸ����
                    {
                    if (temp->left != NULL)//���Ҫɾ���Ľ����ڵ㲻Ϊ��
                    {
                        parent->left = temp->left;//���ӽڵ����ڵ����ӵ����ڵ����ڵ���
                    }
                    else{
                        parent->left = temp ->right;//���ӽڵ���ҽڵ����ӵ����ڵ����ڵ���
                    }
                    
                    }else{
                    if (temp->left != NULL)
                    {
                        parent->right = temp->left;//���ӽڵ����ڵ����ӵ����ڵ���ҽڵ���
                    }
                    else{
                        parent->right = temp ->right;//���ӽڵ���ҽڵ����ӵ����ڵ���ҽڵ���
                    }
                    }
                    free(temp);
                    return succeed;
                }
                
                
            }
                
        }

    }
    //û�ҵ�
    return failed;

    
}
//����Ԫ��
Status BST_search(BinarySortTreePtr binarySortTree, ElemType data){
    NodePtr temp = binarySortTree->root;
    while (temp != NULL){
        if (temp->value > data)//�����ֵ��
        {
            temp = temp->left;
        }
        else if (temp->value < data)//�����ֵС
        {
            temp = temp->right;
        }
        else{
            return succeed;
        }
    }
    return failed;
}
//��ʾ����
void visit(NodePtr p)
{
    printf("%d ",p->value);
}
//ǰ������ǵݹ�
Status BST_preorderI(BinarySortTreePtr binarySortTree, void (*visit)(NodePtr) ){
    if (binarySortTree->root == NULL || binarySortTree == NULL)
    {
        printf("������\n");
        return succeed;
    }
    
    LinkStack * s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);//��ʼ��ջ
    NodePtr current = binarySortTree->root;

    pushLStack(s,current);
    while (!isEmptyLStack(s))//�ж�ջ�Ƿ�Ϊ��
    {
        current = popLStack(s)->data;//��ջ��ȡ��ջ�Ľ��Ԫ��
        visit(current);

        if (current->right != NULL)//�ж��������Ƿ�Ϊ�գ�ѹջ
        {
            pushLStack(s, current->right);
        }
        
        if (current->left != NULL)//�ж��������Ƿ�Ϊ�գ�ѹջ
        {
            pushLStack(s, current->left);
        }

    }
    free(s);
    return succeed;
    


}
//ǰ������ݹ�
Status BST_preorderR(NodePtr root, void (*visit)(NodePtr)){
    if (root == NULL)
    {
        return succeed;
    }
    visit(root);
    BST_preorderR(root->left,visit); 
    BST_preorderR(root->right,visit); 

    
}
//��������ǵݹ�
Status BST_inorderI(BinarySortTreePtr binarySortTree, void (*visit)(NodePtr)){

    if (binarySortTree->root == NULL || binarySortTree == NULL)
        {
        printf("������\n");
        return succeed;
        }
    
    LinkStack * s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);//��ʼ��ջ
    NodePtr current = binarySortTree->root;

    while (!isEmptyLStack(s) || current != NULL)
    {
        while (current != NULL)//��������ȫѹջ
        {
            pushLStack(s,current);
            current = current->left;
        }

        current = popLStack(s)->data;//����ջ��Ԫ��
        visit(current);
        current = current->right;//����Ҷ���ĸ��ڵ��������
        
    }
    free(s);
    return succeed;
    

}
//��������ݹ�
Status BST_inorderR(NodePtr root, void (*visit)(NodePtr)){
    if (root == NULL)
    {
        return succeed;
        
    }
    BST_inorderR(root->left,visit); 
    visit(root);
    BST_inorderR(root->right,visit); 
}

//��������ǵݹ�
Status BST_postorderI(BinarySortTreePtr binarySortTree, void (*visit)(NodePtr)){
    if (binarySortTree->root == NULL || binarySortTree == NULL)
        {
        return succeed;
        }
    
    LinkStack * s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);//��ʼ��ջ
    NodePtr current = binarySortTree->root;
    NodePtr lastpop = NULL;
    pushLStack(s,current);
    while (current != NULL && !isEmptyLStack(s))
    {
        current = getTopLStack(s)->data;//�鿴��ǰ�Ľ��
        if ((current->left == NULL && current->right == NULL) || //ΪҶ�ӽڵ�
            (current->left != NULL && current->right == NULL && lastpop == current->left ) ||//û���ҽڵ�����
            (current->right != NULL && lastpop == current->right) )//���ҽڵ�����
        {
            current = popLStack(s)->data;//��ջ�����ý��
            visit(current);
            lastpop = current;//������һ�ε�ջ������
        }else {//�����ϵ�ջҪ������������ѹջ
            if (current->right != NULL)
        {
            pushLStack(s,current->right);
        }
        if (current->left != NULL)
        {
            pushLStack(s,current->left);
        }
        
        }
        
    }
    free(s);
    return succeed;
}
//��������ݹ�
Status BST_postorderR(NodePtr root, void (*visit)(NodePtr)){
    if (root == NULL)
    {
        return succeed;
    }
    BST_postorderR(root->left,visit); 
    BST_postorderR(root->right,visit);
    visit(root);
}

//��α���
Status BST_levelOrder(BinarySortTreePtr binarySortTree, void (*visit)(NodePtr)){
    if (binarySortTree->root == NULL || binarySortTree == NULL)
        {
        printf("������\n");
        return succeed;
        }
        LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
        InitLQueue(Q);
        NodePtr current = binarySortTree->root;
        EnLQueue(Q,current);
        while ( current != NULL && !IsEmptyLQueue(Q) )
        {
            current = DeLQueue(Q)->data;
            visit(current);
            if (current->left != NULL)
            {
                EnLQueue(Q,current->left);
            }
            if (current->right != NULL)
            {
                EnLQueue(Q,current->right);
            }
            
        }
        free(Q);
        
}

void Enum(){
    printf("=====================\n");
    printf("1.��ʼ����\n");
    printf("2.��������\n");
    printf("3.ɾ������\n");
    printf("4.��������\n");
    printf("5.ǰ�����(�ǵݹ�)\n");
    printf("6.ǰ�����(�ݹ�)\n");
    printf("7.�������(�ǵݹ�)\n");
    printf("8.�������(�ݹ�)\n");
    printf("9.�������(�ǵݹ�)\n");
    printf("10.�������(�ݹ�)\n");
    printf("11.��α���\n");
    printf("0.�˳�\n");
    printf("=====================\n");
    int choose = 100;
    int data = 0;
    int Succed = 0;
    int n = 0;
    BinarySortTreePtr binarySortTree = NULL;
    
    while (1)
    {
        printf("������:");
        n = scanf("%d",&choose);
        fflush(stdin);//��ջ�����������
        while (n != 1)
        {
            printf("����������: ");
            n = scanf("%d",&choose);
        }
        n = 0 ;
        
        switch (choose)
        {
        case 1:
            if (binarySortTree != NULL)
            {
                printf("�������ѳ�ʼ���������ٴγ�ʼ��\n");
            }
            else{
                binarySortTree = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
                if (binarySortTree == NULL)
                {
                    printf("��ȡ�ڴ�ʧ��\n");
                }
                else{
                    Succed = BST_init(binarySortTree);
                    if (Succed == succeed)
                    {
                        printf("��ʼ���ɹ�\n");
                    }
                    else{
                        printf("��ʼ��ʧ��\n");
                    }
                }
   
            }

            break;
        case 2:
            if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                printf("������Ҫ���������:");
                scanf("%d",&data);
                Succed = BST_insert(binarySortTree,data);
                if (Succed == succeed)
                {
                    printf("����ɹ�\n");
                }else
                {
                    printf("����ʧ��,�����Ѵ��ڸ�����\n");
                }      
            }
            break;
        case 3:
             if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                printf("������Ҫɾ��������:");
                scanf("%d",&data);
                Succed = BST_delete(binarySortTree,data);
                if (Succed == succeed)
                {
                    printf("ɾ���ɹ�\n");
                }else
                {
                    printf("ɾ��ʧ��,�ýڵ㲻����\n");
                }      
            }
            break;
            
        case 4:
            if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                printf("������Ҫ���ҵ�����:");
                scanf("%d",&data);
                Succed = BST_search(binarySortTree,data);
                if (Succed == succeed)
                {
                    printf("���ҳɹ�\n");
                }else
                {
                    printf("�ýڵ㲻����\n");
                }      
            }
            break;
            
        case 5:
            if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                BST_preorderI(binarySortTree,visit);
                printf("\n");
            }
            break;
            
        case 6:
            if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                if (binarySortTree->root)
                {
                    BST_preorderR(binarySortTree->root,visit);
                    printf("\n");
                }
                else{
                printf("����������\n");
                }
               
            }
            break;
            
        case 7:
            if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                BST_inorderI(binarySortTree,visit);
                printf("\n");
            }
            break;
            
        case 8:
             if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                if (binarySortTree->root)
                {
                    BST_inorderR(binarySortTree->root,visit);
                    printf("\n");
                }
                else{
                printf("����������\n");
                }
               
            }
            break;
            
        case 9:
            if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                BST_postorderI(binarySortTree,visit);
                printf("\n");
            }
            break;
            
        case 10:
            if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{
                if (binarySortTree->root)
                {
                     BST_postorderR(binarySortTree->root,visit);
                    printf("\n");
                }
                else{
                printf("����������\n");
                }
               
            }
            break;
            
        case 11:
        if (binarySortTree == NULL){
                printf("��δ��ʼ�������ȳ�ʼ��\n");
            }else{

                BST_levelOrder(binarySortTree,visit);
                printf("\n");

            }
            break;
            
        case 0:
            exit(0);
            break;
            
            
        default:printf("����Ƿ�������������\n");
            break;
        }

    }
    

}
int main()
{
    Enum();//�˵�
}
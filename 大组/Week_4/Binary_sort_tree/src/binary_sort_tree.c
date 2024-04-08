#include "binary_sort_tree.h"

//栈
Status initLStack(LinkStack *s){//初始化栈
    s->count = 0;
    s->top = NULL;

}

Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
    if (s->top != NULL && s->count != 0 )
    {
        return failed;
    }
    else
    return succeed;
    
}
Status pushLStack(LinkStack *s,NodePtr root)//入栈
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

StackNode* popLStack(LinkStack *s)//出栈
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
StackNode* getTopLStack(LinkStack *s){//获取栈顶元素，不出栈
    if (!isEmptyLStack(s))
    {
        
        StackNode* p = s->top;
        return p;
        
    }
    
        return failed;
}


//队列
void InitLQueue(LQueue *Q){//初始化队列
    Q->front = NULL;
    Q->rear = Q->front;
    Q->length = 0;
}

Status IsEmptyLQueue(const LQueue *Q){//判断队列是否为空
    if(Q->length == 0)return succeed;
    else return failed;
}

//入队操作
Status EnLQueue(LQueue *Q, NodePtr data){
    QNode * newNode = (QNode*)malloc(sizeof(QNode));//获取内存
    if (newNode == NULL) {//判断是否获取成功
        printf("error\n");
        return failed;
    }
    newNode->data = data;//存入数据
    newNode->next = NULL;
    if (IsEmptyLQueue(Q))//判断是否为空队列
    {
        Q->front = newNode; 
    }else Q->rear->next = newNode;

    Q->rear = newNode;
    Q->length++;
    return succeed;
}
QNode* DeLQueue(LQueue *Q){//出队操作
    if (IsEmptyLQueue(Q))//判断是否为空队列
    {
        return failed;
    }
    QNode * temp = Q->front;
    // NodePtr data = Q->front->data;
    Q->front = temp->next;
    // free(temp);
    Q->length--;
    if (Q->front==NULL)//判断是否为空队列
    {
        Q->rear = Q->front;
    }
    
    return temp;
}

//树
Status BST_init(BinarySortTreePtr binarySortTree){//初始化树

    binarySortTree->root = NULL;
    return succeed;
}
//插入元素
Status BST_insert(BinarySortTreePtr binarySortTree , ElemType data){
    NodePtr p = (NodePtr)malloc(sizeof(Node));
    p->left = NULL;
    p->right = NULL;
    p->value = data;
    NodePtr temp = binarySortTree->root;
    NodePtr parent = NULL;
    //判断根部是否有结点
    if (binarySortTree->root == NULL)
    {
        binarySortTree->root = p;
        return succeed;
    }

    while (temp != NULL) {
        parent = temp;
        if (data < temp->value) {//数据比该结点的数据小 查找左节点
            temp = temp->left;
        } else if (data > temp->value) {//数据比该结点的数据大 查找右节点
            temp = temp->right;
        } else {
            free(p); // 如果数据已存在于树中，则释放新节点并返回
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
//删除元素
Status BST_delete(BinarySortTreePtr binarySortTree , ElemType data){
    NodePtr temp = binarySortTree->root;
    NodePtr parent = NULL;//父类
    NodePtr min = NULL ; //比根节点大的最小结点
    NodePtr minParent = NULL ; //比根节点大的最小结点的父节点
    parent = temp;
    while (temp != NULL)
    {      
        
        if (temp->value > data)//比求的值大
        {
            parent = temp;
            temp = temp->left;
        }
        else if (temp->value < data)//比求的值小
        {
            parent = temp;
            temp = temp->right;
        }
        else{//找到了
            if (temp->left == NULL && temp->right == NULL)//删除的孩子为叶节点
            {
                if (temp == binarySortTree->root)//判断是否为根结点
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
                free(temp);//清理结点的内存
                return succeed;
            }else if (temp->left != NULL && temp->right != NULL)//删除有两个孩子的结点
            {
                minParent = temp;
                min = temp->right;
                int right = 0;
                while (min->left)//查找大于要删除结点的最小结点
                {
                    minParent = min;
                    min = min->left;
                    right = 1;
                }
                temp->value = min->value;//交换值
                if (right == 0)
                {
                minParent->right = min->right;//将父节点的右节点连接最小结点的右结点(为null也可以)                  
                }
                else{
                minParent->left = min->right;//将父节点的左节点连接最小结点的右结点(为null也可以) 
                }
                
                free(min);
                return succeed;
            }
            else{//删除的只有一个子结点
                if (temp == binarySortTree->root)//判断是否为根结点
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
                    if (temp == parent->left )//判断是在哪个结点
                    {
                    if (temp->left != NULL)//如果要删除的结点左节点不为空
                    {
                        parent->left = temp->left;//将子节点的左节点连接到父节点的左节点上
                    }
                    else{
                        parent->left = temp ->right;//将子节点的右节点连接到父节点的左节点上
                    }
                    
                    }else{
                    if (temp->left != NULL)
                    {
                        parent->right = temp->left;//将子节点的左节点连接到父节点的右节点上
                    }
                    else{
                        parent->right = temp ->right;//将子节点的右节点连接到父节点的右节点上
                    }
                    }
                    free(temp);
                    return succeed;
                }
                
                
            }
                
        }

    }
    //没找到
    return failed;

    
}
//查找元素
Status BST_search(BinarySortTreePtr binarySortTree, ElemType data){
    NodePtr temp = binarySortTree->root;
    while (temp != NULL){
        if (temp->value > data)//比求的值大
        {
            temp = temp->left;
        }
        else if (temp->value < data)//比求的值小
        {
            temp = temp->right;
        }
        else{
            return succeed;
        }
    }
    return failed;
}
//显示函数
void visit(NodePtr p)
{
    printf("%d ",p->value);
}
//前序遍历非递归
Status BST_preorderI(BinarySortTreePtr binarySortTree, void (*visit)(NodePtr) ){
    if (binarySortTree->root == NULL || binarySortTree == NULL)
    {
        printf("无数据\n");
        return succeed;
    }
    
    LinkStack * s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);//初始化栈
    NodePtr current = binarySortTree->root;

    pushLStack(s,current);
    while (!isEmptyLStack(s))//判断栈是否为空
    {
        current = popLStack(s)->data;//弹栈获取弹栈的结点元素
        visit(current);

        if (current->right != NULL)//判断右子树是否为空，压栈
        {
            pushLStack(s, current->right);
        }
        
        if (current->left != NULL)//判断左子树是否为空，压栈
        {
            pushLStack(s, current->left);
        }

    }
    free(s);
    return succeed;
    


}
//前序遍历递归
Status BST_preorderR(NodePtr root, void (*visit)(NodePtr)){
    if (root == NULL)
    {
        return succeed;
    }
    visit(root);
    BST_preorderR(root->left,visit); 
    BST_preorderR(root->right,visit); 

    
}
//中序遍历非递归
Status BST_inorderI(BinarySortTreePtr binarySortTree, void (*visit)(NodePtr)){

    if (binarySortTree->root == NULL || binarySortTree == NULL)
        {
        printf("无数据\n");
        return succeed;
        }
    
    LinkStack * s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);//初始化栈
    NodePtr current = binarySortTree->root;

    while (!isEmptyLStack(s) || current != NULL)
    {
        while (current != NULL)//将左子树全压栈
        {
            pushLStack(s,current);
            current = current->left;
        }

        current = popLStack(s)->data;//弹出栈顶元素
        visit(current);
        current = current->right;//查找叶结点的父节点的右子树
        
    }
    free(s);
    return succeed;
    

}
//中序遍历递归
Status BST_inorderR(NodePtr root, void (*visit)(NodePtr)){
    if (root == NULL)
    {
        return succeed;
        
    }
    BST_inorderR(root->left,visit); 
    visit(root);
    BST_inorderR(root->right,visit); 
}

//后序遍历非递归
Status BST_postorderI(BinarySortTreePtr binarySortTree, void (*visit)(NodePtr)){
    if (binarySortTree->root == NULL || binarySortTree == NULL)
        {
        return succeed;
        }
    
    LinkStack * s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);//初始化栈
    NodePtr current = binarySortTree->root;
    NodePtr lastpop = NULL;
    pushLStack(s,current);
    while (current != NULL && !isEmptyLStack(s))
    {
        current = getTopLStack(s)->data;//查看当前的结点
        if ((current->left == NULL && current->right == NULL) || //为叶子节点
            (current->left != NULL && current->right == NULL && lastpop == current->left ) ||//没有右节点的情况
            (current->right != NULL && lastpop == current->right) )//有右节点的情况
        {
            current = popLStack(s)->data;//弹栈弹出该结点
            visit(current);
            lastpop = current;//更新上一次弹栈的数据
        }else {//不符合弹栈要求则将左右子树压栈
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
//后序遍历递归
Status BST_postorderR(NodePtr root, void (*visit)(NodePtr)){
    if (root == NULL)
    {
        return succeed;
    }
    BST_postorderR(root->left,visit); 
    BST_postorderR(root->right,visit);
    visit(root);
}

//层次遍历
Status BST_levelOrder(BinarySortTreePtr binarySortTree, void (*visit)(NodePtr)){
    if (binarySortTree->root == NULL || binarySortTree == NULL)
        {
        printf("无数据\n");
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
    printf("1.初始化树\n");
    printf("2.插入数据\n");
    printf("3.删除数据\n");
    printf("4.查找数据\n");
    printf("5.前序遍历(非递归)\n");
    printf("6.前序遍历(递归)\n");
    printf("7.中序遍历(非递归)\n");
    printf("8.中序遍历(递归)\n");
    printf("9.后序遍历(非递归)\n");
    printf("10.后序遍历(递归)\n");
    printf("11.层次遍历\n");
    printf("0.退出\n");
    printf("=====================\n");
    int choose = 100;
    int data = 0;
    int Succed = 0;
    int n = 0;
    BinarySortTreePtr binarySortTree = NULL;
    
    while (1)
    {
        printf("请输入:");
        n = scanf("%d",&choose);
        fflush(stdin);//清空缓存区的数据
        while (n != 1)
        {
            printf("请输入数字: ");
            n = scanf("%d",&choose);
        }
        n = 0 ;
        
        switch (choose)
        {
        case 1:
            if (binarySortTree != NULL)
            {
                printf("二叉树已初始化，无需再次初始化\n");
            }
            else{
                binarySortTree = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
                if (binarySortTree == NULL)
                {
                    printf("获取内存失败\n");
                }
                else{
                    Succed = BST_init(binarySortTree);
                    if (Succed == succeed)
                    {
                        printf("初始化成功\n");
                    }
                    else{
                        printf("初始化失败\n");
                    }
                }
   
            }

            break;
        case 2:
            if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                printf("请输入要插入的数据:");
                scanf("%d",&data);
                Succed = BST_insert(binarySortTree,data);
                if (Succed == succeed)
                {
                    printf("插入成功\n");
                }else
                {
                    printf("插入失败,树中已存在该数据\n");
                }      
            }
            break;
        case 3:
             if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                printf("请输入要删除的数据:");
                scanf("%d",&data);
                Succed = BST_delete(binarySortTree,data);
                if (Succed == succeed)
                {
                    printf("删除成功\n");
                }else
                {
                    printf("删除失败,该节点不存在\n");
                }      
            }
            break;
            
        case 4:
            if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                printf("请输入要查找的数据:");
                scanf("%d",&data);
                Succed = BST_search(binarySortTree,data);
                if (Succed == succeed)
                {
                    printf("查找成功\n");
                }else
                {
                    printf("该节点不存在\n");
                }      
            }
            break;
            
        case 5:
            if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                BST_preorderI(binarySortTree,visit);
                printf("\n");
            }
            break;
            
        case 6:
            if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                if (binarySortTree->root)
                {
                    BST_preorderR(binarySortTree->root,visit);
                    printf("\n");
                }
                else{
                printf("树中无数据\n");
                }
               
            }
            break;
            
        case 7:
            if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                BST_inorderI(binarySortTree,visit);
                printf("\n");
            }
            break;
            
        case 8:
             if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                if (binarySortTree->root)
                {
                    BST_inorderR(binarySortTree->root,visit);
                    printf("\n");
                }
                else{
                printf("树中无数据\n");
                }
               
            }
            break;
            
        case 9:
            if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                BST_postorderI(binarySortTree,visit);
                printf("\n");
            }
            break;
            
        case 10:
            if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{
                if (binarySortTree->root)
                {
                     BST_postorderR(binarySortTree->root,visit);
                    printf("\n");
                }
                else{
                printf("树中无数据\n");
                }
               
            }
            break;
            
        case 11:
        if (binarySortTree == NULL){
                printf("树未初始化，请先初始化\n");
            }else{

                BST_levelOrder(binarySortTree,visit);
                printf("\n");

            }
            break;
            
        case 0:
            exit(0);
            break;
            
            
        default:printf("输入非法，请重新输入\n");
            break;
        }

    }
    

}
int main()
{
    Enum();//菜单
}
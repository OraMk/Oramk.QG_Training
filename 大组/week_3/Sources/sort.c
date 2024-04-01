#include "sort.h"
//插入排序
void insertSort (int arr[], int number)
{
    int temp = 0;
    int j = 0;
    for (int i = 1; i < number; i++)//第一项不用比较
    {
        temp = arr[i];
        j = i-1;//跟前面的比较
        while (j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = temp;//j<0或者arr[j]<temp 则放在temp放在arr[j]后一位
        
    }
    
}
//归并(MergeSort)递归
//递归部分
void MergeSort(int arr[],int temp[],int start , int end)
{
    if (start >= end)//判断是否只有一个元素
    {
        return;
    }
    int legth = end-start;//获取长度
    int mid = (legth >> 1) + start;//差除2加头值等于中值
    int start1 = start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 = end;
    MergeSort(arr,temp,start1,end1);//递归左边部分
    MergeSort(arr,temp,start2,end2);//递归右边部分
    MergeArray(arr,start,mid,end,temp);//合并数组
    
    
}
//归并排序（合并数组）
void MergeArray(int arr[],int start,int mid,int end,int temp[])
{
    int start1 = start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 = end;
    int k =start;//获取此处头
    while (start1 <= end1 && start2 <= end2)//遍历并判断是否都还有数据
    {
        temp[k++] = arr[start1] < arr[start2]?arr[start1++]:arr[start2++];//比较一个数组的两部分从左到右依次比较赋值于temp
    }
    while (start1 <= end1)
    {
        temp[k++] = arr[start1++];//将剩下的左边部分的直接载入temp（因为这部分是已经排序过的无需比较）
    }
    while (start2 <= end2)
    {
        temp[k++] = arr[start2++];//将剩下的右边部分的直接载入temp（因为这部分是已经排序过的无需比较）
    }
    for (k = start; k <= end; k++)
    {
        arr[k] = temp[k];//将temp的数值更新到原数组中
    }
}
//归并排序(初始化)
void MEergeSort_recursive(int arr[] , int number)
{
    int* temp = (int*)malloc(sizeof(int)*number) ;//创建临时数组
   
    MergeSort(arr,temp,0,number-1);//进入递归函数
    free(temp);
}

//快排的排序函数
int Partition(int arr[], int left, int right)
{   
    if (left>=right)//判断是否合法
    {
        return left;
    }
    int temp = arr[left];//临时储存最左边的数据
    while(left < right)
    {
        while (arr[right] >= temp && left < right)//查找比从右开始的数据比temp小的
    {
        right--;
    }
    if (left >= right)
    {
        break;
    }
    
    arr[left] = arr[right];//将小于temp的放在左边
    while (arr[left] <= temp && left < right)//查找比从左开始的数据比temp大的
    {
        left++;
    }
    if (left >= right)
    {
        break;
    }
    arr[right] = arr[left];//将大于temp的放在左边
    }
    arr[left] = temp;//left为相对中间的位置
    return left;//返回中间点（非等分）
    
}
//快排非递归版
void QuickSort(int* arr,int size){
    int left = 0;
    int right = size -1;
    int stack[right - left + 1]; // 创建一个数组栈模拟递归过程
    int top = -1; // 初始化栈顶指针
    stack[++top] = left; // 将初始的左边界入栈
    stack[++top] = right; // 将初始的右边界入栈

    while (top >= 0) { // 栈不为空时循环
        right = stack[top--]; // 出栈得到右边界,右边界后进先出
        left = stack[top--]; // 出栈得到左边界

        int pivotIndex = Partition(arr, left, right); // 进行一次划分，并得到枢纽元素的位置

        if (pivotIndex - 1 > left) { // 中间索引大于左边界，则左边还需排序
            stack[++top] = left; // 入栈左边界
            stack[++top] = pivotIndex - 1; // 入栈右边界
        }
        if (pivotIndex + 1 < right) { //中间索引小于右边界，则右边还需排序
            stack[++top] = pivotIndex + 1; // 入栈左边界
            stack[++top] = right; // 入栈右边界
        }
    }
}
//快排（递归版）
void QuickSort_Recursion(int arr[], int left , int right)
{
    if(left < right)
    {
    int qor = Partition(arr,left,right);//获取中间点
    QuickSort_Recursion(arr,left,qor-1);//分为左半部分
    QuickSort_Recursion(arr,qor+1,right);//分为右半部分
    }
    return;
}

//CountSort(计数排序)
void CountSort(int arr[],int number,int max)
{
    int* sort = (int *)malloc(sizeof(int)*number);
    int* count =(int*)malloc(sizeof(int)*(max+1));
    for (int i = 0; i < max+1; i++)
    {
        count[i] = 0;//初始化计数数组
    }
    
    for (int i = 0; i < number; i++)
    {
        count[arr[i]]++;//计数
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i-1];// 调整计数数组
    }
    // 生成输出数组
    for (int j = number; j > 0; j--)
    {
        //查找arr[i]应该放output的哪个索引
        // (arr[i] / n) % 10] - 1索引从0开始要减1
        //存进output数组后要减去一个位数
        sort[--count[arr[j-1]]] = arr[j-1];
    }
    for (int i = 0; i < number; i++)
    {
        arr[i] = sort[i];//将sort的结果赋值给arr
    }
    free(sort);
    free(count);
    return;
    
    
}
//基数排序
void RadixCountSort(int arr[],int size,int max)
{

    int digit = 1;
    //获取最大值的位数
    while (max)
    {
        digit++;
        max /= 10;
    }
    
    int count[10] = {0};
    int* output = (int*)malloc(sizeof(int)*size);
    for (int j = 1 , n = 1 ; j <= digit; j++, n *= 10)
    {
        for (int i = 0; i < size; i++)
        count[(arr[i] / n) % 10]++;

        // 调整计数数组
        for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

        // 生成输出数组
        for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / n) % 10] - 1] = arr[i];
        //查找arr[i]应该放output的哪个索引
        // (arr[i] / n) % 10] - 1索引从0开始要减1
        count[(arr[i] / n) % 10]--;
        //存进output数组后要减去一个位数
        }

        // 将输出复制回原数组
        for (int i = 0; i < size; i++)
        arr[i] = output[i];
        //重置计数 数组
        for (int i = 0; i < 10; i++)
            count[i] = 0;
    }
    free(output);
    
}
//保存数据函数
void SaveData(char fileName[],struct file* data)
{
    FILE* File = fopen(fileName,"a");
    if (File == NULL) {
        perror("打开文件时发生错误");
        return;
    }
    fprintf(File,"排序方式:%s 排序模式:%s 耗时:%lldms \n",data->method,data->Modle,data->time);
    fclose(File);
}
//颜色排序
void  Swap(int * a , int * b)//交换函数交换指针中的值
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ColorSort(int a[], int size)
{
    int head = 0;    // 指向下一个应该放0的位置
    int tail = size - 1;  // 指向下一个应该放2的位置
    
    int i = 0;//遍历数组
    while (i <= tail) {
        switch (a[i]) {//判断为0 1 2中的哪个
            case 0:
                Swap(&a[i], &a[head]);
                head++;
                i++;
                break;
            case 1:
                i++;
                break;
            case 2:
                Swap(&a[i], &a[tail]);
                tail--;
                break;
        }
    }
    
}

//颜色排序的简单测试
void Simply_show()
{
    int arr[20] = {2, 1, 0, 2, 0, 1, 1, 0, 2, 0, 1, 2, 1, 0, 2, 2, 0, 1, 1, 0};
    printf("排序前:");
    for(int i = 0; i < 20; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    ColorSort(arr,20);
    printf("排序后:");
    for(int i = 0; i < 20; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//颜色排序的自定义测试
void Customize_show()
{
    int *arr = (int*)malloc(sizeof(int)*200000);
    printf("请输入数据，注意不要超过200000个(输入3则结束输入)\n");
    int n = 0;
    while (1)
    {
        scanf("%d",&arr[n]);
        if (arr[n] == 3)
        {
            n--;
            if (n == -1)
            {
            printf("无数据退出\n");
            return;;
            
            }
            break;
        }
        if (!(arr[n] == 0 || arr[n] == 1 || arr[n] == 2 ))
        {
            printf("输入有误，请重新输入\n");
            continue;
        }
        
    
        n++;
    }
    printf("排序前:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    ColorSort(arr,n);
     printf("排序后:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
//用大数据量测试
void test1(int n)
{
    int *arr  = (int*)malloc(sizeof(int)*n);//储存排序数组
    int *temp = (int*)malloc(sizeof(int)*n);//临时储存数组以回溯已经排序好的数组
    int starttime = 0;//排序开始时间
    int endtime = 0;//排序结束时间
    struct file* data = (struct file*)malloc(sizeof(struct file));//用来储存排序的数据
    strcpy(data->Modle,"大数据量下");//设置变量
    printf("正在产生数组长度%d的随机数组\n",n);
    for (int i = 0; i < n; i++)//产生随机数组
    {
        arr[i] = rand()%100+1;//1-100
        temp[i] = arr[i];
    }

    starttime = GetTickCount();//记录排序开始时间
    insertSort(arr,n);//调用排序函数
    endtime = GetTickCount();//记录排序结束时间
    printf("插入排序:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// 存储数据
    strcpy(data->method,"插入排序");
    SaveData(".\\testdata.txt",data);//保存数据
    printf("正在回溯数组...请稍等...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//回溯数组

    starttime = GetTickCount();//记录排序开始时间
    MEergeSort_recursive(arr,n);//调用排序函数
    endtime = GetTickCount();//记录排序结束时间
    printf("归并排序:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// 存储数据
    strcpy(data->method,"归并排序");
    SaveData(".\\testdata.txt",data);//保存数据
    printf("正在回溯数组...请稍等...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//回溯数组

    starttime = GetTickCount();//记录排序开始时间
    QuickSort_Recursion(arr,0,n-1);//调用排序函数
    endtime = GetTickCount();//记录排序结束时间
    printf("快速排序（递归版）:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// 存储数据
    strcpy(data->method,"快速排序");
    SaveData(".\\testdata.txt",data);//保存数据
    printf("正在回溯数组...请稍等...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//回溯数组

    starttime = GetTickCount();//记录排序开始时间
    QuickSort(arr,n);//调用排序函数
    endtime = GetTickCount();//记录排序结束时间
    printf("快排(非递归):");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// 存储数据
    strcpy(data->method,"快排(非递归)");
    SaveData(".\\testdata.txt",data);//保存数据
    printf("正在回溯数组...请稍等...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//回溯数组

    starttime = GetTickCount();//记录排序开始时间
    CountSort(arr,n,100);//调用排序函数
    endtime = GetTickCount();//记录排序结束时间
    printf("计数排序:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// 存储数据
    strcpy(data->method,"计数排序");
    SaveData(".\\testdata.txt",data);//保存数据
    printf("正在回溯数组...请稍等...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//回溯数组

    starttime = GetTickCount();//记录排序开始时间
    RadixCountSort(arr,n,100);//调用排序函数
    endtime = GetTickCount();//记录排序结束时间
    printf("基数计数排序:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;//存储数据
    strcpy(data->method,"基数排序");
    SaveData(".\\testdata.txt",data);//保存数据

}

//用小数据大规模测试
void test2(int k)
{   
    int arr[100];//储存排序数组
    int temp[100];//临时储存数组以回溯已经排序好的数组
    int starttime = 0;//排序开始时间
    int starttime1 = 0;//回溯时间
    int endtime = 0;//排序结束时间
    int endtime1 = 0;//回溯时间末尾
    int TEMP = 0;//用来记录回溯的时间
    struct file* data = (struct file*)malloc(sizeof(struct file));//存储排序数据
    strcpy(data->Modle,"大量小数据量");//设置数据
    printf("正在产生数组长度100的随机数组\n");
    for (int i = 0; i < 100; i++)//产生随机数组
    {
        arr[i] = rand()%100+1;
        temp[i] = arr[i];
    }

    starttime = GetTickCount();//设置开始时间
    for (int i = 0; i < 100*k; i++)//指向100*k次
    {
        insertSort(arr,100);//调用排序函数
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//回溯
        {
            arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//计算回溯时间并相加
    }
    endtime = GetTickCount();
    printf("插入排序:");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//记录数据
    strcpy(data->method,"插入排序");
    SaveData(".\\testdata.txt",data);//保存数据

    TEMP = 0;//初始化TEMP
    starttime = GetTickCount();//设置开始时间
    for (int i = 0; i < 100*k; i++)//指向100*k次
    {
        MEergeSort_recursive(arr,100);//调用排序函数
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//回溯
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//计算回溯时间并相加
    }
    endtime = GetTickCount();
    printf("归并排序:");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//记录数据
    strcpy(data->method,"归并排序");
    SaveData(".\\testdata.txt",data);//保存数据

    TEMP = 0;//初始化TEMP
    starttime = GetTickCount();//设置开始时间
    for (int i = 0; i < 100*k; i++)//指向100*k次
    {
        QuickSort_Recursion(arr,0,99);//调用排序函数
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//回溯
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//计算回溯时间并相加
    }
    endtime = GetTickCount();
    printf("快速排序:");
    printf("%lld ms\n",endtime-starttime-TEMP); //记录数据
    data->time = endtime - starttime - TEMP;
    strcpy(data->method,"快速排序");
    SaveData(".\\testdata.txt",data);//保存数据

    TEMP = 0;//初始化TEMP
    starttime = GetTickCount();//设置开始时间
    for (int i = 0; i < 100*k; i++)//指向100*k次
    {
        QuickSort(arr,100);//调用排序函数
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//回溯
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//计算回溯时间并相加
    }
    endtime = GetTickCount();
    printf("快排(非递归):");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//记录数据
    strcpy(data->method,"快排(非递归)");
    SaveData(".\\testdata.txt",data);//保存数据

    TEMP = 0;//初始化TEMP
    starttime = GetTickCount();//设置开始时间
    for (int i = 0; i < 100*k; i++)//指向100*k次
    {
        CountSort(arr,100,100);//调用排序函数
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//回溯
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//计算回溯时间并相加
    }
    endtime = GetTickCount();
    printf("计数排序:");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//记录数据
    strcpy(data->method,"计数排序");
    SaveData(".\\testdata.txt",data);//保存数据

    TEMP = 0;//初始化TEMP
    starttime = GetTickCount();//设置开始时间
    for (int i = 0; i < 100*k; i++)//指向100*k次
    {
        RadixCountSort(arr,100,100);
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//调用排序函数
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//计算回溯时间并相加
    }
    endtime = GetTickCount();
    printf("基数排序:");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//记录数据
    strcpy(data->method,"基数排序");
    SaveData(".\\testdata.txt",data);//保存数据

}

//读取文件并用排序函数测试
void Readdata()
{
    
    while (1)
    {
        printf("请输入文件路径(需要后缀)");
        char _path[PATH_MAX];
        getcwd(_path,sizeof(_path));//获取当前路径
        strcat(_path,"//");//设置当前目录为默认路径
        char fileName[100];
        scanf("%s",fileName);
        strcat(_path,fileName);
        FILE* PATH = fopen(_path,"r");
        if (PATH == NULL)
        {
        printf("地址输入错误，请重试");
        continue;

        }
    
        int*arr = (int *)malloc(sizeof(int)*200000);//默认设置二十万的数组大小
        int n = 0;
        while (fscanf(PATH,"%d",&arr[n++]) == 1);//从文件读取数字
        n-=1;//减去最后一个


        int *temp = (int*)malloc(sizeof(int)*n);//以下代码与test1类似减去了保存数据的过程
        int starttime = 0;
        int endtime = 0;
        int max = arr[0];
        for (int i = 0; i < n; i++)
        {
            temp[i] = arr[i];
            if(max < arr[i])
            {
                max = arr[i];
            }
        }
        starttime = GetTickCount();
        insertSort(arr,n);
        endtime = GetTickCount();
        printf("插入排序:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        printf("正在回溯数组...请稍等...\n");
        for (int i = 0; i < n; i++)arr[i] = temp[i];

        starttime = GetTickCount();
        MEergeSort_recursive(arr,n);
        endtime = GetTickCount();
        printf("归并排序:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        printf("正在回溯数组...请稍等...\n");
        for (int i = 0; i < n; i++)arr[i] = temp[i];

        starttime = GetTickCount();
        QuickSort_Recursion(arr,0,n-1);
        endtime = GetTickCount();
        printf("快速排序（递归版）:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        printf("正在回溯数组...请稍等...\n");
        for (int i = 0; i < n; i++)arr[i] = temp[i];

        starttime = GetTickCount();
        CountSort(arr,n,max);
        endtime = GetTickCount();
        printf("计数排序:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        printf("正在回溯数组...请稍等...\n");
        for (int i = 0; i < n; i++)arr[i] = temp[i];

        starttime = GetTickCount();
        RadixCountSort(arr,n,max);
        endtime = GetTickCount();
        printf("基数计数排序:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        break;
    }
    
   
}
//实现查找第k大/小的实现函数
void QuickSort_Find(int arr[], int left , int right , int number)//对快排进行更改
{
    if(left < right)
    {
    int qor = Partition(arr,left,right);//获取中间点
    if (qor == number)//判断是否查找到
    {
        printf("结果为:%d\n",arr[qor]); return ;
        
    }
    else if (qor < number) {
            QuickSort_Find(arr, qor + 1, right, number); // 在右半部分继续查找
    } 
    else{
            QuickSort_Find(arr, left, qor - 1, number); // 在左半部分继续查找
    }
    
    }else if(left == right){
        if (left == number)
        {
            printf("结果为:%d\n",arr[left]); return ;
        }
        
    }
    else
    {
        printf("没找到\n");
        return;

    }
}
//查找无序数组中的第k大/小的函数的界面函数
void Find(int arr[],int size)
{
    printf("请选择第 n 大(1) / 小(2)的数字 选择(1,2)");
    int choose = 0;
    int isFlase = 1;//判断是否正常输入
    int number = 0;
    while (isFlase)
    {
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            printf("请输入n(第n大):");
            while (1)//防止误输入
            {
               scanf("%d",&number);
               if(number <= 0)
               {
                printf("请输入大于0的数字\n");
                continue;
               }
               break;
            }
            QuickSort_Find(arr, 0 , size-1 ,size-number);//快排获取的为从小到大的故要size-number
            isFlase = 0;
            break;

        case 2:
            printf("请输入n(第n小):");
              while (1)//防止误输入
            {
               scanf("%d",&number);
               if(number <= 0)
               {
                printf("请输入大于0的数字\n");
                continue;
               }
               break;
            }
            scanf("%d",&number);
            QuickSort_Find(arr, 0 , size-1 ,number-1);//索引从0开始
            isFlase = 0;
            break;

        default:
            printf("输入错误请重试\n");
            break;
        }

    }
      
}

//查找函数的简单实现
void Find_Simple()
{
    int arr[7] ={5,2,8,4,3,7,6};
    printf("数组为:");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int choose = 0;
    Find(arr,7);
    while (1)
    {
        
        printf("是否要继续查找(1.Yes;2.NO)：");
        scanf("%d",&choose);
        if (!(choose == 1 || choose ==2))
        {
            printf("输入错误请重新输入\n");
            continue;
        }
        if (choose == 2)
        {
            printf("退出查找\n");
            break;
        }
        else{
            Find(arr,7);
        }
    }
}

//自定义实现
void Find_Custom()
{
    int *arr = (int*)malloc(sizeof(int)*200000);
    printf("请输入数据,注意不要超过200000个(输入0则结束输入)\n");
    int n = 0;
    while (1)
    {
        scanf("%d",&arr[n]);
        if (arr[n] == 0)
        {
            n--;
            break;
        }
        
        n++;
    }
    if (n == -1)
    {
        printf("无数据退出\n");
        return ;
    }
    
    printf("自定义数组为:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int choose = 0;
    Find(arr,7);
    while (1)
    {
        
        printf("是否要继续查找(1.Yes;2.NO)：");
        scanf("%d",&choose);
        if (!(choose == 1 || choose ==2))
        {
            printf("输入错误请重新输入\n");
            continue;
        }
        
        if (choose == 2)
        {
            printf("退出查找\n");
            break;
        }
        else{
            Find(arr,n);
        }
    }
    
    
}

//冒泡排序一种优化方式
void BubbleSort_1(int arr[],int number){
    int flag = 0;//标记变量
	int tmp = 0;
	for (int i = 0; i < number - 1; i++)//确定排序趟数
	{
		flag = 0;//初始化标记变量
		for (int j = 0; j < number - 1 - i; j++)//确定比较次数
		{
			if (arr[j]>arr[j + 1])
			{
				//交换
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//进行标记
			}
		}
		if (flag == 0)//如果没有交换过元素，则已经有序
		{
			return;
		}
	}
}
void Customize_BubbleSort_1()
{
    int *arr = (int*)malloc(sizeof(int)*200000);
    printf("请输入数据，注意不要超过200000个(输入3则结束输入)\n");
    int n = 0;
    while (1)
    {
        scanf("%d",&arr[n]);
        if (arr[n] == 3)
        {
            n--;
            break;
        }
        
        n++;
    }
    printf("排序前:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    BubbleSort_1(arr,n);
    printf("排序后:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
void Enum()
{
    while (1)
    {
    printf("=====================================\n");
    printf("1.大数据量测试\n");
    printf("2.大量小数据\n");
    printf("3.读取文件中的数据并进行排序测试\n");
    printf("4.颜色排序\n");
    printf("5.在一个无序序列中找到第K大/小的数\n");
    printf("6.冒泡排序一种优化方式\n");
    printf("0.退出\n");
    printf("=====================================\n");
    int choose = 0;
    printf("请输入选项:");
    scanf("%d",&choose);
    int n = 0;
    int count = 0;
    switch (choose)
    {
    case 1:
        printf("请选择使用哪个层次(1->10000 ; 2->50000 ; 3->200000)\n");
        while (1)
        {
            printf("请输入选项(1,2,3):");
            scanf("%d",&n);
            switch (n)
            {
            case 1:test1(10000);
                break;
            case 2:test1(50000);
                break;
            case 3:test1(200000);
                break;
            default:
                printf("输入错误请重试\n");
                break;
            }
            if ( n == 1 || n == 2 || n == 3)
            {
                break;
            }
            
        }
        
        break;
    case 2:
        printf("请输入k(100个数据*100k次排序)");
        scanf("%d",&count);
        test2(100*count);
        break;
    case 3:
        Readdata();
        break;
    case 4:
        printf("1.简单展示该实现、2.自主测试");
        printf("请选择:");
        while (1)
        {
            printf("请输入选项(1,2):");
            scanf("%d",&n);
            switch (n)
            {
            case 1:Simply_show();
                break;
            case 2:Customize_show();
                break;
            default:
                printf("输入有误，请重试\n");
                break;
            }
            if ( n == 1 || n == 2)
            {
                break;
            }
        }
    
        break;
    case 5:
        printf("1.简单展示该实现、2.自主测试");
        printf("请选择:");
        while (1)
        {
            printf("请输入选项(1,2):");
            scanf("%d",&n);
            switch (n)
            {
            case 1:Find_Simple();
                break;
            case 2:Find_Custom();
                break;
            default:
                printf("输入有误，请重试\n");
                break;
            }
            if ( n == 1 || n == 2)
            {
                break;
            }
        }

        break;
    case 6:
        Customize_BubbleSort_1();
        break;
    case 0:
        printf("退出\n");
        exit(0);
    default:
        printf("输入错误，请重试\n");
        break;
    }
    }

}


int main(){
    srand((unsigned)time(NULL));//使得随机数根据时间戳获取
    Enum(); 
 
}

#include "sort.h"
//��������
void insertSort (int arr[], int number)
{
    int temp = 0;
    int j = 0;
    for (int i = 1; i < number; i++)//��һ��ñȽ�
    {
        temp = arr[i];
        j = i-1;//��ǰ��ıȽ�
        while (j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = temp;//j<0����arr[j]<temp �����temp����arr[j]��һλ
        
    }
    
}
//�鲢(MergeSort)�ݹ�
//�ݹ鲿��
void MergeSort(int arr[],int temp[],int start , int end)
{
    if (start >= end)//�ж��Ƿ�ֻ��һ��Ԫ��
    {
        return;
    }
    int legth = end-start;//��ȡ����
    int mid = (legth >> 1) + start;//���2��ͷֵ������ֵ
    int start1 = start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 = end;
    MergeSort(arr,temp,start1,end1);//�ݹ���߲���
    MergeSort(arr,temp,start2,end2);//�ݹ��ұ߲���
    MergeArray(arr,start,mid,end,temp);//�ϲ�����
    
    
}
//�鲢���򣨺ϲ����飩
void MergeArray(int arr[],int start,int mid,int end,int temp[])
{
    int start1 = start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 = end;
    int k =start;//��ȡ�˴�ͷ
    while (start1 <= end1 && start2 <= end2)//�������ж��Ƿ񶼻�������
    {
        temp[k++] = arr[start1] < arr[start2]?arr[start1++]:arr[start2++];//�Ƚ�һ������������ִ��������αȽϸ�ֵ��temp
    }
    while (start1 <= end1)
    {
        temp[k++] = arr[start1++];//��ʣ�µ���߲��ֵ�ֱ������temp����Ϊ�ⲿ�����Ѿ������������Ƚϣ�
    }
    while (start2 <= end2)
    {
        temp[k++] = arr[start2++];//��ʣ�µ��ұ߲��ֵ�ֱ������temp����Ϊ�ⲿ�����Ѿ������������Ƚϣ�
    }
    for (k = start; k <= end; k++)
    {
        arr[k] = temp[k];//��temp����ֵ���µ�ԭ������
    }
}
//�鲢����(��ʼ��)
void MEergeSort_recursive(int arr[] , int number)
{
    int* temp = (int*)malloc(sizeof(int)*number) ;//������ʱ����
   
    MergeSort(arr,temp,0,number-1);//����ݹ麯��
    free(temp);
}

//���ŵ�������
int Partition(int arr[], int left, int right)
{   
    if (left>=right)//�ж��Ƿ�Ϸ�
    {
        return left;
    }
    int temp = arr[left];//��ʱ��������ߵ�����
    while(left < right)
    {
        while (arr[right] >= temp && left < right)//���ұȴ��ҿ�ʼ�����ݱ�tempС��
    {
        right--;
    }
    if (left >= right)
    {
        break;
    }
    
    arr[left] = arr[right];//��С��temp�ķ������
    while (arr[left] <= temp && left < right)//���ұȴ���ʼ�����ݱ�temp���
    {
        left++;
    }
    if (left >= right)
    {
        break;
    }
    arr[right] = arr[left];//������temp�ķ������
    }
    arr[left] = temp;//leftΪ����м��λ��
    return left;//�����м�㣨�ǵȷ֣�
    
}
//���ŷǵݹ��
void QuickSort(int* arr,int size){
    int left = 0;
    int right = size -1;
    int stack[right - left + 1]; // ����һ������ջģ��ݹ����
    int top = -1; // ��ʼ��ջ��ָ��
    stack[++top] = left; // ����ʼ����߽���ջ
    stack[++top] = right; // ����ʼ���ұ߽���ջ

    while (top >= 0) { // ջ��Ϊ��ʱѭ��
        right = stack[top--]; // ��ջ�õ��ұ߽�,�ұ߽����ȳ�
        left = stack[top--]; // ��ջ�õ���߽�

        int pivotIndex = Partition(arr, left, right); // ����һ�λ��֣����õ���ŦԪ�ص�λ��

        if (pivotIndex - 1 > left) { // �м�����������߽磬����߻�������
            stack[++top] = left; // ��ջ��߽�
            stack[++top] = pivotIndex - 1; // ��ջ�ұ߽�
        }
        if (pivotIndex + 1 < right) { //�м�����С���ұ߽磬���ұ߻�������
            stack[++top] = pivotIndex + 1; // ��ջ��߽�
            stack[++top] = right; // ��ջ�ұ߽�
        }
    }
}
//���ţ��ݹ�棩
void QuickSort_Recursion(int arr[], int left , int right)
{
    if(left < right)
    {
    int qor = Partition(arr,left,right);//��ȡ�м��
    QuickSort_Recursion(arr,left,qor-1);//��Ϊ��벿��
    QuickSort_Recursion(arr,qor+1,right);//��Ϊ�Ұ벿��
    }
    return;
}

//CountSort(��������)
void CountSort(int arr[],int number,int max)
{
    int* sort = (int *)malloc(sizeof(int)*number);
    int* count =(int*)malloc(sizeof(int)*(max+1));
    for (int i = 0; i < max+1; i++)
    {
        count[i] = 0;//��ʼ����������
    }
    
    for (int i = 0; i < number; i++)
    {
        count[arr[i]]++;//����
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i-1];// ������������
    }
    // �����������
    for (int j = number; j > 0; j--)
    {
        //����arr[i]Ӧ�÷�output���ĸ�����
        // (arr[i] / n) % 10] - 1������0��ʼҪ��1
        //���output�����Ҫ��ȥһ��λ��
        sort[--count[arr[j-1]]] = arr[j-1];
    }
    for (int i = 0; i < number; i++)
    {
        arr[i] = sort[i];//��sort�Ľ����ֵ��arr
    }
    free(sort);
    free(count);
    return;
    
    
}
//��������
void RadixCountSort(int arr[],int size,int max)
{

    int digit = 1;
    //��ȡ���ֵ��λ��
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

        // ������������
        for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

        // �����������
        for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / n) % 10] - 1] = arr[i];
        //����arr[i]Ӧ�÷�output���ĸ�����
        // (arr[i] / n) % 10] - 1������0��ʼҪ��1
        count[(arr[i] / n) % 10]--;
        //���output�����Ҫ��ȥһ��λ��
        }

        // ��������ƻ�ԭ����
        for (int i = 0; i < size; i++)
        arr[i] = output[i];
        //���ü��� ����
        for (int i = 0; i < 10; i++)
            count[i] = 0;
    }
    free(output);
    
}
//�������ݺ���
void SaveData(char fileName[],struct file* data)
{
    FILE* File = fopen(fileName,"a");
    if (File == NULL) {
        perror("���ļ�ʱ��������");
        return;
    }
    fprintf(File,"����ʽ:%s ����ģʽ:%s ��ʱ:%lldms \n",data->method,data->Modle,data->time);
    fclose(File);
}
//��ɫ����
void  Swap(int * a , int * b)//������������ָ���е�ֵ
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ColorSort(int a[], int size)
{
    int head = 0;    // ָ����һ��Ӧ�÷�0��λ��
    int tail = size - 1;  // ָ����һ��Ӧ�÷�2��λ��
    
    int i = 0;//��������
    while (i <= tail) {
        switch (a[i]) {//�ж�Ϊ0 1 2�е��ĸ�
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

//��ɫ����ļ򵥲���
void Simply_show()
{
    int arr[20] = {2, 1, 0, 2, 0, 1, 1, 0, 2, 0, 1, 2, 1, 0, 2, 2, 0, 1, 1, 0};
    printf("����ǰ:");
    for(int i = 0; i < 20; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    ColorSort(arr,20);
    printf("�����:");
    for(int i = 0; i < 20; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//��ɫ������Զ������
void Customize_show()
{
    int *arr = (int*)malloc(sizeof(int)*200000);
    printf("���������ݣ�ע�ⲻҪ����200000��(����3���������)\n");
    int n = 0;
    while (1)
    {
        scanf("%d",&arr[n]);
        if (arr[n] == 3)
        {
            n--;
            if (n == -1)
            {
            printf("�������˳�\n");
            return;;
            
            }
            break;
        }
        if (!(arr[n] == 0 || arr[n] == 1 || arr[n] == 2 ))
        {
            printf("������������������\n");
            continue;
        }
        
    
        n++;
    }
    printf("����ǰ:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    ColorSort(arr,n);
     printf("�����:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
//�ô�����������
void test1(int n)
{
    int *arr  = (int*)malloc(sizeof(int)*n);//������������
    int *temp = (int*)malloc(sizeof(int)*n);//��ʱ���������Ի����Ѿ�����õ�����
    int starttime = 0;//����ʼʱ��
    int endtime = 0;//�������ʱ��
    struct file* data = (struct file*)malloc(sizeof(struct file));//�����������������
    strcpy(data->Modle,"����������");//���ñ���
    printf("���ڲ������鳤��%d���������\n",n);
    for (int i = 0; i < n; i++)//�����������
    {
        arr[i] = rand()%100+1;//1-100
        temp[i] = arr[i];
    }

    starttime = GetTickCount();//��¼����ʼʱ��
    insertSort(arr,n);//����������
    endtime = GetTickCount();//��¼�������ʱ��
    printf("��������:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// �洢����
    strcpy(data->method,"��������");
    SaveData(".\\testdata.txt",data);//��������
    printf("���ڻ�������...���Ե�...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//��������

    starttime = GetTickCount();//��¼����ʼʱ��
    MEergeSort_recursive(arr,n);//����������
    endtime = GetTickCount();//��¼�������ʱ��
    printf("�鲢����:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// �洢����
    strcpy(data->method,"�鲢����");
    SaveData(".\\testdata.txt",data);//��������
    printf("���ڻ�������...���Ե�...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//��������

    starttime = GetTickCount();//��¼����ʼʱ��
    QuickSort_Recursion(arr,0,n-1);//����������
    endtime = GetTickCount();//��¼�������ʱ��
    printf("�������򣨵ݹ�棩:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// �洢����
    strcpy(data->method,"��������");
    SaveData(".\\testdata.txt",data);//��������
    printf("���ڻ�������...���Ե�...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//��������

    starttime = GetTickCount();//��¼����ʼʱ��
    QuickSort(arr,n);//����������
    endtime = GetTickCount();//��¼�������ʱ��
    printf("����(�ǵݹ�):");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// �洢����
    strcpy(data->method,"����(�ǵݹ�)");
    SaveData(".\\testdata.txt",data);//��������
    printf("���ڻ�������...���Ե�...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//��������

    starttime = GetTickCount();//��¼����ʼʱ��
    CountSort(arr,n,100);//����������
    endtime = GetTickCount();//��¼�������ʱ��
    printf("��������:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;// �洢����
    strcpy(data->method,"��������");
    SaveData(".\\testdata.txt",data);//��������
    printf("���ڻ�������...���Ե�...\n");
    for (int i = 0; i < n; i++)arr[i] = temp[i];//��������

    starttime = GetTickCount();//��¼����ʼʱ��
    RadixCountSort(arr,n,100);//����������
    endtime = GetTickCount();//��¼�������ʱ��
    printf("������������:");
    printf("%lld ms\n",endtime-starttime);
    printf("\n");
    data->time = endtime - starttime;//�洢����
    strcpy(data->method,"��������");
    SaveData(".\\testdata.txt",data);//��������

}

//��С���ݴ��ģ����
void test2(int k)
{   
    int arr[100];//������������
    int temp[100];//��ʱ���������Ի����Ѿ�����õ�����
    int starttime = 0;//����ʼʱ��
    int starttime1 = 0;//����ʱ��
    int endtime = 0;//�������ʱ��
    int endtime1 = 0;//����ʱ��ĩβ
    int TEMP = 0;//������¼���ݵ�ʱ��
    struct file* data = (struct file*)malloc(sizeof(struct file));//�洢��������
    strcpy(data->Modle,"����С������");//��������
    printf("���ڲ������鳤��100���������\n");
    for (int i = 0; i < 100; i++)//�����������
    {
        arr[i] = rand()%100+1;
        temp[i] = arr[i];
    }

    starttime = GetTickCount();//���ÿ�ʼʱ��
    for (int i = 0; i < 100*k; i++)//ָ��100*k��
    {
        insertSort(arr,100);//����������
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//����
        {
            arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//�������ʱ�䲢���
    }
    endtime = GetTickCount();
    printf("��������:");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//��¼����
    strcpy(data->method,"��������");
    SaveData(".\\testdata.txt",data);//��������

    TEMP = 0;//��ʼ��TEMP
    starttime = GetTickCount();//���ÿ�ʼʱ��
    for (int i = 0; i < 100*k; i++)//ָ��100*k��
    {
        MEergeSort_recursive(arr,100);//����������
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//����
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//�������ʱ�䲢���
    }
    endtime = GetTickCount();
    printf("�鲢����:");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//��¼����
    strcpy(data->method,"�鲢����");
    SaveData(".\\testdata.txt",data);//��������

    TEMP = 0;//��ʼ��TEMP
    starttime = GetTickCount();//���ÿ�ʼʱ��
    for (int i = 0; i < 100*k; i++)//ָ��100*k��
    {
        QuickSort_Recursion(arr,0,99);//����������
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//����
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//�������ʱ�䲢���
    }
    endtime = GetTickCount();
    printf("��������:");
    printf("%lld ms\n",endtime-starttime-TEMP); //��¼����
    data->time = endtime - starttime - TEMP;
    strcpy(data->method,"��������");
    SaveData(".\\testdata.txt",data);//��������

    TEMP = 0;//��ʼ��TEMP
    starttime = GetTickCount();//���ÿ�ʼʱ��
    for (int i = 0; i < 100*k; i++)//ָ��100*k��
    {
        QuickSort(arr,100);//����������
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//����
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//�������ʱ�䲢���
    }
    endtime = GetTickCount();
    printf("����(�ǵݹ�):");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//��¼����
    strcpy(data->method,"����(�ǵݹ�)");
    SaveData(".\\testdata.txt",data);//��������

    TEMP = 0;//��ʼ��TEMP
    starttime = GetTickCount();//���ÿ�ʼʱ��
    for (int i = 0; i < 100*k; i++)//ָ��100*k��
    {
        CountSort(arr,100,100);//����������
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//����
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//�������ʱ�䲢���
    }
    endtime = GetTickCount();
    printf("��������:");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//��¼����
    strcpy(data->method,"��������");
    SaveData(".\\testdata.txt",data);//��������

    TEMP = 0;//��ʼ��TEMP
    starttime = GetTickCount();//���ÿ�ʼʱ��
    for (int i = 0; i < 100*k; i++)//ָ��100*k��
    {
        RadixCountSort(arr,100,100);
        starttime1 = GetTickCount();
        for (int j = 0; j < 100; j++)//����������
        {
        arr[j] = temp[j];
        }
        endtime1 = GetTickCount();
        TEMP += endtime1 - starttime1;//�������ʱ�䲢���
    }
    endtime = GetTickCount();
    printf("��������:");
    printf("%lld ms\n",endtime-starttime-TEMP);
    data->time = endtime - starttime - TEMP;//��¼����
    strcpy(data->method,"��������");
    SaveData(".\\testdata.txt",data);//��������

}

//��ȡ�ļ���������������
void Readdata()
{
    
    while (1)
    {
        printf("�������ļ�·��(��Ҫ��׺)");
        char _path[PATH_MAX];
        getcwd(_path,sizeof(_path));//��ȡ��ǰ·��
        strcat(_path,"//");//���õ�ǰĿ¼ΪĬ��·��
        char fileName[100];
        scanf("%s",fileName);
        strcat(_path,fileName);
        FILE* PATH = fopen(_path,"r");
        if (PATH == NULL)
        {
        printf("��ַ�������������");
        continue;

        }
    
        int*arr = (int *)malloc(sizeof(int)*200000);//Ĭ�����ö�ʮ��������С
        int n = 0;
        while (fscanf(PATH,"%d",&arr[n++]) == 1);//���ļ���ȡ����
        n-=1;//��ȥ���һ��


        int *temp = (int*)malloc(sizeof(int)*n);//���´�����test1���Ƽ�ȥ�˱������ݵĹ���
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
        printf("��������:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        printf("���ڻ�������...���Ե�...\n");
        for (int i = 0; i < n; i++)arr[i] = temp[i];

        starttime = GetTickCount();
        MEergeSort_recursive(arr,n);
        endtime = GetTickCount();
        printf("�鲢����:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        printf("���ڻ�������...���Ե�...\n");
        for (int i = 0; i < n; i++)arr[i] = temp[i];

        starttime = GetTickCount();
        QuickSort_Recursion(arr,0,n-1);
        endtime = GetTickCount();
        printf("�������򣨵ݹ�棩:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        printf("���ڻ�������...���Ե�...\n");
        for (int i = 0; i < n; i++)arr[i] = temp[i];

        starttime = GetTickCount();
        CountSort(arr,n,max);
        endtime = GetTickCount();
        printf("��������:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        printf("���ڻ�������...���Ե�...\n");
        for (int i = 0; i < n; i++)arr[i] = temp[i];

        starttime = GetTickCount();
        RadixCountSort(arr,n,max);
        endtime = GetTickCount();
        printf("������������:");
        printf("%d ms\n",endtime-starttime);
        printf("\n");
        break;
    }
    
   
}
//ʵ�ֲ��ҵ�k��/С��ʵ�ֺ���
void QuickSort_Find(int arr[], int left , int right , int number)//�Կ��Ž��и���
{
    if(left < right)
    {
    int qor = Partition(arr,left,right);//��ȡ�м��
    if (qor == number)//�ж��Ƿ���ҵ�
    {
        printf("���Ϊ:%d\n",arr[qor]); return ;
        
    }
    else if (qor < number) {
            QuickSort_Find(arr, qor + 1, right, number); // ���Ұ벿�ּ�������
    } 
    else{
            QuickSort_Find(arr, left, qor - 1, number); // ����벿�ּ�������
    }
    
    }else if(left == right){
        if (left == number)
        {
            printf("���Ϊ:%d\n",arr[left]); return ;
        }
        
    }
    else
    {
        printf("û�ҵ�\n");
        return;

    }
}
//�������������еĵ�k��/С�ĺ����Ľ��溯��
void Find(int arr[],int size)
{
    printf("��ѡ��� n ��(1) / С(2)������ ѡ��(1,2)");
    int choose = 0;
    int isFlase = 1;//�ж��Ƿ���������
    int number = 0;
    while (isFlase)
    {
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            printf("������n(��n��):");
            while (1)//��ֹ������
            {
               scanf("%d",&number);
               if(number <= 0)
               {
                printf("���������0������\n");
                continue;
               }
               break;
            }
            QuickSort_Find(arr, 0 , size-1 ,size-number);//���Ż�ȡ��Ϊ��С����Ĺ�Ҫsize-number
            isFlase = 0;
            break;

        case 2:
            printf("������n(��nС):");
              while (1)//��ֹ������
            {
               scanf("%d",&number);
               if(number <= 0)
               {
                printf("���������0������\n");
                continue;
               }
               break;
            }
            scanf("%d",&number);
            QuickSort_Find(arr, 0 , size-1 ,number-1);//������0��ʼ
            isFlase = 0;
            break;

        default:
            printf("�������������\n");
            break;
        }

    }
      
}

//���Һ����ļ�ʵ��
void Find_Simple()
{
    int arr[7] ={5,2,8,4,3,7,6};
    printf("����Ϊ:");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int choose = 0;
    Find(arr,7);
    while (1)
    {
        
        printf("�Ƿ�Ҫ��������(1.Yes;2.NO)��");
        scanf("%d",&choose);
        if (!(choose == 1 || choose ==2))
        {
            printf("�����������������\n");
            continue;
        }
        if (choose == 2)
        {
            printf("�˳�����\n");
            break;
        }
        else{
            Find(arr,7);
        }
    }
}

//�Զ���ʵ��
void Find_Custom()
{
    int *arr = (int*)malloc(sizeof(int)*200000);
    printf("����������,ע�ⲻҪ����200000��(����0���������)\n");
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
        printf("�������˳�\n");
        return ;
    }
    
    printf("�Զ�������Ϊ:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int choose = 0;
    Find(arr,7);
    while (1)
    {
        
        printf("�Ƿ�Ҫ��������(1.Yes;2.NO)��");
        scanf("%d",&choose);
        if (!(choose == 1 || choose ==2))
        {
            printf("�����������������\n");
            continue;
        }
        
        if (choose == 2)
        {
            printf("�˳�����\n");
            break;
        }
        else{
            Find(arr,n);
        }
    }
    
    
}

//ð������һ���Ż���ʽ
void BubbleSort_1(int arr[],int number){
    int flag = 0;//��Ǳ���
	int tmp = 0;
	for (int i = 0; i < number - 1; i++)//ȷ����������
	{
		flag = 0;//��ʼ����Ǳ���
		for (int j = 0; j < number - 1 - i; j++)//ȷ���Ƚϴ���
		{
			if (arr[j]>arr[j + 1])
			{
				//����
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//���б��
			}
		}
		if (flag == 0)//���û�н�����Ԫ�أ����Ѿ�����
		{
			return;
		}
	}
}
void Customize_BubbleSort_1()
{
    int *arr = (int*)malloc(sizeof(int)*200000);
    printf("���������ݣ�ע�ⲻҪ����200000��(����3���������)\n");
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
    printf("����ǰ:");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    BubbleSort_1(arr,n);
    printf("�����:");
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
    printf("1.������������\n");
    printf("2.����С����\n");
    printf("3.��ȡ�ļ��е����ݲ������������\n");
    printf("4.��ɫ����\n");
    printf("5.��һ�������������ҵ���K��/С����\n");
    printf("6.ð������һ���Ż���ʽ\n");
    printf("0.�˳�\n");
    printf("=====================================\n");
    int choose = 0;
    printf("������ѡ��:");
    scanf("%d",&choose);
    int n = 0;
    int count = 0;
    switch (choose)
    {
    case 1:
        printf("��ѡ��ʹ���ĸ����(1->10000 ; 2->50000 ; 3->200000)\n");
        while (1)
        {
            printf("������ѡ��(1,2,3):");
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
                printf("�������������\n");
                break;
            }
            if ( n == 1 || n == 2 || n == 3)
            {
                break;
            }
            
        }
        
        break;
    case 2:
        printf("������k(100������*100k������)");
        scanf("%d",&count);
        test2(100*count);
        break;
    case 3:
        Readdata();
        break;
    case 4:
        printf("1.��չʾ��ʵ�֡�2.��������");
        printf("��ѡ��:");
        while (1)
        {
            printf("������ѡ��(1,2):");
            scanf("%d",&n);
            switch (n)
            {
            case 1:Simply_show();
                break;
            case 2:Customize_show();
                break;
            default:
                printf("��������������\n");
                break;
            }
            if ( n == 1 || n == 2)
            {
                break;
            }
        }
    
        break;
    case 5:
        printf("1.��չʾ��ʵ�֡�2.��������");
        printf("��ѡ��:");
        while (1)
        {
            printf("������ѡ��(1,2):");
            scanf("%d",&n);
            switch (n)
            {
            case 1:Find_Simple();
                break;
            case 2:Find_Custom();
                break;
            default:
                printf("��������������\n");
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
        printf("�˳�\n");
        exit(0);
    default:
        printf("�������������\n");
        break;
    }
    }

}


int main(){
    srand((unsigned)time(NULL));//ʹ�����������ʱ�����ȡ
    Enum(); 
 
}

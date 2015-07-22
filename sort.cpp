#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void showResult(int arr[], int n)
{

    for(int i = 0; i < n; i++)
    {

        cout << arr[i] <<" ";
    }
    cout <<"\n";
}

//排序算法


//   1.插入排序
void InsertSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        //if (arr[i] < arr[i - 1])
        //{

            int m = arr[i];
            int j = i - 1;

            while(m < arr[j])
            {
                arr[j+1] = arr[j];
                arr[j] = m;

                if (j <= 0)
                    break;

                j--;
            }

            //arr[j+1] = m;
        //}

    }

    //showResult(arr,n);

}


//  2.希尔排序
void ShellSort(int arr[], int n)
{

    int value = n * 0.5 ;
    while(value >= 1)
    {
        for(int i = value; i < n; i++)
        {
            //if (arr[i] < arr[i - 1])
            //{

                int m = arr[i];
                int j = i - value;

                while(m < arr[j])
                {
                    arr[j+value] = arr[j];
                    arr[j] = m;

                    if (j < value)
                        break;

                    j -= value;
                }

                //arr[j+1] = m;
            //}

        }

        value *= 0.5;
    }

    //showResult(arr,n);
}



//3 选择排序
void SelectSort(int arr[], int n)
{
    int minIdx = 0, maxIdx = n - 1;

    int minTempIdx, maxTempIdx;//, temp;

    while(minIdx < maxIdx)
    {
        minTempIdx = minIdx;
        maxTempIdx = maxIdx;
        for(int i = minIdx ; i <= maxIdx; i++)
        {
            if (arr[i] < arr[minTempIdx])
                minTempIdx = i;
            else if(arr[i] > arr[maxTempIdx])
                maxTempIdx = i;
        }

        int temp = arr[minIdx];
        arr[minIdx] = arr[minTempIdx];
        arr[minTempIdx] = temp;

        temp = arr[maxIdx];
        arr[maxIdx] = arr[maxTempIdx];
        arr[maxTempIdx] = temp;

        minIdx++;
        maxIdx--;
    }

    //showResult(arr,n);
}


//4 冒泡排序

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i + 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

     //showResult(arr,n);
}


//5 快速排序
void FastSort(int arr[], int n)
{
    int sign = arr[0];
    int signIdx = 0;
    for(int i = 1; i < n; i++)
    {
        if (arr[i] < sign)
        {
            if(i - signIdx > 1)
            {
                arr[signIdx] = arr[i];
                arr[i]  = arr[signIdx + 1];
                arr[signIdx + 1] = sign;
                signIdx++;
            }
            else
            {
                arr[signIdx]  = arr[i];
                arr[i] = sign;
                signIdx = i;
            }
        }

    }

    //showResult(arr,n);

    //Left
    if (signIdx > 1)
        FastSort(arr, signIdx);

    //Right
    if (signIdx < (n - 2))
        FastSort(arr + signIdx + 1,  n - signIdx - 1);


}


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int low, int high)
{
    int privotKey = a[low];                 //基准元素
    while(low < high){                   //从表的两端交替地向中间扫描
        while(low < high  && a[high] >= privotKey) --high; //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
        swap(&a[low], &a[high]);
        while(low < high  && a[low] <= privotKey ) ++low;
        swap(&a[low], &a[high]);
    }
//    print(a,10);
    return low;
}


void qsort_improve(int r[ ],int low,int high, int k){
    if( high -low > k ) { //长度大于k时递归, k为指定的数
        int pivot = partition(r, low, high); // 调用的Partition算法保持不变
        qsort_improve(r, low, pivot - 1,k);
        qsort_improve(r, pivot + 1, high,k);
    }
}
void quickSort(int r[], int n, int k){
    qsort_improve(r,0,n,k);//先调用改进算法Qsort使之基本有序

    //再用插入排序对基本有序序列排序
    for(int i=1; i<=n;i ++){
        int tmp = r[i];
        int j=i-1;
        while(tmp < r[j]){
            r[j+1]=r[j]; j=j-1;
        }
        r[j+1] = tmp;
    }

}


void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/

    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }

        a[first] = a[last];/*将比第一个小的移到低端*/

        while(first < last && a[first] <= key)
        {
            ++first;
        }

        a[last] = a[first];
/*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);

}


//6 归并排序
void  MergerSort(int arr[], int n)
{
    int step = 1;
    while(step < n)
    {

        for(int i = 0; i < n; i += 2 * step)
        {
            int leftIdx = i;
            int rightIdx = i + step;

            if (rightIdx >= n)
                break;

            int allNum = (n - i) < (2 * step) ? (n - i) : (2 * step);
            int midIdx = i + step;
            int endIdx = i + allNum;

            int temp[allNum];

            int count = 0;

            //cout << "count, leftIdx, rightIdx = "  << count << "  " << leftIdx << "  " << rightIdx <<" \n";
            while(1)
            {
                if(leftIdx == midIdx)
                    break;
                else if(rightIdx == endIdx)

                    break;
                else if (arr[leftIdx] <= arr[rightIdx])
                {
                    temp[count] = arr[leftIdx];
                    leftIdx++;
                }
                else
                {
                    temp[count] = arr[rightIdx];
                    rightIdx++;
                }
                count++;
            }
            //cout << "count, leftIdx, rightIdx = "  << count << "  " << leftIdx << "  " << rightIdx <<" \n";
            if(leftIdx ==  midIdx)
            {
                memcpy(temp + count, arr + rightIdx, (allNum - count) * sizeof(int));
            }
            else
            {
                memcpy(temp + count, arr + leftIdx, (allNum - count) * sizeof(int));
            }

            //showResult(temp, allNum);
            memcpy(arr + i, temp, allNum * sizeof(int));

        }

        step *= 2;
    }

    //showResult(arr,n);

}


//7.基数排序

//8. 堆排序
void HeapJust(int arr[], int nodeIdx, int n)
{
    int maxIdx = nodeIdx;
    int lChild = nodeIdx * 2;
    int rChild = lChild + 1;

    if(nodeIdx <= n / 2)
    {
        if(lChild <= n && arr[lChild - 1] > arr[maxIdx - 1])
        {
            maxIdx = lChild;
        }

        if(rChild <= n && arr[rChild - 1] > arr[maxIdx - 1])
        {
            maxIdx = rChild;
        }

        if(maxIdx != nodeIdx)
        {
            int temp = arr[nodeIdx - 1];
            arr[nodeIdx - 1] = arr[maxIdx - 1];
            arr[maxIdx - 1] = temp;

            HeapJust(arr, maxIdx, n);
        }
    }

}

void BuildHeap(int arr[], int n)
{
    // 最大的非叶子节点的位于n/2处(完全二叉树第i层至多有2^（i-1）个节点，共i层的完全二叉树最多有2^i-1个节点。)
    for(int i = n/2; i >= 1; i--)
    {
        HeapJust(arr, i, n);
    }
}

void HeapSort(int arr[], int n)
{
    BuildHeap(arr, n);

    for(int i = 1;  i < n; i ++)
    {
        int temp = arr[n - i];
        arr[n - i] = arr[0];
        arr[0] = temp;

        HeapJust(arr, 1, n - i);
    }

    //showResult(arr,n);
}


int main()
{

    int size = 100000;
    int a[size];

    srand(time(0));
    for(int k =0; k < size; k++)
    {
      a[k] = rand()%1000;
    }

//    int size = 10;
//    int a[size] = {97, 33, 38, 49, 49, 55, 63, 76, 62, 27};
//    int a[size] = {6, 3, 9, 7, 3, 9, 0, 5, 2, 3};

    //InsertSort(a, size);
    //ShellSort(a, size);
    //SelectSort(a, size);
    //BubbleSort(a, size);

    //FastSort(a, size);
    //Qsort(a, 0, size - 1);
    //showResult(a,size);

    //MergerSort(a, size);
    HeapSort(a, size);

    return 0;
}

#include<stdio.h>

/**
* 输出数组
* @param array  待输出的数组
* @param len  待输出数组的长度
* @param state  数组的状态，例如："排序前"和"排序后"
* @return void
*/
void PrintArray(int array[],int len,char state[])
{
   int i;
   printf("%s\n",state);
   for(i = 0;i < len;i++)
   {
     printf("%d ",array[i]);
   }
   printf("\n");
}

/**
* 交换两个数
* @param a  整数a的地址
* @param b  整数b的地址
* @return void
*/
void swap(int* a,int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/**
* 调整小顶堆
* @param array  待排序的数组
* @param i  待调整的初试位置
* @param len  待排序的数组的长度
* @return void
*/
void adjustHeap(int array[],int i,int len)
{
  int min_index = i;
  while(i < len)
  {
    if(2*i+1 < len && array[min_index] > array[2*i+1])
    {
       min_index = 2*i+1;
    }
    if(2*i+2 < len && array[min_index] > array[2*i+2])
    {
       min_index = 2*i+2;
    }

    if(i != min_index)
    {
       swap(&array[i],&array[min_index]);
       i = min_index;
    }
    else
        break;
  }
}

/**
* 堆排序
* @param array  待排序的数组
* @param len  待排序数组的长度
* @return void
*/
void HeapSort(int array[],int len)
{
   int i;
   // 构造初始小顶堆
   for(i = len/2-1;i >= 0;i--)
   {
      adjustHeap(array,i,len);
   }
   // test
   PrintArray(array,len,"初始化小顶堆后：");
   // test
   printf("堆排序后：\n");
   for(i = len - 1;i >= 0;i--)
   {
      printf("%d ",array[0]);
      swap(&array[0],&array[i]);
      adjustHeap(array,0,i);
   }
}

int main()
{
   //int array[] = {7,6,5,3,4,2,1,10,9,8};
   int array[] = {10,9,8,7,6,5,4,3,2,1};
   int len = sizeof(array) / sizeof(int);
   PrintArray(array,len,"堆排序前：");
   HeapSort(array,len);
   printf("\n");
   return 0;
}

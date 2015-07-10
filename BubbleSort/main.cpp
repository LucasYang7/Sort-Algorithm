#include<stdio.h>

/**
* 交换两个整数
* @param a  整数a的内存地址
* @param b  整数b的内存地址
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
* 从前往后进行冒泡排序，让大的元素一直往下沉
* @param array  待排序的数组
* @param len  待排序数组的长度
* @return void
*/
void BubbleSort(int array[],int len)
{
   int i,j;
   for(i = len - 1;i >= 1;i--)
   {
     for(j = 0;j < i;j++)
     {
         if(array[j] > array[j + 1])
            swap(&array[j],&array[j + 1]);
     }
   }
}

/**
* 从后往前进行冒泡排序，让小的元素一直向上浮
* @param array  待排序的数组
* @param len  待排序数组的长度
* @return void
*/
void BubbleSort2(int array[],int len)
{
   int i,j;
   for(i = 1;i < len;i++)                 // 表示前i个元素已经处于"排序"状态
   {
     for(j = len - 1;j >= i;j--)
     {
         if(array[j] < array[j - 1])
            swap(&array[j],&array[j - 1]);
     }
   }
}

int main()
{
  int array[] = {10,9,8,7,6,5,4,3,2,1};
  int len = sizeof(array) / sizeof(int);
  PrintArray(array,len,"冒泡排序前：");
  //BubbleSort(array,len);
  BubbleSort2(array,len);
  PrintArray(array,len,"冒泡排序后：");
  return 0;
}

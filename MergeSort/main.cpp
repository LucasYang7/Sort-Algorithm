#include<stdio.h>

/**
* 输出数组
* @param array  待输出的数组
* @param length  待输出数组的长度
* @param state  数组的状态，例如："排序前"和"排序后"
* @return void
*/
void PrintArray(int array[],int length,char state[])
{
   int i;
   printf("%s\n",state);
   for(i = 0;i < length;i++)
   {
     printf("%d ",array[i]);
   }
   printf("\n");
}

/**
* 归并操作
* @param array  待归并的数组
* @param temp   归并过程中的临时数组
* @param gap    归并后有序子数组的长度
* @param length    待归并数组的长度
* @return void
*/
void Merge(int array[],int temp[],int gap,int length)
{
   int begin = 0;
   int middle = begin + gap / 2;
   int end = (begin + gap) < length ? (begin + gap) : length;
   int j = 0;                 // 用于记录temp数组的下标
   int left,right;            // left是归并过程中左边数组的指针，right是归并过程中右边数组的指针
   while(begin < length)
   {
     left = begin;
     right = middle;
     while(left < middle && right < end)
     {
        if(array[left] < array[right])
        {
            temp[j++] = array[left++];
        }
        else
        {
            temp[j++] = array[right++];
        }
     }
     while(left < middle)
     {
        temp[j++] = array[left++];
     }
     while(right < end)
     {
        temp[j++] = array[right++];
     }
     begin = begin + gap;
     middle = begin + gap / 2;
     end = (begin + gap) < length ? (begin + gap) : length;
   }
   for(j = 0;j < length;j++)
   {
       array[j] = temp[j];
   }
}

/**
* 归并排序
* @param array  待排序的数组
* @param temp  归并过程中的临时数组
* @param length  待排序数组的长度
* @return void
*/
int MergeSort(int array[],int temp[],int length)
{
  int gap = 2;           // 一趟归并排序后，有序子数组的长度
  while(gap < 2 * length)
  {
      Merge(array,temp,gap,length);
      gap = 2 * gap;
  }
  return length;
}

int main()
{
   int temp[11];
   int array[] = {7,6,5,3,4,2,1,10,9,8,11};
   int length = sizeof(array) / sizeof(int);
   PrintArray(array,length,"归并排序前：");
   length = MergeSort(array,temp,length);
   PrintArray(array,length,"归并排序后：");
   return 0;
}

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
* 直接插入排序
* @param array  待排序的数组
* @param len  待排序数组的长度
* @return void
*/
void InsertSort(int array[],int len)
{
   int i,j,temp;
   for(i = 1;i < len;i++)
   {
     temp = array[i];
     j = i;                              // 前i个元素都已经排好序了
     while(j > 0 && temp < array[j-1])   // 注意临界条件
     {
         array[j] = array[j-1];
         j--;
     }
     array[j] = temp;
   }
}

int main()
{
   int array[] = {10,9,8,7,6,5,4,3,2,1};
   int len = sizeof(array) / sizeof(int);
   PrintArray(array,len,"直接插入排序前：");
   InsertSort(array,len);
   PrintArray(array,len,"直接插入排序后：");
   return 0;
}

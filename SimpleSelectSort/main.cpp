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
* 交换两个整数
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
* 简单选择排序
* @param array  待排序的数组
* @param len  待排序数组的长度
* @return void
*/
void SimpleSelectSort(int array[],int len)
{
   int i,j;
   for(i = 0;i < len;i++)
   {
       for(j = i + 1;j < len;j++)
       {
           if(array[j] < array[i])
              swap(&array[i],&array[j]);
       }
   }
}

int main()
{
   int array[] = {10,9,8,7,6,5,4,3,2,1};
   int len = sizeof(array) / sizeof(int);
   PrintArray(array,len,"简单选择排序前：");
   SimpleSelectSort(array,len);
   PrintArray(array,len,"简单选择排序后：");
   return 0;
}

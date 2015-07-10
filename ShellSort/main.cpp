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
* 希尔排序
* @param array  待排序的数组
* @param gap  希尔排序的增量
* @param len  待排序数组的长度
* @return void
*/
void ShellSort(int array[],int gap,int len)
{
   int i,j,tj,temp;
   while(gap >= 1)
   {
       for(i = 0;i < gap;i++)
       {
           // 进行直接插入排序
           for(j = i + gap;j < len;j = j + gap)
           {
              tj = j;                // tj用来临时保存j
              temp = array[tj];      // temp用来保存array[tj]
              while(tj > i && temp < array[tj - gap])   // 注意临界条件tj > i，防止数组越界
              {
                  array[tj] = array[tj - gap];
                  tj = tj - gap;
              }
              array[tj] = temp;     // 将temp插入到合适的位置
           }
       }
       gap = gap / 2;
   }
}

int main()
{
   int array[] = {10,9,8,7,6,5,4,3,2,1};
   int len = sizeof(array) / sizeof(int);
   int gap = len / 2;                     // 希尔排序的增量
   PrintArray(array,len,"希尔排序前：");
   ShellSort(array,gap,len);
   PrintArray(array,len,"希尔排序后：");
   return 0;
}

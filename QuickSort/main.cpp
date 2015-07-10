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
* 快速排序
* @param array  待排序数组
* @param left   排序左边界
* @param right  排序右边界
* @return void
*/
void QuickSort(int array[],int left,int right)
{
    if(left < right)
    {
        int low = left,high = right,pivot = array[low];
        while(low < high)
        {
            while(low < high && array[high] > pivot)
            {
                high--;
            }
            array[low] = array[high];
            while(low < high && array[low] < pivot)
            {
                low++;
            }
            array[high] = array[low];
        }
        array[low] = pivot;                // low == high 确定分隔元素的位置
        QuickSort(array,left,low - 1);
        QuickSort(array,high + 1,right);
    }
}

int main()
{
   int array[] = {7,6,5,3,4,2,1,10,9,8};
   int len = sizeof(array) / sizeof(int);
   PrintArray(array,len,"快速排序前：");
   QuickSort(array,0,len - 1);
   PrintArray(array,len,"快速排序后：");
   return 0;
}


#include"my_template.h"

void Insert_sort(Vec_base<int> &inp)
{
    int size = inp.size();
    for(int i = 1;i<size;i++)
    {
        auto now_data = inp[i];
        int j = i;
        while(j>0 && inp[j - 1] > now_data)
        {
            inp[j] = inp[j - 1];
            j--;
        }
        inp[j] = now_data;
    }
}

void selection_sort(Vec_base<int> &inp)
{
    int size = inp.size();
    for(int i = 0;i<size;i++)
    {
        for(int j = i;j<size;j++)
        {
            if(inp[j]<inp[i])
            {
                auto temp = inp[i];
                inp[i] = inp[j];
                inp[j] = temp;
            }
        }
    }
}

void shell_sort(Vec_base<int> &inp)
{
    int size = inp.size();
    int gap = size/2;

    while(gap)
    {
        for(int i = gap;i<size;i++)
        {
            auto now_data = inp[i];
            int j = i;
            while(j>gap-1 && inp[j - gap] > now_data)
            {
                inp[j] = inp[j - gap];
                j -= gap;
            }
            inp[j] = now_data;
        }
        gap = gap/2;
    }
}

void quick_sort(Vec_base<int> &inp,int start,int end)
{
    int i =start,j=end;
    int temp = inp[start];
    if(start < end)
    {
        while(i != j)
        {
            while(j > i && inp[j] > temp)
                j--;
            while(j > i && inp[i] < temp)
                i++;
            int at = inp[j];
            inp[j] = inp[i];
            inp[i] = at;
        }

        quick_sort(inp,start,j - 1);
        quick_sort(inp,i+1,end);
    }
}

void merge(Vec_base<int> &data,int start,int end,Vec_base<int> &result)
{
     int left_length = (end - start + 1) / 2 + 1;//左部分区间的数据元素的个数
     int left_index = start;
     int right_index = start + left_length;
     int result_index = start;
     while(left_index < start + left_length && right_index < end+1)
     {
         //对分别已经排好序的左区间和右区间进行合并
         if(data[left_index] <= data[right_index])
             result[result_index++] = data[left_index++];
         else
             result[result_index++] = data[right_index++];
     }
     while(left_index < start + left_length)
         result[result_index++] = data[left_index++];
     while(right_index < end+1)
         result[result_index++] = data[right_index++];
}

void merge_sort(Vec_base<int> &data, int start, int end, Vec_base<int> &result)
 {
      if(1 == end - start)//如果区间中只有两个元素，则对这两个元素进行排序
      {
          if(data[start] > data[end])
          {
              int temp  = data[start];
              data[start] = data[end];
              data[end] = temp;
         }
         return;
     }
     else if(0 == end - start)//如果只有一个元素，则不用排序
         return;
     else
     {
         //继续划分子区间，分别对左右子区间进行排序
         merge_sort(data,start,(end-start+1)/2+start,result);
         merge_sort(data,(end-start+1)/2+start+1,end,result);
         //开始归并已经排好序的start到end之间的数据
         merge(data,start,end,result);
         //把排序后的区间数据复制到原始数据中去
         for(int i = start;i <= end;++i)
             data[i] = result[i];
     }
 }


void adjust(Vec_base<int> &arr, int len, int index)
{
    int left = 2*index + 1; // index的左子节点
    int right = 2*index + 2;// index的右子节点
 
    int maxone = index;
    if(left<len && arr[left] > arr[maxone])     
    maxone = left;
    if(right<len && arr[right] > arr[maxone])    
    maxone = right;
 
    if(maxone != index)
    {
        int temp = arr[maxone];
        arr[maxone] = arr[index];
        arr[index] = temp;
        adjust(arr, len, maxone);
    }
 
}
 

void heapSort(Vec_base<int> &arr,int size)
{
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }
 

    for(int i = size - 1; i >= 1; i--)
    {
         int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;         
        adjust(arr, i, 0);             
    }
}
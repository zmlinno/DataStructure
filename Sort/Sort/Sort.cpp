//
//  Sort.cpp
//  Sort
//
//  Created by 张木林 on 8/6/25.
//

#include "Sort.hpp"
#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j = 0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)break;
    }
}

//选择排序
void selectionSort(int arr[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int minIndex = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            if(minIndex != i)
            {
                swap(arr[i],arr[minIndex]);
            }
        }
    }
}


//插入排序
void insertionSort(int arr[],int n)
{
    for(int i = 1;i<n;i++)
    {
        int key = arr[i];
        int j = i -1;
        
        //将比key大大元素向右移动
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//归并排序
void merge(int arr[],int left,int mid,int right)
{
    int n1 = mid - left+1;
    int n2 = right - mid;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for(int i = 0;i<n1;i++)
        L[i] = arr[left+i];
    for(int j = 0;j<n2;j++)
        R[j] = arr[mid+1+j];
    int i = 0,j = 0,k = left;
    //合并两个子数组
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i<n1)
        arr[k++] = L[i++];
    while(j<n2)
        arr[k++] = R[j++];
    
    delete[]L;
    delete[]R;
    
}


//快速排序

//先分区函数 - 返回pivot的最终位置
int partition(int arr[],int left,int right)
{
    int pivot = arr[right]; //最右边的作为基准
    int i = left-1; //i指向小雨 pivot的尾部
    
    for(int j = left;j<right;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[right]);  //把pivot放到中间
    return i+1;
}
void quickSort(int arr[],int left,int right)
{
    if(left < right)
    {
        int pivotIndex = partition(arr,left,right);
        quickSort(arr, left, pivotIndex-1); //排左边
        quickSort(arr, pivotIndex+1, right); //排右边
    }
}
void mergeSort(int arr[],int left,int right)
{
    if(left >= right)
        return;
    int mid = left+(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
void printArray(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}

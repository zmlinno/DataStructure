//
//  Sort.hpp
//  Sort
//
//  Created by 张木林 on 8/6/25.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>


//冒泡排序
void bubbleSort(int arr[],int n);
//选择排序
void selectionSort(int arr[],int n);
//插入排序
void insertionSort(int arr[],int n);
//归并排序
void mergeSort(int arr[],int left,int right);
//快速排序
void quickSort(int arr[],int left,int right);

void printArray(int arr[],int n);

#endif /* Sort_hpp */

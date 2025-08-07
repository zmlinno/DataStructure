//
//  main.cpp
//  Sort
//
//  Created by 张木林 on 8/6/25.
//

#include <iostream>
#include"Sort.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[] = {5,2,9,1,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"原始数组: "<<" ";
    printArray(arr, n);
    
    bubbleSort(arr, n);
    selectionSort(arr, n);
    insertionSort(arr, n);
    mergeSort(arr, 0, n-1);
    
    cout<<"冒泡排序后数组: ";
    printArray(arr, n);
    cout<<"选择排序后的数组: ";
    printArray(arr, n);
    cout<<"插入排序后的数组: ";
    printArray(arr, n);
    cout<<"归并排序后的数组: ";
    printArray(arr, n);
    return 0;
}

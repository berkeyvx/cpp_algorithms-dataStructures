//
//  main.cpp
//  mergeSort_recursive
//
//  Created by Berke Yavas on 14.07.2020.
//  Copyright © 2020 Berke Yavas. All rights reserved.
//


/*
    Algorithm               : Merge Sort
    Algorithm Type          : Divide And Conquer
    Time Complexity         : O(NlgN)
    Auxiliary Complexity    : O(N)
    NlgN compares at most, 6NlgN array access to sort any array of size N
    If array is already sorted(best case), it does 1/2NlgN compares
 
    Merge sort is too complicated to use for tiny arrays.
    Use insertion sort or something for small arrays
 */

/*
    Eliminate the copy to the auxiliary array. Save time (but not space)
    by switching the role of the input and auxiliary array in each recursive call
 
    ---- merge part ----
    if(i > mid){
        aux[k] = arr[j++];
    }
    else if (j > high){
        aux[k] = arr[i++];
    }
    else if (arr[i] > arr[j]){
        aux[k] = arr[j++];
    }
    else{
        aux[k] = arr[i++];
    }
    
    ---- sort part ----
 
    sort(aux, arr, low, mid); // sort the first half
    sort(aux, arr, mid + 1, high); // sort the second half
    merge(aux, arr, low, mid, high); // merge them together
 */

#include <iostream>

class Merge {
    
private:
    void sort(int *arr, int *aux, int low, int high);
    void merge(int *arr, int *aux, int low, int mid, int high);
public:

    
    void printArr(int *arr,int size){
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    
    void sort(int *arr, int size);
};


void Merge::sort(int *arr, int *aux, int low, int high){
    if (high <= low)
        return;
    int mid = low + (high - low) / 2; // avoid overflow situation for large high and lows
    sort(arr, aux, low, mid); // sort the first half
    sort(arr, aux, mid + 1, high); // sort the second half
    if (arr[mid] < arr[mid+1]) {
        return; // subarrays already sorted no need to merge
                // with this improvement, if array is already sorted(best case)
                // time complexity is O(N) linear time
    }
    merge(arr, aux, low, mid, high); // merge them together
}

void Merge::merge(int* arr, int *aux, int low, int mid, int high){
    
    for(int i = low; i <= high; i++){
        aux[i] = arr[i];
    }
    
    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++) {
        if(i > mid){
            arr[k] = aux[j++];
        }
        else if (j > high){
            arr[k] = aux[i++];
        }
        else if (aux[i] > aux[j]){
            arr[k] = aux[j++];
        }
        else{
            arr[k] = aux[i++];
        }
    }
}

void Merge::sort(int *arr, int size){
    int *aux = new int[size];
    sort(arr, aux, 0, size-1);
}


int main(int argc, const char * argv[]) {
    int arr[] {3,10,5,12,6,7,8,9,2,3,5,6,8,1,2,3};
    int size = 16;
    Merge m;
    m.printArr(arr, size);
    m.sort(arr, size);
    m.printArr(arr, size);
    return 0;
}

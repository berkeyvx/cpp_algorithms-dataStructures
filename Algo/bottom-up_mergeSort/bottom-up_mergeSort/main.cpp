#include <iostream>


/*
    Non recursive version of merge sort implementation
    Pass through array, merging subarrays of size 1
    Repeat for subarrays of size+size(2,4,8,16...)
 
    for(subarray size = 1; subarray size < actual size; subaray size += subarray size)
        for(low = 0; low < actualsize-subarray size; low += subarray size*2)
            merge(array,low, mid = low + subarray size - 1, min(low+subarray size + subarray size -1), size -1)
 
 */

class MergeBU {
    
private:
    void merge(int *arr, int* aux, int low, int mid, int high);
public:

    
    void printArr(int *arr,int size){
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    
    void sort(int *arr, int size);
};


void MergeBU::merge(int* arr, int* aux, int low, int mid, int high){
    
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

void MergeBU::sort(int *arr, int size){
    int *aux = new int[size];
    for (int sz = 1; sz < size; sz = sz+sz) {
        for (int lo = 0; lo < size-sz; lo += sz+sz) {
            merge(arr, aux, lo, lo+sz-1, std::min(lo+sz+sz-1, size-1));
            // std::min -> determines if its end of the array or not
            // end of the array we might not have full array so we use size-1
        }
    }
}


int main(int argc, const char * argv[]) {
    int arr[] {3,10,5,12,6,7,8,9,2,3,5,6,8,1,2,3};
    int size = 16;
    MergeBU m;
    m.printArr(arr, size);
    m.sort(arr, size);
    m.printArr(arr, size);
    return 0;
}

#include <stdio.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSortOptimized(int arr[], int n) {
    int min_index, max_index;
    
    
    for (int i = 0; i < n / 2; i++) {
        
        min_index = i;
        max_index = i;

        for (int j = i + 1; j < n - i; j++) {
            
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
           
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }

    
        if (min_index == max_index) {
            continue;
        }

      
        swap(&arr[i], &arr[min_index]);

        if (max_index == i) {
            max_index = min_index;
        }


        swap(&arr[n - 1 - i], &arr[max_index]);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSortOptimized(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
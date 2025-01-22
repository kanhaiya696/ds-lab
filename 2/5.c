#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int swapped; 
    for (int i = 0; i < n - 1; i++) {
        swapped = 0; 
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] ^= arr[j + 1]; 
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
                swapped = 1; 
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted Array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}

#include <stdio.h>
void removeDuplicates(int arr[], int *n) {
    int i, j, k = 0;

    for (i = 0; i < *n; i++) {
        int isDuplicate = 0;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            arr[k++] = arr[i];  
        }
    }

    *n = k; 
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    removeDuplicates(arr, &n);
    printf("Array without duplicates:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

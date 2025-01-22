#include <stdio.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findFrequency(int arr[], int n) {
    bubbleSort(arr, n);
    int count = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++; 
        } else {
            printf("%d occurs %d times\n", arr[i - 1], count);
            count = 1;
        }
    }
}

int main() {
    int arr[] = {1, 2, 1, 2, 2, 3, 3, 4, 5, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    findFrequency(arr, n);

    return 0;
}

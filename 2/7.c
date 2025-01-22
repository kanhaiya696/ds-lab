#include <stdio.h>
int partition(int arr[], int low, int high) {
    int pivot = arr[high], temp, i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int p = partition(arr, low, high);
        if (p == k) return arr[p];
        return p > k ? quickselect(arr, low, p - 1, k) : quickselect(arr, p + 1, high, k);
    }
    return -1;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    printf("The %d-th largest element is: %d\n", k, quickselect(arr, 0, n - 1, k - 1));
    return 0;
}

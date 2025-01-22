#include <stdio.h>

void slidingWindowAvg(int arr[], int n, int windowSize) {
    for (int i = 0; i <= n - windowSize; i++) {
        int sum = 0;   
        for (int j = i; j < i + windowSize; j++) {
            sum += arr[j];
        }
        printf("Average of window starting at index %d: %.2f\n", i, (float)sum / windowSize);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int windowSize = 3;
    slidingWindowAvg(arr, n, windowSize);

    return 0;
}

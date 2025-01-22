#include <stdio.h>

void addElement(int* arr, int index, int value, int* size) {
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*size)++;
}

void deleteElement(int* arr, int index, int* size) {
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void displayArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void shiftRight(int* arr, int size) {
    int temp = arr[size - 1];
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main() {
    int arr[100], size, choice, index, value;

    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
      
        printf("\nMenu:\n");
        printf("1. Add an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the array\n");
        printf("4. Reverse the array\n");
        printf("5. Sort the array\n");
        printf("6. Shift the array to the right\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter index to add: ");
                scanf("%d", &index);
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                if (index >= 0 && index <= size) {
                    addElement(arr, index, value, &size);
                } else {
                    printf("Invalid index!\n");
                }
                break;

            case 2: 
                printf("Enter index to delete: ");
                scanf("%d", &index);
                if (index >= 0 && index < size) {
                    deleteElement(arr, index, &size);
                } else {
                    printf("Invalid index!\n");
                }
                break;

            case 3: 
                displayArray(arr, size);
                break;

            case 4:
                reverseArray(arr, size);
                printf("Array has been reversed.\n");
                break;

            case 5: 
                sortArray(arr, size);
                printf("Array has been sorted.\n");
                break;

            case 6: 
                shiftRight(arr, size);
                printf("Array has been shifted to the right.\n");
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

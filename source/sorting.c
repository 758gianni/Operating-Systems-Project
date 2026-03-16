#include <stdio.h>

int main() {
    int num;

    // Get user input for the number of elements in the array
    printf("Enter number of elements: ");
    scanf("%d", &num);

    int arr[num];

    // Get user input for the elements of the array
    printf("Enter numbers:\n");

    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubble sort algorithm
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display the sorted array
    printf("Sorted array:\n");

    for (int i = 0; i < num; i++) {
        printf("%d ",arr[i]);
    }

    printf("\n");

    return 0;
}

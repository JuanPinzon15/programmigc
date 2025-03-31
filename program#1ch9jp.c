program#1ch9jp.c
#include <stdio.h>

void selection_sort(int arr[], int n) {
    if (n <= 1) return; // Base case: an array of 1 or 0 elements is already sorted.

    int max_idx = 0; // Index of the largest element

    // Find the largest element in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }

    // Swap the largest element with the last element
    int temp = arr[max_idx];
    arr[max_idx] = arr[n - 1];
    arr[n - 1] = temp;

    // Recursively sort the remaining elements
    selection_sort(arr, n - 1);
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, n); // Sort the array

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

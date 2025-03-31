/*******************
 * FILENAME: program#1ch9jp.c

 * YOUR NAME: Juan Pinzon

 * DESCRIPTION: This program ask the user to enter a series of integers, then sorts the integers by calling the function selection_sort.

*********************/
#include <stdio.h>

void selection_sort(int arr[], int n) {
    if (n <= 1) return; // The array of 1 or 0 elements is already sorted, so it allows the function to return.

    // Index of the largest element
    int max_idx = 0;

    // Find the largest element in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }

    // Change the largest element with the last element
    int temp = arr[max_idx];
    arr[max_idx] = arr[n - 1];
    arr[n - 1] = temp;

    // Sort the remaining elements recursively 
    selection_sort(arr, n - 1);
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare the array
    int arr[n];

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array
    selection_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

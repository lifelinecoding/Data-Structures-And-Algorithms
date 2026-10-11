#include <stdio.h>
#include<windows.h>

// Helper function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the tree
void heapify(int arr[], int length, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If left child exists and is greater than root
    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child exists and is greater than the largest so far
    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and recursively heapify the affected subtree
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, length, largest);
    }
}

// Heap Sort Algorithm
void HeapSort(int arr[], int length) {
    //Build a max heap
    // Start from the last non-leaf node (n / 2 - 1) up to the root (0)
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(arr, length, i);
    }

    // Extract elements from the heap one by one
    for (int i = length - 1; i > 0; i--) {
        // Move current root (maximum element) to the end of the array
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to traverse the array
void Traverse(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    Traverse(arr, length);

    printf("\n");
    HeapSort(arr, length);

    printf("Sorted array: ");
    Traverse(arr, length);

    return 0;
}
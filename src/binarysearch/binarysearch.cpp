#include "array/array.h"

/**
 * Time complexity: Best case O(1), Average case O(log n), Worst case O(log n)
 */
int BinarySearch(const Array& arr, int key) {
    int low, high, mid;
    low = 0;
    high = arr.length - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (key == arr.data[mid]) {
            return mid;
        } else if (key < arr.data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int BinarySearchRecursive(const Array& arr, int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (key == arr.data[mid]) {
            return mid;
        } else if (key < arr.data[mid]) {
            return BinarySearchRecursive(arr, low, mid - 1, key);
        } else {
            return BinarySearchRecursive(arr, mid + 1, high, key);
        }
    }
    return -1;
}

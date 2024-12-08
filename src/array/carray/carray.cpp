#include <iostream>

#include "carray.h"

/**
 * CArray is C-styleish array that is implemented using struct.
 */


void Append(CArray *arr, int x) {
    if (arr->length < arr->size) {
        arr->data[arr->length++] = x;
    }
}

float Average(const CArray& arr) {
    return (float)Sum(arr) / arr.length;
}

void Delete(CArray *arr, int index) {
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->length--;
    }
}

CArray* DifferenceSorted(const CArray& arr1, const CArray& arr2) {
    int i, j, k;
    i = j = k = 0;

    CArray *arr = new CArray;
    arr->data = new int[arr->size];

    while(i < arr1.length && j < arr2.length) {
        if (arr1.data[i] < arr2.data[j]) {
            arr->data[k++] = arr1.data[i++];
        } else if (arr2.data[j] < arr1.data[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    for (; i < arr1.length; i++) {
        arr->data[k++] = arr1.data[i];
    }

    arr->length = k;
    arr->size = 10;

    return arr;
}

void Display(const CArray& arr) {
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.data[i] << " ";
    }
    std::cout << std::endl;
}

int Get(const CArray& arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.data[index];
    }
    return -1;
}

void Insert(CArray *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->data[i] = arr->data[i - 1];
        }
        arr->data[index] = x;
        arr->length++;
    }
}

CArray* IntersectionSorted(const CArray& arr1, const CArray& arr2) {
    int i, j, k;
    i = j = k = 0;

    CArray *arr = new CArray;
    arr->data = new int[arr->size];

    while(i < arr1.length && j < arr2.length) {
        if (arr1.data[i] < arr2.data[j]) {
           i++;
        } else if (arr2.data[j] < arr1.data[i]) {
            j++;
        } else { // arr1.data[i] == arr2.data[j]
            arr->data[k++] = arr1.data[i++];
            j++;
        }
    }

    arr->length = k;
    arr->size = 10;

    return arr;
}

bool IsSorted(const CArray& arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.data[i] > arr.data[i + 1]) {
            return false;
        }
    }
    return true;
}

int Max(const CArray& arr) {
    int max = arr.data[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.data[i] > max) {
            max = arr.data[i];
        }
    }
    return max;
}

/**
 * Time Complexity: O(m + n) = O(2n) = O(n)
 */
CArray* Merge(const CArray& arr1, const CArray& arr2) {
    int i, j, k;
    i = j = k = 0;

    CArray *arr = new CArray;
    arr->length = arr1.length + arr2.length;
    arr->size = 10;
    arr->data = new int[arr->size];

    while(i < arr1.length && j < arr2.length) {
        if (arr1.data[i] < arr2.data[j]) {
            arr->data[k++] = arr1.data[i++];
        } else {
            arr->data[k++] = arr2.data[j++];
        }
    }
    for (; i < arr1.length; i++) {
        arr->data[k++] = arr1.data[i];
    }
    for (; j < arr2.length; j++) {
        arr->data[k++] = arr2.data[j];
    }

    return arr;
}

int Min(const CArray& arr) {
    int min = arr.data[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.data[i] < min) {
            min = arr.data[i];
        }
    }
    return min;
}

void Rearrange(CArray *arr) {
    int i = 0;
    int j = arr->length - 1;
    while (i < j) {
        while (arr->data[i] < 0) i++;
        while (arr->data[j] >= 0) j--;
        if (i < j) {
            int temp = arr->data[i];
            arr->data[i] = arr->data[j];
            arr->data[j] = temp;
        }
    }
}

void Reverse(CArray *arr) {  
    for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
        int temp = arr->data[i];
        arr->data[i] = arr->data[j];
        arr->data[j] = temp;
    }
}

void Set(CArray *arr, int index, int x) {
    if (index >= 0 && index < arr->length) {
        arr->data[index] = x;
    }
}

int Sum(const CArray& arr) {
    int sum = 0;
    for (int i = 0; i < arr.length; i++) {
        sum += arr.data[i];
    }
    return sum;
}

/**
 * Time Complexity: O(m + n) = O(2n) = O(n)
 */
CArray* UnionSorted(const CArray& arr1, const CArray& arr2) {
    int i, j, k;
    i = j = k = 0;

    CArray *arr = new CArray;
    arr->data = new int[arr->size];

    while(i < arr1.length && j < arr2.length) {
        if (arr1.data[i] < arr2.data[j]) {
            arr->data[k++] = arr1.data[i++];
        } else if (arr2.data[j] < arr1.data[i]) {
            arr->data[k++] = arr2.data[j++];
        } else {
            arr->data[k++] = arr1.data[i++];
            j++;
        }
    }
    for (; i < arr1.length; i++) {
        arr->data[k++] = arr1.data[i];
    }
    for (; j < arr2.length; j++) {
        arr->data[k++] = arr2.data[j];
    }

    arr->length = k;
    arr->size = 10;

    return arr;
}

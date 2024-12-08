#include <iostream>

#include "array.h"

Array::Array(int size) {
    this->size = size;
    this->length = 0;
    this->data = new int[size];
}

Array::~Array() {
    delete[] data;
}

void Array::Append(int x) {
    if (length < size) {
        data[length++] = x;
    }
}

float Array::Average() {
    return (float)Sum() / length;
}

void Array::Delete(int index) {
    if (index >= 0 && index < length) {
        for (int i = index; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }
}

Array* Array::DifferenceSorted(const Array& arr2) {
    int i, j, k;
    i = j = k = 0;

    Array *arr = new Array(10);

    while(i < length && j < arr2.length) {
        if (data[i] < arr2.data[j]) {
            arr->data[k++] = data[i++];
        } else if (arr2.data[j] < data[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    for (; i < length; i++) {
        arr->data[k++] = data[i];
    }

    arr->length = k;

    return arr;
}

void Array::Display() {
    for (int i = 0; i < length; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int Array::Get(int index) {
    if (index >= 0 && index < length) {
        return data[index];
    }
    return -1;
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = x;
        length++;
    }
}

Array* Array::IntersectionSorted(const Array& arr2) {
    int i, j, k;
    i = j = k = 0;

    Array *arr = new Array(10);

    while(i < length && j < arr2.length) {
        if (data[i] < arr2.data[j]) {
           i++;
        } else if (arr2.data[j] < data[i]) {
            j++;
        } else { // data[i] == arr2.data[j]
            arr->data[k++] = data[i++];
            j++;
        }
    }

    arr->length = k;

    return arr;
}

bool Array::IsSorted() {
    for (int i = 0; i < length - 1; i++) {
        if (data[i] > data[i + 1]) {
            return false;
        }
    }
    return true;
}

int Array::Max() {
    int max = data[0];
    for (int i = 1; i < length; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

/**
 * Time Complexity: O(m + n) = O(2n) = O(n)
 */
Array* Array::Merge(const Array& arr2) {
    int i, j, k;
    i = j = k = 0;

    Array *arr = new Array(length + arr2.length);
    arr->length = length + arr2.length;

    while(i < length && j < arr2.length) {
        if (data[i] < arr2.data[j]) {
            arr->data[k++] = data[i++];
        } else {
            arr->data[k++] = arr2.data[j++];
        }
    }
    for (; i < length; i++) {
        arr->data[k++] = data[i];
    }
    for (; j < arr2.length; j++) {
        arr->data[k++] = arr2.data[j];
    }

    return arr;
}

int Array::Min() {
    int min = data[0];
    for (int i = 1; i < length; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

void Array::Rearrange() {
    int i = 0;
    int j = length - 1;
    while (i < j) {
        while (data[i] < 0) i++;
        while (data[j] >= 0) j--;
        if (i < j) {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
}

void Array::Reverse() {  
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

void Array::Set(int index, int x) {
    if (index >= 0 && index < length) {
        data[index] = x;
    }
}

int Array::Sum() {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum;
}

/**
 * Time Complexity: O(m + n) = O(2n) = O(n)
 */
Array* Array::UnionSorted(const Array& arr2) {
    int i, j, k;
    i = j = k = 0;

    Array *arr = new Array(10);

    while(i < length && j < arr2.length) {
        if (data[i] < arr2.data[j]) {
            arr->data[k++] = data[i++];
        } else if (arr2.data[j] < data[i]) {
            arr->data[k++] = arr2.data[j++];
        } else {
            arr->data[k++] = data[i++];
            j++;
        }
    }
    for (; i < length; i++) {
        arr->data[k++] = data[i];
    }
    for (; j < arr2.length; j++) {
        arr->data[k++] = arr2.data[j];
    }

    arr->length = k;

    return arr;
}

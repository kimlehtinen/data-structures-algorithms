#include <iostream>

#include "array.h"


void Append(Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->data[arr->length++] = x;
    }
}

float Average(const Array& arr) {
    return (float)Sum(arr) / arr.length;
}

void Delete(Array *arr, int index) {
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->length--;
    }
}

void Display(const Array& arr) {
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.data[i] << " ";
    }
    std::cout << std::endl;
}

int Get(const Array& arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.data[index];
    }
    return -1;
}

void Insert(Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->data[i] = arr->data[i - 1];
        }
        arr->data[index] = x;
        arr->length++;
    }
}

bool IsSorted(const Array& arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.data[i] > arr.data[i + 1]) {
            return false;
        }
    }
    return true;
}

int Max(const Array& arr) {
    int max = arr.data[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.data[i] > max) {
            max = arr.data[i];
        }
    }
    return max;
}

int Min(const Array& arr) {
    int min = arr.data[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.data[i] < min) {
            min = arr.data[i];
        }
    }
    return min;
}

void Rearrange(Array *arr) {
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

void Reverse(Array *arr) {  
    for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
        int temp = arr->data[i];
        arr->data[i] = arr->data[j];
        arr->data[j] = temp;
    }
}

void Set(Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length) {
        arr->data[index] = x;
    }
}

int Sum(const Array& arr) {
    int sum = 0;
    for (int i = 0; i < arr.length; i++) {
        sum += arr.data[i];
    }
    return sum;
}

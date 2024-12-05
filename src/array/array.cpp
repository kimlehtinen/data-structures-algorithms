#include <iostream>

#include "array.h"


void Display(const Array& arr) {
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.data[i] << " ";
    }
    std::cout << std::endl;
}

void Append(Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->data[arr->length++] = x;
    }
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

void Delete(Array *arr, int index) {
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->length--;
    }
}

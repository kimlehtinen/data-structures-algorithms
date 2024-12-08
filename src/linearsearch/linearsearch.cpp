#include <iostream>
#include "array/carray/carray.h"


int LinearSearch(CArray arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.data[i] == key) {
            return i;
        }
    }
    return -1;
}

int LinearSearchSwap(CArray *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->data[i] == key) {
            int temp = arr->data[i];
            arr->data[i] = arr->data[i - 1];
            arr->data[i - 1] = temp;
            return i;
        }
    }
    return -1;
}

int LinearSearchHead(CArray *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->data[i] == key) {
            int temp = arr->data[i];
            for (int j = i; j > 0; j--) {
                arr->data[j] = arr->data[j - 1];
            }
            arr->data[0] = temp;
            return i;
        }
    }
    return -1;
}

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

// Struct definition
struct Array {
    int *data;
    int size;
    int length;
};

// Function declarations
void Display(const Array& arr);
void Append(Array* arr, int x);
void Insert(Array* arr, int index, int x);
void Delete(Array* arr, int index);

#endif // ARRAY_H
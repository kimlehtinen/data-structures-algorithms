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
void Append(Array* arr, int x);
float Average(const Array& arr);
void Delete(Array* arr, int index);
void Display(const Array& arr);
int Get(const Array& arr, int index);
void Insert(Array* arr, int index, int x);
bool IsSorted(const Array& arr);
int Max(const Array& arr);
Array* Merge(const Array& arr1, const Array& arr2);
int Min(const Array& arr);
void Rearrange(Array* arr);
void Reverse(Array* arr);
void Set(Array* arr, int index, int x);
int Sum(const Array& arr);

#endif // ARRAY_H
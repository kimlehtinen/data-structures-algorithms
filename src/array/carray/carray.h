#ifndef CARRAY_H
#define CARRAY_H

#include <iostream>

/**
 * CArray is C-styleish array that is implemented using struct.
 */

// Struct definition
struct CArray {
    int *data;
    int size;
    int length;
};

// Function declarations
void Append(CArray* arr, int x);
float Average(const CArray& arr);
void Delete(CArray* arr, int index);
CArray* DifferenceSorted(const CArray& arr1, const CArray& arr2);
void Display(const CArray& arr);
int Get(const CArray& arr, int index);
void Insert(CArray* arr, int index, int x);
CArray* IntersectionSorted(const CArray& arr1, const CArray& arr2);
bool IsSorted(const CArray& arr);
int Max(const CArray& arr);
CArray* Merge(const CArray& arr1, const CArray& arr2);
int Min(const CArray& arr);
void Rearrange(CArray* arr);
void Reverse(CArray* arr);
void Set(CArray* arr, int index, int x);
int Sum(const CArray& arr);
CArray* UnionSorted(const CArray& arr1, const CArray& arr2);

#endif // CARRAY_H
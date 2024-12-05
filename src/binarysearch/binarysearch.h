#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>

#include "array/array.h"

int BinarySearch(const Array& arr, int key);

int BinarySearchRecursive(const Array& arr, int low, int high, int key);

#endif // BINARYSEARCH_H

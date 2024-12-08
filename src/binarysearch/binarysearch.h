#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>

#include "array/carray/carray.h"

int BinarySearch(const CArray& arr, int key);

int BinarySearchRecursive(const CArray& arr, int low, int high, int key);

#endif // BINARYSEARCH_H

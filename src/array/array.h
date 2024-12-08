#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
private:
    int *data;
    int size;
    int length;
public:
    Array(int size);
    ~Array();
    void Append(int x);
    float Average();
    void Delete(int index);
    Array* DifferenceSorted(const Array& arr2);
    void Display();
    int Get(int index);
    void Insert(int index, int x);
    Array* IntersectionSorted(const Array& arr2);
    bool IsSorted();
    int Max();
    Array* Merge(const Array& arr2);
    int Min();
    void Rearrange();
    void Reverse();
    void Set(int index, int x);
    int Sum();
    Array* UnionSorted(const Array& arr2);
};

#endif // ARRAY_H
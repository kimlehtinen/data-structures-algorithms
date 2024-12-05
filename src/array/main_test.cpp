#include "array.h"
#include "linearsearch/linearsearch.h"


int main_test() {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    Display(arr);

    Append(&arr, 4);

    Display(arr);

    Insert(&arr, 1, 5);

    Display(arr);

    Delete(&arr, 1);

    Display(arr);

    std::cout << "LinearSearch: " << LinearSearch(arr, 3) << std::endl;

    std::cout << "LinearSearchSwap: " << LinearSearchSwap(&arr, 3) << std::endl;

    Display(arr);

    std::cout << "LinearSearchHead: " << LinearSearchHead(&arr, 3) << std::endl;

    Display(arr);

    return 0;
}

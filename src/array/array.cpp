#include <iostream>


struct Array {
    int *data;
    int size;
    int length;
};

void Display(Array arr) {
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

int LinearSearch(Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.data[i] == key) {
            return i;
        }
    }
    return -1;
}

int LinearSearchSwap(Array *arr, int key) {
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

int LinearSearchHead(Array *arr, int key) {
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

int main() {
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

